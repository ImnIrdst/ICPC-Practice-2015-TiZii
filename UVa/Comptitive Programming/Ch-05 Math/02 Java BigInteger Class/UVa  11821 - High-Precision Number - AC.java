import java.util.Scanner;
import java.math.BigDecimal;;

class Main{//Main
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); int tc = sc.nextInt();
		BigDecimal a,b;
		while(tc--!=0){
			
			b = BigDecimal.ZERO;
			while(true){
				a = sc.nextBigDecimal(); if(a.equals(BigDecimal.ZERO)) break;
				b = b.add(a);
			}
			if(b.compareTo(BigDecimal.ZERO)==0) System.out.println("0");
			else System.out.println(b.stripTrailingZeros().toPlainString());
		}
	}
}

