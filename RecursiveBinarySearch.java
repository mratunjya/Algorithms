import java.util.Scanner;

class RecursiveBinarySearch {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] input = sc.nextLine().split(" ");
        int[] numbers = strToInt(input);
        int search = sc.nextInt();

        if (recursiveBinarySearch(numbers, search) == -1) {
            System.out.println(-1);
        }
    }

    private static int recursiveBinarySearch(int[] numbers, int search) {
        return search(numbers, search, 0, numbers.length -1);
    }

    public static int search(int[] numbers, int search, int left, int right) {
        int middle = (left + right) / 2;
        if (left <= right) {
            System.out.println(middle);
            if (numbers[middle] == search) {
                return middle;
            } else if (numbers[middle] < search) {
                return search(numbers, search, middle + 1, right);
            } else if (numbers[middle] > search) {
                return search(numbers, search, left, middle - 1);
            }
        }
        return -1;
    }

    public static int[] strToInt(String[] array) {
        int[] numbers = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            numbers[i] = Integer.parseInt(array[i]);
        }
        return numbers;
    }
}