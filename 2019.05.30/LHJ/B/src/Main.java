import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		
		if(a>c && a>b) {
			double d;
			int answer;
			d=(((Math.sqrt(a*a-b*b)*Math.sqrt(a*a-c*c)-b*c)/a)+0.000000000001);
			if(a>d && d>0) {
				if((d-(int)d)>0.9999999 || (d-(int)d)<0.00000001) {
					answer=(int)d;
					System.out.println(answer);
				}
			} else System.out.println("-1");
		} else System.out.println("-1");
	}
}
