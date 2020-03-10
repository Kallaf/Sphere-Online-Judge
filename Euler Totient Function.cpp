#include<bits/stdc++.h>
using namespace std;

int tc=1,n;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
}

void solve()
{
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    printf("%d\n",result);
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        solve();
    }
    return 0;
}
