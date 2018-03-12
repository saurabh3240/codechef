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
#define LOG 51
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




struct node
{
    int bucket[51];
};
struct node s[4*100005];
int n,q;

void build(int id = 1,int l = 0,int r = n)         //root index 1,children 2x,2x+1
{                          // root = [0,n)
    // cout<<id<<" "<<l<<" "<<r<<endl;
    if( l+1 == r )
    {
        rep(i,LOG)
                s[id].bucket[i]=-1;

        s[id].bucket[LOG-1]=arr[l];
        // cout<<id<<" "<<arr[l]<<endl;
        return;             // comes from array
    }

    ll mid = l + (r-l)/2;
    int left =id*2;
    int right = id*2+1;
    build( left, l, mid);           // interval = [left,right)
    build( right, mid, r);
    rep(i,LOG)
            s[id].bucket[i]=-1;

    // Merge sort

    int ind = LOG-1;
    int l0 = LOG-1;
    int r0 = LOG-1;


    while(l0>=0&&r0>=0)
    {
        if(s[left].bucket[l0]<0)
            break;

        if(s[right].bucket[r0]<0)
            break;



        if(s[left].bucket[l0]>s[right].bucket[r0])
        {
            s[id].bucket[ind--]=s[left].bucket[l0--];
        }
        else
        {
            s[id].bucket[ind--]=s[right].bucket[r0--];
        }

        if(ind<0)
            break;
        // cout<<ind<<endl;
    }
    while(l0>=0)
    {
        if(s[left].bucket[l0]<0)
            break;

        s[id].bucket[ind--]=s[left].bucket[l0--];
        if(ind<0)
            break;


    }

    while(r0>=0)
    {
        if(s[right].bucket[r0]<0)
            break;

        s[id].bucket[ind--]=s[right].bucket[r0--];
        if(ind<0)
            break;

    }
    // cout<<id<<endl;
    // rep(i,LOG)
    //     cout<<s[id].bucket[i]<<" ";
    // cout<<endl;

}
void modify(int p, int  x, int id=1, int l=0, int r=n)    // call modify(p,x)
{
                    //x is the value to which a[p] is changed
    //s[id] += x-a[p] ;         // change the value of the segtree node
    if( l+1 == r)
    {           // l=r-1=p
        rep(i,LOG)
            s[id].bucket[i]=-1;

       arr[p]=x;
       s[id].bucket[LOG-1]=arr[l];
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
        s[id].bucket[i]=-1;
    }

    int ind = LOG-1;
    int l0 = LOG-1;
    int r0 = LOG-1;
    while(l0>=0&&r0>=0)
    {
        if(s[left].bucket[l0]<0)
            break;
        if(s[right].bucket[r0]<0)
            break;

        if(s[left].bucket[l0]>s[right].bucket[r0])
        {
            s[id].bucket[ind--]=s[left].bucket[l0--];
        }
        else
        {
            s[id].bucket[ind--]=s[right].bucket[r0--];
        }
        if(ind<0)
            break;
    }
    while(l0>=0)
    {
        if(s[left].bucket[l0]<0)
            break;

        s[id].bucket[ind--]=s[left].bucket[l0--];
        if(ind<0)
            break;


    }

    while(r0>=0)
    {
        if(s[right].bucket[r0]<0)
            break;

        s[id].bucket[ind--]=s[right].bucket[r0--];
        if(ind<0)
            break;

    }

}

struct node query(int x,int y,int id=1,int l=0,int r=n){        //verify return type
                            // call query(l,r)
    struct node zero;

    // cout<<x<<" "<<y<<"-"<<id<<"-"<<l<<"-"<<r<<endl;
    if( x >= r or l >= y )
    {
        rep(i,LOG)
            zero.bucket[i]=-1;

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
            n3.bucket[i]=-1;
    }

        int ind = LOG-1;
        int l0 = LOG-1;
        int r0 = LOG-1;
        while(l0>=0&&r0>=0)
        {   if(n1.bucket[l0]<0)
                break;
            if(n2.bucket[r0]<0)
                break;
            if(n1.bucket[l0]>n2.bucket[r0])
            {
                n3.bucket[ind--]=n1.bucket[l0--];
            }
            else
            {
                n3.bucket[ind--]=n2.bucket[r0--];
            }
            if(ind<0)
                break;

        }
        while(l0>=0)
        {

            if(n1.bucket[l0]<0)
                break;
                
            n3.bucket[ind--]=n1.bucket[l0--];
            if(ind<0)
                break;
        }

        while(r0>=0)
        {
            if(n2.bucket[r0]<0)
                break;

            n3.bucket[ind--]=n2.bucket[r0--];
            if(ind<0)
                break;

        }

    return n3;
}

ll get(int l,int r)
{
    struct node nn = query(l,r);
    ll  bucket[LOG];
    rep(i,LOG)
    {
        bucket[i]=nn.bucket[i];
        // pis(bucket[i]);
    }
    ll ans=0;
    for(int i=LOG-1;i>=2;i--)
    {
        ll a= bucket[i];
        ll b= bucket[i-1];
        ll c= bucket[i-2];
        // cout<<a<<b<<c<<endl;
        if(a!=-1&&b!=-1&&c!=-1&&a<b+c)
        {    ans = a+b+c;
            return ans;
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
