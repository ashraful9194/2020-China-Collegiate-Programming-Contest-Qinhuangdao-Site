#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
vector<pii>v[1000005];
int cnt;
int ans;
int height_of_subtree(int node)
{
    if(v[node].size()==0) return 1;
    for(int i=0; i<v[node].size(); i++)
    {
        int son=v[node][i].second;
        v[node][i].first=height_of_subtree(son);
    }
    sort(v[node].begin(),v[node].end());
    return v[node].back().first+1;
}
int dfs(int node,int height)
{
    for(int i=0; i<v[node].size(); i++)
    {
        int son=v[node][i].second;
        ++cnt;
        dfs(son,height+1);
        ++cnt;
    }
    if(v[node].empty()) ans+=min(cnt,height),cnt=0;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         int n;
         cin>>n;
         for(int i=1; i<=n; i++) v[i].clear();
         for(int i=2; i<=n; i++)
         {
             int x;
             cin>>x;
             v[x].pb({0,i});
         }
         height_of_subtree(1);
         cnt=0,ans=0;
         dfs(1,0);
         cout<<"Case #"<<tc<<": ";
        cout<<ans<<endl;
     }
}

