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

   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   
	   // Valid URLs
	   String validUrls[] = { // add valid urls here
			   "http://www.amazon.com",
			   "http://www.amazon.com/",
			   "http://www.amazon.com:0",
			   "http://www.amazon.com:65535",
			   "https://google.com:1000",
			   "https://www.google.com/path1?auth=1"
	   };
	   
	   System.out.println("Running Manual Test: Valid Urls | Count: " + validUrls.length);
	   for(int i = 0; i < validUrls.length; i++) {
		   
		   if(urlVal.isValid(validUrls[i]) == false) {
			   System.out.println( "testManualTest: Actual: " +urlVal.isValid(validUrls[i]) + " | Expected: true  || " + validUrls[i] );
			   System.out.println("testManualTest: FOUND ERROR in above url.");
		   }
		   //assertEquals(urlVal.isValid(validUrls[i]), true);
	   }
	   
	   // Invalid URLs
	   String invalidUrls[] = { //add invalid Urls here
			   "http://www..com",
			   "http://.amazon.com/",
			   "//www.amazon.com/",
			   "amazon.com/~",
			   "https://www.google.com$test123",
			   "https://  www.google.com/test1234",
			   "https://www.google.com/test1234   ",
			   "https://www.google.com/test   1234",
			   "https://www.google.com   /test1234"   
	   };
	   
	   System.out.println("Running Manual Test: Invalid Urls | Count: " + invalidUrls.length);
	   for(int i = 0; i < invalidUrls.length; i++) {
		   
		   if(urlVal.isValid(invalidUrls[i]) == true) {
			   System.out.println( "testManualTest: Actual: " +urlVal.isValid(invalidUrls[i]) + " | Expected: false  || " + invalidUrls[i] );
			   System.out.println("testManualTest: FOUND ERROR in above url.");
		   }
		   //assertEquals(urlVal.isValid(invalidUrls[i]), false);
	   }
	   
	   System.out.println("\nCompleted testManualTest \n\n");
	     
   }
   
   public void testPortPartition()
   {
	    String testString = "";
	    boolean actualResult = false;
		
	    // ==================== VALID TEST ========================
	    // generates "http://google.com:n" where [0 <= n <= 65535]
	    System.out.println("Running testPorPartition Test: Valid Ports");
		for (int n = 0; n < 65536; n++) {
		    ResultPair testPair = new ResultPair(new Integer(n).toString(), true);
		    testString = "http://google.com:";
		    testString += testPair.item;
		    actualResult = urlVal.isValid(testString);
		    
		    if(actualResult == false) {
		    	System.out.println( "testPortPartition: Actual: " + actualResult + " | Expected: true || " +  testString );
		    	System.out.println("testPortPartition: FOUND ERROR in above url.");
		    }
		    //assertEquals(actualResult, true);
		}
		
		
		// ================== INVALID TEST ========================
		System.out.println("Running testPorPartition Test: Invalid Ports");
		ResultPair[] invalidPorts = { //add additional invalid ports here
		    new ResultPair("string", false),
			new ResultPair("-1234", false),
			new ResultPair("+1234", false),
			new ResultPair("@1234", false),
			new ResultPair("~1234", false),
			new ResultPair("*1234", false),
			new ResultPair("$1234", false)
		};
		
		for (int n = 0; n < invalidPorts.length; n++) {
		    ResultPair testPair = invalidPorts[n];
		    testString = "http://google.com:";
		    testString += testPair.item;
		    actualResult = urlVal.isValid(testString);
		    
		    if(actualResult == true) {
		    	System.out.println( "testPortPartition: Actual: " + actualResult + " | Expected: false || " +  testString );
		    	System.out.println("testPortPartition: FOUND ERROR in above url.");
		    }
		    //assertEquals(actualResult, false);
		    
		}
		
		System.out.println("\nCompleted testPortPartition \n\n");
	   
   }
   
   public void testQueryPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   
	   ResultPair[] urlScheme = {
			   new ResultPair("https://", true),
			   new ResultPair("http://", true),
			   new ResultPair("ftp://", true),
			   new ResultPair("...://", false),
			   new ResultPair("://", false),
			   new ResultPair("...//", false),
	   };
	   ResultPair[] urlAuthority = {
			   new ResultPair("www.google.com", true),
			   new ResultPair("google.com", true),
			   new ResultPair("255.255.255.255", true),
			   new ResultPair("SomeStringOnly", false),
			   new ResultPair("www.google.commmmmmm", false),
			   new ResultPair("wwwwwwwwww.google.com", false),
			   new ResultPair("", false)
	   };
	   ResultPair[] urlPort = {
			   new ResultPair("", true),
			   new ResultPair(":1", true),
			   new ResultPair(":8080", true),
			   new ResultPair(":65535", true),
			   new ResultPair(":alpha", false),
			   new ResultPair(":alpha1234", false),
			   new ResultPair(":-123", false)
	   };
	   ResultPair[] urlPath = {
			   new ResultPair("/path1", true),
			   new ResultPair("/123", true),
			   new ResultPair("/123/456", true),
			   new ResultPair("/123//789", true),
			   new ResultPair("$test1234", false),
			   new ResultPair("   /test1234", false),
			   new ResultPair("/test1234/#", false),
			   new ResultPair("/test1234/...", false),
			   new ResultPair("", true)
	   };
	   ResultPair[] urlQuery = {
			   new ResultPair("", true),
			   new ResultPair("?authentication=true", true),
			   new ResultPair("?user=SomeUser123&pass=123456", true)
	   };
	   
	   System.out.println("Running testIsValid Test");
	   int i, j, k, l, m;
	   String testString = "";
	   String expectedStr = "";
	   boolean expectedResult, actualResult;
	   
	   for(i = 0; i < urlScheme.length; i++){
		   for(j = 0; j < urlAuthority.length; j++) {
			   for(k = 0; k < urlPort.length; k++) {
				   for(l = 0; l < urlPath.length; l++) {
					   for(m = 0; m < urlQuery.length; m++) {
						   testString = "";
						   expectedStr = "";
						   
						   testString += urlScheme[i].item;
						   expectedStr += urlScheme[i].valid;
						   
						   testString += urlAuthority[j].item;
						   expectedStr += urlAuthority[j].valid;
						   
						   testString += urlPort[k].item;
						   expectedStr += urlPort[k].valid;
						   
						   testString += urlPath[l].item;
						   expectedStr += urlPath[l].valid;
						   
						   testString += urlQuery[m].item;
						   expectedStr += urlQuery[m].valid;
						   
						   //check if any of the partitions contain a false validation
						   //for example "TrueTrueTrueTrueFalse" will return false (!True), which 
						   //should be the return result of the isValid method as well.
						   expectedResult = !expectedStr.toLowerCase().contains("false".toLowerCase());
						   actualResult = urlVal.isValid(testString);
						   
						   if(expectedResult != actualResult) {
							   System.out.println( "testIsValid: Actual: " + actualResult + " | Expected: " +  expectedResult + " || " +  testString );
							   //System.out.println( urlScheme[i].valid + " | " + urlAuthority[j].valid + " | " + urlPort[k].valid + " | " + urlPath[l].valid + " | " + urlQuery[m].valid);
							   //System.out.println( urlScheme[i].item + " | " + urlAuthority[j].item + " | " + urlPort[k].item + " | " + urlPath[l].item + " | " + urlQuery[m].item);
							   //System.out.println("testIsValid: FOUND ERROR in above url.");
						   }
						
						   //assertEquals(expectedResult, actualResult);
				
					   }
				   }
			   }
		   }
	   }
	   
	   System.out.println("\nCompleted testIsValid \n\n");
   }
   
   public void testAnyOtherUnitTest()
   {
	   
	   /**
	    * Create set of tests by taking the testUrlXXX arrays and
	    * running through all possible permutations of their combinations.
	    *
	    * @param testObjects Used to create a url.
	    */
   }

}
