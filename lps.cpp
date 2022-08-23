int lps(string s) {
	    // Your code goes here
	    vector<int> lps(s.length());
	    lps[0] = 0;
	   
	    int i=1, len = 0;
	    while(i<s.length()) {
	        if(s[i] == s[len]) {
	            lps[i] = len+1;
	            len++;
	            i++;
	        }
	        else {
	            if(len == 0) {
	                lps[i] = 0;
	                i++;
	            }
	            else {
	                len = lps[len-1];
	            }
	        }
	    }
	    return lps[s.length()-1];
	    
	}