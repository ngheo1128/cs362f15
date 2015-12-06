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

/**
 * CS362-400 - Final Project Part B
 * Jason Gourley
 * James Riccelli
 * Michael Walker
 *
 * Performs Validation Test for URI validations.
 */

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   /*
    * Manual tests covering various real websites and known invalid URIs
    * */   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //.com
	   System.out.println("Manual testing Valid Urls:");
	   System.out.println(String.format( "http://www.amazon.com") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.amazon.com"));
	   System.out.println(String.format( "http://www.google.com") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.google.com"));
	   System.out.println(String.format( "http://www.facebook.com") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://facebook.com"));
	   System.out.println(String.format( "http://www.nhl.com") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.nhl.com"));
	   //.org
	   System.out.println(String.format( "http://www.wikipedia.org") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.wikipedia.org"));
	   System.out.println(String.format( "http://www.craigslist.org/") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.craigslist.org/"));
	   System.out.println(String.format( "https://wordpress.org/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("https://wordpress.org/"));
	   System.out.println(String.format( "https://www.mozilla.org") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("https://www.mozilla.org"));
	   
	   //.mil
	   System.out.println(String.format( "http://www.uscg.mil") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.uscg.mil"));
	   System.out.println(String.format( "www.navy.mil/") + "\t\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.navy.mil"));
	   System.out.println(String.format( "www.army.mil") + "\t\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.army.mil"));
	   System.out.println(String.format( "www.af.mil/") + "\t\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.af.mil/"));
	   
	   //.io
	   System.out.println(String.format( "http://socket.io/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://socket.io/"));
	   System.out.println(String.format( "http://getyarn.io/yarn-popular") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://getyarn.io/yarn-popular"));
	   System.out.println(String.format( "http://getyarn.io") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://getyarn.io"));
	   System.out.println(String.format( "http://mean.io/#!/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://mean.io/#!/"));
	   
	   //.edu
	   System.out.println(String.format( "http://oregonstate.edu/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://oregonstate.edu/"));
	   System.out.println(String.format( "http://www.berkeley.edu/") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.berkeley.edu/"));
	   System.out.println(String.format( "http://www2.howard.edu/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www2.howard.edu/"));
	   System.out.println(String.format( "http://www.farmingdale.edu/") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.farmingdale.edu/"));
	   
	   //.int
	   System.out.println(String.format( "http://www.itu.int/en/Pages/default.aspx") + "\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.itu.int/en/Pages/default.aspx"));
	   System.out.println(String.format( "http://www.who.int/en/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.who.int/en/"));
	   System.out.println(String.format( "http://www.oie.int/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.oie.int/"));
	   System.out.println(String.format( "http://boards.4chan.org/int/") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://boards.4chan.org/int/"));
	   
	   //.tv
	   System.out.println(String.format( "http://www.maker.tv/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.maker.tv/"));
	   System.out.println(String.format( "http://www.twitch.tv") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.twitch.tv"));
	   System.out.println(String.format( "http://wordpress.tv/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://wordpress.tv/"));
	   System.out.println(String.format( "http://i.tv/") + "\t\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://i.tv/"));
	   
	   // .country
	   System.out.println(String.format( "https://cira.ca/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("https://cira.ca/"));
	   System.out.println(String.format( "http://www.tsn.ca/") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.tsn.ca/"));
	   System.out.println(String.format( "http://www.watchfree.to/") + "\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("http://www.watchfree.to/"));
	   System.out.println(String.format( "https://www.denic.de/en/homepage.html") + "\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("https://www.denic.de/en/homepage.html"));
	  
	   //invalid tests *******************************************************************************************************
	   System.out.println("\nManual testing invalid Urls:");
	   System.out.println(String.format("http://www.amazon") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://www.amazon"));
	   System.out.println(String.format( "http://ww.google.com") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://ww.google.com"));
	   System.out.println(String.format( "http://www.facebook.om") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://www.facebook.om"));
	   System.out.println(String.format( "http://www.nhl.c") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://www.nhl.c"));
	   //.org
	   System.out.println(String.format( "htp://www.wikipedia.org") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("htp://www.wikipedia.org"));
	   System.out.println(String.format( "h:///www.craigslist.org/") + "\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("h:///www.craigslist.org/"));
	   System.out.println(String.format( "https:///wordpress.org/") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("https:///wordpress.org/"));
	   System.out.println(String.format( "https://wwwmozilla.org") + "\t\t\t\t" + "Expected: true\t\tActual: " + urlVal.isValid("https://wwwmozilla.org"));
	   
	   //.io
	   System.out.println(String.format( "http://socketio/") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://socketio/"));
	   System.out.println(String.format( "htt://getyarn.io/yarn-popular") + "\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("htt://getyarn.io/yarn-popular"));
	   System.out.println(String.format( "http//getyarn.io") + "\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http//getyarn.io"));
	   System.out.println(String.format( "http://.io/#!/") + "\t\t\t\t\t" + "Expected: false\t\tActual: " + urlVal.isValid("http://.io/#!/"));	   
	   
   }
   

   /*
    * Partition test focused on URL scheme variations
    * */
   public void testYourFirstPartition()
   {
	   String message = "\nBegginning testYourFirstPartition()";
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
       if (errors == 0) {
		   message = "End testYourFirstPartition(): Errors = " + errors + "\n"; 
		   System.out.println(message);  
	   }
	   else {
		   message = "End testYourFirstPartition(): Errors = " + errors + "\n"; 
		   System.err.println(message);  
		   assertEquals(message, 0, errors);
	   }
   }
   
   
   /*
    * Partition test focused on URL Domain Host, Label, and TLD combinations
    * */   
   public void testYourSecondPartition(){
	   String message = "\nBegginning testYourSecondPartition()";
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
       if (errors == 0) {
		   message = "End testYourSecondPartition(): Errors = " + errors + "\n"; 
		   System.out.println(message);  
	   }
	   else {
		   message = "End testYourSecondPartition(): Errors = " + errors + "\n"; 
		   System.err.println(message);  
		   assertEquals(message, 0, errors);
	   }   
   }
   
   
   /*
    * Unit tests focused on combinations of various valid and invalid URL scheme elements
    * */
   public void testIsValid()
   {
	   String message = "\nBegginning testIsValid()";
	   System.out.println(message);  
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   ResultPair[] testUrlScheme = {
			   new ResultPair("", true),
			   new ResultPair(" ", false),
			   new ResultPair("http://", true),
			   new ResultPair("https://", true),
			   new ResultPair("ftp://", true),
			   new ResultPair("pop://", true),
			   new ResultPair("smtp://", true),
			   new ResultPair("imap://", true),
			   new ResultPair("ht tps://", false),
			   new ResultPair("https:/", false),
			   new ResultPair("https//", false),
			   new ResultPair("https:", false)
	   };

	   ResultPair[] testUrlSubdomain = {
			   new ResultPair("", true),
			   new ResultPair(" ", false),
			   new ResultPair("www.", true),
			   new ResultPair("video.", true),
			   new ResultPair("vi deo.", false)
	   };
	   
	   ResultPair[] testUrlDomain = {
			   new ResultPair("", false),
			   new ResultPair("\\", false),
			   new ResultPair("/", false),
			   new ResultPair(" ", false),
			   new ResultPair("google", false),
			   new ResultPair("google.com", true),
			   new ResultPair("google.net", true),
			   new ResultPair("goo gle.com", false),
	   };
	   
	   ResultPair[] testUrlPort = {
			   new ResultPair("", true),
			   new ResultPair(":0", true),
			   new ResultPair(":10", true),
			   new ResultPair(":100", true),
			   new ResultPair(":999", true),
			   new ResultPair(":1000", true),
			   new ResultPair(":10000", true),
			   new ResultPair(":002", false),
			   new ResultPair(":0002", false),
			   new ResultPair(":0 1", false)
	   };
	   
	   ResultPair[] testPath = {
			   new ResultPair("", true),
			   new ResultPair("/", true),
			   new ResultPair("/test", true),
			   new ResultPair("/te st", false),
			   new ResultPair("//", false),
			   new ResultPair("/?/", false),
	   };
	   
	   int errors = 0;
	   int numURLsTested = 0;
	   String expectedString;
	   String actualString;
	   boolean expected;
	   
	   // iterate through all testUrlXXX arrays
	   for (int i = 0; i < testUrlScheme.length; i++) 
       {
		   for (int ii = 0; ii < testUrlSubdomain.length; ii++) 
	       {
			   for (int iii = 0; iii < testUrlDomain.length; iii++) 
		       {
				   for (int iiii = 0; iiii < testUrlPort.length; iiii++) 
			       {
					   for (int iiiii = 0; iiiii < testPath.length; iiiii++) 
				       {
						   // create current permutation of testUrlXXX arrays
						   String newUrl = testUrlScheme[i].item + testUrlSubdomain[ii].item + testUrlDomain[iii].item + testUrlPort[iiii].item + testPath[iiiii].item;
						   
						   // check if any parts of current test URL are invalid
						   expected = true;
						   if (!testUrlScheme[i].valid || !testUrlSubdomain[ii].valid || !testUrlDomain[iii].valid || !testUrlPort[iiii].valid || !testPath[iiiii].valid) {
							   expected = false;
						   }
						   
						   // run current permutation of testUrlXXX arrays through URL validator
						   boolean result = urlVal.isValid(newUrl);
					       
						   // check if actual results equal expected results
					       if(result != expected){
					    	   if (expected == true) {
					    		   expectedString = "True";
					    		   actualString = "False";
					    	   }
					    	   else {
					    		   expectedString = "False";
					    		   actualString = "True";
					    	   }
					    	   
					    	   System.err.println("\t" + newUrl);
					    	   System.err.println("\tExpected: " + expectedString + "  Actual: " + actualString + "\n");
					    	   errors++;
					       }
					       else {
					    	   //System.out.println("\t" + newUrl);  
					       }
					       numURLsTested++;
				       }
			       }
		       }
	       }
       }
	   
	   if (errors == 0) {
		   message = "End testIsValid(): Number of URLs Tested: " + numURLsTested + "  Errors = " + errors + "\n"; 
		   System.out.println(message);  
	   }
	   else {
		   message = "End testIsValid(): Number of URLs Tested: " + numURLsTested + "  Errors = " + errors + "\n"; 
		   System.err.println(message);  
		   assertEquals(message, 0, errors);
	   }
   }
  
   
   public void testAnyOtherUnitTest()
   {

   }

}
