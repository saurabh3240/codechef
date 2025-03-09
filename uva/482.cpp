
 
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
#include <climits>
 
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

int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
   }


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

int comp2(string a,string b)
{
	while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
	return a>b;
	
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

 
int main()
{

	int t;
	cin>>t;
	string s,blank;	
	int i=1;
	while(t--)
	{	

		if(i)
		{	getline(cin,blank);
			i =0;
		}
		getline(cin,blank);
		
		getline(cin,s);
		//cout<<s<<endl;
		istringstream iss(s);
		vector<int> v;
		int n;
		while(iss>>n)
		{
			v.pb(n);			
		}


		getline(cin,s);
		//cout<<s<<endl;
		istringstream iss2(s);
		vector<string> v_d;
		string d;
		while(iss2>>d)
		{
			v_d.pb(d);			
		}	
		string ans[v_d.size()];
		rep(i,v.size())
		{
			ans[v[i]-1] = v_d[i];
		}
		rep(i,v_d.size())
			cout<<ans[i]<<endl;
		if(t!=0)
			cout<<endl;
			
	}
}


