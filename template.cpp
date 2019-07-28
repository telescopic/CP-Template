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
###############################################################
Trie:
// NOTE: initialize root before using. 
typedef struct nd{
    //char c; // content of the node - this is not really necessary
   // bool is_end; // to mark a node as an end of a string 
    struct nd *ptrs[26]; // pointers to deeper nodes
} node;
node * root;
node * temp;
void traverse(char K){
    ll idx=K-'a'; //index of alphabet
    if(temp->ptrs[idx]==NULL){ //if link isn't present
        node * creat=(node*)malloc(sizeof(node)); //allocate memory for alphabet
        for(int i=0;i<26;i++) creat->ptrs[i]=NULL; //initialize its next pointers to null
        temp->ptrs[K-'a']=creat; // make the link
        temp=creat;
    }
    else{
        temp=temp->ptrs[K-'a']; // go to next alphabet
    }
}
#############################################
Fast Modulo Multiplication:
// NOTE: initalize MOD with suitable value
ll fast_exp(ll base, ll expz) {
	    ll res=1;
	    while(expz>0) {
	       if(expz%2==1) res=(res*base)%MOD;
	       base=(base*base)%MOD;
	       expz/=2;
	    }
	    return res%MOD;
}
