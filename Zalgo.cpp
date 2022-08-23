#include<bits/stdc++.h>
using namespace std;
// ababcababe
vector<int> z;

void findZarray(string &s) {
    int n = s.length();
    int l = 0, r = 0;
    for(int i=1; i<n; i++) {
        if(i<=r) {
            // in range
            z[i] = min(r-i+1, z[i-l]);
        }

        while(s[i+z[i]] == s[z[i]]) 
            z[i]++;

        if(i+z[i]-1 > r) {
            // new bigger range answer is now available so increase the range
            l = i;
            r = i+z[i]-1;
        }
    }
}

int main() {
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();

    string str = t + "#" + s;
    z = vector<int> (str.length());
    findZarray(str);

    int occur = 0;
    for(int i=0; i<str.length(); i++) {
        if(z[i] == m) {
            occur++;
        }
    }
    cout<<occur<<"\n";

    return 0;
}