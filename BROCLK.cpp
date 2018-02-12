
 
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

 void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (F[0][0]*M[0][0] )%MOD+ (F[0][1]*M[1][0])%MOD;
  ll y =  (F[0][0]*M[0][1] )%MOD+ (F[0][1]*M[1][1])%MOD;
  ll z =  (F[1][0]*M[0][0] )%MOD+ (F[1][1]*M[1][0])%MOD;
  ll w =  (F[1][0]*M[0][1] )%MOD+ (F[1][1]*M[1][1])%MOD;
 
  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;
}
 
/* Optimized version of power() in method 4 */
void powerf(ll F[2][2], ll n, ll p, ll q)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{2*p,(MOD-q)},{q,0}};
  powerf(F, n/2,p,q);
  multiply(F, F);
  if (n%2 != 0)
     multiply(F, M);
}
ll fib(ll n,ll p,ll q)
{
  ll F[2][2] = {{2*p,(MOD-q)},{q,0}};
  if (n == 0)
      return 0;
  
  powerf(F, n-1, p, q);
 //  rep(i,2)
 //  {
	//   rep(j,2)
	//   pls(F[i][j]);
	// pnl();
 //  }
  ll z = ((F[0][0]*p)%MOD + (F[0][1]*q)%MOD)%MOD;
  return z;
}

int main()
{	
	int t;
	gi(t);
	while(t--)
	{	ll l,d,r;
		cin>>l>>d>>r;
		// cout<<endl;
		if(r==1)
		{
			
			//ll gc = gcd(l,d);
		//	cout<<"answer"<<endl;
			pln(d);

		}	
		else
		{
			ll zz =fib(r,d,l);
			ll aa = mod_pow(l,r-1,MOD);
			ll temp = mod_pow(aa,MOD-2,MOD);
		//	cout<<"answeer"<<endl;

			ll vv =(zz*temp)%MOD;
			
			//ll gc = gcd(l,vv);
			 
			pln(vv);
			
		}
		
		

	}
}
