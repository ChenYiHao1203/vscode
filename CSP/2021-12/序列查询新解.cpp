#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
ll n,N;
//floor()向下取整
//ceil()向上取整
//roound()四舍五入取整
ll arr[100005]={0};
ll f[100005],g[100005];

int main(){
    cin>>n>>N;
    for(int i=1;i<=n;i++){
        ll tem;
        cin>>tem;
        arr[i]=tem;
    }
    ll err=0;
    for(int i=0;i<N;i++){
        ll r;
        r=floor(N/i+1);
        g[i]=floor(i/r);
        f[i]=round((n+1)*i/N);
        err+=abs(g[i]-f[i]);

    }
    cout<<err<<endl;
    return 0;
}

