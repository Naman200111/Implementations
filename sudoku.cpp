#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

bool canPlace(vector<vector<char>> &grid, int r, int c, int n, char no)
{
    for(int i=0; i<n; i++) {
        if(grid[i][c] == no) {
            return false;
        }
    }

    for(int j=0; j<n; j++) {
        if(grid[r][j] == no) {
            return false;
        }
    }

    int sr=(r/4)*4;
    int sc=(c/4)*4;

    for(int x=sr; x<sr+4; x++) {
        for(int y=sc; y<sc+4; y++) {
            if(grid[x][y] == no)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &grid, int n)
{
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(grid[i][j] == 'X') {
                break;
            }
        }
        if(j<n)
            break;
    }

    if(i==n && j==n)
        return true;

    vector<char> v {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int k=0; k<16; k++) {
        cout<<i<<" "<<j<<" "<<k<<endl;
        if(canPlace(grid, i, j, n, v[k])) 
        {
            grid[i][j] = v[k];
            if(solve(grid, n))
                return true;
            grid[i][j] = 'X';
        }
    }
    return false;
}

int32_t main()
{
    int n;
    cin>>n;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }

    cout<<endl;
    bool ans = solve(grid, n);

    if(ans == false)
        cout<<"Nhi Hua"<<endl;

    else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}




/*

16
X E X X X X X 4 1 C X A 9 X X X
X C 6 8 X X B X X 9 X X X X 1 X
7 X X D X 1 5 X 3 X X X 2 X A X
3 X X X E 9 X X 5 X X X X 0 X X
X X X X X X X X A 7 X X X 5 4 X
6 4 X X X X C X X X 5 1 D X X E
X 2 5 X X X X X X F C B X X X X
X D C X X 5 X B 4 3 2 X X X 0 A
4 9 X X X 8 0 5 E X 7 X X B F X
X X X X 3 2 4 X X X X X X A 8 X
A X X 2 9 6 X X X 4 X X X X E 3
X 1 8 X X X 7 D X X X X X X X X 
X X 4 X X X X C X X F 7 X X X 6
X 0 X E X X X 3 X B 4 X F X X 7
X 6 X X X X 1 X X D X X 4 2 9 X 
X X X 9 8 X D F 2 X X X X X 3 X


9
3 0 0 0 0 2 0 4 0 
5 8 0 0 0 0 0 0 0
0 7 4 0 0 5 0 2 0
0 0 0 0 1 0 8 0 5 
0 0 0 7 0 0 0 0 0 
0 9 1 0 0 0 3 0 0 
6 5 3 0 0 0 0 0 4
0 0 0 0 4 0 0 0 7
0 0 0 9 8 0 0 0 0


gfg
9
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0


lvl2
9
0 0 5 0 0 7 0 0 0
0 0 0 0 0 0 9 0 2
7 0 1 2 0 9 6 0 0 
9 5 0 0 8 0 3 0 0
0 2 0 0 3 6 0 0 0
0 0 7 0 0 5 0 1 0
0 0 0 6 0 0 0 5 9
5 3 0 0 9 0 0 0 0
0 0 0 1 5 0 2 6 0 

*/