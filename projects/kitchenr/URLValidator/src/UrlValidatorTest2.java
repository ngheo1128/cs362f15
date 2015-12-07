import static org.junit.Assert.*;

import org.junit.Test;
import java.util.Scanner;

public class UrlValidatorTest2 {

	@Test
	public void test() {
		//String[] schemes={"http"};
		//UrlValidator urlVd = new UrlValidator(schemes);
		UrlValidator urlVd = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		Scanner scan = new Scanner(System.in);
		String input;
		do{
			input=scan.next();
			if(urlVd.isValid(input)){
				System.out.println("Valid");
			}
			else
			{
				System.out.println("Invalid");
			}
		} while(!"done".equals(input));
		//	fail("Not yet implemented");
	}

}
