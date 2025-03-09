#include<stdio.h>
#include<string.h>
int main()
{
    register int t,len;
    char s[2014];
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s",s);
	   len=strlen(s);
	   while(len--)
	   {
		     if((s[len]=='?' || s[len]=='F') && (s[len-1]=='?' || s[len-1]=='E') && (s[len-2]=='?' || s[len-2]=='H') && (s[len-3]=='?' || s[len-3]=='C'))
		     {
			 s[len]='F';
			 s[len-1]='E';
			 s[len-2]='H';
			 s[len-3]='C';
			 len=len-3;
		    }
		    else
			    if(s[len]=='?')
				               s[len]='A';
	   }
	   printf("%s\n",s);
    }
    return 0;
}
