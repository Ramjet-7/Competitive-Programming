// Problem: https://dmoj.ca/problem/year2015p4
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1000*1000+1;
int a,b,m;
struct Node {int x,y;};
short actions[MXN];
vector<int> paths;
bool vis[MXN], poss=false;
int parent[MXN];
queue<Node> q;
queue<int> bq;
vector<int> adj[MXN];
map<pair<int, int>, int> freq;
Node fill(Node nod, int state){
	if (state == 1){
		nod.x=a;
		return nod;
	} else {
		nod.y=b;
		return nod;
	}
}
Node chug(Node nod, int state){
	if (state==1){
		nod.x=0;
		return nod;
	} else {
		nod.y=0;
		return nod;
	}
}
Node pour(Node nod, int state){
	if (state==1){
		// Pour A into B
		if (b-nod.y>=nod.x){
			nod.y+=nod.x;
			nod.x=0;
			return nod;
		} else {
			nod.x=nod.x-(b-nod.y);
			nod.y=b;
			return nod;
		}
	} else {
		// Pour B into A
		if (a-nod.x>=nod.y){
			nod.x+=nod.y;
			nod.y=0;
			return nod;
		} else{
			nod.y=nod.y-(a-nod.x);
			nod.x=a;
			return nod;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> m;
	Node NODE;
	NODE.x=0;NODE.y=0;
	q.push(NODE);
	int ps = 0, des = 1, ans=0;
	freq[{0,0}]++;
	while (!q.empty()){
		Node node = q.front();
		int A = node.x, B=node.y;
		if (A==m||B==m) {ans=ps;poss=true;break;}
		q.pop();
		pair<int, int> chug1 = {chug(node,1).x,chug(node,1).y};
		pair<int, int> chug2 = {chug(node,2).x,chug(node,2).y};
		pair<int, int> fill1 = {fill(node,1).x,fill(node,1).y};
		pair<int, int> fill2 = {fill(node,2).x,fill(node,2).y};
		pair<int, int> pour1 = {pour(node,1).x,pour(node,1).y};
		pair<int, int> pour2 = {pour(node,2).x,pour(node,2).y};
		if (freq[chug1]==0){
			adj[ps].push_back(des);
			actions[des]=1;
			des++;freq[chug1]++;
			q.push(chug(node, 1));
		} if (freq[chug2]==0){
			adj[ps].push_back(des);
			actions[des]=2;
			des++;freq[chug2]++;
			q.push(chug(node, 2));
		} if (freq[fill1]==0){
			adj[ps].push_back(des);
			actions[des]=3;
			freq[fill1]++;des++;
			q.push(fill(node, 1));
		} if (freq[fill2]==0){
			adj[ps].push_back(des);
			actions[des]=4;
			freq[fill2]++;des++;
			q.push(fill(node, 2));
		} if (freq[pour1]==0){
			adj[ps].push_back(des);
			actions[des]=5;
			freq[pour1]++;des++;
			q.push(pour(node, 1));
		} if (freq[pour2]==0){
			adj[ps].push_back(des);
			actions[des]=6;
			freq[pour2]++;des++;
			q.push(pour(node, 2));
		}
		ps++;
	}
	if (!poss) {cout << "Not possible\n"; return 0;}
	vis[0] = true;
	bq.push(0);
	parent[0]=-1;
	bool reached=false;
	while (!bq.empty()&&!reached) {
		int s = bq.front(); bq.pop();
		for (int u : adj[s]) {
			if (vis[u]) continue;
			vis[u] = true;
			parent[u]=s;
			bq.push(u);
			if (u==ans){
				reached=true;
				break;
			}
		}
	}
	paths.push_back(ans);
	while (1){
		paths.push_back(parent[ans]);
		ans=parent[ans];
		if (ans==0) break;
	}
	reverse(paths.begin(), paths.end());
	for (int i : paths){
		if (actions[i]==1) cout << "chug A\n";
		else if (actions[i]==2) cout << "chug B\n";
		else if (actions[i]==3) cout << "fill A\n";
		else if (actions[i]==4) cout << "fill B\n";
		else if (actions[i]==5) cout << "pour A B\n";
		else if (actions[i]==6) cout << "pour B A\n";
	}
}
