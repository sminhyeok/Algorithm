import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N= sc.nextInt();
		int[] number=new int[53];
		for(int i=0;i<N;i++) number[sc.nextInt()]++;
		String trash = sc.nextLine();
		String secret = sc.nextLine();
		int[] result=new int[1000];
		
		for(int i=0;i<N;i++) {
			if(secret.charAt(i)==' ') {result[0]++;}
			else if(secret.charAt(i)>='A' && secret.charAt(i)<='Z') {result[secret.charAt(i)-'A'+1]++;}
			else {result[(int)(secret.charAt(i)-'a'+27)]++;}
		}
		boolean flag =true;
		for(int i=0;i<53;i++) {
			if(number[i]!=result[i]) {
				flag=false;
				break;
			}
		}
		if(flag) System.out.println("y");
		else System.out.println("n");
	}
}