class Solution {
  public:
  
    void BST(int arr[],int &index,int lower,int upper,int N){
        if(index==N || arr[index]<lower || arr[index]>upper){
            return ;
        }
        
        int value=arr[index++];
        BST(arr,index,lower,value,N);
        BST(arr,index,value,upper,N);
    }
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int index=0;
        int N=arr.size();
        int lower=INT_MIN;
        int upper=INT_MAX;
        BST(arr.data(),index,lower,upper,N);
        return index==N;
        
    }
};