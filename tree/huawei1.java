import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] rArrStr = scanner.nextLine().split(" ");
        int[] rArr = Arrays.stream(rArrStr).mapToInt(Integer::parseInt).toArray();
        int cnt = scanner.nextInt();

        int left = 0;
        int right = Arrays.stream(rArr).max().getAsInt();
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int sum = Arrays.stream(rArr).map(x -> Math.min(x, mid)).sum();
            if (sum > cnt) {
                right = mid - 1;
            } else {
                left = mid + 1;
                result = mid;
            }
        }

        System.out.println(result);
    }
}