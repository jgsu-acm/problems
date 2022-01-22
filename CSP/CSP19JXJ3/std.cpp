#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=3005,MAXM=6005;
int n,m;
int s1,t1,s2,t2;
int cnte,h[MAXN],to[MAXM],nx[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
queue<int> que;
int dis[3][MAXN];
/*
dis[0]存以从1为起点的单源最短路
dis[1]存以从s1为起点的单源最短路
dis[2]存以从s2为起点的单源最短路
*/
void Bfs(int rt,int *d){
	d[rt]=0;
	que.push(rt);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(d[v]>d[u]+1)
				d[v]=d[u]+1,que.push(v);
		}
	}
	return ;
}
int ans;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
	memset(dis,0x3f,sizeof(dis));
	Bfs(1,dis[0]);
	Bfs(s1,dis[1]);
	Bfs(s2,dis[2]);
	ans=2e9;	//无限大
	for(int i=1; i<=n; i++)
		if(dis[0][i]+dis[1][i]<=t1&&dis[0][i]+dis[2][i]<=t2)
			ans=min(ans,dis[0][i]+dis[1][i]+dis[2][i]);
	if(ans==2e9) ans=-1;
	else ans=cnte/2-ans;	//题目问的是最多去掉多少道路，cnte/2就是道路总数（码风啊）
	printf("%d\n",ans);
	return 0;
}