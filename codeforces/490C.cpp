
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
ll mod_pow(ll num, ll pow, ll mod)
{
    ll test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
ll dp1[10000005];
ll dp2[10000005];
int main()
{
    string s;
    cin>>s;
    ll a,b;
    cin>>a>>b;
    ll n= s.size();

    dp1[0]=s[0]-'0';
    dp1[0]%=a;
    dp2[n-1]=s[n-1]-'0';
    dp2[n-1]%=b;
    ll z = 10ll;
    forup(i,1,n)
    {
        ll x = s[i]-'0';
        ll y = s[n-i-1]-'0';
        dp1[i] = dp1[i-1]*10+x;
        //cout<<x<<" "<<y<<" "<<z<<endl;
        dp1[i]%=a;
        dp2[n-i-1] = y*z+dp2[n-i];
        dp2[n-i-1]%=b;
        z = z*10ll;
        z= z%b;
    }

    // forup(i,0,n)
    // {
    //     cout<<dp1[i]<<" " <<dp2[i]<<endl;
    // }

    int flag =0;
    int idx =-1;
    forup(i,0,n-1)
    {
        if(dp1[i]==0 && dp2[i+1]==0)
        {
            int asize = i+1;
            int bsize = n-asize;
            // pin(i);
            // pin(asize);
            // pin(bsize);
            if(asize >=1 && s[0]=='0')
            {
                continue;
            }
            if(bsize >=1 && s[i+1]=='0')
            {
            //    cout<<"ehere"<<endl;
                continue;
            }
            flag =1;
            idx = i;
            break;
        }
    }

    if(flag)
    {
        cout<<"YES"<<endl;
        //pin(idx);
        rep(i,idx+1)
        {
            cout<<s[i];
        }
        cout<<endl;
        forup(i,idx+1,n)
        {
            cout<<s[i];
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }

}
