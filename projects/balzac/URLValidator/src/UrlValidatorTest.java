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
	   
	   System.out.println(urlVal.isValid("http://www.amazon.com"));//true
	   System.out.println(urlVal.isValid("https://www.google.com"));//true
	   System.out.println(urlVal.isValid("ftp://www.test.com"));//true
	   System.out.println(urlVal.isValid("http://www.test.com/test.html"));//true
	   System.out.println(urlVal.isValid("http://www.test.com/test.php"));//true
	   System.out.println(urlVal.isValid("geo://www.test.com"));//true
	   System.out.println(urlVal.isValid("http://255.255.255.255:80"));//true
	   System.out.println(urlVal.isValid(null));//false
	   System.out.println(urlVal.isValid(" "));//false
	   System.out.println(urlVal.isValid("https://///www.google.com"));//false
	   System.out.println(urlVal.isValid("http://www.jibberishdomain.sdfsfsdf"));//false
	   System.out.println(urlVal.isValid("http://www.testcom"));//false
	   System.out.println(urlVal.isValid("http://wwwtestcom"));//false
	   System.out.println(urlVal.isValid("http://www.test."));//false
	   System.out.println(urlVal.isValid("http:/www.test.com"));//false
	   System.out.println(urlVal.isValid("http:www.test.com"));//false
	   System.out.println(urlVal.isValid("http//www.test.com"));//false
	   System.out.println(urlVal.isValid("http/www.test.com"));//false
	   System.out.println(urlVal.isValid("httpwww.test.com"));//false
	   System.out.println(urlVal.isValid("http://"));//false
	   System.out.println(urlVal.isValid("http"));//false
	   System.out.println(urlVal.isValid("moc.tset.www//:ptth"));//false
	   System.out.println(urlVal.isValid("com.test.wwwhttp://"));//false
	   System.out.println(urlVal.isValid("com.test.www//:http"));//false
	   System.out.println(urlVal.isValid("://:65a/test1//file"));//false
	   System.out.println(urlVal.isValid("3ht://www.google.com"));//false
	   
	   //FOUND BUGS, THIS SHOULD BE FALSE NOT TRUE
	   System.out.println(urlVal.isValid("http://wwwtest.com"));//no . after www
	   System.out.println(urlVal.isValid("htp://www.test.com"));//bad scheme
	   System.out.println(urlVal.isValid("sdfsffsdfsdfs://www.test.com"));//bad scheme
	   
	   //FOUND BUGS, THIS SHOULD BE TRUE NOT FALSE
	   System.out.println(urlVal.isValid("http://www.test.xxx"));//valid domain
	   System.out.println(urlVal.isValid("http://www.test.zw"));//valid domain
	   System.out.println(urlVal.isValid("http://www.test.je"));//valid domain
	   System.out.println(urlVal.isValid("http://www.google.com:80/test1?action=view"));// ? causes error
	   System.out.println(urlVal.isValid("www.google.com"));//valid
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
