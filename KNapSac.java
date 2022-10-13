// K-Nap Sac Problem implemented using Dynamic Programming

import java.util.*;

public class KNapSac {
    public static void main(String[] args) {
        int[] weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] values = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
        int capacity = 10;
        int[][] table = new int[weights.length + 1][capacity + 1];
        for (int i = 0; i < table.length; i++) {
            for (int j = 0; j < table[i].length; j++) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                } else if (weights[i - 1] <= j) {
                    table[i][j] = Math.max(values[i - 1] + table[i - 1][j - weights[i - 1]], table[i - 1][j]);
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        System.out.println("The maximum value is: " + table[weights.length][capacity]);
        System.out.println("The items that are included are: ");
        int i = weights.length;
        int j = capacity;
        while (i > 0 && j > 0) {
            if (table[i][j] != table[i - 1][j]) {
                System.out.println(weights[i - 1]);
                j = j - weights[i - 1];
            }
            i--;
        }
    }
}