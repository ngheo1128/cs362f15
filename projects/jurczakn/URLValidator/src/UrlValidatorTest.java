
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
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May
 *          2011) $
 */
public class UrlValidatorTest extends TestCase {

	private boolean printStatus = false;
	private boolean printIndex = false;// print index that indicates current
										// scheme,host,port,path, query test
										// were using.

	public UrlValidatorTest(String testName) {
		super(testName);
	}

	public void testManualTest() {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		System.out.println(urlVal.isValid("http://www.amazon.com"));// true
		System.out.println(urlVal.isValid("https://www.google.com"));// true
		System.out.println(urlVal.isValid("ftp://www.test.com"));// true
		System.out.println(urlVal.isValid("http://www.test.com/test.html"));// true
		System.out.println(urlVal.isValid("http://www.test.com/test.php"));// true
		System.out.println(urlVal.isValid("geo://www.test.com"));// true
		System.out.println(urlVal.isValid("http://255.255.255.255:80"));// true
		System.out.println(urlVal.isValid(null));// false
		System.out.println(urlVal.isValid(" "));// false
		System.out.println(urlVal.isValid("https://///www.google.com"));// false
		System.out.println(urlVal.isValid("http://www.jibberishdomain.sdfsfsdf"));// false
		System.out.println(urlVal.isValid("http://www.testcom"));// false
		System.out.println(urlVal.isValid("http://wwwtestcom"));// false
		System.out.println(urlVal.isValid("http://www.test."));// false
		System.out.println(urlVal.isValid("http:/www.test.com"));// false
		System.out.println(urlVal.isValid("http:www.test.com"));// false
		System.out.println(urlVal.isValid("http//www.test.com"));// false
		System.out.println(urlVal.isValid("http/www.test.com"));// false
		System.out.println(urlVal.isValid("httpwww.test.com"));// false
		System.out.println(urlVal.isValid("http://"));// false
		System.out.println(urlVal.isValid("http"));// false
		System.out.println(urlVal.isValid("moc.tset.www//:ptth"));// false
		System.out.println(urlVal.isValid("com.test.wwwhttp://"));// false
		System.out.println(urlVal.isValid("com.test.www//:http"));// false
		System.out.println(urlVal.isValid("://:65a/test1//file"));// false
		System.out.println(urlVal.isValid("3ht://www.google.com"));// false

		// FOUND BUGS, THIS SHOULD BE FALSE NOT TRUE
		System.out.println(urlVal.isValid("http://wwwtest.com"));// no . after
																	// www
		System.out.println(urlVal.isValid("htp://www.test.com"));// bad scheme
		System.out.println(urlVal.isValid("sdfsffsdfsdfs://www.test.com"));// bad
																			// scheme

		// FOUND BUGS, THIS SHOULD BE TRUE NOT FALSE
		System.out.println(urlVal.isValid("http://www.test.xxx"));// valid
																	// domain
		System.out.println(urlVal.isValid("http://www.test.zw"));// valid domain
		System.out.println(urlVal.isValid("http://www.test.je"));// valid domain
		System.out.println(urlVal.isValid("http://www.google.com:80/test1?action=view"));// ?
																							// causes
																							// error

		System.out.println(urlVal.isValid("http://www.google.com #"));// true

	}

