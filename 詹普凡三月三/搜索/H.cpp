#include<iostream>
#include<cstring>
using namespace std;

char mapp[10][10];
int h,l,t;
int x,y;
int ans;

bool check(int h1,int l1){
    if(mapp[h1][l1]=='X') return false;
    return true;
}

void dfs(int h1,int l1,int timee){
    //cout<<h1<<" "<<l1<<" "<<mapp[h1][l1]<<" "<<timee<<endl;
    h1++;
    if(check(h1,l1)){
        int k=1;
        if(mapp[h1][l1]=='D'){
            if(timee==t){
                ans=timee;
                return;
            }
            if(timee!=t){
                k=0;
            }
        }
        if(k){
            mapp[h1][l1]='X';
            dfs(h1,l1,timee+1);
            mapp[h1][l1]='.';
        }
    }
    h1=h1-2;
    if(check(h1,l1)){
        int k=1;
        if(mapp[h1][l1]=='D'){
            if(timee==t){
                ans=timee;
                return;
            }
            if(timee!=t){
                k=0;
            }
        }
        if(k){
            mapp[h1][l1]='X';
            dfs(h1,l1,timee+1);
            mapp[h1][l1]='.';
        }
    }
    h1++;
    l1++;
    if(check(h1,l1)){
        int k=1;
        if(mapp[h1][l1]=='D'){
            if(timee==t){
                ans=timee;
                return;
            }
            if(timee!=t){
                k=0;
            }
        }
        if(k){
            mapp[h1][l1]='X';
            dfs(h1,l1,timee+1);
            mapp[h1][l1]='.';
        }
    }
    l1=l1-2;
    if(check(h1,l1)){
        int k=1;
        if(mapp[h1][l1]=='D'){
            if(timee==t){
                ans=timee;
                return;
            }
            if(timee!=t){
                k=0;
            }
        }
        if(k){
            mapp[h1][l1]='X';
            dfs(h1,l1,timee+1);
            mapp[h1][l1]='.';
        }
    }
    return;
}

int main(){
    while(cin>>h>>l>>t){
        if(h==0&&l==0&&t==0) break;
        memset(mapp,'X',sizeof(mapp));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>mapp[i][j];
                if(mapp[i][j]=='S'){
                    y=i;
                    x=j;
                }
            }
        }
        ans=0;
        mapp[y][x]='X';
        dfs(y,x,1);
        if(ans==t) cout<<"YES"<<endl;
        if(ans==0) cout<<"NO"<<endl;
    }
    return 0;
}