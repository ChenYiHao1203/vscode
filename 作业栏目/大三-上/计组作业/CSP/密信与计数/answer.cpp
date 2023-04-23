#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define MOD 998244353
int cnt=0;
int ch[60][26];     //用于AC自动机的字典树
int fail[60];       //AC自动机fail
bool mark[60];      //自动机的终止条件
/// @brief 
int n,m,k;
int Out[60][26];    //明文->密文
int next[60][26];   //转换页数
char s[60][60];      //词典
int len[60];         //词典中单词的长度
int Q[60];          //建立自动机的fail时的BFS使用的队列
long long F[1010][51][51]; //F[i][j][k]代表长度为i，匹配到第j个节点，且在查看第k页的明文个数
long long Ans[1010];

void newnode(int x){
  int i;
  for(int i=0;i<26;i++){
    ch[x][i]=0;
  }
  fail[x]=0;
  mark[x]=0;

}

void insert(char *s){
   int i,k;
   int len=strlen(s);
   int x=0;
   for(int i=0;i<len;i++){
      k=s[i]-'a';
      if(ch[x][k]==0){
        cnt++;
        ch[x][k]=cnt;
        newnode(ch[x][k]);
      }
      x=ch[x][k];
   }
    mark[k]=true;

}

void build(){
    int i;
    int l=0,r=0;
    for(int i=0;i<26;i++){
       if(ch[0][i]){
        r++;
        Q[r]=ch[0][i];
       }


    }
    wile(l<r){//队列有index
    l++;
    int x=Q[l];
    for(int i=0;i<26;i++){
        if(ch[x][i]){
  //回跳边
          fail[ch[x][i]]=ch[fail[x][i]];
          mark[ch[x][i]]= mark[fail[x][i]];
          r++;
          Q[r]=ch[x][i];

        }else{
            ch[x][i]=ch[fail[x][i]];

        }
    }

    }
}
void solve(){
    int i,j,k,l,ll;
    f[0][0][1]=1;
    for(int i=0;i<=m;i++){//长度为1-m
       for(j=0;j<=cnt;j++){//遍历AC自动机所有节点
       for(k=1;k<=n;k++){//遍历所有页
           if(f[i][j][k]){

            f[i][j][k] = f[i][j][k]%MOD;
            Ans[i]=Ans[i]+f[i][j][k];
            bool flag=true;
            int tj,tk,x;

            for(l=0;l<k;l++){
                //遍历词典中的语句
                if(i+len[l]>m)continue;

                 flag=true;
                 tj=j;
                 tk=k;
                 for(ll=0;ll<len[l];ll++){
                    x= Out[tk][s[l][ll]];
                    tk=next[tk][s[l][ll]];
                    tj=ch[tj][x];
                    if(mark[tj]){
                        flag=false;
                        break;
                    }
                 }
                 if(flag){
                    f[i+len[l][tj][tk]]=f[i+len[l][tj][tk]]+f[i][j][k];//状态转移方程
                 }

            }
           }
         }
       }
    }
    for(int i=1;i<=mi++){
        Ans[i]=Ans[i]%MOD;
        cout<<Ans[i]<<endl;
    }
}



int main(){
    int i,j;
    cnt=0;
    newnode(0);
    cin>>n>>m;
    for(int i=0;i<26;i++)//输入解密密码本
    {
        for(int j=1;j<=n;j++){
            char s[1010];
            scanf("%s",s);
            Out[j][s[0]-'a']=i;
            int len = strlen(s);
            int v=0;   //提取出对应的跳转的页面
            if(len==2){
                v=s[1]-'0';

            }else{
                v=(s[1]-'0')*10+s[2]-'0';
            }
            next[j][s[0]-'a']=v;//提取出密文对应的跳转的页
        }
    }
    k=0;
    while (scanf("%s",s[k]!=EOF))
    {


        insert(s[k]);
        len[k]=strlen(s[k]);//AC自动机模板串的建立
        for(i=0;i<len(k);i++)
        s[k][i]=s[k][i]-'a';
        
        k++;
        /* code */
    }
    build();//AC自动机的fail指针
    solve();//求解，动态规划，以及字符串匹配
    return0;
    
}