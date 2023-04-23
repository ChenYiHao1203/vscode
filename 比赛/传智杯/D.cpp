#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll arr[100005];

ll zd(ll x){
    ll max=x;
   for(int i=0;i<n;i++){
    if(arr[i]>max)
    max=arr[i];
   }
   return max;
}
ll zx(ll x){
     ll min=x;
   for(int i=0;i<n;i++){
    if(arr[i]<min)
    min=arr[i];
   }
   return min;
}

int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++)
   { int temp;
    cin>>temp;
    arr[i]=temp;
   }
   while(m--){

   }
   
}