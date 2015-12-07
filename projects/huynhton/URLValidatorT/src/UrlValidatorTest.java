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
	   /*System.out.println(urlVal.isValid("ftp://www.amazon.com"));
	   System.out.println(urlVal.isValid("h3t://www.amazon.com"));
	   System.out.println(urlVal.isValid("3ht://www.amazon.com"));
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("http:www.amazon.com"));
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("://www.amazon.com"));
	   System.out.println(urlVal.isValid(""));*/
	   
	   /*System.out.println(urlVal.isValid("http://www.amazon.cooom"));
	   System.out.println(urlVal.isValid("http://www.amazon.net"));
	   System.out.println(urlVal.isValid("http://www.amazon.kkt"));*/
	   //assertTrue(urlVal.isValid("http://google.com"));
	   
	   
	   /*
	   String testURLstr1 = "ftp://255.255.255.255:1005/test1/";
	   String testURLstr2 = "ftp://www.google.com/test1";
	   String testURLstr3 = "h3t://go.cc:65636/test1/?action=edit&mode=up";
	   String testURLstr4 = "http://yahoo.au:90/testing/testt123?anythinggoes=view";
	   */
	   
	   /*
	   System.out.println(urlVal.isValid(testURLstr1));
	   System.out.println(urlVal.isValid(testURLstr2));
	   System.out.println(urlVal.isValid(testURLstr3));
	   System.out.println(urlVal.isValid(testURLstr4));
	   */
	   
	   /* valid URLs that come out as invalid (from manual testing):
	    * http://go.cc:65535/t123?action=edit&mode=up
	    * h3t://go.cc:65636/test1/?action=edit&mode=up
	    * ftp://255.255.255.255:65636/test1/file?action=view	// in section 65636, this section can't take more than three digits
	    * mailto://yahoo.au:90/testing/testt123?anythinggoes=view	// once the "?" is introduced, it gives us a false URL
	    * 
	    * 
	    */
	   
   }
   /*
    ResultPair[] testUrlScheme = {new ResultPair("http://", true),
                               new ResultPair("ftp://", true),
                               new ResultPair("h3t://", true),
                               new ResultPair("3ht://", false),
                               new ResultPair("http:/", false),
                               new ResultPair("http:", false),
                               new ResultPair("http/", false),
                               new ResultPair("://", false),
                               new ResultPair("", true)};
    */
   
   public void testYourFirstPartition()  // manual input testing. finding 
   {
	   // initialize some variables
	   int i1, i2, i3, i4 , i5, i6;
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("FIRST PARTITION TEST\n");
	   
	   
	// loop variable
	   int i;
	   
	   // creating strings to partition 
	   
	   // create a valid, "control" string to test against
	   String firstHalfUrl = "ftp://255.255.255.255";
	   String secondHalfUrl = ":65/$23";
	   String validUrl = firstHalfUrl + secondHalfUrl;	   
	   
	   String firstHalfSet[] = {"http://0.0.0.0", "h3t://1.1.1.1", "ftp://www.amazon.com","h3t://go.au"};
	   String secondHalfSet[] = {"",":6",":667/test1/?action=edit&mode=up",":0/test1/file"};
	   String firstHalfBad[] = {"http://1.2.3.4.", "http:/www.google.com", "go.a", "://aaa."};
	   String secondHalfBad[] = {"/../$23?action=view", ":-1/#", "/#/file", "/test1//file"};
	   String testURLstr; 
	   
	   System.out.printf("Base Case: %s",validUrl);
	   System.out.printf("\n  Result: %s\n\n",urlVal.isValid(validUrl));
	   
	   System.out.println("Expected Valid URLs\n----------");
	   for(i = 0; i < 4; i++)
	   {
		   testURLstr = firstHalfUrl + secondHalfSet[i];
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   
		   testURLstr = firstHalfSet[i] + secondHalfUrl;
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   }
	   
	   System.out.println("\nExpected Invalid URLs\n----------");
	   for(i = 0; i < 4; i++)
	   {
		   testURLstr = firstHalfUrl + secondHalfBad[i];
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   
		   testURLstr = firstHalfBad[i] + secondHalfUrl;
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   }
	   
	   
	   
	   
	   /*
	   // creating strings to partition 
	   String testUrlScheme[] = {"http://","ftp://","h3t://", "http:", "3ht://"};
	   int testSchemeValid[] = {0, 0, 0, 1, 1};	// 0 = true, 1 = false
	   String testUrlAuthority[] = {"www.google.com","255.com","go.cc", "0.0.0.0", "256.256.256.256"};
	   int testAuthorityValid[] = {0, 0, 0, 0, 1};
	   String testUrlPort[] = {":80",":0",":65535", ":65a", "-1"};	//(t,t,f,f,t)
	   int testPortValid[] = {0, 0, 0, 1, 1};
	   String testUrlPath[] = {"/test1","","/$23", "/../", "/test1//file"};	//(t,t,f,f,t)
	   int testPathValid[] = {0, 0, 0, 1, 1};
	   String testUrlOptions[] = {"/test1","/t123","/test1/file", "", "/#/file"};	//(t,t,f,f,t)
	   int testOptionsValid[] = {0, 0, 0, 0, 1};
	   String testUrlQuery[] = {"?action=view","?action=edit&mode=up","", "testing_ThisShouldFail", "F7*6AwdIjs()&9L"};	//(t,t,f,f,t)
	   int testQueryValid[] = {0, 0, 0, 1, 1};
	   
	   
	   
	   String testURLstr1, testURLstr2, testURLstr3, testURLstr4, testURLstr5, testURLstr6;
	   int validChecker;
	   */
	   
	   
	   /*
	   for(i1 = 0; i1 < 3; i1++)
	   {
		   validChecker = 0;
		   testURLstr1 = testUrlScheme[i1];
		   validChecker += testSchemeValid[i1];
		   
		   for(i2 = 0; i2 < 3; i2++)
		   {
			   testURLstr2 = testURLstr1 + testUrlAuthority[i2];
			   validChecker += testAuthorityValid[i2];
			   
			   for(i3 = 0; i3 < 3; i3++)
			   {
				   testURLstr3 = testURLstr2 + testUrlPort[i3];
				   validChecker += testPortValid[i3];
				   
				   for(i4 = 0; i4 < 3; i4++)
				   {
					   testURLstr4 = testURLstr3 + testUrlPath[i4];
					   validChecker += testPathValid[i4];
					   
					   for(i5 = 0; i5 < 3; i5++)
					   {
						   testURLstr5 = testURLstr4 + testUrlOptions[i5];
						   validChecker += testOptionsValid[i5];
						   
						   for(i6 = 0; i6 < 3; i6++)
						   {
							   testURLstr6 = testURLstr5 + testUrlQuery[i6];
							   validChecker += testQueryValid[i6];
							   
							   //System.out.println(testURLstr6);
							   //System.out.println(urlVal.isValid(testURLstr6));
							   //System.out.println(validChecker);
							   validChecker -= testQueryValid[i6];
						   }
						   
						   validChecker -= testOptionsValid[i5];
					   }

					   validChecker -= testPathValid[i4];
				   }
				   
				   validChecker -= testPortValid[i3];
			   }
			   
			   validChecker -= testAuthorityValid[i2];
		   }
		   
		   validChecker -= testSchemeValid[i1];
		   
	   }
	   */
	   //System.out.println("http://www.google.com:80/test1/test1");
	   
	   
		//System.out.println(urlVal.isValid("http://www.google.com:80/test1/test1"));
			   
			   
      
   }
   
   public void testYourSecondPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("\n\nSECOND PARTITION TEST\n");
	   
	   // loop variable
	   int i;
	   
	   // creating strings to partition 
	   
	   // create a valid, "control" string to test against
	   String firstHalfUrl = "http://www.google.com";
	   String secondHalfUrl = ":80/test1";
	   String validUrl = firstHalfUrl + secondHalfUrl;	   
	   
	   String firstHalfSet[] = {"http://255.com", "ftp://go.cc", "http://0.0.0.0","h3t://go.cc"};
	   String secondHalfSet[] = {":80/$23/t123",":65535",":958",":0/test1/file"};
	   String firstHalfBad[] = {"http://1.2.3.4.", "http:/www.google.com", "go.a", "://aaa."};
	   String secondHalfBad[] = {"/../$23?action=view", ":-1/#", "/test1/$23/file?action=edit&mode=up", ":65a?action=view"};
	   String testURLstr; 
	   
	   System.out.printf("Base Case: %s",validUrl);
	   System.out.printf("\n  Result: %s\n\n",urlVal.isValid(validUrl));
	   
	   System.out.println("Expected Valid URLs\n----------");
	   for(i = 0; i < 4; i++)
	   {
		   testURLstr = firstHalfUrl + secondHalfSet[i];
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   
		   testURLstr = firstHalfSet[i] + secondHalfUrl;
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   }
	   
	   System.out.println("\nExpected Invalid URLs\n----------");
	   for(i = 0; i < 4; i++)
	   {
		   testURLstr = firstHalfUrl + secondHalfBad[i];
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   
		   testURLstr = firstHalfBad[i] + secondHalfUrl;
		   System.out.printf("URL: %s\n", testURLstr);
		   System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
	   }	   
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
