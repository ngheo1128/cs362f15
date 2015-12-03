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
	   
	   System.out.println("Inital Basic Test:");
	   
	   System.out.println("Should print out true:");
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.google.com"));
	   System.out.println(urlVal.isValid("http://www.amazon.org"));
	   System.out.println(urlVal.isValid("http://www.water.org"));
	   
	   System.out.println("Should print out false:");
	   System.out.println(urlVal.isValid("http:wer.amazon.com.com"));
	   
	   System.out.println(urlVal.isValid("http://www.wa.ter.org"));
	   //BUG FOUND: Too many periods in the domain.
	   
	   
	   System.out.println(urlVal.isValid("http://www.water.org:2010200202"));
	   System.out.println(urlVal.isValid("http://www.water.o.o."));
	      
   }
   
   
   public void testValidProtocol() {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Testing Valid Protocol Section:");
	   System.out.println("All these should be true:");
	   
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("https://www.amazon.com"));
	   System.out.println(urlVal.isValid("pop://www.amazon.com"));
	   System.out.println(urlVal.isValid("stmp://www.amazon.com"));
	   System.out.println(urlVal.isValid("ftp://www.amazon.com"));
	   
	   
	   System.out.println(urlVal.isValid("www.amazon.com"));
	   //BUG FOUND: The URL should be valid without the protocol in the front.
	   
	   
   }
   
   public void testInvalidProtocol() {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Testing Invalid Protocol Section:");
	   System.out.println("All these should be false:");
	   
	   System.out.println(urlVal.isValid("htp:/www.amazon.com"));
	   System.out.println(urlVal.isValid("https:2//www.amazon.com"));
	   System.out.println(urlVal.isValid("ftp:://www.amazon.com"));
	   System.out.println(urlVal.isValid("pop:/www.amazon.com"));
	   System.out.println(urlVal.isValid("stmp/www.amazon.com"));
	   
   }
   
   public void testPorts() {
	   
//	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
//		Un-comment section below to enable test:
	   
//	   System.out.println("Testing Valid Ports (0-65535)");
//	   System.out.println("Should all be true:");
	   	   
	   
//	   for(int i = 0; i<=2000; i++)
//	   {
//		   
//		   String str = "http://www.amazon.com:";  
//		   str += i;
//
//		   System.out.println(str);
//		   
//		   System.out.println(urlVal.isValid(str));
//		   
//	   }
	   
	   //BUG FOUND: Ports 1000 and above fail.
   }
	   
	   public void testInvalidPorts() {
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   System.out.println("Testing Invalid Ports (Negative Numbers and appended Letters)");
		   System.out.println("Should all be false:");
		   
		   
		   System.out.println(urlVal.isValid("http://www.amazon.com:-2"));
		   System.out.println(urlVal.isValid("http://www.amazon.com:-10"));
		   System.out.println(urlVal.isValid("http://www.amazon.com:-2b"));
		   System.out.println(urlVal.isValid("http://www.amazon.com:2b"));
	   }
	   
	   public void testValidDomain() {
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   System.out.println("Testing Valid Domain");
		   System.out.println("Should all be true:");
		   
		   System.out.println(urlVal.isValid("http://www.amazon.com"));
		   System.out.println(urlVal.isValid("http://www.google.com"));
		   System.out.println(urlVal.isValid("http://www.break.com"));
		   System.out.println(urlVal.isValid("www.break.com"));
		   System.out.println(urlVal.isValid("http://google.com"));
		   System.out.println(urlVal.isValid("google.com"));
		   System.out.println(urlVal.isValid("break.com"));
		   System.out.println(urlVal.isValid("http://www.wjl2343isduf.com"));
		   
		   System.out.println("Testing Valid Numbered Domains");
		   System.out.println("Should all be true:");
		   
		   System.out.println(urlVal.isValid("192.168.1.1"));
		   //BUG FOUND: This should work in a browser.
		   
	   }
	   
	   public void testInvalidDomain() {
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   System.out.println("Testing Invalid Domain");
		   System.out.println("Should all be false:");
		   
		   System.out.println(urlVal.isValid("http://www.wjl#3isduf.com"));
		   
		   System.out.println(urlVal.isValid("http://www.google.google.com"));
		   //BUG FOUND: Too many periods in the domain.
		   
		   System.out.println(urlVal.isValid("www.google.google.com"));
		   
		   System.out.println(urlVal.isValid("http://www.2.2.com"));
		 //BUG FOUND: Too many periods in the domain.
		   
		   System.out.println(urlVal.isValid("http://www.google..com"));
		   System.out.println(urlVal.isValid("http://www..google.com"));
		   System.out.println(urlVal.isValid("http://www..google..com"));
		   
		   System.out.println(urlVal.isValid("http://www.g.o.o.g.l.e.com"));
		 //BUG FOUND: Too many periods in the domain.
		   System.out.println(urlVal.isValid("256.256.256.256"));
		   
		   
	   }
	   
	   public void testValidPath() {
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   System.out.println("Testing Valid Path");
		   System.out.println("Should all be true:");
		   
		   System.out.println(urlVal.isValid("http://google.com/"));
		   
		   System.out.println(urlVal.isValid("http://google.com/#"));
		   
		   System.out.println(urlVal.isValid("http://google.com/jklwerjkl"));
		   
		   System.out.println(urlVal.isValid("http://google.com/jklwerjkl/"));
		   
		   System.out.println(urlVal.isValid("http://google.com/jslkdf2444"));
		   
		   System.out.println(urlVal.isValid("http://google.com/23434"));
		   System.out.println(urlVal.isValid("http://google.com/23434/skldfjlks"));
		   
		   System.out.println(urlVal.isValid("http://google.com/2/s/k/l/d/f/j/l/k/s/s"));
		   
		   System.out.println(urlVal.isValid("http://google.com/?query=23444"));
		   
		   System.out.println(urlVal.isValid("http://google.com/?query=234888&?user=franklin"));
		   
		   System.out.println(urlVal.isValid("https://www.google.com/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=getty%20images"));
		   //BUG FOUND: The question mark in the path causes errors
		   
		   System.out.println("Testing Signs in Path:");
		   System.out.println(urlVal.isValid("http://google.com/query=23444"));
		   System.out.println(urlVal.isValid("http://google.com/?q"));
		   System.out.println(urlVal.isValid("http://google.com/?"));
		   
	   }
	 
	   
	   public void testInvalidPath() {
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   System.out.println("Testing Invalid Path");
		   System.out.println("Should all be false:");
		   
		   System.out.println(urlVal.isValid("http://google.com/../"));
		   System.out.println(urlVal.isValid("http://google.com/okay.ko/"));
		   //BUG FOUND: Period should not be okay in the path.
		   
		   System.out.println(urlVal.isValid("http://google.com/.."));
		   System.out.println(urlVal.isValid("http://google.com/jwerkkr/.."));
		   System.out.println(urlVal.isValid("http://google.com/jwerkkr/../"));
		 //BUG FOUND: Period should not be okay in the path.
		   
		   
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
