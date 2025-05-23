class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int revn = 0;
        while(n != 0){
            int lastdigit = n %10;
            revn = (revn *10)+ lastdigit;
            n = n/10;
        }
        return revn;
    }
};