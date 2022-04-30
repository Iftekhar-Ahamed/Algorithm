import java.util.Arrays;
import java.util.Scanner;

/**
 * LPS
 */
public class LPS {

    public static void main(String[] args) {
        String s;
        Scanner sc=new Scanner(System.in);
        s = sc.nextLine();
        int n = s.length(), i, x = 0, y = 0, k;
        int[][] dp = new int[n][n];
        for (i = 0; i < n; i++)
        Arrays.fill(dp[i], 0);

        for (i = 0; i < n; i++)
            dp[i][i] = 1;

        for (i = 0; i < n - 1; i++)
            if (s.charAt(i) == s.charAt(i + 1))
                dp[i][i + 1] = 1;

        for (k = 2; k < n; k++) {
            for (i = 0; i < n - k; i++) {
                if (s.charAt(i) == s.charAt(i + k) && dp[i + 1][k + i - 1] == 1) {
                    dp[i][k + i] = 1;
                    x = i;
                    y = k + i;
                }
            }
        }
        System.out.println(y-x);
        sc.close();

    }
}