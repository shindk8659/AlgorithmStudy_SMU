import java.util.Scanner;


public class Main {

	
	public static void main(String[] args) {
		
		stack s1 = new stack();
		
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		
		if(num>=1 && num<=10000) {
			
			for(int i=0;i<num;i++) {
				
				String a = scanner.next();
				
				if(a.equals("push")) {
						int x = scanner.nextInt();
						s1.push(x);
				}
				else if(a.equals("pop")) {
					s1.pop();
				}
				
				else if(a.equals("size"))
					s1.size();
				else if(a.equals("empty"))
					s1.empty();
				else if(a.equals("top"))
					s1.top();
			}		
		
			scanner.close();
		}
	}
	
}


class stack{
	
	
	int arr[];
	static int top = 0;
	
	
	public stack() {
		this.arr= new int[10000];
	}
	
	
	void push(int a) {
		
			arr[top]=a;
			top++;
			
	}
	
	void pop() {
		if(top ==0) 
			System.out.println("-1");
		else
		{
			top= top-1;
			System.out.println(arr[top]);
		}
	}
	
	
	void size() {
		int num=0;
		
		for(int i=0;i<top;i++) {
			num++;
		}
		
		System.out.println(num);
	}
	
	
	void empty() {
		
		if(top==0)
			System.out.println("1");
		else
			System.out.println("0");
		
	}
	
	void top() {
		if(top>0)
			System.out.println(arr[top-1]);
		else
			System.out.println("-1");
	}
}
