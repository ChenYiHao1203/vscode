#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;

int base(string s , int b)
{// 转换10进制的方法
    //在B进制下的string转换成十进制数
    int res=0;
    for(auto x:s)
       res=res*b+x-'0';
    
    return res;
}
int main(){
  string x,y;
  cin>>x>>y;
  //定义一个哈希表
  unordered_set<int> hash;
  for(int i=0;i<x.size();i++)
  {
    string s=x;
    s[i] ^=1;//偶数异或1 +1  奇数异或1 -1
    hash.insert(base(s,2));//枚举所有可能性
  }
  for(int i=0;i<y.size();i++){
    for(int j=0;j<3;j++){
        if(y[i]-'0'!=j){
            string s=y;
            s[i]=j+'0';//第i位置设置为j -- 0,1,2
            int n=base(s,3);
            if(hash.count(n)){//如果出现过
            cout<<n<<endl;

            }
        }

    }
  }



}