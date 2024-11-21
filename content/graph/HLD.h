
void dfs(int u)
{
    sz[u] = 1;
    for(int v : adj[u])
    {
        if(p[u] == v) continue;
        p[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}
void HLD(int u)
{
    if(!chainhead[nChain]) chainhead[nChain] = u;
    chainid[u] = nChain;
    int bigChild = -1;
    timein[u] = ++Time;
    for(int v : adj[u])
    {
        if(v == p[u]) continue;
        if(bigChild == -1 || sz[bigChild] < sz[v])
            bigChild = v;
    }
    if(bigChild != -1) HLD(bigChild);
    for(int v : adj[u])
    {
        if(v == p[u] || v == bigChild) continue;
        nChain++;
        HLD(v);
    }
}
int LCA(int u, int v)
{
    while(chainhead[chainid[u]] != chainhead[chainid[v]])
    {
        if(depth[chainhead[chainid[u]]] < depth[chainhead[chainid[v]]]) swap(u, v);
        u = p[chainhead[chainid[u]]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    return u;
}
int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}
int Query(int u, int v)
{
    int res = 0;
    while(chainhead[chainid[u]] != chainhead[chainid[v]])
    {
        if(depth[chainhead[chainid[u]]] < depth[chainhead[chainid[v]]]) swap(u, v);
        res += get(1, 1, n, timein[chainhead[chainid[u]]], timein[u]);
        u = p[chainhead[chainid[u]]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    res += get(1, 1, n, timein[u], timein[v]);
    return res;
}
