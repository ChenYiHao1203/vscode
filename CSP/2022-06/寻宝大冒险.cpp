#include<bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,L,S;
vector<pair<int,int>> v;
int m[60][60];
int k=0;

bool check(int x,int y){
    if(x+S+1>L||y+S+1>L)
    return false;
    else
    return true;
}
int main(){
    cin>>n>>L>>S;
    memset(m,0,sizeof(m));
    while(n--){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});

    }
    for(int i=S;i>=0;i--)
     for(int j=0;j<=S;j++){
        cin>>m[i][j];
     }
     int res=0;
     for(int i=0;i<n;i++){
        if(check(v[i].first,v[i].second)){
            res++;
        };
     }
     cout<<res;
     return 0;
}