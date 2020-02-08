#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    if(n==42)exit(0);
    tc = 1;
}
 
void solve()
{   printf("%d\n",n);
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
