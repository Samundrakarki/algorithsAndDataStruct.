
// If in case java.lang.OutOfMemoryError: java heap space occurs
// https://stackoverflow.com/questions/37335/how-to-deal-with-java-lang-outofmemoryerror-java-heap-space-error
// Here the solution of the error that this program might throw is given
// as java tend to provide less heap space in everyones computer so, I cannot solve this 
// error from my code as I dont know how much heap space is proided 
// in your computer.
// I would have benn glad to do this problem in C++ but I am running out of time.

import java.util.*;

class Cylinder{
    int oxygen, nitrogen, weight;
    public Cylinder(int oxygen, int nitrogen, int weight){
        this.oxygen = oxygen;
        this.nitrogen = nitrogen;
        this.weight = weight;
    }
}

public class ScubaDiver{
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String [] args){
        int testCase;
        int provided_oxygen, provided_nitrogen, numberOfCylinder;

        testCase = scanner.nextInt();
        while(testCase != 0){
            provided_oxygen = scanner.nextInt();
            provided_nitrogen = scanner.nextInt();
            numberOfCylinder = scanner.nextInt();

            //value initislization
            Cylinder[] cyc = new Cylinder[numberOfCylinder];
            for(int i = 0; i < numberOfCylinder; i++){
                int o, n, w;
                o = scanner.nextInt();
                n = scanner.nextInt();
                w = scanner.nextInt();
                cyc[i] = new Cylinder(o, n, w);
            }
            
            //definining 3D array for memoization that loops over the numberofCylinder and 
            // each number of cylinder it loops over the provided value of oxygen
            // and for each liter of oxygen it loops over the provided value of nitrogen nitrogen
            // it stores  0 when both oxygen and nitrogen's value is 0 other wise infinity or MAX_VALUE
            int[][][] tempArray = new int[numberOfCylinder][provided_oxygen+1][provided_nitrogen+1];
            for(int i = 0; i < numberOfCylinder; i++){
                for(int j = 0; j <= provided_oxygen; j++){
                    for(int k = 0; k <= provided_nitrogen; k++){
                        tempArray[i][j][k] = ((j==0 && k==0) ? 0 : Integer.MAX_VALUE);
                    }
                }
            }
            
            // assignes the value for the temp array when it fullfills the given condition
            for(int j = 0; j <= provided_oxygen; j++){
                for(int k = 0; k <= provided_nitrogen; k++){
                    if(j <= cyc[0].oxygen && k <= cyc[0].nitrogen &&( j > 0 || k > 0)){
                        tempArray[0][j][k] = cyc[0].weight;
                    }
                }
            }

            //main concept involved reagardin dynamic progamming
            for(int i = 1; i < numberOfCylinder; i++){
                for(int j = 0; j <= provided_oxygen; j++){
                    for(int k = 0; k <= provided_nitrogen; k++){
                        tempArray[i][j][k] = tempArray[i-1][j][k];
                        if(j <= cyc[i].oxygen && k <= cyc[i].nitrogen){
                            tempArray[i][j][k] = Math.min(tempArray[i][j][k], cyc[i].weight);
                        }else{
                            int newJ = Math.max(0, j-cyc[i].oxygen);
                            int newK = Math.max(0, k-cyc[i].nitrogen);
                            if(tempArray[i][j][k] > (cyc[i].weight + tempArray[i-1][newJ][newK])){
                                tempArray[i][j][k] = cyc[i].weight + tempArray[i-1][newJ][newK];
                            }
                        }
                    }
                }
            }

            int iterator = numberOfCylinder - 1;
            int currentOxy = provided_oxygen;
            int currentNitro = provided_nitrogen;

            Vector<Integer> vec = new Vector<Integer>();
            while(iterator >= 0 && (currentOxy > 0 || currentNitro > 0)){
                if(iterator == 0){
                    vec.addElement(iterator + 1);
                }else if(tempArray[iterator][currentOxy][currentNitro] != tempArray[iterator-1][currentOxy][currentNitro]){
                    currentOxy = currentOxy - cyc[iterator].oxygen;
                    currentNitro = currentNitro - cyc[iterator].nitrogen;

                    currentOxy = Math.max(currentOxy, 0);
                    currentNitro = Math.max(currentNitro, 0);
                    vec.addElement(iterator+1);
                    iterator --;
                }else{
                    iterator--;
                }
            }
            Object[] arr = vec.toArray();


            System.out.println(tempArray[numberOfCylinder-1][provided_oxygen][provided_nitrogen]);
            for(int i = arr.length -1; i>=0; i++){
                System.out.println(arr[i]);
            }
            testCase--;
        }
    }
}