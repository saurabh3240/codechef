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
 
struct SegTree{
        long long sum ;
        long long update ;
};
 
 
SegTree tree[4*1000000+10] = {0} ;
 
 
void build_tree(int node , int a , int b )
{
        tree[node].update = 0 ;
        tree[node].sum = 0 ;
        if(a == b)
        {
                tree[node].sum = 0 ;
                return ;
        }
        build_tree(2*node , a , (a+b)/2) ;
        build_tree(2*node + 1 , (a+b)/2 + 1 , b) ;
 
}
 
void update(int node , int a , int b , int i , int j , long long v)
{
        if(tree[node].update)
        {
                tree[node].sum += tree[node].update*(b - a + 1) ;
                if(a != b)
                {
                        tree[2*node].update += tree[node].update ;
                        tree[2*node + 1].update += tree[node].update ;
                }
                tree[node].update = 0 ;
        }
        if(i > b || j < a)
        {
                return ;
        }
 
        if(a >= i && b <= j)
        {
                tree[node].sum += v*(b - a + 1) ;
                if(a != b)
                {
                        tree[2*node].update += v ;
                        tree[2*node + 1].update += v ;
                }
                return ;
        }
        update(2*node , a , (a+b)/2 , i , j , v) ;
        update(2*node + 1 , (a+b)/2 + 1 , b , i , j , v) ;
        tree[node].sum = tree[2*node].sum + tree[2*node + 1].sum ;
 
}
 
long long query(int node ,int a , int b , int i , int j)
{
        if(tree[node].update)
        {
                tree[node].sum += tree[node].update*(b - a + 1) ;
                if(a != b)
                {
                        tree[2*node].update += tree[node].update ;
                        tree[2*node + 1].update += tree[node].update ;
                }
                tree[node].update = 0 ;
        }
        if(i > b || j < a)
        {
                return 0;
        }
        if(a >= i && b <= j)
        {
                return tree[node].sum ;
        }
 
        return (query(2*node , a , (a+b)/2 , i , j) + query(2*node + 1 , (a+b)/2 + 1 , b , i , j)) ;
}
 
 
int main()
{
    int n,m,c;
    fastRead_int(n);
    fastRead_int(m);
    fastRead_int(c);
    build_tree(1,1,n) ;
    update(1,1,n,1,n,c) ;
 
 
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
            pln(query(1,1,n,x,x) );
        }
        else
        {   int u,v,k;
            fastRead_int(u);
            fastRead_int(v);
            fastRead_int(k);
            update(1,1,n,u,v,k) ;
        }
    }
 
}
 