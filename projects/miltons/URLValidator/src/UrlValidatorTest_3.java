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
	   System.out.println("1 Valid URL, expected true, returned " + urlVal.isValid("http://www.amazon.com"));
	   
	   System.out.println("2 Valid URL, expected true, returned " + urlVal.isValid("http://www.facebook.com"));
	   
	   System.out.println("3 Invalid scheme, expected false, returned " + urlVal.isValid("hppt://www.facebook.com")); // invalid scheme

	   System.out.println("4 Invalid scheme, expected false, returned " + urlVal.isValid("l33t://www.facebook.com")); // invalid scheme	 
	   
	   System.out.println("5 Invalid scheme, expected false, returned " + urlVal.isValid("areeaallylongonehere://www.facebook.com")); // invalid scheme	   	 
	   
	   System.out.println("6 Invalid scheme, expected false, returned " + urlVal.isValid("http//www.facebook.com")); // invalid scheme	   	   	   

	   System.out.println("7 Invalid scheme, expected false, returned " + urlVal.isValid("http:://www.facebook.com")); // invalid scheme	   
	   
	   System.out.println("8 Invalid scheme, expected false, returned " + urlVal.isValid("0://www.facebook.com")); // invalid scheme	   
	   
	   System.out.println("9 Invalid scheme, expected false, returned " + urlVal.isValid("0//www.facebook.com")); // invalid scheme		   
	   
	   System.out.println("10 Invalid authority, expected false, returned " + urlVal.isValid("http://www..facebook.com")); // invalid authority
	   
	   System.out.println("11 Invalid authority, expected false, returned " + urlVal.isValid("http://www.facebook./com")); // invalid authority
	   
	   System.out.println("12 Valid port, expected true, returned " + urlVal.isValid("http://www.facebook.com:65535")); // valid port
	   
	   System.out.println("12b Valid port, expected true, returned " + urlVal.isValid("http://www.facebook.com:0")); // valid port	  

	   System.out.println("12c Valid port, expected true, returned " + urlVal.isValid("http://www.facebook.com:10")); // valid port
	   
	   System.out.println("12d Valid port, expected true, returned " + urlVal.isValid("http://www.facebook.com:100")); // valid port		 
	   
	   System.out.println("12e Valid port, expected true, returned " + urlVal.isValid("http://www.facebook.com:1000")); // valid port		   
	   
	   System.out.println("12f Invalid port, expected false, returned " + urlVal.isValid("http://www.facebook.com:65536")); // invalid port	 
	   
	   System.out.println("12g Invalid port, expected false, returned " + urlVal.isValid("http://www.facebook.com:-1")); // invalid port	   
	   
	   System.out.println("13 Invalid port, expected false, returned " + urlVal.isValid("http://www.facebook.com::65535")); // invalid port
	   
	   System.out.println("14 Valid path, expected true, returned " + urlVal.isValid("http://www.facebook.com/validPath.html"));
	   
	   System.out.println("15 Invalid path, expected false, returned " + urlVal.isValid("http://www.facebook.com///invalidPath.html"));

	   System.out.println("16 Valid query, expected true, returned " + urlVal.isValid("http://www.facebook.com?validquery=true"));
	   
	   System.out.println("17 Invalid query, expected false, returned " + urlVal.isValid("http://www.facebook.com?validquery==false"));	   

	   System.out.println("18 Invalid scheme, expected false, returned " + urlVal.isValid("http: //www.facebook.com")); // contains white space
	   
	   System.out.println("19 Invalid scheme, expected false, returned " + urlVal.isValid("http:/ /www.facebook.com")); // contains white space	   
	   
	   System.out.println("20 Invalid authority, expected false, returned " + urlVal.isValid("http:// www.facebook.com")); // contains white space
	   
	   System.out.println("21 Invalid authority, expected false, returned " + urlVal.isValid("http://www .facebook.com")); // contains white space
	   
	   System.out.println("22 Invalid path, expected false, returned " + urlVal.isValid("http://www.facebook.com /invalidPath")); // contains white space	   	   
	   
	   System.out.println("23 Invalid path, expected false, returned " + urlVal.isValid("http://www.facebook.com/ invalidPath")); // contains white space	   	   

	   System.out.println("24 Invalid path, expected false, returned " + urlVal.isValid("http://www.facebook.com ?invalidQuery")); // contains white space	   	   

	   System.out.println("25 Invalid path, expected false, returned " + urlVal.isValid("http://www.facebook.com? invalidQuery")); // contains white space		   
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
   
   
   // Test ports 0-65535
   public void testPorts()
   {
	   String url;
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);
	   
	   for(int i=1000; i<1100; i++) // i=900; i<1100
	   {
		   url = "http://www.google.com:"+Integer.toString(i);
		   if(!urlVal.isValid(url))
		   {
			   System.out.println("TEST Failed: "+url);
		   }
		   
	   }
   }

}
