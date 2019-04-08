#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        int dp[105]={0};
        cin>>m>>n;
        for(int i=0;i<n;i++){
            int v,w,s;
            cin>>v>>w>>s;
            for(int j=m;j>=0;j--){
                for(int k=1;k<=s;k++){
                    if(k*v>j) break;
                    dp[j]=max(dp[j],dp[j-k*v]+k*w);
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}