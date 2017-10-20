#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
static const int MAX = 10000;
static const int INF = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX];


void dijkstra(){
    priority_queue<pair<int, int> > PQ;
    int color[MAX];
    int d[MAX];
    for(int i=0; i<n; i++){
        d[i] = INF;
        color[i] = WHITE;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = WHITE;
    
    while(!PQ.empty()){
        pair<int, int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        color[u] = BLACK;
        
        // 最小値を取り出し，最短でなければ無視する
        // PQが降順のため，-1をかけて格納している
        if (d[u] < f.first * (-1) ) continue;

        for(int j=0; j<adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1), v));
                color[v] = GRAY;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
    }
}




int main() 
{
    ios::sync_with_stdio(false);
    
    cin >> n;
    int k, c, u, v;
    for(int i=0; i<n; i++){
        cin >> u >> k;
        for(int j=0; j<k; j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    
    dijkstra();
    
    return 0;
}
