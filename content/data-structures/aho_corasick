struct Aho_Corasick
{
    vector<node> aho;
    void init()
    {
        aho.clear();
        aho.emplace_back(-1, 'a');
    }
    ll add(string s, ll val) // them val lan xau s vao cay aho
    {
        ll now = 0;
        for(char c : s)
        {
            if(aho[now].nxt[c - 'a' + 1] == -1)
            {
                aho[now].nxt[c - 'a' + 1] = aho.size();
                aho.emplace_back(now, c);
            }
            now = aho[now].nxt[c - 'a' + 1];
        }
        aho[now].leaf = val;
        return now;
    }
    ll get_val(ll u)
    {
        if(u == 0) return 0;
        if(aho[u].val == -1)
        {
            aho[u].val = aho[u].leaf + get_val(get_link(u));
        }
        return aho[u].val;
    }
    ll go(ll v,ll t)
    {
        if(aho[v].go[t] == -1)
        {
            if(aho[v].nxt[t] != -1)
            {
                aho[v].go[t]=aho[v].nxt[t];
            }
            else
            {
                if(v == 0) aho[v].go[t] = 0;
                else aho[v].go[t] = go(get_link(v), t);
            }
        }
        return aho[v].go[t];
    }
    ll get_link(ll v)
    {
        if(aho[v].link == -1)
        {
            if(aho[v].par == 0 | v == 0) aho[v].link = 0;
            else aho[v].link = go(get_link(aho[v].par), aho[v].ch - 'a' + 1);
        }
        return aho[v].link;
    }
    ll get(string s) // dem so lan xuat hien cua cac xau con cua s trong cay aho
    {
        ll now = 0;
        ll res = 0;
        for(char c : s)
        {
            now = go(now, c - 'a' + 1);
            res += get_val(now);
        }
        return res;
    }
};
