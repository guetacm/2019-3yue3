#include<iostream>
#include<cstring>
using namespace std;

int sum;
int n;
int data[15];
int vis[15];
int ans[100][15];
int check;
int step;

void dfs(int summ,int loc){
    if(summ>sum) return;
    if(summ==sum){
        /*for(int i=1;i<=n;i++){
            if(vis[i]) cout<<data[i]<<" ";
        }
        cout<<endl;*/
        check=1;
        for(int i=1;i<=step;i++){
            int t=1;
            int countt=1;
            for(int j=1;j<=n;j++){
                if(vis[j]){
                    countt++;
                    if(data[j]==ans[i][t]) t++;
                }
            }
            if(t>1&&countt>1&&t==countt) return;
        }
        int j=1;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                ans[step][j]=data[i];
                j++;
            }
        }
        step++;
        return;
    }
    for(int i=loc;i<=n;i++){
        if(vis[i]==0){
            summ+=data[i];
            vis[i]=1;
            dfs(summ,i);
            summ-=data[i];
            vis[i]=0;
        }
    }
    return;
}

int main(){
    while(cin>>sum>>n){
        if(sum==0&&n==0) break;
        memset(data,0,sizeof(data));
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        step=1;
        for(int i=1;i<=n;i++){
            cin>>data[i];
        }
        cout<<"Sums of "<<sum<<":"<<endl;
        check=0;
        dfs(0,1);
        if(check==0) cout<<"NONE"<<endl;
        if(check==1){
            for(int i=1;i<step;i++){
                cout<<ans[i][1];
                for(int j=2;j<=12;j++){
                    if(ans[i][j]!=0) cout<<"+"<<ans[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}