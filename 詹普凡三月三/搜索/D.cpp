#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int data[70];
int vis[70];
int counts,length,n;

bool cmp(int a,int b){
    return a>b;
}



bool dfs(int now_counts,int now_length,int now_locate){
    if(now_counts==counts) return true;
    if(now_length==length) return dfs(now_counts+1,0,0);
    for(int i=now_locate;i<n;i++){
        if(vis[i]==0&&(now_length+data[i]<=length)){
            vis[i]=1;
            if(dfs(now_counts,now_length+data[i],i+1)) return true;
            vis[i]=0;
            if(now_length==0) return false;
            while(data[i]==data[i+1]&&i+1<n) i++;
        }
    }
    return false;
}

int main(){
    while(cin>>n){
        if(n==0) break;
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>data[i];
            sum+=data[i];
        }
        sort(data,data+n,cmp);
        int ans=0;
        for(int i=1;i<=sum;i++){
            if(sum%i==0){
                memset(vis,0,sizeof(vis));
                length=i;
                counts=sum/length;
                if(dfs(0,0,0)){
                    ans=length;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
