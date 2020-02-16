#include <bits/stdc++.h>
using namespace std;

int tc=1,a,b,c,idx=1;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d%d%d",&a,&b,&c);
}

void solve()
{   
    printf("Case %d: %s\n",idx++,c%__gcd(a,b)?"No":"Yes");
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
