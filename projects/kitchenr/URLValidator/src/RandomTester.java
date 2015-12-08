import static org.junit.Assert.*;

import org.junit.Test;
import java.util.Random;
import java.util.ArrayList;
import java.math.*;
import java.lang.StringBuilder;

public class RandomTester {

	
	public String generateValidHost(Random r){
		String value = new String();
		int length = Math.abs(r.nextInt()%30)+1;
		String valid = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String validport="1234567890";
		for(int i=0;i<length;i++){
			value = value + valid.charAt(Math.abs(r.nextInt()%valid.length()));
			if(r.nextInt()%length == 0 && i>0 && i<length-1) value+='-';
		}
		value = value + ".com";
		if(r.nextBoolean()){
			value+=':';
			int len=Math.abs(r.nextInt()%3)+1;
			for(int i=0;i<len;i++) value+=validport.charAt(Math.abs(r.nextInt()%10));
		}
		
		return value;
	}
	
	public String generateValidPath(Random r){
		String value = new String();
		String valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+:@&=+$,-_.!~*'()";
		int sections = Math.abs(r.nextInt()%5)+1;
		for(int i=0;i<sections;i++){
			value+='/';
			int seclength=Math.abs(r.nextInt()%5)+1;
			for(int j=0;j<seclength;j++){
				char x = valid.charAt(Math.abs(r.nextInt()%valid.length()));
				value+=x;
			}
		}
		return value;
	}
	
	public String invalidateHost(String s, Random r){
		StringBuilder output = new StringBuilder(s);
		int pos = Math.abs(r.nextInt()%s.length());
		String invalidChars="!@#$%^&*()_+=|\\";
		output.setCharAt(pos,invalidChars.charAt(Math.abs(r.nextInt()%invalidChars.length())));
		return output.toString();
	}
	
	
	@Test
	public void testValid() {
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		int NUM_TEST_CASES = 1000;
		ArrayList<String> failures= new ArrayList<String>();
		ArrayList<String> success=new ArrayList<String>();
		Random r = new Random();
		for(int i=0;i<NUM_TEST_CASES;i++){
			String current = new String("http://");
			current = current + generateValidHost(r);
			current = current + generateValidPath(r);
			//System.out.println(current);
			if(!urlVd.isValid(current)) failures.add(current);
			else success.add(current);
		}
		System.out.println(success.size() + " successes " + failures.size() + " failures");
		if(failures.size()>0){
			for(String cur : failures){
				System.out.println(cur);
			}
			assert(false);
		}
	
	}
	
	@Test
	public void testInvalid() {
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		int NUM_TEST_CASES = 1000;
		ArrayList<String> failures= new ArrayList<String>();
		ArrayList<String> success=new ArrayList<String>();
		Random r = new Random();
		for(int i=0;i<NUM_TEST_CASES;i++){
			String current = new String("http://");
			current = current + invalidateHost(generateValidHost(r),r);
			current = current + generateValidPath(r);
			//System.out.println(current);
			
			if(urlVd.isValid(current)) failures.add(current);
			else success.add(current);
		}
		System.out.println(success.size() + " successes " + failures.size() + " failures");
		if(failures.size()>0){
			for(String cur : failures){
				System.out.println(cur);
			}
			assert(false);
		}
	}

}
