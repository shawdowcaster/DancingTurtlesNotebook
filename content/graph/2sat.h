
struct two_sat
{
    static constexpr int N = 1e6 + 5;
    int n;
    vector<int> adj[N];
    int vis[N];
    int low[N], num[N], Time = 0;
    int node[N], nNode = 0;
    vector<int> S;
    void init(int _n)
    {
        n = _n;
        Time = nNode = 0;
        for(int i=0; i<=n*2; i++)
        {
            vis[i] = 0;
            low[i] = num[i] = 0;
            node[i] = 0;
            adj[i].clear();
        }
        S.clear();
    }
    int rev(int a)
    {
        if(a <= n) return a + n;
        else return a - n;
    }
    void add_edge(int a, int b)
    {
        adj[rev(a)].pb(b);
        adj[rev(b)].pb(a);
    }
    void add_or(int a, int b) // at least 1 of them true
    {
        add_edge(a, b);
    }
    void add_xor(int a, int b) // only one of them true
    {
        add_or(a, b);
        add_or(rev(a), rev(b));
    }
    void add_and(int a, int b) // they must be the same
    {
        add_xor(a, rev(b));
    }
    void dfs(int u)
    {
        S.pb(u);
        low[u] = num[u] = ++Time;
        for(int v : adj[u])
        {
            if(num[v] == -1) continue;
            if(num[v]) low[u] = min(low[u], num[v]);
            else
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
        if(low[u] == num[u])
        {
            nNode++;
            while(!S.empty())
            {
                int v = S.back();
                S.pop_back();
                node[v] = nNode;
                num[v] = -1;
                if(v == u) break;
            }
        }
    }
    bool is_good()
    {
        for(int i=1; i<=n*2; i++)
            if(!num[i]) dfs(i);

        for(int i=1; i<=n; i++)
            if(node[i] == node[rev(i)]) return false;
        return true;
    }
};
