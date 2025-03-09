
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
int dp[100005];
int arr[100005];

int main()
{
  int n;
  gi(n);
  rep(i,n)
    gi(arr[i]);
  int prev= -1;
  int st =0;
  int len =0;
  std::vector<pair<int,int> > v;
  rep(i,n)
  {
    if(prev<arr[i])
    {
      prev = arr[i];
      len++;
      dp[i]= len;
    }
    else
    {

      v.pb(make_pair(st,st+len-1));
      len = 1;
      st= i;
      dp[i]=len;
      prev =arr[i];
    }
//	    pis(dp[i]);
  }
  v.pb(make_pair(st,st+len-1));

  if(v.size()==1)
  {
    pin(n);
  }
  else
  {
int   mx =-1;
/*	rep(i,v.size())
	{
		pis(v[i].fs);
		pin(v[i].sc);
	}
*/
    rep(i,v.size()-1)
    {
      int asize =v[i].sc-v[i].fs+1;
       int bsize = v[i+1].sc-v[i+1].fs+1;
        mx = max(mx,asize);
        mx = max(mx,bsize);
        if(asize==1||bsize==1)
        {
          mx = max(mx,asize+bsize);
        }
        else
        {
            // check compatible
			int a,b,c,d;
            a = v[i].sc-1;
            b = v[i].sc;
			c = v[i+1].fs;
			d = v[i+1].fs+1;
			

            if(arr[d]-arr[b]>=2 || arr[c]-arr[a]>=2)
			{
				mx = max(mx,asize+bsize);
			}
			else
			{
				mx = max(mx,asize+1);
				mx = max(mx,bsize+1);
			
			}
        }
    }
	pin(mx);
  }
}
