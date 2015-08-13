import java.util.Scanner;
import java.math.*;

public class Main {
    final static int Max = 200 + 10;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger fib[] = new BigInteger[Max];
        fib[0] = BigInteger.ONE;
        for(int i=1 ; i<Max; i++) {
            fib[i] = fib[i-1].multiply(BigInteger.valueOf(i));
        }

        int tc = sc.nextInt();
        while( tc-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int blacks = 0;
            for(int i=0 ; i<k ; i++) {
                blacks += sc.nextInt();
            }

            int whites = n - blacks + 1;

            // C(Whites, k)
            if(whites < k) System.out.println(0);
            else           System.out.println(fib[whites].divide(fib[k].multiply(fib[whites-k])));
        }
    }
}