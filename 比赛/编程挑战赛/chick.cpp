#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<algorithm>


typedef long long ll;
ll step,cost,wash,keep;
ll total=cost+wash;
const int nn=1000;
int num_guo=0;

struct guo{
    int flag;
    int time;
}gu[nn];

vector<guo> shiyong;

int time_out(int nextPerid){
    int size=shiyong.size();
    for(int i=0;i<size;i++){
        if(shiyong[i].time+total<nextPerid){
            shiyong[i].flag=0;
            vector<guo>::iterator it=shiyong.begin()+i; 
            shiyong.erase(it);
        }
    }
}


int judge(int t,int num){
    for(int i=0;i<nn;i++)
    {
        if(!gu[i].flag){
            shiyong.push_back(gu[i]);
            gu[i].flag=1;
            gu[i].time=t;
            num--;
        }
        if(!num)
        break;//如果烤鸡都满足,则退出
    }

}

int max_num(){
    if(shiyong.size()>num_guo)
    num_guo=shiyong.size();
}
int main(){
    
    cin>>step>>cost>>keep>>wash;
    ll time,num;
    while(step--){
        cin>>time>>num;
        time_out(time);//每次执行前 清楚vector中 已经用完的锅
        judge(time,num);//判断哪些锅是否入队列
        max_num();//更新最大值
    }
    cout<<num_guo<<endl;
    return 0;
    
}