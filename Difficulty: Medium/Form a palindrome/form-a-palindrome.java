//{ Driver Code Starts
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String str = read.readLine();

            Solution ob = new Solution();
            
            System.out.println(ob.countMin(str));
        }
    } 
} 
// } Driver Code Ends



//User function Template for Java

class Solution{
     static int countMin(String str) {
        // code here
        int ans = 0;
        int n = str.length();
        String rev = helper(str);
        int lcs = TabulationSpaceOptimisation(str,rev,n,n);
        return n - lcs;
    }
     static String helper(String str){
        String ans = "";
        for(int i=str.length()-1;i>=0;i--){
            ans += str.charAt(i);
        }
        return ans;
    }
     static int TabulationSpaceOptimisation(String s1, String s2, int m, int n){
        int max = Math.max(m,n);
        int[] prev = new int[max+1];
        int[] curr = new int[max+1];

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = Math.max(prev[j], curr[j-1]);
                }
            }
            System.arraycopy(curr, 0, prev, 0, n+1); // Correct way to copy curr to prev
        }
        return prev[n];
    }
}