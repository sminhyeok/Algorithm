package boj;

import java.io.*;
import java.util.*;


/*
 * 문제 A.
 * 
 * 복호화된 문자열 암호를 한 글자씩 다시 암호화하여 암호입력키에 존재할 경우 다음 문자로 넘어감.
 * 
 * 배열 en : 암호화 키가 존재할 경우 암호키 자리에 +1 씩 더해준다.
 * 변수 result : 복호화키를 암호화하여 암호키 자리에 +1 해준다.
 * 변수 x : 비교를 위해 하나의 글자를 저장
 * 
 * 마지막으로 두 변수 en과 result 값이 일치할 경우 'y' 출력// 다를 경우 'n' 출력
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