	// url parts pools
	   final List<String> validProtocols = Arrays.asList("http://", "https://", "oid://", "proxy://", "ni://", "cvs://", "dict://", "data://", "content://", "appdata://", "ftp://");
	   final List<String> invalidProtocols = Arrays.asList("9224://", "18yolo://", "abc124://", "destination://", "fake124fake://");
	   final List<String> validSub_domain = Arrays.asList("www.", "test.", "weblog.", "websurveys.", "web0.", "mysql.", "direct.", "www2.", "homedir.");
	   final List<String> invalidSub_domain = Arrays.asList("-test.", "www$.", "w#2.", "@!#$*()+=.", "###.");
	   final List<String> validDomain_name = Arrays.asList("google", "youtube", "cinemassacre", "24hourcars", "new-url", "wsj");
	   final List<String> invalidDomain_name = Arrays.asList("9&asobn", "-qwoba", "$(*@%obnoawe", "asjobi#(@*#", "goo@gle");
	   final List<String> validTop_level_domain = Arrays.asList(".com", ".org", ".net", ".int", ".edu", ".gov", ".mil", ".arpa", ".cn", ".eu", ".mr", ".tv", ".adult", ".beer", ".foo", ".pizza", ".wang");
	   final List<String> invalidTop_level_domain = Arrays.asList(".-ja", ".%noa", ".n()se", "com#", ".los%e");
	   final List<String> validPath = Arrays.asList("/student/j/hello", "/public/final/docs");
	   final List<String> invalidPath = Arrays.asList("/fake//dir", "/end/", "/invalid/chars/h$*k");
	   final List<String> validExtension = Arrays.asList(".html", ".jpg", ".txt", ".doc", ".mp4", ".gif");
	   final List<String> invalidExtension = Arrays.asList(".jpe*g", ".d@c", ".--j");
	   final List<String> validQuery = Arrays.asList("?animal=dog", "?name=nick&age=25");
	   final List<String> invalidQuery = Arrays.asList("?novalue", "?=novariable","?varialble#=ivalid", "?value=inva@lid");
	   final List<String> validAnchor = Arrays.asList("#MYANCHOR", "#newAnchor", "#fake=2&parameters=3");
	   final List<String> invalidAnchor = Arrays.asList("#soin*^eogb", "#-(asionb", "#wjoie.bioue");
	   ArrayList<List<String>> validParts = new ArrayList<List<String>> (Arrays.asList(validProtocols, validSub_domain, validDomain_name, validTop_level_domain, validPath, validExtension, validQuery, validAnchor));
	   ArrayList<List<String>> invalidParts = new ArrayList<List<String>> (Arrays.asList(invalidProtocols, invalidSub_domain, invalidDomain_name, invalidTop_level_domain, invalidPath, invalidExtension, invalidQuery, invalidAnchor));
	   int validtests = 0;
	   int validfails = 0;
	   int invalidtests = 0;
	   int invalidpass = 0;
	   
	   
	   public String buildPartURL(String[] parts, Boolean[] valid){
		   
		   String returnUrl = "";
		   
		   Random randomValue = new Random();
		   
		   for (int i = 0; i < 8; i++){//cycle through parts
			   
			   if (parts[i] != "-1"){//check if part is used
				   
				   if (valid[i]){//check if part should use valid example
					   
					   parts[i] = validParts.get(i).get(randomValue.nextInt(validParts.get(i).size()));//add random valid part
					   
				   }
				   
				   else{
					   
					   parts[i] = invalidParts.get(i).get(randomValue.nextInt(invalidParts.get(i).size()));//add invalid random part
					   
				   }
				   
				   returnUrl+=parts[i];//add part to return url
				   
			   }
			   
			   
		   }
		   return returnUrl;//return formed url
	   }
		 
