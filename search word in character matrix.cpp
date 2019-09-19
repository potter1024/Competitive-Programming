char arr[100][100];
bool visited[100][100];
bool dfs(ll i,ll j,string c,ll ind)
{
    if(c[ind]!=arr[i][j])
        return 0;
    visited[i][j]=1;
    if(i<0 || j<0 || i>=n || j>=n)
        return 0;
    if(ind==c.size()-1 && arr[i][j]==c[ind])
        return 1;
    return (!visited[i+1][j+1] && dfs(i+1,j+1,c,ind+1)) || 
    (!visited[i-1][j-1] && dfs(i-1,j-1,c,ind+1)) || 
    (!visited[i+1][j-1] && dfs(i+1,j-1,c,ind+1)) || 
    (!visited[i-1][j+1] && dfs(i-1,j+1,c,ind+1)) || 
    (!visited[i][j+1] && dfs(i,j+1,c,ind+1)) || 
    (!visited[i][j-1] && dfs(i,j-1,c,ind+1)) || 
    (!visited[i+1][j] && dfs(i+1,j,c,ind+1)) || 
    (!visited[i-1][j] && dfs(i-1,j,c,ind+1)) ;
}
