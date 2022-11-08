#include <stdlib.h>
#include <stdio.h>

using namespace std;

void insertSort( int a[], int min, int n){ //insertion sort of the file
    for( int i = min +1 ; i<n+1; i++){
        int val = a[i];
        int j = i;
        while(j > min && a[j- 1]> val){
            a[j] = a[j-1]; //swap values 
            j -= 1;
        };
        a[j] = val;
    };

}

int partion(int a[], int min, int max){
    int pivot = a[max]; //take the vale at the max as the pivot 
    int i, j;
    i = min;
    j = min;

    for( int i = min; i < max; i++){ 
        if(a[i] < pivot){
            int temp = a[i]; //swap values
            a[i] = a[j];
            a[j] = temp;
            j += 1;
        };
    };

    int temp = a[j];
    a[j] = a[max];
    a[max] = temp;

return j;
}//Partion

void quickSort( int a[], int min, int max){

    if(min < max){ //make min is not larger than max
        int pivot = partion( a, min, max); //partion 
        quickSort( a, min, pivot-1); //partion the left side 
        quickSort(a, pivot+1, max); //partion the right side 
    }
}//quickSort

void quickSort2( int a[], int min, int max){
    while(min < max){
    if(max-min+1 < 32){ //if the size of the array is less than 32 use insertion sort
        insertSort(a, min, max);
        break;
    }else{ //use quicksort if bigger than 32
        int pivot = partion(a, min, max); //partion
        if(pivot-min < max -pivot){
            quickSort2( a, min, pivot-1);
            min = pivot + 1;
        }else{ 
            quickSort2(a, pivot +1, max); //insert into quicksort 
            max = pivot - 1; 
            }
        }
    }
}


int main(){

    int p[100000];
    FILE *RANDOM = fopen( "RANDOM.TXT", "r" );
    FILE *OUTPUT = fopen( "LAB4_PART3.TXT", "W"); //create output file for sorted list 

for( int i = 0; i<100000; i++){ //scan val
    fscanf(RANDOM," %d", &p[i]);
    
}

    quickSort2(p, 0, 100000);//sort array 

    for( int i = 0; i<100000; i++){  //print output file 
        fprintf(OUTPUT, "%d\n", p[i]);
    }
}

