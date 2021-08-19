#include <bits/stdc++.h>
using namespace std;
vector<int> e[200010];
int d[200010];
struct data{
    int x,d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
};
priority_queue<data> q;
int main(){
    int t,i,j,tc,n,m,x,y;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i){
            vector<int>().swap(e[i]);
            d[i]=0;
        }
        for(i=1;i<=m;++i){
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
            ++d[x],++d[y];
        }
        priority_queue<data>().swap(q);
        for(i=1;i<=n;++i)sort(e[i].begin(),e[i].end()),q.push({i,d[i]});
        while(!q.empty()){
            i=q.top().x,j=q.top().d,q.pop();
            if(d[i]!=j)continue;
            if(d[i]>2)break;
            if(d[i]<2)continue;
            x=y=0;
            for(j=0;j<e[i].end()-e[i].begin();++j)if(d[e[i][j]]){
                if(x){
                    y=e[i][j];
                    break;
                }
                else x=e[i][j];
            }
            j=lower_bound(e[x].begin(),e[x].end(),y)-e[x].begin();
            if(j==e[x].end()-e[x].begin()||e[x][j]!=y)continue;
            d[i]=0;
            q.push({x,--d[x]});
            q.push({y,--d[y]});
            --n;
        }
        printf("Case #%d\n%d\n",t,n);
    }
    return 0;
}