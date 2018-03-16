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
#define LOG 55
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
    int bucket[LOG];
};
struct node tree[4*100005];
int n,q;

void build_tree(int node, int a, int b)
{
    if(a > b) return; // Out of range

    rep(i,LOG)
        tree[node].bucket[i]=-1;

  	if(a == b) { // Leaf node
    		tree[node].bucket[LOG-1] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

    int left = node*2;
    int right = node*2+1;
    // merge
    int l=LOG-1;
    int r =LOG-1;
    int ind = LOG-1;
    while(l>=0&&r>=0)
    {
        if(tree[left].bucket[l]<0&& tree[right].bucket[r]<0)
            break;
        if(tree[left].bucket[l]>tree[right].bucket[r])
            tree[node].bucket[ind--] = tree[left].bucket[l--];
        else
            tree[node].bucket[ind--] = tree[right].bucket[r--];
        if(ind<0)
            return;
    }
    while(l>=0)
    {
        if(tree[left].bucket[l]<0)
            break;
        tree[node].bucket[ind--] = tree[left].bucket[l--];
        if(ind<0)
            return;

    }
    while(r>=0)
    {
        if(tree[right].bucket[r]<0)
            break;
        tree[node].bucket[ind--] = tree[right].bucket[r--];
        if(ind<0)
            return;
    }

}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

    rep(i,LOG)
        tree[node].bucket[i]=-1;

  	if(a == b) { // Leaf node


    		tree[node].bucket[LOG-1] = value;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    int left = node*2;
    int right = node*2+1;
    // merge
    int l=LOG-1;
    int r =LOG-1;
    int ind = LOG-1;
    while(l>=0&&r>=0)
    {
        if(tree[left].bucket[l]<0&& tree[right].bucket[r]<0)
            break;
        if(tree[left].bucket[l]>tree[right].bucket[r])
            tree[node].bucket[ind--] = tree[left].bucket[l--];
        else
            tree[node].bucket[ind--] = tree[right].bucket[r--];
        if(ind<0)
            return;
    }
    while(l>=0)
    {
        if(tree[left].bucket[l]<0)
            break;
        tree[node].bucket[ind--] = tree[left].bucket[l--];
        if(ind<0)
            return;

    }
    while(r>=0)
    {
        if(tree[right].bucket[r]<0)
            break;
        tree[node].bucket[ind--] = tree[right].bucket[r--];
        if(ind<0)
            return;
    }

	// /tree[node] = min(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
struct node query_tree(int node, int a, int b, int i, int j) {

    struct node q3;
    rep(i,LOG)
        q3.bucket[i]=-1;

	if(a > b || a > j || b < i) return q3; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

    struct node q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	struct node q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    // struct node q3s;
//	int res = min(q1, q2); // Return final result
    int l=LOG-1;
    int r =LOG-1;
    int ind = LOG-1;
    while(l>=0&&r>=0)
    {
        if(q1.bucket[l]<0&& q2.bucket[r]<0)
            break;
        if(q1.bucket[l]>q2.bucket[r])
            q3.bucket[ind--] = q1.bucket[l--];
        else
            q3.bucket[ind--] = q2.bucket[r--];
        if(ind<0)
            return q3;
    }
    while(l>=0)
    {
        if(q1.bucket[l]<0)
            break;
        q3.bucket[ind--] = q1.bucket[l--];
        if(ind<0)
            return q3;

    }
    while(r>=0)
    {
        if(q2.bucket[r]<0)
            break;
        q3.bucket[ind--] = q2.bucket[r--];
        if(ind<0)
            return q3;

	return q3;
    }
    return q3;
}



ll get(int l,int r)
{
    struct node nn = query_tree(1,0,n-1,l-1,r-1);
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
        if(a!=-1ll&&b!=-1ll&&c!=-1ll&&a<b+c)
        {    ans = max(ans,a+b+c);
        }
    }
    return ans;
}

int main()
{


    gi(n);
    gi(q);
    rep(i,n)
        gi(arr[i]);
    // cout<<"starting build"<<endl;
    build_tree(1,0,n-1);
    // cout<<"here"<<endl;
    while(q--)
    {
        int op;
        int l,r;
        gi(op);
        gi(l);
        gi(r);
        if(op==1)
        {
            update_tree(1,0,n-1,l-1,l-1,r);
        }
        else
        {
            ll ans=0;
            ans = get(l,r);
            pln(max(0ll,ans));
        }
    }
}
