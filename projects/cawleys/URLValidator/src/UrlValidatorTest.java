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

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("ftp://www.amazon.com"));
	   System.out.println(urlVal.isValid("h3t://www.amazon.com"));
	   System.out.println(urlVal.isValid("3ht://www.amazon.com"));
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("http:www.amazon.com"));
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("://www.amazon.com"));
	   System.out.println(urlVal.isValid(""));
	   
	   /*System.out.println(urlVal.isValid("http://www.amazon.cooom"));
	   System.out.println(urlVal.isValid("http://www.amazon.net"));
	   System.out.println(urlVal.isValid("http://www.amazon.kkt"));*/
	   System.out.println(urlVal.isValid("yahoo.3ng:65a/testing//file"));
	   assertTrue(urlVal.isValid("eztv.ag:54321/testt123"));
   }
   /*
    * ResultPair[] testUrlScheme = {new ResultPair("http://", true),
                               new ResultPair("ftp://", true),
                               new ResultPair("h3t://", true),
                               new ResultPair("3ht://", false),
                               new ResultPair("http:/", false),
                               new ResultPair("http:", false),
                               new ResultPair("http/", false),
                               new ResultPair("://", false),
                               new ResultPair("", true)};
    */
   
     public void testYourFirstPartition()  // manual input testing. finding 
     {
        // initialize some variables
        int i1, i2, i3, i4 , i5, i6;
        
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        
        System.out.println("FIRST PARTITION TEST\n");
        
        
     // loop variable
        int i;
        
        // creating strings to partition 
        
        // create a valid, "control" string to test against
        String firstHalfUrl = "ftp://255.255.255.255";
        String secondHalfUrl = ":65/$23";
        String validUrl = firstHalfUrl + secondHalfUrl;        
        
        String firstHalfSet[] = {"http://0.0.0.0", "h3t://1.1.1.1", "ftp://www.amazon.com","h3t://go.au"};
        String secondHalfSet[] = {"",":6",":667/test1/?action=edit&mode=up",":0/test1/file"};
        String firstHalfBad[] = {"http://1.2.3.4.", "http:/www.google.com", "go.a", "://aaa."};
        String secondHalfBad[] = {"/../$23?action=view", ":-1/#", "/#/file", "/test1//file"};
        String testURLstr; 
        
        System.out.printf("Base Case: %s",validUrl);
        System.out.printf("\n  Result: %s\n\n",urlVal.isValid(validUrl));
        
        System.out.println("Expected Valid URLs\n----------");
        for(i = 0; i < 4; i++)
        {
             testURLstr = firstHalfUrl + secondHalfSet[i];
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        
             testURLstr = firstHalfSet[i] + secondHalfUrl;
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        }
        
        System.out.println("\nExpected Invalid URLs\n----------");
        for(i = 0; i < 4; i++)
        {
             testURLstr = firstHalfUrl + secondHalfBad[i];
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        
             testURLstr = firstHalfBad[i] + secondHalfUrl;
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        }   
   }
   
