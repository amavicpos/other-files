import java.util.*;

public class SieveOfEratosthenes {
    // This class uses Eratosthenes' technique to find all prime numbers up to a limit number

    void sieveOfEratosthenes(int limit) {
        boolean output[] = new boolean[limit + 1];
        for (int x = 0; x <= limit; x++) {
            output[x] = true;
        }
        output[0] = false;
        output[1] = false;
        for (int i = 2; i <= limit; i++) {
            if (output[i] == true) {
                for (int j = i * 2; j <= limit; j = j + i) {
                    output[j] = false;
                }
            }
        }

        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < output.length; i++) {
            if (output[i] == true) {
                result.add(i);
            }
        }
        System.out.println("Prime numbers up to " + limit + ": " + Arrays.toString(result.toArray()));
    }

    void sieveOfEratosthenesOptimized(int limit) {
        boolean[] output = new boolean[limit + 1];
        for (int x = 0; x <= limit; x++) {
            output[x] = true;
        }
        output[0] = false;
        output[1] = false;

        for (int i = 2; i <= Math.pow(limit, 0.5); i++) {
            // Since we just check for multiples bigger than i^2, we can just check until
            // sqr(limit)'s multiples
            if (output[i] == true) {
                for (int j = (int) Math.pow(i, 2); j <= limit; j = j + i) {
                    // No need to check multiples below i^2, since they have already been checked
                    output[j] = false;
                }
            }
        }

        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < output.length; i++) {
            if (output[i] == true) {
                result.add(i);
            }
        }
        System.out.println("Prime numbers up to " + limit + ": " + Arrays.toString(result.toArray()));
    }

    public static void main(String[] args) {
        int n = 7;
        SieveOfEratosthenes g = new SieveOfEratosthenes();
        long startTime = System.nanoTime();
        g.sieveOfEratosthenes(n);
        long endTime = System.nanoTime();
        System.out.println(endTime - startTime + " ns needed to calculate prime numbers" +
                " with basic implementation.");

        startTime = System.nanoTime();
        g.sieveOfEratosthenesOptimized(n);
        endTime = System.nanoTime();
        System.out.println(endTime - startTime + " ns needed to calculate prime numbers" +
                " with optimized implementation.");
    }
}
