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
	   
	   //Testing invalid URLs

	   assertFalse(urlVal.isValid("ht://www.google.com"));
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
	   assertTrue(urlVal.isValid("http://www.amazon.com:8080"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:80808"));
	   
	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
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
