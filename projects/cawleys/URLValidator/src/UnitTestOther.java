import static junit.framework.TestCase.*;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

public class UnitTestOther {
	TestPart[] testUrlScheme = {   
	            new TestPart("http://", true),
	            new TestPart("ftp://", true),
	            new TestPart("mailto://", true),
	            new TestPart("file://", true),
	            new TestPart("http", false), // no ://
	            new TestPart("http:", false), //no //
	            new TestPart("http:/", false), //no second /
	            new TestPart("://", false), //nothing before :
	            new TestPart("", true)};

	TestPart[] testUrlAuthority = {
	             new TestPart("www.yahoo.com", true),
	             new TestPart("yahoo.com", true),
	             new TestPart("yahoo.au", true),
	             new TestPart("0.0.0.0", true),
	             new TestPart("255.255.255.255", true),
	             new TestPart("256.256.256.256", false), //256 is too large
	             new TestPart("123.com", true),
	             new TestPart("ab cd.com", false), //can not contain a space
	             new TestPart("1.2.3.4.", false), //. after 4
	             new TestPart("1.2.3", false),
	             new TestPart(".1.2.3.4", false), //.before 1
	             new TestPart("blank\\.com", false), //invalid because of \
	             new TestPart("yahoo.3ng", false), //3ng invalid
	             new TestPart("eztv.ag", true),
	             new TestPart("yahoo.2345", false), //2345 invalid
	             new TestPart("abc.", false), //dot w/o com invalid
	             new TestPart(".abc", false), //nothing before .
	             new TestPart("abc", false), //no delimiter
	             new TestPart("", false) //empty
	};
	TestPart[] testUrlPort = {
	             new TestPart(":90", true),
	             new TestPart(":12345", true),
	             new TestPart(":0", true),
	             new TestPart("", true),
	             new TestPart(":-1", false), //no negative numbers
	             new TestPart(":54321", true),
	             new TestPart(":65a", false) //no letters
	};
	TestPart[] testPath = {
	             new TestPart("/testing", true),
	             new TestPart("/testt123", true),
	             new TestPart("/$2$3", true),
	             new TestPart("/..", false),
	             new TestPart("/../", false),
	             new TestPart("/testbla/", true),
	             new TestPart("", true),
	             new TestPart("/testing/file", true),
	             new TestPart("/..//file", false),
	             new TestPart("/testing//file", true),
	};
	
	TestPart[] testUrlQuery = {
	             new TestPart("?anythinggoes=view", true),
	             new TestPart("?anythinggoes=test&mode=up", true),
	             new TestPart("", true)
	};
	
	TestPart[][] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
	int[] testPartsIndex = {0, 0, 0, 0, 0};
	
	//---------------- Test data for individual url parts ----------------
	TestPart[] testScheme = {new TestPart("http", true),
	           new TestPart("ftp", false),
	           new TestPart("httpd", false),
	           new TestPart("telnet", false)};
	
	
	public void runTestUrl() {
		PrintWriter writer;
		
		try {
			writer = new PrintWriter("runTestUrl.txt", "UTF-8");
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		
		String url1 = "";
		String url2 = "";
		String url3 = "";
		String url4 = "";
		String url5 = "";
		int failCount = 0;
		boolean shouldBeInvalid;
		boolean invalid;
		String expected;
		String actually;
		
		int i = 0; //counter for scheme
		int j = 0; //counter for authority
		int k = 0; //counter for port
		int l = 0; //counter for path
		int m = 0; //counter for query
		
	
		//build each url
		for(i=0; i<testUrlScheme.length; i++){
			url1=testUrlScheme[i].part;
			for(j=0; j<testUrlAuthority.length; j++){
				url2 = url1+ testUrlAuthority[j].part;
				for(k=0; k<testUrlPort.length ; k++){
					url3 = url2 + testUrlPort[k].part;
					for(l=0; l<testPath.length; l++){
						url4 = url3 + testPath[l].part;
						for(m=0; m<testUrlQuery.length; m++){
							url5 =  url4+ testUrlQuery[m].part;
							
							//make a new instance of test UrlValidator to test
							UrlValidator testURL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
							
							shouldBeInvalid = testUrlScheme[i].TorF == false || testUrlAuthority[j].TorF == false || 
									testUrlPort[k].TorF == false || testPath[l].TorF == false || testUrlQuery[m].TorF == false;
							
							expected = shouldBeInvalid ? "invalid" : "valid";
							
							invalid = !testURL.isValid(url5);
							
							actually = invalid ? "invalid" : "valid";
							
							try {
								
								assertTrue(shouldBeInvalid == invalid);
								
								writer.println("PASS (expected " + expected + ", actually " + actually + ") " + url5);
							} catch (AssertionError e) {
								writer.println(" FAIL (expected " + expected + ", actually " + actually + ") " + url5);
								failCount++;
							}
						}
					}
				}
			}
			
		}
		
		writer.close();
		
		if (failCount > 0) {
			System.out.println("(" + failCount + " failures) See runTestOther.txt");
		}
		
		assertTrue(failCount == 0);
		
	}
}
