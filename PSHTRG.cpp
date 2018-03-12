#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include<algorithm>
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
#define limit 100005
#define LOG 32
// using namespace std;
int arr[100005];


inline void fastRead_int(int &x) {
        register int c = getchar();
        x = 0;
        int neg = 0;

        for(; ((c<48 || c>57) && c != '-'); c = getchar());

        if(c=='-') {
            neg = 1;
            c = getchar();
        }

        for(; c>47 && c<58 ; c = getchar()) {
            x = (x<<1) + (x<<3) + c - 48;
        }

        if(neg)
            x = -x;
    }



int get_ind(int  x)
{
    int i=0;
    while(x)
    {   i++;
        x>>=1;
    }
    return i-1;
}

struct node
{
    int bucket[LOG][3];
};
struct node s[4*100005];
int n,q;

void build(int id = 1,int l = 0,int r = n)         //root index 1,children 2x,2x+1
{                          // root = [0,n)
    // cout<<id<<" "<<l<<" "<<r<<endl;
    if( l+1 == r )
    {
        int ind = get_ind(arr[l]);
        // cout<<"id "<<id<<"*********"<<endl;
        rep(i,LOG)
        {
            rep(j,3)
                s[id].bucket[i][j]=-1;
        }
        s[id].bucket[ind][2]=arr[l];

         // cout<<arr[l]<<endl;

        return;             // comes from array
    }

    ll mid = l + (r-l)/2;
    int left =id*2;
    int right = id*2+1;
    build( left, l, mid);           // interval = [left,right)
    build( right, mid, r);
    // cout<<"id "<<id<<"*********"<<endl;
    rep(i,LOG)
    {
        rep(j,3)
        {
            s[id].bucket[i][j]=-1;
        }
    }

    rep(i,LOG)
    {


        int ind = 2;
        int l = 2;
        int r = 2;


        while(l>=0&&r>=0)
        {
            if(s[left].bucket[i][l]>s[right].bucket[i][r])
            {
                s[id].bucket[i][ind--]=s[left].bucket[i][l];
                l--;
            }
            else
            {
                s[id].bucket[i][ind--]=s[right].bucket[i][r];
                r--;
            }
            if(ind<0)
                break;
        }
        if(ind<0)
            continue;
        while(l>=0)
        {
            s[id].bucket[i][ind--]=s[left].bucket[i][l--];
            if(ind<0)
                break;
        }
        if(ind<0)
            continue;

        while(r>=0)
        {
            s[id].bucket[i][ind--]=s[right].bucket[i][r--];
            if(ind<0)
                break;
        }

    }
    // rep(i,LOG)
    // {
    //     rep(j,3)
    //     {
    //         pis(s[id].bucket[i][j]);
    //
    //     }
    //     pnl();
    // }

}
void modify(int p, int  x, int id=1, int l=0, int r=n)    // call modify(p,x)
{
                    //x is the value to which a[p] is changed
    //s[id] += x-a[p] ;         // change the value of the segtree node
    if( l+1 == r)
    {           // l=r-1=p


        rep(i,LOG)
            rep(j,3)
                s[id].bucket[i][j]=-1;

       arr[p]=x;
       int ind = get_ind(arr[p]);
       s[id].bucket[ind][2]=arr[l];


       return;
    }

    ll mid = l + (r-l)/2;

    if( p < mid )
    {
       modify(p, x, id*2, l, mid);
    }
    else
    {
       modify(p, x, id*2+1, mid, r);
    }
    int left =id*2;
    int right = id*2+1;

    rep(i,LOG)
    {
        rep(j,3)
        {
            s[id].bucket[i][j]=-1;
        }
    }

    rep(i,LOG)
    {


        int ind = 2;
        int l = 2;
        int r = 2;
        while(l>=0&&r>=0)
        {
            if(s[left].bucket[i][l]>s[right].bucket[i][r])
            {
                s[id].bucket[i][ind--]=s[left].bucket[i][l];
                l--;
            }
            else
            {
                s[id].bucket[i][ind--]=s[right].bucket[i][r];
                r--;
            }
            if(ind<0)
                break;
        }
        if(ind<0)
            continue;

        while(l>=0)
        {
            s[id].bucket[i][ind--]=s[left].bucket[i][l--];
            if(ind<0)
                break;
        }
        if(ind<0)
            break;

        while(r>=0)
        {
            s[id].bucket[i][ind--]=s[right].bucket[i][r--];
            if(ind<0)
                break;
        }
    }

}
//
//
//
struct node query(int x,int y,int id=1,int l=0,int r=n){        //verify return type
                            // call query(l,r)
    struct node zero;

    // cout<<x<<" "<<y<<"-"<<id<<"-"<<l<<"-"<<r<<endl;
    if( x >= r or l >= y )
    {
        rep(i,LOG)
            rep(j,3)
                zero.bucket[i][j]=-1;

        return zero;    // no overlap

    }
    if( x <= l and r <= y )  return s[id];      // complete overlap
    ll mid = l + (r-l)/2;             // partial overlap
    int left =id*2;
    int right = id*2+1;

