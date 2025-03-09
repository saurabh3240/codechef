
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
#define ull unsigned long long
#define BL 24
using namespace std;
int gmask =0;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll INF =  1e18 +9LL;
typedef pair<ll,ll> pll;
typedef vector< pll > vll;

typedef pair<int,int> pii;
typedef vector< pii > vii;

int n,e,k;

vector< pair<int,int> > T; // tree
vector< pair< pair<int,ll> , int> > G[300005];
 //
ll dist[300005];
bool vis[300005];

pair<int,int> P[300005];
void Dijistra(int s)
{
  for(int i=0;i<=n;i++)
    dist[i] = INF;
  dist[s]=0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int> > > Q;
  Q.push({0ll,s});
  while(!Q.empty())
  {
      int u = Q.top().sc;
      Q.pop();
      for(auto v:G[u])
      {

        // v.fs.fs  = second node
        // v.fs.sc =  second node weight
          if(dist[v.fs.fs]> dist[u]+ v.fs.sc)
          {
            dist[v.fs.fs] = dist[u] + v.fs.sc;
            P[v.fs.fs] = {u,v.sc};
            // p[v.fs.fs]  = {u, v.}
            Q.push({dist[v.fs.fs],v.fs.fs});
          }
      }
  }
}




int main()
{
  int u,v;
  ll w;

  gi(n);
  gi(e);
  gi(k);
  rep(i,e)
  {
    gi(u);gi(v);gl(w);
    G[u].pb({{v,w},i});
    G[v].pb({{u,w},i});
  }
  Dijistra(1);
for(int i=0;i<=n;i++)
{
  cout<<i<<" "<<P[i].fs<<" "<<P[i].sc<<endl;
}


  // int source = 1;
  // Dijkstra(source,n+1,k);
  //
  // GG =  new vector<pair<int,ll> > [n+1];
  // rem = k;
  // for(int i=2;i<=n;i++)
  // {
  //   int v = edgex[i];
  //   GG[v].pb({i,1});
  //   GG[i].pb({v,1});
  //   // cout<<i<<" --"<<v<<endl;
  // }
  // dfs(1);
  // pin(ans.size());
  // rep(i,ans.size())
  //   pis(ans[i]);

}
