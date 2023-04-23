#include<bits/stdc++.h>
using namespace std;
int flag=0;
int jc(){
    int s=0;
    if(flag)
    {
       s=1;
    }
    return s;
}

int main(){
   int n,m;
   cin>>n>>m;
   stack<int> nn;
   stack<int> mm;
   stack<int> out;
   int out1,out2;
   int temp;
   for(int i=0;i<n;i++)
   {
    cin>>temp;
    nn.push(temp);
   }
   for(int i=0;i<m;i++){
    cin>>temp;
    mm.push(temp);
   }
   if(m<=n){
    
    for(int i=1;i<=m;i++){
        int sum=0;
         out1=mm.top();
         out2=nn.top();
        mm.pop();
        nn.pop();
        if(jc()){
            sum++;
        }
        sum+=(out2+out1);
        if(sum>=(i+1)){
            sum=sum%(i+1);
            out.push(sum);
            flag=1;
        }else{
    
            out.push(sum);
            flag=0;
        }
    }
    while (!nn.empty())
    {
        int next=nn.top();
        nn.pop();
        if(flag)
        next++;
     if(next>=(m+2))
    {
        next=next%(m+2);
        flag=1;
    }else{
        flag=0;
    }
     
        out.push(next);
        m++;
    }

   }else{

    for(int i=1;i<=n;i++){
        int sum=0;
          out1=mm.top();
         out2=nn.top();
        mm.pop();
        nn.pop();
        if(jc()){
            sum++;
        }
        sum+=(out1+out2);
        if(sum>=(i+1)){
            sum=sum%(i+1);
            out.push(sum);
            flag=1;
        }else{
         
            out.push(sum);
            flag=0;
        }
    }
    while (!mm.empty())
    {
        int next=mm.top();
        mm.pop();
       if(flag)
        next++;
     if(next>=(n+2))
    {
        next=next%(n+2);
        flag=1;
    }else{
        flag=0;
    }
    out.push(next);
    m++;
        /* code */
    }
    
   }

   while (!out.empty())
   {
    if(out.size()!=1){
    cout<<out.top()<<" ";
    out.pop();
    }
    else{
        cout<<out.top();
        out.pop();
    }
        /* code */
   }
   return 0;
}