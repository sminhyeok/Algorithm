package boj;

import java.io.*;
import java.util.*;

public class numberF {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N, M, L, count = 0;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		int[] p = new int[N];
		int now = 0, next;
		p[now]++;
		while (true) {
			if (p[now] == M)
				break;

			if (p[now] % 2 == 0) {
				next = (N+now-L) % N;
			} else {
				next = (now + L) % N;
			}
			now = next;
			count++;
			p[now]++;
		}
		System.out.println(count);
	}
}
