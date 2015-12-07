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


import java.util.Random;

import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   private static int PROTOCOL_NUM=9;
   private static String[] protocol = new String[] {
		   "http://",	//valid
		   "h3t://",	//valid
		   "3hc://",	//invalid
		   "https://",	//valid
		   "ftp://",	//valid
		   "http:/",	//invalid
		   "http:",		//invalid
		   "",			//valid
		   "://"		//invalid
   };
   private boolean[] protocolValidity = new boolean[] {
		   true,true,false,true,true,false,false,true,false
   };
   
   private static int HOSTNAME_NUM=10;
   private static String[] hostname = new String[] {
		   "hulahoop.edu",		//valid
		   "www.gusto.com",		//valid
		   "ew_fd.au",			//invalid
		   "fs:.ru",			//invalid
		   "Puffle&W.com",		//invalid
		   "0.0.0.0",			//valid
		   "255.255.255.255",	//valid
		   "256.256.256.256",	//invalid
		   "500.500.500.500",	//invalid
		   "1000.1000.1000.1000"	//invalid
   };
   private boolean[] hostnameValidity = new boolean[] {
		   true,true,false,false,false,true,true,false,false,false
   };
   
   private static int PORT_NUM=6;
   private static String[] port = new String[] {
		   ":80",		//valid
		   ":65535",	//valid
		   ":65536",	//invalid
		   "",			//valid
		   ":-1",		//invalid
		   ":16v"		//invalid
   };
   private boolean[] portValidity = new boolean[] {
		   true,true,false,true,false,false
   };
   
   private static int PATH_NUM=10;
   private static String[] path = new String[] {
		   "",			//valid
		   "/test",		//valid
		   "/test123",	//valid
		   "$123",		//valid
		   "/test/test",//valid
		   "/#",		//invalid
		   "//",		//invalid
		   "/test//",	//invalid
		   "/test/#",	//invalid
		   "/123"		//invalid
   };
   private boolean[] pathValidity = new boolean[] {
		   true,true,true,true,true,
		   false,false,false,false,false
   };
   
   private static int QUERY_NUM=4;
   private static String[] query=new String[] {
		   "?qid=21",		//valid
		   "?action=edit",	//valid
		   "?action=edit&mode=up", //valid
		   "?1122341"		//invalid
   };
   private static boolean[] queryValidity=new boolean[]{
		   true,true,true,false
   };
   
   public UrlValidatorTest(String testName) {
      super(testName);

   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   assert(urlVal.isValid("http://www.amazon.com"));
	   
	   testIsValid(urlVal);
   }
   
   
   public void testYourFirstPartition(UrlValidator urlVal)
   {
	   
	   //TEST ALL VALID PROTOCOLS
	   //http:// already tested in assertion statement.
	   //test https://
	   if(urlVal.isValid("https://www.amazon.com"))System.out.println("PASS: Correctly recognized valid https:// protocol.");
	   else System.out.println("FAIL: https:// protocol registering as invalid.");
	   
	   //test ftp://
	   if(urlVal.isValid("ftp://www.amazon.com"))System.out.println("PASS: Correctly recognized valid ftp:// protocol.");
	   else System.out.println("FAIL: ftp:// protocol registering as invalid.");
	   
	   //test blank protocol
	   if(urlVal.isValid("www.amazon.com"))System.out.println("PASS: No protocol required in order to output valid result.");
	   else System.out.println("FAIL: Invalid address returned if no protocol specified.");
	   
	   //test h3t://
	   if(urlVal.isValid("h3t://www.amazon.com"))System.out.println("PASS: Correctly recognized valid h3t:// protocol.");
	   else System.out.println("FAIL: h3t:// protocol registering as invalid.");
	   
	   //TEST ALL INVALID PROTOCOLS
	   //test 3ht://
	   if(!urlVal.isValid("3ht://www.amazon.com"))System.out.println("PASS: 3ht:// registering as invalid protocol.");
	   else System.out.println("FAIL: 3ht:// registering as valid protocol.");	   
	   
	   //test http:/
	   if(!urlVal.isValid("http:/www.amazon.com"))System.out.println("PASS: http:/ registering as invalid protocol.");
	   else System.out.println("FAIL: http:/ registering as valid protocol.");
	   
	   //test http:
	   if(!urlVal.isValid("http:www.amazon.com"))System.out.println("PASS: http: registering as invalid protocol.");
	   else System.out.println("FAIL: http: registering as valid protocol.");	   
	   
	   //test :// protocol
	   if(!urlVal.isValid("://www.amazon.com"))System.out.println("PASS: :// registered as invalid protocol.");
	   else System.out.println("FAIL: :// registering as valid protocol.");
   }
   
   public void testYourSecondPartition(UrlValidator urlVal){
	   //TEST VALID HOSTS
	   //hulahoop.edu
	   if(urlVal.isValid("http://hulahoop.edu")) System.out.println("PASS: hulahoop.edu registering as valid host.");
	   else System.out.println("FAIL: hulahoop.edu registering as invalid host.");
	   
	   //www.gusto.com
	   if(urlVal.isValid("http://www.gusto.com"))System.out.println("PASS: www.gusto.com registering as valid host.");
	   else System.out.println("FAIL: www.gusto.com registering as invalid host.");
	   
	   //0.0.0.0
	   if(urlVal.isValid("http://0.0.0.0"))System.out.println("PASS: 0.0.0.0 registering as valid host.");
	   else System.out.println("FAIL: 0.0.0.0 registering as invalid host.");
	   
	   //255.255.255.255
	   if(urlVal.isValid("http://255.255.255.255"))System.out.println("PASS: 255.255.255.255 registering as valid host.");
	   else System.out.println("FAIL: 255.255.255.255 registering as invalid host.");
   
	   //TEST INVALID HOSTS
	   //256.256.256.256
	   if(!urlVal.isValid("http://256.256.256.256"))System.out.println("PASS: 256.256.256.256 registering as invalid host.");
	   else System.out.println("FAIL: 256.256.256.256 registering as valid host.");
	   
	   //ew_fd.au
	   if(!urlVal.isValid("http://ew_fd.au"))System.out.println("PASS: ew_fd.au registering as invalid host");
	   else System.out.println("FAIL: ew_fd.au registering as valid host.");
	   
	   //fs:.ru
	   if(!urlVal.isValid("http://fs:.ru"))System.out.println("PASS: fs:.ru registering as invalid host");
	   else System.out.println("FAIL: fs:.ru registering as valid host.");
	   
	   //Puffle&W.com
	   if(!urlVal.isValid("http://Puffle&W.com"))System.out.println("PASS: Puffle&W.com registering as invalid host");
	   else System.out.println("FAIL: Puffle&W.com registering as valid host.");
   }
   
   
   public void testIsValid(UrlValidator urlVal)
   {
	   Random rng=new Random();
	   int randSelected=0;
	   String test_address;
	   boolean currentFalse;
	   
	   System.out.println("UNIT TESTING: PROTOCOL");
	   testYourFirstPartition(urlVal);
	   
	   System.out.println("UNIT TESTING: HOST");
	   testYourSecondPartition(urlVal);
	   
	   testAnyOtherUnitTest(urlVal);
	   
	   //RANDOM TESTING: Protocol+Host
	   System.out.println("\nCOMMENCE RANDOM TESTING:");
	   for(int i = 0;i<100;i++)
	   {
		   currentFalse=false;
		   test_address="";
		   
		   randSelected = Math.abs(rng.nextInt() % PROTOCOL_NUM);
		   test_address+=protocol[randSelected];
		   if(!protocolValidity[randSelected])
			   currentFalse=true;
		   
		   randSelected = Math.abs(rng.nextInt() % HOSTNAME_NUM);
		   test_address+=hostname[randSelected];
		   if(!hostnameValidity[randSelected])
			   currentFalse=true;
		   
		   if(currentFalse == urlVal.isValid(test_address))
			   System.out.println("FAIL: "+test_address+" solving as "+currentFalse);
	   }
	   
	   //RANDOM TESTING: Protocol+Host+Port
	   for(int i=0;i<100;i++){
		   currentFalse=false;
		   test_address="";
		   
		   randSelected = Math.abs(rng.nextInt() % PROTOCOL_NUM);
		   test_address+=protocol[randSelected];
		   if(!protocolValidity[randSelected])
			   currentFalse=true;
		   
		   randSelected = Math.abs(rng.nextInt() % HOSTNAME_NUM);
		   test_address+=hostname[randSelected];
		   if(!hostnameValidity[randSelected])
			   currentFalse=true;		   
		   
		   randSelected = Math.abs(rng.nextInt() % PORT_NUM);
		   test_address+=port[randSelected];
		   if(!portValidity[randSelected])
			   currentFalse=true;
		   
		   if(currentFalse == urlVal.isValid(test_address))
			   System.out.println("FAIL: "+test_address+" solving as "+currentFalse);
	   }
	   
	 //RANDOM TESTING: Protocol+Host+Port+Path
	   for(int i=0;i<100;i++){
		   currentFalse=false;
		   test_address="";
		   
		   randSelected = Math.abs(rng.nextInt() % PROTOCOL_NUM);
		   test_address+=protocol[randSelected];
		   if(!protocolValidity[randSelected])
			   currentFalse=true;
		   
		   randSelected = Math.abs(rng.nextInt() % HOSTNAME_NUM);
		   test_address+=hostname[randSelected];
		   if(!hostnameValidity[randSelected])
			   currentFalse=true;		   
		   
		   randSelected = Math.abs(rng.nextInt() % PORT_NUM);
		   test_address+=port[randSelected];
		   if(!portValidity[randSelected])
			   currentFalse=true;
	
		   randSelected = Math.abs(rng.nextInt() % PATH_NUM);
		   test_address+=path[randSelected];
		   if(!pathValidity[randSelected])
			   currentFalse=true;		   
		   
		   if(currentFalse == urlVal.isValid(test_address))
			   System.out.println("FAIL: "+test_address+" solving as "+currentFalse);
	   }
	   
	   //RANDOM TESTING: Protocol+Host+Port+Path+Query
	   for(int i=0;i<100;i++){
		   currentFalse=false;
		   test_address="";
		   
		   randSelected = Math.abs(rng.nextInt() % PROTOCOL_NUM);
		   test_address+=protocol[randSelected];
		   if(!protocolValidity[randSelected])
			   currentFalse=true;
		   
		   randSelected = Math.abs(rng.nextInt() % HOSTNAME_NUM);
		   test_address+=hostname[randSelected];
		   if(!hostnameValidity[randSelected])
			   currentFalse=true;		   
		   
		   randSelected = Math.abs(rng.nextInt() % PORT_NUM);
		   test_address+=port[randSelected];
		   if(!portValidity[randSelected])
			   currentFalse=true;
	
		   randSelected = Math.abs(rng.nextInt() % PATH_NUM);
		   test_address+=path[randSelected];
		   if(!pathValidity[randSelected])
			   currentFalse=true;		   
		   
		   randSelected = Math.abs(rng.nextInt() % QUERY_NUM);
		   test_address+=query[randSelected];
		   if(!queryValidity[randSelected])
			   currentFalse=true;		   
		   
		   if(currentFalse == urlVal.isValid(test_address))
			   System.out.println("FAIL: "+test_address+" solving as "+currentFalse);
	   }
   }
   
   public void testAnyOtherUnitTest(UrlValidator urlVal)
   {
	   //PORT TESTING
	   System.out.println("UNIT TESTING: PORTS");
	   //TEST VALID PORTS
	   //Correct result on blank port field already shown during assertion
	   //:80
	   if(urlVal.isValid("http://www.amazon.com:80"))System.out.println("PASS: :80 recognized as valid port.");
	   else System.out.println("FAIL: :80 not recognized as valid port.");
	   //:65535
	   if(urlVal.isValid("http://www.amazon.com:65535"))System.out.println("PASS: :65535 recognized as valid port.");
	   else System.out.println("FAIL: :65535 not recognized as valid port.");	   
	   //:65536
	   if(!urlVal.isValid("http://www.amazon.com:65536"))System.out.println("PASS: :65536 recognized as invalid port.");
	   else System.out.println("FAIL: :65536 not recognized as invalid port.");
	   //:-1
	   if(!urlVal.isValid("http://www.amazon.com:-1"))System.out.println("PASS: :-1 recognized as invalid port.");
	   else System.out.println("FAIL: :-1 not recognized as invalid port.");
	   //:16v
	   if(!urlVal.isValid("http://www.amazon.com:16v"))System.out.println("PASS: :16v recognized as invalid port.");
	   else System.out.println("FAIL: :16v not recognized as invalid port.");
	  
	  //PATH TESTING
	  System.out.println("UNT TESTING: PATHS");
	  //TEST VALID PATHS
	  // /test
	  if(urlVal.isValid("http://www.amazon.com/test"))System.out.println("PASS: /test recognized as valid path.");
	  else System.out.println("FAIL: /test not recognized as valid path.");
	  // /test/test
	  if(urlVal.isValid("http://www.amazon.com/test/test"))System.out.println("PASS: /test/test recognized as valid path.");
	  else System.out.println("FAIL: /test/test not recognized as valid path.");
	  // /test123
	  if(urlVal.isValid("http://www.amazon.com/test123"))System.out.println("PASS: /test123 recognized as valid path.");
	  else System.out.println("FAIL: /test123 not recognized as valid path.");
	  // /$est3
	  if(urlVal.isValid("http://www.amazon.com/$est3"))System.out.println("PASS: /$est3 recognized as valid path.");
	  else System.out.println("FAIL: /$est3 not recognized as valid path.");
	  //TEST INVALID PATHS
	  // /..
	  if(!urlVal.isValid("http://www.amazon.com/.."))System.out.println("PASS: /.. recognized as invalid path.");
	  else System.out.println("FAIL: /.. not recognized as invalid path.");
	  // /../
	  if(!urlVal.isValid("http://www.amazon.com/../"))System.out.println("PASS: /../ recognized as invalid path.");
	  else System.out.println("FAIL: /../ not recognized as invalid path.");
	  // /../files
	  if(!urlVal.isValid("http://www.amazon.com/../files"))System.out.println("PASS: /../files recognized as invalid path.");
	  else System.out.println("FAIL: /../files not recognized as invalid path.");
	  // /#/
	  if(!urlVal.isValid("http://www.amazon.com/#/"))System.out.println("PASS: /#/ recognized as invalid path.");
	  else System.out.println("FAIL: /#/ not recognized as invalid path.");
	  // /..
	  if(!urlVal.isValid("http://www.amazon.com/#/file"))System.out.println("PASS: /#/file recognized as invalid path.");
	  else System.out.println("FAIL: /#/file not recognized as invalid path.");
	  // //
	  if(!urlVal.isValid("http://www.amazon.com//"))System.out.println("PASS: // recognized as invalid path.");
	  else System.out.println("FAIL: // not recognized as invalid path.");
	  
	  //QUERY TESTING
	  //?action=view
	  if(urlVal.isValid("http://www.amazon.com?action=view"))System.out.println("PASS: ?action=view recognized as valid query.");
	  else System.out.println("FAIL: ?action=view not recognized as valid query.");
	  if(urlVal.isValid("http://www.amazon.com?qid=201"))System.out.println("PASS: ?qid=201 recognized as valid query.");
	  else System.out.println("FAIL: ?qid=201 not recognized as valid query.");
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
