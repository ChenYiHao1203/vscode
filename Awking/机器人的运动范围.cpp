#include<bits/stdc++.h>
using namespace std;


//这是一个典型的宽度优先搜索问题，从（0，0）每次朝上下左右四个方向扩展新的节点
/**
 * @brief 
 * 扩展是需要满足的条件
 * 之前有无遍历过此节点，bool数组来判断
 * 是否走出边界
 * 横纵坐标个位数字之和是否小于k
 */

class solution{
    public:
    int get_sum(pair<int, int>p){
        int s=0;
        while(p.first){
            s+=p.first%10;
            p.first/=10;
        }
        while (p.second)
        {
            s+=p.second%10;
            p.second/=10;
            /* code */
        }
        return s;
    }
    int moveCount(int threshold,int rows,int cols){
        if(!rows||!cols) return 0; //越界
        queue<pair<int,int>> q;//存储点对
        vector<vector<bool>> st(rows, vector<bool>(cols,false));//初始化二维访问数组
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//上下左右

        //vector<vector<bool> st2(rw, vector<bool>(cols,false));



        int res=0;
        q.push({0,0});
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(st[t.first][t.second]||get_sum(t)>threshold) continue;//略过，访问过或者大于k

            res++;//
            st[t.first][t.second]=true;
            for(int i=0;i<4;i++){
                int x=t.first+dx[i],y=dy[i]+t.second;//相当于dfs_4个方向
                if(x>=0&&x<rows&&y>=0&&y<cols) q.push({x,y});
            }

        }
        return res;

}
};

