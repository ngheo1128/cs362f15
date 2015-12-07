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

   // Manual testing
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Running testManualTest():");
	   System.out.println("=========================");
	   String testURLsValid[] = {
			   //add URLs here manually to test
			   "http://www.amazon.com", //valid
			   "http://www.google.com/drive", //valid
			   "http://www.google.com/", //valid
			   "http://google.com/", //valid
			   "http://validator.w3.org/feed/check.cgi?url=http://www.google.com/", //valid
			   "http://www.googl3.com/", //valid
			   "http://wwww.google.com/ ", //valid
			   "http://ww.google.com/", //valid
			   "173.194.121.32", //valid
			   "http://www.net" //valid
	   };	
	   
	   String testURLsInvalid[] = {
			   //add URLs here to manually test
			   "http://www..net", //invalid
			   "http://www.google.com//", //invalid
			   "http://www.goog|e.com/", //invalid
			   "http://www.googl3.c0m/", //invalid
			   "http://www.google.com /drive", //invalid
			   "http://www.google.com/ drive", //invalid
			   "http://www.google.com/  drive", //invalid
			   "http://www.google.com  /drive", //invalid
			   "http://www.google.com/ drive ", //invalid
			   "http://www .google.com/drive", //invalid
			   "http://www.google .com/drive", //invalid
			   "http://www."
	   };
	   
	   System.out.println("  -Testing Valid Urls:");
	   for(int i = 0; i < testURLsValid.length; i++){
		   if(urlVal.isValid(testURLsValid[i]) == false){
			   System.out.println("    *Bug found: '" + testURLsValid[i] + "': isValid() returned false.");
		   }
		   //System.out.println("'" + testURLsValid[i] + "' || result=" + urlVal.isValid(testURLsValid[i]));
	   }
	   
	   System.out.println("  -Testing Invalid Urls:");
	   for(int i = 0; i < testURLsInvalid.length; i++){
		   if(urlVal.isValid(testURLsInvalid[i]) == true){
			   System.out.println("    *Bug found: '" + testURLsInvalid[i] + "': isValid() returned true.");
		   }
		   //System.out.println("'" + testURLsValid[i] + "' || result=" + urlVal.isValid(testURLsValid[i]));
	   }
	   System.out.println("========================");
	   System.out.println("Manual Testing Completed");
   }

   // Test ports 0-65535
   public void testPorts()
   {
	   String url;
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);
	   
	   for(int i=0; i<65536; i++)
	   {
		   url = "http://www.google.com:"+Integer.toString(i);
		   if(!urlVal.isValid(url))
		   {
			   System.out.println("TEST Failed: "+url);
		   }
		   
	   }
   }
   
   // Test queries by assembling different variations of query parameters
   public void testParams()
   {
	   String param_list[] = {"action=true", "data=somedata", "username=nayara",""};
	   String schemes[]  = {"https", "http"};
	   String domains[] = {"www.amazon", "www.google", "www.bing"};
	   String suffixes[] = {".com", ".net", ".org"};
	   String subdir[] = {"test",null};
	   String url;
	   UrlValidator urlVal = new UrlValidator(schemes);
	   
	   String scheme,domain, suffix, dir, param;
	   
	   for(int a=0; a<2; a++)
	   {
		   scheme = schemes[a];
		   for(int b=0; b<3; b++)
		   {
			   domain = domains[b];
			   for(int c=0; c<3;c++)
			   {
				   suffix = suffixes[c];
				   for(int d=0; d<2;d++)
				   {
					   
					   for(int e=0; e<4;e++)
					   {
						   param = param_list[e];
						   if(subdir[d] != null)
						   {
							   url = scheme+"://"+domain+suffix+"/"+subdir[d]+"?"+param;
						   }
						   else
						   {
							   url = scheme+"://"+domain+suffix+"?"+param;
						   }
						   if (!urlVal.isValid(url))
						   {
							   System.out.println("TEST Failed: "+url);							   
						   }	   
					   }
				   }
			   }
		   }   
	   }
	   
	   for(int a=0; a<2; a++)
	   {
		   scheme = schemes[a];
		   for(int b=0; b<3; b++)
		   {
			   domain = domains[b];
			   for(int c=0; c<3;c++)
			   {
				   suffix = suffixes[c];
				   for(int d=0; d<2;d++)
				   {
					   if(subdir[d] != null)
					   {
						   url = scheme+"://"+domain+suffix+"/"+subdir[d]+"?";
					   }
					   else
					   {
						   url = scheme+"://"+domain+suffix+"?";
					   }
					   url = url + param_list[0]+"&"+param_list[1]+"&"+param_list[2];
					   if (!urlVal.isValid(url))
					   {
						   System.out.println("TEST Failed: "+url);							   
					   }	   

				   }
			   }
		   }
	   }
	   
	   // Perform a few more manual tests
	   url = "http://www.a.com?action=true";
	   if (!urlVal.isValid(url))
	   {
		   System.out.println("TEST Failed: "+url);							   
	   }	   
	   
	   url = "http://www.google.com??";
	   if (urlVal.isValid(url))
	   {
		   System.out.println("TEST Failed: "+url);							   
	   }	   
			   
	   url = "http://www.google.com?action=true?";
	   if (urlVal.isValid(url))
	   {
		   System.out.println("TEST Failed: "+url);							   
	   }	   
	   url = "http://www.google.com?action=?";
	   
	   if (urlVal.isValid(url))
	   {
		   System.out.println("TEST Failed: "+url);							   
	   }	   
	   
    }
   
   // Check URLs by IP. Check URLs of 
   // one, two, three, four, and five octets
   public void testIPs()
   {

	   String url;
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);

	   int max_num = 300;
	   
	   System.out.println("Testing one octet...");
	   for(int a=0; a < max_num; a++)
	   {
		   url = "http://"+Integer.toString(a);
		   if(urlVal.isValid(url))
		   {
			   System.out.println("TEST Failed: "+url);
		   }
	   }
	   System.out.println("Testing two octets...");
	   for(int a=0; a < max_num; a++)
	   {
		   for(int b=0; b < max_num; b++)
		   {
			   url = "http://"+Integer.toString(a)+"."+Integer.toString(b);
			   if(urlVal.isValid(url))
			   {
				   System.out.println("TEST Failed: "+url);
			   }

		   }
	   }
	   System.out.println("Testing three octets...");
	   for(int a=0; a < max_num; a++)
	   {
		   for(int b=0; b < max_num; b++)
		   {
			   for(int c=0; c< max_num; c++)
			   {
				   url = "http://"+Integer.toString(a)+"."+Integer.toString(b) +"."+ Integer.toString(c);
				   
				   if(urlVal.isValid(url))
				   {
					   System.out.println("TEST Failed: "+url);
				   }				   
			   }
		   }
	   }
	   System.out.println("Testing four octets...");
	   for(int a=0; a < max_num; a++)
	   {
		   for(int b=0; b < max_num; b++)
		   {
			   for(int c=0; c< max_num; c++)
			   {
				   for(int d=0; d< max_num; d++)
				   {
					   url = "http://"+Integer.toString(a)+"."+Integer.toString(b) +"."+ Integer.toString(c)+"."+Integer.toString(d);
					   //System.out.println(url);
					   if (a >255 || b >255 || c>255 ||d>255)
					   {
						   //System.out.println(url);
						   if(urlVal.isValid(url))
						   {
							   System.out.println("TEST FAILED: "+ url);
						   }
					   }
					   else
					   {
						   if(!urlVal.isValid(url))
						   {
							   System.out.println("TEST FAILED"+ url);  
						   }
					   }
				   }
			   }
		   }
	   }
	   System.out.println("Testing five octets...");	   
	   for(int a=0; a < max_num; a++)
	   {
		   for(int b=0; b < max_num; b++)
		   {
			   for(int c=0; c< max_num; c++)
			   {
				   for(int d=0; d< max_num; d++)
				   {
					   for(int e=0; e< max_num; e++)
					   {
						   url = "http://"+Integer.toString(a)+"."+Integer.toString(b) + "." 
					   + Integer.toString(c)+ "." +Integer.toString(d)+"."+Integer.toString(e);
						   if(urlVal.isValid(url))
						   {
							   System.out.println("TEST FAILED"+ url);  
						   }
					   }
					   
				   }
			   }
		   }
	   }	   
   }
   

   // Test URLs made of only numbers
   public void testNumbers()
   {
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);	   
	   char[] alphabet = "1234567890".toCharArray();
	   for(int i=0; i<10;i++)
	   {
		   String url = "http://www.";
		   for(int j=0;j<i+1;j++)
		   {
			   url = url +Character.toString(alphabet[j]);
			   
		   }
		   url = url + ".com";
		   if(!urlVal.isValid(url))
		   {
			   System.out.println("TEST FAILED: "+ url);   
		   }
		   
	   }	   
   }
   
   // Test URLs made of only letters
   public void testLetters()
   {
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);	   
	   char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();
	   for(int i=0; i<26;i++)
	   {
		   String url = "http://www.";
		   for(int j=0;j<i+1;j++)
		   {
			   url = url +Character.toString(alphabet[j]);
			   
		   }
		   url = url + ".com";
		   if(!urlVal.isValid(url))
		   {
			   System.out.println("TEST FAILED: "+ url);   
		   }
		   
	   }
   }
   
   // Test URLs made of numbers and letters
   public void testNumbersAndLetters()
   {
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);	   
	   char[] alphabet = "abcdefghijklmnopqrstuvwxyz1234567890".toCharArray();
	   for(int i=0; i<36;i++)
	   {
		   String url = "http://www.";
		   for(int j=0;j<i+1;j++)
		   {
			   url = url +Character.toString(alphabet[j]);
			   
		   }
		   url = url + ".com";
		   if(!urlVal.isValid(url))
		   {
			   System.out.println("TEST FAILED: "+ url);   
		   }
		   
	   }	   
   }
   
   // Test URLs made of strange characters
   public void testOddities()
   {
	   String schemes[] = {"http", "https"};
	   UrlValidator urlVal = new UrlValidator(schemes);	   
	   char[] alphabet = "!@#$%^&*()_+".toCharArray();
	   for(int i =0; i< alphabet.length; i++)
	   {
		   String url = "http://www.";
		   for(int j=0;j<i+1;j++)
		   {
			   url = url + Character.toString(alphabet[j]);
		   }
		   url = url + ".com";
		   if(urlVal.isValid(url))
		   {
			   System.out.println("TEST FAILED: "+ url);
		   }
	   }
	   
   }
  
   public void testYourFirstPartition()
   {
	   	String[] schemes = {"action1=true","action2=false", "action1=true&action2=false"};
   }
   
   public void testYourSecondPartition()
   {
	   
	   //System.out.println("Partition 2");   
   }
   
   
   public void testIsValid()
   {
	   //System.out.println("testIsValid function");
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   //System.out.println("Other testing");
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}