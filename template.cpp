Closest Pair algorithm using sweep line:
long long ClosestPair(vector<pair<ll, ll>> pts) {
	// returns square of minimum distance 
    ll n = pts.size();
    sort(pts.begin(), pts.end());
    set<pair<ll, ll>> s;
    long long best_dist = 1e18;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        ll d = ceil(sqrt(best_dist));
        while (pts[i].first - pts[j].first >= best_dist) {
            s.erase({pts[j].second, pts[j].first});
            j += 1;
        }
        auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
        auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});
        
        for (auto it = it1; it != it2; ++it) {
            ll dx = pts[i].first - it->second;
            ll dy = pts[i].second - it->first;
            best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);      
        } 
        s.insert({pts[i].second, pts[i].first}); 
    }
    return best_dist;
}
