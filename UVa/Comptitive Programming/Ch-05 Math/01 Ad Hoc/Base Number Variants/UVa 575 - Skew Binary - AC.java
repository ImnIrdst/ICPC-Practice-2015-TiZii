import java.util.Scanner;

class Main{//Main
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(true){
			String str = sc.next(); if(str.equals("0")) break;
			int pow2=2 , ans=0, s;
			for(int i=str.length()-1 ; i>=0  ; i--){
				s = str.charAt(i)-'0';
				ans += s*(pow2-1); pow2*=2;
			}
			System.out.println(ans);
		}
	}
}