	   public void singlePartitionTest(String[] parts, int tests){
		   
		   Boolean[] valid = new Boolean[8];
		   
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   assertTrue(urlVal.isValid("http://www.google.com"));
		   
		   Random randomValue = new Random();
		   
		   String url;
		   
		   Boolean testIsValid = true;
		   
		   Arrays.fill(valid, true);
		   
		   url = buildPartURL(parts, valid);//all valid test
		   
		   validtests++;
		   
		   if(urlVal.isValid(url)){
			   
			   System.out.println("Valid test for passed");
			   
		   }
		   
		   else{
			   
			   System.out.println("Valid test for failed");
			   System.out.printf("Url used in test: %s\n", url);
			   validfails++;
			   
		   }
		   
		   for (int i = 1; i < tests; i++){
			   
			   testIsValid = true;
			   
			   for (int j = 0; j < 8; j++){
				   
				   valid[j] = (randomValue.nextInt(7) != 0);
				   
				   if (!valid[j] && parts[j] != "-1"){
					   testIsValid = false;   
				   }
			   }
			   
			   url = buildPartURL(parts, valid);
			   
			   if(urlVal.isValid(url) == testIsValid){
				   
				   System.out.println("Test # " + i + " PASSED.");
				   if(testIsValid){
					   validtests++;
					   System.out.println("Test value: " + url);
				   }
				   else{
					   
					   invalidtests++;
					   
				   }
			   }
			   
			   else{
				   
				   System.out.println("Test # " + i + " FAILED.<========");
				   if (testIsValid){
					   
					   System.out.println("Expected value: true");
					   System.out.println("Returned value: false");
					   System.out.println("Test value: " + url);
					   validtests++;
					   validfails++;
					   
				   }
				   
				   else{
					   
					   invalidtests++;
					   invalidpass++;
					   System.out.println("Expected value: false");
					   System.out.println("Returned value: true");
					   System.out.println("Test value: " + url);
					   System.out.println("Invalid parts: ");
					   for (int k = 0; k < 8; k++){   
						   if (!valid[k]){
							   
							   System.out.println("              " + parts[k]);
							   
						   }
						   
					   }
					   
				   }
				   
			   }
		   
		   }
	   }
	   
