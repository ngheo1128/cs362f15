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

   
   // Some of my unitTest are randomTest for extra credit consideration. Those randomtest are
   // portTest() and ipv4Test()
   public void testManualTest1()
   {
	   //this manual test is khiem initial tests
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));		//return true

	   /*
	   
	   //tests should return true
	   System.out.println("tests should return true");
	   System.out.println(urlVal.isValid("ftp://www.amazon.com"));					//true
	   System.out.println(urlVal.isValid("h3t://www.amazon.com"));					//true
	   System.out.println(urlVal.isValid("www.amazon.com"));						//false	--> bug empty scheme
	   System.out.println(urlVal.isValid("http://255.255.255.255"));				//true
	   System.out.println(urlVal.isValid("http://amazon.au"));						//true
	   System.out.println(urlVal.isValid("http://www.amazon.com:80"));				//true
	   System.out.println(urlVal.isValid("http://www.amazon.com:65535"));			//false	--> bug, valid port
	   System.out.println(urlVal.isValid("http://www.amazon.com/test1"));			//true
	   System.out.println(urlVal.isValid("http://go.cc"));							//true
	   System.out.println(urlVal.isValid("http://www.amazon.com?action=view"));		//false --> bug in query
	   System.out.println(urlVal.isValid("http://www.amazon.com?action=edit&mode=up"));		//false --> bug in query
	   
	   //test should return false
	   System.out.println("tests should return false");
	   System.out.println(urlVal.isValid("3ht://www.amazon.com"));		//false
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));		//false
	   System.out.println(urlVal.isValid("http/www.amazon.com"));		//false
	   System.out.println(urlVal.isValid("://www.amazon.com"));			//false
	   System.out.println(urlVal.isValid("http://wwwamazon.com"));		//true, no period after www --> bug
	   System.out.println(urlVal.isValid("htp://www.amazon.com"));		//true, invalid scheme	--> bug
	   System.out.println(urlVal.isValid("stupidscheme://www.amazon.com"));	//true, invalid scheme	--> bug
	   System.out.println(urlVal.isValid("http://ww.amazon.com"));		//true, invalid only 2 ww --> bug
	   System.out.println(urlVal.isValid("http://www.a.ma.zon.com"));	//true	multiple period --> bug
	   System.out.println(urlVal.isValid("http://1.2.3"));				//false
	   System.out.println(urlVal.isValid("http://www.amazon.com:-1"));	//false
	   System.out.println(urlVal.isValid("http://www.amazon.com:65a"));		//false
	   System.out.println(urlVal.isValid("http://go.au"));				//true	invalid authority --> bug
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("3ht://www.amazon.com"));
	   System.out.println(urlVal.isValid("http:www.amazon.com"));
	   System.out.println(urlVal.isValid("http/www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.amazon.com?stupidQuery"));		//false 
	   System.out.println(urlVal.isValid("http://www.amazon.com?incorrected"));		//false
	   
		*/
   }
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("General Manual Tests:");
	   System.out.println("");
	   
	   //tests that should return true
	   
	   System.out.println("URLs that should return true:");
	   System.out.println("");
	   
	   String[] validURLs = {
			   "http://www.amazon.com",
			   "ftp://www.amazon.com",
			   "h3t://www.amazon.com",
			   "http://255.255.255.255",
			   "http://amazon.au",
			   "http://www.amazon.com:80",
			   "http://www.amazon.com:65535",
			   "http://www.amazon.com/test1",
			   "http://go.cc",
			   "http://www.amazon.com?action=view",
			   "http://www.amazon.com?action=edit&mode=up"
	   };
	   
	   for (String url : validURLs) {
		   System.out.println(urlVal.isValid(url) + ": " + url);
	   }
	   
	   //tests that should return false
	   
	   System.out.println("");
	   System.out.println("URLs that should return false:");
	   System.out.println("");
	   
	   String[] invalidURLs = {
			   "www.amazon.com",
			   "3ht://www.amazon.com",
			   "http:/www.amazon.com",
			   "http/www.amazon.com",
			   "://www.amazon.com",
			   "htp://www.amazon.com",
			   "stupidscheme://www.amazon.com",
			   "http://1.2.3",
			   "http://www.amazon.com:-1",
			   "http://www.amazon.com:65a",
			   "http:www.amazon.com",
			   "http/www.amazon.com"
	   };
	   
	   for (String url : invalidURLs) {
		   System.out.println(urlVal.isValid(url) + ": " + url);
	   }
	   
	   
	   //ipv4
	   
	   System.out.println("");
	   System.out.println("IPv4 Address Tests:");
	   System.out.println("");
	   
	   //tests that should return true
	   
	   System.out.println("IPs that should return true:");
	   System.out.println("");
	   
	   String[] validIPs = {
			   "http://192.168.0.1",
			   "http://0.0.0.0",
			   "http://255.255.255.255"
	   };
	   
	   for (String ip : validIPs) {
		   System.out.println(urlVal.isValid(ip) + ": " + ip);
	   }
	   
	   
	   //tests that should return false
	   
	   System.out.println("");
	   System.out.println("IPs that should return false:");
	   System.out.println("");
	   
	   String[] invalidIPs = {
			   "http://192.168.0.-1",
			   "http://0.0.0.256",
			   "http://256.256.256.256",
			   "http://0.0.a.0"
	   };
	   
	   for (String ip : invalidIPs) {
		   System.out.println(urlVal.isValid(ip) + ": " + ip);
	   }
	   
	   System.out.println("");
	   System.out.println("End of Manual Tests");
	   System.out.println("");

   }
   
   /*
   we split the input domain to the URL scheme, authority, port, and query. Then
we split it even further with valid and invalid input for each part of the url,
this will minimize the area of bug that will occur. For example if the test for set of
valid scheme input pass, which means that the program validate the valid scheme
input properly. On the other hand, if the test for set of invalid scheme inputs
fail, this indicate that the program have bug in the area where the program check
for invalid scheme input.
*/
   
   public void testYourFirstPartition()
   {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if (urlVal.isValid("http://www.amazon.com") &&
		   urlVal.isValid("ftp://www.amazon.com") &&
		   urlVal.isValid("h3t://www.amazon.com") &&
		   urlVal.isValid("www.amazon.com"))
	   {
		   System.out.println("valid input schemes, pass");
	   }
	   else
	   {
		   System.out.println("valid input schemes, fail");
	   }
	   //valid input scheme fail
	   if (!urlVal.isValid("3ht://www.amazon.com") &&
			   !urlVal.isValid("http:/www.amazon.com") &&
			   !urlVal.isValid("http:www.amazon.com") &&
			   !urlVal.isValid("http/www.amazon.com") &&
			   !urlVal.isValid("://www.amazon.com"))
		   {
			   System.out.println("invalid input schemes, pass");
		   }
		   else
		   {
			   System.out.println("invalid input schemes, fail");
		   }
		
   }
   
   public void testYourSecondPartition(){
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if (!urlVal.isValid("http://www.amazon.com") &&
			   !urlVal.isValid("http://go.com") &&
			   !urlVal.isValid("http://go.au") &&
			   !urlVal.isValid("http://0.0.0.0") &&
			   !urlVal.isValid("http://go.a") &&
			   !urlVal.isValid("http://.aaa"))
		   {
			   System.out.println("invalid input authority, pass");
		   }
		   else
		   {
			   System.out.println("invalid input authority, fail");
		   }
		   // valid input authority fail
	   if (urlVal.isValid("http://256.256.256.256") &&
			   urlVal.isValid("http://1.2.3.4.5") &&
			   urlVal.isValid("http://wwwamazon.com") &&
			   urlVal.isValid("http://ww.amazon.com") &&
			   urlVal.isValid("http://255.255.255.255"))
		   {
			   System.out.println("valid input authority, pass");
		   }
		   else
		   {
			   System.out.println("valid input authority, fail");
		   }
		   //invalid input authority also fail
		   
   }
   
   public void testYourThirdPartition(){
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if (urlVal.isValid("http://www.amazon.com:69") &&
			   urlVal.isValid("http://www.amazon.com:654321") &&
			   urlVal.isValid("http://www.amazon.com:0") &&
			   urlVal.isValid("http://www.amazon.com") &&
			   urlVal.isValid("http://www.amazon.com:55555") )
		   {
			   System.out.println("valid input port, pass");
		   }
		   else
		   {
			   System.out.println("valid input port, fail");
		   }
	   //valid input port fail, there is bug in port validator
	   if (!urlVal.isValid("http://www.amazon.com:-1") &&
			   !urlVal.isValid("http://www.amazon.com:-10") &&
			   !urlVal.isValid("http://www.amazon.com:a2") &&
			   !urlVal.isValid("http://www.amazon.com:35e") )
		   {
			   System.out.println("invalid input port, pass");
		   }
		   else
		   {
			   System.out.println("invalid input port, fail");
		   }
		   
   }
   
   
   public void testIsValid()
   {
	   testScheme();
	   testPort();
	   testQuery();
	   testAuthority();
	   testRandomPort();
	   testRandomIpv4();
   }
   
   public void testScheme()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Scheme Tests:");
	   System.out.println("");
	   
	   System.out.println("Schemes that should return true:");
	   System.out.println("");
	   
	   String[] validSchemes = {
			   "http://",
			   "ftp://",
			   "h3t://"
	   };
	   
	   for (String scheme : validSchemes) {
		   String url = scheme + "www.amazon.com";
		   System.out.println(urlVal.isValid(url) + ": " + scheme);
	   }
	   
	   System.out.println("");
	   
	   System.out.println("Schemes that should return false:");
	   System.out.println("");
	   
	   String[] invalidSchemes = {
			   "3ht://",
			   "http:/",
			   "http:",
			   "://",
			   "",
			   "htp://",
			   "stupidscheme://"
	   };
	   
	   for (String scheme : invalidSchemes) {
		   String url = scheme + "www.amazon.com";
		   System.out.println(urlVal.isValid(url) + ": " + scheme);
	   }
	   
	   System.out.println("");
   }
   
