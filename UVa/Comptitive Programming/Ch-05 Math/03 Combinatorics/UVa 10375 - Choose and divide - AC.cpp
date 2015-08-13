import java.math.BigDecimal;
import java.util.Scanner;
import java.math.BigInteger;
import java.math.MathContext;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger[] fact = new BigInteger[10000+10];
        
        fact[0]=BigInteger.ONE;
        for(int i=1 ; i<10000+10 ; i++){
            fact[i]=fact[i-1].multiply(BigInteger.valueOf(i));
        }

        int p, q, s, r;
        while(sc.hasNextInt()){
            p = sc.nextInt(); q = sc.nextInt();
            s = sc.nextInt(); r = sc.nextInt();
            BigDecimal num = new BigDecimal(fact[p].divide(fact[q].multiply(fact[p-q])));
            BigDecimal den = new BigDecimal(fact[s].divide(fact[r].multiply(fact[s-r])));
            BigDecimal ans = num.divide(den,new MathContext(30));
            //System.out.println(ans);
            System.out.printf("%.5f\n" ,ans.doubleValue());//

        }
    }
}
