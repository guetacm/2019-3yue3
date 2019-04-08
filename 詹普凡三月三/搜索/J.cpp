#include<iostream>
#include<cstring>
using namespace std;

char mapp[205][205];
int vis[205][205];
int h,l,t;

bool check(int h1,int l1){
    if(mapp[h1][l1]=='#'||vis[h1][l1]) return false;
    return true;
}

void dfs(int h1,int l1,int timee){
    //cout<<h1<<" "<<l1<<" "<<mapp[h1][l1]<<" "<<timee<<endl;
    if(timee>t) return;//当计步器比之前记录的终点还要大时，就不要再dfs了
    l1--;
    if(check(h1,l1)){
        if(mapp[h1][l1]=='r'){
            if(t>timee) t=timee;
            return;
        }
        if(mapp[h1][l1]=='.'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+1);
            vis[h1][l1]=0;
        }
        if(mapp[h1][l1]=='x'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+2);
            vis[h1][l1]=0;
        }
    }
    l1=l1+2;
    if(check(h1,l1)){
        if(mapp[h1][l1]=='r'){
            if(t>timee) t=timee;
            return;
        }
        if(mapp[h1][l1]=='.'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+1);
            vis[h1][l1]=0;
        }
        if(mapp[h1][l1]=='x'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+2);
            vis[h1][l1]=0;
        }
    }
    h1--;
    l1--;
    if(check(h1,l1)){
        if(mapp[h1][l1]=='r'){
            if(t>timee) t=timee;
            return;
        }
        if(mapp[h1][l1]=='.'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+1);
            vis[h1][l1]=0;
        }
        if(mapp[h1][l1]=='x'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+2);
            vis[h1][l1]=0;
        }
    }
    h1=h1+2;
    if(check(h1,l1)){
        if(mapp[h1][l1]=='r'){
            if(t>timee) t=timee;
            return;
        }
        if(mapp[h1][l1]=='.'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+1);
            vis[h1][l1]=0;
        }
        if(mapp[h1][l1]=='x'){
            vis[h1][l1]=1;
            dfs(h1,l1,timee+2);
            vis[h1][l1]=0;
        }
    }
    return;
}

int main(){
    while(cin>>h>>l){
        memset(mapp,'#',sizeof(mapp));
        memset(vis,0,sizeof(vis));
        int y,x;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>mapp[i][j];
                if(mapp[i][j]=='a') {y=i;x=j;}
            }
        }
        //比较欣赏的是看到多个起点的时候选择了使用单个终点来dfs
        t=0x3f3f3f;
        int ans=0x3f3f3f;
        vis[y][x]=1;
        dfs(y,x,1);
        if(ans>t) ans=t;
        if(ans==0x3f3f3f) cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
//自己写的总是超时，到网上查了一下才发现一些剪枝的好办法，学到了