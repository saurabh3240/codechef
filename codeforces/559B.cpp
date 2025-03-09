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
#include<unordered_map>
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
{	ll r;
	while(b)
	{	r= a%b;a = b; b = r;
	}
	return a;
}
ll hashA[200005];
string a,b;
ll hashB[200005];
ll pow31[200005];
bool isequal(int sA,int eA,int sB,int eB)
{
	for(int i=sA,j=sB;i<=eA;i++,j++)
	{
		if(a[i-1]!=b[j-1])
			return false;
	}
	return true;
}

bool isequivalent(int sA,int eA,int sB,int eB)
{
	
	
	//cout<<"strings "<<strA<<" "<<strB<<endl; 
		
	//check if the are equal
	bool temp = isequal(sA,eA, sB,eB);
	/*
	int x = sA;
	int y = sB;
	ll HA = hashA[eA]- hashA[sA-1] + MOD + MOD;
	HA%=MOD;
	
	ll HB = hashB[eB]- hashB[sB-1] + MOD + MOD;
	HB%=MOD;
	
	if(x>=y)
	{
		HB = HB*pow31[abs(x-y)];
		HB%=MOD;
	}
	else
	{		
		HA = HA*pow31[abs(x-y)];
		HA%=MOD;
	}
	*/
	if(temp)
	{		
	//	cout<<"strings "<<strA<<" "<<strB<<endl;
	//	cout<<"ans of this call is TRUE"<<endl;
			return true;
	}
	else
	{
		int xx = eA-sA+1;
		if(xx%2==0)  // if divisibel
		{	//cout<<"divisible"<<endl;
			int x2 = xx/2;
			return 
			(isequivalent(sA , sA+x2-1, sB, sB+x2-1) && isequivalent( sA+x2, eA, sB+x2, eB) )||
			(isequivalent(sA, sA+x2-1, sB+x2, eB) && isequivalent(sA+x2, eA, sB, sB+x2-1));
			//cout<<"strings "<<strA<<" "<<strB<<endl; 
			//cout<<"ans of this call is XXX "<<(Ans1||Ans2)<<endl;
		}	
		else
		{
			//cout<<"strings "<<strA<<" "<<strB<<endl; 
			//cout<<"ans of this call is FALSE"<<endl;
			return false;
		}	
	}
}
map<int,map<int,map<int,map<int,int> >  > > mp;
int main()
{
	ll z = 1ll;
	rep(i,200005)
	{
		pow31[i]=z;
		z*=31;
		z%=MOD;
	}	
	cin>>a>>b;
	//build hash for A
	int n = a.size();
	ll prevA =0ll,prevB = 0ll;
	rep(i,a.size())
	{
		hashA[i+1] =hashA[i]+ (a[i]*pow31[i])%MOD;
		hashA[i+1]%=MOD;
		
		hashB[i+1] =hashB[i]+ (b[i]*pow31[i])%MOD;
		hashB[i+1]%=MOD;
	}
	/*
	rep(i,a.size()+1)
	{
		cout<<hashA[i]<<" ";
	}
	cout<<endl;
	
	rep(i,a.size()+1)
	{
		cout<<hashB[i]<<" ";
	}
	cout<<endl;
	*/
	if(isequivalent(1,n,1,n))
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
		
}
