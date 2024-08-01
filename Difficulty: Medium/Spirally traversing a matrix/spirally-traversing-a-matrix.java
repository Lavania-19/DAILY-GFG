//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends



class Solution {
    // Function to return a list of integers denoting spiral traversal of matrix.
    public ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        ArrayList<Integer> result = new ArrayList<>();
        int n=matrix.length;
        int m=matrix[0].length;
        int top=0;
        int right=m-1;
        int left=0;
        int down=n-1;
        int dir=0;
        int k=0;
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++)
                    result.add(matrix[top][i]);
                top=top+1;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++)
                    result.add(matrix[i][right]);
                right=right-1;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--)
                    result.add(matrix[down][i]);
                down=down-1;
            }
            else if(dir==3){
                for(int i=down ;i>=top;i--)
                    result.add(matrix[i][left]);            
                left=left+1;
            }
            dir=(dir+1)%4;
            }
            return result;
        // code here
    }
}