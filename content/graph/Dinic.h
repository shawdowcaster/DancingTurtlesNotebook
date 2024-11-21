struct Edge
{
    int u, v;
    ll c;
    Edge() {}
    Edge(int u, int v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
struct Dinic
{
    const ll Inf = 1e17;
 
    int n, sink, source;
    vector<vector<int>> adj;
    vector<Edge> s;
    vector<int> h;
    vector<vector<int>::iterator> cur;
 
    void Assign(int n = 0)
    {
        this->n = n;
        adj.resize(n + 2);
        s.reserve(n + 2);
        cur.resize(n + 2);
        h.resize(n + 2);
    }
 
    void AddEdge(int u, int v, ll c)
    {
        s.emplace_back(u, v, c);
        adj[u].emplace_back(s.size() - 1);
        s.emplace_back(v, u, 0);
        adj[v].emplace_back(s.size() - 1);
    }
 
    bool BFS()
    {
        fill(h.begin(), h.end(), n + 2);
        queue<int> q({sink});
        h[sink] = 0;
 
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
 
            for(auto i : adj[c])
                if(h[s[i].v] == n + 2 && s[i ^ 1].c != 0)
                {
                    h[s[i].v] = h[c] + 1;
 
                    if(s[i].v == source)
                        return true;
 
                    q.emplace(s[i].v);
                }
        }
        return false;
    }
 
    ll dfs(int v, ll flowin)
    {
        if(v == sink)
            return flowin;
 
        ll flowout(0);
 
        for(; cur[v] != adj[v].end(); ++cur[v])
        {
            int i = *cur[v];
 
            if(s[i].c == 0 | h[s[i].v] + 1 != h[v])
                continue;
 
            ll q = dfs(s[i].v, min(flowin, s[i].c));
 
            flowout += q;
            if(flowin != Inf)
                flowin -= q;
            s[i].c -= q;
            s[i ^ 1].c += q;
 
            if(flowin == 0)
                break;
        }
 
        return flowout;
    }
 
    ll BlockFlow()
    {
        for(int i = 1; i <= n; ++i)
            cur[i] = adj[i].begin();
        return dfs(source, Inf);
    }
 
    ll MaxFlow(int s, int t)
    {
        sink = t;
        source = s;
 
        ll Flow(0);
 
        while(BFS())
            Flow += BlockFlow();
 
        return Flow;
    }
};