	   public void partitionTest(int tests)
	   {
		   
		   String[] parts = new String[8];
		  
		   Arrays.fill(parts, "-1"); 
		   
		   //partition 1:
		   parts[2] = "fill";
		   parts[3] = "fill";
		   
		   System.out.println("Testing Partition 1:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 2:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   
		   System.out.println("Testing Partition 2:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 3:
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   
		   System.out.println("Testing Partition 3:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 4:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   
		   System.out.println("Testing Partition 4:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 5:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   
		   System.out.println("Testing Partition 5:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 6:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   
		   System.out.println("Testing Partition 6:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 7:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   
		   System.out.println("Testing Partition 7:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 8:
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   
		   System.out.println("Testing Partition 8:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 9:
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 9:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 10:
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 10:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 11:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   
		   System.out.println("Testing Partition 11:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 12:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   
		   System.out.println("Testing Partition 12:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 13:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   
		   System.out.println("Testing Partition 13:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 14:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 14:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 15:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 15:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 16:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 16:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 17:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 17:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 18:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 18:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 19:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 19:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 20:
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 20:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 21:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 21:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 22:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 22:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 23:
		   parts[0] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 23:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 24:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   
		   System.out.println("Testing Partition 24:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 25:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 25:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 26:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 26:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 27:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[6] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 27:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 28:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[6] = "fill";
		   
		   System.out.println("Testing Partition 28:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 29:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 29:");
		   
		   singlePartitionTest(parts, tests);
		   
		   Arrays.fill(parts, "-1");
		   
		   //partition 30:
		   parts[0] = "fill";
		   parts[1] = "fill";
		   parts[2] = "fill";
		   parts[3] = "fill";
		   parts[4] = "fill";
		   parts[5] = "fill";
		   parts[6] = "fill";
		   parts[7] = "fill";
		   
		   System.out.println("Testing Partition 30:");
		   
		   singlePartitionTest(parts, tests);
		   
		   System.out.printf("Valid tests ran: %d\n", validtests);
		   System.out.printf("Valid tests failed: %d\n", validfails);
		   System.out.printf("Invalid tests ran: %d\n", invalidtests);
		   System.out.printf("Invalid tests passed: %d\n", invalidpass);
			   
		}
	   

	public void testIsValid() {
		String[] schemes = new String[] {"http://", "ftp://"};
		String[] ports = new String[] {"/", ":80/", ":443/", ":8080/"};
		String[] authorities = new String[] {"localhost", "google.com", "google.xyz", "arbitrary.website", "127.0.0.1", "oregonstate.edu"};
		String[] paths = new String[] {"", "", "foo", "foo/", "foo/bar", "foo/bar/", "foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar/foo/bar"};
		String[] queries = new String[] {"", "?", "?foo", "?foo=bar"};
		String[] fragments = new String[] {"", "#", "#test"};
		
		UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES | UrlValidator.ALLOW_LOCAL_URLS);

		for (String scheme : schemes) {
			for (String auth : authorities) {
				for (String port : ports) {
					for (String path : paths) {
						for (String query : queries) {
							for (String fragment : fragments) {
								String url = scheme + auth + port + path + query + fragment;
								if (!urlValidator.isValid(url)) {
									System.out.printf("error: %s invalid\n", url);
								}
							}
						}
					}
				}
			}
		}
	}

	public void testAnyOtherUnitTest() {
		UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
		String maximalLabelUrl = "http://";
		for (int label = 0; label < 4; label++) {
			for (int i = 0; i < 63; i++) {
				maximalLabelUrl += "x";
				String url = maximalLabelUrl + ".com";
				if (url.length() > 253) {
					System.out.println("maximal url length reached. done\n");
					label = 4;
					i = 64;
					break;
				}
				if (!urlValidator.isValid(url)) {
					System.out.printf("error: Failed on url %s\n", url);
				}
			}
			maximalLabelUrl += ".";
		}
	}

	/**
	 * Create set of tests by taking the testUrlXXX arrays and running through
	 * all possible permutations of their combinations.
	 *
	 * @param testObjects
	 *            Used to create a url.
	 */

	/*
	 * Generate random values for the scheme in 3 different parts for example
	 * http:// would be broken into three parts; (http), (:), and (//) Each of
	 * these three parts will be randomized using numbers 0-9 and random
	 * characters and symbols. Phase 1, only randomize part 1, phase 2, only
	 * randomize part 2, phase 3 only randomize part 3, phase 4, randomize all
	 * three parts.
	 */
	public void testRandomScheme() {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.google.com"));

		int count = 0;
		System.out.printf("\nTesting Random Scheme\n\n");
		System.out.printf("Phase 1 test\n");
		for (int j = 0; j < 500; j++) {
			String domain = "://www.google.com";
			String part1 = "";
			String url = "";
			Boolean valid;

			/* Generate random length for part1 for each iteration 0 - 6 */
			Random randomGenerator = new Random();
			int randomLength = randomGenerator.nextInt(6);

			for (int i = 0; i <= randomLength; i++) {
				Random randomValue = new Random();
				int randomAscii = (randomValue.nextInt(127) + 32); /* 32-126 */
				char c = (char) randomAscii;
				// System.out.println(c);
				part1 += c;
			}
			url += part1;

			url += domain;
			// System.out.println(url);

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(part1);
			} else {
				count++;
			}
		}
		System.out.printf("%d Schemes from phase 1 were invalid out of 500\n", count);

		System.out.printf("Phase 2 test\n");
		count = 0;
		for (int j = 0; j < 1000; j++) {
			String domain = "//www.google.com";
			String part2 = "";
			String url = "http";
			Boolean valid;

			Random randomPart2 = new Random();
			int randomAscii = (randomPart2.nextInt(127) + 32); /* 32-126 */
			char c = (char) randomAscii;

			url += c;
			url += domain;

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(c);
			} else {
				count++;
			}
		}
		System.out.printf("%d Schemes from phase 2 were invalid out of 1000\n", count);

		System.out.printf("Phase 3 test\n");
		count = 0;
		for (int j = 0; j < 100000; j++) {
			String domain = "www.google.com";
			String part3 = "";
			String url = "http:";
			Boolean valid;

			for (int i = 0; i < 2; i++) {
				Random randomPart3 = new Random();
				int randomSymbol = (randomPart3.nextInt(127) + 32); /* 32-126 */
				char c = (char) randomSymbol;
				part3 += c;
			}

			url += part3;
			url += domain;

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(part3);
			} else {
				count++;
			}
		}
		System.out.printf("%d Schemes from phase 3 were invalid out of 100000\n", count);

		System.out.printf("Phase 4 test\n");
		count = 0;

		for (int j = 0; j < 10000000; j++) {
			String domain = "www.google.com";
			String part1 = "";
			String part3 = "";
			String url = "";
			Boolean valid;

			/* Generate random length for part1 for each iteration 0 - 6 */
			Random randomGenerator = new Random();
			int randomLength = randomGenerator.nextInt(6);

			for (int i = 0; i <= randomLength; i++) {
				Random randomValue = new Random();
				int randomAscii = (randomValue.nextInt(127) + 32); /* 32-126 */
				char c = (char) randomAscii;
				// System.out.println(c);
				part1 += c;
			}
			url += part1;

			Random randomPart2 = new Random();
			int randomAscii = (randomPart2.nextInt(127) + 32); /* 32-126 */
			char c = (char) randomAscii;
			url += c;

			for (int i = 0; i < 2; i++) {
				Random randomPart3 = new Random();
				int randomSymbol = (randomPart3.nextInt(127) + 32); /* 32-126 */
				char s = (char) randomSymbol;
				// System.out.println(c);
				part3 += s;
			}

			url += part3;
			url += domain;
			// System.out.println(url);

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(url);
			} else {
				count++;
			}
		}
		System.out.printf("%d Schemes from phase 4 were invalid out of 10000000\n", count);
	}

	/*
	 * This test generates random values for the two separators in the url. The
	 * Separators that I am referring to are the "." in the url. For example,
	 * http://www.google.com has two "." separators.
	 */
	public void testRandomSeparator() {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.google.com"));

		int count = 0;
		System.out.printf("\nTesting Random Separators\n\n");

		for (int j = 0; j < 10000; j++) {
			String part1 = "google";
			String part2 = "com";
			String url = "http://www";
			String s1 = "";
			String s2 = "";
			Boolean valid;

			/* assign separator 1 a random value */
			Random randomValue = new Random();
			int randomAscii = (randomValue.nextInt(127) + 32); /* 32-126 */
			char c = (char) randomAscii;
			// System.out.println(c);
			s1 += c;
			url += s1;
			url += part1;

			/* assign separator 2 a random value */
			Random randomValue2 = new Random();
			int randomAscii2 = (randomValue2.nextInt(127) + 32); /* 32-126 */
			char c2 = (char) randomAscii2;
			// System.out.println(c2);
			s2 += c2;

			url += s2;
			url += part2;

			// System.out.println(url);

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(url);
			} else {
				count++;
			}
		}
		System.out.printf("%d Separtor combininations were invalid out of 10000\n", count);
	}

	/*
	 * Testing random values for path character and content. For example
	 * "http://www.google.com/path", the "/" after .com with be replaced with
	 * randomly generated characters along with the value for where "path" is.
	 */
	public void testRandomPath() {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.google.com"));

		int count = 0;
		System.out.printf("\nTesting Random Path\n\n");

		for (int j = 0; j < 10000; j++) {
			String url = "http://www.google.com";
			String pathSign = "";
			String path = "";
			Boolean valid;

			/* assign pathSign a random value */
			Random randomValue = new Random();
			int randomAscii = (randomValue.nextInt(127) + 32); /* 32-126 */
			char c = (char) randomAscii;
			// System.out.println(c);
			pathSign += c;
			url += pathSign;

			/* Generate random length for part1 for each iteration 0 - 6 */
			Random randomGenerator = new Random();
			int randomLength = randomGenerator.nextInt(6);

			for (int i = 0; i <= randomLength; i++) {
				Random randomValue2 = new Random();
				int randomAscii2 = (randomValue2.nextInt(127) + 32); /* 32-126 */
				char c2 = (char) randomAscii2;
				// System.out.println(c);
				path += c2;
			}
			url += path;

			// System.out.println(url);

			valid = urlVal.isValid(url);

			if (valid == true) {
				System.out.println(url);
			} else {
				count++;
			}
		}
		System.out.printf("%d Path combininations were invalid out of 10000\n", count);
	}
	
	public static void main(String[] args) {
		UrlValidatorTest test = new UrlValidatorTest("test");
		test.testManualTest();
		test.partitionTest(10);
		test.testRandomScheme();
		test.testRandomSeparator();
		test.testRandomPath();
		test.testIsValid();
		test.testAnyOtherUnitTest();
	}

}
