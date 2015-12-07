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

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Random;




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
		   String thisString = "";
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	
		   System.out.println("Expected VALID Urls (Manual Tests):");
		   System.out.println(String.format("%-60s", thisString = "http://www.amazon.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://www.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://amazon.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "www.test.org") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "test.org") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "ftp://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "bolo://test.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "bitcoin://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "bitcoin1://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "chrome-extension://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "-extension://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "chrome-://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "chrome.extension://google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://ww3-www.google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://ww3_www.google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://ww3.www.google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://ww3~www.google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google~test.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google-test.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google_test.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.test~com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.test-com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.test_com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.arpa") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.com.us") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.state.ca.us") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.state.ca.us.gov") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "ftp://user:password@google.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "mailto://mcwhorta@oregonstate.edu") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "mailto://mcwhorta@gmail.com") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.com/%2F") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.google.com/%0D%0A") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/path?query_string#fragment_id") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/path") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/path?query_string") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/path#fragment_id") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println(String.format("%-60s", thisString = "http://www.domain.edu:80/path?query-string#fragment_id") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   	   System.out.println("");
		   System.out.println("\nExpected INVALID Urls (Manual Tests):");
		   System.out.println(String.format("%-60s", thisString = "") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://www.amazon") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "!!!://www.amazon") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "httpwww.amazon.com") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "://www.amazon.com") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://bad!!!.gov") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://www.google.com.com.org") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://128.193.4.500") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://128.193.4.200:80") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://128.193.4.200:1000") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://128.193.4.200:65535") + "Expected: true\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://128.193.4.200:65536") + "Expected: false\tActual: " + urlVal.isValid(thisString));
		   System.out.println(String.format("%-60s", thisString = "http://www.google.sz") + "Expected: true\tActual: " + urlVal.isValid(thisString));
	   }
	   
	   // Partition plan: scheme & domain
	   // URL format: scheme://domain:port/path?query_string#fragment_id
	   
	   //Scheme Source: http://en.wikipedia.org/wiki/URI_scheme
	   ResultPair [] validSchemes = {
			   new ResultPair("aaa", true),
			   new ResultPair("aaas", true),
			   new ResultPair("about", true),
			   new ResultPair("acap", true),
			   new ResultPair("acct", true),
			   new ResultPair("adiumxtra", true),
			   new ResultPair("afp", true),
			   new ResultPair("afs", true),
			   new ResultPair("aim", true),
			   new ResultPair("app", true),
			   new ResultPair("apt", true),
			   new ResultPair("attachment", true),
			   new ResultPair("aw", true),
			   new ResultPair("barion", true),
			   new ResultPair("beshare", true),
			   new ResultPair("bitcoin", true),
			   new ResultPair("bolo", true),
			   new ResultPair("callto", true),
			   new ResultPair("cap", true),
			   new ResultPair("chrome", true),
			   new ResultPair("chrome", true),
			   new ResultPair("chrome-extension", true),
			   new ResultPair("cid", true),
			   new ResultPair("coap", true),
			   new ResultPair("coaps", true),
			   new ResultPair("com-eventbrite-attendee", true),
			   new ResultPair("content", true),
			   new ResultPair("crid", true),
			   new ResultPair("cvs", true),
			   new ResultPair("data", true),
			   new ResultPair("dav", true),
			   new ResultPair("dict", true),
			   new ResultPair("dlna-playsingle", true),
			   new ResultPair("dlna-playcontainer", true),
			   new ResultPair("dns", true),
			   new ResultPair("dtn", true),
			   new ResultPair("dvb", true),
			   new ResultPair("ed2k", true),
			   new ResultPair("facetime", true),
			   new ResultPair("fax", true),
			   new ResultPair("feed", true),
			   new ResultPair("file", true),
			   new ResultPair("finger", true),
			   new ResultPair("fish", true),
			   new ResultPair("ftp", true),
			   new ResultPair("geo", true),
			   new ResultPair("gg", true),
			   new ResultPair("git", true),
			   new ResultPair("gizmoproject", true),
			   new ResultPair("go", true),
			   new ResultPair("gopher", true),
			   new ResultPair("gtalk", true),
			   new ResultPair("h323", true),
			   new ResultPair("hcp", true),
			   new ResultPair("http", true),
			   new ResultPair("https", true),
			   new ResultPair("iax", true),
			   new ResultPair("icap", true),
			   new ResultPair("icon", true),
			   new ResultPair("im", true),
			   new ResultPair("imap", true),
			   new ResultPair("info", true),
			   new ResultPair("ipn", true),
			   new ResultPair("ipp", true),
			   new ResultPair("irc", true),
			   new ResultPair("irc6", true),
			   new ResultPair("ircs", true),
			   new ResultPair("iris", true),
			   new ResultPair("iris.beep", true),
			   new ResultPair("iris.xpc", true),
			   new ResultPair("iris.xpcs", true),
			   new ResultPair("iris.lws", true),
			   new ResultPair("itms", true),
			   new ResultPair("jabber", true),
			   new ResultPair("jar", true),
			   new ResultPair("jms", true),
			   new ResultPair("keyparc", true),
			   new ResultPair("lastfm", true),
			   new ResultPair("ldap", true),
			   new ResultPair("ldaps", true),
			   new ResultPair("magnet", true),
			   new ResultPair("mailserver", true),
			   new ResultPair("mailto", true),
			   new ResultPair("maps", true),
			   new ResultPair("market", true),
			   new ResultPair("message", true),
			   new ResultPair("mid", true),
			   new ResultPair("mms", true),
			   new ResultPair("modem", true),
			   new ResultPair("ms-help", true),
			   new ResultPair("ms-settings-power", true),
			   new ResultPair("msnim", true),
			   new ResultPair("msrp", true),
			   new ResultPair("msrps", true),
			   new ResultPair("mtqp", true),
			   new ResultPair("mumble", true),
			   new ResultPair("mupdate", true),
			   new ResultPair("mvn", true),
			   new ResultPair("news", true),
			   new ResultPair("nfs", true),
			   new ResultPair("ni", true),
			   new ResultPair("nih", true),
			   new ResultPair("nntp", true),
			   new ResultPair("notes", true),
			   new ResultPair("oid", true),
			   new ResultPair("opaquelocktoken", true),
			   new ResultPair("pack", true),
			   new ResultPair("palm", true),
			   new ResultPair("paparazzi", true),
			   new ResultPair("pkcs11", true),
			   new ResultPair("platform", true),
			   new ResultPair("pop", true),
			   new ResultPair("pres", true),
			   new ResultPair("prospero", true),
			   new ResultPair("proxy", true),
			   new ResultPair("psyc", true),
			   new ResultPair("query", true),
			   new ResultPair("reload", true),
			   new ResultPair("res", true),
			   new ResultPair("resource", true),
			   new ResultPair("rmi", true),
			   new ResultPair("rsync", true),
			   new ResultPair("rtmfp", true),
			   new ResultPair("rtmp", true),
			   new ResultPair("rtsp", true),
			   new ResultPair("secondlife", true),
			   new ResultPair("service", true),
			   new ResultPair("session", true),
			   new ResultPair("sftp", true),
			   new ResultPair("sgn", true),
			   new ResultPair("shttp", true),
			   new ResultPair("sieve", true),
			   new ResultPair("sip", true),
			   new ResultPair("sips", true),
			   new ResultPair("skype", true),
			   new ResultPair("smb", true),
			   new ResultPair("sms", true),
			   new ResultPair("snews", true),
			   new ResultPair("snmp", true),
			   new ResultPair("soap.beep", true),
			   new ResultPair("soap.beeps", true),
			   new ResultPair("soldat", true),
			   new ResultPair("spotify", true),
			   new ResultPair("ssh", true),
			   new ResultPair("steam", true),
			   new ResultPair("stun", true),
			   new ResultPair("stuns", true),
			   new ResultPair("svn", true),
			   new ResultPair("tag", true),
			   new ResultPair("teamspeak", true),
			   new ResultPair("tel", true),
			   new ResultPair("telnet", true),
			   new ResultPair("tftp", true),
			   new ResultPair("things", true),
			   new ResultPair("thismessage", true),
			   new ResultPair("tip", true),
			   new ResultPair("tn3270", true),
			   new ResultPair("turn", true),
			   new ResultPair("turns", true),
			   new ResultPair("tv", true),
			   new ResultPair("udp", true),
			   new ResultPair("udp", true),
			   new ResultPair("unreal", true),
			   new ResultPair("urn", true),
			   new ResultPair("ut2004", true),
			   new ResultPair("vemmi", true),
			   new ResultPair("ventrilo", true),
			   new ResultPair("videotex", true),
			   new ResultPair("view-source", true),
			   new ResultPair("wais", true),
			   new ResultPair("webcal", true),
			   new ResultPair("ws", true),
			   new ResultPair("wss", true),
			   new ResultPair("wtai", true),
			   new ResultPair("wyciwyg", true),
			   new ResultPair("xcon", true),
			   new ResultPair("xcon-userid", true),
			   new ResultPair("xfire", true),
			   new ResultPair("xmlrpc.beep", true),
			   new ResultPair("xmlrpc.beeps", true),
			   new ResultPair("xmpp", true),
			   new ResultPair("xri", true),
			   new ResultPair("ymsgr", true),
			   new ResultPair("z39.50", true),
			   new ResultPair("z39.50r", true),
			   new ResultPair("z39.50s", true),
			   new ResultPair("doi", true),
			   new ResultPair("javascript", true),
			   new ResultPair("jdbc", true),
			   new ResultPair("stratum", true)
		};
	   
	   ResultPair [] invalidSchemes = {
			   new ResultPair("www?google", false),
			   new ResultPair("w12°", false),
			   new ResultPair(":", false),
			   new ResultPair("http://www.hero6.org/\"", false),	//Most browsers will resolve this though :(
			   new ResultPair("12www", false),
			   new ResultPair("", false)
	   };

	   //Domain source: http://en.wikipedia.org/wiki/List_of_Internet_top-level_domains
	   ResultPair [] validDomain = {
			   new ResultPair("com", true),
			   new ResultPair("edu", true),
			   new ResultPair("gov", true),
			   new ResultPair("int", true),
			   new ResultPair("mil", true),
			   new ResultPair("net", true),
			   new ResultPair("org", true),
			   new ResultPair("ac", true),
			   new ResultPair("ad", true),
			   new ResultPair("ae", true),
			   new ResultPair("af", true),
			   new ResultPair("ag", true),
			   new ResultPair("ai", true),
			   new ResultPair("al", true),
			   new ResultPair("am", true),
			   new ResultPair("an", true),
			   new ResultPair("ao", true),
			   new ResultPair("aq", true),
			   new ResultPair("ar", true),
			   new ResultPair("as", true),
			   new ResultPair("at", true),
			   new ResultPair("au", true),
			   new ResultPair("aw", true),
			   new ResultPair("ax", true),
			   new ResultPair("az", true),
			   new ResultPair("ba", true),
			   new ResultPair("bb", true),
			   new ResultPair("bd", true),
			   new ResultPair("be", true),
			   new ResultPair("bf", true),
			   new ResultPair("bg", true),
			   new ResultPair("bh", true),
			   new ResultPair("bi", true),
			   new ResultPair("bj", true),
			   new ResultPair("bm", true),
			   new ResultPair("bn", true),
			   new ResultPair("bo", true),
			   new ResultPair("bq", true),
			   new ResultPair("br", true),
			   new ResultPair("bs", true),
			   new ResultPair("bt", true),
			   new ResultPair("bv", true),
			   new ResultPair("bw", true),
			   new ResultPair("by", true),
			   new ResultPair("bz", true),
			   new ResultPair("ca", true),
			   new ResultPair("cc", true),
			   new ResultPair("cd", true),
			   new ResultPair("cf", true),
			   new ResultPair("cg", true),
			   new ResultPair("ch", true),
			   new ResultPair("ci", true),
			   new ResultPair("ck", true),
			   new ResultPair("cl", true),
			   new ResultPair("cm", true),
			   new ResultPair("cn", true),
			   new ResultPair("co", true),
			   new ResultPair("cr", true),
			   new ResultPair("cs", true),
			   new ResultPair("cu", true),
			   new ResultPair("cv", true),
			   new ResultPair("cw", true),
			   new ResultPair("cx", true),
			   new ResultPair("cy", true),
			   new ResultPair("cz", true),
			   new ResultPair("dd", true),
			   new ResultPair("de", true),
			   new ResultPair("dj", true),
			   new ResultPair("dk", true),
			   new ResultPair("dm", true),
			   new ResultPair("do", true),
			   new ResultPair("dz", true),
			   new ResultPair("ec", true),
			   new ResultPair("ee", true),
			   new ResultPair("eg", true),
			   new ResultPair("eh", true),
			   new ResultPair("er", true),
			   new ResultPair("es", true),
			   new ResultPair("et", true),
			   new ResultPair("eu", true),
			   new ResultPair("fi", true),
			   new ResultPair("fj", true),
			   new ResultPair("fk", true),
			   new ResultPair("fm", true),
			   new ResultPair("fo", true),
			   new ResultPair("fr", true),
			   new ResultPair("ga", true),
			   new ResultPair("gb", true),
			   new ResultPair("gd", true),
			   new ResultPair("ge", true),
			   new ResultPair("gf", true),
			   new ResultPair("gg", true),
			   new ResultPair("gh", true),
			   new ResultPair("gi", true),
			   new ResultPair("gl", true),
			   new ResultPair("gm", true),
			   new ResultPair("gn", true),
			   new ResultPair("gp", true),
			   new ResultPair("gq", true),
			   new ResultPair("gr", true),
			   new ResultPair("gs", true),
			   new ResultPair("gt", true),
			   new ResultPair("gu", true),
			   new ResultPair("gw", true),
			   new ResultPair("gy", true),
			   new ResultPair("hk", true),
			   new ResultPair("hm", true),
			   new ResultPair("hn", true),
			   new ResultPair("hr", true),
			   new ResultPair("ht", true),
			   new ResultPair("hu", true),
			   new ResultPair("id", true),
			   new ResultPair("ie", true),
			   new ResultPair("il", true),
			   new ResultPair("im", true),
			   new ResultPair("in", true),
			   new ResultPair("io", true),
			   new ResultPair("iq", true),
			   new ResultPair("ir", true),
			   new ResultPair("is", true),
			   new ResultPair("it", true),
			   new ResultPair("je", true),
			   new ResultPair("jm", true),
			   new ResultPair("jo", true),
			   new ResultPair("jp", true),
			   new ResultPair("ke", true),
			   new ResultPair("kg", true),
			   new ResultPair("kh", true),
			   new ResultPair("ki", true),
			   new ResultPair("km", true),
			   new ResultPair("kn", true),
			   new ResultPair("kp", true),
			   new ResultPair("kr", true),
			   new ResultPair("kw", true),
			   new ResultPair("ky", true),
			   new ResultPair("kz", true),
			   new ResultPair("la", true),
			   new ResultPair("lb", true),
			   new ResultPair("lc", true),
			   new ResultPair("li", true),
			   new ResultPair("lk", true),
			   new ResultPair("lr", true),
			   new ResultPair("ls", true),
			   new ResultPair("lt", true),
			   new ResultPair("lu", true),
			   new ResultPair("lv", true),
			   new ResultPair("ly", true),
			   new ResultPair("ma", true),
			   new ResultPair("mc", true),
			   new ResultPair("md", true),
			   new ResultPair("me", true),
			   new ResultPair("mg", true),
			   new ResultPair("mh", true),
			   new ResultPair("mk", true),
			   new ResultPair("ml", true),
			   new ResultPair("mm", true),
			   new ResultPair("mn", true),
			   new ResultPair("mo", true),
			   new ResultPair("mp", true),
			   new ResultPair("mq", true),
			   new ResultPair("mr", true),
			   new ResultPair("ms", true),
			   new ResultPair("mt", true),
			   new ResultPair("mu", true),
			   new ResultPair("mv", true),
			   new ResultPair("mw", true),
			   new ResultPair("mx", true),
			   new ResultPair("my", true),
			   new ResultPair("mz", true),
			   new ResultPair("na", true),
			   new ResultPair("nc", true),
			   new ResultPair("ne", true),
			   new ResultPair("nf", true),
			   new ResultPair("ng", true),
			   new ResultPair("ni", true),
			   new ResultPair("nl", true),
			   new ResultPair("no", true),
			   new ResultPair("np", true),
			   new ResultPair("nr", true),
			   new ResultPair("nu", true),
			   new ResultPair("nz", true),
			   new ResultPair("om", true),
			   new ResultPair("pa", true),
			   new ResultPair("pe", true),
			   new ResultPair("pf", true),
			   new ResultPair("pg", true),
			   new ResultPair("ph", true),
			   new ResultPair("pk", true),
			   new ResultPair("pl", true),
			   new ResultPair("pm", true),
			   new ResultPair("pn", true),
			   new ResultPair("pr", true),
			   new ResultPair("ps", true),
			   new ResultPair("pt", true),
			   new ResultPair("pw", true),
			   new ResultPair("py", true),
			   new ResultPair("qa", true),
			   new ResultPair("re", true),
			   new ResultPair("ro", true),
			   new ResultPair("rs", true),
			   new ResultPair("ru", true),
			   new ResultPair("rw", true),
			   new ResultPair("sa", true),
			   new ResultPair("sb", true),
			   new ResultPair("sc", true),
			   new ResultPair("sd", true),
			   new ResultPair("se", true),
			   new ResultPair("sg", true),
			   new ResultPair("sh", true),
			   new ResultPair("si", true),
			   new ResultPair("sj", true),
			   new ResultPair("sk", true),
			   new ResultPair("sl", true),
			   new ResultPair("sm", true),
			   new ResultPair("sn", true),
			   new ResultPair("so", true),
			   new ResultPair("sr", true),
			   new ResultPair("ss", true),
			   new ResultPair("st", true),
			   new ResultPair("su", true),
			   new ResultPair("sv", true),
			   new ResultPair("sx", true),
			   new ResultPair("sy", true),
			   new ResultPair("sz", true),
			   new ResultPair("tc", true),
			   new ResultPair("td", true),
			   new ResultPair("tf", true),
			   new ResultPair("tg", true),
			   new ResultPair("th", true),
			   new ResultPair("tj", true),
			   new ResultPair("tk", true),
			   new ResultPair("tl", true),
			   new ResultPair("tm", true),
			   new ResultPair("tn", true),
			   new ResultPair("to", true),
			   new ResultPair("tp", true),
			   new ResultPair("tr", true),
			   new ResultPair("tt", true),
			   new ResultPair("tv", true),
			   new ResultPair("tw", true),
			   new ResultPair("tz", true),
			   new ResultPair("ua", true),
			   new ResultPair("ug", true),
			   new ResultPair("uk", true),
			   new ResultPair("us", true),
			   new ResultPair("uy", true),
			   new ResultPair("uz", true),
			   new ResultPair("va", true),
			   new ResultPair("vc", true),
			   new ResultPair("ve", true),
			   new ResultPair("vg", true),
			   new ResultPair("vi", true),
			   new ResultPair("vn", true),
			   new ResultPair("vu", true),
			   new ResultPair("wf", true),
			   new ResultPair("ws", true),
			   new ResultPair("ye", true),
			   new ResultPair("yt", true),
			   new ResultPair("yu", true),
			   new ResultPair("za", true),
			   new ResultPair("zm", true),
			   new ResultPair("zr", true),
			   new ResultPair("zw", true),
			   new ResultPair("xn--lgbbat1ad8j", true),
			   new ResultPair("xn--y9a3aq", true),
			   new ResultPair("xn--54b7fta0cc", true),
			   new ResultPair("xn--90ais", true),
			   new ResultPair("xn--fiqs8s", true),
			   new ResultPair("xn--fiqz9s", true),
			   new ResultPair("xn--wgbh1c", true),
			   new ResultPair("xn--node", true),
			   new ResultPair("xn--j6w193g", true),
			   new ResultPair("xn--h2brj9c", true),
			   new ResultPair("xn--mgbbh1a71e", true),
			   new ResultPair("xn--fpcrj9c3d", true),
			   new ResultPair("xn--gecrj9c", true),
			   new ResultPair("xn--s9brj9c", true),
			   new ResultPair("xn--xkc2dl3a5ee0h", true),
			   new ResultPair("xn--45brj9c", true),
			   new ResultPair("xn--mgba3a4f16a", true),
			   new ResultPair("xn--mgbtx2b", true),
			   new ResultPair("xn--mgbayh7gpa", true),
			   new ResultPair("xn--80ao21a", true),
			   new ResultPair("xn--d1alf", true),
			   new ResultPair("xn--mgbx4cd0ab", true),
			   new ResultPair("xn--l1acc", true),
			   new ResultPair("xn--mgbc0a9azcg", true),
			   new ResultPair("xn--mgb9awbf", true),
			   new ResultPair("xn--mgbai9azgqp6j", true),
			   new ResultPair("xn--ygbi2ammx", true),
			   new ResultPair("xn--wgbl6a", true),
			   new ResultPair("xn--p1ai", true),
			   new ResultPair("xn--mgberp4a5d4ar", true),
			   new ResultPair("xn--90a3ac", true),
			   new ResultPair("xn--yfro4i67o", true),
			   new ResultPair("xn--clchc0ea0b2g2a9gcd", true),
			   new ResultPair("xn--3e0b707e", true),
			   new ResultPair("xn--fzc2c9e2c", true),
			   new ResultPair("xn--xkc2al3hye2a", true),
			   new ResultPair("xn--mgbpl2fh", true),
			   new ResultPair("xn--ogbpf8fl", true),
			   new ResultPair("xn--kprw13d", true),
			   new ResultPair("xn--kpry57d", true),
			   new ResultPair("xn--o3cw4h", true),
			   new ResultPair("xn--pgbs0dh", true),
			   new ResultPair("xn--j1amh", true),
			   new ResultPair("xn--mgbaam7a8h", true),
			   new ResultPair("xn--mgb2ddes", true),
			   new ResultPair("abogado", true),
			   new ResultPair("academy", true),
			   new ResultPair("accountants", true),
			   new ResultPair("active", true),
			   new ResultPair("actor", true),
			   new ResultPair("aero", true),
			   new ResultPair("agency", true),
			   new ResultPair("airforce", true),
			   new ResultPair("archi", true),
			   new ResultPair("army", true),
			   new ResultPair("associates", true),
			   new ResultPair("attorney", true),
			   new ResultPair("auction", true),
			   new ResultPair("audio", true),
			   new ResultPair("autos", true),
			   new ResultPair("band", true),
			   new ResultPair("bar", true),
			   new ResultPair("bargains", true),
			   new ResultPair("beer", true),
			   new ResultPair("best", true),
			   new ResultPair("bid", true),
			   new ResultPair("bike", true),
			   new ResultPair("bio", true),
			   new ResultPair("biz", true),
			   new ResultPair("black", true),
			   new ResultPair("blackfriday", true),
			   new ResultPair("blue", true),
			   new ResultPair("boo", true),
			   new ResultPair("boutique", true),
			   new ResultPair("build", true),
			   new ResultPair("builders", true),
			   new ResultPair("business", true),
			   new ResultPair("buzz", true),
			   new ResultPair("cab", true),
			   new ResultPair("camera", true),
			   new ResultPair("camp", true),
			   new ResultPair("cancerresearch", true),
			   new ResultPair("capital", true),
			   new ResultPair("cards", true),
			   new ResultPair("care", true),
			   new ResultPair("career", true),
			   new ResultPair("careers", true),
			   new ResultPair("casa", true),
			   new ResultPair("cash", true),
			   new ResultPair("catering", true),
			   new ResultPair("center", true),
			   new ResultPair("ceo", true),
			   new ResultPair("channel", true),
			   new ResultPair("cheap", true),
			   new ResultPair("christmas", true),
			   new ResultPair("church", true),
			   new ResultPair("city", true),
			   new ResultPair("claims", true),
			   new ResultPair("cleaning", true),
			   new ResultPair("click", true),
			   new ResultPair("clinic", true),
			   new ResultPair("clothing", true),
			   new ResultPair("club", true),
			   new ResultPair("codes", true),
			   new ResultPair("coffee", true),
			   new ResultPair("college", true),
			   new ResultPair("community", true),
			   new ResultPair("company", true),
			   new ResultPair("computer", true),
			   new ResultPair("condos", true),
			   new ResultPair("construction", true),
			   new ResultPair("consulting", true),
			   new ResultPair("contractors", true),
			   new ResultPair("cooking", true),
			   new ResultPair("cool", true),
			   new ResultPair("coop", true),
			   new ResultPair("country", true),
			   new ResultPair("credit", true),
			   new ResultPair("creditcard", true),
			   new ResultPair("cricket", true),
			   new ResultPair("cruises", true),
			   new ResultPair("dad", true),
			   new ResultPair("dance", true),
			   new ResultPair("dating", true),
			   new ResultPair("day", true),
			   new ResultPair("deals", true),
			   new ResultPair("degree", true),
			   new ResultPair("delivery", true),
			   new ResultPair("democrat", true),
			   new ResultPair("dental", true),
			   new ResultPair("dentist", true),
			   new ResultPair("desi", true),
			   new ResultPair("diamonds", true),
			   new ResultPair("diet", true),
			   new ResultPair("digital", true),
			   new ResultPair("direct", true),
			   new ResultPair("directory", true),
			   new ResultPair("discount", true),
			   new ResultPair("domains", true),
			   new ResultPair("eat", true),
			   new ResultPair("education", true),
			   new ResultPair("email", true),
			   new ResultPair("energy", true),
			   new ResultPair("engineer", true),
			   new ResultPair("engineering", true),
			   new ResultPair("enterprises", true),
			   new ResultPair("equipment", true),
			   new ResultPair("esq", true),
			   new ResultPair("estate", true),
			   new ResultPair("events", true),
			   new ResultPair("exchange", true),
			   new ResultPair("expert", true),
			   new ResultPair("exposed", true),
			   new ResultPair("fail", true),
			   new ResultPair("farm", true),
			   new ResultPair("feedback", true),
			   new ResultPair("finance", true),
			   new ResultPair("financial", true),
			   new ResultPair("fish", true),
			   new ResultPair("fishing", true),
			   new ResultPair("fitness", true),
			   new ResultPair("flights", true),
			   new ResultPair("florist", true),
			   new ResultPair("fly", true),
			   new ResultPair("foo", true),
			   new ResultPair("forsale", true),
			   new ResultPair("foundation", true),
			   new ResultPair("fund", true),
			   new ResultPair("furniture", true),
			   new ResultPair("futbol", true),
			   new ResultPair("gallery", true),
			   new ResultPair("gift", true),
			   new ResultPair("gifts", true),
			   new ResultPair("gives", true),
			   new ResultPair("glass", true),
			   new ResultPair("global", true),
			   new ResultPair("gop", true),
			   new ResultPair("graphics", true),
			   new ResultPair("gratis", true),
			   new ResultPair("green", true),
			   new ResultPair("gripe", true),
			   new ResultPair("guide", true),
			   new ResultPair("guitars", true),
			   new ResultPair("guru", true),
			   new ResultPair("haus", true),
			   new ResultPair("healthcare", true),
			   new ResultPair("help", true),
			   new ResultPair("here", true),
			   new ResultPair("hiphop", true),
			   new ResultPair("hiv", true),
			   new ResultPair("holdings", true),
			   new ResultPair("holiday", true),
			   new ResultPair("homes", true),
			   new ResultPair("horse", true),
			   new ResultPair("host", true),
			   new ResultPair("hosting", true),
			   new ResultPair("house", true),
			   new ResultPair("how", true),
			   new ResultPair("immo", true),
			   new ResultPair("immobilien", true),
			   new ResultPair("industries", true),
			   new ResultPair("info", true),
			   new ResultPair("ing", true),
			   new ResultPair("ink", true),
			   new ResultPair("institute", true),
			   new ResultPair("insure", true),
			   new ResultPair("international", true),
			   new ResultPair("investments", true),
			   new ResultPair("jetzt", true),
			   new ResultPair("jobs", true),
			   new ResultPair("juegos", true),
			   new ResultPair("kaufen", true),
			   new ResultPair("kim", true),
			   new ResultPair("kitchen", true),
			   new ResultPair("land", true),
			   new ResultPair("lawyer", true),
			   new ResultPair("lease", true),
			   new ResultPair("lgbt", true),
			   new ResultPair("life", true),
			   new ResultPair("lighting", true),
			   new ResultPair("limited", true),
			   new ResultPair("limo", true),
			   new ResultPair("link", true),
			   new ResultPair("loans", true),
			   new ResultPair("lotto", true),
			   new ResultPair("ltda", true),
			   new ResultPair("luxe", true),
			   new ResultPair("luxury", true),
			   new ResultPair("maison", true),
			   new ResultPair("management", true),
			   new ResultPair("market", true),
			   new ResultPair("marketing", true),
			   new ResultPair("media", true),
			   new ResultPair("meet", true),
			   new ResultPair("meme", true),
			   new ResultPair("menu", true),
			   new ResultPair("mobi", true),
			   new ResultPair("moda", true),
			   new ResultPair("moe", true),
			   new ResultPair("mortgage", true),
			   new ResultPair("motorcycles", true),
			   new ResultPair("mov", true),
			   new ResultPair("museum", true),
			   new ResultPair("name", true),
			   new ResultPair("navy", true),
			   new ResultPair("network", true),
			   new ResultPair("new", true),
			   new ResultPair("ngo", true),
			   new ResultPair("ninja", true),
			   new ResultPair("ong", true),
			   new ResultPair("onl", true),
			   new ResultPair("ooo", true),
			   new ResultPair("organic", true),
			   new ResultPair("partners", true),
			   new ResultPair("parts", true),
			   new ResultPair("photo", true),
			   new ResultPair("photography", true),
			   new ResultPair("photos", true),
			   new ResultPair("physio", true),
			   new ResultPair("pics", true),
			   new ResultPair("pictures", true),
			   new ResultPair("pink", true),
			   new ResultPair("pizza", true),
			   new ResultPair("place", true),
			   new ResultPair("plumbing", true),
			   new ResultPair("post", true),
			   new ResultPair("press", true),
			   new ResultPair("pro", true),
			   new ResultPair("productions", true),
			   new ResultPair("properties", true),
			   new ResultPair("property", true),
			   new ResultPair("pub", true),
			   new ResultPair("realtor", true),
			   new ResultPair("recipes", true),
			   new ResultPair("red", true),
			   new ResultPair("reise", true),
			   new ResultPair("reisen", true),
			   new ResultPair("ren", true),
			   new ResultPair("rentals", true),
			   new ResultPair("repair", true),
			   new ResultPair("report", true),
			   new ResultPair("republican", true),
			   new ResultPair("rest", true),
			   new ResultPair("restaurant", true),
			   new ResultPair("reviews", true),
			   new ResultPair("rich", true),
			   new ResultPair("rocks", true),
			   new ResultPair("rodeo", true),
			   new ResultPair("sarl", true),
			   new ResultPair("schule", true),
			   new ResultPair("services", true),
			   new ResultPair("sexy", true),
			   new ResultPair("shiksha", true),
			   new ResultPair("shoes", true),
			   new ResultPair("singles", true),
			   new ResultPair("social", true),
			   new ResultPair("solar", true),
			   new ResultPair("solutions", true),
			   new ResultPair("soy", true),
			   new ResultPair("space", true),
			   new ResultPair("supplies", true),
			   new ResultPair("supply", true),
			   new ResultPair("support", true),
			   new ResultPair("surf", true),
			   new ResultPair("surgery", true),
			   new ResultPair("systems", true),
			   new ResultPair("tattoo", true),
			   new ResultPair("tax", true),
			   new ResultPair("technology", true),
			   new ResultPair("tel", true),
			   new ResultPair("tienda", true),
			   new ResultPair("tips", true),
			   new ResultPair("today", true),
			   new ResultPair("tools", true),
			   new ResultPair("top", true),
			   new ResultPair("town", true),
			   new ResultPair("toys", true),
			   new ResultPair("trade", true),
			   new ResultPair("training", true),
			   new ResultPair("travel", true),
			   new ResultPair("university", true),
			   new ResultPair("uno", true),
			   new ResultPair("vacations", true),
			   new ResultPair("ventures", true),
			   new ResultPair("versicherung", true),
			   new ResultPair("vet", true),
			   new ResultPair("viajes", true),
			   new ResultPair("villas", true),
			   new ResultPair("vision", true),
			   new ResultPair("vodka", true),
			   new ResultPair("voting", true),
			   new ResultPair("voyage", true),
			   new ResultPair("wang", true),
			   new ResultPair("watch", true),
			   new ResultPair("webcam", true),
			   new ResultPair("website", true),
			   new ResultPair("wed", true),
			   new ResultPair("wiki", true),
			   new ResultPair("works", true),
			   new ResultPair("world", true),
			   new ResultPair("wtf", true),
			   new ResultPair("xxx", true),
			   new ResultPair("xyz", true),
			   new ResultPair("zone", true),
			   new ResultPair("xn--ngbc5azd", true),
			   new ResultPair("xn--mgbab2bd", true),
			   new ResultPair("xn--q9jyb4c", true),
			   new ResultPair("xn--3ds443g", true),
			   new ResultPair("xn--fiq228c5hs", true),
			   new ResultPair("xn--6frz82g", true),
			   new ResultPair("xn--ses554g", true),
			   new ResultPair("xn--io0a7i", true),
			   new ResultPair("xn--55qx5d", true),
			   new ResultPair("xn--czru2d", true),
			   new ResultPair("xn--nqv7f", true),
			   new ResultPair("xn--6qq986b3xl", true),
			   new ResultPair("xn--czr694b", true),
			   new ResultPair("xn--rhqv96g", true),
			   new ResultPair("xn--d1acj3b", true),
			   new ResultPair("xn--80asehdb", true),
			   new ResultPair("xn--c1avg", true),
			   new ResultPair("xn--80aswg", true),
			   new ResultPair("xn--i1b6b1a6a2e", true),
			   new ResultPair("alsace", true),
			   new ResultPair("asia", true),
			   new ResultPair("bayern", true),
			   new ResultPair("berlin", true),
			   new ResultPair("brussels", true),
			   new ResultPair("budapest", true),
			   new ResultPair("bzh", true),
			   new ResultPair("capetown", true),
			   new ResultPair("cat", true),
			   new ResultPair("cologne", true),
			   new ResultPair("cymru", true),
			   new ResultPair("durban", true),
			   new ResultPair("eus", true),
			   new ResultPair("frl", true),
			   new ResultPair("gal", true),
			   new ResultPair("gent", true),
			   new ResultPair("hamburg", true),
			   new ResultPair("joburg", true),
			   new ResultPair("kiwi", true),
			   new ResultPair("koeln", true),
			   new ResultPair("krd", true),
			   new ResultPair("london", true),
			   new ResultPair("madrid", true),
			   new ResultPair("melbourne", true),
			   new ResultPair("miami", true),
			   new ResultPair("moscow", true),
			   new ResultPair("nagoya", true),
			   new ResultPair("nrw", true),
			   new ResultPair("nyc", true),
			   new ResultPair("okinawa", true),
			   new ResultPair("paris", true),
			   new ResultPair("quebec", true),
			   new ResultPair("ruhr", true),
			   new ResultPair("saarland", true),
			   new ResultPair("scot", true),
			   new ResultPair("taipei", true),
			   new ResultPair("tatar", true),
			   new ResultPair("tirol", true),
			   new ResultPair("tokyo", true),
			   new ResultPair("vegas", true),
			   new ResultPair("vlaanderen", true),
			   new ResultPair("wales", true),
			   new ResultPair("wien", true),
			   new ResultPair("yokohama", true),
			   new ResultPair("xn--80adxhks", true),
			   new ResultPair("allfinanz", true),
			   new ResultPair("android", true),
			   new ResultPair("axa", true),
			   new ResultPair("bloomberg", true),
			   new ResultPair("bmw", true),
			   new ResultPair("bnpparibas", true),
			   new ResultPair("cal", true),
			   new ResultPair("caravan", true),
			   new ResultPair("cern", true),
			   new ResultPair("chrome", true),
			   new ResultPair("citic", true),
			   new ResultPair("crs", true),
			   new ResultPair("cuisinella", true),
			   new ResultPair("dnp", true),
			   new ResultPair("dvag", true),
			   new ResultPair("emerck", true),
			   new ResultPair("firmdale", true),
			   new ResultPair("flsmidth", true),
			   new ResultPair("frogans", true),
			   new ResultPair("gbiz", true),
			   new ResultPair("gle", true),
			   new ResultPair("globo", true),
			   new ResultPair("gmail", true),
			   new ResultPair("gmo", true),
			   new ResultPair("gmx", true),
			   new ResultPair("google", true),
			   new ResultPair("ibm", true),
			   new ResultPair("kred", true),
			   new ResultPair("lacaixa", true),
			   new ResultPair("lds", true),
			   new ResultPair("mango", true),
			   new ResultPair("mini", true),
			   new ResultPair("monash", true),
			   new ResultPair("mormon", true),
			   new ResultPair("neustar", true),
			   new ResultPair("nexus", true),
			   new ResultPair("nhk", true),
			   new ResultPair("nra", true),
			   new ResultPair("otsuka", true),
			   new ResultPair("ovh", true),
			   new ResultPair("sca", true),
			   new ResultPair("scb", true),
			   new ResultPair("tui", true),
			   new ResultPair("yandex", true),
			   new ResultPair("xn--qcka1pmc", true),
			   new ResultPair("xn--flw351e", true),
			   new ResultPair("xn--cg4bki", true),
			   new ResultPair("xn--fiq64b", true),
			   new ResultPair("xn--kgbechtv", true),
			   new ResultPair("xn--hgbk6aj7f53bba", true),
			   new ResultPair("xn--0zwm56d", true),
			   new ResultPair("xn--g6w251d", true),
			   new ResultPair("xn--80akhbyknj4f", true),
			   new ResultPair("xn--11b5bs3a9aj6g", true),
			   new ResultPair("xn--jxalpdlp", true),
			   new ResultPair("xn--9t4b11yi5a", true),
			   new ResultPair("xn--deba0ad", true),
			   new ResultPair("xn--zckzah", true),
			   new ResultPair("xn--hlcj6aya9esc7a", true)
		   };

	   ResultPair [] invalidDomain = {
			   new ResultPair("bad!", false),
			   new ResultPair("123", false)
	   };

	   //Tests scheme partition
	   public void testYourFirstPartition()
	   {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   String thisString = "";
		   boolean result = false;
		   System.out.println("\nTesting Scheme Partition:");
			   
		   for (int n = 0; n < validSchemes.length; n++) {
			   ResultPair testPair = validSchemes[n];
			   //System.out.println(String.format("%-60s", thisString = testPair.item + "://www.google.com/") + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));		   
			   //assertEquals(testPair.item + "://www.google.com/", testPair.valid, result);	
		   }
			   
		   for (int n = 0; n < invalidSchemes.length; n++) {
			   ResultPair testPair = invalidSchemes[n];
			   //System.out.println(String.format("%-60s", thisString = testPair.item + "://www.google.com/") + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));	   
			   //assertEquals(testPair.item + "://www.google.com/", testPair.valid, result);	
		   }
	   }
	  
	   //Tests domain partition
	   public void testYourSecondPartition() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   String thisString = "";
		   boolean result = false;
		   System.out.println("\nTesting Domain Partition:");
		   
		   for (int n = 0; n < validDomain.length; n++) {
			   ResultPair testPair = validDomain[n];
			   //System.out.println(String.format("%-60s", thisString = "http://www.google." + testPair.item) + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));
			   //assertEquals("http://www.google." + testPair.item, testPair.valid, result);
		   }
		   
		   for (int n = 0; n < invalidDomain.length; n++) {
			   ResultPair testPair = invalidDomain[n];
			   //System.out.println(String.format("%-60s", thisString = "http://www.google." + testPair.item) + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));	   
			   //assertEquals("http://www.google." + testPair.item, testPair.valid, result);
		   }
	   }
	   
	   public void testYourThirdPartition(){

		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   Random Rand = new Random();
		   int Port;
		   for(int i=0; i<10000; i++){
			   if(i%10 == 1){
				   int RandInt = Rand.nextInt(1500);
				   int RandInt2 = Rand.nextInt(1500);
				   int RandInt3 = Rand.nextInt(1500);
				   int RandInt4 = Rand.nextInt(1500);
				   String IP = RandInt+"."+RandInt2+"."+RandInt3+"."+RandInt4;
				   Port = Rand.nextInt(100000);
				   String URL = "http://"+IP+":"+Port;

				   /*
				   if(RandInt>255||RandInt2>255||RandInt3>255||RandInt4>255||Port>65535){
					   System.out.println("URL Tested: "+URL+"\t\tTest Value: "+urlVal.isValid(URL)+"\tExpected: False.");
				   }
				   else{
					   System.out.println("URL Tested: "+URL+"\t\tTest Value: "+urlVal.isValid(URL)+"\tExpected: True.");
				   }
				   */
			   }
			   else{
				   int RandInt = Rand.nextInt(255);
				   int RandInt2 = Rand.nextInt(255);
				   int RandInt3 = Rand.nextInt(255);
				   int RandInt4 = Rand.nextInt(255);
				   String IP = RandInt+"."+RandInt2+"."+RandInt3+"."+RandInt4;
				   if(i%4 == 1){
					   Port = Rand.nextInt(100000);
				   }
				   else{
					   Port = Rand.nextInt(65535);
				   }
				   String URL = "http://"+IP+":"+Port;

				   /*
				   if(Port>65535){
					   System.out.println("URL Tested: "+URL+"\t\tTest Value: "+urlVal.isValid(URL)+"\tExpected: False.");
				   }
				   else{
					   System.out.println("URL Tested: "+URL+"\t\tTest Value: "+urlVal.isValid(URL)+"\tExpected: True.");
				   }
				   */
			   }
		   }

	   }
	   
	   public void testIsValid()
	   {
		   String filename = "UrlValidatorTestResults.txt";
		   PrintWriter Writer = null;
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   String thisString = "";
		   boolean result = false;
		   Random Rand = new Random();
		   int Port;
		   
		   try {
			   Writer = new PrintWriter(filename);
		   }
		   catch (FileNotFoundException e){
			   e.printStackTrace();;
		   }
			
		   Writer.println("\nTesting Scheme Partition:");
			   
		   for (int n = 0; n < validSchemes.length; n++) {
			   ResultPair testPair = validSchemes[n];
			   Writer.println(String.format("%-60s", thisString = testPair.item + "://www.google.com/") + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));		   
			   assertEquals(testPair.item + "://www.google.com/", testPair.valid, result);	
		   }
			   
		   for (int n = 0; n < invalidSchemes.length; n++) {
			   ResultPair testPair = invalidSchemes[n];
			   Writer.println(String.format("%-60s", thisString = testPair.item + "://www.google.com/") + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));	   
			   assertEquals(testPair.item + "://www.google.com/", testPair.valid, result);	
		   }
		   
		   Writer.println("\nTesting Domain Partition:");
		   
		   for (int n = 0; n < validDomain.length; n++) {
			   ResultPair testPair = validDomain[n];
			   Writer.println(String.format("%-60s", thisString = "http://www.google." + testPair.item) + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));
			   //assertEquals("http://www.google." + testPair.item, testPair.valid, result);
		   }
		   
		   for (int n = 0; n < invalidDomain.length; n++) {
			   ResultPair testPair = invalidDomain[n];
			   Writer.println(String.format("%-60s", thisString = "http://www.google." + testPair.item) + "Expected: " + testPair.valid + "\tActual: " + (result = urlVal.isValid(thisString)));	   
			   //assertEquals("http://www.google." + testPair.item, testPair.valid, result);
		   }
		   
		   Writer.println("\nTesting Port Partition:");
		   
		   for(int i=0; i<10000; i++){
			   if(i%10 == 1){
				   int RandInt = Rand.nextInt(1500);
				   int RandInt2 = Rand.nextInt(1500);
				   int RandInt3 = Rand.nextInt(1500);
				   int RandInt4 = Rand.nextInt(1500);
				   String IP = RandInt+"."+RandInt2+"."+RandInt3+"."+RandInt4;
				   Port = Rand.nextInt(100000);
				   String URL = "http://"+IP+":"+Port;

				   if(RandInt>255||RandInt2>255||RandInt3>255||RandInt4>255||Port>65535){
					   Writer.println(String.format("%-60s", URL) + "Expected: False" + "\tActual: " + (result = urlVal.isValid(URL)));
				   }
				   else{
					   Writer.println(String.format("%-60s", URL) + "Expected: True" + "\tActual: " + (result = urlVal.isValid(URL)));
				   }
			   }
			   else{
				   int RandInt = Rand.nextInt(255);
				   int RandInt2 = Rand.nextInt(255);
				   int RandInt3 = Rand.nextInt(255);
				   int RandInt4 = Rand.nextInt(255);
				   String IP = RandInt+"."+RandInt2+"."+RandInt3+"."+RandInt4;
				   if(i%4 == 1){
					   Port = Rand.nextInt(100000);
				   }
				   else{
					   Port = Rand.nextInt(65535);
				   }
				   String URL = "http://"+IP+":"+Port;

				   if(Port>65535){
					   Writer.println(String.format("%-60s", URL) + "Expected: False" + "\tActual: " + (result = urlVal.isValid(URL)));
				   }
				   else{
					   Writer.println(String.format("%-60s", URL) + "Expected: True" + "\tActual: " + (result = urlVal.isValid(URL)));
				   }
			   }
		   }
		   Writer.close();
	   }
	   
	   /**
	    * Create set of tests by taking the testUrlXXX arrays and
	    * running through all possible permutations of their combinations.
	    *
	    * @param testObjects Used to create a url.
	    */ 
}