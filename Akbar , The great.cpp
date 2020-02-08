#include <bits/stdc++.h>
#define SIZE 1000006
using namespace std;

int tc=1,n,r,m;
bitset<SIZE> isSafe;
vector<vector<int>> neighbors;
bool optimum;

void bfs(int k,int s)
{
    queue<pair<int,int>> q;
    q.push(make_pair(k,s));
    
    if(isSafe.test(k))optimum = false;
    isSafe.set(k);
    bitset<SIZE> visited;
    visited.set(k);
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        if(!curr.second)break;
        for(int neighbor:neighbors[curr.first])
        {
            if(!visited.test(neighbor))
            {
                if(isSafe.test(neighbor))optimum = false;
                isSafe.set(neighbor);
                q.push(make_pair(neighbor,curr.second-1));
                visited.set(neighbor);
            }
        }
    }
}

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d%d%d",&n,&r,&m);
    neighbors.clear();
    neighbors.resize(n+5);
    for(int i=0;i<r;i++)
    {
        int e1,e2;
        scanf("%d%d",&e1,&e2);
        neighbors[e1].push_back(e2);
        neighbors[e2].push_back(e1);
    }
}

void solve()
{   
    optimum = true;
    isSafe.reset();
    for(int i=0;i<m;i++)
    {
        int k,s;
        scanf("%d%d",&k,&s);
        bfs(k,s);
    }
    bool allSafe = true;
    for(int i=1;i<=n&&allSafe;i++)allSafe = isSafe.test(i);
    puts(allSafe&&optimum?"Yes":"No");
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
