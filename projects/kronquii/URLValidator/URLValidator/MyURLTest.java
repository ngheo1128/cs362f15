


import junit.framework.TestCase;




public class MyURLTest extends TestCase {
	public void testValidatorInputPartitioning() {
			String schemes[] = {"http://", "https://", "ftp://", "irc:/", "spdy://", "htttttps://"};
			Boolean schemes_validity[] = {true, true, true, false, false, false,};
			assertEquals(schemes.length, schemes_validity.length);
			
			String authorities[] = {"google.com", "git.osuosl.org", "192.168.1.1", "emoji.☯", "notld"};
			Boolean authorities_validity[] = {true, true, true, false, false};
			assertEquals(authorities.length, authorities_validity.length);
			
			String paths[] = {"/", "", "/a/longer/path/goes/here", "/with/relative/../dirs/", "\\windows\\style"};
			Boolean paths_validity[] = {true, true, true, true, false};
			assertEquals(paths.length, paths_validity.length);
			
			String ports[] = {":80", "", ":443", ":", ":123:123", ":deadbeef", ":65535"};
			Boolean ports_validity[] = {true, true, true, false, false, false, true};
			assertEquals(ports.length, ports_validity.length);
		
			String queries[] = {"?key=val", "#internal-link", "?q=asdf&t=ffab&ia=videos", "?emoji=☯"};
			Boolean queries_validity[] = {true, true, true, false};
			assertEquals(queries.length, queries_validity.length);
	 
	      
	       UrlValidator urlValidator = new UrlValidator();

	       for( int s = 0; s < schemes.length; s++)
	       {
	    	   String test_s = "";
	    	   Boolean expected_s = true;
	    	   test_s += schemes[s];
	    	   expected_s &= schemes_validity[s];
	    	   for( int a = 0; a < authorities.length; a++)
		       {
	    		   String test_a = test_s + authorities[a];
		    	   Boolean expected_a = expected_s & authorities_validity[a];
		    	   if(urlValidator.isValid(test_a) != expected_a) {
		    		   System.out.print("The URL ");
		    		   System.out.print(test_a);
		    		   System.out.print(" was supposed to ");
		    		   System.out.print(expected_a ? "pass\n" : "fail\n");
		    		   assertFalse(true);

		    	   }
		    	   for( int po = 0; po < ports.length; po++)
			       {
		    		   String test_po = test_a + ports[po];
			    	   Boolean expected_po = expected_a & ports_validity[po];
			    	   if(urlValidator.isValid(test_po) != expected_po) {
			    		   System.out.print("The URL ");
			    		   System.out.print(test_po);
			    		   System.out.print(" was supposed to ");
			    		   System.out.print(expected_po ? "pass\n" : "fail\n");
			    		   assertFalse(true);

			    	   }
			    	   for( int p = 0; p < paths.length; p++)
				       {
			    		   String test_p = test_po + paths[p];
				    	   Boolean expected_p = expected_po & paths_validity[p];
				    	   if(urlValidator.isValid(test_p) != expected_p) {
				    		   System.out.print("The URL ");
				    		   System.out.print(test_p);
				    		   System.out.print(" was supposed to ");
				    		   System.out.print(expected_p ? "pass\n" : "fail\n");
				    		   assertFalse(true);

				    	   }
				    	   for( int q = 0; q < queries.length; q++)
					       {
				    		   String test = test_p + queries[q];
					    	   Boolean expected = expected_p & queries_validity[q];
					    	   if(urlValidator.isValid(test) != expected) {
					    		   System.out.print("The URL ");
					    		   System.out.print(test);
					    		   System.out.print(" was supposed to ");
					    		   System.out.print(expected ? "pass\n" : "fail\n");
					    		   assertFalse(true);
					    	   }
					       }
				       }
			       }
	    		   
		       }
	       }
	       

	 }
	
}
