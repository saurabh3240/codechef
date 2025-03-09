
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
vector<int> edges[1000005];
int visited[1000005];
double p=1;
double d = 0;
double ans = 0;

void dfs(int x)
{
  visited[x]=1;
  if(edges[x].size()==1 && x!=1)  // this is a leave node
  {
      // pis(x);
      // pis(edges[x].size());
      // pds(p); pds(d);
    ans+=p*d;
//    pin(ans);
  }
  else
  {
    double z = edges[x].size()-1;
    if(x==1)
        z++;
    p = p/z;
    d++;
    rep(i,edges[x].size())
    {
        int v = edges[x][i];
        if(!visited[v])
            dfs(v);
    }
    d--;
    p = p*z;
  }
}

int main()
{
  int n;
  gi(n);
  rep(i,n-1)
  {
    int u,v;
    gi(u);
    gi(v);
    edges[u].pb(v);
    edges[v].pb(u);
  }

  if(n==1)
  {
    printf("0.000000");
  }
  else
  {
    dfs(1);
    printf("%.12f\n",ans);
  }
}
