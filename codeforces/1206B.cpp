//https://codeforces.com/problemset/problem/1206/B

#include <bits/stdc++.h> 
 
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


bool check(int x)
{   
    int tot =0;
    while(x)
    {
        tot+= x%10;
        x = x/10;
    }
    return tot==10;
}
int main()
{
   int n;
   gi(n);
   vector<int> v;
   ll neg =0;
   ll ans =0;
   ll zeros =0;
   rep(i,n)
   {
       ll x;
       gl(x);
       if(abs(x))
           ans += abs(x)-1;
        if(x==0)
            zeros++;
       if(x<0)
       {
         neg++;
       }
   }
   //cout<<ans;
   if(neg%2==1)
   {    if(zeros)
           ans+=zeros;
        else
        {
            ans+=2;
        }
        
   }
   else
   {
       ans+=zeros;
   }
   
   
   cout<<ans<<endl;


}


