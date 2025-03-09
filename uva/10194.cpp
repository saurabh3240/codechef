
 
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

string tolower(string a)
{	
	string s = "";
	rep(i,a.size())
	{
		if(a[i]>='A'&&a[i]<='Z')
			s+=(a[i]-'A'+'a');
		else
			s+=a[i];
	}
	return s;
}

int comp2(string a,string b)
{
	while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
	return a>b;
	
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
struct tteam
{
	string name;
	int win; // wins
	int totalpoints; // points
	int gp; // games played
	int ties; // ties
 	int loss;  // losses
	int gd;  // goal difference
	int gs;  // goal scored
	int ga;  // goal against
	
	tteam()
	{
		name = "";
		win = totalpoints =gp = gs =  ties = loss = gd = ga = 0;
	}
};

bool comp(struct tteam a, struct tteam b)
{
	if(a.totalpoints!=b.totalpoints)
	{
		return a.totalpoints > b.totalpoints;
	}
	else
	{
		if(a.win!=b.win)
		{
			return a.win > b.win;
		}
		else
		{
			if(a.gd!=b.gd)
			{
				return a.gd > b.gd;
			}
			else
			{
				if(a.gs!=b.gs)
				{
					return a.gs > b.gs;
				}
				else
				{
					if(a.gp!=b.gp)
					{	
						return a.gp < b.gp;
					
					}
					else
					{
						int x =tolower(a.name).compare(tolower(b.name));
					//	cout<<tolower(a.name);
					//	cout<<tolower(b.name);
					//	cout<<endl;
						//cout<<x<<endl;
						if(x<0)
							return true;
						else
							return false;
					}
				}
			}
		}
	}
	
	
}


int main()
{
	int t;
	cin>>t;
	string tname,s;
	cin.ignore();
	while(t--)
	{
		
		getline(cin,tname);
		cout<<tname<<endl;
		int n;
		cin>>n;
		cin.ignore();
		struct tteam teams[n];
		map<string,int > mp;
		rep(i,n)
		{
			getline(cin,s);
//			teams.pb(s);
			mp[s]=i;
			//	cout<<s<<endl;
			teams[i].name = s;		
		}
		int q;
		cin>>q;
		cin.ignore();
		rep(i,q)
		{
			getline(cin,s);
			// process in put
			string t1,t2,s1,s2;
			s1="";
			t1 = "";
			t2 = "";
			s2 ="";
			int j =0;
			// first team name;
			for(;j<s.size();j++)
			{
				if(s[j]=='#')
					break;
				t1+=s[j];
			}
			j++;
			// first score
			for(;j<s.size();j++)
			{
				if(s[j]=='@')
					break;
				s1+=s[j];
			}
			j++;
			
			for(;j<s.size();j++)
			{
				if(s[j]=='#')
					break;
				s2+=s[j];
			}
			j++;
			for(;j<s.size();j++)
			{
				t2+=s[j];
			}
			
			//cout<<t1<<" "<<t2<<" "<<<<" "<<string2int(s2)<<endl;
			int a1 = string2int(s1);
			int a2 = string2int(s2);
			// process resutls 
			int i1 = mp[t1];
			int i2 = mp[t2];
			
			
			teams[i1].gp++;   // games plauyed
			teams[i2].gp++; 
			
			teams[i1].gd += a1-a2;  // goal diff
			teams[i2].gd += a2-a1;
			
			teams[i1].gs += a1;  // goal scored
			teams[i2].gs += a2;
				
				
			teams[i1].ga += a2;  // goal against
			teams[i2].ga += a1;
				
						
			if(a1>a2)
			{
				
				// for team a 
				teams[i1].totalpoints+=3;  // win 3
				teams[i1].win++; 
				teams[i2].loss++;
								
			}
			else if(a2>a1)
			{
				teams[i2].totalpoints+=3;
				teams[i2].win++;
				teams[i1].loss++;
				
			}
			else
			{
				teams[i1].totalpoints+=1;
				teams[i2].totalpoints+=1;			
				teams[i1].ties++;
				teams[i2].ties++;	
			}
		}
		sort(teams,teams+n,comp);		
		rep(i,n)
		{
			cout<<i+1<<") "<<teams[i].name<<" "<<teams[i].totalpoints<<"p, ";
			cout<<teams[i].gp<<"g ("<<teams[i].win<<"-";
			cout<<teams[i].ties<<"-"<<teams[i].loss<<"), ";
			cout<<teams[i].gd<<"gd ("<<teams[i].gs<<"-"<<teams[i].ga<<")\n";
			
			
		}
		if(t!=0)
		cout<<endl;
	}
	
} 
