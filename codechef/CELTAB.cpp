#include<stdio.h>
#include<iostream>

main()
{   int test;
    int dummy=0;
    scanf("%d",&test);
    while(test--)
    {

        int i,j,k,l,m,n,p,c=0,s;
        scanf("%d %d",&m,&n);
        int a[405],b[405],q,max;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(j=0;j<m;j++)
            b[j]=-1;  //initialize all frame elements with -1
        for(i=0;i<n;i++)
        {
            for(k=0;k<m;k++)
                if(b[k]==a[i])
                    goto here;
            for(j=0;j<m;j++)
            {
                if(b[j]==-1)//check if element already present in frame,if true then no page fault.
                {
                    b[j]=a[i];
                    c++;
                    goto here;
                }
            }

            if(j==m)
            {
                l=i+1,max=0;
                for(j=0;j<m;j++)
                {

                    for(s=l;s<n;s++)
                    {
                        if(a[s]==b[j])
                        {
                            if(s>max)
                            {
                                max=s;
                                p=j;
                            }
                            break;
                        }

                    }
                    if(s==n)
                    {
                        max=s;
                        p=j;
                    }

                }
            }
            b[p]=a[i];
            c++;
            here: dummy++;
        }
        printf("%d\n",c);
    }
}
 
