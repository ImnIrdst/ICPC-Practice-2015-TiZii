import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] Args) {
        Scanner sc     = new Scanner(System.in);
        BigInteger mod = BigInteger.valueOf((long)1e16+7);
        int tc = sc.nextInt();
        while(tc-- > 0) {
            Long R   = sc.nextLong();
            Long C   = sc.nextLong();

            BigInteger m   = BigInteger.valueOf((R * C) / 2);
            BigInteger n   = BigInteger.valueOf((R * C) - (R * C) / 2);

            BigInteger ans = BigInteger.valueOf(1);
            ans = ans.multiply(m.modPow(n.subtract(BigInteger.ONE), mod));
            ans = ans.multiply(n.modPow(m.subtract(BigInteger.ONE), mod));
            System.out.println(ans.mod(mod));
        }
    }
}