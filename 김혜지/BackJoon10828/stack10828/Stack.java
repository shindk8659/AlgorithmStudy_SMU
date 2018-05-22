package stack1;

public class Stack {
	public Node top;
	int size=0;
	
	public Stack(){
		top=null;
	}
	//empty
	public void empty(){
		if(top==null){
			System.out.println(1);			
		}
		else{
			System.out.println(0);
		}	
	}
	
	//push
	public void push(int x){
		Node node=new Node(x);
		node.next=top;
		top=node;
		size++;
	}
	//pop
	public void pop(){
		if(top==null){
			System.out.println(-1);
		}
		else{
			System.out.println(top.data);
			top=top.next;
			size--;
		}
	}
	//size
	public void size(){
		System.out.println(size);
	}
	
	//top
	public void top(){
		if(top==null){
			System.out.println(-1);
		}
		else{
			System.out.println(top.data);
		}
	}

}
