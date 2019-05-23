package boj;

import java.io.*;
import java.util.*;

public class numberE {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		int []card = new int[N+1];
		
		for(int i=0;i<=N;i++)
			card[i] = i;
		int[]result = new int[N+1];
		for(int j=1;j<N;j++) {
			result[j] = card[j];	//버린카드 result에 입력
			int tmp = card[j+1];	//버린 후 가장 첫번째 카드번호 임시저장
			for(int k=j+1;k<N;k++) {	//첫번째 카드를 가장 마지막으로 보냄
				card[k] = card[k+1];
			}
			card[N]=tmp;	//가장 마지막에 첫번째카드 넣음
		}
		result[N] = card[N];
		for(int i=1;i<=N;i++)
			System.out.print(result[i] + " ");
	}
}