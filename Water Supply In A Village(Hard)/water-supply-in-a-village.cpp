#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second > b.second)
            return true;
        else
            return false;
    }
};
int supplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &pipe : pipes)
    {
        adj[pipe[0]].push_back({pipe[1], pipe[2]});
        adj[pipe[1]].push_back({pipe[0], pipe[2]});
    }
    // create edges for wells
    for (int i = 0; i < wells.size(); i++)
    {
        adj[0].push_back({i + 1, wells[i]});
        adj[i + 1].push_back({0, wells[i]});
    }
    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<bool> mst(n + 1, false);

    key[0] = 0;
    parent[0] = -1;
    // node, weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int node = top.first;
        int wt = top.second;

        mst[node] = true;

        for (auto &ad : adj[node])
        {
            int adjNode = ad.first;
            int adjWt = ad.second;
            if (mst[adjNode] == false && adjWt < key[adjNode])
            {
                key[adjNode] = adjWt;
                parent[adjNode] = node;
                pq.push({adjNode, adjWt});
            }
        }
    }
    int minCost = 0;
    for (auto &cost : key)
        minCost += cost;
    return minCost;
}
int main()
{
    int wellLength, pipesLength;
    cin >> wellLength >> pipesLength;
    vector<int> wells(wellLength);
    for (int i = 0; i < wellLength; i++)
        cin >> wells[i];
    vector<vector<int>> pipes;
    for (int i = 0; i < pipesLength; i++)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        pipes.push_back(v);
    }
    int ans = supplyWater(wellLength, wells, pipes);
    cout << ans << endl;
    return 0;
}