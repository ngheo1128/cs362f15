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

/*
 * Tony Liang
 * Khiem Nguyen
 * 
 * CS 362 Final Project
 * 12/6/15
 */


/**
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
   
   public void testAuthority(){
	   
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
   
   // This delves further into the nature of the invalid ports
   public void testPortRandom()
   {   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   int numFail = 0;
	   int testPort;
	   
	   for (int i = 0; i < 10000; i++)
	   {
		   url = "http://www.amazon.com:";
		   Random r = new Random();
		   testPort = r.nextInt(65535 + 1); // 0 to 65535
		   url = url + testPort;
		   if (!urlVal.isValid(url))
		   {
//			   System.out.println("Port number: " + testPort + " Failed"); //UN-COMMENT IF DESIRED
			   numFail++;
		   }
	   }
	   System.out.println("Random Port Tests:");
	   System.out.println("Proportion of failed port tests: " + numFail + "/" + 10000);
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
   }
}