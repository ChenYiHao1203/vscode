#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,m;
map<int,int> mp;
int days[105]={0};
int minStart[105]={0};
int maxStart[105]={0};

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
         int d;
         cin>>d;
         mp[i]=d;
    }
    for(int i=1;i<=m;i++){
        int d;
        cin>>d;
        days[i]=d;
    }
    for(int i=1;i<=m;i++){
        if(mp[i]==0){
            minStart[i]=1;
        }else{
            minStart[i]=
        }
    }
    



}



























////map的插入和删除
//**//

// void test03() {
// 	//插入(四种插入)
// 	map<int, int>mp;
// 	//第一种
// 	mp.insert(pair<int, int>(10, 520));
// 	//第二种
// 	mp.insert(make_pair(21, 666));
// 	//第三种
// 	mp.insert(map<int, int>::value_type(1, 999));
// 	//第四种
// 	mp[16] = 1314;
// 	display(mp);
 
// 	//删除
// 	mp.erase(mp.begin());
// 	display(mp);
// 	mp.erase(21);
// 	display(mp);
 
// 	//清空
// 	mp.clear();
// 	//或者
// 	//mp.erase(mp.begin(), mp.end());
// 	display(mp);
// }
// *//