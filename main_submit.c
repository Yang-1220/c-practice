#include <stdio.h>
#include <string.h>

char x[500005];
long long cntS[26], cntT[26];

int main()
{
    int T, q, d, i, j;
    long long k;

    scanf("%d", &T);
    while (T--)
    {
        long long S_len = 1, T_len = 1;
        scanf("%d", &q);
        memset(cntS, 0, sizeof cntS);
        memset(cntT, 0, sizeof cntT);
        cntS[0] = cntT[0] = 1;

        while (q--)
        {
            scanf("%d %lld %s", &d, &k, x);   /* %lld \u624d\u80fd\u8de8\u5e73\u53f0\u8bfb long long */
            long long xl = strlen(x);

            if (d == 1)
            {
                for (i = 0; i < xl; i++) cntS[x[i] - 'a'] += k;
                S_len += xl * k;
            }
            else
            {
                for (i = 0; i < xl; i++) cntT[x[i] - 'a'] += k;
                T_len += xl * k;
            }

            int max_T = 0;
            for (j = 25; j >= 0; j--)
                if (cntT[j] > 0) { max_T = j; break; }

            if (max_T > 0) printf("YES\n");
            else if (S_len < T_len && cntS[0] == S_len) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
