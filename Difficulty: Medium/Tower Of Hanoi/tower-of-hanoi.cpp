class Solution {
  public:
    void TOH(int n ,int source, int help, int destination){
        if(n==1){
        return;
        }
    TOH(n-1,source,destination,help);
          
    TOH(n-1,help,source,destination);
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        TOH(n,from,aux,to);
        return pow(2,n)-1;
    }
};