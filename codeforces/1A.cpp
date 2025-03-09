#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    long long n,m,a;
    cin>>n>>m>>a;
    long long x =ceil((double)n/a);
    long long y = ceil((double)m/a);
    
    cout<<x*y;
}