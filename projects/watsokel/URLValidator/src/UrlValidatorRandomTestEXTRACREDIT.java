/*
 * Random tests for UrlValidator isValid() method
 * Programmed by Kelvin Watson
 * ONID: watsokel, OSU ID 932540242
 */

import junit.framework.TestCase;
import java.util.*;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May
 *          2011) $
 */
public class UrlValidatorRandomTestEXTRACREDIT extends TestCase {
	private int MAX_ELEM = 5; 
	private ArrayList<String> rScheme = new ArrayList<String>();
	private ArrayList<String> rHost = new ArrayList<String>();
	private ArrayList<String> rTld = new ArrayList<String>();
	private ArrayList<String> rPort = new ArrayList<String>();
	private ArrayList<String> rPath = new ArrayList<String>();
	private ArrayList<String> rQuery = new ArrayList<String>();
	private ArrayList<String> rFragment = new ArrayList<String>();
	private ArrayList<String> failedTests = new ArrayList<String>();
	private ArrayList<String> passedTests = new ArrayList<String>();
	//stackoverflow.com/questions/2863852/how-to-generate-a-random-string-in-java?lq=1
	/**
	 * Generates a fixed-length string of random characters 
	 * @param rng
	 * @param characters
	 * @param length
	 * @return random string of characters of fixed length
	 */
	public static String generateRandStr(Random rng, String characters, int length){
		char[] text = new char[length];
	    for (int i=0; i<length; i++){
	        text[i] = characters.charAt(rng.nextInt(characters.length()));
	    }
	    return new String(text);
	}
	
	/**
	 * Generates a string of random characters of up to a maximum length 
	 * @param rng
	 * @param characters
	 * @param length
	 * @return
	 */
	public static String generateRandStrMaxLen(Random rng, String characters, int length){
		Random r = new Random();
		int len = r.nextInt(length);
		char[] text = new char[len];
	    for (int i=0; i<len; i++){
	        text[i] = characters.charAt(rng.nextInt(characters.length()));
	    }
	    return new String(text);
	}
	
	/**
	 * Constructor
	 */
	public UrlValidatorRandomTestEXTRACREDIT(String testName) {
		super(testName);
	}
	
	/**
	 * Initializes arrays with valid components
	 */	
	protected void setUp() throws Exception {
		super.setUp();
		System.out.println("\nTRACE: setUp()");
	}
	
	/**
	 * Clean up
	 */
	protected void tearDown() throws Exception {
		super.tearDown(); //  
		System.out.println("TRACE: tearDown()\n");	  
		//TODO: cleanup code goes here 
	 }
	

	
	/**
	 * Random Tests
	 */
	public void testRandomTest() {
		System.out.println("TRACE: testRandomTest()");	   
		UrlValidator uv = new UrlValidator();
		String testURL = null;

		//generate schemes
		rScheme.add("ftp://");
		rScheme.add("http://");
		rScheme.add("https://");

		//generate random hosts
		rHost.add("www."+generateRandStrMaxLen(new Random(),"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",20));
		for(int i=0; i<MAX_ELEM-1; i++){
			rHost.add(generateRandStrMaxLen(new Random(),"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",20));
		}
		//generate random top-level domains
		for(int i=0; i<MAX_ELEM; i++){
			rTld.add("."+generateRandStrMaxLen(new Random(),"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",6));
		}
		//generate random ports
		for(int i=0; i<MAX_ELEM; i++){
			rPort.add(":"+generateRandStrMaxLen(new Random(),"0123456789",5));
		}
		//generate random paths
		
		String rand1 = "/"+generateRandStrMaxLen(new Random(),"/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10);
		String rand2 = "/"+generateRandStrMaxLen(new Random(),"/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10)+"/";
		String rand3 = "/"+generateRandStrMaxLen(new Random(),"/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10);
		String randPath = null;
		for(int i=0; i<MAX_ELEM; i++){
			//concatenate at random
			int randNum = new Random().nextInt(4);
			if(randNum==0){
				randPath = rand1;
			} else if(randNum==1){
				randPath = rand1+rand2;
			} else if(randNum==2){
				randPath = rand1+rand2+rand3;				
			} else{
				randPath = rand1+rand2+rand3;
			}
			rPath.add(randPath);
		}
		
		for(int i=0; i<MAX_ELEM; i++){
			rPath.add("/"+generateRandStrMaxLen(new Random(),"/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10));
		}
		//generate queries
		for(int i=0; i<MAX_ELEM; i++){
			String randKey = generateRandStrMaxLen(new Random(),"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10); 
			String randVal = generateRandStrMaxLen(new Random(),"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10);
			String randQuery = "?"+randKey+"="+randVal;				
			rQuery.add("?"+randKey+"="+randVal);
		}
		//generate fragments
		for(int i=0; i<MAX_ELEM; i++){
			rFragment.add("#"+generateRandStrMaxLen(new Random(),"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",10));
		}
				
		System.out.println("Generated schemes: "+rScheme.toString());
		System.out.println("Generated hosts: "+rHost.toString());
		System.out.println("Generated TLDs: "+rTld.toString());
		System.out.println("Generated ports: "+rPort.toString());
		System.out.println("Generated paths: "+rPath.toString());
		System.out.println("Generated queries: "+rQuery.toString());
		System.out.println("Generated fragments: "+rFragment.toString());

		//concatenate to produce URLs
		for(int i=0, sLen=rScheme.size(); i<sLen; i++){
			for(int j=0, hLen=rHost.size(); j<hLen; j++){
				for(int k=0, tLen=rTld.size(); k<tLen; k++){
					for(int l=0, pLen=rPort.size(); l<pLen; l++){
						for(int m=0, paLen=rPath.size(); m<paLen; m++){
							for(int n=0, qLen=rQuery.size(); n<qLen; n++){
								for(int o=0, fLen=rFragment.size(); o<fLen; o++){
									testURL = 
											new StringBuilder().append(rScheme.get(i)).append(rHost.get(j)).append(rTld.get(k))
											.append(rPort.get(l)).append(rPath.get(m)).append(rQuery.get(n)).append(rFragment.get(o)).toString();
									//print passing tests only and manually check if they should have passed
									if(uv.isValid(testURL)){
										passedTests.add(testURL);
									} else{
										failedTests.add(testURL);
									}
								}
							}
						}
					}
				}
			}
		}
		analyzeResults(passedTests.size(),failedTests.size());

	}

	/**
	 * Examine Test Results
	 * A delta-debugger or manual debugging should be done on failed tests to reduce
	 * the input space.
	 */
	public void analyzeResults(int passed, int failed) {
		System.out.println("\nNumber of passed tests: "+passed);
		System.out.println("Number of failed tests: "+failed);
		System.out.println("Manually examine failed tests or run delta-debugger to reduce input space and localize fault(s)");
	}
}


