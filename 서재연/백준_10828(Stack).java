import java.util.Scanner;

public class AlgorithmTest3 {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int index=scan.nextInt();
		scan.nextLine();
		Stack stack= new Stack();
		for(int i=0; i<index; i++) {
			String command=scan.nextLine();
			if(command.contains(" ")) {
				int num=Integer.parseInt(command.split(" ")[1]);
				stack.push(num);	
			}
			if(command.equals("pop"))
				System.out.println(stack.pop());
			if(command.equals("size"))
				System.out.println(stack.size());
			if(command.equals("empty")) {
				System.out.println(stack.empty());
			}
			if(command.equals("top"))
				System.out.println(stack.top());
		}
	}
}
class Stack{
	int[] array=new int[10000];
	int Top=0;
	
	int pop() {
		if(Top==0) return -1;
		return array[--Top];
	}
	void push(int n) {
		array[Top++]=n; 
	}
	int size() {
		return Top;
	}
	int empty() {
		if(Top==0) return 1;
		return 0;
	}
	int top() {
		if(Top==0) return -1;
		return array[Top-1];
	}
	
}

