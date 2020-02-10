#include <bits/stdc++.h>
#define MAXN 100005
#define K 25
using namespace std;

int tc=1,n,lg[MAXN+1],arr[MAXN+1],st[MAXN][K];


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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
}

void solve()
{       
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        int j = lg[R - L + 1];
        printf("%d\n",min(st[L][j], st[R - (1 << j) + 1][j]));
    }
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
