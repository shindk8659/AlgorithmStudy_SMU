import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	static int row;
	static int column;
	static int d[][]={{0,-1},{0,1},{1,0},{-1,0}};
	static boolean check[][];
	static int count[][];
	static int maze[][];
	
	static void bfs(int a,int b){
		Queue<Location> q=new LinkedList<Location>();
		if(a==row-1&&b==column-1){
			return;
		}
		
		q.add(new Location(a,b));
		
		while(true){
			if(q.isEmpty()){
				break;
			}
			
			Location l=q.poll();
						
			for(int i=0;i<4;i++){
				a=l.x+d[i][0];
				b=l.y+d[i][1];
				Location x=new Location(a,b);
				
				if(a<0||a>=row||b<0||b>=column){
					continue;
				}
				
				if(check[a][b]==true||maze[a][b]==0){
					continue;
				}
							
				q.add(x);
				check[a][b]=true;
				count[a][b]=count[l.x][l.y]+1;
			}
			
		}
	}
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		row=scanner.nextInt();
		column=scanner.nextInt();
		maze=new int[row][column];
		check=new boolean[row][column];
		count=new int[row][column];
		
		for(int r=0;r<row;r++){
			String line=scanner.next();
			for(int c=0;c<column;c++){
				maze[r][c]=(int)line.charAt(c)-48;
				check[r][c]=false;
				count[r][c]=1;
			}
		}
		check[0][0]=true;
		bfs(0,0);
		System.out.println(count[row-1][column-1]);
		
	}

}

class Location{
	int x;
	int y;
	public Location(int x, int y){
		this.x=x;
		this.y=y;
	}
}

