import java.util.Scanner;

public class Cup {
	public static void main(String[] args) {
		int tmp;

		Scanner kb = new Scanner(System.in);
		int N=kb.nextInt(); // N번 

		int []x = new int[4];  // 0제외 1~3까지
		x[1]=1;

		for(int i=0;i<N;i++) {  // 총 n번
			int a = kb.nextInt();
			int b = kb.nextInt();
			tmp = x[a];
			x[a]=x[b];
			x[b]=tmp;
		}
		kb.close();
		for(int j=1;j<4;j++) {
			if(x[j]==1) {
				System.out.println(j);
				break;
			}
		}
	}
} 