import math

def insertion_sort(a_list):
    for index in range(1,len(a_list)):

        current = a_list[index]
        position = index

        while (position>0 and a_list[position-1]>current):
            a_list[position]=a_list[position-1]
            position = position-1

        a_list[position]=current

    return a_list

def merge_sort(arr, K):
    if len(arr) > K: 
        q = math.floor(len(arr)/2) 
        mat1 = arr[:q]
        mat2 = arr[q:] 
  
        merge_sort(mat1, K)  
        merge_sort(mat2, K) 
  
        L = insertion_sort(mat1)
        R = insertion_sort(mat2)
    
        i = 0; j = 0; k = 0
        
        while i < len(mat1) and j < len(mat2): 
            if mat1[i] < mat2[j]: 
                arr[k] = L[i] 
                i+=1
            else: 
                arr[k] = R[j] 
                j+=1
            k+=1
          
        while i < len(mat1): 
            arr[k] = mat1[i] 
            i+=1
            k+=1
          
        while j < len(mat2): 
            arr[k] = mat2[j] 
            j+=1
            k+=1
 
  
