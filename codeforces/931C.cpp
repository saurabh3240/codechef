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

int main()
{
    int n;
    gi(n);
    std::vector<int> v;
    rep(i,n)
    {
        int x;
        gi(x);
        v.pb(x);
    }
    sort(v.begin(),v.end());
    if(abs(v[0]-v[n-1])<=1)
    {
        pin(n);
        rep(i,n)
        {
            pis(v[i]);
        }
    }
    else
    {
        int L=0,R=0,C=0;
        int hi = v[0];
        int lo = v[n-1];
        int cen = hi+1;
        rep(i,n)
        {
            if(v[i]==hi)
                L++;
            else if(v[i]==cen)
                C++;
            else
                R++;
        }
        // pis(L);
        // pis(C);
        // pin(R);
        int val;
        //cin>>val;
        int minans=MOD;
        int x =0;
        if(C%2==1)
            x=1;
        //L C R

        int Lnew = L;
        int Rnew = R;
        int Cnew = C;
        int LANS,RANS,CANS;
        for(int z=C;z>=x;z=z-2)
        {


        //    cout<<"HEre"<<z<<" "<<x<<endl;
            int x = min(L,Lnew)+min(R,Rnew)+min(C,Cnew);
            if(x<minans)
            {
                minans = x;
                LANS  = Lnew;
                RANS = Rnew;
                CANS = Cnew;
        //        pis(minans);pis(LANS);pis(CANS);pin(RANS);

            }
            Lnew++;
            Rnew++;
            Cnew-=2;

        }
        // cout<<"ss"<<endl;
        // add to center
        if(R>L)
        {
            Lnew = L;
            Rnew = R;
            Cnew = C;
            for(int z=L;z>=0;z-=1)
            {
        //        cout<<"HEre2"<<z<<endl;

                int x = min(L,Lnew)+min(R,Rnew)+min(C,Cnew);
                if(x<minans)
                {
                    minans = x;
                    LANS  = Lnew;
                    RANS = Rnew;
                    CANS = Cnew;
    //                pis(minans);pis(LANS);pis(CANS);pin(RANS);
                }
                Lnew--;
                Cnew+=2;
                Rnew--;

            }

        }
        else
        {
            Lnew = L;
            Rnew = R;
            Cnew = C;
            for(int z=R;z>=0;z-=1)
            {
        //        cout<<"HEre3"<<z<<endl;
                int x = min(L,Lnew)+min(R,Rnew)+min(C,Cnew);
                if(x<minans)
                {
                    minans = x;
                    LANS  = Lnew;
                    RANS = Rnew;
                    CANS = Cnew;
        //            pis(minans);pis(LANS);pis(CANS);pin(RANS);

                }
                Lnew--;
                Cnew+=2;
                Rnew--;

            }
        }
        cout<<minans<<endl;
        rep(i,LANS)
        {
            pis(hi);
        }
        rep(i,CANS)
        {
            pis(cen);
        }
        rep(i,RANS)
        {
            pis(lo);
        }

    }

}
