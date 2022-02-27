#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long ll;
const int MAXN = 200011;
const int INF = 0x3f3f3f3f;

inline int read() {
	int x = 0; char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	do x = x * 10 + ch - 48, ch = getchar(); while(ch >= '0' && ch <= '9');
	return x;
}

int n, m, l, end;
int a[MAXN], lim[MAXN];

struct Person
{
	int s,b,id,tar,dis;
	Person() {}
	Person(int _s,int _b,int _id,int _tar,int _dis) :
		s(_s), b(_b), id(_id), tar(_tar), dis(_dis) {} 
	friend bool operator < (const Person &x,const Person &y) {
		if(x.s != y.s) return x.s < y.s;
		return x.b < y.b;
	}
};

struct Chain
{
	int l[MAXN],r[MAXN];
	void init() {
		for(int i = 1;i <= m;i++) {
			l[i] = i - 1;
			r[i] = i + 1;
		}
		l[1] = m, r[m] = 1;
	}
	int pre(int x) {
		return l[x];
	}
	int nxt(int x) {
		return r[x];
	}
	void del(int x) {
		r[l[x]] = r[x];
		l[r[x]] = l[x];
	}
};

Person p[MAXN];
Chain c;

struct Segment_Tree
{
#define lc(k) k << 1
#define rc(k) k << 1 | 1
	struct node
	{
		int id,dis,tar;
		node() {}
		node(int _id,int _dis,int _tar) :
			id(_id), dis(_dis), tar(_tar) {}
		friend bool operator < (const node &x,const node &y) {
			if(x.dis != y.dis) return x.dis < y.dis;
			return ::p[x.id].id < ::p[y.id].id;
		}
	};
	
	struct tag
	{
		int dis, tar;
		tag() {}
		tag(int _dis,int _tar) :
			dis(_dis), tar(_tar) {}
	};

	node p[MAXN << 2];
	tag t[MAXN << 2];

	void pushdown(int k) {
		if(!t[k].dis && !t[k].tar) return;
		perform(lc(k),t[k]);
		perform(rc(k),t[k]);
		t[k].dis = t[k].tar = 0;
		return;
	}
	
	void pushup(int k) {
		p[k] = std::min(p[lc(k)],p[rc(k)]);
	}

	void perform(int k,tag x) {
		p[k].dis += x.dis;
		if(x.tar) p[k].tar = x.tar;
		t[k].dis += x.dis;
		if(x.tar) t[k].tar = x.tar;
		return;
	}

	void build(int k,int l,int r) {
		if(l == r) {
			p[k] = node(l,::p[l].dis,::p[l].tar);
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(k),l,mid);
		build(rc(k),mid + 1,r);
		pushup(k);
	}
	
	void update(int k,int l,int r,int x,int y,tag v) {
		if(l > y || r < x) return;
		if(l >= x && r <= y) {
			perform(k,v);
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(k);
		update(lc(k),l,mid,x,y,v);
		update(rc(k),mid + 1,r,x,y,v);
		pushup(k);
		return;
	}

	void upset(int k,int l,int r,int x) {
		if(l == r) {
			p[k].dis = INF;
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(k);
		if(x <= mid) upset(lc(k),l,mid,x);
		else upset(rc(k),mid + 1,r,x);
		pushup(k);
	}

	node query() {
		return p[1];
	}
};

Segment_Tree t;

void init() {
	for(int i = 1;i <= n;i++) {
		if(!p[i].s) {
			int k = std::lower_bound(a + 1,a + 1 + m,p[i].b) - a - 1;
			if(k == m) p[i].tar = 1, p[i].dis = l - p[i].b;
			else p[i].tar = k + 1, p[i].dis = a[k + 1] - p[i].b; 
		} else {
			int k = std::upper_bound(a + 1,a + 1 + m,p[i].b) - a - 1;
			p[i].tar = k, p[i].dis = p[i].b - a[k];
		}
	}
	return;
}

void Modify1(int l,int r,Segment_Tree::tag tag) {
	int k1 = std::upper_bound(p + 1,p + end,Person(0,l,0,0,0)) - p;
	int k2 = std::upper_bound(p + 1,p + end,Person(0,r,0,0,0)) - p - 1;
	if(l > r) {
		if(k1 < end) t.update(1,1,n,k1,end - 1,tag);
		if(k2 >= 1) t.update(1,1,n,1,k2,tag);
	} else if(k1 <= k2) t.update(1,1,n,k1,k2,tag);
}

void Modify2(int l,int r,Segment_Tree::tag tag) {
	int k1 = std::lower_bound(p + end,p + 1 + n,Person(1,l,0,0,0)) - p;
	int k2 = std::lower_bound(p + end,p + 1 + n,Person(1,r,0,0,0)) - p - 1;
	if(l > r) {
		if(k1 <= n) t.update(1,1,n,k1,n,tag);
		if(k2 >= end) t.update(1,1,n,end,k2,tag);
	} else if(k1 <= k2) t.update(1,1,n,k1,k2,tag);
}

int main() {
	n = read(), m = read(), l = read();
	for(int i = 2;i <= m;i++) a[i] = read();
	for(int i = 1;i <= m;i++) lim[i] = read();
	for(int i = 1;i <= n;i++) {
		p[i].s = read(), p[i].b = read();
		p[i].id = i;
	}
	std::sort(p + 1, p + 1 + n);
	while(end <= n && !p[end].s) end++;
	init();
	t.build(1,1,n);
	c.init();
	ll ans = 0; int usdup = 0;
	for(int i = 1;i <= n;i++) {
		Segment_Tree::node k = t.query();
		int id = k.id,tar = k.tar;
		ans ^= 1ll * p[id].id * tar;
		//std::printf("node = %d target = %d\n",p[id].id,tar);
		t.upset(1,1,n,id);
		if(!--lim[tar]) {
			Modify1(a[c.pre(tar)],a[tar],Segment_Tree::tag((a[c.nxt(tar)] - a[tar] + l) % l,c.nxt(tar)));
			Modify2(a[tar],a[c.nxt(tar)],Segment_Tree::tag((a[tar] - a[c.pre(tar)] + l) % l,c.pre(tar)));
			c.del(tar);
			if(++usdup == m) break;
		}
	}
	std::printf("%lld\n",ans);
	return 0;
}