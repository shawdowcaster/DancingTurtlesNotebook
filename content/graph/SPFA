#include<bits/stdc++.h>
typedef pair<int, int> ii;
const int MaxN = 1e5 + 5;
const int Inf = 1e9;
vector<vector<ii>> AdjList;
int Dist[MaxN];
int Cnt[MaxN];
bool inqueue[MaxN];
int S;
int N;
queue<int> q;

bool spfa() {
    for(int i = 1 ; i <= N ; i++) {
        Dist[i] = Inf;
        Cnt[i] = 0;
        inqueue[i] = false;
    }
    Dist[S] = 0;
    q.push(S);
    inqueue[S] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (ii tmp: AdjList[u]) {
            int v = tmp.first;
            int w = tmp.second;

            if (Dist[u] + w < Dist[v]) {
                Dist[v] = Dist[u] + w;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                    Cnt[v]++;
                    if (Cnt[v] > N)
                        return false;
                }
            }
        }
    }
    return true;
}
