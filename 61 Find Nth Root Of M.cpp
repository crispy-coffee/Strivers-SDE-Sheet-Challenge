int NthRoot(int n, int m) {
  // Write your code here.

    for(int i=1; i<=m; i++){  
      double root = pow(i, n);

      if(root == m){
        return i;
      }

      if(root > m){
        break;
      }

    }
    
    return -1;
}