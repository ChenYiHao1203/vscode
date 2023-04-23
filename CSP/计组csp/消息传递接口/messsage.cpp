#include<bits/stdc++.h>
using namespace std;
const int MAX=10005;
struct mes
{
    char flag;//看是R或者S
    int target;//所发送或者接收的对象
};
struct pro
{
    queue<mes> task;//消息队列
    /* data */
};

pro po[MAX];//进程数组
int wait[MAX];//进程等待标志

int exe(int no){
   if(wait[no]==1) return -1;//如果处于等待状态，那就是死锁
   if(po[no].task.empty()) return 0;//为空，则执行成功
   mes cur=po[no].task.front();//取出第一个元素
   if(cur.flag=='R'){
    wait[no]=1;
    if(receiveM(no,cur.target)==-1) return -1;
    //如果消息执行成功
    po[no].task.pop();
    wait[no]=0;
    if(exe(no)==-1) return -1;//递归处理下一条消息结构体
    return 0;
   }else if(cur.flag=='S'){
    wait[no]=1;
    if(sendM(no,cur.target)==-1) return -1;

    //如果成功的话
    po[no].task.pop();
    wait[no]=0;
    if(exe(no)==-1) return -1;
    return 0;
   }

}

int sendM(int from, int to){
    if(wait[to]==1) return -1;
    if(po[to].task.empty()) return -1;
    mes cur=po[to].task.front();//获取目标进程的消息队列中的第一个消息
    if(cur.flag=='R'){//不能处理
      if(cur.target==from){
      po[to].task.pop();
      return 0;
      }
      
       if(receiveM(to,cur.target)==-1)  return -1;

        wait[to]=0;
        po[to].task.pop();
        if(sendM(from,to)==0) return 0;//递归判断之前的消息是否能得到处理
        return -1;


    }else if(cur.flag=='S'){
        
        wait[to]=1;
        if(sendM(to,cur.target)==-1)  return -1;

        wait[to]=0;
        po[to].task.pop();
        if(sendM(from,to)==0) return 0;//递归判断之前的消息是否能得到处理
        return -1;
    }
    return -1;
}


int receiveM(int from,int to){
    if(wait[to]==1) return -1;
    if(po[to].task.empty()) return -1;
    mes cur=po[to].task.front();//获取目标进程的消息队列中的第一个消息
    if(cur.flag=='R'){//不能处理
        wait[to]=-1;
        if(receiveM(to,cur.target)==-1) return -1;//递归处理目标进程的下一个消息
        wait[to]=0;
        po[to].task.pop();
        if(receiveM(from,to)==0) return 0;//递归判断之前的消息能否能否得到处理
        return -1;
    }else if(cur.flag=='S'){
        //非自身的S情况
        if(cur.target==from){
            //可以处理当前的消息
            po[to].task.pop();
            return 0;
        }
        //如果不能处理
        wait[to]=-1;
        if(sendM(to,cur.target)==-1)  return -1;

        wait[to]=0;
        po[to].task.pop();
        if(receiveM(from,to)==0) return 0;//递归判断之前的消息是否能得到处理
        return -1;
    }
    return -1;
}

int main(){
    int T,n;
    cin>>T>>n;
    getchar();
    for(int i=0;i<T;i++){
        memset(wait,0,sizeof(wait));
        //初始化每个进程的消息队列
        for(int j=0;j<n;j++){
            while(!po[j].task.empty())
            po[j].task.pop();
        }//循环j
        //存储消息节点
        for(int j=0;j<n;j++){
            string line;
            getline(cin,line);
            istringstream ss(line);
            string tmp;
            while(ss>>tmp){
                mes me;
                me.flag=tmp[0];
                me.target=atoi(tmp.c_str()+1);
                po[j].task.push(me);
            }
        }
        int flag=0;
        for(int j=0;j<n;j++){
            if(!po[j].task.empty()){
                //执行该进程
                if(exe(j)==-1){
                    flag=1;
                    break;
                }
            }
        }
        cout<<flag<<endl;
    }//大循环T
     return 0;
}


