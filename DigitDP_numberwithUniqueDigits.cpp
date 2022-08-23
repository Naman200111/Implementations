// https://leetcode.com/problems/count-numbers-with-unique-digits/
#define ll long long int
class Solution {
public:
    ll dp[12][(1<<10)][2];
    ll helper(string s, ll mask, int tight, int pos) {
        if(pos == s.length()) {
            if(mask != 0) 
                return 1;
            return 0;
        }
        
        if(dp[pos][mask][tight]!=-1)
            return dp[pos][mask][tight];
    
        ll ans = 0;
        if(tight) {
            for(int i=0; i<=s[pos]-'0'; i++) {
                if((1<<i)&mask) {
                    // already taken digit
                    continue;
                }
                else {
                    ll nm = ((mask==0 && i==0) ? 0 : mask|(1<<i));
                    if(i == s[pos]-'0')
                        ans += helper(s,nm,1,pos+1);
                    else 
                        ans += helper(s,nm,0,pos+1);
                }
            }
        }
        else {
            for(int i=0; i<=9; i++) {
                if((1<<i)&mask) {
                    // already taken digit
                    continue;
                }
                else {
                    ll nm = ((mask==0 && i==0) ? 0 : mask|(1<<i));
                    ans += helper(s,nm,0,pos+1);
                }
            }
        }
        return dp[pos][mask][tight] = ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        ll r = 1;
        for(int i=0; i<n; i++)
            r = r*10;
        r--;
        memset(dp,-1,sizeof(dp));
        ll ans = helper(to_string(r),0,1,0);
        return ans+1;
    }
};