import static org.junit.Assert.*;

import org.junit.Test;


public class AuthorityTester {

	@Test
	public void testValid() {
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		
		assert(urlVd.isValid("http://abcdefghijklmnopqrstuvwxyz-1234567890.com"));
		assert(urlVd.isValid("http://test.test.test.com?"));

	}
	
	@Test
	public void testPorts(){
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assert(urlVd.isValid("http://google.com:1234"));
	}
	
	@Test
	public void testInvalid() {
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assert(!urlVd.isValid("http://goog2+3.com"));
		assert(!urlVd.isValid("http://adsf:adf.com"));
		
	}
	

}
