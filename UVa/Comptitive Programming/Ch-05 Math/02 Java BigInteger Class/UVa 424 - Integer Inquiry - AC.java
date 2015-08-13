package main;

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger num, sum=BigInteger.ZERO;
        while(true){
            num = sc.nextBigInteger();
            if(num.toString().equals("0")) break;

            sum = sum.add(num);
        }
        System.out.println(sum);
    }
}
