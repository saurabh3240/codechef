/* Author :Saurabh
   Problem :MAXdiff
   */
#include<iostream>
#include<stdio.h>
using namespace std;
int compare (const void *elem1, const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {         int n,k;
              scanf("%d %d",&n,&k);
              int a[n];
              for(int i =0;i<n;i++)
                      scanf("%d",&a[i]);
              qsort(a,n,sizeof(int),compare);
              int p=0,c=0;
              if(k<=n/2)
              {
                       for(int i =0;i<n;i++)
                       {
                               if(i<k)
                                       c = c+a[i];
                               else
                                       p=p+a[i];

                       }

              }
              else
              {
                       for(int i=0;i<n;i++)
                       {
                               if(i<k)
                                       c = c+a[n-1-i];
                               else
                                       p=p+a[n-1-i];

                       }

              }
              printf("%d\n",abs(p-c));
    }

}
