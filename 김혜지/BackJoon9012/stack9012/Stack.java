package stack2;

public class Stack {
	public Node top;
	int size=0;
	
	class Node{
		char data;
		Node next;
		
		public Node(char data){
			this.data=data;
			this.next=null;
		}
	}
	
	public Stack(){
		top=null;
	}
	
	public boolean empty(){
		if(top==null)
			return true;
		else
			return false;
	}
	
	public void push(char x){
		Node node=new Node(x);
		node.next=top;
		top=node;
		size++;
	}
	
	public char pop(){
		char d;
		if(top==null){
			System.exit(1);
		}
		d=top.data;
		top=top.next;
		size--;
		return d;
	}
	
	public int size(){
		return size;
	}
}
