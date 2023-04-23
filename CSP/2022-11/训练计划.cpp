#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,out=0,huan;
void find_yl(int num); 
int find_over(int k);
int emp,k1=0,k2=0;

struct data
{
    int yl;
    int day;
    int early;
    int last;
    bool is;//标记是否为可参考初始点
}datas[105];

void wancheng(int x){
    if(datas[x].early+datas[x].day-1<=n)
    out++;

}

int find_over(int k){
    int res;
    if(datas[k].is==false){//如果此任务还未开始,就需要递归求父节点的父节点
       res=find_over(datas[k].yl)+datas[k].day-1;

    }else{
    res=datas[k].early+datas[k].day-1;
    }
    return res;

}

void find_yl(int num){
  int over_day=find_over(datas[num].yl);
  datas[num].early=over_day+1;
  datas[num].is=true;

}

int main(){
    cin>>n>>m;
    int s=m;
    while(m--){
        cin>>emp;
        datas[k1++].yl=emp;
    }
    m=s;
    while (m--)
    {
        cin>>emp;
        datas[k2++].day=emp;
    }
    for(int i=0;i<m;i++){//没有依赖的第一天开始
        if(datas[i].yl==0){
            datas[i].early=1;
            datas[i].is=true;//标志任务已开始
        }
    }
    for(int i=0;i<m;i++){//若有依赖，则进行依赖查找
        if(datas[i].yl!=0){
            find_yl(datas[i].yl);
        }
    }
    for(int i=0;i<m;i++){//判定是否都能完成
        wancheng(i);
    }
    if(out<m){//判定是否输出第2行
     for(int i=0;i<m;i++)
     cout<<datas[i].early<<" ";
    }else{
        for(int i=0;i<m;i++){//输出第1行
                if(i==m-1)
            cout<<datas[i].early<<endl;
            else
            cout<<datas[i].early<<" ";
        
        }
        for(int i=0;i<m;i++){//输出第2行
             if(i==m-1)
              cout<<(11-datas[i].day);
              else
              {
                /* code */
                cout<<(11-datas[i].day)<<" ";
              }         
        }
    }
}
