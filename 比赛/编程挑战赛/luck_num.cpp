#include <bits/stdc++.h>
using namespace std;
int cnt=0;

int judge(int n,int k){
    int flag=1;
    while(n>0){
        int temp=n%10;
        if(k==temp){
            flag=0;
        }
        n=n/10;
    }
    return flag;

}
void Prime(int n,int s)
{
    bool* isPrimes = new bool[n+1];
    for(int i=2;i<=n;++i)
    {
        if(judge(n,s))
        isPrimes[i] = true;
    }//创建一个与传入N 相同 大小的bool型数组30

    if(s!=2)
    isPrimes[2] = true;
    for(int j=2;j<=n;++j)
    {
        if(isPrimes[j]==true)
        {
            for(int m=2;j*m<=n;++m)
            {
                isPrimes[j*m] = false;
            }//这里 j会从2~n   j*m 的数就不是素数 把对应的数组的数组 去掉
        }

    }
    for(int k=2;k<=n;++k)
    {
        if(isPrimes[k]==true)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    delete [] isPrimes;
}
int main()
{
    int num,k;
    cin>>num>>k;
    Prime(num,k);
    return 0;
}