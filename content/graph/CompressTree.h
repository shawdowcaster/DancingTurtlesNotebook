/**
 * Author: Nguyen Tri Tam
 * Date: 2016-01-14
 * License: CC0
 * Description: Given a rooted tree and a subset S of nodes, compute the minimal
 * subtree that contains all the nodes by adding all (at most $|S|-1$)
 * pairwise LCA's and compressing edges.
 * Returns a vector of edges in the virtual tree
 * The root points to itself.
 * Time: $O(|S| \log |S|)$
 * Status: Tested at CodeForces
 */
vector<pair<int, int>> build_virtual_tree(vector<int>& vc)
{
    int k = vc.size();
    sort(vc.begin(), vc.end(), [](int i, int j)
    {
        return tin[i] < tin[j];
    });
    for(int i=0; i<k; i++)
    {
        if(i < k - 1) vc.pb(lca(vc[i], vc[i + 1]));
        if(jump[vc[i]][0]) vc.pb(jump[vc[i]][0]);
    }
    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end());
    sort(vc.begin(), vc.end(), [](int i, int j)
    {
        return tin[i] > tin[j];
    });
    stack<int> S;
    vector<pair<int, int>> edges;
    for(int v : vc)
    {
        while(!S.empty() && chk(v, S.top()))
        {
            edges.pb({v, S.top()});
            S.pop();
        }
        S.push(v);
    }
    return edges;
}
