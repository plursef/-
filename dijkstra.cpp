#include<iostream>
using namespace std;
#include<cstring>
#include<queue>

//稀疏图的Dijkstra算法
//稠密图用邻接矩阵，稀疏图用邻接表

int n, m;
const int N=150010 , MAX=0x3f3f3f3f;
int idx, e[N], h[N], ne[N], v[N];

int d[N];//存储当前点到1的最短距离
bool st[N];//存储当前点是否确认
typedef pair<int,int> PII;


void add(int a, int b, int c){
    e[idx]=b;
    v[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

void Dijkstra(){
    memset(d, MAX, sizeof d);
    //初始化起点
    d[1]=0;
    priority_queue<PII , vector<PII>, greater<PII>> heap;//小顶堆
    heap.push({0,1});//起点放入
    
    //
    while(heap.size()){
        //查找距离最近的且未确认的点
        PII minn = heap.top();
        heap.pop();
        int min_idx = minn.second, min_dis = minn.first;
        if(st[min_idx]) continue;//特：如果当前点已经确认则continue
        //更新新起点
        st[min_idx] = true;
        //更新新起点连通点的最短距离
        for(int i = h[min_idx]; i!=-1; i=ne[i]){
            int j=e[i];
            if(d[j]>min_dis+v[i]){
                d[j]=min_dis+v[i];
                heap.push({d[j],j});
            }
        }
    }
}


int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    Dijkstra();
    if(d[n] == MAX) cout<< -1;
    else cout<<d[n];
    return 0;
}


