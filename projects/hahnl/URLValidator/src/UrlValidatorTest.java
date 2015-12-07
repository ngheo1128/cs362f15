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


import java.util.Arrays;

import junit.framework.TestCase;

import java.util.Iterator;
import java.util.Vector;




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
	   
	   System.out.println("Begin Manual Testing\n");
	   
	   
	   int error;							//Tracks the number of errors in an individual section
	   int errorCount = 0;					//Tracks the number of total errors
	   
	   //Array of strings used to test URLs and IP addresses
	   String[] invalidWebLinks = new String[]{"http://amazon", "http://",
			   "ebay.com", "www.yahoo.com/news", "",
			   "http://www.asu", "http://www.$%#.org", "http://#%$",
			   "http://.net/en", "3jj://www.bestbuy.com"};
	   
	   String[] validWebLinks = new String[]{"http://www.amazon.com", "http://www.gamefaqs.com",
			   "http://oregonstate.edu", "http://www.ebay.com", "http://www.yahoo.com/news",
			   "http://www.asu.edu", "http://www.wish.org", "http://www.nau.edu",
			   "http://us.battle.net/en", "http://www.bestbuy.com"};
	   
	   String[] invalidAuth = new String[]{"256.256.256.256", ".1.2.3.4", "go.a", "1.2.3", "123.123.456.123", 
				"123.123.0.456", "1.2.3.4.", "1.444.1.1", "1.2.3.4.5", "0.999.0.999"};


	   String[] validAuth = new String[]{"go.au", "go.com", "0.0.0.0", "255.255.255.255", "255.com", "go.cc"};
	   
	   //Testing invalid links
	   System.out.println("Testing Invalid Links");
	   error = 0;
	   for(int i = 0; i < invalidWebLinks.length; i++){
		   if(urlVal.isValid(invalidWebLinks[i]) == true){
			   System.out.println("Error: " + invalidWebLinks[i] + " is valid when it should be invalid.");
			   error++;
			   errorCount++;
		   }
	   }
	   if(error == 0){
		   System.out.println("No errors found...");
	   }	   
	   System.out.println("");
	   
	   //Testing valid links
	   System.out.println("Testing Valid Links");
	   error = 0;
	   for(int i = 0; i < validWebLinks.length; i++){
		   if(urlVal.isValid(validWebLinks[i]) == false){
			   System.out.println("Error: " + validWebLinks[i] + " is invalid when it should be valid.");
			   error++;
			   errorCount++;
		   }
	   }
	   if(error == 0){
		   System.out.println("No errors found...");
	   }
	   System.out.println("");

	   //Testing invalid authorities
	   System.out.println("Testing Invalid Authorities");
	   error = 0; 
	   for (int i = 0; i < invalidAuth.length; i++) {
		   if (urlVal.isValidAuthority(invalidAuth[i]) == true) {
			   System.out.println("Error: " + invalidAuth[i] + " is valid when it should be invalid.");
			   error++;
			   errorCount++;
		   }
	   }
	   if (error == 0) {
		   System.out.println("No errors found...");
	   }
	   System.out.println("");
	   
	   //Testing valid authorities
	   System.out.println("Testing valid authorities...");
	   error = 0; 
	   
	   for (int i = 0; i < validAuth.length; i++) {
		   if (urlVal.isValidAuthority(validAuth[i]) == false) {
			   System.out.println("Error: " + validAuth[i] + " is invalid when it should be valid.");
			   error++;
			   errorCount++;
		   }
	   }   
	   if (error == 0) {
		   System.out.println("No errors found...");
	   }
	   System.out.println("");
	   
	   
	   System.out.println("Testing Complete... Total number of errors found is: " + errorCount);
	   System.out.println("****************************************************************************************");
	   
   }
   
   
   public void testYourFirstPartition()
   {
		  System.out.println("Testing TLD for countries........\n"); 
		  String[] validCountryTLD = new String[]{"af", "be", "ca", "de", "es", "gb", "hu", "in", 
				   "jp", "kr", "lr", "mx", "nz", "om", "pl", "qa", "ru", "se", "th", "uk",  "vn", "wf", "ye", "zw"};
		  String[] invalidCountryTLD = new String[]{"aa", "3j", "%i", "foo", "bar", "xe", "ay", "zz", "68", "qr"};
		  String url = "http://www.google.";
		  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		  Vector testResults = new Vector();
		  
		  System.out.println("The following links are valid, but the test is saying they are invalid:");
		  for (int i = 0; i < validCountryTLD.length; i++) {
			  String temp = url + validCountryTLD[i];
			  if (!urlVal.isValid(temp)) {
				  testResults.add(temp);
				  
			  }
		  }
		  
		  for (int j = 0; j < invalidCountryTLD.length; j++) {
			  String temp = url + invalidCountryTLD[j];
			  if (urlVal.isValid(temp)) {
				  testResults.add(temp + ", is not valid.");
			  }
		  }
		  
		  if (testResults.size() > 0) {
			  Iterator itr = testResults.iterator();
			  Object first = itr.next();
			  Object next = null; 
			  while (itr.hasNext()) {
				  next = itr.next();
				  System.out.println(next);
			  }
			  
		  }
		  else {
			  System.out.println("No TLD country errors found!");
			  
		  }
			   
		  System.out.println("\nTesting Complete...");
		  System.out.println("****************************************************************************************");
   }
   
   public void testYourSecondPartition(){
	   System.out.println("Testing port numbers...");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String prefix = ":";
	   String test = "1.1.1.1";
	   Vector portResults = new Vector(); 
	   Vector TLDResults = new Vector();
	   
	   for (int portno = -10; portno < 70000; portno++) {
		   test = test + prefix + portno; 
		   if ( (urlVal.isValidAuthority(test) && (portno < 0 || portno > 65535)) ||
			   (!(urlVal.isValidAuthority(test)) && (portno >= 0 && portno <= 65535))) {
			   portResults.add(new String("Error when port is: " + portno));
		   }
		   test = "1.1.1.1"; 
	   }
		   
	   if (portResults.size() > 0) {
		   Iterator itr = portResults.iterator();
		   Object next = null;    
		   while(itr.hasNext()) {
		          next = itr.next(); 
		    	  //statement commented out after discovering a large number of errors
		          //System.out.println(next + " ");
		      }
		      System.out.println();
		      Iterator itr2 = portResults.iterator();
		      //statement used to discover range of port numbers with errors
		      System.out.println("Range of port numbers with errors: ");
		      System.out.println( itr2.next() + ", " + next);
		      
	   }
	   else {
		   System.out.println("No errors with port numbers found!");
	   }
		   
	   System.out.println("\nTesting Complete...");
       System.out.println("****************************************************************************************");   
   }
   
   
   public void testIsValid()
   {
	   System.out.println("Testing combinations of URLs and IP/port number combinations\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Stores arrays to be used to test combinations of website link as well as IP/Port number combinations.
	   String[] validScheme = new String[]{"http://", "ftp://", "h3t://", "attachment://", "chrome-extension://", 
			   "chrome://", "abc://", "icon://", "imap://", "info://", "mailto://", "magnet://"};
	   
	   String[] invalidScheme = new String[]{"3ttp://", "4444://", "7test://", "@apple://", "#goto://", "@mail://", 
			   "^new://", "$finance://", "!extreme://", "&and://", "*star://", "(towards)://", "8#abc://"};
	   
	   String[] validAuth = new String[]{"www.google.com", "www.amazon.com", "www.ebay.com", "www.nau.edu", 
			   "yahoo.com", "wish.org", "wikipedia.org", "www.az.gov", "www.fanfiction.net", "www.ign.com", 
			   "maps.google.com", "tacobell.com"};
	   
	   String[] invalidAuth = new String[]{"www.google.c3m", "www.google.bar", "www.yahoo.123", "mapquest", "z00m.3ml"};

	   String[] validPath = new String[]{"/test", "/123", "/images", "/image", "/img", "/home", "/user", "/usr", 
			   "/profile", "/pic", "/contact", "/mail" };
	   
	   String[] invalidPath = new String[]{"//test", ".img", "//images", "..map", "/user//bin", "/dir.", ".profile//", 
			   "/.mail", "tea.m/", "//12345", ".photo//", "//contact"};
	   
	   String[] validIP = new String[]{"1.2.3.4", "0.0.0.0", "255.255.255.255", "255.0.255.0", "5.8.200.58"};
  
	   String[] invalidIP = new String[]{"256.256.256.256", ".1.2.3.4", "go.a", "1.2.3", "123.123.456.123", 
				"123.123.0.456", "1.2.3.4.", "1.444.1.1", "1.2.3.4.5", "0.999.0.999"}; 
	   
	   String[] validPort = new String[]{"0", "1", "10", "99", "100", "500", "999", "1000", "5000", "9999", 
			   "10000", "50000", "60000", "65535"};
	   
	   String[] invalidPort = new String[]{"-1", "-65535", "65536", "70000", "jdgj", "1#5", "355i", "100000", 
			   "1000000", "999999"};
	   
	   //Count the number of errors
	   int validUrlError = 0;
	   int invalidUrlError = 0;
	   int validAuthorityError = 0;
	   int invalidAuthorityError = 0;
	   int totalErrors = 0;
	   String combinedLink;
	   
	   //Testing every possible valid combinations using scheme + authority + path
	   System.out.println("Testing combinations of valid URLs:");
	   for(int i = 0; i < validScheme.length; i++){
		   for(int j = 0; j < validAuth.length; j++){
			   for(int k = 0; k < validPath.length; k++){
				   //Sets up the url link
				   combinedLink = validScheme[i] + validAuth[j] + validPath[k];
				   
				   //Tests if the web link is valid. If it is not, increment the number of errors.
				   if(urlVal.isValid(combinedLink) != true){
					   validUrlError++;
				   }
			   }
		   }
	   }
	   System.out.println("The number of errors in this section is: " + validUrlError + "\n");
	   
	   //Testing every possible invalid combinations using scheme + authority + path to see if it errors out
	   System.out.println("Testing combinations of invalid URLs:");
	   for(int i = 0; i < invalidScheme.length; i++){
		   for(int j = 0; j < invalidAuth.length; j++){
			   for(int k = 0; k < invalidPath.length; k++){
				   //Sets up the url link
				   combinedLink = invalidScheme[i] + invalidAuth[j] + invalidPath[k];
				   
				   //Tests if the web link is invalid. If it is valid, increment the number of errors.
				   if(urlVal.isValid(combinedLink) != false){
					   invalidUrlError++;
				   }
			   }
		   }
	   }
	   System.out.println("The number of errors in this section is: " + invalidUrlError + "\n");
	   
	   //Testing every possible valid combinations for IP/Port number pairs using ip + port number
	   System.out.println("Testing combinations of valid IP and Port number combinations:");
	   for(int i = 0; i < validIP.length; i++){
		   for(int j = 0; j < validPort.length; j++){
			   //Sets up the link
			   combinedLink = validIP[i] + ":" + validPort[j];
			   
			   //Tests if the web link is valid. If it is not, increment the number of errors.
			   if(urlVal.isValidAuthority(combinedLink) != true){
				   validAuthorityError++;
				   //System.out.println(combinedLink);
			   }
		   }
	   }
	   System.out.println("The number of errors in this section is: " + validAuthorityError + "\n");
	   
	   //Testing every possible invalid combinations for IP/Port number pairs using ip + port number
	   System.out.println("Testing combinations of invalid IP and Port number combinations:");
	   for(int i = 0; i < invalidIP.length; i++){
		   for(int j = 0; j < invalidPort.length; j++){
			   //Sets up the link
			   combinedLink = invalidIP[i] + ":" + invalidPort[j];
			   
			   //Tests if the web link is invalid. If it is valid, increment the number of errors.
			   if(urlVal.isValidAuthority(combinedLink) != false){
				   invalidAuthorityError++;
			   }
		   }
	   }
	   System.out.println("The number of errors in this section is: " + invalidAuthorityError + "\n");
	   
	   
	   //Adds all the errors together and prints to console the total number of errors
	   totalErrors = validUrlError + invalidUrlError + validAuthorityError + invalidAuthorityError;
	   
	   //urlVal.isValidAuthority(validAuth[i]) == false)
	   System.out.println("Testing Complete... Total number of errors found is: " + totalErrors);
	   System.out.println("****************************************************************************************");	 
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
