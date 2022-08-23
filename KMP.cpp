#include<bits/stdc++.h>
using namespace std;

vector<int> lps;

void constructLPS(string &t, int m) {
    lps[0] = 0;
    int len = 0;
    int i = 1;
    
    while(i<m) {
        if(t[i] == t[len]) {
            lps[i] = len+1;
            len++;
            i++;
        }
        else {
            if(len==0)
                lps[i++] = 0;
            else 
                len = lps[len-1];
        }
    }
}

int main() {
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();

    lps = vector<int> (m);
    constructLPS(t,m);

    int i=0, j=0;
    int occur = 0;

    while(i<n) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }
        
        if(j==m) {
            occur++;
            j = lps[j-1];
        }

        else if(i<n && s[i]!=t[j]) {
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }
    }
    cout<<occur<<"\n";

    return 0;
}