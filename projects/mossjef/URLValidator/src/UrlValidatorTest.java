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
		   System.out.println(testString);
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
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
