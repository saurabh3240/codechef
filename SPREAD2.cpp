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
#include <cstdio>
 
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
inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;
 
    while (c < 33)
        c = getchar_unlocked();
 
    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}
 
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
 
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
 
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
 
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
 
    if(neg)
        x = -x;
}
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
//while((getchar())!='\n'); //buffer clear
ll gcd(ll a,ll b)
{   ll r;
    while(b)
    {   r= a%b;a = b; b = r;
    }
    return a;
}
// BIT(BINARY INDEXED TREE)
#define LOGSZ 20  //2^17
 
ll tree[(1<<LOGSZ)+1];
ll N = (1<<LOGSZ);
 
// add v to value at x
void update(int x, ll v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}
 
// get cumulative sum up to and including x
ll get(int x) {
  ll res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}
 
ll getval(int x)
{
	return get(x)-get(x-1);
}
// get largest value with cumulative sum less than or equal to x;
// for smallest, pass x-1 and add 1 to result
int getind(int x) {
  int idx = 0, mask = N;
  while(mask && idx < N) {
    int t = idx + mask;
    if(x >= tree[t]) {
      idx = t;
      x -= tree[t];
    }
    mask >>= 1;
  }
  return idx;
}
 
 
int main()
{
    int n,m,c;
    fastRead_int(n);
    fastRead_int(m);
    fastRead_int(c);
    //build_tree(1,1,n) ;
  //  update(1,1,n,1,n,c) ;
    update(1,c);
    update(n+1,-c);
 
    while(m--)
    {
         char ch;
        ch=getchar_unlocked();
        while(!(ch=='Q'||ch=='S'))
            ch=getchar();
        if(ch=='Q')
        {
            int x;
            fastRead_int(x);
            pln(get_val(x));
        }
        else
        {   int u,v,k;
            fastRead_int(u);
            fastRead_int(v);
            fastRead_int(k);
            update(u,k);
            update(v+1,-k);
//            update(1,1,n,u,v,k) ;
        }
    }
 
}
  