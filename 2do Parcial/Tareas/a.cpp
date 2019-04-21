#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;
 
#define INF INT_MAX


void Dijkstra(int N, vector<vector<pair<int, int> > > &G, vector<int> &Dist) {
 
    priority_queue <pair<int,int>, 
        vector<pair<int,int> >, 
        greater<pair<int,int> > > Q;
    
    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int, int> p(0,0);
    Q.push(p);
    while(!Q.empty())
    {
        int u = Q.top().first;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            pair<int, int> p = G[u][i];
            int v  = p.first;
            int w = p.second;
            if(Dist[v] > Dist[u]+w)
            {
                Dist[v] = Dist[u]+w;
                pair<int, int> nvo(v, Dist[v]);
                Q.push(nvo);
            }
        }
    }    
    
}

int main() 
{
    int N, M, w, C;
    int cases = 1;
	char u, v;
    cin >> C; 
    while (C)
    {
        vector<vector<pair<int, int> > > G(20);
		vector<int> Dist;

        cin >> N >> M; 

        for(int i=0;i<M;++i){
            cin >> u >> v >> w;
			pair<int, int> n1(int(v - 'A'), w);
			pair<int, int> n2(int(u - 'A'), w);
			G[int(u - 'A')].push_back(n1);
			G[int(v - 'A')].push_back(n2);
        }
        Dijkstra(N, G, Dist);
        
        int index, max = Dist[0];
		for (int i = 0; i < Dist.size(); i++) 
        {
			if (max < Dist[i]) 
            {
				max = Dist[i];
				index = i;
			}
		}
        cout << "Case " << cases << ": " << char(index + 'A') << endl;
        cases++;
        C--;
    }
    
    return 0;
}