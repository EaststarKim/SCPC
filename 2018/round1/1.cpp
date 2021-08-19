#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int a[200010];
int main(){
    int t,i,j,l,tc,n,k,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        sort(a+1,a+n+1);
        ans=1;
        priority_queue<int>().swap(q);
        q.push(-a[1]);
        for(i=2;i<=n;++i){
            j=-q.top();
            if(a[i]-j>k)q.pop();
            else ++ans;
            q.push(-a[i]);
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}