package boj;

import java.io.*;
import java.util.*;

public class boj13126461 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int M = Integer.parseInt(st.nextToken());
		int X,Y,tmp=0;
		int[] cup = new int[4];
		Arrays.fill(cup, 0); cup[1] = 1;
		for(int i=1;i<=M;i++) {
			st = new StringTokenizer(br.readLine());
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			tmp = cup[X];
			cup[X] = cup[Y];
			cup[Y] = tmp;
		}
		for(int i=1;i<cup.length;i++) {
			if(cup[i] ==1)
				System.out.println(i);
		}
	}
}