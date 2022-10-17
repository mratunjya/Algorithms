import java.util.*;

public class Main{

    private static boolean inRange(int i,int j,int n,int m){
        if(0<=i && 0<=j && i<=n && j<=m){
            return true;
        }
        
        return false;
    }


    private static boolean inRange(int i,int j,int[][] maze){
        if(0<=i && 0<=j && i< maze.length && j< maze[0].length){
            return true;
        }
        
        return false;
    }
     
// ============================================Maze Path==================================================================
    private static int printMazePathJump(int sr,int sc,int dr,int dc ,int[][] dir, String[] dirN,String psf){
        
        if(sr == dr && sc == dc){
            System.out.println(psf);
            return 1;
        }
        int count = 0;
        
        for(int d=0;d<dir.length ; d++){
            for(int jump=1;jump<=Math.max(dr,dc);jump++){
                int nr = sr + dir[d][0] * jump;
                int nc = sc + dir[d][1] * jump;
                if(inRange(nr,nc,dr,dc)){
                    count += printMazePathJump(nr,nc, dr,dc,dir,dirN,psf+dirN[d]+jump);
                }
            }

        }
        return count;
    }

    private static void solveMazePathWithJump(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] dir = {{0,1},{1,1},{1,0}};
        String[] dirN = {"h","d","v"};
        

        int count = printMazePathJump(0,0,n-1,m-1,dir,dirN, "");
        
        System.out.println("Count: "+count);
    }

// ==============================================Flood Fill===============================================

    private static int printFloodFillPaths(int[][] maze,int sr,int sc, String psf,int[][] dir,String[] dirN){

        if(sr == maze.length -1 && sc == maze[0].length-1){
            System.out.println(psf);
            return 1;
        }

        int count =0;

        maze[sr][sc] = 1;
        for(int d = 0;d <dir.length;d++){
            int nr = sr + dir[d][0];
            int nc = sc + dir[d][1];

            if( inRange(nr,nc,maze) && maze[nr][nc] == 0){
                count +=printFloodFillPaths(maze,nr,nc,psf+dirN[d],dir,dirN);
            }
        }
        maze[sr][sc]=0;

        return count;
    }


    private static void floodFillSolver(){
        Scanner sc = new Scanner(System.in);
        int[][] dir = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        String[] dirN = {"A","B","C","D","E","F","G","H"};
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] maze = new int[n][m];

        int pathCount = printFloodFillPaths( maze,0,0,"",dir,dirN);
        System.out.println(pathCount);
    }

// ==================================================================HomeWork Shortest Path in Flood fill====================================================================

    private static String getShortestPath(int sr,int sc ,int dr,int dc, int[][] dir, String[] dirN,String psf){
        
        if(sr == dr && sc == dc){
            System.out.println(psf);
            return "";
        }



        String shortestPath = "";
        boolean gotFirst =false;
        for(int d=0; d<dir.length ; d++){
            int nr = sr + dir[d][0];
            int nc = sc + dir[d][1];

            if(inRange(nr,nc,dr,dc)){
                String path = getShortestPath(nr,nc,dr,dc,dir,dirN,psf + dirN[d]);
                path = dirN[d] + path;
                if(!gotFirst){
                    shortestPath = path;
                    gotFirst = true;
                }else if(shortestPath.length() > path.length()){
                    shortestPath = path;
                }
            }
        }
        return shortestPath;
    }


    private static void shortestFloodFillSolver(){
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();

        int[][] dir = {{0,1},{1,1},{1,0}};
        String[] dirN = {"h","d","v"};

        System.out.println("All Possible Paths:");
        String shortestPath = getShortestPath(0,0,m-1,n-1,dir,dirN,"");
        System.out.println("Shortest Path : "+shortestPath);
        System.out.println("Length of Shortest Path : "+ shortestPath.length());
    }


    public static void main(String args[]){
        shortestFloodFillSolver();
    }
}
