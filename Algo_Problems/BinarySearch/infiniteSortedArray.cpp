/*
-> Given an infinite sorted array
-> We have to find an element in that infinite array

-> Solution
: start = 0, end = 1
: while(arr[end]<key){
    start = end;
    end*=2;
}
: After this process a finite array will be created
: In this, key will be between start and end indices
: Apply binary search to find the element
*/