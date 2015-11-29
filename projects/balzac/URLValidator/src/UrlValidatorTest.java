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
	   
	   
	   System.out.println(urlVal.isValid("http://www.google.com #"));//true
	   
	   
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
   
   
   /*Generate random values for the scheme in 3 different parts for example
    * http:// would be broken into three parts; (http), (:), and (//) Each of these three
    * parts will be randomized using numbers 0-9 and random characters and symbols.
    * Phase 1, only randomize part 1, phase 2, only randomize part 2, phase 3 only randomize
    * part 3, phase 4, randomize all three parts.*/
   public void testRandomScheme()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   int count = 0;
	   System.out.printf("\nTesting Random Scheme\n\n");
	   System.out.printf("Phase 1 test\n");
	   for(int j = 0; j < 500; j++)
	   {
		   String domain = "://www.google.com";
		   String part1 = "";
		   String url = "";
		   Boolean valid;
	   
		   /*Generate random length for part1 for each iteration 0 - 6*/
		   Random randomGenerator = new Random();
		   int randomLength = randomGenerator.nextInt(6);
		   
		   for(int i = 0; i <= randomLength; i++)
		   {
			   Random randomValue = new Random();
			   int randomAscii = (randomValue.nextInt(127) + 32); /*32-126*/
			   char c = (char)randomAscii;
			  // System.out.println(c);
			   part1 += c;
		   }
		   url += part1;
		   
		   url += domain;
		 //  System.out.println(url);
		   
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(part1);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Schemes from phase 1 were invalid out of 500\n", count);
	   
	   System.out.printf("Phase 2 test\n");
	   count = 0;
	   for(int j = 0; j < 1000; j++)
	   {
		   String domain = "//www.google.com";
		   String part2 = "";
		   String url = "http";
		   Boolean valid;
	   
		   
		   Random randomPart2 = new Random();
		   int randomAscii = (randomPart2.nextInt(127) + 32); /*32-126*/
		   char c = (char)randomAscii;
		   
		   url += c;
		   url += domain;
		
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(c);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Schemes from phase 2 were invalid out of 1000\n", count);
	   
	   System.out.printf("Phase 3 test\n");
	   count = 0;
	   for(int j = 0; j < 100000; j++)
	   {
		   String domain = "www.google.com";
		   String part3 = "";
		   String url = "http:";
		   Boolean valid;
	   
		   
		   for(int i = 0; i < 2; i++)
		   {
			   Random randomPart3 = new Random();
			   int randomSymbol = (randomPart3.nextInt(127) + 32); /*32-126*/
			   char c = (char)randomSymbol;
			   part3 += c;
		   }
		   
		   url += part3;
		   url += domain;
		
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(part3);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Schemes from phase 3 were invalid out of 100000\n", count);
	   
	   System.out.printf("Phase 4 test\n");
	   count = 0;
	   
	   for(int j = 0; j < 10000000; j++)
	   {
		   String domain = "www.google.com";
		   String part1 = "";
		   String part3 = "";
		   String url = "";
		   Boolean valid;
	   
		   /*Generate random length for part1 for each iteration 0 - 6*/
		   Random randomGenerator = new Random();
		   int randomLength = randomGenerator.nextInt(6);
		   
		   for(int i = 0; i <= randomLength; i++)
		   {
			   Random randomValue = new Random();
			   int randomAscii = (randomValue.nextInt(127) + 32); /*32-126*/
			   char c = (char)randomAscii;
			  // System.out.println(c);
			   part1 += c;
		   }
		   url += part1;
		   
		   Random randomPart2 = new Random();
		   int randomAscii = (randomPart2.nextInt(127) + 32); /*32-126*/
		   char c = (char)randomAscii;
		   url += c;
		  
		   for(int i = 0; i < 2; i++)
		   {
			   Random randomPart3 = new Random();
			   int randomSymbol = (randomPart3.nextInt(127) + 32); /*32-126*/
			   char s = (char)randomSymbol;
			  // System.out.println(c);
			   part3 += s;
		   }
		   
		   url += part3;
		   url += domain;
		 //  System.out.println(url);
		   
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(url);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Schemes from phase 4 were invalid out of 10000000\n", count);
   }
   
   /*This test generates random values for the two separators in the url. The Separators that I am
    * referring to are the "." in the url. For example, http://www.google.com has two "." separators.*/
   public void testRandomSeparator()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   int count = 0;
	   System.out.printf("\nTesting Random Separators\n\n");
	  
	   for(int j = 0; j < 10000; j++)
	   {
		   String part1 = "google";
		   String part2 = "com";
		   String url = "http://www";
		   String s1 = "";
		   String s2 = "";
		   Boolean valid;
	   
		   
		   /*assign separator 1 a random value*/
		   Random randomValue = new Random();
		   int randomAscii = (randomValue.nextInt(127) + 32); /*32-126*/
		   char c = (char)randomAscii;
		  // System.out.println(c);
		   s1 += c;
		   url += s1;
		   url += part1;
		   
		   /*assign separator 2 a random value*/
		   Random randomValue2 = new Random();
		   int randomAscii2 = (randomValue2.nextInt(127) + 32); /*32-126*/
		   char c2 = (char)randomAscii2;
		 //  System.out.println(c2);
		   s2 += c2;
		  
		   url += s2;
		   url += part2;
		   
		   //System.out.println(url);
		   
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(url);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Separtor combininations were invalid out of 10000\n", count);
   }
   
   /*Testing random values for path character and content. For example "http://www.google.com/path", the
    * "/" after .com with be replaced with randomly generated characters along with the value for where "path" is.*/
   public void testRandomPath()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   int count = 0;
	   System.out.printf("\nTesting Random Path\n\n");
	  
	   for(int j = 0; j < 10000; j++)
	   {
		   String url = "http://www.google.com";
		   String pathSign = "";
		   String path = "";
		   Boolean valid;
	   
		   
		   /*assign pathSign a random value*/
		   Random randomValue = new Random();
		   int randomAscii = (randomValue.nextInt(127) + 32); /*32-126*/
		   char c = (char)randomAscii;
		  // System.out.println(c);
		   pathSign += c;
		   url += pathSign;
		   
		   /*Generate random length for part1 for each iteration 0 - 6*/
		   Random randomGenerator = new Random();
		   int randomLength = randomGenerator.nextInt(6);
		   
		   for(int i = 0; i <= randomLength; i++)
		   {
			   Random randomValue2 = new Random();
			   int randomAscii2 = (randomValue2.nextInt(127) + 32); /*32-126*/
			   char c2 = (char)randomAscii2;
			  // System.out.println(c);
			   path += c2;
		   }
		   url += path;
		   
		   //System.out.println(url);
		   
		   valid = urlVal.isValid(url);
		   
		   if(valid == true)
		   {
			   System.out.println(url);
		   }
		   else
		   {
			   count++;
		   }
	   }
	   System.out.printf("%d Path combininations were invalid out of 10000\n", count);
   }
   
   
   
}




