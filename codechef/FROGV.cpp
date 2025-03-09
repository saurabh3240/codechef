/* user :saurabh3240
	contest : JUNE 14
	problem: FROGV
	platform :CodeChef
	date: 5-7-2014
*/

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
struct node
{
	int x;
	int index;
};

int compare(void const* a, void const* b)
{
	int x = (*(struct node*)a).x - (*(struct node*)b).x;
	if(x==0)
	{
		return (*(struct node*)a).index-(*(struct node*)b).index;
	}
	return x;
}

int main()
{
	int n,k,p;
	gi(n);
	gi(k);
	gi(p);
	struct node arr[n];
	int group[n];
	rep(i,n)
	{
		gi(arr[i].x);
		arr[i].index = i;
	}
	qsort(arr,n,sizeof(struct node),compare);
	group[arr[0].index]=1;
	int cc = 1;
	for(int i=1;i<n;i++)
	{
		if((arr[i].x-arr[i-1].x)<=k)
		{
			group[arr[i].index]=cc;
		}
		else
		{	cc++;
			group[arr[i].index]=cc;
		}
	}
	int a,b;
	while(p--)
	{
		gi(a);
		gi(b);
		if(group[a-1]==group[b-1])
			printf("Yes\n");
		else
			printf("No\n");
	}

}
 
