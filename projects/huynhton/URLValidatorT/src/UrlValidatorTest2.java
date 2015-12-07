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
	   System.out.println("MANUAL TEST\n----------");
	   System.out.println(urlVal.isValid("http://www.amazon.com"));	// basic given test
	   System.out.println(urlVal.isValid("http://www.google.com")); // given test -> returns true
	   System.out.println(urlVal.isValid("http://///www.google.com")); // given test -> returns false

	   System.out.println(urlVal.isValid("Xhttp://www.google.com")); // first bug found: having value before http still returns true.
	   		// bug found by Sarah Cawley
	   System.out.println("\n");
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   // In this partition, I am going for common, expected cases
	   //	I am still trying to find a way to find a bug, though.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("FIRST PARTITION TEST\n----------");
	   String testURLstr1 = "http://www.google.com";
	   for(int i = 0;i<5;i++)
	   {
		   
		   
		   System.out.println(urlVal.isValid(testURLstr1)); // given test -> returns true
		   testURLstr1 += " ";	// string to append on
		   //^^^ I believe this is another bug.  I believe we can't append on spaces to the end of a URL, but this test passes
	   }	   
	   System.out.println(testURLstr1);
	   System.out.println("\n");
   }
   
   
   public void testYourSecondPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("SECOND PARTITION TEST\n----------");
	   String testURLstr1 = "http://www.google.com";
	   for(int i = 0;i<5;i++)
	   {
		  String newString = testURLstr1.substring(0,3) + "http:/" + testURLstr1.substring(10,12);
		   
		   System.out.println(urlVal.isValid(testURLstr1)); // given test -> returns true
		   testURLstr1 += ".com";	// string to append on
		   System.out.println(newString);
	   }	   
	   System.out.println("\n");
   }
   
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("testIsValid TEST\n----------");
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
	   
	   System.out.println("\n");
   }
   
   public void testAnyOtherUnitTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("OTHER TESTS\n----------");
	   
	   System.out.println("\n");
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
