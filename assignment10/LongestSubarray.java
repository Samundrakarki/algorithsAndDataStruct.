
import java.util.*;

public class LongestSubarray{
    private static Scanner scanner = new Scanner(System.in);
    private static void longSubarray(int[] arr, int size){
        int[] subArray;
        int[] outputSubArray = new int[size];
        int[] highestSubArray = new int[size];
        for(int i = 0; i < size; i++){
            highestSubArray[i] = 1;
            outputSubArray[i] = i;
        }

        //highest sub array stores the highest number of subarray in each position
        //output sub array stores the index of the element next smaller than present
        for(int i = 1; i < size; i++){
            for(int j = 0; j < i; j++){
                if((arr[i] > arr[j]) && (highestSubArray[i] < (highestSubArray[j] + 1))){
                    highestSubArray[i] = highestSubArray[j] + 1;
                    outputSubArray[i] = j;
                }
            }
        }

        int longSeq = Arrays.stream(highestSubArray).max().getAsInt();
        int longIndex = 0;
        for(int i = 0; i < size; i++){
            if(longSeq == highestSubArray[i]){
                longIndex = i;
            }
        }
        //size of our subArray will be the max value of the highestSubArray
        subArray = new int[longSeq];
        
        //here outputsubArray is used to store the index of the 
        // next smaller than the present element of the array
        for(int i = 0 ; i < longSeq; i++){
            subArray[i] = arr[longIndex];
            longIndex = outputSubArray[longIndex];
        } 
        
        for(int i = longSeq- 1; i >=0; i--){
            System.out.print(subArray[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        int size;

        System.out.println("Enter the size of the array: ");
        size = scanner.nextInt();
        int[] arr = new int[size];

        System.out.println("Enter the array whose longest subarray you wanna know: ");
        for(int i = 0; i < size; i++){
            arr[i] = scanner.nextInt();
        } 

        longSubarray(arr, size);
    }
}