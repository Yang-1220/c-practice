#include <stdio.h>
#include <string.h>

char x[500005];

long long cntS[26],cntT[26];

int main ()
{
	int T,q,d,i,j;
	long long k;

    scanf("%d",&T);

    while (T--)
    {
        long long S_len=1,T_len=1;
        scanf("%d",&q);
        memset(cntS,0,sizeof cntS);
        memset(cntT,0,sizeof cntT);
        cntS[0]=1;
        cntT[0]=1;
        for (i=0;i<q;i++)
        {
            scanf("%d %lld %s",&d,&k,x);
            if (d==1)
            {
                long long xl=strlen(x);
                for (j=0;j<xl;j++)
                {
                    int c=x[j]-'a';
                    cntS[c]+=k;
                }
                S_len+=xl*k;
            }
            else if (d==2)
            {
                long long xl=strlen(x);
                for (j=0;j<xl;j++)
                {
                    int c=x[j]-'a';
                    cntT[c]+=k;
                }
                T_len+=xl*k;
            }
            int max_T=0;
            for (j=25;j>=0;j--)
            {
                if(cntT[j]>0)
                {
                    max_T=j;
                    break;
                }
            }
            int max_S=0;                       /* \u65b0\u589e\uff1aS \u7684\u6700\u5927\u5b57\u7b26 */
            for (j=25;j>=0;j--)
            {
                if(cntS[j]>0)
                {
                    max_S=j;
                    break;
                }
            }
            if (max_T>0) printf("YES\n");
            else if (max_S==0 && S_len<T_len) printf("YES\n");   /* \u5173\u952e\u4fee\u590d */
            else printf("NO\n");
        }
    }

    return 0;
}
