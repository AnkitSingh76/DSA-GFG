class Solution {
  public:
    int minChar(string &s) {
        // code here
        string rev=s;
        reverse(rev.begin(),rev.end());
        int size=s.size();
        s+="$";
        s+=rev;
        
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0,suff=1;
        
        while(suff<n)
        {
            if(s[pre]==s[suff])
            {
                lps[suff]=pre+1;
                pre++,suff++;
            }
            else
            {
                if(pre==0)
                    suff++;
                
                else
                {
                    pre=lps[pre-1];
                }
            }
        }
        
        return size - lps[n-1];
        
    }
};
