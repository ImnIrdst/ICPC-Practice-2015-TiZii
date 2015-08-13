import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main (String [] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger[] fib = new BigInteger[2000*2+10];
        fib[1] = new BigInteger("1");
        fib[2] = new BigInteger("1");
        for (int i = 3; i < 2000*2+10; i++)
            fib[i] = fib[i - 1].add(fib[i - 2]);
        while (true) {
            int n = sc.nextInt(); if (n == 0) break;
            System.out.println(fib[2 * n]);
        }
        sc.close();
    }
}