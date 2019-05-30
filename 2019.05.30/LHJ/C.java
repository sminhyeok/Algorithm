import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;
public class Main{
	public void sort(int[] data,int l,int r) {
		int left=l;
		int right=r;
		int pivot=data[(left+right)/2];
		
		do {
			while(data[left]<pivot) left++;
			while(data[right]>pivot) right--;
			if(left<=right) {
				int temp=data[left];
				data[left]=data[right];
				data[right]=temp;
				left++;
				right--;
			}
		}while(left<=right);
		
		if(l<right) sort(data,l,right);
		if(r>left) sort(data,left,r);
	}
	
	public static void main(String[] args) {
		Main c= new Main();
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		String text;
		HashMap<Integer,Integer> map=new HashMap<>();
		int[] result = new int[N*5];
		int[] act = new int[N*5];
		for(int i=0;i<N*5;i++) {
			text=sc.next();
			String[] temp = text.split("-");
			if(temp[1].length()==3) {
				text=(int)temp[0].charAt(0)+temp[1];
			} else if(temp[1].length()==2) {
				text=(int)temp[0].charAt(0)+"0"+temp[1];
			} else {
				text=(int)temp[0].charAt(0)+"00"+temp[1];
			}
			result[i]=Integer.parseInt(text);
			act[i]=result[i];
			map.put(result[i], i+1);
		}
		c.sort(result, 0, result.length-1);
		Stack<Integer> wait = new Stack<>();
		
		int count=1;
		boolean flag=true;
		boolean[] d = new boolean[N*5];
		for(int i=1;i<=N*5;i++) {
			int temp=map.get(result[i-1]);
			if((count-temp)<0) {
				for(int k=count;k<temp;k++) {
					if(!d[k-1]) {
						wait.push(act[k-1]);
						if(wait.size()>=2) {
							int a=wait.pop();
							if(a>wait.peek()) {
								flag=false;
								break;
							} else {
								wait.push(a);
							}
						}
					}
				}
			} else if((count-temp)>=1) {
				if(!wait.isEmpty()) {
					wait.pop();
				}
			}
			if(!flag) break;
			d[temp-1]=true;
			count=temp;
		}
		
		if(flag) System.out.println("GOOD");
		else System.out.println("BAD");
	}
}