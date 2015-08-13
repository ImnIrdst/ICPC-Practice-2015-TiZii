import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		BigInteger a,b,c; int tc = sc.nextInt(); String str;
		while((tc--)!=0){
			a = sc.nextBigInteger();
			str = sc.next();
			//System.out.println(
			b = sc.nextBigInteger(); 
			c = a.gcd(b);
			System.out.println(a.divide(c)+" / "+b.divide(c));
		}
		sc.close();
	}
}
