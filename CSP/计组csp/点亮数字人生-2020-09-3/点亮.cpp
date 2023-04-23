#include<map>
#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<string>
using namespace std;
//这个题考查 图的构建，拓扑排序，计算值，逻辑运算
//数字电路抽象出来就是有向图，中间过程是模拟作为边的
//入度点使用 位计算 其值作为该点的权值，最后输出

//步骤
//构建图（临接表，邻接矩阵）【构建的时候，计算每个点的入读】
//存储需要测试的输入，输出数据
//使用拓扑排序 来判断是否 电路（有向图）是否成环
//使用类似于拓扑排序的方法来 从前向后依次计算 每个元器件（点）得数值

int Q;        //问题的个数
int M,N;      //整个电路的输入和器件个数
map<string, int>Mp;  //做一个映射，把元器件得 逻辑符号转换为数字，方便处理
int S;        //电路运行次数
/**@brief 建立string 到 int的映射
 */
void Map_init(){
    Mp["NOT"]=0;
    Mp["AND"] = 1;
    Mp["OR"] = 2;
    Mp["XOR"] = 3;
    Mp["NAND"] = 4;
    Mp["NOR"] = 5;
}
//对于每个元器件来说，一个元器件得输入有2种情况，1.输入信号 
//2.another的输出结果作为输入端
struct Node
{ /* data */
    int func;    //逻辑功能，也就是刚刚转换好的func
    vector<int> In;//第In[i]个输入信号连接到该器件输入端
    vector<int> Out;//第Out[i]个器件的输出连接到该器件的输入端

}Dev[505];//max=500
// 10005次运行- Smax 
int Input[10005][505]; //第i次电路运行的第j个输入信号状态(0/1),及时性
int Ind[505];          //第i个器件有Ind[i]个输入 是其他器件的输出,记录数字次数
//以上2个搭配使用，拓扑排序用
int ans[505];          //第i个器件的运行结果Ans[i],导向性

vector<int> e[505];//每个器件的输出,与上面的Input[][]搭配使用
int getNum(int pos,char *str){
    int num=0;
    int len=strlen(str);
    while (pos<len)
    {
        num=num*10+str[pos]-'0'; //直接从1开始,跳过'I'
        ++pos;
        /* code */
    }
    return num;
}
//写拓扑排序时，考虑如何去判断 什么事 回路 的要求
//拓扑排序
bool topolog(){
    //用拓扑排序
    queue<int> Que;//存放“输入全是整个电路的输入”的器件队列
    for(int i=1;i<=N;i++){
        //每个器件，先从“进”考虑
        if(!Ind[i]){//如果该器件的输入 全是 整个电路的输入
        Que.push(i);//把器件i放入队列中
        }
    }
    int cnt=0;
    //从出考虑
    while (!Que.empty())//遍历
    {
        int u=Que.front();//访问对首元素
        Que.pop();//对首元素出列
        ++cnt;   // 递增 与 后面 N比较
        int cnt=e[u].size();//该器件的输出个苏数
        for(int i=0;i<cnt;i++){//遍历该器件每个输出端口连接的下一个器件
        int v=e[u][i];// 着重强调,第i个输出连接的器件
        if(!(--Ind[v]))
        Que.push(v);//若非信号输入 的输出端 "输入" 变成0时入队

        }
        
    }
    return cnt==N;//判断是否和 器件数量 相等
    
}

int opera(vector<int> q,int func){
    //参考 map表去得到func
    if(func==0) return !q[0];  // NOT
    else{
        int cnt = q.size();
        int r = q[0];
        if(func==1){  // AND
            for(int i=1;i<cnt;++i) r &= q[i];
            return r;
        }
        else if(func==2){  // OR
            for(int i=1;i<cnt;++i) r |= q[i];
            return r;
        }
        else if(func==3){  // XOR
            for(int i=1;i<cnt;++i) r ^= q[i];
            return r;
        }
        else if(func==4){  // NAND
            for(int i=1;i<cnt;++i) r &= q[i];
            return !r;
        }
        for(int i=1;i<cnt;++i) r |= q[i];  // NOR
        return !r; 
    }
 
}


int dfs(int s,int u){//第s次运行电路，要输出器件u的运行结果 - - -> i  +  num
if(ans[u]!=-1){
    return ans[u];//第u个器件已经运行出结果
}
int cnt=Dev[u].In.size();//有多少个电路输入信号 器件u的输入端
vector<int> t;
for(int i=0;i<cnt;i++){//遍历每个输入信号
int temp=Dev[u].In[i];//第i个输入信号输入到端口u
t.push_back(Input[s][temp]);//保存每个 op

}
cnt=Dev[u].Out.size();///有多少个其他器件输出连接到器件u的输入端
for(int i=0;i<cnt;i++){
    t.push_back(dfs(s,Dev[u].func));//递归 - - 第s次，把func当作下一节点的器件
    //不断递归
}
return ans[u]=opera(t,Dev[u].func);


}


int main(){
    Map_init();//初始化Map
    char str[10];
    cin>>Q;//q个问题
    while (Q--)
    {
        cin>>M>>N;//整个电路的 输入 和 器件个数
        //因为考虑到当测试点3-10，Qmax发生改变，需要将每个问题的器件初始化
        for(int i=1;i<=N;i++){
            //清空输出端
            e[i].clear();//清空所有元素
            Ind[i]=0;
            //清空输入端
            Dev[i].In.clear();
            Dev[i].Out.clear();
        }
        /* code */
        //对于每个器件
        for(int i=1;i<=N;i++){
            cin>>str;
            Dev[i].func=Mp[str];//转换成对应的数字
            int k;
            cin>>k;//输入数量
            for(int j=0;j<k;j++){//即分别输入I(x)和O(x)
                cin>>str;
                int num= getNum(1,str);//从字符串中得到数字,写一个getNum函数
                //第num输入信号
                if(str[0]=='I')
                Dev[i].In.push_back(num);//作为 输入信号 去进行 num的输入信号 输入到器件 i上
                //如果不是I[x]而是O[x]
                else{
                    e[num].push_back(i);//第num个器件的输出 连接到 第i个器件上，大循环i
                    Ind[i]++;//记录++一次输入值得情况
                    //这里为什么要用  e[]和Ind[]  去表达这个结果,后面有待考证
                    Dev[i].Out.push_back(num);// 第num个器件的输出连接到第i个器件输入端
                }

            }

        }
        //上一阶段 结构构造成功
        //下一阶段 输入
        cin>>S;//电路运行次数
        //S行为输入描述,什么时候用 i=0,i=1
        for(int i=0;i<S;i++){ //S次
            for(int j=1;j<=M;j++){ //每次输入信号
            //例如例题1中给的 3
            cin>>Input[i][j];//各个输入信号器件状态
            // 各个输入信号（按编号排列）的状态（0或1）
            }
        }
        //利用拓扑来判断是否具有电路(有向图)是否成环
        bool fg=topolog();
        if(!fg)//若非闭环
        cout<<"LOOP"<<endl;
 //     //若为非闭环， 则需要输出
        for(int i=0;i<S;i++){//第i次运行电路
        int s,num;
        cin>>s;//需要输出的信号数量
 //此处需要查询
        memset(ans,-1,sizeof(ans));//初始化,将ans数组清空，每次Q问题时
        for(int j=0;j<s;j++){
            cin>>num;//需要输出结果的器件编号
            if(fg){
                //上一步为非闭环电路
                int out=dfs(i,num);
                cout<<out;
                //行间变换
                if(j==s-1)cout<<endl;//信号数量
                else cout<<" ";
            }

        }

            
        }
    }//Q个问题
    return 0;
}


