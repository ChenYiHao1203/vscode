#include<bits/stdc++.h>
using namespace std;

int n,x;//图书的数量 
int maxn;
int minx=maxn;
vector<int>book;
int visit[35]={0};
void DFS(int sum,int t){
if(sum>=x){
    minx=min(minx,sum);
    return;
}
for(int i=t;i<book.size();i++){//深度优先遍历
    if(visit[i]==0){
        visit[i]=1;
        DFS(sum+book[i],i);
        visit[i]=0;//重置

    }
}

}


int main(){
    cin>>n>>x;
    int y;
    for(int i=0;i<n;i++){
        cin>>y;
        book.push_back(y);
    }
    DFS(0,0);
    cout<<minx<<endl;
    return 0;
}