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
	   System.out.println(" ********************Start Manual Testing******************** ");
	   System.out.println("1. " + urlVal.isValid("http://www.amazon.com"));//true
	   System.out.println("2. " + urlVal.isValid("http://www.manualtest.com"));//true
	   System.out.println("3. " + urlVal.isValid("http://wwwmanualtest.com"));//true
	   System.out.println("4. " + urlVal.isValid("http://www.manualtestcom"));//false
	   System.out.println("5. " + urlVal.isValid("http://www.manualtest.co"));//true
	   System.out.println("6. " + urlVal.isValid("ftp://www.manualtest.a"));///false
	   System.out.println("7. " + urlVal.isValid("http//www.manualtest.com"));//false
	   System.out.println("8. " + urlVal.isValid("h3t://www.manualtest.com"));//true
	   System.out.println("9. " + urlVal.isValid("http:/www.manualtest.com"));//false
	   System.out.println("10. " + urlVal.isValid("http:www.manualtest.com"));//false
	   System.out.println("11. " + urlVal.isValid("http://www.manualtest.com:80"));//true
	   System.out.println("12. " + urlVal.isValid("http://www.manualtest.com/test1"));//true
	   System.out.println("13. " + urlVal.isValid("3ht://www.manualtest.com"));//false
	   System.out.println("14. " + urlVal.isValid("http://www.manualtest..com"));//false
	   System.out.println("15. " + urlVal.isValid("://www.manualtest.com"));//false
	   System.out.println("16. " + urlVal.isValid("http://.aa:60abc/test1/file1"));//false
	   System.out.println("17. " + urlVal.isValid("http://www.manualtest.com:-1/test1"));//false
	   System.out.println("18. " + urlVal.isValid(":6172/test1/file1"));//false
	   System.out.println("19. " + urlVal.isValid("http://manualtest.com:80"));//true
	   System.out.println("20. " + urlVal.isValid("http://fdsjdhj.manualtest.com"));//true
	   
	   /* ****************************Bug found****************************** */
	   
	   /* Valid URL, should return true */
	   System.out.println("21. " + urlVal.isValid("http://www.manualtest.com?action=view"));//false
	   System.out.println("22. " + urlVal.isValid("http://www.manualtest.com:9810/?action=view"));//false
	   System.out.println("23. " + urlVal.isValid("http://www.manualtest.com:80/test1/?action=view"));//false
	   System.out.println("24. " + urlVal.isValid("http://www.manualtest.com/test1?action=view"));//false
	   
	   /* Valid Port and Path, but return false; False if port greater than a particular number */
	   System.out.println("25. " + urlVal.isValid("http://www.manualtest.com:9999/a123"));//false
	   
	   /* Specific country URL, but return false */
	   System.out.println("26. " + urlVal.isValid("http://www.manualtest.jp"));//false
	   System.out.println("27. " + urlVal.isValid("http://www.manualtest.com.my"));//false
	   
	   /* Invalid Scheme, but return true */
	   System.out.println("28. " + urlVal.isValid("asdh://www.manualtest.com"));//true
	   
	   /* Invalid Authority, but return true */
	   System.out.println("29. " + urlVal.isValid("http://www.255.255.256.255.com"));//true
	   
	   /* Special characters in URL, but return true */
	   System.out.println("30. " + urlVal.isValid("http://www.manualtest.com/%#^@"));//true
   }
   
   
   public void testYourFirstPartition()
   {
	   /* Testing all valid combination randomly - Expected to return true for all combination*/
	   System.out.println(" \n********************Start First Partition Test 1: True Combination******************** ");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   StringBuffer buffer = new StringBuffer();
	   
	   Random rand = new Random();
	   
	   ResultPair[] scheme = (ResultPair[]) testUrlPartsTrue[0];
	   ResultPair[] authority = (ResultPair[]) testUrlPartsTrue[1];
	   ResultPair[] port = (ResultPair[]) testUrlPartsTrue[2];
	   ResultPair[] path = (ResultPair[]) testUrlPartsTrue[3];
	   ResultPair[] query = (ResultPair[]) testUrlPartsTrue[4];
	   
	   int i, j, k, l, m;
		   
	   for (int n = 0; n < 200; n++){
		   i = rand.nextInt(scheme.length);
		   j = rand.nextInt(authority.length);
		   k = rand.nextInt(port.length);
		   l = rand.nextInt(path.length);
		   m = rand.nextInt(query.length);
		       
		   buffer.append(scheme[i].item);
		   buffer.append(authority[j].item);
		   buffer.append(port[k].item);
		   buffer.append(path[l].item);
		   buffer.append(query[m].item);

		   System.out.println("URL: " + buffer);
		   System.out.println("Test Result: " + urlVal.isValid(buffer.toString()) + "\t\tExpected: True\n");
		   
		   buffer.delete(0, buffer.length());
	   }
	   
	   /* Testing all valid combination randomly - Expected to return false for all combination*/
	   System.out.println(" \n********************Start First Partition Test 2: False Combination******************** ");
	   
	   scheme = (ResultPair[]) testUrlPartsFalse[0];
	   authority = (ResultPair[]) testUrlPartsFalse[1];
	   port = (ResultPair[]) testUrlPartsFalse[2];
	   path = (ResultPair[]) testUrlPartsFalse[3];
	   query = (ResultPair[]) testUrlPartsFalse[4];
		   
	   for (int n = 0; n < 100; n++){
		   i = rand.nextInt(scheme.length);
		   j = rand.nextInt(authority.length);
		   k = rand.nextInt(port.length);
		   l = rand.nextInt(path.length);
		   m = rand.nextInt(query.length);
		       
		   buffer.append(scheme[i].item);
		   buffer.append(authority[j].item);
		   buffer.append(port[k].item);
		   buffer.append(path[l].item);
		   buffer.append(query[m].item);

		   System.out.println("URL: " + buffer);
		   System.out.println("Test Result: " + urlVal.isValid(buffer.toString()) + "\t\tExpected: False\n");
		   
		   buffer.delete(0, buffer.length());
	   }
   }
   
   public void testYourSecondPartition(){
	   /* URL with port and path */
	   System.out.println(" \n********************Start Second Partition Test******************** ");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   StringBuffer buffer = new StringBuffer();
	   int rand_num;
	   String URLs[] = {"www.google.com",
			            "www.amazon.com",
			            "www.yahoo.com",
			            "www.wikipedia.com",
			            "www.facebook.com",
			            "www.twitter.com"};
	   
	   Random rand = new Random(); 
	   
	   System.out.println(" \n**********With Port********** ");
	   for (int i = 0; i < 100; i++){
		   for(int j = 0; j < URLs.length; j++){
			   rand_num = rand.nextInt(500) + 1;
		       buffer.append("http://" + URLs[j]);
		       buffer.append(":" + rand_num);
		       System.out.println("URL: " + buffer);
		       System.out.println("Test Result: " + urlVal.isValid(buffer.toString()) + "\t\tExpected: True\n");
		       buffer.delete(0, buffer.length());
		   }
		   
	   }
	   
	   System.out.println(" \n**********With File Directory********** ");
	   for (int i = 0; i < 6; i++){
		   for(int j = 0; j < URLs.length; j++){
		       buffer.append("http://" + URLs[j]);
		       buffer.append("/file1/");
		       System.out.println("URL: " + buffer);
		       System.out.println("Test Result: " + urlVal.isValid(buffer.toString()) + "\t\tExpected: True\n");
		       buffer.delete(0, buffer.length());
		   }
		   
	   }
	   
	   System.out.println(" \n**********With Port & File Directory********** ");
	   for (int i = 0; i < 100; i++){
		   for(int j = 0; j < URLs.length; j++){
			   rand_num = rand.nextInt(500) + 1;
		       buffer.append("http://" + URLs[j]);
		       buffer.append(":" + rand_num);
		       buffer.append("/file1/");
		       System.out.println("URL: " + buffer);
		       System.out.println("Test Result: " + urlVal.isValid(buffer.toString()) + "\t\tExpected: True\n");
		       buffer.delete(0, buffer.length());
		   }
		   
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
   
   ResultPair[] testUrlSchemeTrue = {new ResultPair("http://", true),
		   					   	   new ResultPair("ftp://", true),
		   					   	   new ResultPair("h3t://", true),
		   					   	   new ResultPair("", true)};
   
   ResultPair[] testUrlSchemeFalse = {new ResultPair("3ht://", false),
			   						new ResultPair("http:/", false),
			   						new ResultPair("http:", false),
			   						new ResultPair("http/", false),
			   						new ResultPair("://", false)};

   ResultPair[] testUrlAuthorityTrue = {new ResultPair("www.google.com", true),
		   						  new ResultPair("go.com", true),
		   						  new ResultPair("go.au", true),
		   						  new ResultPair("0.0.0.0", true),
		   						  new ResultPair("255.255.255.255", true),
		   						  new ResultPair("255.com", true),
		   						  new ResultPair("go.cc", true)};
   
   ResultPair[] testUrlAuthorityFalse = {new ResultPair("256.256.256.256", false),
			  						   new ResultPair("1.2.3.4.5", false),
			  						   new ResultPair("1.2.3.4.", false),
			  						   new ResultPair("1.2.3", false),
			  						   new ResultPair(".1.2.3.4", false),
			  						   new ResultPair("go.a", false),
			  						   new ResultPair("go.a1a", false),
			  						   new ResultPair("go.1aa", false),
			  						   new ResultPair("aaa.", false),
			  						   new ResultPair(".aaa", false),
			  						   new ResultPair("aaa", false),
			  						   new ResultPair("", false)};
   
   ResultPair[] testUrlPortTrue = {new ResultPair(":80", true),
		   					 new ResultPair(":65535", true),
		   					 new ResultPair(":0", true),
		   					 new ResultPair("", true),
		   					 new ResultPair(":65636", true)};
   
   ResultPair[] testUrlPortFalse = {new ResultPair(":-1", false),
				 				  new ResultPair(":65a", false)};
   
   ResultPair[] testPathTrue = {new ResultPair("/test1", true),
		        		  new ResultPair("/t123", true),
		        		  new ResultPair("/$23", true),
		        		  new ResultPair("/test1/", true),
		        		  new ResultPair("", true),
		        		  new ResultPair("/test1/file", true)};
   
   ResultPair[] testPathFalse = {new ResultPair("/..", false),
 		                       new ResultPair("/../", false),
 		                       new ResultPair("/..//file", false),
 		                       new ResultPair("/test1//file", false)};
  

   ResultPair[] testUrlQueryTrue = {new ResultPair("?action=view", true),
		   					  new ResultPair("?action=edit&mode=up", true),
		   					  new ResultPair("", true)};
   
   Object[] testUrlPartsTrue = {testUrlSchemeTrue, testUrlAuthorityTrue, testUrlPortTrue, testPathTrue, testUrlQueryTrue};
   Object[] testUrlPartsFalse = {testUrlSchemeFalse, testUrlAuthorityFalse, testUrlPortFalse, testPathFalse, testUrlQueryTrue};
   
   //Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
   //Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
   int[] testPartsIndex = {0, 0, 0, 0, 0};
   
}
