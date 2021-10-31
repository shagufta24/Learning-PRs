import java.util.*;

// Java program to find optimal parenthesization in matrix chain multiplication.
class MatrixChain
{
    static char name;

    //To find optimal parenthesization
    static void Parenthesis(int i, int j, int n, int[][] bracket)
        {
        // Base case: one matrix left
        if (i == j)
        {
            System.out.print(name++);
            return;
        }
        System.out.print("(");

        // Recursively putting brackets around subexpression from i to bracket[i][j]
        Parenthesis(i, bracket[i][j], n, bracket);

        // Recursively putting brackets around subexpression from bracket[i][j] + 1 to j
        Parenthesis(bracket[i][j] + 1, j, n, bracket);
        System.out.print(")");
    }

    // p[] represents chain of matrices (n-1 matrices)
    // Each matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    static void matrixChain(int p[], int n)
    {
        //0th row and 0th column of m[][] are not used, created for simplicity
        int[][] m = new int[n][n];

        // bracket[i][j] stores optimal splitting point in subexpression from i to j.
        int[][] bracket = new int[n][n];

        /* 
        m[i,j] = Minimum number of scalar multiplications needed to compute the 
        matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] 
        */

        // cost is zero when multiplying one matrix.
        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        // L is matrix chain length.
        for (int L = 2; L < n; L++)
        {
            for (int i = 1; i < n - L + 1; i++) //for each matrix chain length from 2 to n
            {
                int j = i + L - 1;   // i is first, j is last matrix in chain
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j - 1; k++)
                {
                    // q = cost per scalar multiplication
                    // cost[i,j] = min {cost[i,k] + cost[k+1,j] + dim(i-1) * dim(k) * dim(j)} for i<=k<j
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) //picking minimum q - least cost multiplication for length L of matrix chain
                    {
                        m[i][j] = q;
                        // Each entry in bracket[i,j] = k shows where to split the product arr i,i+1....j 
                        //for the minimum cost
                        bracket[i][j] = k;
                    }
                }
            }
        }

        // The first matrix is printed as 'A', next as 'B' and so on
        name = 'A';
        System.out.println("\nOptimal Parenthesization: ");
        Parenthesis(1, n - 1, n, bracket);
        System.out.print("\nOptimal Cost: " + m[1][n - 1]);
    }

    // Driver code
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of matrices: ");
        int n = sc.nextInt() + 1;

        int[] arr = new int[n];
        System.out.println("Enter dimensions for matrix chain:\n (Example: A (30x10) multiplied with B (10x5) will be: 30 10 5) \n");
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        char mat = 'A';
        System.out.print ("Matrices are: ");
        for(int i = 0; i < n-1; i++){
            System.out.print(mat++ + " ");
        }

        matrixChain(arr, n);
    }
}