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
	   /* Credit for listing of valid / invalid URLS:
	    * https://mathiasbynens.be/demo/url-regex
	    */
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("All Should Be Valid (true)");
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/"));
	   System.out.println(urlVal.isValid("http://amazon.com"));
	   System.out.println(urlVal.isValid("http://amazon.com:80"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah/"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah_(wikipedia)"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah_(wikipedia)_(again)"));
	   System.out.println(urlVal.isValid("http://www.example.com/wpstyle/?p=364"));
	   System.out.println(urlVal.isValid("https://www.example.com/foo/?bar=baz&inga=42&quux"));	   
	   System.out.println(urlVal.isValid("http://userid:password@example.com:8080"));
	   System.out.println(urlVal.isValid("http://userid:password@example.com:8080/"));
	   System.out.println(urlVal.isValid("http://userid@example.com"));
	   System.out.println(urlVal.isValid("http://userid@example.com/"));
	   System.out.println(urlVal.isValid("http://userid@example.com:8080"));
	   System.out.println(urlVal.isValid("http://userid@example.com:8080/"));
	   System.out.println(urlVal.isValid("http://userid:password@example.com"));
	   System.out.println(urlVal.isValid("http://userid:password@example.com/"));
	   System.out.println(urlVal.isValid("http://142.42.1.1/"));
	   System.out.println(urlVal.isValid("http://142.42.1.1:8080/"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_(wikipedia)#cite-1"));
	   System.out.println(urlVal.isValid("http://foo.com/blah_(wikipedia)_blah#cite-1"));
	   System.out.println(urlVal.isValid("http://foo.com/(something)?after=parens"));
	   System.out.println(urlVal.isValid("http://code.google.com/events/#&product=browser"));
	   System.out.println(urlVal.isValid("http://j.mp"));
	   System.out.println(urlVal.isValid("ftp://foo.bar/baz"));
	   System.out.println(urlVal.isValid("http://foo.bar/?q=Test%20URL-encoded%20stuff"));
	   System.out.println(urlVal.isValid("http://-.~_!$&'()*+,;=:%40:80%2f::::::@example.com"));
	   System.out.println(urlVal.isValid("http://1337.net"));
	   System.out.println(urlVal.isValid("http://a.b-c.de"));
	   System.out.println(urlVal.isValid("http://223.255.255.254"));
   
	   System.out.println("All Should Be Invalid (false)");
	   System.out.println(urlVal.isValid("http://"));
	   System.out.println(urlVal.isValid("http://."));
	   System.out.println(urlVal.isValid("http://.."));
	   System.out.println(urlVal.isValid("http://../"));
	   System.out.println(urlVal.isValid("http://?"));
	   System.out.println(urlVal.isValid("http://??"));
	   System.out.println(urlVal.isValid("http://??/"));
	   System.out.println(urlVal.isValid("http://#"));
	   System.out.println(urlVal.isValid("http://##"));
	   System.out.println(urlVal.isValid("http://##/"));
	   System.out.println(urlVal.isValid("http://foo.bar?q=Spaces should be encoded"));
	   System.out.println(urlVal.isValid("//"));
	   System.out.println(urlVal.isValid("//a"));
	   System.out.println(urlVal.isValid("///a"));
	   System.out.println(urlVal.isValid("///"));
	   System.out.println(urlVal.isValid("http:///a"));
	   System.out.println(urlVal.isValid("foo.com"));
	   System.out.println(urlVal.isValid("rdar://1234"));
	   System.out.println(urlVal.isValid("h://test"));
	   System.out.println(urlVal.isValid("http:// shouldfail.com"));
	   System.out.println(urlVal.isValid(":// should fail"));
	   System.out.println(urlVal.isValid("http://foo.bar/foo(bar)baz quux"));
	   System.out.println(urlVal.isValid("ftps://foo.bar/"));
	   System.out.println(urlVal.isValid("http://-error-.invalid/"));
	   System.out.println(urlVal.isValid("http://a.b--c.de/"));
	   System.out.println(urlVal.isValid("http://-a.b.co"));
	   System.out.println(urlVal.isValid("http://a.b-.co"));
	   System.out.println(urlVal.isValid("http://0.0.0.0"));
	   System.out.println(urlVal.isValid("http://10.1.1.0"));
	   System.out.println(urlVal.isValid("http://10.1.1.255"));
	   System.out.println(urlVal.isValid("http://224.1.1.1"));
	   System.out.println(urlVal.isValid("http://1.1.1.1.1"));
	   System.out.println(urlVal.isValid("http://123.123.123"));
	   System.out.println(urlVal.isValid("http://3628126748"));
	   System.out.println(urlVal.isValid("http://.www.foo.bar/"));
	   System.out.println(urlVal.isValid("http://www.foo.bar./"));
	   System.out.println(urlVal.isValid("http://.www.foo.bar./"));
	   System.out.println(urlVal.isValid("http://10.1.1.1"));

	   
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
