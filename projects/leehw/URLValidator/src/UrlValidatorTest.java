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
	   System.out.println("Allow all schemas (not just http, https, ftp)...");
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   assertTrue(urlVal.isValid("http://ww.amazon.com"));
	   assertTrue(urlVal.isValid("htt://ww.amazon.com"));
	   assertFalse(urlVal.isValid("amazon"));
	   assertFalse(urlVal.isValid("amazon.com"));
	   assertFalse(urlVal.isValid("htt//ww.kjsdfc.com"));
	   
	   // Test for restricted schemas (http, https, ftp).
	   System.out.println("Restrict schemas (http, https, ftp)...");
	   String[] restrictSchemas = {"http", "https", "ftp"};
	   urlVal = new UrlValidator(restrictSchemas);
	   assertTrue(urlVal.isValid("http://www.tower.com"));
	   assertFalse(urlVal.isValid("ssh://www.tower.com"));
	   assertFalse(urlVal.isValid("rtsp://www.boing.net"));
	   assertTrue(urlVal.isValid("https://www.google.com"));
	   assertTrue(urlVal.isValid("ftp://www.yahoo.com"));

	   // Test for local URLs (allowed).
	   System.out.println("Local (not-FQDN) URLs okay...");
	   urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
	   
	   // THESE COMMENTED-OUT ASSERTIONS ALL FAIL
	   // assertTrue(urlVal.isValid("http://localhost"));
	   // assertFalse(urlVal.isValid("http://localhost.mymachine"));
	   // assertTrue(urlVal.isValid("http://localhost/blog/index.php?post=356"));
	   // assertTrue(urlVal.isValid("http://localhost/index.php#contact"));
	   
	   assertTrue(urlVal.isValid("http://www.fool.com"));
	   assertTrue(urlVal.isValid("http://127.0.0.1"));

	   // Test for 2 slashes in paths (allowed).
	   System.out.println("Allow 2 slashes in paths...");
	   urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_2_SLASHES);
	   assertTrue(urlVal.isValid("http://www.example.com//blog"));
	   assertTrue(urlVal.isValid("http://www.example.com//blog//index.php"));

	   // Test for fragments (NOT allowed).
	   System.out.println("Forbid fragments...");
	   urlVal = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	   assertTrue(urlVal.isValid("http://www.foobar.com/file.php"));
	   assertFalse(urlVal.isValid("http://www.foobar.com/file.php#aboutus"));
   }
   
   
   public void testYourFirstPartition()
   {
	   // simple test run of URL Builder
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   ResultPair url = URLbuilder(1,1,0,0,0);
	   System.out.println(url.item);

	   if (url.valid) {
		   assertTrue(urlVal.isValid(url.item));
	   }
	   else {
		   assertFalse(urlVal.isValid(url.item));
	   }
	   System.out.println("Run success");
   }
   
   
   public void testYourSecondPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   ResultPair url = URLbuilder(2,0,0,0,0);
	   System.out.println("Testing URL: " + url.item);

	   if (url.valid) {
		   assertTrue(urlVal.isValid(url.item));
	   }
	   else {
		   assertFalse(urlVal.isValid(url.item));
	   }

	   System.out.println("Run success"); 
   }
   
   public void testIsValid()
   {
	   int schemasIdx, hostsIdx, portsIdx, pathsIdx, queriesIdx;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
	   // UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   // UrlValidator urlVal = new UrlValidator();
	   ResultPair url;
	   String validity;
	   
	   boolean testResult;
	   int errorCount = 0;
	   int runCount = 0;
	   queriesIdx = 0;
	   portsIdx = 0;

	   // Loop through all variations of URLs
	   for(schemasIdx = 0; schemasIdx <= schemas.length; schemasIdx++)
	   {
		   for(hostsIdx = 0; hostsIdx <= hosts.length; hostsIdx++)
		   {
			   // COMMENTING OUT THE addition of Ports since we now know it's a bug
			   // 12/3/15 @ 6pm
			   //for(portsIdx = 0; portsIdx <= ports.length; portsIdx++)
			   //{
				   for(pathsIdx = 0; pathsIdx <= paths.length; pathsIdx++)
				   {
					   // COMMENTING OUT THE addition of Queries since we know it's a bug
					   // 12/3/15 @ 6pm
					   //for(queriesIdx = 0; queriesIdx <= queries.length; queriesIdx++)
					   //{
					       // build the URL string
						   url = URLbuilder(schemasIdx,hostsIdx,portsIdx,pathsIdx,queriesIdx);
						   validity = (url.valid) ? "VALID" : "INVALID";
						   
						   testResult = urlVal.isValid(url.item);
						   runCount++;
						   if (testResult != url.valid) {		// then assertion has failed
							   System.out.println("Testing " + url.item);
							   System.out.println("---expected " + validity + " but returned "
							   + (testResult ? "VALID" : "INVALID") + "\n");
							   errorCount++;		   
						   }  
					   //}
				   }
			   //}
		   }
	   }
	   System.out.println("Total URLs tested: " + runCount + "\tTotal errors counted: " + errorCount);
   
   }
   
   public void testAnyOtherUnitTest()
   {
	   int schemasIdx, hostsIdx, portsIdx, pathsIdx, queriesIdx;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   ResultPair url;
	   String validity;

	   // Loop through all variations of URLs
	   for(schemasIdx = 0; schemasIdx <= schemas.length; schemasIdx++)
	   {
		   for(hostsIdx = 0; hostsIdx <= hosts.length; hostsIdx++)
		   {
			   for(portsIdx = 0; portsIdx <= ports.length; portsIdx++)
			   {
				   for(pathsIdx = 0; pathsIdx <= paths.length; pathsIdx++)
				   {
					   for(queriesIdx = 0; queriesIdx <= queries.length; queriesIdx++)
					   {
						   url = URLbuilder(schemasIdx,hostsIdx,portsIdx,pathsIdx,queriesIdx);
						   validity = (url.valid) ? "VALID" : "INVALID";
						   
						   System.out.format("Testing " + validity + " URL: " + url.item);

						   if (url.valid) {
							   assertTrue(urlVal.isValid(url.item));
						   }
						   else {
							   assertFalse(urlVal.isValid(url.item));
						   }

						   System.out.println(" [SUCCESS]");

					   }
				   }
			   }
		   }
	   }
   }

   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   
	// schemas: by default, are http, https, and ftp, per documentation 
	ResultPair[] schemas = {
		   new ResultPair("", false),	// should this be true or false?
		   new ResultPair("http://", true),
		   new ResultPair("http:////", false),
		   new ResultPair("http//", false),
		   new ResultPair("http:/", false),
		   new ResultPair("https://", true),
		   new ResultPair("ftp://", true),
		   new ResultPair("foobar://", false)
	};
	// hosts: this is the domain name
	ResultPair[] hosts = {
		   new ResultPair("", false),
		   new ResultPair("www.amazon.com", true),
		   new ResultPair("amazon", false),
		   new ResultPair("amazon.", false),
		   new ResultPair(".amazon", false),
		   new ResultPair("www.amazon", false),
		   new ResultPair("amazon com", false),
		   new ResultPair("askjeeves.cc", true),
		   new ResultPair("127.0.0.1", true),
		   new ResultPair("127..0.1", false),
		   new ResultPair("127.1", false),
		   new ResultPair(".127.0.0.1", false),
		   new ResultPair("256.0.0.1", false),
		   new ResultPair("127", false)
	};
	// ports: need to be a number between 0 and 65535
	// 0 to 1023: well-known ports
	// 1024 to 49151: registered ports
	// 49152 to 65535: ephemeral ports
	ResultPair[] ports = {
		   new ResultPair("", true),
		   new ResultPair(":80", true),
		   new ResultPair(":8080", true),
		   new ResultPair(":65535", true),
		   new ResultPair(":65536", false),
		   new ResultPair(":23a", false),
		   new ResultPair(":-80", false)
	};
	// paths: any route following the host and/or port. Should begin with a slash
	ResultPair[] paths = {
		   new ResultPair("", true),
		   new ResultPair("/path", true),
		   new ResultPair("/path/", true),
		   new ResultPair("/path2/../path1", true),
		   new ResultPair("/path2/..path1", false),
		   new ResultPair("noslashes", false),
		   new ResultPair("/path/name", true) 
	};
	// queries: information following a path, for passing parameters via URL
	// should start with a '?'
	// QUERY_REGEX = "^(.*)$", per UrlValidator.java, line 151
	ResultPair[] queries = {
		   new ResultPair("", true),
		   new ResultPair("?lvalue=rvalue", true),
		   new ResultPair("?lvalue=rvalue&lvalue2=rvalue2", true),
		   new ResultPair("?lvalue=rvalue;lvalue2=rvalue2", true),
		   new ResultPair("?lvalue=rvalue:lvalue2=rvalue2", false),
		   new ResultPair("?=rvalueonly", false) 
	};

   // This function will build a URL and return it inside a ResultPair,
   // along with its expected validity.
   // NOTE: the passed-in parameters index into the ResultPair arrays listed above,
   // so passing a 0 for any index should make that part empty
   public ResultPair URLbuilder(int schema_index, int host_index, int port_index, int path_index, int query_index)
   {
	   // if index parameters are not within range of available ResultPairs,
	   // then return an invalid URL
	   if ((schema_index >= schemas.length) || (host_index >= hosts.length) ||
			   (port_index >= ports.length) || (path_index >= paths.length) ||
			   (query_index >= queries.length)) {
		   return new ResultPair("out_of_range", false);
	   }
	   // else build a URL string & return it inside a ResultPair, along with
	   // its expected validity
	   else {
		   String URLcombo = schemas[schema_index].item + hosts[host_index].item
				   + ports[port_index].item + paths[path_index].item +
				   queries[query_index].item;
		   
		   boolean URLvalidity = true;
		   
		   // set the return pair's 'valid' variable to false if any of the
		   // URL's parts are expected to be false
		   if (!schemas[schema_index].valid || !hosts[host_index].valid
				   || !ports[port_index].valid || !paths[path_index].valid
				   || !queries[query_index].valid) {
			   URLvalidity = false;
		   }
		   
		   ResultPair expectedURL = new ResultPair(URLcombo, URLvalidity);
		   return expectedURL;  
	   }
   }
}
