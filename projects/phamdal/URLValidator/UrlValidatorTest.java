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

   public void manualHelper(boolean expected, UrlValidator urlVal, String testURL) {
	   boolean result = urlVal.isValid(testURL); 
	   System.out.println("Expected: " + expected + " Returned: " + result);
	   if(expected != result) {
		   System.out.println("Failed Test: " + testURL); 
	   }
   }
   
   public void testManualTest()
   {
	   System.out.println("----------------- manual testing URL's ------------------------------ \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   /*add expected vs returned print line*/
	   /* attempt valid URLs */
	   manualHelper(true, urlVal, "http://www.amazon.com"); 
	   manualHelper(true, urlVal,  "http://www.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.org"); 
	   manualHelper(true, urlVal, "http://tech.yahoo.com/rc/desktops/102;_ylt=Ao8yevQHlZ4On0O3ZJGXLEQFLZA5");
	   manualHelper(true, urlVal,  "http://somewhere.com/pathxyz/file(1).html"); 
	   manualHelper(true, urlVal, "http://www.apache.org/test/index.html"); 	   
	   manualHelper(true, urlVal, "file:///C:/some.file"); 
	   manualHelper(true, urlVal, "file:///etc/hosts"); 
	   /* Bug */
	   manualHelper(true, urlVal, "http://www.google.com:80/test1?action=view"); 
	   /* Bug */
	   manualHelper(true, urlVal, "ftp://www.google.com:80/test1?action=view");
	  
	   /*attempt invalid URLs */
	   manualHelper(false, urlVal, "://www.google.com:80/test1?action=view"); 
	   manualHelper(false, urlVal, "http://##/");
	   manualHelper(false, urlVal, "file://C:/some.file"); 
	   manualHelper(false, urlVal, "file://C:\\some.file"); 
	   manualHelper(false, urlVal, "file:///C:\\some.file");
	   manualHelper(false, urlVal, "http://broke.my-test/test/index.html"); 
	   manualHelper(false, urlVal, "example.com"); 
	   manualHelper(false, urlVal, "example.c");
   };
   
   
   /*domain partition, all values should be false, at least one object will be false*/
   /*we iterate over the length of each false object array pairing it with true members 
    * from each other object array to build URL's.  We uncover all edge cases by 
    * using a for loop for each object array.  We partition the false values only 
    * into that array, then concat the string url with TRUE values and assert that 
    * the url as a whole is still false.  The multiple for loops are necessary because
    * we pair each false result pair object with all true objects and assert that it is
    * still false, this way fault localization becomes easer as we will have better
    * specificity for assertion failures*/
   public void testYourFirstPartition()
   {
	   System.out.println("----------------- testing invalid URL's ------------------------------ \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   /*defensive assertions prior to test runs*/
	   assertFalse(urlVal.isValid("http:/www.google.com"));
	   assertFalse(urlVal.isValid("http:/www.google.com/"));
	   int i = 0;
	   int j = 0;
	   int e = 0;
	   int x = 0;
	   int y = 0;
	   //for loop iterators, 
	   int index = 0; //init to zero for loop counter
	   StringBuffer buffer = new StringBuffer();
	   /*get the result pair for the index in the for loops*/
	   
	   /*scheme is false component*/
	   
	   ResultPair[] part1 = (ResultPair[]) testUrlPartsfalse[0];
	   for(i = 0; i < part1.length; i++)
	   {
		   buffer.append(part1[i].item);
		   for(int z = 0; z < 100; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[1];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[2];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*Authority is false component*/
	   part1 = (ResultPair[]) testUrlPartsfalse[1];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 100; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[2];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[4];
			   buffer.append(part2[j].item);
			   buffer.append(part1[i].item);//append here since second component
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*port is false*/
	   part1 = (ResultPair[]) testUrlPartsfalse[2];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 100; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part1[i].item);//append here since third component
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*path is false*/
	   part1 = (ResultPair[]) testUrlPartsfalse[3];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 100; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[2];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part1[i].item);//append here since fourth component
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*query is false*/
	   /*part1 = (ResultPair[]) testUrlPartsfalse[4];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 100; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[2];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[3];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   buffer.append(part1[i].item);//append here since fifth componenet
			   if(j < part2.length - 2)
			   {/*increse index here, prevent out of bounds array access*//*
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   //System.out.println(buffer);
			   assertFalse("Should be invalid: " + buffer,  urlVal.isValid(buffer.toString())); 
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   */
   }  
	   
	   /*domain partition, all true, all values should evaluate to true, all objects in each URL will be true*/
   /*only one for loop needed since we aren't switching between true and false components, they're all 
    * true so we just use the longest object array, iterate over all of it's indices and then concat with 
    * the components in the other object arrays: there will be repeats but that's irrelevant to our 
    * test case.  All boundary cases will be uncovered with this*/
   public void testYourSecondPartition(){
	   System.out.println("----------------- testing valid URL's ------------------------------ \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/"));
	   int i = 0;
	   int j = 0;
	   int e = 0;
	   int x = 0;
	   int y = 0;
			    //for loop iterators, 
	   int index = 0; //init to zero for loop counter
	   StringBuffer buffer = new StringBuffer();
	   
	   ResultPair[] part1 = (ResultPair[]) testUrlPartstrue[3]; //port, longest object array to ensure all combos
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 100; z++)//longest true array
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlPartstrue[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlPartstrue[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlPartstrue[2];
			   ResultPair[]part5 = (ResultPair[]) testUrlPartstrue[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part1[i].item);//append here since fourth componenet
			   buffer.append(part5[y].item);
			   
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
   }
   
   
   public void testIsValid()
   {
	   System.out.println("----------------- testing mixed URL's ------------------------------ \n");
	   int i = 0;
	   int j = 0;
	   int e = 0;
	   int x = 0;
	   int y = 0;
			    //for loop iterators, 
	   int index = 0; //init to zero for loop counter
	   StringBuffer buffer = new StringBuffer();
	   /*get the result pair for the index in the for loops*/
	   /*Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};*/
	   /*scheme is first component*/
	   
	   ResultPair[] part1 = (ResultPair[]) testUrlParts[0];
	   for(i = 0; i < part1.length; i++)
	   {
		   buffer.append(part1[i].item);
		   for(int z = 0; z < 200; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlParts[1];
			   ResultPair[]part3 = (ResultPair[]) testUrlParts[2];
			   ResultPair[]part4 = (ResultPair[]) testUrlParts[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlParts[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*Authority is second component*/
	   part1 = (ResultPair[]) testUrlParts[1];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 200; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlParts[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlParts[2];
			   ResultPair[]part4 = (ResultPair[]) testUrlParts[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlParts[4];
			   buffer.append(part2[j].item);
			   buffer.append(part1[i].item);//append here since second component
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*port is third*/
	   part1 = (ResultPair[]) testUrlParts[2];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 200; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlParts[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlParts[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlParts[3];
			   ResultPair[]part5 = (ResultPair[]) testUrlParts[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part1[i].item);//append here since third component
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*path is fourth*/
	   part1 = (ResultPair[]) testUrlParts[3];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 200; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlParts[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlParts[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlParts[2];
			   ResultPair[]part5 = (ResultPair[]) testUrlParts[4];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part1[i].item);//append here since fourth component
			   buffer.append(part5[y].item);
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
	   }
	   /*query is fifth*/
	   part1 = (ResultPair[]) testUrlParts[4];
	   for(i = 0; i < part1.length; i++)
	   {
		   
		   for(int z = 0; z < 200; z++)
		   {
			   ResultPair[]part2 = (ResultPair[]) testUrlParts[0];
			   ResultPair[]part3 = (ResultPair[]) testUrlParts[1];
			   ResultPair[]part4 = (ResultPair[]) testUrlParts[2];
			   ResultPair[]part5 = (ResultPair[]) testUrlParts[3];
			   buffer.append(part2[j].item);
			   buffer.append(part3[e].item);
			   buffer.append(part4[x].item);
			   buffer.append(part5[y].item);
			   buffer.append(part1[i].item);//append here since fifth component
			   if(j < part2.length - 2)
			   {/*increase index here, prevent out of bounds array access*/
				   j++;
			   }
			   else{
				   j = 0;
			   }
			   if(e < part3.length - 2)
			   {
				   e++;
			   }
			   else{
				   e = 0;
			   }
			   if(x < part4.length - 2)
			   {
				   x++;
			   }
			   else{
				   x = 0;
			   }
			   if(y < part5.length - 2)
			   {
				   y++;
			   }
			   else{
				   y = 0;
			   }
			   System.out.println(buffer);
			   buffer.delete(0,  buffer.length());
		   }
		   j = 0;
		   e = 0;
		   x = 0;
		   y = 0;
		  
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
   /*create object arrays partitioned to be all false and all true for 
    * domain partitioning*/
   ResultPair[] testUrlSchemefalse = {new ResultPair("3ht://", false),
       	new ResultPair("http:/", false),
       	new ResultPair("http:", false),
       	new ResultPair("http/", false)
   };
   ResultPair[] testUrlSchemetrue = {
		   new ResultPair("http://", true),
           new ResultPair("ftp://", true),
           new ResultPair("h3t://", true),
           new ResultPair("", true)
   };
   
   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
           new ResultPair("ftp://", true),
           new ResultPair("h3t://", true),
           new ResultPair("3ht://", false),
           new ResultPair("http:/", false),
           new ResultPair("http:", false),
           new ResultPair("http/", false),
           new ResultPair("://", false),
           new ResultPair("", true)
           };
   
   ResultPair[] testUrlAuthorityfalse = {new ResultPair("256.256.256.256", false),
		   new ResultPair("1.2.3.4.5", false),
           new ResultPair("1.2.3.4.", false),
           new ResultPair("1.2.3", false),
           new ResultPair(".1.2.3.4", false),
           new ResultPair("go.a", false),
           new ResultPair("go.a1a", false),
           new ResultPair("go.1aa", false),
           new ResultPair("aaa.", false),
           new ResultPair(".aaa", false),
           new ResultPair("aaa", false),
           new ResultPair("", false)
		   
   };
   ResultPair[] testUrlAuthoritytrue = {new ResultPair("www.google.com", true),
           new ResultPair("go.com", true),
           new ResultPair("go.au", true),
           new ResultPair("0.0.0.0", true),
           new ResultPair("255.255.255.255", true),
           new ResultPair("255.com", true),
           new ResultPair("go.cc", true)
		   
   };
   
   ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
              new ResultPair("go.com", true),
              new ResultPair("go.au", true),
              new ResultPair("0.0.0.0", true),
              new ResultPair("255.255.255.255", true),
              new ResultPair("256.256.256.256", false),
              new ResultPair("255.com", true),
              new ResultPair("1.2.3.4.5", false),
              new ResultPair("1.2.3.4.", false),
              new ResultPair("1.2.3", false),
              new ResultPair(".1.2.3.4", false),
              new ResultPair("go.a", false),
              new ResultPair("go.a1a", false),
              new ResultPair("go.cc", true),
              new ResultPair("go.1aa", false),
              new ResultPair("aaa.", false),
              new ResultPair(".aaa", false),
              new ResultPair("aaa", false),
              new ResultPair("", false)
   };
   
   ResultPair[] testUrlPortfalse = {
		   new ResultPair(":-1", false),
		   new ResultPair(":65a", false)
   };
   
   ResultPair[] testUrlPorttrue = {new ResultPair(":80", true),
       new ResultPair(":65535", true),
       new ResultPair(":0", true),
       new ResultPair("", true),
       new ResultPair(":65636", true)
   };
   
   
   
   ResultPair[] testUrlPort = {new ResultPair(":80", true),
         new ResultPair(":65535", true),
         new ResultPair(":0", true),
         new ResultPair("", true),
         new ResultPair(":-1", false),
         new ResultPair(":65636", true),
         new ResultPair(":65a", false)
   };
   
   ResultPair[] testPathfalse = {new ResultPair("/..", false),
		 new ResultPair("/../", false),
		 new ResultPair("/..//file", false),
	     new ResultPair("/test1//file", false)
   };
   
   ResultPair[] testPathtrue= {new ResultPair("/test1", true),
		 new ResultPair("/t123", true),
		 new ResultPair("/$23", true),
		 new ResultPair("/test1/", true),
	     new ResultPair("", true),
	     new ResultPair("/test1/file", true)
   };

   ResultPair[] testPath = {new ResultPair("/test1", true),
      new ResultPair("/t123", true),
      new ResultPair("/$23", true),
      new ResultPair("/..", false),
      new ResultPair("/../", false),
      new ResultPair("/test1/", true),
      new ResultPair("", true),
      new ResultPair("/..//file", false),
      new ResultPair("/test1//file", false),
      new ResultPair("/test1/file", true)
   };
   
//Test allow2slash, noFragment
ResultPair[] testUrlPathOptionsfalse = {new ResultPair("/..", false),
        new ResultPair("/../", false),
        new ResultPair("/#", false),
        new ResultPair("/../file", false),
        new ResultPair("/..//file", false),
        new ResultPair("/#/file", false)
   };
ResultPair[] testUrlPathOptionstrue= {new ResultPair("/test1", true),
        new ResultPair("/t123", true),
        new ResultPair("/$23", true),
        new ResultPair("/test1/", true),
        new ResultPair("", true),
        new ResultPair("/test1/file", true),
        new ResultPair("/t123/file", true),
        new ResultPair("/$23/file", true),
        new ResultPair("/test1//file", true) 
};

   ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
                new ResultPair("/t123", true),
                new ResultPair("/$23", true),
                new ResultPair("/..", false),
                new ResultPair("/../", false),
                new ResultPair("/test1/", true),
                new ResultPair("/#", false),
                new ResultPair("", true),
                new ResultPair("/test1/file", true),
                new ResultPair("/t123/file", true),
                new ResultPair("/$23/file", true),
                new ResultPair("/../file", false),
                new ResultPair("/..//file", false),
                new ResultPair("/test1//file", true),
                new ResultPair("/#/file", false)
   };

   /*ResultPair[] testUrlQueryfalse = {new ResultPair("&", false),
	          new ResultPair("!", false),
	   };
	*/
   ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
          new ResultPair("?action=edit&mode=up", true),
          new ResultPair("", true)
   };
   /*no false query test because itll just return */
   Object[] testUrlPartstrue = {testUrlSchemetrue, testUrlAuthoritytrue, testUrlPorttrue, testPathtrue, testUrlQuery};
   Object[] testUrlPartsfalse = {testUrlSchemefalse, testUrlAuthorityfalse, testUrlPortfalse, testPathfalse};
   Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
   Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
   int[] testPartsIndex = {0, 0, 0, 0, 0};

}
