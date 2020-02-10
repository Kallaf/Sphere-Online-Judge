#include <bits/stdc++.h>
#define MAXN 100005
#define K 25
using namespace std;

int tc=1,n,q,lg[MAXN+1],arr[MAXN+1],st[MAXN][K];


void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;
}

void input()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
}

void solve()
{       
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    int cnt = 0;
    for(int i=0;i<q;i++)
    {
        int L,R,a;
        scanf("%d%d",&L,&R);
        --L, --R;
        a = arr[L];
        if (L <= R) {
            int j = lg[R - L];
            if (max(st[L][j], st[R - (1 << j)][j]) <= a)
                ++cnt;
        }
        else {
            int j = lg[L - R];
            if (max(st[R][j], st[L - (1 << j)][j]) <= a)
                ++cnt;
        }
    }
    printf("%d\n",cnt);
}

int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
