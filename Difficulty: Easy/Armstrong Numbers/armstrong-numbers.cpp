// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum =0;
        int num = n;
        while(n!=0){
            int ld = n%10;
            sum = sum +(ld*ld*ld);
            n=n/10;
            
        }
        return sum == num ? true:false;
    }
};