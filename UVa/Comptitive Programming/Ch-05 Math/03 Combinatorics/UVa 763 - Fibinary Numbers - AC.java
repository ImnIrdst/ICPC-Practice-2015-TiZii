
import java.util.Scanner;
import java.math.BigInteger;


class Main{//Main
	
	private static BigInteger[] fib;
	private static int MAX = 100+10;
	
	public static void init(){
		fib = new BigInteger[MAX];
		fib[0] = BigInteger.ONE;
		fib[1] = fib[0].add(BigInteger.ONE);
		for(int i=2 ; i<MAX ; i++){
			fib[i]=fib[i-1].add(fib[i-2]);
		}
	}
	
	public static BigInteger toint(String num){
		BigInteger val = BigInteger.ZERO;
		for(int i=num.length()-1, j=0 ; i>=0 ; i--,j++){
			if(num.charAt(i)=='1') val=val.add(fib[j]);
		}
		return val;
	}
	
	public static String tofib(BigInteger num){
		String val = ""; int first=1; 
		for(int i=MAX-1 ; i>=0 ; i--){
			if(fib[i].compareTo(num)==-1 
					|| fib[i].compareTo(num)==0){
				val=val.concat("1"); first=0;
				num = num.subtract(fib[i]);
				//System.out.println(fib[i]);
			}
			else if(first==0) val=val.concat("0");
		}
		return val;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		init(); int first=1;
		while(sc.hasNext()){
			String Num1=sc.next(),Num2=sc.next();
			BigInteger val = toint(Num1).add(toint(Num2));
			if(first==0) System.out.println(); first=0;
			if(val.equals(BigInteger.ZERO)) System.out.println(0);
			else System.out.println(tofib(val).toString());
		}
		sc.close();
	}
	
}



