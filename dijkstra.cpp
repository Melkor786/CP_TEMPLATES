vector<pair<ll, ll>> adj[100005];
void dijkstra(ll source, ll node)
{
  map<ll, ll> mp;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> ans(node + 10, inf);
  ans[source] = 0;
  pq.push({0, source}); // weight,source
  while (!pq.empty())
  {
    ll parent_weight = pq.top().first;
    ll parent_node = pq.top().second;
    pq.pop();
    for (auto it : adj[parent_node])
    {
      ll child_node = it.first;
      ll child_weight = it.second;
      if (parent_weight > ans[parent_node])
        continue;
      if (ans[child_node] > child_weight + parent_weight){
        mp[child_node] = parent_node;
        ans[child_node] = child_weight + parent_weight;
        pq.push({ans[child_node], child_node});
      }
    }
  }

  ll n = node;
  if (mp[n] == 0)
    cout << -1 << endl;
  else{
    vector<ll> final;
    mp[1] = -1;
    while (n != -1){
      final.push_back(n);
      n = mp[n];
    }
    reverse(final.begin(), final.end());
    for (auto it : final)
      cout << it << " ";
    cout << endl;
  }
}
