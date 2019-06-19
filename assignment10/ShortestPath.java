/**Samundra karki */
/**path with maximum sum */
import java.util.*;
import java.lang.Exception;

public class ShortestPath{
    private static Scanner scanner = new Scanner(System.in);
    
    private static int Path(int[][] A, int[][] B, int row){
        int sum = sumOfPath(A, B, 0, 0, row);
        return sum;
    }

    private static int sumOfPath(int[][] A, int[][] B, int i, int j, int row){
        if(i == row){
            return 0;
        }else{    
            int r_child, l_child;            
            if(B[i][j] == Integer.MIN_VALUE){
                r_child = A[i][j] + sumOfPath(A, B, i+1, j, row);
                l_child = A[i][j] + sumOfPath(A, B, i+1, j+1, row);
            
               if(r_child > l_child){
                B[i][j] = r_child;
                }else{
                B[i][j] = l_child;
                }
            }
        }
        return B[i][j];
    }
    public static void main(String[] args){
        int row, column;        

        System.out.println("Please enter number of row and column respectively: ");        
        row = scanner.nextInt();
        column = scanner.nextInt();

        //thrwoing exception if the value for row doesnot fullfill given condiiton
        if( row < 1 &&  row > 100){
            try{
                throw new ArrayIndexOutOfBoundsException();
            }catch(ArrayIndexOutOfBoundsException e){
                System.out.println(e);
            }
            row = scanner.nextInt();
            column = scanner.nextInt();
            while (!(row < 2 &&  row > 100)){
                try{
                    throw new ArrayIndexOutOfBoundsException();
                }catch(ArrayIndexOutOfBoundsException e){
                    System.out.println(e);
                }
                row = scanner.nextInt();
                column = scanner.nextInt();
            }
        }

        //try catch is used to recognize the if the condition fullfill or not
        System.out.println("Now enter the elements in the rows and column respectively: ");
        int[][] array = new int [row][column];
        int[][] maxArray = new int [row][column];        
        for(int i = 0; i < row; i++){
            for(int j = 0; j <=i; j++){
                array[i][j] =  scanner.nextInt();
                while (array[i][j] > 10000 || array[i][j] < 0 || array[i][j] != (int)(array[i][j])){
                    try {
                        throw new Exception();    
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    array[i][j] =  scanner.nextInt();
            }
                maxArray[i][j] = Integer.MIN_VALUE;
            }
        }
        
        System.out.println("Sample input");
        for(int i = 0; i < row; i++){
            for(int j = 0; j <=i; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }

        int[] path = new int[row];
        int sum = Path(array, maxArray, row);

        //determining the path of the array 
        for(int i = 0; i < row; i++){
            int j = 0;
            if(maxArray[i][j] > maxArray[i][j+1]){
                path[i] = array[i][j];
            }else{
                path[i] = array[i][j+1];
            }
        
        }

        System.out.println("Sample output");
        System.out.println(sum);
        for(int i = 0; i < row; i++){
            System.out.print(path[i] + " "); 
        }
        System.out.println();
    }
}