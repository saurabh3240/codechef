
 
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
 
 
int main()
{	
	int t;
	gi(t);
	while(t--)
	{
		vector<int> v[26];

		string s;
		cin>>s;
		
		int n = s.size();
		int arr[n];
		int flag=1;
		int a  =0;
		int b = n-1;
		rep(i,n)
		{
			v[s[i]-'a'].pb(i);
		}
		if(n%2==0)
		{
			rep(i,26)
			{
				int x = v[i].size();
				if(x%2==0)
				{
					rep(j,x/2)
					{
						arr[a++]=v[i][j];
						arr[b--]=v[i][x-j-1];
					}
				}	
				else
				{
					flag =0;
					break;
				}
			}
		}
		else
		{	int odd =0;
			int flag2=1;
			int mid = n/2;
			rep(i,26)
			{
				int x = v[i].size();
				if(x%2==0)
				{
					rep(j,x/2)
					{
						arr[a++]=v[i][j];
						arr[b--]=v[i][x-j-1];
					}
				}	
				else
				{
					if(odd==1)
					{	flag=0;
						break;
					}
					else
					{
						rep(j,x/2)
						{
							arr[a++]=v[i][j];
							arr[b--]=v[i][x-j-1];
						}
						arr[mid]=v[i][x/2];
						odd++;
					}
				}
			}
		}
		if(flag==0)
			cout<<-1<<endl;
		else
		{
			rep(i,n)
				pis(arr[i]+1);
			cout<<endl;
		}
	}
}