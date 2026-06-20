class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // Code here
        int row=mat.size(),col=mat[0].size();
       int i,j;
           
        for(i=0;i<row;i++){
             int start=0,end=row-1;
             while(start<end){
             swap(mat[i][start],mat[i][end]);
             start++,end--;
             }
        }
        for(j=0;j<col;j++){
             int start=0,end=row-1;
             while(start<end){
             swap(mat[start][j],mat[end][j]);
             start++,end--;}
        }
    
    }
};