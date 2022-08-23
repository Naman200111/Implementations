#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of x and places is y

const int N = 10, M = 10;
vector<vector<int>> table(N, vector<int> (M));

void build(vector<int> &arr) {
    // base case
    // i,0 => starting pt is i and length is 2^0 = 1
    for(int i=0; i<N; i++) 
        table[i][0] = arr[i];

    for(int j=1; j<M; j++) {
        for(int i=0; i+(1<<j)-1<N; i++) {
            // starting pt is i and length is 2^j
            table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            // cout<<table[i][j]<<" y\n";
        }
    }
}

// int max_query(int l, int r, vector<int> &arr) {
//     if(l==r)
//         return arr[l];
//     int len = r-l+1;
//     int place=0;
//     while(len) {
//         len = len>>1;
//         place++;
//     }
//     place--;
//     int val = (1<<place);
//     if(val == r-l+1) {
//         // power of 2
//         place--;
//         return max(table[l][place], table[r-(1<<place)+1][place]);
//     }
//     else {
//         // lowerpower of 2 
//         return max(table[l][place], table[r-(1<<place)+1][place]);
//     }
// }

// 4 6 => 3 => 011 => (4,0)+(5)
// int range_sum(int l, int r, vector<int> &arr) {
//     if(l==r)
//         return arr[l];

//     int len = r-l+1;
//     int place=0, ans=0;
//     while(len) {
//         if(len&1) {
//             ans += (table[l][place]+range_sum(l+(1<<place), r,arr));
//         }
//         // len = len>>1;
//         // place++;
//         break;
//     }
//     return ans;
    // place--;
    // int val = (1<<place);
    // if(val == r-l+1) {
    //     // power of 2
    //     place--;
    //     return (table[l][place]+table[r-(1<<place)+1][place]);
    // }
    // else {
    //     // lowerpower of 2 
    //     return (table[l][place]+table[r-(1<<place)+1][place]);
    // }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // keep up the good work
    // sparse table (N*M)
    // sparse table helps to find out the answer for query in O(1), when no update is required 
    // also the task should be idempotent which means overlapping does not cause any problem
    // i.e. if ans(1,7) = ans (ans(1,5) and ans(3,7) )

    //                 0 1 2 3 4 5 6 7 8 9
    vector<int> array {2,6,4,7,1,3,8,4,9,5};

    build(array);


    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++) {
    //         cout<<i<<" "<<j<<" "<<table[i][j]<<"\n";
    //     }
    // }
    // max query
    // 2,7 => 2,2   and  4,
    // cout<<max_query(array)<<"\n";

    
    // range sum query 
    cout<<range_sum(4,6,array)<<"\n";



    return 0;
}