import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        while(tc-- > 0) {
            BigInteger n   = sc.nextBigInteger();
            BigInteger ans = BigInteger.valueOf(1);
            BigInteger tmp = BigInteger.valueOf(1);
            for(int i=0 ; i<4 ; i++) {
                tmp  = tmp.multiply(n);
                n    = n.subtract(BigInteger.ONE);
                if(i == 1) {
                    ans = ans.add(tmp.divide(BigInteger.valueOf(2*1)));
                }
            }
            ans = ans.add(tmp.divide(BigInteger.valueOf(4*3*2*1)));
            System.out.println(ans);
        }
    }
}