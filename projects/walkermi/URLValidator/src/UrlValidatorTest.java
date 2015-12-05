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


/**
 * CS362-400 - Final Project Part B
 * Jason Gourley
 * James Riccelli
 * Michael Walker
 *
 * Performs Validation Test for url validations.
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

       ResultPair[] testAuthority = {
    		   new ResultPair("www.oregonstate.edu", true),
               new ResultPair("oregonstate.edu", true),
               new ResultPair("-oregonstate.edu", false),
               new ResultPair("oregonstate-.edu", false),
               new ResultPair("oregon-state.edu", true),
               new ResultPair("oregonstate", false),
               new ResultPair("test.com", true),
               new ResultPair("test.us", true),
               new ResultPair("test.biz", true),
               new ResultPair("test.tv", true),
               new ResultPair("", false)};

       
       final String testScheme = "http://";
       int errors = 0;

       for (int i = 0; i < testAuthority.length; i++) 
       {
           String newUrl = testScheme + testAuthority[i].item;
           boolean expected = testAuthority[i].valid;
           boolean result = urlVal.isValid(newUrl);
           
           if(result == expected){
        	   System.out.println(newUrl);  
           } else { 
        	   //assertEquals(newUrl, expected, result);
        	   System.err.println(newUrl);  
        	   errors++;
           }
       }
       if (errors > 0) {
    	   String message = "Errors = " + errors; 
    	   assertEquals(message, 0, errors);
       }		   
	   
   }
   

   /*
    * Partition test focused on URL scheme variations
    * 
    * */
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       
       ResultPair[] testScheme = {
    		   new ResultPair("http://", true),
    		   new ResultPair("HTTP://", true),
               new ResultPair("https://", true),
               new ResultPair("HTTPS://", true),
               new ResultPair("aaa://", true),
               new ResultPair("aaas://", true),
               new ResultPair("about://", true),
               new ResultPair("acap://", true),
               new ResultPair("acct://", true),
               new ResultPair("cap://", true),
               new ResultPair("cid://", true),
               new ResultPair("coap://", true),
               new ResultPair("coaps://", true),
               new ResultPair("chrome-extension://", true),
               new ResultPair("crid://", true),
               new ResultPair("data://", true),
               new ResultPair("dav://", true),
               new ResultPair("dict://", true),
               new ResultPair("dns://", true),
               new ResultPair("example://", true),
               new ResultPair("file://", true),
               new ResultPair("ftp://", true),
               new ResultPair("geo://", true),
               new ResultPair("go://", true),
               new ResultPair("gopher://", true),
               new ResultPair("h323://", true),
               new ResultPair("iax://", true),
               new ResultPair("icap://", true),
               new ResultPair("im://", true),
               new ResultPair("imap://", true),
               new ResultPair("info://", true),
               new ResultPair("ipp://", true),
               new ResultPair("ipps://", true),
               new ResultPair("iris://", true),
               new ResultPair("iris.beep://", true),
               new ResultPair("iris.lwz://", true),
               new ResultPair("iris.xpc://", true),
               new ResultPair("iris.xpcs://", true),
               new ResultPair("jabber://", true),
               new ResultPair("ldap://", true),
               new ResultPair("mailto://", true),
               new ResultPair("mid://", true),
    		   new ResultPair("ms-secondary-screen-controller://", true),
    		   new ResultPair("msrp://", true),
    		   new ResultPair("mtqp://", true),
    		   new ResultPair("mupdate://", true),
    		   new ResultPair("news://", true),
    		   new ResultPair("nfs://", true),
    		   new ResultPair("ni://", true),
    		   new ResultPair("nih://", true),
    		   new ResultPair("nntp://", true),
    		   new ResultPair("opaquelocktoken://", true),
    		   new ResultPair("pkcs11://", true),
    		   new ResultPair("pop://", true),
    		   new ResultPair("pres://", true),
    		   new ResultPair("reload://", true),
    		   new ResultPair("rtsp://", true),
    		   new ResultPair("rtsps://", true),
    		   new ResultPair("rtspu://", true),
    		   new ResultPair("service://", true),
    		   new ResultPair("session://", true),
    		   new ResultPair("shttp://", true),
    		   new ResultPair("sieve://", true),
    		   new ResultPair("sip://", true),
    		   new ResultPair("sips://", true),
    		   new ResultPair("sms://", true),
    		   new ResultPair("snmp://", true),
    		   new ResultPair("soap.beep://", true),
    		   new ResultPair("soap.beeps://", true),
    		   new ResultPair("stun://", true),
    		   new ResultPair("stuns://", true),
    		   new ResultPair("tag://", true),
    		   new ResultPair("tel://", true),
    		   new ResultPair("telnet://", true),
    		   new ResultPair("tftp://", true),
    		   new ResultPair("thismessage://", true),
    		   new ResultPair("tip://", true),
    		   new ResultPair("tn3270://", true),
    		   new ResultPair("turn://", true),
    		   new ResultPair("turns://", true),
    		   new ResultPair("tv://", true),
    		   new ResultPair("urn://", true),
    		   new ResultPair("vemmi://", true),
    		   new ResultPair("ws://", true),
    		   new ResultPair("wss://", true),
    		   new ResultPair("xcon://", true),
    		   new ResultPair("xcon-userid://", true),
    		   new ResultPair("xmlrpc.beep://", true),
    		   new ResultPair("xmlrpc.beeps://", true),
    		   new ResultPair("xmpp://", true),
    		   new ResultPair("z39.50r://", true),
    		   new ResultPair("z39.50s://", true),
    		   new ResultPair("123://", false),
    		   new ResultPair("a://", true),
    		   new ResultPair("a+://", true),
    		   new ResultPair("a+b://", true),
    		   new ResultPair("a-://", true),
    		   new ResultPair("a-b://", true),
    		   new ResultPair("a.://", true),
    		   new ResultPair("a.b://", true),
    		   new ResultPair("http:///", false),
    		   new ResultPair("http:/", false),
               new ResultPair("http:", false),
               new ResultPair("http/", false),
               new ResultPair("http:\\", false),
               new ResultPair("http:\\\\", false),
               new ResultPair("://", false),
       };
       
       final String testServer = "oregonstate";
       final String testTld = ".edu";
       int errors = 0;

       for (int i = 0; i < testScheme.length; i++) 
       {
           String newUrl = testScheme[i].item + testServer + testTld;
           boolean expected = testScheme[i].valid;
           boolean result = urlVal.isValid(newUrl);
           
           if(result == expected){
        	   System.out.println(newUrl);  
           } else { 
        	   //assertEquals(newUrl, expected, result);
        	   System.err.println(newUrl);  
        	   errors++;
           }
       }
       if (errors > 0) {
    	   String message = "Errors = " + errors; 
    	   assertEquals(message, 0, errors);
       }
   }
   
   /*
    * Partition test focused on URL Domain Host, Label, and TLD combinations
    * 
    * */   
   public void testYourSecondPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       
       ResultPair[] testAuthority = {
    		   new ResultPair("", false),
    		   new ResultPair("a", false),
               new ResultPair("a.b", false),
               new ResultPair("a.b.c", false),
               new ResultPair("a.b.c.d", false),
               new ResultPair("a.b.c.d.com", true),
               new ResultPair("a.b.c.com", true),
               new ResultPair("a.b.com", true),
               new ResultPair("a.com", true),       
               new ResultPair("-a.com", false),
               new ResultPair("a-.com", false),
               new ResultPair("a-b.com", true),
               new ResultPair("a-b-.com", false),
               new ResultPair("a-b-c.com", true),
               new ResultPair("a-b-c-.com", false),
               new ResultPair("a-b-c-d.com", true),
               new ResultPair("a_b_c_d.com", false),
               new ResultPair("a_b_c_.com", false),
               new ResultPair("_a_b_c.com", false),
               new ResultPair("a?.com", false),
               new ResultPair("a!.com", false),
               new ResultPair("a#.com", false),
               new ResultPair("a$.com", false),
               new ResultPair("a%.com", false),
               new ResultPair("a^.com", false),
               new ResultPair("a&.com", false),
               new ResultPair("a*.com", false),
               new ResultPair("a(.com", false),
               new ResultPair("a).com", false),
               new ResultPair("192.168.1.1", true),
               new ResultPair("192.168.1", false),
               new ResultPair("192.168", false),
               new ResultPair("192", false),
               new ResultPair("0", false),
               new ResultPair("0.", false),
               new ResultPair("0.0", false),
               new ResultPair("0.0.", false),
               new ResultPair("0.0.0", false),
               new ResultPair("0.0.0.", false),
               new ResultPair("0.0.0.0", true),
               new ResultPair("255.255.255.255", true),
               new ResultPair("256.256.256.256", false),
               new ResultPair("255.255.255.255.255", false),
               new ResultPair("255.255.255.255.", false),
               new ResultPair("255.com", true),               
               new ResultPair(".com", false),
               new ResultPair("TEST.com", true),
               new ResultPair("test.COM", true),
               new ResultPair("TEST.COM", true),
               new ResultPair("TEST.CoM", true),
               new ResultPair("TEST.cOm", true),
               new ResultPair("tEsT.cOm", true),
               new ResultPair("test.aa", false),
               new ResultPair("test.a", false),
               new ResultPair("test.123", false),
               new ResultPair("test.1", false),
               new ResultPair("1.com", true),
               new ResultPair("1.us", false),
               new ResultPair("1abc.com", true),
               new ResultPair("abc1.com", true),
               new ResultPair("1abc.us", true),
               new ResultPair("abc1.us", true),
               new ResultPair("abc.us", true),
               new ResultPair("aaa.", false),
               new ResultPair(".aaa", false),
               new ResultPair("aaa", false),
               new ResultPair("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk.com", true),
               new ResultPair("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk.abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk.com", true),
               new ResultPair("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcde1abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk2abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk3abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopq.com", true),
               new ResultPair("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcde1abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk2abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk3abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv.com", false),
       };

       final String testScheme = "http://";
       
       int errors = 0;

       for (int i = 0; i < testAuthority.length; i++) 
       {
           String newUrl = testScheme + testAuthority[i].item;
           boolean expected = testAuthority[i].valid;
           boolean result = urlVal.isValid(newUrl);
           
           if(result == expected){
        	   System.out.println(newUrl);  
           } else { 
        	   //assertEquals(newUrl, expected, result);
        	   System.err.println(newUrl);  
        	   errors++;
           }
       }
       if (errors > 0) {
    	   String message = "Errors = " + errors; 
    	   assertEquals(message, 0, errors);
       }	   
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
