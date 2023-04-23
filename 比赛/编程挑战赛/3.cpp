#include<iostream>
#include<cmath>
using namespace std;
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
int a,cnt;
int main()
{
   
    int num;
    cin >> num >> a;
    for(int n=1;n<=num;n++){
         int flag=1;
      for(int i = 2; i <= sqrt(n); i++)
      {
        if(n%i==0)
        {
            flag=0;
            break;
        }
      }
   
       if(judge(n,a)&&flag){
        cnt++;
        }

    }
    cout<<cnt<<endl;
    return 0;
}
