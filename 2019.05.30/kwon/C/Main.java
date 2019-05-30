package boj;

/*
 * ���� C
 * 
 * ����  Compare : ������ �ۿ��� Ƽ���� ���� �����
 * ����  Problem : Ƽ���� ���ĺ�����, ���ڼ������ ���Ľ�Ŵ.
 * ����  wait	  : �����ο� �ִ� �����.
 * 
 * ���� wait�� ���߿� ���� ����� �켱������ �����Ƿ� stack �ڷᱸ�� ���.
 * 1. ���� Compare������ ù��° �ε����� Problem ù��° �ε����� �� -> ���� ������� wait ��⿭�� Compare ù��° �ε����� �־���.
 * 2. wait������ ���� �������� ���� �ε����� Problem ù��° �ε��� �� -> ���� ������� continue
 * 
 * ���� �ΰ��� ���� �񱳽� ���� ��� ������ �ϴ°��̹Ƿ� �� �������� ���������ָ� ��.
 * 
 * ���ĵ� problem�� ��� ���� �Ǿ��� ��� GOOD, ������ ���� ��� BAD
 * 
 * 
 */
import java.util.*;
import java.io.*;

class pair {
	char x;
	int y;

	public pair(char x, int y) {
		this.x = x;
		this.y = y;
	}
}

class comp implements Comparator<pair> {
	@Override
	public int compare(pair p1, pair p2) {
		if (p1.x > p2.x)
			return 1;
		else if (p1.x < p2.x)
			return -1;
		else {
			if (p1.y > p2.y)
				return 1;
			else if (p1.y < p2.y)
				return -1;
			else
				return 0;
		}
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		String line = "";
		List<pair> problem = new ArrayList<pair>();
		List<pair> compare = new ArrayList<pair>();

		
		char al;
		int x;
		for (int j = 0; j < N; j++) {
			line = br.readLine();
			for (int i = 0; i < 5; i++) {
				String[] tok = line.split(" ");
				al = tok[i].charAt(0);
				x = Integer.parseInt(tok[i].substring(2, tok[i].length()));
				problem.add(new pair(al, x));
				compare.add(new pair(al, x));
			}
		}
		comp com = new comp();
		Collections.sort(problem, com);
		List<pair> wait = new ArrayList<pair>();
		
		for(int i=0;i<compare.size();i++) {
			if(compare.get(i).x == problem.get(i).x && compare.get(i).y == problem.get(i).y){
				problem.remove(0);
				compare.remove(0);
				i--;
			}
			else if( compare.get(i).y != problem.get(i).y || compare.get(i).x != problem.get(i).x) {
				int num = wait.size();
				if( num != 0) {
					if(wait.get(num-1).x == problem.get(i).x && wait.get(num-1).y == problem.get(i).y){
						wait.remove(num-1);
						problem.remove(0);
						i--;
						continue;
					}
				}
				wait.add(compare.get(i));
				compare.remove(0);
				i--;
			}
		}
		int idx = 0;
		while(!wait.isEmpty()) {
			int num = wait.size();
			if(wait.get(num-1).x == problem.get(idx).x && wait.get(num-1).y == problem.get(idx).y) {
				wait.remove(num-1); idx++;
			}else
				break;
		}
		if(wait.size() == 0) System.out.print("GOOD");
		else System.out.print("BAD");
	}
}
