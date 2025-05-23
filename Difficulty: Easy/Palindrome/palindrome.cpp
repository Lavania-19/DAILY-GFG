// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int n) {
        // Code here.
         if(n<0) return false;
           int revn =0;
           int dup =n;
        while(n != 0){
          int  lastdigit = n %10;
            
            revn =(revn *10) + lastdigit;
            n = n/10;
        }        
        return dup == revn;
    }
};