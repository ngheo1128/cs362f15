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
import java.io.Serializable;



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

      //true
	   System.out.println(urlVal.isValid("http://www.amazon.com")); //true
	   System.out.println(urlVal.isValid("www.amazon.com")); //false***
      System.out.println(urlVal.isValid("255.255.255.255"));	 //false***
	   System.out.println(urlVal.isValid("http://www.amazon.com:80")); //true
	   //false
	   System.out.println(urlVal.isValid("http://*.amazon.com")); //false
	   System.out.println(urlVal.isValid("http://www.amazon\\.com")); //false
	   System.out.println(urlVal.isValid("http://www.amazon.asdf")); //false
	   System.out.println(urlVal.isValid("htp://ww.amazon.com")); //true***
	   System.out.println(urlVal.isValid("htp://w.amazon.com")); //true***
	   System.out.println(urlVal.isValid("htp://www.amazon.com")); //true***
      System.out.println(urlVal.isValid("256.255.255.255")); //false
	   System.out.println(urlVal.isValid("http://www.amazon.com:55555")); //false
   }


   //test Domain Name
   public void testYourFirstPartition()
   {
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      //should pass
      if (urlVal.isValid("255.255.255.255") &&
         urlVal.isValid("http://www.amazon.com") &&
         urlVal.isValid("http://www.AMAZON.com") &&
         urlVal.isValid("http://www.amazon*.com") &&
         urlVal.isValid("http://www.amazon.com:80"))
      {
         System.out.println("Domain Name validator fail on correct input");
      }

      //should fail
      if (urlVal.isValid("http://www.amazon\\.com") ||
         urlVal.isValid("256.255.255.255") ||
         urlVal.isValid("http://www.amazon.com:555555"))
      {
         System.out.println("Domain Name validator fail on incorrect input");
      }

      //should pass, repeated to check any state issues
      if (urlVal.isValid("255.255.255.255") &&
         urlVal.isValid("http://www.amazon.com") &&
         urlVal.isValid("http://www.AMAZON.com") &&
         urlVal.isValid("http://www.amazon*.com") &&
         urlVal.isValid("http://www.amazon.com:80"))
      {
         System.out.println("Domain Name validator fail on correct input (second run)");
      }

	   //should fail, repeated to check state issues.
      if (urlVal.isValid("http://www.amazon\\.com") ||
         urlVal.isValid("256.255.255.255") ||
         urlVal.isValid("http://www.amazon.com:555555"))
      {
         System.out.println("Domain Name validator fail on incorrect input (second run)");
      }
   }

   //test Protocol
   public void testYourSecondPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //should pass
	   //failed test
	   if (urlVal.isValid("http://www.amazon.com") &&
   	   urlVal.isValid("https://www.amazon.com") &&
   	   urlVal.isValid("HTTPS://www.amazon.com") &&
   	   urlVal.isValid("HttpS://www.amazon.com") &&
   	   urlVal.isValid("ftp://www.amazon.com"))
   	{
   	   System.out.println("Protocol validator fail on correct input");
   	}


	   //should fail
	   // failed test
	   if (urlVal.isValid("htp://www.amazon.com") ||
   	   urlVal.isValid("ftps://www.amazon.com") ||
   	   urlVal.isValid("http//www.amazon.com") ||
   	   urlVal.isValid("http:/www.amazon.com"))
	   {
	     System.out.println("Protocol validator fail on incorrect input");
	   }

	   //should pass
	   // failed test
	   if (urlVal.isValid("http://www.amazon.com") &&
   	   urlVal.isValid("https://www.amazon.com") &&
   	   urlVal.isValid("HTTPS://www.amazon.com") &&
   	   urlVal.isValid("HttpS://www.amazon.com") &&
   	   urlVal.isValid("ftp://www.amazon.com"))
   	{
   	   System.out.println("Protocol validator fail on correct input (second run)");
   	}


	   //should fail
	   // failed test
	   if (urlVal.isValid("htp://www.amazon.com") ||
   	   urlVal.isValid("ftps://www.amazon.com") ||
   	   urlVal.isValid("http//www.amazon.com") ||
   	   urlVal.isValid("http:/www.amazon.com"))
	   {
	     System.out.println("Protocol validator fail on incorrect input (second run)");
	   }
   }

   //test Top Level Domain
   public void testYourThirdPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      //should pass
      // failed test
      if (urlVal.isValid("http://www.amazon.com") &&
         urlVal.isValid("http://www.amazon.gr") &&
         urlVal.isValid("http://www.amazon.gt") &&
         urlVal.isValid("http://www.amazon.eg") &&
         urlVal.isValid("http://www.amazon.dk") &&
         urlVal.isValid("http://www.amazon.mil") &&
         urlVal.isValid("http://www.amazon.mobi"))
      {
         System.out.println("Top Level Domain validator fail on correct input");
      }

      //should fail
      // passed test
      if (urlVal.isValid("http://www.amazon.moby") ||
         urlVal.isValid("http://www.amazon.ab") ||
         urlVal.isValid("http://www.amazon.complex") ||
         urlVal.isValid("http://www.amazon.prof"))
      {
         System.out.println("Top Level Domain validator fail on incorrect input");
      }

      //should pass
      // failed test
      if (urlVal.isValid("http://www.amazon.com") &&
         urlVal.isValid("http://www.amazon.gr") &&
         urlVal.isValid("http://www.amazon.gt") &&
         urlVal.isValid("http://www.amazon.eg") &&
         urlVal.isValid("http://www.amazon.dk") &&
         urlVal.isValid("http://www.amazon.mil") &&
         urlVal.isValid("http://www.amazon.mobi"))
      {
         System.out.println("Top Level Domain validator fail on correct input (second run)");
      }

      //should fail
      //passed test
      if (urlVal.isValid("http://www.amazon.moby") ||
         urlVal.isValid("http://www.amazon.ab") ||
         urlVal.isValid("http://www.amazon.complex") ||
         urlVal.isValid("http://www.amazon.prof"))
      {
         System.out.println("Top Level Domain validator fail on incorrect input (second run)");
      }
   }

   public void testIsValid()
   {
      //test for valid IP address
      ipAddrTest();
      //test for Valid Port
      portTest();
      //test for query
      queryTest();
      //test for scheme
      testScheme();
   }

   // Port Test: Tests valid range of port numbers
   // If working correctly, there should not be any failures.
   public void portTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String address = "amazon.com:";
	   int port = 0;
	   String combinedAdd = "";

	   // iterates from 0 ~ 65536, which are valid port numbers

	   for(int i = 0;i<=65536;i++)
	   {
		   port = i;
		 // Combines amazon.com: with valid range of port
		   combinedAdd = address + port;
		   if (!urlVal.isValidAuthority(combinedAdd))
		   {
			   System.out.println("Port number: " + i + " Failed");
		   }

	   }
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */


   // Query Test
   // Tests different correct & incorrect variations of the query portion of the URL
   // If working, there should be no failures
   public void queryTest()
   {
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      //Correct Queries
      if (urlVal.isValid("http://www.amazon.com?field=value&field1=value1")) {
         System.out.println("Test Passed");
      } else {
         System.out.println("Test Failed");
      }
      if (urlVal.isValid("http://www.amazon.com")) {
         System.out.println("Test Passed");
      } else {
         System.out.println("Test Failed");
      }

      //Incorrect Queries
      if (urlVal.isValid("http://www.amazon.com?field=value&=value1")) {
         System.out.println("Test Failed");
      } else {
         System.out.println("Test Passed");
      }
      if (urlVal.isValid("http://www.amazon.com?field=value&= value1")) {
         System.out.println("Test Failed");
      } else {
         System.out.println("Test Passed");
      }
   }

   public void ipAddrTest()
   {
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      Random ran = new Random();
      String IP_REGEX = "^(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$";

      for (int x = 0 ; x < 10000; x++) {
         RegexValidator ipValidator = new RegexValidator(IP_REGEX);
         StringBuilder sb = new StringBuilder();
         for (int i=0; i<4; i++) {
            int z = ran.nextInt(256);
            sb.append(z);
            if (i != 3) {
               sb.append(".");
            }
         }
         String ipString = sb.toString();
         System.out.println(ipString);

         String[] result = ipValidator.match(ipString);

         Boolean fail = false;
         for (int i = 0; i <= 3; i++) {
            String strSegment = result[i];
            int intSegment = 0;
            intSegment = Integer.parseInt(strSegment);
            if ( intSegment > 255) {
               fail = true;
            }
         }
         //isValidAuthority is true and Fail is true = Test failed
         //isValidAuthority is false and fail is true = test passed
         //isValid Autho    is true and fail is false = test passed
         if (urlVal.isValidAuthority(ipString) && !fail) {
            System.out.println("Test Passed");
         } else if (urlVal.isValidAuthority(ipString) == false && fail) {
            System.out.println("Test Passed!!");
         }
         else {
            System.out.println("Test Failed");
         }
      }
   }
   // just sample test of test
   public void ipAddrTest2()
   {
//	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
//	   System.out.println(urlVal.isValid("www.google.com"));
	      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	      String ipString = "200.200.200.200";
	      if (urlVal.isValidAuthority(ipString))
	      {
	    	  System.out.println("working");
	      } else
	      {
	    	  System.out.println("Not working");
	      }
   }

   // Tests for valid scheme syntax
   // uses schemePrint()
   public void testScheme()
   {
	   schemePrint("3p://www.amazon.com",1);
     schemePrint("http://www.amazon.com",0);
   }

   // something : scheme to be tested
   // Flag 0 : scheme should be true
   // Flag 1 : scheme should be false
   public void schemePrint(String something, int flag)
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   if (flag == 0)
	   {
		   if(!urlVal.isValid(something))
		   {
			   System.out.println("ERROR: " + something + " is not a valid scheme");
		   } else
		   {
			   System.out.println("good");
		   }
	   }

	   if (flag == 1)
	   {
		   if(urlVal.isValid(something))
		   {
			   System.out.println("ERROR: " + something + " should not be a valid scheme");
		   } else
		   {
			   System.out.println("good");
		   }
	   }
   }
}
