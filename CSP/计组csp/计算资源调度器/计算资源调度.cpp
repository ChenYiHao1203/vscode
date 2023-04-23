#include<bits/stdc++.h>
using namespace std;
int n,m,g;

struct node{
    int id;//所属编号
    int num;//应用任务数
    int belong;//所属区归属地
    set<int> yy;//已定义计算任务，反亲和性,不能重复
}nodes[1050];

map<int,int>region[1050];///可用区是否有指定应用，亲和性
//区 - - > 任务
int cnt[1050];//区限制++,扫描所在规定区可用的计算节点
int l,f,a,na,pa,paa,paar;

void judge_na(int na){
    if(na==0){
    for(int i=1;i<=n;i++)
      cnt[i]++;//所有计算节点++
    }else{
        for(int i=1;i<=n;i++){
            if(nodes[i].belong==na){
                //如果其在所需要的区内
                cnt[i]++;
            }
        }
    }
}
void judge_pa(int pa){
    if(pa==0){//若没要求
    for(int i=1;i<=n;i++)
     cnt[i]++;
    }else{
        for(int i=1;i<=n;i++){
            if(region[nodes[i].belong][pa]==1)//存在,如果那个区有这个任务
            cnt[i]++;
        }
    }

}

void judge_paa(int paa){
    if(paa==0){
    for(int i=1;i<=n;i++)
     cnt[i]++;
    }else{
        for(int i=1;i<=n;i++){
            if(nodes[i].yy.count(paa)==0)//存在,如果那个区有这个任务
            //count_paa，不能和其计算节点运行
            cnt[i]++;
        }
    }
}

int get_min(vector<node> group){
    int min_cur=group[0].id;//初始化
    for(int i=1;i<=group.size();i++){
        if(nodes[min_cur].num>group[i].num){
            min_cur=group[i].id;
        }else if(nodes[min_cur].num==group[i].num&&nodes[min_cur].id>group[i].id){
            //选择id小的
            min_cur=group[i].id;
        }
    }
    return min_cur;//返回编号
}

void work(int a,int na,int pa,int paa,int paar){
    //过滤
    judge_na(na);
    judge_pa(pa);
    judge_paa(paa);
    //过滤后存放所有节点
    vector<node>group;//设计成node型
    for(int i=1;i<=n;i++){
        if(cnt[i]==3)//同时满足
        {
            group.push_back(nodes[i]);
        }
    }
    //排序阶段
    if(group.size()){
        //有node，则开始排序
        int temp=group.size();
        int cur=get_min(group);//得到最小的下标的计算节点
        cout<<cur<<" ";
        //“善后”
        nodes[cur].yy.insert(a);//将应用编号a发放入计算节点
        nodes[cur].num++;//节点用应用任务数+1，后面排序
        region[nodes[cur].belong][a]=1;//补充可行区
        //因为这个可行区只有元任务，需要添加此任务，后续铺垫
        return;
    }else if(group.size()==0&&paa&&!paar){//都不满足,此时需要尽量满足
    memset(cnt,0,sizeof(cnt));//置空重新计算
    judge_na(na);
    judge_pa(pa);
    //此时只需要判断1和2
    vector<node> group;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2){
            group.push_back(nodes[i]);
        }
    }
     if(group.size()){
        //有node，则开始排序
        int cur=get_min(group);//得到最小的下标的计算节点
        cout<<cur<<" ";
        nodes[cur].yy.insert(a);//将应用编号a发放入计算节点
        nodes[cur].num++;//节点用应用任务数+1，后面排序
        region[nodes[cur].belong][a]=1;//补充可行区
        //因为这个可行区只有元任务，需要添加此任务，后续铺垫
        return;
    }
   }//else if
   //如果都没有
   cout<<0<<" ";
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l;
        nodes[i].id=i;//设置编号
        nodes[i].belong=l;//设置计算节点的区域
    }
    cin>>g;//g行
    while(g--){
        cin>>f>>a>>na>>pa>>paa>>paar;
        while (f--)//f个计算任务
        {
            work(a,na,pa,paa,paar); /* code */
        }
        cout<<endl;//换行
    }//g
    return 0;
}//main