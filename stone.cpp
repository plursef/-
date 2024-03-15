#include <iostream>
using namespace std;
int sum(int i,int j,int *p){int sum=0;
    for(int k=i;k<=j;k++){
        sum += p[k];
    }
    return sum;

}
int main() {
    int n;cin>>n;
    int stn[n];
    for(int &x:stn)
    cin>>x;
    int dp[n][n];
    for(int i=0;i<=n-2;i++){
        dp[i][i+1] = stn[i]+stn[i+1];
            
    }
    for(int i=0;i<=n-1;i++){
        dp[i][i] = 0; 
            
    }
    for(int l=2;l<=n-1;l++){
        for(int i=0;i<=n-1-l;i++){
            dp[i][i+l] = 10000;
            for(int k=1;k<=l;k++)
            dp[i][i+l] = min(dp[i][i+l],dp[i+l-k+1][i+l]+dp[i][i+l-k]+sum(i,i+l,stn));

        }
    }
    cout<<dp[0][n-1];
    return 0;
    
}