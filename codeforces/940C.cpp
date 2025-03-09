
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
int mp[27];
int cm[28];
int main()
{
    string s;
    int n,k;

    gi(n);
    gi(k);

        cin>>s;
        vector<char> vc;
        rep(i,n)
        {
            mp[s[i]-'a']=1;
        }

        rep(i,26)
        {
            cm[i+1] = cm[i]+mp[i];
            if(mp[i]==1)
                vc.pb(i+'a');
        }
        sort(vc.begin(),vc.end());
    if(k<=n)
    {
        // rep(i,vc.size())
        //     cout<<vc[i]<<" "<<endl;
        int x = cm[26];
        string ans=s;
        int ind =-1;
        char lastc =vc[vc.size()-1];
        for(int i=k-1;i>=0;i--)
        {
            if(ans[i]==lastc)
            {
            }
            else
            {   ind = i;
                break;
            }
        }
        char c = ans[ind],c2;
        // find next big char
        for(int i=c+1;i<='z';i++)
        {
            if(mp[i-'a']==1)
            {
                c2 = i;
                break;
            }
        }
    //    cout<<ans<<endl;
        ans[ind]=c2;
    //    cout<<ans<<endl;

        for(int i=ind+1;i<n;i++)
        {
            ans[i]=vc[0];
        }
        rep(i,k)
            cout<<ans[i];
    }
    else
    {
        string ans = s;
        rep(i,k-n)
        {
            ans+=vc[0];
        }
        cout<<ans<<endl;
    }
    // smallest letter

}
