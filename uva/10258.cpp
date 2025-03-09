/* user :saurabh3240
    contest : codeforces 311 2015
    problem:  A
    platform :CKISSHUG
    date: 30-06-2015
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
#include <unordered_map>
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
#define limit 100005
 
int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
   }
 
 
unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
 
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;
		a = b;
		b = r;
	}
	return a;
}
void printspace(int x)
{
	rep(i,x)
		printf(" ");
}

void printschar(int x,char c)
{
	rep(i,x)
		printf("%c",c);
}
int string2int(string s)
{
	int  ans=0;
	rep(i,s.size())
	{
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
		
}

int main()
{
	int t;
	cin>>t;
	string line;
	cin.ignore();
	getline(cin,line);
	while(t--)
	{	
		int i=1;
		vector<vector<int>  >v;
		while(getline(cin,line))
		{			
			if(line.size()==0)
				break;
			istringstream iss(line);
			int ct,p,t;
			char res;
			vector<int> temp;
			iss>>ct>>p>>t>>res;
			temp.pb(ct);
			temp.pb(p);
			temp.pb(t);
			temp.pb(i);
			if(res=='C')
			{
				temp.pb(1);
				v.pb(temp);	
			}
			else if(res =='I')
			{
				temp.pb(0);
				v.pb(temp);
			
			}
			else
			{
				temp.pb(-1); // no effect
				v.pb(temp);
				
			}
			

			i++;
		}
		sort(v.begin(),v.end());
		vector<vector<int> > vv;
		map<int,int> solved;
		map<int,int> timetotal;
		int x = -1;
		int time =0;
		int nos =0;
		vector<vector<int> >ans;
		
		
		rep(i,v.size())
		{
			int p = v[i][1]; // problem
			
			int t = v[i][2];  // timestamp;
			
			if(x!=v[i][0]) // if different contestant
			{
				if(x!=-1)   // store the previous values 
				{
					vector<int> temp;  
					temp.pb(-nos);
					temp.pb(time);  
					temp.pb(x);
					ans.pb(temp);
				}
				x = v[i][0];
				time =0;
				nos = 0;
				timetotal.clear();
				solved.clear();
				// change the contestant
				if(v[i][4]==1) //solved
				{		
						nos++;
						solved[p]=1;
						time+=t;
				}
				else if(v[i][4]==0)
				{
					timetotal[p]+=20;
				}
				
			}
			else  // same consitent
			{
				if(v[i][4]==1) // if solved
				{
					if(solved[p]==1) // already solved)
					{
						//skip
					}
					else // first time solved
					{	
						nos++;
						solved[p]=1;
						time+=t;
						time+=timetotal[p];
					}
					
				} 
				else if(v[i][4]==0&&solved[p]==0) // 
				{
					timetotal[p]+=20;			
				}			
				
			}
		}
		vector<int> temp;
		temp.pb(-nos);
		temp.pb(time);
		temp.pb(x);
		ans.pb(temp);

		sort(ans.begin(),ans.end());
		rep(i,ans.size())
		{
			cout<<ans[i][2]<<" "<<-ans[i][0]<<" "<<ans[i][1]<<endl;
		}
		
		if(t!=0)	
		cout<<endl;
		
	}
}

