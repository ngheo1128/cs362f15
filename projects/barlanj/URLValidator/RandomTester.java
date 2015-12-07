/*
 * Random tester for UrlValidator isValid()
 * This implementation generates random URLs from a set of partition domain.
 * This also generates random ports between 0 and 655535 using getRandomPort()
 * method, which half the time will invalidate this port number by adding
 * a random character inside the string representation of the port number.
 * For detail see getRandomPort.
 */


import java.util.Random;

import junit.framework.TestCase;

public class RandomTester extends TestCase  {

	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);
	   int max_test_to_run = 5000; // set this to the total number of random cases to run
	   int failed_count = 0;
	   
	   
	   public RandomTester(String testName) {
	      super(testName);
	   }
	   
	   public int getRandomInt(int low, int high) {
		   Random r = new Random();
		   return r.nextInt(high-low) + low;
	   }
	   
	   public ResultPair getRandomPort() {
		   boolean expected = true;
		   
		   //get a random port number
		   int num = getRandomInt(0, 65535);
		   
		   //turn it into string
		   String val = Integer.toString(num);
		   StringBuilder result = new StringBuilder(val);
		   
		   //randomly choose a character to add to the string port value
		   String[] random_chars = {"-", ".", "@", "*"};
		   String r_char;
		   
		   if(getRandomInt(0,10) < 6) {
			   r_char = random_chars[getRandomInt(0, random_chars.length)];
			   expected = (expected == false);
		   } else {
			   r_char = "";
			   expected = (expected == true);
		   }
	
		   //insert the r_char at some random index
		   result.insert(getRandomInt(0, val.length()), r_char);
		  
		   //insert separator
		   result.insert(0, ":");
		   
		   
		   return new ResultPair(result.toString(), expected);
	   }
	   
	   public void testRandomUrlValidator()
	   {
		   ResultPair[] urlScheme = {
				   new ResultPair("https://", true),
				   new ResultPair("http://", true),
				   new ResultPair("ftp://", true),
				   new ResultPair("...://", false),
				   new ResultPair("://", false),
				   new ResultPair("...//", false),
		   };
		   ResultPair[] urlAuthority = {
				   new ResultPair("www.google.com", true),
				   new ResultPair("google.com", true),
				   new ResultPair("255.255.255.255", true),
				   new ResultPair("SomeStringOnly", false),
				   new ResultPair("www.google.commmmmmm", false),
				   new ResultPair("wwwwwwwwww.google.com", false),
				   new ResultPair("", false)
		   };
		   
		   ResultPair[] urlPath = {
				   new ResultPair("/path1", true),
				   new ResultPair("/123", true),
				   new ResultPair("/123/456", true),
				   new ResultPair("/123//789", true),
				   new ResultPair("$test1234", false),
				   new ResultPair("   /test1234", false),
				   new ResultPair("/test1234/#", false),
				   new ResultPair("/test1234/...", false),
				   new ResultPair("", true)
		   };
		   ResultPair[] urlQuery = {
				   new ResultPair("", true),
				   new ResultPair("?authentication=true", true),
				   new ResultPair("?user=SomeUser123&pass=123456", true)
		   };
		   
		   System.out.println("Running testIsValid Test");
		   int i;
		   String testString = "";
		   String expectedStr = "";
		   boolean expectedResult, actualResult;
		   
		   int len_scheme = urlScheme.length;
		   int len_authority = urlAuthority.length;
		   int len_path = urlPath.length;
		   int len_query = urlQuery.length;
		   
		   int random_index;
		   
		   for(i=0; i < max_test_to_run; i++) {
			   
			   testString = "";
			   expectedStr = "";
			   
			   //randomly generate a URL
			   random_index = getRandomInt(0, len_scheme);
			   testString += urlScheme[random_index].item;
			   expectedStr += urlScheme[random_index].valid;
			   
			   random_index = getRandomInt(0, len_authority);
			   testString += urlAuthority[random_index].item;
			   expectedStr += urlAuthority[random_index].valid;
			   
			   testString += getRandomPort().item;
			   expectedStr += getRandomPort().valid;
			   
			   random_index = getRandomInt(0, len_path);
			   testString += urlPath[random_index].item;
			   expectedStr += urlPath[random_index].valid;
			   
			   random_index = getRandomInt(0, len_query);
			   testString += urlQuery[random_index].item;
			   expectedStr += urlQuery[random_index].valid;
			   
			   expectedResult = !expectedStr.toLowerCase().contains("false".toLowerCase());
			   actualResult = urlVal.isValid(testString);
			   
			   if(expectedResult != actualResult) {
				   System.out.println( "testIsValid: Actual: " + actualResult + " | Expected: " +  expectedResult + " || " +  testString );
				   failed_count++;
			   }
			   
		   }
		   
		   System.out.println("\nTotal Test Ran: " + max_test_to_run);
		   System.out.println("Failed Count: " + failed_count);
		   System.out.println("Percentage Failed: " + ((double)failed_count/max_test_to_run * 100)+ "%");
	   }
	
	
}
