#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k,d;
    cin>>n>>k>>d;
    vector<int> arr;
    for(int i=1;i<=n;i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);
    }

	int i = 0;
	int arr[4] ={1,3,4,8};
	int queries[2][4] ={{0,1},{1,2},{0,3},{3,3}};
	i = sizeof(arr)/sizeof(arr[0]);  // i存了arr数组长度
	int res = 0;
	int pre[4] = {};
	int temp = 0;
	int result[4] = {};
	for(int j=0;j<4;j++)
	{
		temp = temp ^ arr[j];
		pre[j] = temp;
	}
        // 这时候的pre已经存储了前缀和
	for(int q=0;q<4;q++)
	    for(int w=0;w<1;w++)
	    {
	      
	      res =  pre[queries[q][w]]^pre[queries[q][w+1]]^arr[queries[q][w]];
	      result[q] = res;
	    }	
	for(int k=0;k<4;k++)
	{
		printf("%d",result[k]);
	}
	return 0;
}


