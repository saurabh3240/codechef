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

int main()
{
	int seq = 1;
	string s;
	printspace(9);
	cout<<"NAME";
	printspace(21);
	
	map<char,int> mp;
/*
1 B, P, F, V
2 C, S, K, G, J, Q, X, Z
3 D, T
4 L
5 M, N
6 R
5. Trailing zeros are appended t
*/
	mp['B'] = 1;
	mp['P'] = 1;
	mp['F'] = 1;
	mp['V'] = 1;
	mp['C'] = 2;
	mp['S'] = 2;
	mp['K'] = 2;
	mp['G'] = 2;
	mp['J'] = 2;
	mp['Q'] = 2;
	mp['X'] = 2;
	mp['Z'] = 2;
	mp['D'] = 3;
	mp['T'] = 3;
	mp['L'] = 4;
	mp['M'] = 5;
	mp['N'] = 5;
	mp['R'] = 6;

	map<char,int> mp2;
	mp2['A']= 1;
	mp2['E'] = 1;
	mp2['I']= 1;
	mp2['O'] = 1;
	mp2['U']= 1;
	mp2['Y'] = 1;
	mp2['W'] = 1;
	mp2['H'] = 1;
	
	


	cout<<"SOUNDEX CODE"<<endl;
	while(cin>>s)
	{	
		string code = "";
		printspace(9);
		cout<<s;
		code+=s[0];
		int prev=0;
		forup(i,1,s.size())
		{
			if(mp2[s[i]])
			{	prev  = i;
				continue;
			}
			if(mp[s[i]]==mp[s[prev]])
			{	prev = i;
				continue;
			}
			else
			{
				int x = mp[s[i]];
				code+=x+'0';
				prev = i;
			}
		}
		int y = 34-9-s.size();
		//cout<<y<<"sss   "<<endl;
		printspace(y);
		
		if (code.size()<4)
		{
			cout<<code;
			printschar(4-code.size(),'0');
		}
		else
		{	
			rep(i,4)
				cout<<code[i];

		}
		cout<<endl;
		

	}	
	printspace(19);
	cout<<"END OF OUTPUT"<<endl;
}

