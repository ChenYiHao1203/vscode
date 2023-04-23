#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define maxn 300010
using namespace std;

int n,v,Max,sum,x;//max为最大价值
int main(){
    cin>>n>>x;
    int c[n+1];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sum+=c[i];
    }
    v=sum-x;//不超过x的最大值，相当于背包空间
    int dp[n+1][v+1];
    memset(dp,0,sizeof(dp));//dp初始化为0
    for(int i=1;i<=n;i++){//对n个物品选择
      for(int j=1;j<=v;j++){
        //穷尽背包空间
        if(j-c[i]>=0){
            //背包还有空间
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+c[i]);
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
        if(dp[i][j]>Max)//更新
        {
            Max=dp[i][j];
        }
      }

    }

cout<<sum-Max<<endl;
return 0;


}