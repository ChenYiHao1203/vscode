#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k,p=0;
ll arr[100005];
struct obj
{
    ll in;
    ll stay; 
    /* data */
}obj[100005];

bool in_tme(int in,int fist){
    if(k+fist<=in){
        return true;
    }else{
        return false;
    }
}

bool out_time(int fist,int in){
   if(fist+k+23<in){
    return false;
   }else{
    return true;
   }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        obj[i].in=temp1;
        obj[i].stay=temp2;
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        int num=0;
        for(int j=0;j<n;j++){
           bool x1=in_tme(obj[j].in,t);
           bool x2=out_time(obj[j].stay,obj[j].in);
           if(x1&&x2){
            num++;
           }
        }
        arr[p++]=num;
    }
    for(int i=0;i<p;i++)
    cout<<arr[i]<<endl;
    return 0;
}