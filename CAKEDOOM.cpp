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

string check2(string s,int sz)
{
    string a,b;
    bool t1=true,t2=true;

    rep(i,sz)
    {
        if(i%2==0)
        {
            a+='0';
            b+='1';

        }
        else
        {
            a+='1';
            b+='0';
        }
    }
    rep(i,sz)
    {
        if(s[i]!='?'&&s[i]!=a[i])
        {
            t1 =false;
        }
        if(s[i]!='?'&&s[i]!=b[i])
        {
            t2 = false;
        }

    }
    if(t1)
    {
        return a;
    }
    if(t2)
        return b;
    else
        return "NO";



}
string solve(string s,int n)
{
    int sz = s.size();
    string ans = s;
    if(sz==1)
    {
        if(s[0]=='?')
            return "0";
        else
            return s;
    }
    
    if(n==1)
    {
        return "NO";
    }
    if(sz>1&&n<=1)
        return "NO";
    int flag =0;

    if(n==2&&sz%2==1)
    {
        flag=1;
        return "NO";
    }
    else if(n==2&&sz%2==0)
    {
        // for first ? chose 1
        ans=  check2(s,sz);
        return ans;
    }
    else
    {
        rep(i,sz)
        {
            if(ans[i]=='?')
            {
                char k='0';
                while(k<=n-1+'0')
                {
                    if(k!=ans[(i+1)%sz] && k!=ans[(i-1+sz)%sz])
                    {
                            ans[i]=k;
                            break;
                    }
                    k++;
                }
                if(k>n-1+'0')
                {
                    flag =1;
                }
            }
            else
            {
                if(ans[i]==ans[(i-1+sz)%sz])
                {
                    flag =1;
                    break;
                }
            }
        }

    }

    if(ans[0]==ans[sz-1])
        flag=1;

    if(flag)
        return "NO";
    else
        return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{   int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n)<<endl;
	}
}
