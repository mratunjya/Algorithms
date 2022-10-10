import java.util.*; 
; 

public class NQueens {
    public static boolean isSafe(char[][] board,int row,int col)
    {
        //in this function we'll check if the position is safe horizontally,verticaly,left down, left up, right down, right up
        
        
        //horizontal
        for(int i=0;i<board.length;i++)
        {
            if(board[row][i]=='Q')
            {
                return false;
            }
        }
        //vertical
        for(int j=0;j<board.length;j++)
        {
            if(board[j][col]=='Q')
            {
                return false;
            }
        }
        
        //upper left row-1,col-1
        int r = row;
        for(int c=col;c>=0&&r>=0;r--,c--)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
        }
        //lower right row+1,col+1
        r = row;
        for(int c=col;r<board.length&&c<board.length;r++,c++)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
        }
        //lower left row+1,col-1
        r=row;
        for(int c=col;r<board.length && c>=0;r++,c--)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
        }
        //upper right row-1,col+1
        r = row;
        for(int c=col;r>=0 && c<board.length; r--,c++)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
        }
        
        return true;
    }
    
    //saving ther char array in list
    public static void saveBoard(char[][] board,List<List<String>> allBoards)
    {
        String row = "";
        List<String> newBoard = new ArrayList<>();
        for(int i=0; i<board.length;i++)
        {
            row="";
            for(int j=0;j<board[0].length;j++)
            {
                if(board[i][j]=='Q')
                {
                    row+='Q';
                }
                else{
                    row+='.';
                }
            }
            newBoard.add(row);
        }
        allBoards.add(newBoard);
    }
    public static void helper(char[][] board,List<List<String>> allBoards,int col){
        //base condition if column is at his last position which is length of the board
        if(col==board.length)
        {
            saveBoard(board,allBoards);
            return;
        }
        
        for (int row=0;row<board.length;row++)
        {
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                helper(board,allBoards,col+1);
                board[row][col] = '.';
            }
        }
    }
    public static  List<List<String>> solveQueens(int n){
        List<List<String>> allBoards = new ArrayList<>();
        char[][] board = new char[n][n];
        //recursive function
        helper(board,allBoards,0);
        return allBoards;
    }
    public static void main(String[] args) {
        List<List<String>> getBoards = solveQueens(4);
        System.out.println(getBoards);
        System.out.println("\n Length of the board = "+ getBoards.size());
    }
}