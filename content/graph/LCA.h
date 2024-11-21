void Log()
{
    for(int i=2; i<maxN; i++) lg[i] = lg[i / 2] + 1;
}
void dfs(int u, int par)
{
    pos[u] = tour.size();
    tour.pb(u);
    for(int v : adj[u])
    {
        if(v == par) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        tour.pb(u);
    }
}
int mini(int u, int v)
{
    return depth[u] < depth[v] ? u : v;
}
void build_LCA()
{
    depth[1] = 1;
    tour.clear();
    dfs(1, 0);
    for (int i = 0; i < tour.size(); i++)
    {
        rmq[i][0] = tour[i];
    }

    for (int i = 1; i <=20; i++)
    {
        for (int j = 0; j < tour.size(); j++)
        {
            if (j + (1 << (i - 1)) >= tour.size())
                rmq[j][i] = rmq[j][i - 1];
            else
                rmq[j][i] = mini(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int LCA(int u, int v)
{
    int l = min(pos[u], pos[v]), r = max(pos[u], pos[v]);
    int k = lg[r - l + 1];
    return mini(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}
