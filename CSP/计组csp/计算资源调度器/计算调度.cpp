#include<bits/stdc++.h>
using namespace std;
int n,m,g;

//计算节点的结构体定义
struct node{
    int id;//编号，初始化过程中
    int num;//计算节点的任务数
    int belong;//所属区
    set<int> yy;//反亲和性时使用，不重复，表示某计算节点的应用种类

}nodes[1050];
map<int,int>region[1050];//区- - >任务亲和性，可用区是否有指定任务
int cnt[1050];//判定数组，是否符合条件
int l,f,a,na,pa,paa,paar;//所需要的参数
//最后就是看这3次判断是否都满cnt==3
//或者当paar=0时，尽量满足cnt==2
//1.初次判断
void judge_na(int na){
    if(na==0){
        for(int i=1;i<=n;i++)
        cnt[i]++;//每个区都可用++
    }else{
        for(int i=1;i<=n;i++){
            if(nodes[i].belong==na){
                //在指定区内
                cnt[i]++;
            }
        }
    }

}
void judge_pa(int pa){//亲和性
    if(pa==0){
        for(int i=1;i<=n;i++)
        cnt[i]++;//每个区都可用++
    }else{
        for(int i=1;i<=n;i++){
            if(region[nodes[i].belong][pa]==1){//此区存在该应用任务，既满足条件
                //在指定区内
                cnt[i]++;
            }
        }
    }
}
void judge_paa(int paa){//非亲和性
    if(paa==0){
        for(int i=1;i<=n;i++)
        cnt[i]++;//每个区都可用++
    }else{
        for(int i=1;i<=n;i++){
            if(nodes[i].yy.count(paa)==0){//此区不存在“躲避”应用任务，既满足条件
                //在指定区内的任务count==0
                cnt[i]++;
            }
        }
    }
}
int get_min(vector<node> group){
    int cur_min=group[0].id;
    for(int i=1;i<=group.size();i++){
        if(nodes[cur_min].num>group[i].num){
           cur_min=group[i].id;
        }else if(nodes[cur_min].num>group[i].num&&nodes[cur_min].id>group[i].id){
            //选择最小的id
            cur_min=group[i].id;
        }
    }
    return cur_min;
}
void work(int a,int na,int pa,int paa,int paar){
    //过滤
    judge_na(na);
    judge_pa(pa);
    judge_paa(paa);
    //得到过滤后的节点
    vector<node> group;//输出的容器,node型
    for(int i=1;i<=n;i++){
        if(cnt[i]==3){
            //全部通过
            group.push_back(nodes[i]);
        }
    }//for检测
    //排序阶段
    if(group.size()){
        //有node,则开始排序
        //已经筛出来符合的计算节点，排序得到想要的值
        int cur=get_min(group);//得到的最小符合下标的值，计算节点
        cout<<cur<<" ";
        //“善后”
        nodes[cur].yy.insert(a);//任务应用a
        nodes[cur].num++;//数量增加
        region[nodes[cur].belong][a]=1;//补充可行区，下一次循环的亲和性判断
        return;
    }//判断正常e
    else if(!group.size()&&paa&&!paar){//尽量满足
    memset(cnt,0,sizeof(cnt));//重新0
    judge_na(na);
    judge_pa(pa);
    //此时不需要判断非亲和性
    vector<node>group;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2){
            //全部通过
            group.push_back(nodes[i]);
        }
    }//for检测
    if(group.size()){
        int cur=get_min(group);//得到的最小符合下标的值，计算节点
        cout<<cur<<" ";
        //“善后”
        nodes[cur].yy.insert(a);//任务应用a
        nodes[cur].num++;//数量增加
        region[nodes[cur].belong][a]=1;//补充可行区，下一次循环的亲和性判断
        return;
       }
    }//else if
    //如果没有
    cout<<0<<" ";
}

int main(){
    cin>>n>>m;//首先输入计算节点数目和区的数目
    for(int i=1;i<=n;i++){
        cin>>l;
        nodes[i].id=i;
        nodes[i].belong=l;//设定区
    }
    cin>>g;//g行
    while(g--){
        cin>>f>>a>>na>>pa>>paa>>paar;
        while (f--)//每一个任务应用执行f次
        {
            work(a,na,pa,paa,paar);
        }
        
    }
}