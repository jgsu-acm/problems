#include<iostream>
using namespace std;
int dp[1001][1001],a1[2001],a2[2001],n,m;
int main()
{
   //dp[i][j]表示两个串从头开始，直到第一个串的第i位 
   //和第二个串的第j位最多有多少个公共子元素 
   cin>>n>>m;
   for(int i=1;i<=n;i++)scanf("%d",&a1[i]);
   for(int i=1;i<=m;i++)scanf("%d",&a2[i]);
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
     {
     	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
     	if(a1[i]==a2[j])
     	dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
     	//因为更新，所以++； 
     }
   cout<<dp[n][m];
}