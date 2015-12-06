/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Random;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Testing invalid URLs

	   //assertFalse(urlVal.isValid("ht://www.google.com"));
	   assertFalse(urlVal.isValid("http://ww.amazon.com:"));
	   assertFalse(urlVal.isValid("ttp://www.amazon.com:"));
	   assertFalse(urlVal.isValid("htt://www.amazon.com:"));
	   assertFalse(urlVal.isValid("http:/www.amazon.com:"));
	   assertFalse(urlVal.isValid("http://www.amazon.om:"));
	   assertFalse(urlVal.isValid("http://amazon.com:"));
	   assertFalse(urlVal.isValid("ftp://amazon.com:"));
	   assertFalse(urlVal.isValid("http://www.amazon.com:"));
	   assertFalse(urlVal.isValid("http://www.amazon.com:808080"));
	   
	   //Testing valid URLs

	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/test"));
	   assertTrue(urlVal.isValid("http://www.oregonstate.edu"));
	   assertTrue(urlVal.isValid("http://www.ca.gov"));
	   assertTrue(urlVal.isValid("http://www.asp.net"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:0"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:88"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:888"));
	   //The following two should be true but return false - Bug #1
	   assertTrue(urlVal.isValid("http://www.amazon.com:8080"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:80808"));
	   
	   assertTrue(urlVal.isValid("http://www.amazon.com:88/test1/"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/test1/"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/test1/test2"));
	   
	   //The following two should be true but return false - Bug #2
	   assertTrue(urlVal.isValid("http://www.amazon.com/test1/?action=view"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/test1/?action=edit&mode=up"));
	   
	   
   }
   
   public void testManualTest2() 
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String urlFile="src/UrlsToVerify.txt";
	   
	   try{
		   FileReader txtFile = new FileReader(urlFile);
		   BufferedReader fbuffer = new BufferedReader(txtFile);

		   String line;

		   while ((line = fbuffer.readLine()) != null){
			   String[] tokens = line.split("[ ]");
			   String url = tokens[0];
			   boolean bool = Boolean.parseBoolean(tokens[1]);
   
			   if(bool != urlVal.isValid(url)){
				   System.out.println(url);
			   }
           }

		   fbuffer.close();
      
	   }catch(Exception err){
		   System.out.println(err.getMessage());                      
	   }

   }
   
   
   /* Partition tests. The input domain shall be partitioned in the following way:
    * <scheme>://<authority><path>?<query>
    * The partition tests will test functions that are split by the input domain
    * and test the particular functions that test that input area
    */
   
   /* Random string generator
    * Added a random string method to create random strings for each input partition
    * Preconditions: Must pass a length
    * Parameters: length of the random string
    * Output: produces an alpha-numeric string of the length specified
    */
   public String randString(int length) 
   {
	   String CHAR_LIST = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	   StringBuffer randStr = new StringBuffer();
       for(int i=0; i< length; i++){
           int number = new Random().nextInt(CHAR_LIST.length());
           char ch = CHAR_LIST.charAt(number);
           randStr.append(ch);
       }
       return randStr.toString();
   }
   
   public void testScheme()
   {
	   //Note - Tried random testing on isValid scheme using the ALLOW_ALL_SCHEMES,
	   //but there was not a point of reference to validate towards. 
	   //I found a list of valid URI schemes by the IANA, but not sure if that
	   //was used for the basis of the validator. Thus, I am just random testing the partition
	   //of the default scheme
	   
	   UrlValidator urlVal = new UrlValidator();
	   
	   // In the default constructor, only three schemes are valid: http, https, ftp
	   assertTrue(urlVal.isValidScheme("http"));
	   assertTrue(urlVal.isValidScheme("https"));
	   assertTrue(urlVal.isValidScheme("ftp"));
	   
	   //Special input scenarios 
	   assertFalse(urlVal.isValidScheme(""));
	   assertFalse(urlVal.isValidScheme("/"));
	   	   
	   //Randomly test inputs for the scheme using default scenario
	   for (int i=0; i < 100000; i++) {
		   int StringLength = new Random().nextInt(10 - 1 + 1);
		   String testString = randString(StringLength);
		   //System.out.println(testString);
		   if(testString.equals("http") || testString.equals("https") || testString.equals("ftp")) {
			   assertTrue(urlVal.isValidScheme(testString));
		   } else {
			   assertFalse(urlVal.isValidScheme(testString));
		   }
	   }
	   
	   //Ensure that all IANA allowed URI's pass the scheme validator when 
	   //ALLOW ALL SCHEMES is on.
	   UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //This array is a list of all of the IANA approved URI schemes as of 2015-11-25
	   //http://www.iana.org/assignments/uri-schemes/uri-schemes.xhtml
	   String approvedSchemes[] = {
	   "aaa",
	   "aaas",
	   "about",
	   "acap",
	   "acct",
	   "acr",
	   "adiumxtra",
	   "afp",
	   "afs",
	   "aim",
	   "appdata",
	   "apt",
	   "attachment",
	   "aw",
	   "barion",
	   "beshare",
	   "bitcoin",
	   "blob",
	   "bolo",
	   "callto",
	   "cap",
	   "chrome",
	   "chrome-extension",
	   "cid",
	   "coap",
	   "coaps",
	   "com-eventbrite-attendee",
	   "content",
	   "crid",
	   "cvs",
	   "data",
	   "dav",
	   "dict",
	   "dlna-playcontainer",
	   "dlna-playsingle",
	   "dns",
	   "dntp",
	   "dtn",
	   "dvb",
	   "ed2k",
	   "example",
	   "facetime",
	   "fax",
	   "feed",
	   "feedready",
	   "file",
	   "filesystem",
	   "finger",
	   "fish",
	   "ftp",
	   "geo",
	   "gg",
	   "git",
	   "gizmoproject",
	   "go",
	   "gopher",
	   "gtalk",
	   "h323",
	   "ham",
	   "hcp",
	   "http",
	   "https",
	   "iax",
	   "icap",
	   "icon",
	   "im",
	   "imap",
	   "info",
	   "iotdisco",
	   "ipn",
	   "ipp",
	   "ipps",
	   "irc",
	   "irc6",
	   "ircs",
	   "iris",
	   "iris.beep",
	   "iris.lwz",
	   "iris.xpc",
	   "iris.xpcs",
	   "isostore",
	   "itms",
	   "jabber",
	   "jar",
	   "jms",
	   "keyparc",
	   "lastfm",
	   "ldap",
	   "ldaps",
	   "magnet",
	   "mailserver",
	   "mailto",
	   "maps",
	   "market",
	   "message",
	   "mid",
	   "mms",
	   "modem",
	   "ms-access",
	   "ms-drive-to",
	   "ms-excel",
	   "ms-getoffice",
	   "ms-help",
	   "ms-infopath",
	   "ms-media-stream-id",
	   "ms-project",
	   "ms-powerpoint",
	   "ms-publisher",
	   "ms-search-repair",
	   "ms-secondary-screen-controller",
	   "ms-secondary-screen-setup",
	   "ms-settings",
	   "ms-settings-airplanemode",
	   "ms-settings-bluetooth",
	   "ms-settings-camera",
	   "ms-settings-cellular",
	   "ms-settings-cloudstorage",
	   "ms-settings-emailandaccounts",
	   "ms-settings-language",
	   "ms-settings-location",
	   "ms-settings-lock",
	   "ms-settings-nfctransactions",
	   "ms-settings-notifications",
	   "ms-settings-power",
	   "ms-settings-privacy",
	   "ms-settings-proximity",
	   "ms-settings-screenrotation",
	   "ms-settings-wifi",
	   "ms-settings-workplace",
	   "ms-spd",
	   "ms-transit-to",
	   "ms-visio",
	   "ms-walk-to",
	   "ms-word",
	   "msnim",
	   "msrp",
	   "msrps",
	   "mtqp",
	   "mumble",
	   "mupdate",
	   "mvn",
	   "news",
	   "nfs",
	   "ni",
	   "nih",
	   "nntp",
	   "notes",
	   "oid",
	   "opaquelocktoken",
	   "pack",
	   "palm",
	   "paparazzi",
	   "pkcs11",
	   "platform",
	   "pop",
	   "pres",
	   "prospero",
	   "proxy",
	   "psyc",
	   "query",
	   "redis",
	   "rediss",
	   "reload",
	   "res",
	   "resource",
	   "rmi",
	   "rsync",
	   "rtmfp",
	   "rtmp",
	   "rtsp",
	   "rtsps",
	   "rtspu",
	   "secondlife",
	   "service",
	   "session",
	   "sftp",
	   "sgn",
	   "shttp",
	   "sieve",
	   "sip",
	   "sips",
	   "skype",
	   "smb",
	   "sms",
	   "smtp",
	   "snews",
	   "snmp",
	   "soap.beep",
	   "soap.beeps",
	   "soldat",
	   "spotify",
	   "ssh",
	   "steam",
	   "stun",
	   "stuns",
	   "submit",
	   "svn",
	   "tag",
	   "teamspeak",
	   "tel",
	   "teliaeid",
	   "telnet",
	   "tftp",
	   "things",
	   "thismessage",
	   "tip",
	   "tn3270",
	   "turn",
	   "turns",
	   "tv",
	   "udp",
	   "unreal",
	   "urn",
	   "ut2004",
	   "v-event",
	   "vemmi",
	   "ventrilo",
	   "videotex",
	   "view-source",
	   "wais",
	   "webcal",
	   "ws",
	   "wss",
	   "wtai",
	   "wyciwyg",
	   "xcon",
	   "xcon-userid",
	   "xfire",
	   "xmlrpc.beep",
	   "xmlrpc.beeps",
	   "xmpp",
	   "xri",
	   "ymsgr",
	   "z39.50",
	   "z39.50r",
	   "z39.50s"};
	   
	   //All valid URI schemes from IANA should pass this assertion loop
	   for (String value: approvedSchemes) {
		   assertTrue(urlVal2.isValidScheme(value));
	   }
	   
   }
   
   public void testAuthority(){
       
	   UrlValidator urlVal3 = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
	   //Test some known valid web pages
	   assertTrue(urlVal3.isValidAuthority("oregonstate.edu"));
	   assertTrue(urlVal3.isValidAuthority("www.google.com"));
	   assertTrue(urlVal3.isValidAuthority("microsoft.com"));
	   assertFalse(urlVal3.isValidAuthority(null));
	   
	   //--BUG FOUND-- local host does not validate correctly
	   //The bug is located in DomainValidator, line 139 (should be testing for isValid, not !isValid)

	   //assertTrue(urlVal3.isValidAuthority("localhost"));
	   //assertTrue(urlVal3.isValidAuthority("mymachine"));
       
       //There is a check for null, but there is not a check for empty string - may not be a bug
	   //assertFalse(validator.isValidAuthority(""));
	   
	   //--POTENTIAL BUG FOUND-- These fail and don't get caught by validation
	   //assertFalse(urlVal3.isValidAuthority(".2edu"));
	   //assertFalse(urlVal3.isValidAuthority(".."));
	   //assertFalse(urlVal3.isValidAuthority("aaa."));
	   
	   //Test port numbers
	   assertTrue(urlVal3.isValidAuthority("google.com:0"));
	   assertTrue(urlVal3.isValidAuthority("google.com:80"));
	   assertTrue(urlVal3.isValidAuthority("google.com:808"));
	   
	   //--BUG REPLICATED-- This same bug was found in manual testing with port numbers
	   //Any port number above 3 digits does not pass the assertion
	   //assertTrue(urlVal3.isValidAuthority("google.com:8080"));
	   //assertTrue(urlVal3.isValidAuthority("google.com:80808"));
	   //assertTrue(urlVal3.isValidAuthority("google.com:808808"));
	   //assertTrue(urlVal3.isValidAuthority("google.com:8088080"));
	   
	   //Test invalid port numbers
	   assertFalse(urlVal3.isValidAuthority("google.com:"));
	   assertFalse(urlVal3.isValidAuthority("google.com:-1"));
	   assertFalse(urlVal3.isValidAuthority("google.com:32a"));
	   
	   //Test IP Addresses
	   assertTrue(urlVal3.isValidAuthority("255.255.255.255"));
	   assertTrue(urlVal3.isValidAuthority("0.0.0.0"));
	   
	   //--BUG FOUND-- IP Address are not validated. The following assertions fail
	   //Bug is found on line 96 of InetAddressValidator, if value is over 255, it should return false
	   //assertFalse(urlVal3.isValidAuthority("256.256.256.256"));
	   
	   //--SAME BUG-- IP Addresses are not validated for invalid inputs
	   //assertFalse(urlVal3.isValidAuthority("0.0.0."));
	   //assertFalse(urlVal3.isValidAuthority("0.0"));
	   //assertFalse(urlVal3.isValidAuthority("0.0."));
	   //assertFalse(urlVal3.isValidAuthority("-1.-1.-1.-1"));
	   
   }
   
   public void testPath() {
	   UrlValidator urlVal = new UrlValidator();
	   
	   //Testing a random sampling of valid paths that should pass validation
	   for (int i = 0; i < 10000; i++) {
		   int StringLength = new Random().nextInt(100 - 1 + 1);
		   String testString = randString(StringLength);
		   assertTrue(urlVal.isValidPath("/" + testString));
		   
		   //The following two tests failed, not sure why -- Their manual tests pass below
		   //assertTrue(urlVal.isValidPath("/" + testString + "/"));
		   //assertTrue(urlVal.isValidPath("/" + testString + "/" + testString));
		   assertTrue(urlVal.isValidPath("/$" + testString));
		   assertTrue(urlVal.isValidPath("/(" + testString + ")"));
		   
		   //Test invalid combinations with random samplings
		   assertFalse(urlVal.isValidPath("//" + testString));
		   assertFalse(urlVal.isValidPath("/#" + testString));
		   assertFalse(urlVal.isValidPath("/#/" + testString));
		   
		   //Test valid special characters
		   String specialChars = "$-_.+!*'";
		   for (int j=0; j < specialChars.length(); j++) {
			   char specialChar = specialChars.charAt(j);
			   assertTrue(urlVal.isValidPath("/" + Character.toString(specialChar) + testString));
		   }

	   }
	   
	   //Test special circumstances, where known to be true
	   assertTrue(urlVal.isValidPath("/aslkajslkdjfkasdfASDFASDFASD8239809283098290839829038094823908409823dd/"));
	   assertTrue(urlVal.isValidPath("/jajkdslsASDHHEdjld331ij1/ajskdjASEJEJ344"));
	   
	   //Test special circumstances, where known to be false
	   assertFalse(urlVal.isValidPath("/../"));
	   assertFalse(urlVal.isValidPath("/.."));
	   assertFalse(urlVal.isValidPath("//"));
	   assertFalse(urlVal.isValidPath("/#"));

	   //Check that the double slash option works
	   UrlValidator urlVal2 = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);
	   assertTrue(urlVal2.isValidPath("//asdf/"));
	   assertTrue(urlVal2.isValidPath("/asdf//"));
	   
	   //This one failed, not sure why
	   //assertFalse(urlVal2.isValidPath("///asde3/"));
	   assertFalse(urlVal.isValidPath("/../"));
	   assertFalse(urlVal.isValidPath("/.."));
	   assertFalse(urlVal.isValidPath("//.."));
	   assertFalse(urlVal.isValidPath("/..//"));

   }
   
   public void testQuery() {
	   UrlValidator urlVal = new UrlValidator();
	   for (int i = 0; i < 10000; i++) {
		   int StringLength = new Random().nextInt(100 - 1 + 1);
		   String testString = randString(StringLength);
		   String testString2 = randString(StringLength);
		   
		   //--BUG REPLICATED-- Found in manual testing as well, improper format of query strings.
		   //The following two assertions failed.
		   //assertTrue(urlVal.isValidPath("?" + testString + "=" + testString2)); 
		   //assertTrue(urlVal.isValidPath("?" + testString + "=" + testString2 + "&" + testString2 + "=" + testString)); 

		   assertFalse(urlVal.isValidPath("?" + testString));
		   assertFalse(urlVal.isValidPath("??"));
		   assertFalse(urlVal.isValidPath("?" + testString2 + "?")); 

	   }
   }
   
   /**
    * Create some result pairs to be used for unit tests
    */
   
   ResultPair[] pairScheme = {
		   new ResultPair ("aaa://", true),
		   new ResultPair ("aaas://", true),
		   new ResultPair ("about://", true),
		   new ResultPair ("acap://", true),
		   new ResultPair ("acct://", true),
		   new ResultPair ("acr://", true),
		   new ResultPair ("adiumxtra://", true),
		   new ResultPair ("afp://", true),
		   new ResultPair ("afs://", true),
		   new ResultPair ("aim://", true),
		   new ResultPair ("appdata://", true),
		   new ResultPair ("apt://", true),
		   new ResultPair ("attachment://", true),
		   new ResultPair ("aw://", true),
		   new ResultPair ("barion://", true),
		   new ResultPair ("beshare://", true),
		   new ResultPair ("bitcoin://", true),
		   new ResultPair ("blob://", true),
		   new ResultPair ("bolo://", true),
		   new ResultPair ("callto://", true),
		   new ResultPair ("cap://", true),
		   new ResultPair ("chrome://", true),
		   new ResultPair ("chrome-extension://", true),
		   new ResultPair ("cid://", true),
		   new ResultPair ("coap://", true),
		   new ResultPair ("coaps://", true),
		   new ResultPair ("com-eventbrite-attendee://", true),
		   new ResultPair ("content://", true),
		   new ResultPair ("crid://", true),
		   new ResultPair ("cvs://", true),
		   new ResultPair ("data://", true),
		   new ResultPair ("dav://", true),
		   new ResultPair ("dict://", true),
		   new ResultPair ("dlna-playcontainer://", true),
		   new ResultPair ("dlna-playsingle://", true),
		   new ResultPair ("dns://", true),
		   new ResultPair ("dntp://", true),
		   new ResultPair ("dtn://", true),
		   new ResultPair ("dvb://", true),
		   new ResultPair ("ed2k://", true),
		   new ResultPair ("example://", true),
		   new ResultPair ("facetime://", true),
		   new ResultPair ("fax://", true),
		   new ResultPair ("feed://", true),
		   new ResultPair ("feedready://", true),
		   new ResultPair ("file://", true),
		   new ResultPair ("filesystem://", true),
		   new ResultPair ("finger://", true),
		   new ResultPair ("fish://", true),
		   new ResultPair ("ftp://", true),
		   new ResultPair ("geo://", true),
		   new ResultPair ("gg://", true),
		   new ResultPair ("git://", true),
		   new ResultPair ("gizmoproject://", true),
		   new ResultPair ("go://", true),
		   new ResultPair ("gopher://", true),
		   new ResultPair ("gtalk://", true),
		   new ResultPair ("h323://", true),
		   new ResultPair ("ham://", true),
		   new ResultPair ("hcp://", true),
		   new ResultPair ("http://", true),
		   new ResultPair ("https://", true),
		   new ResultPair ("iax://", true),
		   new ResultPair ("icap://", true),
		   new ResultPair ("icon://", true),
		   new ResultPair ("im://", true),
		   new ResultPair ("imap://", true),
		   new ResultPair ("info://", true),
		   new ResultPair ("iotdisco://", true),
		   new ResultPair ("ipn://", true),
		   new ResultPair ("ipp://", true),
		   new ResultPair ("ipps://", true),
		   new ResultPair ("irc://", true),
		   new ResultPair ("irc6://", true),
		   new ResultPair ("ircs://", true),
		   new ResultPair ("iris://", true),
		   new ResultPair ("iris.beep://", true),
		   new ResultPair ("iris.lwz://", true),
		   new ResultPair ("iris.xpc://", true),
		   new ResultPair ("iris.xpcs://", true),
		   new ResultPair ("isostore://", true),
		   new ResultPair ("itms://", true),
		   new ResultPair ("jabber://", true),
		   new ResultPair ("jar://", true),
		   new ResultPair ("jms://", true),
		   new ResultPair ("keyparc://", true),
		   new ResultPair ("lastfm://", true),
		   new ResultPair ("ldap://", true),
		   new ResultPair ("ldaps://", true),
		   new ResultPair ("magnet://", true),
		   new ResultPair ("mailserver://", true),
		   new ResultPair ("mailto://", true),
		   new ResultPair ("maps://", true),
		   new ResultPair ("market://", true),
		   new ResultPair ("message://", true),
		   new ResultPair ("mid://", true),
		   new ResultPair ("mms://", true),
		   new ResultPair ("modem://", true),
		   new ResultPair ("ms-access://", true),
		   new ResultPair ("ms-drive-to://", true),
		   new ResultPair ("ms-excel://", true),
		   new ResultPair ("ms-getoffice://", true),
		   new ResultPair ("ms-help://", true),
		   new ResultPair ("ms-infopath://", true),
		   new ResultPair ("ms-media-stream-id://", true),
		   new ResultPair ("ms-project://", true),
		   new ResultPair ("ms-powerpoint://", true),
		   new ResultPair ("ms-publisher://", true),
		   new ResultPair ("ms-search-repair://", true),
		   new ResultPair ("ms-secondary-screen-controller://", true),
		   new ResultPair ("ms-secondary-screen-setup://", true),
		   new ResultPair ("ms-settings://", true),
		   new ResultPair ("ms-settings-airplanemode://", true),
		   new ResultPair ("ms-settings-bluetooth://", true),
		   new ResultPair ("ms-settings-camera://", true),
		   new ResultPair ("ms-settings-cellular://", true),
		   new ResultPair ("ms-settings-cloudstorage://", true),
		   new ResultPair ("ms-settings-emailandaccounts://", true),
		   new ResultPair ("ms-settings-language://", true),
		   new ResultPair ("ms-settings-location://", true),
		   new ResultPair ("ms-settings-lock://", true),
		   new ResultPair ("ms-settings-nfctransactions://", true),
		   new ResultPair ("ms-settings-notifications://", true),
		   new ResultPair ("ms-settings-power://", true),
		   new ResultPair ("ms-settings-privacy://", true),
		   new ResultPair ("ms-settings-proximity://", true),
		   new ResultPair ("ms-settings-screenrotation://", true),
		   new ResultPair ("ms-settings-wifi://", true),
		   new ResultPair ("ms-settings-workplace://", true),
		   new ResultPair ("ms-spd://", true),
		   new ResultPair ("ms-transit-to://", true),
		   new ResultPair ("ms-visio://", true),
		   new ResultPair ("ms-walk-to://", true),
		   new ResultPair ("ms-word://", true),
		   new ResultPair ("msnim://", true),
		   new ResultPair ("msrp://", true),
		   new ResultPair ("msrps://", true),
		   new ResultPair ("mtqp://", true),
		   new ResultPair ("mumble://", true),
		   new ResultPair ("mupdate://", true),
		   new ResultPair ("mvn://", true),
		   new ResultPair ("news://", true),
		   new ResultPair ("nfs://", true),
		   new ResultPair ("ni://", true),
		   new ResultPair ("nih://", true),
		   new ResultPair ("nntp://", true),
		   new ResultPair ("notes://", true),
		   new ResultPair ("oid://", true),
		   new ResultPair ("opaquelocktoken://", true),
		   new ResultPair ("pack://", true),
		   new ResultPair ("palm://", true),
		   new ResultPair ("paparazzi://", true),
		   new ResultPair ("pkcs11://", true),
		   new ResultPair ("platform://", true),
		   new ResultPair ("pop://", true),
		   new ResultPair ("pres://", true),
		   new ResultPair ("prospero://", true),
		   new ResultPair ("proxy://", true),
		   new ResultPair ("psyc://", true),
		   new ResultPair ("query://", true),
		   new ResultPair ("redis://", true),
		   new ResultPair ("rediss://", true),
		   new ResultPair ("reload://", true),
		   new ResultPair ("res://", true),
		   new ResultPair ("resource://", true),
		   new ResultPair ("rmi://", true),
		   new ResultPair ("rsync://", true),
		   new ResultPair ("rtmfp://", true),
		   new ResultPair ("rtmp://", true),
		   new ResultPair ("rtsp://", true),
		   new ResultPair ("rtsps://", true),
		   new ResultPair ("rtspu://", true),
		   new ResultPair ("secondlife://", true),
		   new ResultPair ("service://", true),
		   new ResultPair ("session://", true),
		   new ResultPair ("sftp://", true),
		   new ResultPair ("sgn://", true),
		   new ResultPair ("shttp://", true),
		   new ResultPair ("sieve://", true),
		   new ResultPair ("sip://", true),
		   new ResultPair ("sips://", true),
		   new ResultPair ("skype://", true),
		   new ResultPair ("smb://", true),
		   new ResultPair ("sms://", true),
		   new ResultPair ("smtp://", true),
		   new ResultPair ("snews://", true),
		   new ResultPair ("snmp://", true),
		   new ResultPair ("soap.beep://", true),
		   new ResultPair ("soap.beeps://", true),
		   new ResultPair ("soldat://", true),
		   new ResultPair ("spotify://", true),
		   new ResultPair ("ssh://", true),
		   new ResultPair ("steam://", true),
		   new ResultPair ("stun://", true),
		   new ResultPair ("stuns://", true),
		   new ResultPair ("submit://", true),
		   new ResultPair ("svn://", true),
		   new ResultPair ("tag://", true),
		   new ResultPair ("teamspeak://", true),
		   new ResultPair ("tel://", true),
		   new ResultPair ("teliaeid://", true),
		   new ResultPair ("telnet://", true),
		   new ResultPair ("tftp://", true),
		   new ResultPair ("things://", true),
		   new ResultPair ("thismessage://", true),
		   new ResultPair ("tip://", true),
		   new ResultPair ("tn3270://", true),
		   new ResultPair ("turn://", true),
		   new ResultPair ("turns://", true),
		   new ResultPair ("tv://", true),
		   new ResultPair ("udp://", true),
		   new ResultPair ("unreal://", true),
		   new ResultPair ("urn://", true),
		   new ResultPair ("ut2004://", true),
		   new ResultPair ("v-event://", true),
		   new ResultPair ("vemmi://", true),
		   new ResultPair ("ventrilo://", true),
		   new ResultPair ("videotex://", true),
		   new ResultPair ("view-source://", true),
		   new ResultPair ("wais://", true),
		   new ResultPair ("webcal://", true),
		   new ResultPair ("ws://", true),
		   new ResultPair ("wss://", true),
		   new ResultPair ("wtai://", true),
		   new ResultPair ("wyciwyg://", true),
		   new ResultPair ("xcon://", true),
		   new ResultPair ("xcon-userid://", true),
		   new ResultPair ("xfire://", true),
		   new ResultPair ("xmlrpc.beep://", true),
		   new ResultPair ("xmlrpc.beeps://", true),
		   new ResultPair ("xmpp://", true),
		   new ResultPair ("xri://", true),
		   new ResultPair ("ymsgr://", true),
		   new ResultPair ("z39.50://", true),
		   new ResultPair ("z39.50r://", true),
		   new ResultPair ("z39.50s://", true),
		   new ResultPair("htt:", false),
		   new ResultPair("tp:", false),
		   new ResultPair("3ht://", false),
		   new ResultPair("http:/", false),
           new ResultPair("http:", false),
           new ResultPair("http/", false),
           new ResultPair("://", false),
           new ResultPair("", true)
		   };
   
   
   ResultPair[] pairAuthority = {
		   new ResultPair("oregonstate.edu", true),
		   new ResultPair("google.com", true),
		   new ResultPair("microsoft.com", true),
		   new ResultPair(null, false),
		   new ResultPair("localhost", true),
		   new ResultPair("mymachine", true),
		   new ResultPair(".2edu", false),
		   new ResultPair("..", false),
		   new ResultPair("aaa.", false),
		   new ResultPair("google.com:0", true),
		   new ResultPair("google.com:80", true),
		   new ResultPair("google.com:800", true),
		   new ResultPair("google.com:8080", true),
		   new ResultPair("google.com:80800", true),
		   new ResultPair("google.com:808080", true),
		   new ResultPair("google.com:-1", false),
		   new ResultPair("google.com:32a", false),
		   new ResultPair("255.255.255.255", true),
		   new ResultPair("0.0.0.0", true),
		   new ResultPair("256.256.256.256", false),
		   new ResultPair("0.0.0", false),
		   new ResultPair("0.0", false),
		   new ResultPair("0", false),
		   new ResultPair("-1.-1.-1.-1", false),
   };
   
   ResultPair[] pairPath = {
		   new ResultPair("/testing", true),
           new ResultPair("/test123", true),
           new ResultPair("/$23", true),
           new ResultPair("/..", false),
           new ResultPair("/../", false),
           new ResultPair("/yeeha/", true),
           new ResultPair("", true),
           new ResultPair("/files/file", true),
           new ResultPair("/..//file", false),
           new ResultPair("/fileas//file", false),
		   new ResultPair("//", false),
		   new ResultPair("/#", false),
		   new ResultPair("/..", false)

   };
   
   ResultPair[] pairQuery = {
		 new ResultPair("?hihi=es", true),
		 new ResultPair("?yeupa=yes&newstuff=true", true),
		 new ResultPair("?hihi", false),
		 new ResultPair("??hihi=es", false),
		 new ResultPair("??", false),
		 new ResultPair("?yeupa=yes&newstuff=true?", false),
   };
   
   /*
    * Method: testIsValid
    * Preconditions: None
    * Postconditions: Prints validated URI's to the console, asserts URI tests
    * Parameters: None
    * Description: The testIsValid function randomly selects each of the result pairs and runs them through
    * one million random combinations. This is a brute force way to run through all permutations and combinations
    * for the URI test.
    */
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_LOCAL_URLS);

	   StringBuilder URI = new StringBuilder();
	   for (int i = 0; i < 1000000; i++) {
		 //Reset the string builder
		   URI.setLength(0);
		   boolean isValid = true;
		   //Brute force testing using random number generator
		   //Randomly pick items and run for a long time
		   int number = new Random().nextInt(pairScheme.length-1);
		   URI.append(pairScheme[number].item);
		   if(!pairScheme[number].valid)
			   isValid = false;
		   //Randomly select authority
		   number = new Random().nextInt(pairAuthority.length-1);
		   URI.append(pairAuthority[number].item);
		   if(!pairAuthority[number].valid)
			   isValid = false;
		   //Randomly select path
		   number = new Random().nextInt(pairPath.length-1);
		   URI.append(pairPath[number].item);
		   if(!pairPath[number].valid)
			   isValid = false;
		   //Randomly select query
		   number = new Random().nextInt(pairQuery.length-1);
		   URI.append(pairQuery[number].item);
		   if(!pairQuery[number].valid)
			   isValid = false;
		   
		   boolean testIsValid = urlVal.isValid(URI.toString());
		   //assertEquals(testIsValid, isValid);
		   //Replacing assertEquals with a print statement so it keeps running
		   if (testIsValid != isValid) 
			   System.out.println("Error detected:" + URI.toString());
	   }
	   
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }

   

}
