import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
//import java.util.

public class Main {
    public static String S2I(String str){
        BigInteger num = BigInteger.ZERO;

        for(int i=0 ; i<str.length() ; i++) {
            num = num.multiply(BigInteger.valueOf(26));
            num = num.add(BigInteger.valueOf(str.charAt(i) - 'a' + 1));
        }
        //num = num.add(BigInteger.ONE);
        return num.toString();
    }
    public static String I2S(BigInteger num) {

        ArrayList<Integer> rems = new ArrayList<>();
        if(num.equals(BigInteger.ZERO)) rems.add(0);
        while (!num.equals(BigInteger.ZERO)) {
            num = num.subtract(BigInteger.ONE);
            rems.add(num.mod(BigInteger.valueOf(26)).intValue());
            num = num.divide(BigInteger.valueOf(26));
        }
        StringBuilder str = new StringBuilder();
        for(int i = rems.size() - 1; i>=0 ; i--) {
            str.append((char)(rems.get(i)+'a'));
        }

        //BigInteger sb = S2I(str.toString());
        return str.toString();
    }
    public static String len22(String str) {
        StringBuilder sb = new StringBuilder(str);
        while (sb.length()!=22) {
            sb.append(' ');
        }
        return sb.toString();
    }

    public static String addCommas(String num) {

        StringBuilder sb = new StringBuilder();
        for(int i=num.length()-1, j=0; i>=0; i--, j++) {
            if(j%3==0 && j!=0) sb.append(',');
            sb.append(num.charAt(i));
        }
        return reverse(sb.toString());
    }

    public static String reverse(String str) {
        StringBuilder sb = new StringBuilder();
        for(int i=str.length()-1; i>=0; i--) {
            //if(j%3==0 && j!=0) sb.append(',');
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()) {
            String inp = sc.next();
            if(inp.equals("*")) break;
            String num, str;
            if(inp.charAt(0) >= 'a') {
                str = inp; num = S2I(inp);
            }else {
                str = I2S(new BigInteger(inp)); num = inp;
            }
            System.out.println(len22(str)+addCommas(num));
        }
    }
}

