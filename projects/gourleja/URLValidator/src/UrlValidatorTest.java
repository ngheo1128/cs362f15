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
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   
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
               new ResultPair("ftp://", true),
               new ResultPair("aaa://", true),
               new ResultPair("aaas://", true),
               new ResultPair("cap://", true),
               new ResultPair("chrome-extension://", true),
               new ResultPair("cid://", true),
               new ResultPair("data://", true),
               new ResultPair("dict://", true),
    		   new ResultPair("imap://", true),
    		   new ResultPair("ms-secondary-screen-controller://", true),
    		   new ResultPair("soap.beep://", true),
    		   new ResultPair("z39.50r://", true),
    		   new ResultPair("z39.50s://", true),
    		   new ResultPair("123://", false),
    		   new ResultPair("a://", true),
    		   new ResultPair("http:/", false),
               new ResultPair("http:", false),
               new ResultPair("http/", false),
               new ResultPair("://", false),
               new ResultPair("", true)};
       
       
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
        	   System.err.println(newUrl + "\n");  
        	   errors++;
           }
       }
       if (errors > 0) {
    	   String message = "Errors = " + errors; 
    	   assertEquals(message, 0, errors);
       }
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
