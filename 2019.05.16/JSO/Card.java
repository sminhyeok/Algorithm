import java.util.Scanner;

public class Card {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		int N = kb.nextInt();
		int []arr = new int[100];
		int []t = new int[100];
		int i, j = 0, k =0;

		kb.close();
		
		for(i=0;i<N;i++) {
			arr[i]=i+1;
		}
		while(N>2) {
			t[j++]=arr[k++];
			arr[i++]=arr[k++];
			N--;	
		}
		t[j++]=arr[k++];
		for(int a=0;a<j;a++)
			System.out.print(t[a]+" ");
		System.out.println(arr[k]);
	}
}
