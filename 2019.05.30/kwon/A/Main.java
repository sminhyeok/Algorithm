package boj;

import java.io.*;
import java.util.*;


/*
 * ���� A.
 * 
 * ��ȣȭ�� ���ڿ� ��ȣ�� �� ���ھ� �ٽ� ��ȣȭ�Ͽ� ��ȣ�Է�Ű�� ������ ��� ���� ���ڷ� �Ѿ.
 * 
 * �迭 en : ��ȣȭ Ű�� ������ ��� ��ȣŰ �ڸ��� +1 �� �����ش�.
 * ���� result : ��ȣȭŰ�� ��ȣȭ�Ͽ� ��ȣŰ �ڸ��� +1 ���ش�.
 * ���� x : �񱳸� ���� �ϳ��� ���ڸ� ����
 * 
 * ���������� �� ���� en�� result ���� ��ġ�� ��� 'y' ���// �ٸ� ��� 'n' ���
 */
public class Main {
	static int N;
	static int[] en = new int[53];
	static int[] result = new int[53];
	static String line;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		Arrays.fill(en, 0);
		for (int i = 0; i < N; i++)
			en[Integer.parseInt(st.nextToken())]++;

		line = br.readLine();
		
		for(int i=0;i<N;i++) {
			char x = line.charAt(i);
			if(x == ' ')
				result[0]++;
			else if(x >= 'A' && x <='Z')
				result[x-'A' +1]++;
			else
				result[x-'a' +27]++;
		}
		boolean flag = true;
		for(int i=0;i<53;i++) {
			if(en[i] != result[i]) {
				flag = false;
				break;
			}
		}
		if(flag) System.out.println("y");
		else System.out.println("n");
	}
}
