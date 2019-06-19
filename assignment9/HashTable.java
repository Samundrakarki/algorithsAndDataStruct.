import java.util.Random;

class Node{
    int key;
    int value;
    Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

public class HashTable{
    Node arr[] = new Node[200];//declaring a array of node type
    int maxSize;
    int currentSize;
    
    //initializing all the fields of the class
    HashTable(){
        maxSize = 67;
        currentSize = 0;
        Node temp = new Node(0, 0);
        for(int i = 0; i < maxSize; i++){
            arr[i] = temp;
        }
    }
    int hashCode(int key){
        int index = (key % maxSize);
        return index;
    }
    void insertNode(int key, int value){
        int idx = hashCode(key);
        boolean status = isEmpty(idx);
        while(status != true){
            idx += 1;
            status = isEmpty(idx);  
        }
        Node newElem = new Node(key, value);
        arr[idx] = newElem;

    }

    int get(int key){
        int idx = hashCode(key);
        if(arr[idx].key == key){
            return idx;
        }else{
            while(arr[idx].key != key){
                idx += 1;
            }
            return idx;
        }
    }
    boolean isEmpty(int idx){
        if((arr[idx]).key == 0){
            return true;
        }else{
            return false;
        }
    }

    public static void main(String args[]){
        HashTable h = new HashTable();
        int i = 48; 
        //just to see if the function is working
        h.insertNode(i, i+100);
        System.out.println("Value at index " + i + " with key " + h.arr[i].key + " is " +h.arr[i].value);

        h.insertNode(i, i+200);
        System.out.println("Value at index " + (i+1) + " with key " + h.arr[i+1].key + " is " +h.arr[i+1].value);
        
        //testing the getting funtion
        int x = h.get(i);
        System.out.println("Getting the value with index i : " + x);

    }
}


/* 
 *Java files are not compatible with makefiles 
 * we dont know what are the class going to be generated form 
 * makefile logic is implement in smart javac wrapper (sjavac) written in JAVA
*/