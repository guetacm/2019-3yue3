#include<iostream>
#include<cstring>
using namespace std;

int mapp[1005][1005];
int vis[1005][1005];
int m,n;
int check;

bool judge(int h,int l,int h2,int l2){
    if(h<1) return false;
    if(h>n) return false;
    if(l<1) return false;
    if(l>m) return false;
    if(vis[h][l]) return false;
    if(h==h2&&l==l2) return true;
    if(mapp[h][l]!=0) return false;
    return true;
}

void dfs(int h1,int l1,int h2,int l2,int step,int way){//step存储转折几次，way=1时左右移动，way=2时上下移动
    //cout<<h1<<" "<<l1<<" "<<mapp[h1][l1]<<" "<<step<<endl;
    if(h1!=h2&&l1!=l2&&step==2) return;//优化剪枝
    if(step>2) return;
    if(h1==h2&&l1==l2) {
        check=1;
        return;
    }
    if(judge(h1,l1+1,h2,l2)){
        vis[h1][l1+1]=1;
        if(way==0) dfs(h1,l1+1,h2,l2,step,1);//vis[h][l1+1]=0;}
        if(way==1) dfs(h1,l1+1,h2,l2,step,1);//vis[h][l1+1]=0;}
        if(way==2) dfs(h1,l1+1,h2,l2,step+1,1);//vis[h][l1+1]=0;}
        vis[h1][l1+1]=0;
    }
    if(judge(h1,l1-1,h2,l2)){
        vis[h1][l1-1]=1;
        if(way==0) dfs(h1,l1-1,h2,l2,step,1);//vis[x1-1][y1]=0;}
        if(way==1) dfs(h1,l1-1,h2,l2,step,1);//vis[x1-1][y1]=0;}
        if(way==2) dfs(h1,l1-1,h2,l2,step+1,1);//vis[x1-1][y1]=0;}
        vis[h1][l1-1]=0;
    }
    if(judge(h1+1,l1,h2,l2)){
        vis[h1+1][l1]=1;
        if(way==0) dfs(h1+1,l1,h2,l2,step,2);//vis[x1][y1+1]=0;}
        if(way==1) dfs(h1+1,l1,h2,l2,step+1,2);//vis[x1][y1+1]=0;}
        if(way==2) dfs(h1+1,l1,h2,l2,step,2);//vis[x1][y1+1]=0;}
        vis[h1+1][l1]=0;
    }
    if(judge(h1-1,l1,h2,l2)){
        vis[h1-1][l1]=1;
        if(way==0) dfs(h1-1,l1,h2,l2,step,2);//vis[x1][y1-1]=0;}
        if(way==1) dfs(h1-1,l1,h2,l2,step+1,2);//vis[x1][y1-1]=0;}
        if(way==2) dfs(h1-1,l1,h2,l2,step,2);//vis[x1][y1-1]=0;}
        vis[h1-1][l1]=0;
    }
    //check=0;
    return;
}

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapp[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        int cases;
        cin>>cases;
        for(int i=1;i<=cases;i++){
            int h1,l1,h2,l2;
            check=0;
            cin>>h1>>l1>>h2>>l2;
            if(mapp[h1][l1]!=mapp[h2][l2]||mapp[h1][l1]==0||mapp[h2][l2]==0) cout<<"NO"<<endl;
            else{
                dfs(h1,l1,h2,l2,0,0);
                if(check==1) cout<<"YES"<<endl;
                if(check==0) cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}