#include <iostream>
#include <string>
using namespace std;
string s[10];
int fw[5][10][10],a[15][15]; // fw[i] i从1到4分别保存干员朝向上下左右时的攻击范围；a为战场
int main()
{
    for(int i=0;i<7;i++) cin>>s[i]; // 用string简单读入
    for(int i=1;i<=7;i++) for(int j=1;j<=7;j++) fw[1][i][j]=s[i-1][j-1]-'0'; // 朝上
    for(int i=1;i<=7;i++) for(int j=1;j<=7;j++) fw[2][i][j]=fw[1][8-i][j]; // 朝下
    for(int i=1;i<=7;i++) for(int j=1;j<=7;j++) fw[3][i][j]=fw[1][j][i]; // 朝左
    for(int i=1;i<=7;i++) for(int j=1;j<=7;j++) fw[4][i][j]=fw[1][8-j][i]; // 朝右
    int n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        int x,y,f;
        cin>>x>>y>>f;
        for(int i=x-3;i<=x+3;i++) // 因为刚才已经旋转好了所以直接涂色即可
            for(int j=y-3;j<=y+3;j++)
                if(!(i<1||i>10||j<1||j>10)) // 如果没涂到战场范围之外的话
                    a[i][j]|=fw[f][i+4-x][j+4-y]; // 就涂色即可（若之前是0我们要把它变成1，若之前是1则还是1，用或即可）
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}