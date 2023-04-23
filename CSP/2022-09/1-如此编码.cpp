#include<bits/stdc++.h>
using namespace std;

//n道单向选择题 ，第i题又ai个选项，正确项有bi个
int n;//题目数量
long long c[25],b[25],m;
#define N 1000


int main(){
    cin>>n>>m;
    int a[N],temp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        a[i]=temp;
    }
    for(int i=1;i<=n;i++)
    c[i]=1;//初始化
    c[0]=1;
    //计算c[i]
    for(int i=1;i<=n;i++)
     for(int j=1;j<=i;j++)
       c[i]=c[i]*a[j];
    long long sum=0;
    for(int i=1;i<=n;i++)//c[i]
    {
      for(int j=0;j<i;j++)
      {
        sum=c[j]*b[j+1];//求出前半部分
      }
        long long last=m%c[i]-sum;//得到前半部分
        b[i]=last/c[i-1];//得出b[i]
        sum=0;//归零
    }
    for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
    return 0;
    
}