from re import I
import tempfile
import time
def selection(arr):
    
    for i in range(len(arr)):
        min_idx=i
        for j in range(i+1,len(arr)):
            if(arr[j]<arr[min_idx]):
                min_idx=j
        arr[i],arr[min_idx]=arr[min_idx],arr[i]

    print(arr)

selection([10,7,5,100,2,4,6])

