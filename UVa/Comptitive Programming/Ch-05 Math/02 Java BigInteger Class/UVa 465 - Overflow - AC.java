import java.math.BigInteger;
import java.util.Scanner;
import java.util.regex.Matcher;
//import java.util.

public class Main {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);

        BigInteger a, b; String op;
        while(sc.hasNextLine()) {
            String line = sc.nextLine();
            System.out.println(line);

            String[] tokens = line.split("\\s+");
            a  = new BigInteger(tokens[0]);
            op = new String(tokens[1]);
            b  = new BigInteger(tokens[2]);

            if(a.compareTo(BigInteger.valueOf(1l<<31))>=0) {
                System.out.println("first number too big");
            }
            if(b.compareTo(BigInteger.valueOf(1l<<31))>=0) {
                System.out.println("second number too big");
            }
            if(op.equals("+") && a.add(b).compareTo(BigInteger.valueOf(1l<<31))>=0) {
                System.out.println("result too big");
            }
            if(op.equals("*") && a.multiply(b).compareTo(BigInteger.valueOf(1l<<31))>=0) {
                System.out.println("result too big");
            }
        }
    }
}