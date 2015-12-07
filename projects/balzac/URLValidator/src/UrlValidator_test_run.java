import static org.junit.Assert.*;

import org.junit.Test;

public class UrlValidator_test_run {

	@Test
	public void test() {
		UrlValidatorTest urltest = new UrlValidatorTest("Full test");
		urltest.testManualTest();
		urltest.partitionTest(10);
		urltest.testRandomScheme();
		urltest.testRandomSeparator();
		urltest.testRandomPath();
	}

}
