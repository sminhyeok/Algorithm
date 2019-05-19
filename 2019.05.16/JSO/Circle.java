import java.util.Scanner;

public class Circle {

	public static void main(String[] args) {

		Scanner kb = new Scanner(System.in);

		int N = kb.nextInt();
		int M = kb.nextInt();
		int L = kb.nextInt();
		int a =1;
		int []count= new int[N+1];
		int realcount =0;
		count[a] = 1;
		
		kb.close();
		
		while(count[a]!=M) {
			if(count[a]%2==0) { // 짝수이면 반시계방향으로 L 번째
				a=a+N-L;
				if(a>N) {
					a=a-N;	
				}
				count[a]++;
				realcount++;
			}
			else if(count[a]%2==1) { // 홀수이면 시계방향으로 L번째
				a=a+L;
				if(a>N) {
					a=a-N;	
				}
				count[a]++;
				realcount++;
			}
		}
		System.out.println(realcount);
	}
}
