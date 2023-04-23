#include<bits/stdc++.h>
using namespace std;
int n,temp,arr[1050];
double mid,fc,fd;

void pingjun(int arr[]){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    mid=sum/n;

}

void fangcha(int arr[]){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=pow(arr[i]-mid,2);
    }
    fc=(double)sum/n;
}

void out(int arr[]){
    double t;
    for (int i = 0; i < n; i++)
    {
        t=(arr[i]-mid)/pow(fc,0.5);
        printf("%lf\n",t);
    }
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>temp;
       arr[i]=temp;
    }
    pingjun(arr);
    fangcha(arr);
    out(arr);
    return 0;
}