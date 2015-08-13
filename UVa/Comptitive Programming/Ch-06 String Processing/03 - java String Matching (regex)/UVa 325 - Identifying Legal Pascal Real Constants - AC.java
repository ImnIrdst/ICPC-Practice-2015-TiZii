import java.util.Scanner;
import java.util.regex.*;

public class Main {
    final static int Max = 200 + 10;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Pattern p = Pattern.compile("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)");
        String str;
        while( true) {
            str = sc.next();
            if(str.equals("*")) break;

            System.out.print(str+" ");
            if(p.matcher(str).matches())
                System.out.println("is legal.");
            else System.out.println("is illegal.");
        }
    }
}