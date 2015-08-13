
import java.util.Scanner;
import java.math.BigInteger;


class Main{//Main
	
	private static BigInteger[] fib;
	private static int MAX = 1000+10;
	
	public static void init(){
		fib = new BigInteger[MAX];
		fib[0] = BigInteger.ONE;
		fib[1] = fib[0].add(BigInteger.ONE);
		for(int i=2 ; i<MAX ; i++){
			fib[i]=fib[i-1].add(fib[i-2]);
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		init(); int first=1;
		while(sc.hasNext()){
			int n = sc.nextInt();
			System.out.println(fib[n]);
		}
		sc.close();
	}
	
}



