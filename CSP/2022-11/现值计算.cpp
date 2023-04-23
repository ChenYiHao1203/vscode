#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double n,y;
vector <double>arr;

int main(){
  cin>>n>>y;
  int temp=n+1;
  while (temp--)
  {
    int t;
    cin>>t;
    arr.push_back(t);
    /* code */
  }
  double sum=arr[0];
  for(int i=1;i<=n+1;i++){
    sum+=(arr[i]/pow(1+y,i));
  }

  printf("%.3f",sum);
return 0;

}