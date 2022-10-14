// K-Nap Sac 0-1 Problem implemented using Dynamic Programming

import java.util.*;

public class KNapSac01 {
    public static void main(String[] args) {
        int[] weights = {1, 3, 4, 5};
        int[] values = {1, 4, 5, 7};
        int capacity = 7;
        int[][] dp = new int[weights.length + 1][capacity + 1];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j <= capacity; j++) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else if (weights[i] > j) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = Math.max(dp[i][j], dp[i][j - weights[i]] + values[i]);
                }
            }
        }
        System.out.println(dp[weights.length][capacity]);
    }
}