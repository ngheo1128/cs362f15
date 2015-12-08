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


public class UrlValidatorTest extends TestCase {

	public UrlValidatorTest(String testName) {
		super(testName);
	}

	public void testIsValid()
	{

		String[] scheme = {"http://", 
				"http:/", 
				"http:",
                                "http/",
                               	""};

   		String[] authority = {"www.google.com",
				"google.com",
                          	"google.se",
                          	"0.0.0.0"};

		String[] port = {":99",
                          	":9999",
                          	":-1",
			  	":test"};

		String[] path = {"/page1",
                          	"/..",
                          	"/../",
                          	"/..//page"};

		String[] query = {"?test=hello",
                              	"?test=hello&test2=hi",
                              	""};

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(validator.isValid("http://www.google.com"));

		for(int a = 0 ; i < scheme.length ; a++){
			for(int b = 0 ; b < authority.length ; b++){
				for(int c = 0 ; c < port.length ; c++){
					for(int d = 0 ; d < path.length ; d++){
						for(int e = 0 ; e < query.length ; e++){
							String testURL = scheme[a] + 
									authority[b] +
									port[c] +
									path[d] +
									query[e];
							System.out.println("Testing: " + testURL +
								" " + validator.isValid(testURL));
						}
					}
				}
			}
		}


	}

	public static void main(String[] argv) {
		UrlValidatorTest fct = new UrlValidatorTest("url test");
      		fct.setUp();
      		fct.testIsValid();
	}
   

}
