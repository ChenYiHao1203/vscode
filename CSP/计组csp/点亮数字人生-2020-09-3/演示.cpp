#include<bits/stdc++.h>
using namespace std;
//考查点： 图的构建（有向图）中间过程模拟作为边去执行操作、拓扑排序、计算值、逻辑运算
//步骤：1.构建图 2.存储需要测试的输入、输出的器件 3.使用拓扑 来判断是否电路具有 环 .计算每个元器件得度数值

int Q;//问题的个数
int M,N;//整个的电路的输入信号的个数和 器件个数
map<string,int> Mp;//做一个映射，把元器件得逻辑符号转换成数字
int  S;//电路运行的次数
void Map_init(){
    Mp["NOT"]=0;
    Mp["AND"]=1;
    Mp["OR"]=2;
    Mp["XOR"]=3;
    Mp["NAND"]=4;
    Mp["NOR"]=5;
}//对于每个元器件来说，1.输入信号 - -结构体 2.输出端 “输入”数组
struct Node
{
    int func;//逻辑功能
    vector<int> In;//第In[i]个输入信号连接到该器件输入端
    vector<int> Out;//第Out[i]个器件的输出连接到输入端
    /* data */
}Dev[505];//max=500
//存放每次输入0/1
int Input[10005][505];//第i次电路运行的第j个输入信号(0/1),保存起来
int Ind[505];//第i个器件有Ind[i]个输入是其他器件的输出，记录数字的次数---拓扑排序
int ans[505];//存储输出结果

vector<int> e[505];

int getNum(int pos,char *str){
    int num=0;
    int len=strlen(str);
    while (pos<len)
    {
        num=num*10+str[pos]-'0';
        ++pos;
        /* code */
    }
    return num;

}

//拓扑排序
bool tuopu(){
    //拓扑排序
    queue<int> que;//存放“输入全是信号电路的输入”的器件队列
    for(int i=1;i<=N;i++){
        if(!Ind[i]){
            que.push(i);//把器件i放入队列
        }
    }
    int cnt=0;
    while (!que.empty())//遍历
    {
        int u=que.front();//访问队首元素
        que.pop();//出队列
        ++cnt;
        int cnt=e[u].size();//u队首元素，对首元素的非 “输入信号的 elem"的个数
        for(int i=0;i<cnt;i++){
            //遍历每个输出端连接此元器件
//////
            int v=e[u][i];//找他的“头”器件
            if(!(--Ind[v])){
                que.push(v);//若纯输入信号 的器件，则入队列
            }
        }
        /* code */
    }
    return cnt==N;

}

int dfs(int s,int u){//第s次运行电路，要输出 器件u的运行结果
if(ans[u]!=-1){
    return ans[u];//第u个器件以递归结果，运算完毕
}
/// @brief  输入
/// @param s 
/// @param u 
/// @return 
int cnt=Dev[u].In.size();//有多少个电路输入 信号，器件u的输入端
vector<int> t;
for(int i=0;i<cnt;i++){
    //遍历每个输入输入信号
    int temp=Dev[u].In[i];//得到具体的器件u的输入信号 i，i是随着size递增
    t.push_back(Input[s][temp]);//temp对应器件,s对应次数 保存输入结果 0/1
    
}
/// @brief 输出
/// @param s 
/// @param u 
/// @return 
cnt=Dev[u].Out.size();//有多少个输出端连接 器件u
for(int i=0;i<cnt;i++){
    //Input是我们已知的，但是此处 输出端 -> 器件u，是未知的
    //因此需要去做递归
//////
    t.push_back(dfs(s,Dev[u].func));//递归.0/1一步步递归

}
return ans[u]==opera(t,Dev[u].func);

}

int opera(vector<int>q, int func){
    //参考map
    if(func==0) return !q[0];//NOT
    else{
        int cnt=q.size();
        int r=q[0];
        if(func==1){//AND
            for(int i=1;i<cnt;i++) r&=q[i];
            return r;//不断的做逻辑运算
        }else if(func==2){//OR
            for(int i=1;i<cnt;i++) r|=q[i];
             return r;
        }else if (func==3)//xor
        {
             for(int i=1;i<cnt;i++) r^=q[i];
             return r;
            /* code */
        }else if(func==4){//NAND
            for(int i=1;i<cnt;i++) r&=q[i];
            return !r;//不断的做逻辑运算

        }
        for(int i=1;i<cnt;i++) r|=q[i];//NOR
            return !r;//不断的做逻辑运算
        
    }
}

int main(){
   Map_init();
   char str[10];
   cin>>Q;
   while(Q--){
    cin>>M>>N;
    //每一次问题，我们都需要去clear器件
    for(int i=1;i<=N;i++){
        e[i].clear();//清空所有元素
        Ind[i]=0;
        Dev[i].In.clear();
        Dev[i].Out.clear();
    }
    //对每个器件的输入
    for(int i=1;i<=N;i++){
        cin>>str;
        Dev[i].func=Mp[str];
        int k;
        cin>>k;//我们所要输入的个数
        for(int j=0;j<k;j++){//分别输入I(x)O(x)
        cin>>str;
        int num=getNum(1,str);//找到对应的数字
        if(str[0]=='I'){
            Dev[i].In.push_back(num);//输入信号
        }//I输入信号
        else{
            e[num].push_back(i);//第num个器件的输出 连接到第 i 个器件上
            Ind[i]++;//记录非输入信号
            Dev[i].Out.push_back(num);//第num个器件的输出 连接 第i个器件的输入端
        }

        }//j

    }//每个器件的输入
    //结构构造完成
    //下一阶段，输入
    cin>>S;//电路运行s次
    for(int i=0;i<S;i++){
        for(int j=1;j<=M;j++){
            cin>>Input[i][j];//每次输入的信号 0/1

        }//M个器件
        //拓扑排序,来判断是否具有生成环
        bool fg=tuopu();
        if(!fg){
            //闭环
            cout<<"LOOP"<<endl;
        }
/////
        //若非闭环，则需要输出
        for(int i=0;i<S;i++){//第S次运行电路
            int s,num;
            cin>>s;//需要输出的信号数量
////
            memset(ans,-1,sizeof(ans));//初始化，将ans清空，每次输出时
            for(int j=0;j<s;j++){
                cin>>num;//需要输出的 器件编号
                if(fg){
                    //非闭环
                    int out=dfs(i,num);//次器件num返回的值，0/1
                    cout<<out;
                    //格式
                    if(j==(s=1))cout<<endl;
                    else cout<<" ";
                }

            }//j

        }//S
    }//运行S次

   }//Q个问题
   return 0;

}

