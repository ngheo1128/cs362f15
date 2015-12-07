/*
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
 * Daniel Bonnin
 * Victor Hernandez
 * Billy Kerns
 * 
 * CS362: Final Project, Part B
 * 
 * This file contains unit testing we performed for part B of the final project.
 */
import junit.framework.TestCase;
import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {
   
   //Declare known valid URL components.
   String validAuthority = "www.google.com";
   String validScheme = "http";
   String validPort = ":22";
   String validPath = "/test1";
   String validQuery = "?action=view";

   public UrlValidatorTest(String testName) {
      super(testName);
   }
  
   /**
    * Perform manual tests of UrlValidator.isValid().
    */
   public void testManualTest()
   {
	   System.out.println("Manual Tests: ");
	   UrlValidator urlVal = new UrlValidator();
	   //assertTrue(urlVal.isValid("http://300.128.128.128"));

	   //Smoke test with extremely common URL
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   
	   //Check port validation
	   assertTrue(urlVal.isValid("http://www.amazon.org:22"));
	   
	   //Check path and different subdomain
	   assertTrue(urlVal.isValid("http://adasd.amazon.com/test1"));
	   
	   //Check unusual top-level domain
	   assertTrue(urlVal.isValid("http://www.amazon.zw")); 
	 
	   //Lucky catch.  
	 //Line 446 UrlValidator.java  return !QUERY_PATTERN.matcher(query).matches(); 
	 //should be return QUERY_PATTERN.matcher(query).matches(); 
	 //
	 assertTrue(urlVal.isValid("http://www.amazon.gov?action=view"));
   }
   
 /**
    *  Test the scheme partition. 
    * 
    *  Test isValid() with known valid URL strings with known valid/invalid schemes. 
    */
   public HashMap<String, Boolean> testYourFirstPartition()
   {
	   HashMap<String, Boolean> schemes = new HashMap<String, Boolean>();
	   
	 //Known valid schemes
	   schemes.put("http://", true);
	   schemes.put("ftp://", true);
	   schemes.put("https://", true);
	   
	 //Known invalid schemes  
	   schemes.put("https", false);
	   schemes.put("data://", false);
	   schemes.put("zzzzz://", false);
	   schemes.put("ftp:/", false);
	   schemes.put("ftp", false);
	   schemes.put("ftp:://", false);
	   schemes.put("ftp:", false);
	   schemes.put("https:///", false);
	   schemes.put("https:$/", false);
	   schemes.put("https//", false);
	   
	return schemes;
   }
   
      /**
    *  Test the Authority partition. 
    * 
    *  Test isValid() with known valid URL strings with known valid/invalid authority strings. 
    */
      public void testYourSecondPartition(){
	   System.out.println("Testing Authority Partition:");
	   UrlValidator urlVal = new UrlValidator();
	   
	   assertTrue(urlVal.isValidScheme("http"));

	   assertTrue(urlVal.isValidAuthority(validAuthority + validPort));

	   assertTrue(urlVal.isValidPath(validPath));

	   //We can't use this assert until query bug is fixed.
	   //assertTrue(urlVal.isValidQuery(validQuery));

	 //Check known invalid authorities
	   String invalidAuthorityArr[] = {
			   "256.256.256.256",
			   "1.2.3.4.5",
			   ".1.2.3.4",
			   "go.a1a",
			   "go.1aa",
			   ".aaa",
			   "aaa",
			   "aaa.",
			   "1.2.3",
			   ""
	   	};
	   for(int i = 0; i < invalidAuthorityArr.length; i++){
		   String urlTry = validScheme + invalidAuthorityArr[i] + validPort + validPath + validQuery;
		   System.out.println(urlTry);
		   assertFalse(urlVal.isValid(urlTry));
	   }
		      
	 //Check known valid authorities
	   String validAuthorityArr[] = {
			"www.google.com",
	   		"google.com",
			"google.org",
			"255.com",
	   		"google.gov",
	   		"google.edu"
	   	};
		   
	   for(int i = 0; i < validAuthorityArr.length; i++){
		   String urlTry = validScheme + "://" + validAuthorityArr[i] + validPort + validPath;
		   assertTrue(urlTry, urlVal.isValid(urlTry));
	   }
	   
   }
   
      /**
    *  Test the port partition. 
    * 
    *  Test isValid() with known valid URL strings with known valid/invalid port strings. 
    */
   public void testYourThirdPartition(){
	   System.out.println("Testing Port Partition:");
	   UrlValidator urlVal = new UrlValidator();
	   String urlTry;
	   assertTrue(urlVal.isValidScheme(validScheme));

	   assertTrue(urlVal.isValidAuthority(validAuthority));

	   assertTrue(urlVal.isValidPath(validPath));
	   
	   //We can't use this assert until query bug is fixed.
	   //assertTrue(urlVal.isValidQuery(validQuery));
	   
	 //Check known invalid ports
	   String[] invalidPortArr = {
	   ":123456",
	   ":655365",
	   ":1b3",
	   ":b21",
	   ":.11111",
	   ":ljljl",
	   ":-1",
	   ":-200",
	   ":-b.",
	   ":1234567",
	   ":-0"};
		   
	   for(int i = 0; i < invalidPortArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + invalidPortArr[i] + validPath;
		   assertFalse(urlTry, urlVal.isValid(urlTry));
	   }
	   
	 //Check known valid ports
	   String[] validPortArr = {
	   ":22",
	   ":65535",
	   ":0",
	   ":65534",
	   ":1",
	   ":12",
	   ":123",
	   ":1234",
	   ":12345",
	   ":11111",
	   };
	   for(int i = 0; i < validPortArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + validPortArr[i] + validPath;
		   assertTrue(urlTry, urlVal.isValid(urlTry));
	   }   
   }
   
      /**
    *  Test the path partition. 
    * 
    *  Test isValid() with known valid URL strings with known valid/invalid path strings. 
    */
   public void testYourFourthPartition(){
	   String urlTry;
	   System.out.println("Testing Path Partition:");
	   UrlValidator urlVal = new UrlValidator();
	   
	   assertTrue(validScheme, urlVal.isValidScheme(validScheme));

	   assertTrue(validAuthority, urlVal.isValidAuthority(validAuthority));

	   assertTrue(validAuthority+validPort, urlVal.isValidAuthority(validAuthority + validPort));
	   
	   //We can't use this assert until query bug is fixed.
	   //assertTrue(validQuery, urlVal.isValidQuery(validQuery));

	   //Check known invalid paths
	   String invalidPathArr[] = {
			   "/..",
			   "/../",
			   "/..//file",
			   "/test1//file",
			   "///////",
			   "abc",
			   "_$",
			   "/^"
	   };
	   
	   for(int i = 0; i < invalidPathArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + validPort + invalidPathArr[i];
		   assertFalse(urlTry, urlVal.isValid(urlTry));
	   }
	   
	   //Check known valid paths
	   String validPathArr[] = {
			   "/test1",
			   "/t123",
			   "/$23",
			   "/test1/",
			   "/test1/file",
			   "/java/java_object_classes",
			   "/courses/1555028/assignments/6594488",
			   "/wiki/Uniform_Resource_Identifier",
			   "/search",
			   "/r/cscareerquestions"
	   };
	   
	   for(int i = 0; i < validPathArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + validPort + validPathArr[i];
		   assertTrue(urlTry, urlVal.isValid(urlTry));
	   }   
   }
   
      /**
    *  Test the query partition. 
    * 
    *  Test isValid() with known valid URL strings with known valid/invalid query strings. 
    */
   public void testYourFithPartition(){
	   String urlTry;
	   System.out.println("Testing Query Partition:");
	   UrlValidator urlVal = new UrlValidator();
	   
	   assertTrue(validScheme, urlVal.isValidScheme(validScheme));

	   assertTrue(validAuthority, urlVal.isValidAuthority(validAuthority));

	   assertTrue(validAuthority + validPort, urlVal.isValidAuthority(validAuthority + validPort));

	   assertTrue(validPath, urlVal.isValidPath(validPath));

	 //Check known invalid queries
	   String[] invalidQueryArr = {
	   "?!!!!@#$#$%^%^&%*&()..",
	   "?/../",
	   "?/..//file",
	   "?/test1//file",
	   "?///////",
	   "?456/@",
	   "?abc",
	   "?_$",
	   "?/_#",
	   "?/^"
	   };
	   
	   //All valid queries return true. This test will fail on any query. 
	   for(int i = 0; i < invalidQueryArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + validPort + validPath + invalidQueryArr[i];
		   assertFalse(urlTry + Integer.toString(i), urlVal.isValid(urlTry));
	   }

	 //Check known valid queries
	   String[] validQueryArr = {
	   "?action=view",
	   "?action=edit&mode=up",
	   "?newwindow=1&q=url+query",
	   "?module_item_id=16435218",
	   "?some_action=Some_thiNG",
	   "?1111=22222",
	   "?royals=world_series_champs",
	   "?ideas=NoNe",
	   "?last_ONE=false",
	   "?LAST_one=true",
	   };
	   
	   for(int i = 0; i < validQueryArr.length; i++){
		   urlTry = validScheme + "://" + validAuthority + validPort + validPath + validQueryArr[i];
		   assertTrue(urlTry, urlVal.isValid(urlTry));
	   } 
   }
   
   public void combinationTest(
		   int testNo,
		   int scheme, 
		   int auth, 
		   int port, 
		   int path,
		   boolean allowAllSchemes, 
		   boolean allow2Slashes,
		   boolean noFragments,
		   boolean allowLocal
		   ){
	   
	   //Declare valid/invalid URL parts.
	   String thisScheme [] = {"http://",        "wrongScheme://",      ""};
	   String thisAuth [] =   {"www.google.com", "go.1aa",   "", "128.128.128.128", "999.999.999.999"};
	   String thisPort [] =   {":22",            ":1234567", ""};
	   String thisPath [] =   {"/test1",         "_$",       ""};
	   Boolean shouldPass;
	   long options = 0 + 
			   	(allowAllSchemes ? UrlValidator.ALLOW_ALL_SCHEMES : 0) + 
				(allow2Slashes ? UrlValidator.ALLOW_2_SLASHES : 0) + 
				(noFragments ? UrlValidator.NO_FRAGMENTS : 0);
	   
	   String url = thisScheme[scheme] + thisAuth[auth] + thisPort[port] + thisPath[path];

	   UrlValidator urlVal = new UrlValidator(options);
	   if 	(((scheme == 1 || scheme == 2) && !allowAllSchemes)	|| 
	   		(auth == 1 || auth == 2 || auth == 4)				||
	   		(port == 1)											||
	   		(path == 1)) {
		   
		   shouldPass = false;
		   System.out.println("Test# " + Integer.toString(testNo) + ((testNo < 10) ? ": " : ":") + " Expected to " + 
				   (shouldPass ? "pass: " : "fail: ") + url);
		   assertFalse(urlVal.isValid(url));
	   }
	   else {
		   shouldPass = true;
		   System.out.println("Test# " + Integer.toString(testNo) + ((testNo < 10) ? ": " : ":") + " Expected to " + 
				   (shouldPass ? "pass: " : "fail: ") + url);
		   assertTrue(urlVal.isValid(url));
	   }
   }
   
   /**
    * testIsValid() implements a 3-way covering array with the following 
    * parameters:
    * scheme, authority, port, path, allowAllSchemes, allow2Slashes, 
    * noFragments, allowLocal.
    * 
    * We used a tool called pairwiser (https://inductive.no/pairwiser/)
    * to help generate the covering array.
    * 
    * There are 65 test cases in all. They are read from 3wayCombination.txt.
    * 
    * combinationTest() prints relevant info to console.
    */
   public void testIsValid()
   {
	   //Read 3wayCombination.txt into an object containing test cases.
	   //Help received from https://www.caveofprogramming.com/java/java-file-reading-and-writing-files-in-java.html
	   String line = null;
	   String fileName = "src/3wayCombination.txt";
	   
	   ArrayList<ArrayList<String>> testCases = new ArrayList<ArrayList<String>>();

	   try {
		   FileReader fileReader = new FileReader(fileName);
		   
		   BufferedReader bufferedReader = new BufferedReader(fileReader);
		   
		   while((line = bufferedReader.readLine()) != null) {
			   testCases.add(new ArrayList<String>(Arrays.asList(line.split("\\s*,\\s*"))));
		   }
		   bufferedReader.close();
		   
	   }
	   
	//2 blocks below are copied verbatim from Source.
       catch(FileNotFoundException ex) {
           System.out.println(
               "Unable to open file '" + 
               fileName + "'");                
       }
       catch(IOException ex) {
           System.out.println(
               "Error reading file '" 
               + fileName + "'");                  
       }
	   
	   for (ArrayList<String> tCase : testCases) {
	   //Assert the correct outcome according to the options
	   combinationTest(
			Integer.parseInt(tCase.get(0)), Integer.parseInt(tCase.get(1)), 
			Integer.parseInt(tCase.get(2)), Integer.parseInt(tCase.get(3)),  
			Integer.parseInt(tCase.get(4)), Boolean.parseBoolean(tCase.get(5)), 
			Boolean.parseBoolean(tCase.get(6)), Boolean.parseBoolean(tCase.get(7)), 
			Boolean.parseBoolean(tCase.get(8))
			);
	   }
   }
   
 public void testAnyOtherUnitTest()
   {
	   UrlValidator urlVal = new UrlValidator();
	   String validAuthority = "www.google.com";
	   String validScheme = "http";
	   String validPort = ":22";
	   String validPath = "/test1";
	   String validQuery = "?action=view";
	   
	   System.out.println("Testing Scheme Partition:");
	   //Check to make sure the pieces we aren't testing are valid.
	   assertTrue(urlVal.isValidAuthority(validAuthority + validPort));
	   assertTrue(urlVal.isValidAuthority(validAuthority));
	   assertTrue(urlVal.isValidPath(validPath));
	   //We can't use this assert until query bug is fixed.
	   //assertTrue(urlVal.isValidQuery(validQuery));

	   
	   Map<String, Boolean> schemesUnitTest = new HashMap<String, Boolean>();
	   
	   schemesUnitTest = testYourFirstPartition();
	   for(Map.Entry<String, Boolean> entry : schemesUnitTest.entrySet()){
		   String urlTry = entry.getKey() + validAuthority + validPort + validPath;
		   System.out.println(urlTry);
		   if(entry.getValue() == true){
			   assertTrue(urlTry, urlVal.isValid(urlTry));
		   }
		   else{
			   assertFalse(urlTry, urlVal.isValid(urlTry));
		   }
       }

   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
  
}