    struct node n1,n2,n3;
    n1 = query(x, y, left, l, mid) ;
    n2 = query(x, y, right, mid, r);


    rep(i,LOG)
    {
        rep(j,3)
        {
            n3.bucket[i][j]=-1;
        }
    }
    rep(i,LOG)
    {


        int ind = 2;
        int l = 2;
        int r = 2;
        while(l>=0&&r>=0)
        {
            if(n1.bucket[i][l]>n2.bucket[i][r])
            {
                n3.bucket[i][ind--]=n1.bucket[i][l];
                l--;
            }
            else
            {
                n3.bucket[i][ind--]=n2.bucket[i][r];
                r--;
            }
            if(ind<0)
                break;
        }
        if(ind<0)
            continue;
        while(l>=0)
        {
            n3.bucket[i][ind--]=n1.bucket[i][l--];
            if(ind<0)
                break;
        }
        if(ind<0)
            continue;

        while(r>=0)
        {
            n3.bucket[i][ind--]=n2.bucket[i][r--];
            if(ind<0)
                break;
        }
    }

    return n3;
}

ll get(int l,int r)
{
    struct node nn = query(l,r);
    int  bucket[LOG][3];
    rep(i,LOG)
    {
        rep(j,3)
        {    bucket[i][j]=nn.bucket[i][j];
            // pis(nn.bucket[i][j]);
        }
        // pnl();
    }
    ll ans=0;
    for(int i=LOG-1;i>=0;i--)
    {
        int b1 = 0;
        rep(m,3)
        {   if(bucket[i][m]!=-1)
            b1++;
        }

        if(b1==3)
        {
            ll a1,a2,a3;
            a1 = bucket[i][2];
            a2 = bucket[i][1];
            a3 = bucket[i][0];
            if(a1<a2+a3)
            {
                ans = max(ans,a1+a2+a3);
                return ans;
            }
        }
        else if(b1==2)
        {
            // find next index
            ll a1,a2,a3;
            a1 = bucket[i][2];
            a2 = bucket[i][1];
            // int  dif = a1-a2;

            int flag=0;
            for(int j=i-1;j>=0;j--)
            {
                int b2 =0;
                rep(m,3)
                {   if(bucket[j][m]!=-1)
                    b2++;
                }

                if(b2>0)
                {
                    a3 = bucket[j][2];
                    if(a1<a2+a3)
                    {
                    //cout/<<"hh222h"<<a1<<endl;

                        ans = max(ans,a1+a2+a3);
                        return ans;
                    }
                }
            }

            rep(kk,2)
            {
                a1 = bucket[i][1+kk];
                int b2 = 0;
                rep(m,3)
                {   if(bucket[i-1][m]!=-1)
                    b2++;
                }

                if(b2==1)
                {
                    a2 = bucket[i-1][2];
                    for(int j=i-2;j>=0;j--)
                    {
                        int b3 = 0;
                        rep(m,3)
                        {   if(bucket[j][m]!=-1)
                                b3++;
                        }

                        if(b3>0)
                        {
                            a3 = bucket[j][2];
                            if(a1<a2+a3)
                            {    ans = max(ans,a1+a2+a3);
                                flag =1;
                            }
                        }
                    }
                }
                else if(b2>1)
                {
                    a2 = bucket[i-1][2];
                    a3 = bucket[i-1][1];
                    if(a1<a2+a3)
                    {
                        ans = max(ans,a1+a2+a3);
                    }
                }

            }

        }
        else if(b1==1)
        {
            ll a1,a2,a3;
            a1 = bucket[i][2];
            int b2 =0;
            rep(m,3)
            {   if(bucket[i-1][m]!=-1)
                b2++;
            }

            if(b2==1)
            {
                a2 = bucket[i-1][2];
                for(int j=i-2;j>=0;j--)
                {
                    int b3 = 0;
                    rep(m,3)
                    {   if(bucket[j][m]!=-1)
                        b3++;
                    }

                    if(b3>0)
                    {
                        a3 = bucket[j][2];
                        if(a1<a2+a3)
                            ans = max(ans,a1+a2+a3);
                    }
                }
            }
            else if(b2>1)
            {
                a2 = bucket[i-1][2];
                a3 = bucket[i-1][1];
                if(a1<a2+a3)
                    ans = max(ans,a1+a2+a3);
            }

        }

    }

    return ans;
}

int main()
{


    fastRead_int(n);
    fastRead_int(q);
    rep(i,n)
        fastRead_int(arr[i]);
    // cout<<"starting build"<<endl;
    build();
    // cout<<"here"<<endl;
    while(q--)
    {
        int op;
        int l,r;
        fastRead_int(op);
        fastRead_int(l);
        fastRead_int(r);
        if(op==1)
        {
            modify(l-1,r);
        }
        else
        {
            ll ans=0;
            ans = get(l-1,r);
            pln(max(0ll,ans));
        }
    }
}
  