public void testPort(){
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Port Tests:");
	   System.out.println("");
	   
	   System.out.println("Ports that should return true:");
	   System.out.println("");
	   
	   String[] validPorts = {
			   "0",
			   "69",
			   "999",
			   "1000",
			   "9000",
			   "11111",
			   "65535"
	   };
	   
	   for (String port : validPorts) {
		   String url = "http://www.amazon.com:" + port;
		   System.out.println(urlVal.isValid(url) + ": " + port);
	   }
	   
	   System.out.println("");
	   
	   System.out.println("Ports that should return false:");
	   System.out.println("");
	   
	   String[] invalidPorts = {
			   "-1",
			   "-10",
			   "a2",
			   "35e",
			   "65536",
			   "1000000"
	   };
	   
	   for (String port : invalidPorts) {
		   String url = "http://www.amazon.com:" + port;
		   System.out.println(urlVal.isValid(url) + ": " + port);
	   }
	   
	   System.out.println("");   
   }
   
public void testQuery()
	{
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Query Tests:");
	   System.out.println("");
	   
	   System.out.println("Queries that should return true:");
	   System.out.println("");
	   
	   String[] validQueries = {
			   "/?action=view",
			   "?action=view",
			   "?action=edit&mode=up"
	   };
	   
	   for (String query : validQueries) {
		   String url = "http://www.amazon.com" + query;
		   System.out.println(urlVal.isValid(url) + ": " + query);
	   }
	   
	   System.out.println("");
	   
	   System.out.println("Queries that should return false:");
	   System.out.println("");
	   
	   String[] invalidQueries = {
			   "&action=view",
			   "=action",
			   "$action=view",
			   "*action=view",
			   "?action=view"
	   };
	   
	   for (String query : invalidQueries) {
		   String url = "http://www.amazon.com" + query;
		   System.out.println(urlVal.isValid(url) + ": " + query);
	   }
	   
	   System.out.println("");
	   /*
	    the bug in query is tricky because it fail the valid input but pass the invalid input. 
	    So I check the isValidQuery() function, and I found the bug right away at line 446 in 
	    urlValidator.java, it return negate statement of QUERY_PATTERN.matcher(query).matches();
	    Therefore, valid input instead of return true, it will return false and fail the test.
	    On the other hand, I thought isValidQuery(0 function would return true since it negate 
	    the return statement, but it doesn't. Indeed, it return false for invalid input. I don't 
	    understand the mechanism behind the function which makes it really hard to find bug and 
	    debug effectively
	    corrected: return QUERY_PATTERN.matcher(query).matches();
	    bug: return !QUERY_PATTERN.matcher(query).matches();
	    */
	}

	public void testAuthority()
	{
	   
	   // This really tests the domain or hostname since we already did enough IP address testing
	   // in the General Manual Tests
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Authority Tests:");
	   System.out.println("");
	   
	   System.out.println("Authorities that should return true:");
	   System.out.println("");
	   
	   String[] validAuthorities = {
			   "go.com",
			   "bbc.co.uk",
			   "www.parliament.uk",
			   "9jumpin.com.au",
			   "YeahNah.au",
			   "bogan.co.au",
			   "news.cn",
			   "mail.google.com",
			   "smile.amazon.co.uk",
			   "eh.ca"
	   };
	   
	   for (String authority : validAuthorities) {
		   String url = "http://" + authority;
		   System.out.println(urlVal.isValid(url) + ": " + authority);
	   }
	   
	   System.out.println("");
	   
	   System.out.println("Authorities that should return false:");
	   System.out.println("");
	   
	   String[] invalidAuthorities = {
			   "aaa",
			   "aaa.",
			   ".aaa",
			   "go.a1a",
			   "go.a",
			   "go.1up",
			   "dude,wheres.my.ca"
	   };
	   
	   for (String authority : invalidAuthorities) {
		   String url = "http://" + authority;
		   System.out.println(urlVal.isValid(url) + ": " + authority);
	   }
	   
	   System.out.println("");
	   /*
	   According to the testAuthority(), the program pass both valid and
	   invalid authority. So I check back at the domainValidator.java file. The first function check it 
	   has is public boolean isValid(String domain), this function return true if the domain is valid
	   and false otherwise. However the function happen to negate the hostnameRegex.isValid(domain) which
	   make function return true when it see invalid domain. So it does not matter the domain valid or invalid
	   the function will return true, which make it fail as domainValidator
	   The bug is at line 139 in DomainValidator.java. So this bug cause the function isValid(String domain) return true for invalid domain
	   corrected: if (hostnameRegex.isValid(domain))
	   bug: if (!hostnameRegex.isValid(domain))
	   */
   }

	public void testRandomPort()
	{
	   
	   //Since the validating port only fail the valid input, I randomly test valid port
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   int numFail = 0;
	   //i start out with 100 tests
	   int testPort;
	   //random number from 0 to 65636
	   
	   for (int i = 0; i < 100; i++)
	   {
		   url = "http://www.amazon.com:";
		   Random r = new Random();
		   testPort = r.nextInt(30000);	//generate random number from 1 to 1001
		   url = url + testPort;
		   System.out.println(url);
		   if (!urlVal.isValid(url))
		   {
			   System.out.println("Port number: " + testPort + " Failed");
			   numFail++;
		   }
	   }
	   System.out.println("number of fail test = " + numFail );
	   System.out.println("");
	   //reduce the random number to 30000
	   numFail = 0;
	   for (int i = 0; i < 100; i++)
	   {
		   url = "http://www.amazon.com:";
		   Random r = new Random();
		   testPort = r.nextInt(30000);	//generate random number from 1 to 1001
		   url = url + testPort;
		   System.out.println(url);
		   if (!urlVal.isValid(url))
		   {
			   System.out.println("Port number: " + testPort + " Failed");
			   numFail++;
		   }
	   }
	   System.out.println("number of fail test = " + numFail);
	   System.out.println("");
	   //I try small this time, may be 2000
	   numFail = 0;
	   for (int i = 0; i < 100; i++)
	   {
		   url = "http://www.amazon.com:";
		   Random r = new Random();
		   testPort = r.nextInt(2000);	//generate random number from 1 to 1001
		   url = url + testPort;
		   System.out.println(url);
		   if (!urlVal.isValid(url))
		   {
			   System.out.println("Port number: " + testPort + " Failed");
			   numFail++;
		   }
	   }
	   System.out.println("number of fail test = " + numFail);
	   System.out.println("");
	   //reduce the random number to 1000
	   numFail = 0;
	   for (int i = 0; i < 100; i++)
	   {
		   url = "http://www.amazon.com:";
		   Random r = new Random();
		   testPort = r.nextInt(1000);	//generate random number from 1 to 1001
		   url = url + testPort;
		   System.out.println(url);
		   if (!urlVal.isValid(url))
		   {
			   System.out.println("Port number: " + testPort + " Failed");
			   numFail++;
		   }
	   }
	   System.out.println("number of fail test = " + numFail);
	   System.out.println("");
	   /*
	   So any port higher than 1000 fail the tests. Therefore I check the number of port allowed 
	   in the program, and find out the bug is at line 158 in urlvalidator.java. What it does it 
	   set the attribute port_regex to be 3 instead of 5, which means it can only allow port 
	   up to 3 digit, the maximum port is 999, however the limit of the port we can use is up to 
	   65535 which is 5 digit port
	   corrected: 	private static final String PORT_REGEX = "^:(\\d{1,5})$";
	   bug: 		private static final String PORT_REGEX = "^:(\\d{1,3})$";
	   */
	   
	}
   public void testRandomIpv4()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //invalid input
	   if (urlVal.isValid("http://192.168.1"))
	   {
		   System.out.println("invalid1 input fail");
	   }
	   if (urlVal.isValid("http://192.168.1.1.1"))
	   {
		   System.out.println("invalid2 input fail");
	   }
	   if (urlVal.isValid("http://255.255.255.256"))
	   {
		   System.out.println("invalid3 input fail");
	   }
	   if (urlVal.isValid("http://-1.0.2.3"))
	   {
		   System.out.println("invalid4 input fail");
	   }
	   //valid input, they actually pass the tests
	   if (!urlVal.isValid("http://192.168.1.1"))
	   {
		   System.out.println("valid1 input fail");
	   }
	   if (!urlVal.isValid("http://0.1.2.3"))
	   {
		   System.out.println("invalid2 input fail");
	   }
	   /*
	    According to the test above the test case fail is (urlVal.isValid("http://255.255.255.256"))
	    the function return true while it suppose to return false because ipv4 only go from 0 to 255.
	    256 is invalid, so I create a random test for it
	    */
	   String url;
	   int numFail = 0;
	   //i start out with 100 tests
	   int testIpv4;
	   //random number from 0 to 65636
	   
	   for (int i = 0; i < 100; i++)
	   {
		   url = "http://192.168.1.";
		   Random r = new Random();
		   testIpv4 = r.nextInt(500);	//generate random number from 1 to 1001
		   url = url + testIpv4;
		   System.out.println(url);
		   if (testIpv4 > 255)
		   {
		   		//if the isValid(url) pass the invalid input, display the fail test and increase fail test counter
			   if (urlVal.isValid(url))
			   {
				   System.out.println("Port number: " + testIpv4 + " Failed");
				   numFail++;
			   }
		   }
	   }
	   System.out.println("number of fail test = " + numFail);

	   /*
		According to the test above, the function isValid() pass all the invalid ipv4 address, in specific
		all the number > 255. So i look through the InetAddressValidator.java file. I found a bug
		at line 95 in. This bug cause the function isValidInet4Address(String inet4Address) return true 
		for iIpsegment > 255. Basically it doesn't limit the number of ipv4 address, it pass ipv4 address
		with number > 255. This bug violate the definition of ivp4 address, where ipv4 address number is made
		up of eight bit value -> 2^8 = 255, so it can only go from 0 to 255
		corrected: if (iIpSegment > 255) {          
           				return false;}
		bug: if (iIpSegment > 255) {          
           				return true;}
       */
   }
   		
   
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}

