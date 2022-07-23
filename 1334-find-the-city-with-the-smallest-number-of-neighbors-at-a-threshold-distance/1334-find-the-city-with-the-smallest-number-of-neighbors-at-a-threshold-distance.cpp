class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(auto e:edges){
            int u=e[0], v=e[1], w=e[2];
            dp[u][v]=w;
            dp[v][u]=w;
        }
        for(int i=0; i<n; i++) dp[i][i]=0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX)
                        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        int res=INT_MAX, node=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dp[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=res){
                res=cnt;
                node=i;
            }
        }
        return node;
    }
};