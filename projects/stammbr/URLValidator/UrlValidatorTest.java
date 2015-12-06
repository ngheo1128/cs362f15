/*
 * Authors:  Jody Hansen, Wisam Thalij, and Brian Stamm
 * Assignment:  Final Project
 * Date:  12.6.15
 * Notes:  These are the tests designed by our team, and they are detailed
 * in the final paper.  Assert statements were commented out as needed during
 * testing to help with the debugging process, but are not commented out in this
 * version.
 */

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

   /*
    * Function:  testManualTest
    * Outcome:  Goes through manually testing some variations of URLs, simulating possible
    * simple errors a user might do.
    * */
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println("Entering testManual.\n");	   

	   //Testing invalid URLs
	   assertFalse(urlVal.isValid("http:www.amazon.com"));
	   assertFalse(urlVal.isValid("http//www.amazon.com"));
	   assertFalse(urlVal.isValid("http:/www.amazon.com"));
	   assertFalse(urlVal.isValid("http/www.amazon.com"));
	   
	   assertFalse(urlVal.isValid("://www.amazon.com"));
	     
	   assertFalse(urlVal.isValid("http://www.amazon.com:-1"));
	   assertFalse(urlVal.isValid("http://www.amazon.com:80abc"));
	   assertFalse(urlVal.isValid("http://www.amazon.com:808080"));

	   assertFalse(urlVal.isValid("http://www.amazon.comtest1/"));
	   assertFalse(urlVal.isValid("http://www.amazon.com/test1/?action=view"));
	   assertFalse(urlVal.isValid("http://www.amazon.comtest1/?action=view"));
	   assertFalse(urlVal.isValid("http://www.amazon.com?action=view"));
	   assertFalse(urlVal.isValid("http://www.amazon.com/?actionview"));
	   
	   //The following should be false
	   System.out.println("1.  " + urlVal.isValid("htt://www.amazon.com"));
	   System.out.println("2.  " + urlVal.isValid("ttp://www.amazon.com"));
	   System.out.println("3.  " + urlVal.isValid("http://www.amazon.com/."));
	   System.out.println("4.  " + urlVal.isValid("http://www.amazon.com/action=view"));
	   
	   
	   //Testing valid URLs
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   assertTrue(urlVal.isValid("ftp://www.amazon.com"));
	   assertTrue(urlVal.isValid("https://www.amazon.com"));
	   assertTrue(urlVal.isValid("http://www.amazon.au"));

	   assertTrue(urlVal.isValid("http://amazon.com"));
	  
	   assertTrue(urlVal.isValid("http://www.amazon.com:0"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:80"));
	   assertTrue(urlVal.isValid("http://www.amazon.com:808"));
	  
	   assertTrue(urlVal.isValid("http://www.amazon.com/test"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/file"));
	   
	   //The following should be true 
	   System.out.println("5.  " + urlVal.isValid("www.amazon.com"));
	   System.out.println("6.  " + urlVal.isValid("amazon.com"));
	   System.out.println("7.  " + urlVal.isValid("http://www.amazon.com:8080"));
	   System.out.println("8.  " + urlVal.isValid("http://www.amazon.com:80808"));
	   System.out.println("9.  " + urlVal.isValid("http://www.amazon.com/test1/?action=view"));
   
   }
   
   /*
    * Function:  testYourFirstPartition
    * Outcome:  Randomly creates the URL string and tests it using the isValid function.
    * */
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Test the url "c#.c#.c#", randomly filling 3 parts of the url from the string alphanum
	   String alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	   System.out.println("Entering testYourFirstPartition.\n");
	   
	   for(int i=0; i< 10000; i++){
		   StringBuffer url1 = new StringBuffer();
		   StringBuffer url2 = new StringBuffer();
		   StringBuffer url3 = new StringBuffer();
		   StringBuffer fullUrl = new StringBuffer();
    	   
		   char c;
    	   int n;
    	   int r;
    	   
    	   r = new Random().nextInt(3) + 1;
    	   for(int j = 0; j < r; j++){
    		   n = new Random().nextInt(alphanum.length());
    		   c = alphanum.charAt(n);
               url1.append(c);
    	   }
    	   
    	   r = new Random().nextInt(1) + 1;
    	   for(int j = 0; j < r; j++){
    		   n = new Random().nextInt(alphanum.length());
    		   c = alphanum.charAt(n);
               url2.append(c);
    	   }
    	   
    	   r = new Random().nextInt(3) + 1;
    	   for(int j = 0; j < r; j++){
    		   n = new Random().nextInt(alphanum.length());
    		   c = alphanum.charAt(n);
               url3.append(c);
    	   }
    	   
    	   fullUrl.append(url1);
    	   fullUrl.append(".");
    	   fullUrl.append(url2);
    	   fullUrl.append(".");
    	   fullUrl.append(url3);
    	   
    	   String finalString = fullUrl.toString();
    	   
    	   //Prints out "#ofIteration. finalStringToBeTested :  resultOf'isValid'"
    	   System.out.println(i + ".  " + finalString + " :  " + urlVal.isValid(finalString));  	   
       }
   }
   
   /*
    * Function:  testYourSecondPartition
    * Outcome:  Has a valid URL and puts a port number between the size of 1 to 6 at the end.
    * */
   public void testYourSecondPartition(){
	   //This is to test if the length of the port number matters.
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Entering testYourSecondPartition.\n");
	   
	   //Test the url "http://www.anything.com:c#"
	   String urlSchemes[] = {
			   "www.amazon.com:",
			   "www.google.com:",
			   "www.facebook.com:",
			   "www.youtube.com:",
			   "www.yahoo.com:",
			   "www.qq.com:",
			   "www.wikipedia.org:",
			   "www.twitter.com:",
			   "www.IMadeThisUp.com:",
			   "www.ebay.com:",
			   "www.linkedin.com:",
	   };
			   
	   String number = "0123456789";

	   for(int i=0; i< 10000; i++){
		   StringBuffer url = new StringBuffer();
		   char c;
    	   int n;
    	   int r;
    	   
    	   r = new Random().nextInt(6) + 1;
    	   for(int j = 0; j < r; j++){
    		   n = new Random().nextInt(number.length());
    		   c = number.charAt(n);
               url.append(c);
    	   }
    	       	   
    	   String finalurl = url.toString();
    	   r = new Random().nextInt(10) + 0;
    	   System.out.println(i + ":  url - " + "http://www.amazon.com:"+finalurl + "\t\tresult:  " + urlVal.isValid("http://www.amazon.com:"+finalurl));
       }
   
   }
   
    /*
     * Function:  testIsValid
     * Outcome:  Creates URLs parts, both valid/invalid, and tests various combinations of
     * these.
     * */
   public void testIsValid()
   {
	 // Create a UrlValidator object to test on
	 UrlValidator urlValidator = new UrlValidator();
     
     // Test Units Fixed input
     // Fixed URL Schemes
     String[] ValidTestSchemes = {
          "ftp://foo.bar.com",  		//True
          "http://foo.bar.com",   		//True
          "https://foo.bar.com"}; 		//True
     String[] InvalidTestSchemes = {
          "http:/foo.bar.com",   		//False
          "http:foo.bar.com",    		//False
          "http::foo.bar.com",   		//False
          "://foo.bar.com",      		//False
          "httpp://foo.bar.com", 		//False
          "htt1://foo.bar.com",  		//False
          "1http://foo.bar.com", 		//False
          "Wrong://foo.bar.com", 		//False
          "www.google.com"};     		//False
     // Fixed URL Authority
     String[] ValidTestAuthority = {
          "http://www.google.com",  	//True
          "http://foo.bar.com",   		//True
          "http://foo.au",      		//True
          "http://0.0.0.0",     		//True
          "http://255.255.255.255", 	//True
          "http://1.2.3.4",     		//True
          "http://localhost:8080",  	//True
          "http://hostname:8080",}; 	//True
     String[] InvalidTestAuthority = {
          "http://www.google.sss",  	//False
          "http://www.google.com1", 	//False
          "http://.com",       			//False
          "http://1.2.3",       		//False
          "http://.1.2.3.4",     		//False
          "http://1.2.3.4.5"};    		//False
     // Fixed URL Ports
     String[] ValidTestUrlPorts = {
          "http://www.google.com:80",   	//True
          "http://www.google.com:12345"}; 	//True
     String[] InvalidTestUrlPorts = {
          "http://foo.bar.com:123456",  //False
          "http://www.google.com:1234", //False
          "http://www.google.com:123",  //False
          "http://www.google.com:-80",  //False
          "http://www.google.com:80a",  //False
          "http://www.google.com:aa",   //False
          "http://www.google.com:" };   //False
     // Fixed URL Paths
     String[] ValidTestUrlPaths = {
          "http://www.google.com:80/path",    	//True
        "http://www.google.com/path/Subpath", 	//True
        "http://www.google.com/path134",    	//True
        "http://www.google.com/134",      		//True
        "http://www.google.com/",       		//True
        "http://www.google.com/@path",      	//True
        "http://www.google.com/$/Subpath" };  	//True
     String[] InvalidTestUrlPaths = {
        "http://www.google.com/..",         		//False
        "http://www.google.com/../",        		//False
        "http://www.google.com/../path",      		//False
        "http://www.google.com/..//path",     		//False
        "http://www.google.com/path//Subpath"};   	//False
     // Fixed URL Queries
     String[] ValidTestUrlQuery = {
          "http://www.google.com:80?action=view",		//True
        "http://www.google.com:80?action=edit",			//True
        "http://www.google.com:80?action=Somthingelse",	//True
        "http://www.google.com:80?action=edit&mode=up",	//True
        "http://www.google.com:80?action= ",      		//True
        "http://www.google.com:80?action=#",      		//True
        "http://www.google.com:80?action=123",      	//True
        "http://www.google.com:80?action=aa123",    	//True
        "http://www.google.com:80?action=123aa"};   	//True
     String[] InvalidTestUrlQuery = {
        "http://www.google.com:80#action=123aa",  		//False
        "http://www.google.com:80/action=123aa" };  	//False
     
     // Test URL Schemes 
     // Accepted Schemes {"http", "https" , "ftp"}
     System.out.println("*************************Valid Schemes Test********************");
     // Loop through the URLs and check if valid schemes
     for (int i=0 ; i<ValidTestSchemes.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(ValidTestSchemes[i])) {
           System.out.println(ValidTestSchemes[i] + " is valid");
       } else {
          System.out.println(ValidTestSchemes[i] + " is invalid");
       }
       // Assert the scheme is valid
       assertTrue(urlValidator.isValid(ValidTestSchemes[i]));
       
     }
     System.out.println("*************************Invalid Schemes Test********************");
     // Loop through the URLs and check if valid schemes
     for (int i=0 ; i<InvalidTestSchemes.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(InvalidTestSchemes[i])) {
           System.out.println(InvalidTestSchemes[i] + " is valid");
       } else {
          System.out.println(InvalidTestSchemes[i] + " is invalid");
       }
       // Assert the scheme is invalid
       assertTrue(!urlValidator.isValid(InvalidTestSchemes[i]));
      
     }
     
     // Test URL Authority 
     // Test should accept valid Top most domains and 32-bits IP addresses
     System.out.println("*************************Valid Authority Test********************");
     // Loop through the URLs and check if valid Authority
     for (int i=0 ; i<ValidTestAuthority.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(ValidTestAuthority[i])) {
           System.out.println(ValidTestAuthority[i] + " is valid");
       } else {
          System.out.println(ValidTestAuthority[i] + " is invalid");
       }
       // Assert the Authority is valid
       assertTrue(urlValidator.isValid(ValidTestAuthority[i]));
     }
     System.out.println("*************************Invalid Authority Test********************");
     // Loop through the URLs and check if valid Authority
     for (int i=0 ; i<InvalidTestAuthority.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(InvalidTestAuthority[i])) {
           System.out.println(InvalidTestAuthority[i] + " is valid");
       } else {
          System.out.println(InvalidTestAuthority[i] + " is invalid");
       }
       // Assert the Authority is invalid
       assertTrue(!urlValidator.isValid(ValidTestAuthority[i]));
     }
     
     // Test URL PORT 
     // Test Should accept a positive values and integers only 
     // Ports numbers should be five digits
     System.out.println("*************************Valid Ports Test********************");
     // Loop through the URLs and check if valid port number
     for (int i=0 ; i<ValidTestUrlPorts.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(ValidTestUrlPorts[i])) {
           System.out.println(ValidTestUrlPorts[i] + " is valid");
       } else {
          System.out.println(ValidTestUrlPorts[i] + " is invalid");
       }
       // Assert the PORT is valid
       assertTrue(urlValidator.isValid(ValidTestUrlPorts[i]));
     }
     System.out.println("*************************Invalid Ports Test********************");
     // Loop through the URLs and check if valid port number
     for (int i=0 ; i<InvalidTestUrlPorts.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(InvalidTestUrlPorts[i])) {
           System.out.println(InvalidTestUrlPorts[i] + " is valid");
       } else {
          System.out.println(InvalidTestUrlPorts[i] + " is invalid");
       }
       // Assert the PORT is invalid
       assertTrue(!urlValidator.isValid(InvalidTestUrlPorts[i]));
     }
     
     // Test URL Paths 
     // Test Should accept letters, integers and special characters 
     // Test Should accept sub direction (deep path)
     System.out.println("*************************Valid Paths Test********************");
     // Loop through the URLs and check if valid Paths
     for (int i=0 ; i<ValidTestUrlPaths.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(ValidTestUrlPaths[i])) {
           System.out.println(ValidTestUrlPaths[i] + " is valid");
       } else {
          System.out.println(ValidTestUrlPaths[i] + " is invalid");
       }
       // Assert the Paths is valid
       assertTrue(urlValidator.isValid(ValidTestUrlPaths[i]));
     }
     System.out.println("*************************Invlaid Paths Test********************");
     // Loop through the URLs and check if valid Paths
     for (int i=0 ; i<InvalidTestUrlPaths.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(InvalidTestUrlPaths[i])) {
           System.out.println(InvalidTestUrlPaths[i] + " is valid");
       } else {
          System.out.println(InvalidTestUrlPaths[i] + " is invalid");
       }
       // Assert the Paths is invalid
       assertTrue(!urlValidator.isValid(InvalidTestUrlPaths[i]));
     }
     
     // Test URL Query 
     // Test Should accept letters, integers and special characters 
     // Test Should accept sub direction (deep path)
     System.out.println("*************************Valid Queries Test********************");
     // Loop through the URLs and check if valid Paths
     for (int i=0 ; i<ValidTestUrlQuery.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(ValidTestUrlQuery[i])) {
           System.out.println(ValidTestUrlQuery[i] + " is valid");
       } else {
          System.out.println(ValidTestUrlQuery[i] + " is invalid");
       }
       // Assert the Query is valid
       assertTrue(urlValidator.isValid(ValidTestUrlQuery[i]));
     }
     System.out.println("*************************Invalid Queries Test********************");
     // Loop through the URLs and check if valid Paths
     for (int i=0 ; i<InvalidTestUrlQuery.length ; i++){
       // Print statements for testing
       if (urlValidator.isValid(InvalidTestUrlQuery[i])) {
           System.out.println(InvalidTestUrlQuery[i] + " is valid");
       } else {
          System.out.println(InvalidTestUrlQuery[i] + " is invalid");
       }
       // Assert the Query is invalid
       assertTrue(!urlValidator.isValid(InvalidTestUrlQuery[i]));
     }
   }
   
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /*
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   


   /*
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   public static void main(String[] argv) {	   
	   
	      UrlValidatorTest fct = new UrlValidatorTest("url test");
	      //fct.setUp();
	      fct.testIsValid();
	      //fct.testIsValidScheme();
	   }

}
