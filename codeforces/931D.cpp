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
#define INF 1000000000
#define ull unsigned long long
using namespace std;
int parent[100005];
vector<int> edges[100005];
int visited[100005];
int depth[100005];
int d = 1;
void dfs(int u)
{
    if(!visited[u])
    {
        depth[u]=d;
        d++;
        visited[u]=1;
        rep(i,edges[u].size())
        {
            int v = edges[u][i];
            dfs(v);
        }
        d--;
    }
}
int main()
{
    int n;
    gi(n);

    rep(i,n-1)
    {
        int x;
        gi(x);
        parent[i+2]=x;
        edges[x].pb(i+2);
        edges[i+2].pb(x);
    }
    dfs(1);
    map<int,int> mp;
    rep(i,n)
    {
        mp[depth[i+1]]++;
    }
    ll ans =0;
    map<int,int> ::reverse_iterator it;
    it = mp.rbegin();
    for(;it!=mp.rend();it++)
    {
        ans+=it->sc%2;
    }
    cout<<ans<<endl;
}
