import static org.junit.Assert.*;

import org.junit.Test;


public class PathTester {

	@Test
	public void test() {
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assert(urlVd.isValid("http://google.com/asdfasdf123+343"));
	}

	
	@Test
	public void invalid(){
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assert(!urlVd.isValid("http://google.com/;"));
		assert(!urlVd.isValid("http://google.com//"));
	}
	
	@Test
	public void inescaped(){
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assert(urlVd.isValid("http://google.com/test%20this"));
	}
}
