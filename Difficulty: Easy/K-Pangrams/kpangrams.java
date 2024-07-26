//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine().trim());
        while (t-- > 0) {
            String str = sc.nextLine();
            int k = Integer.parseInt(sc.nextLine().trim());
            Solution obj = new Solution();
            if (obj.kPangram(str, k))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    boolean isCharacter(char ch)
    {
        if(ch>='a' && ch<='z'){
            return true;
        }
        
        return false;
    }
    boolean kPangram(String str, int k) {
        
      
        int[] arr = new int[26];
        
        int c=0;
        int count=0;
        
        char temp = ' ';
        
        for(int i=0;i<str.length();i++)
        {
             temp = Character.toLowerCase(str.charAt(i));
            
            if(isCharacter(temp)){
                arr[temp - 'a']++;
                
                count++;
            }
        }
        
        
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==0){
                c++;
            }
        }
        
        
        if((count>=26) && (c<=k))
        {
            return true;
        }
        
        
        return false;
        
    }
}