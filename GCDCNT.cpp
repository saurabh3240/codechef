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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;

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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}

ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;
		a = b;
		b = r;
	}
	return a;
}
int n,q;
int arr[100005];
vector<int> divisor[100005];
ordered_set pos[100005];
bool prime[100005];
void sieve()
{
    prime[0]=true;
    prime[1]=true;
    divisor[1].pb(1);
    for(int i=2;i<100005;i++)
    {
        divisor[i].pb(i);
        if(!prime[i])
        {
            for(int j=i+i;j<100005;j+=i)
            {
                prime[j]=true;
                divisor[j].pb(i);
            }
        }
        else
        {
            for(int j=i+i;j<100005;j+=i)
            {
                divisor[j].pb(i);
            }
        }
    }
}
int bsearch(int l,int r,int prod)
{
    //std::set<int>::iterator itleft,itright;
    // cout<<"size"<<pos[prod].size();
    int a = pos[prod].order_of_key(l);
    int b = pos[prod].order_of_key(r+1);
    // cout<<"bseach "<<l<<" "<<r<<" "<<prod<<endl;
    // cout<<a<<" "<<b<<endl;
    // itleft = pos[prod].lower_bound(l);
    // itright = pos[prod].lower_bound(r+1);
    // cout<<"bsearch"<<endl;
    // cout<<itleft<<endl;
    //cout<<itright<<endl;
    return (b-a);
}

int get(int l, int r, int g)
{
    // find all prime of divisor of g
    vector<int> pdiv;
//    cout<<divisor[g].size()<<endl;
    rep(i,divisor[g].size())
    {   int x = divisor[g][i];
        if(prime[x]==false)
        {
            pdiv.pb(x);
//            pis(x);
        }
    }
//    pnl();

    // inclusion exclusinon

    int zz = pdiv.size();
    int ans=0;
    int limt = 1<<zz;
    int mask = 1;

    // pin(zz);

    for(int i=mask;i<limt;i++)
    {
        // find product of all the mask
        int prod =1;
        rep(j,zz)
        {
            if(i&(1<<j))
            {
                prod*=pdiv[j];
            }
        }
        int pc = __builtin_popcount(i);
        // pis(MOD);
        // pis(prod);
        // pin(pc);
        int res = bsearch(l,r,prod);
        (pc%2==1)?ans+=res:ans-=res;
    }
    // for each bitmask(
    // calcular l,r,prod using binary search in prod
    // return ans
    //int fromone = bsearch(l,r,1);
    return ans;
}
int main()
{
    sieve();
    gi(n);
    forup(i,1,n+1)
    {
        int x ;
        gi(x);
        arr[i] = x;
        // for every divisor arr[i+1]
        rep(j,divisor[x].size())
        {
            int div  = divisor[x][j];
            pos[div].insert(i);
        }
    }
    gi(q);
    rep(i,q)
    {
        int op;
        gi(op);
        if(op==1)
        {
            int x,y;
            gi(x);
            gi(y);
            // remove arr[x]  and all position from its divisor
            int z = arr[x];
            rep(j,divisor[z].size())
            {
                int div = divisor[z][j];
                pos[div].erase(x);
            //    cout<<"reaased"<<endl;
            }
            arr[x]=y;
            z = arr[x];
            rep(j,divisor[z].size())
            {
                int div = divisor[z][j];
                pos[div].insert(x);
        //        cout<<"inserted in "<<div<<endl;

            }
            // add new arr[x] and all position into its divisor
        }
        else
        {
            int l,r,g;
            gi(l);
            gi(r);
            gi(g);
            if(g==1)
            {
                pin(r-l+1);
            }
            else
            {
                pin((r-l+1)-get(l,r,g));
            }
        }
    }

}
 