public void testYourSecondPartition()
   {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        System.out.println("\n\nSECOND PARTITION TEST\n");
        
        // loop variable
        int i;
        
        // creating strings to partition 
        
        // create a valid, "control" string to test against
        String firstHalfUrl = "http://www.google.com";
        String secondHalfUrl = ":80/test1";
        String validUrl = firstHalfUrl + secondHalfUrl;        
        
        String firstHalfSet[] = {"http://255.com", "ftp://go.cc", "http://0.0.0.0","h3t://go.cc"};
        String secondHalfSet[] = {":80/$23/t123",":65535",":958",":0/test1/file"};
        String firstHalfBad[] = {"http://1.2.3.4.", "http:/www.google.com", "go.a", "://aaa."};
        String secondHalfBad[] = {"/../$23?action=view", ":-1/#", "/test1/$23/file?action=edit&mode=up", ":65a?action=view"};
        String testURLstr; 
        
        System.out.printf("Base Case: %s",validUrl);
        System.out.printf("\n  Result: %s\n\n",urlVal.isValid(validUrl));
        
        System.out.println("Expected Valid URLs\n----------");
        for(i = 0; i < 4; i++)
        {
             testURLstr = firstHalfUrl + secondHalfSet[i];
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        
             testURLstr = firstHalfSet[i] + secondHalfUrl;
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        }
        
        System.out.println("\nExpected Invalid URLs\n----------");
        for(i = 0; i < 4; i++)
        {
             testURLstr = firstHalfUrl + secondHalfBad[i];
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        
             testURLstr = firstHalfBad[i] + secondHalfUrl;
             System.out.printf("URL: %s\n", testURLstr);
             System.out.printf("  Result: %s\n", urlVal.isValid(testURLstr));
        }    
   }
   
   
     
   private static String[] SCHEMES = new String[] {
          "http", 
          "https",
          "ftp",               
          "file",
          "data",
          "mailto",
   };
   
   private static String[] TLDS = new String[] {
          "aero",               // air transport industry
          "asia",               // Pan-Asia/Asia Pacific
          "biz",                // businesses
          "cat",                // Catalan linguistic/cultural community
          "com",                // commercial enterprises
          "coop",               // cooperative associations
          "info",               // informational sites
          "jobs",               // Human Resource managers
          "mobi",               // mobile products and services
          "museum",             // museums, surprisingly enough
          "name",               // individuals' sites
          "net",                // internet support infrastructure/business
          "org",                // noncommercial organizations
          "pro",                // credentialed professionals and entities
          "tel",                // contact data for businesses and individuals
          "travel",             // entities in the travel industry
          "gov",                // United States Government
          "edu",                // accredited postsecondary US education entities
          "mil",                // United States Military
          "int",                 // organizations established by international treaty
          //country ones
          "ac",                 // Ascension Island
          "ad",                 // Andorra
          "ae",                 // United Arab Emirates
          "af",                 // Afghanistan
          "ag",                 // Antigua and Barbuda
          "ai",                 // Anguilla
          "al",                 // Albania
          "am",                 // Armenia
          "an",                 // Netherlands Antilles
          "ao",                 // Angola
          "aq",                 // Antarctica
          "ar",                 // Argentina
          "as",                 // American Samoa
          "at",                 // Austria
          "au",                 // Australia (includes Ashmore and Cartier Islands and Coral Sea Islands)
          "aw",                 // Aruba
          "ax",                 // aland
          "az",                 // Azerbaijan
          "ba",                 // Bosnia and Herzegovina
          "bb",                 // Barbados
          "bd",                 // Bangladesh
          "be",                 // Belgium
          "bf",                 // Burkina Faso
          "bg",                 // Bulgaria
          "bh",                 // Bahrain
          "bi",                 // Burundi
          "bj",                 // Benin
          "bm",                 // Bermuda
          "bn",                 // Brunei Darussalam
          "bo",                 // Bolivia
          "br",                 // Brazil
          "bs",                 // Bahamas
          "bt",                 // Bhutan
          "bv",                 // Bouvet Island
          "bw",                 // Botswana
          "by",                 // Belarus
          "bz",                 // Belize
          "ca",                 // Canada
          "cc",                 // Cocos (Keeling) Islands
          "cd",                 // Democratic Republic of the Congo (formerly Zaire)
          "cf",                 // Central African Republic
          "cg",                 // Republic of the Congo
          "ch",                 // Switzerland
          "ci",                 // Cote d'Ivoire
          "ck",                 // Cook Islands
          "cl",                 // Chile
          "cm",                 // Cameroon
          "cn",                 // China, mainland
          "co",                 // Colombia
          "cr",                 // Costa Rica
          "cu",                 // Cuba
          "cv",                 // Cape Verde
          "cx",                 // Christmas Island
          "cy",                 // Cyprus
          "cz",                 // Czech Republic
          "de",                 // Germany
          "dj",                 // Djibouti
          "dk",                 // Denmark
          "dm",                 // Dominica
          "do",                 // Dominican Republic
          "dz",                 // Algeria
          "ec",                 // Ecuador
          "ee",                 // Estonia
          "eg",                 // Egypt
          "er",                 // Eritrea
          "es",                 // Spain
          "et",                 // Ethiopia
          "eu",                 // European Union
          "fi",                 // Finland
          "fj",                 // Fiji
          "fk",                 // Falkland Islands
          "fm",                 // Federated States of Micronesia
          "fo",                 // Faroe Islands
          "fr",                 // France
          "ga",                 // Gabon
          "gb",                 // Great Britain (United Kingdom)
          "gd",                 // Grenada
          "ge",                 // Georgia
          "gf",                 // French Guiana
          "gg",                 // Guernsey
          "gh",                 // Ghana
          "gi",                 // Gibraltar
          "gl",                 // Greenland
          "gm",                 // The Gambia
          "gn",                 // Guinea
          "gp",                 // Guadeloupe
          "gq",                 // Equatorial Guinea
          "gr",                 // Greece
          "gs",                 // South Georgia and the South Sandwich Islands
          "gt",                 // Guatemala
          "gu",                 // Guam
          "gw",                 // Guinea-Bissau
          "gy",                 // Guyana
          "hk",                 // Hong Kong
          "hm",                 // Heard Island and McDonald Islands
          "hn",                 // Honduras
          "hr",                 // Croatia (Hrvatska)
          "ht",                 // Haiti
          "hu",                 // Hungary
          "id",                 // Indonesia
          "ie",                 // Ireland (Eire)
          "il",                 // Israel
          "im",                 // Isle of Man
          "in",                 // India
          "io",                 // British Indian Ocean Territory
          "iq",                 // Iraq
          "ir",                 // Iran
          "is",                 // Iceland
          "it",                 // Italy
          //all TLDS below this fail
          "je",                 // Jersey
          "jm",                 // Jamaica
          "jo",                 // Jordan
          "jp",                 // Japan
          "ke",                 // Kenya
          "kg",                 // Kyrgyzstan
          "kh",                 // Cambodia (Khmer)
          "ki",                 // Kiribati
          "km",                 // Comoros
          "kn",                 // Saint Kitts and Nevis
          "kp",                 // North Korea
          "kr",                 // South Korea
          "kw",                 // Kuwait
          "ky",                 // Cayman Islands
          "kz",                 // Kazakhstan
          "la",                 // Laos (currently being marketed as the official domain for Los Angeles)
          "lb",                 // Lebanon
          "lc",                 // Saint Lucia
          "li",                 // Liechtenstein
          "lk",                 // Sri Lanka
          "lr",                 // Liberia
          "ls",                 // Lesotho
          "lt",                 // Lithuania
          "lu",                 // Luxembourg
          "lv",                 // Latvia
          "ly",                 // Libya
          "ma",                 // Morocco
          "mc",                 // Monaco
          "md",                 // Moldova
          "me",                 // Montenegro
          "mg",                 // Madagascar
          "mh",                 // Marshall Islands
          "mk",                 // Republic of Macedonia
          "ml",                 // Mali
          "mm",                 // Myanmar
          "mn",                 // Mongolia
          "mo",                 // Macau
          "mp",                 // Northern Mariana Islands
          "mq",                 // Martinique
          "mr",                 // Mauritania
          "ms",                 // Montserrat
          "mt",                 // Malta
          "mu",                 // Mauritius
          "mv",                 // Maldives
          "mw",                 // Malawi
          "mx",                 // Mexico
          "my",                 // Malaysia
          "mz",                 // Mozambique
          "na",                 // Namibia
          "nc",                 // New Caledonia
          "ne",                 // Niger
          "nf",                 // Norfolk Island
          "ng",                 // Nigeria
          "ni",                 // Nicaragua
          "nl",                 // Netherlands
          "no",                 // Norway
          "np",                 // Nepal
          "nr",                 // Nauru
          "nu",                 // Niue
          "nz",                 // New Zealand
          "om",                 // Oman
          "pa",                 // Panama
          "pe",                 // Peru
          "pf",                 // French Polynesia With Clipperton Island
          "pg",                 // Papua New Guinea
          "ph",                 // Philippines
          "pk",                 // Pakistan
          "pl",                 // Poland
          "pm",                 // Saint-Pierre and Miquelon
          "pn",                 // Pitcairn Islands
          "pr",                 // Puerto Rico
          "ps",                 // Palestinian territories (PA-controlled West Bank and Gaza Strip)
          "pt",                 // Portugal
          "pw",                 // Palau
          "py",                 // Paraguay
          "qa",                 // Qatar
          "re",                 // Reunion
          "ro",                 // Romania
          "rs",                 // Serbia
          "ru",                 // Russia
          "rw",                 // Rwanda
          "sa",                 // Saudi Arabia
          "sb",                 // Solomon Islands
          "sc",                 // Seychelles
          "sd",                 // Sudan
          "se",                 // Sweden
          "sg",                 // Singapore
          "sh",                 // Saint Helena
          "si",                 // Slovenia
          "sj",                 // Svalbard and Jan Mayen Islands Not in use (Norwegian dependencies; see .no)
          "sk",                 // Slovakia
          "sl",                 // Sierra Leone
          "sm",                 // San Marino
          "sn",                 // Senegal
          "so",                 // Somalia
          "sr",                 // Suriname
          "st",                 // Sao Tome and Principe
          "su",                 // Soviet Union (deprecated)
          "sv",                 // El Salvador
          "sy",                 // Syria
          "sz",                 // Swaziland
          "tc",                 // Turks and Caicos Islands
          "td",                 // Chad
          "tf",                 // French Southern and Antarctic Lands
          "tg",                 // Togo
          "th",                 // Thailand
          "tj",                 // Tajikistan
          "tk",                 // Tokelau
          "tl",                 // East Timor (deprecated old code)
          "tm",                 // Turkmenistan
          "tn",                 // Tunisia
          "to",                 // Tonga
          "tp",                 // East Timor
          "tr",                 // Turkey
          "tt",                 // Trinidad and Tobago
          "tv",                 // Tuvalu
          "tw",                 // Taiwan, Republic of China
          "tz",                 // Tanzania
          "ua",                 // Ukraine
          "ug",                 // Uganda
          "uk",                 // United Kingdom
          "um",                 // United States Minor Outlying Islands
          "us",                 // United States of America
          "uy",                 // Uruguay
          "uz",                 // Uzbekistan
          "va",                 // Vatican City State
          "vc",                 // Saint Vincent and the Grenadines
          "ve",                 // Venezuela
          "vg",                 // British Virgin Islands
          "vi",                 // U.S. Virgin Islands
          "vn",                 // Vietnam
          "vu",                 // Vanuatu
          "wf",                 // Wallis and Futuna
          "ws",                 // Samoa (formerly Western Samoa)
          "ye",                 // Yemen
          "yt",                 // Mayotte
          "yu",                 // Serbia and Montenegro (originally Yugoslavia)
          "za",                 // South Africa
          "zm",                 // Zambia
          "zw",                 // Zimbabwe
          
      };
   
   public static String generateString(String characters, int length)
   {
     Random rng = new Random();
     int length_rand = rng.nextInt(length)+1;
     char[] text = new char[length_rand];
       for (int i = 0; i < length_rand; i++)
       {
           text[i] = characters.charAt(rng.nextInt(characters.length()));
       }
       return new String(text);
   }
   
   public void testIsValid()
   {
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
     String valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
     String valid_path = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.?%&=+-";
     String valid_num = "0123456789";
     String garbage = "/?|}{[]+_-=~!@#$%^&*()";
     String brute = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ:/?|}{[]+_-=.~!@$%^&*()0123456789";
     Random rng = new Random();
     
     
     int i = 0;
     int j = 0;
     int path_length = 0;
     //tracking
     int pass = 0;
     int fail = 0;
     int tests = 10000;
     
     for(i = 0; i < tests; i++)
     {
       //construct a valid url
       //first generate scheme
       //String testme = generateString(valid, 3);
       String testme = SCHEMES[rng.nextInt(SCHEMES.length)];
       testme += "://";
       
       //generate authority
       //toggle between IP and string
       if(rng.nextBoolean()){
         testme += generateString(valid, 10);
         testme += ".";
         testme += TLDS[rng.nextInt(TLDS.length)];
       }
       else{
         testme += String.valueOf(rng.nextInt(255));
         testme += ".";
         testme += String.valueOf(rng.nextInt(255));
         testme += ".";
         testme += String.valueOf(rng.nextInt(255));
         testme += ".";
         testme += String.valueOf(rng.nextInt(255));
       }
       
       
       //generate port randomly
       //limited to 3 digits to 
       if(rng.nextBoolean()){
          testme += ":";
          testme += String.valueOf(rng.nextInt(1000));
       }
       
       
       //generate path
       // DISABLED: unknown path bug
       /*   
       path_length = rng.nextInt(5);
       for(j = 0; j < path_length; j++){
         testme += "/";
         testme += generateString(valid_path, 10);
       }
       */
       if(!urlVal.isValid(testme)){        
         System.out.println("FAIL: expected valid: " + testme);
         fail++;
       }
       else{
         pass++;
       }
      
       //System.out.println(urlVal.isValid(testme));
     }
     System.out.println("\nValid URLs marked as Valid: " + pass + "/" + tests);
     
     pass = 0;
     fail = 0;
     System.out.println("\nTesting Invalid URLs...\n");
     //10000 random invalid urls
     
     for(i = 0; i < tests; i++)
     {
     //construct a valid url
       //first generate scheme
       //String testme = "http://";
       //testme += generateString(brute, 50);
       String testme = SCHEMES[rng.nextInt(SCHEMES.length)];
       
       if(rng.nextBoolean()){
         testme += generateString(garbage, 10);
         testme += ".";
         testme += TLDS[rng.nextInt(TLDS.length)];
       }
       else{
         testme += String.valueOf(rng.nextInt(744)+256);
         testme += ".";
         testme += String.valueOf(rng.nextInt(744)+256);
         testme += ".";
         testme += String.valueOf(rng.nextInt(744)+256);
         testme += ".";
         testme += String.valueOf(rng.nextInt(744)+256);
       }
       
       
       if(urlVal.isValid(testme)){
         System.out.println("FAIL: Expected invalid: got valid: " + testme);
         fail++;
       }
       else{
         pass++;
       }
      
       //System.out.println(urlVal.isValid(testme));
     }
     
     System.out.println("Invalid URLS marked as invalid: " + pass + "/" + tests);
   }
   
   public void testAnyOtherUnitTest()
   {
	   UnitTestOther test = new UnitTestOther();
	   test.runTestUrl();
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
