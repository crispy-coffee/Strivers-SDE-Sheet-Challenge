void dfs(int i, int j, int n, int m, int** arr /*, vector<vector<bool>>& visited*/){
   if(i<0 or i>=n or j<0 or j>=m or arr[i][j] == 0 /*or visited[i][j] == true*/)
      return;
   
   // visited[i][j] = true;
   arr[i][j] = 0;

   dfs(i-1, j+0, n, m, arr /*, visited*/);
   dfs(i-1, j+1, n, m, arr /*, visited*/);
   dfs(i+0, j+1, n, m, arr /*, visited*/);
   dfs(i+1, j+1, n, m, arr /*, visited*/);
   dfs(i+1, j+0, n, m, arr /*, visited*/);
   dfs(i+1, j-1, n, m, arr /*, visited*/);
   dfs(i+0, j-1, n, m, arr /*, visited*/);
   dfs(i-1, j-1, n, m, arr /*, visited*/);
}

int getTotalIslands(int** arr, int n, int m)
{
   // vector<vector<bool>> visited(n, vector<bool>(m,false));
   int count = 0;
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         if(arr[i][j] == 1 /*and visited[i][j] == false*/){
            count++;
            dfs(i, j, n, m, arr /*, visited*/);
         }
      }
   }
   return count;
}
