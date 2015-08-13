import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a, b; String op;
        int tc = sc.nextInt();
        while(tc-- > 0){
            a = sc.nextBigInteger(16); op = sc.next();
            b = sc.nextBigInteger(16);
            String sa = a.toString(2), sb = b.toString(2);
            while(sa.length()!=13) sa = "0".concat(sa);
            while(sb.length()!=13) sb = "0".concat(sb);
            if(op.equals("+")) System.out.println(sa + " + " + sb + " = " + a.add(b).toString());
            if(op.equals("-")) System.out.println(sa + " - " + sb + " = " + a.subtract(b).toString());
        }
    }
}

