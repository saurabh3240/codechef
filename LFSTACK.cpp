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
#define pnl() printf("n")
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
const int INF = 2000000000;
typedef pair<int,int> PII;

#define ull unsigned long long
using namespace std;
ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='n'); //buffer clear
ll gcd(ll a,ll b)
{    ll r;
    while(b)
    {    r= a%b;a = b; b = r;
    }
    return a;
}
int n;
int tot;
std::vector<int> st;// stackfinal
std::vector<std::vector<int> > v;

bool solvable(int top, vector<int> vpos)
{
    cout<<top<<endl;
    if(top==tot)
    {
        return true;
    }
    rep(i,v.size())
    {
        if(v[i][vpos[i]]!=0)
        {
            if(st[top]==v[i][vpos[i]-1])
            {
                vpos[i]--;
                bool ret;
                ret = solvable(top+1,vpos);
                if(ret==true)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
  int t;
  gi(t);
  while(t--)
  {
      gi(n);
      v.clear();
      tot=0;
      std::vector<int> vpos_l;
      rep(i,n)
      {
          std::vector<int> vc;

          int x;
          vpos_l.pb(x);
          tot+=x;
          gi(x);
          rep(j,x)
          {
              int y;
              gi(y);
              vc.pb(y);
           }
           v.pb(vc);
      }
      rep(i,tot)
      {
          int y;
          gi(y);
          st.pb(y);
      }
      cout<<"here"<<endl;
      if(solvable(0,vpos_l))
      {
          cout<<"YES"<<endl;
      }
      else
      {
          cout<<"NO"<<endl;
      }

  }

}