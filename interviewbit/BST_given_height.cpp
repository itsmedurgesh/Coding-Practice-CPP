#include <iostream>
#include <vector>

#define MOD 1000000007

void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD;}

// this is nCr MOD table
void build_choose(int N, vector<vector<int>> &choose){
   choose[0][0] = 1;
   for(int i = 1; i <= 2*N; ++i){
        choose[i][0] = 1;
        for(int j=1; j<= i; ++j){
            choose[i][j] = choose[i][j-1];
            add(choose[i][j], choose[i-1][j-1]);
        }
   }
}

int rec(int n, int h, auto &choose, auto &dp){
    if(n <= 1) return h == 0;
    if(h < 0) return 0;
    int &ret = dp[n][h];
    if(ret != -1) return ret;

    ret = 0;
    int x, y;

    for(int i = 1; i <=n; ++i){
        x = i-1;
        y = n-x-1;

        int sum1 = 0, sum2 = 0, ret1 = 0;
        
        for(int j = 0; j < h-1; ++j){
            add(sum1, rec(x, j));
            add(sum2, rec(y, j));
        }

        add(ret1, (LL)sum1*rec(y, h-1)%MOD);
        add(ret1, (LL)sum2*rec(x, h-1)%MOD);
        add(ret1, (LL)(rec(x,h-1)*rec(y,h-1))%MOD);
        ret1  = ((LL)ret1 * (LL)choose[x+y][y])%MOD;
        add(ret, ret1);
    }

    return ret;
}
