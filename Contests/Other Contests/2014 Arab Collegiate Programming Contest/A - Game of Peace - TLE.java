import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cs = 1;
        int tc = sc.nextInt();

        while (tc-->0) {
            BigInteger x1 = BigInteger.ZERO;
            BigInteger x2 = sc.nextBigInteger();


            int n  = sc.nextInt();
            BigInteger y = sc.nextBigInteger();
            int m  = sc.nextInt();

            for(int i=0 ; i<m ; i++) {
                if(i==n) {
                    if(x1.compareTo(x2) > 0) x1 = x1.add(y);
                    else                     x2 = x2.add(y);
                }
                if(x2.compareTo(x1) > 0) x1 = x1.add(x2);
                else                     x2 = x2.add(x1);
            }

            System.out.println("Case " + (cs++) + ": " + gcd(x1,x2));
        }
    }

    private static BigInteger gcd(BigInteger a, BigInteger b) {
        if(b.equals(BigInteger.ZERO)) return a;
        return gcd(b, a.modPow(BigInteger.ONE,b));
    }
}