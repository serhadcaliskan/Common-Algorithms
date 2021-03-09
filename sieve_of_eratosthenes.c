#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * The Program finds prime numbers equal or less then the given number and prints those.
 */



void print_primes(int* number_array,int size){

    //print primes with a space
    for(int i=0;i<=size;i++){

        if(number_array[i]==0){

            printf("%d ",i);

        }

    }
}

int main(void) {

    int size,*number_array;

    printf("enter a number\n");
    scanf("%d",&size);


    //creates an array index from 0 to given number
    number_array=(int*)calloc(size+1,sizeof(int));

    //according to axioms they are not prime
    number_array[0]=1;
    number_array[1]=1;


    //starts with first prime '2'
    for(int i=2;i<=sqrt(size);i++){

        //if the number is not prime, pass.
        if(number_array[i]==0){

            int counter=2;

            //searches for the numbers which are divided by 'i'
            while(counter*i<=size){

                //if a number is not prime, it makes number_array[number] value 1
                number_array[counter*i]=1;
                counter++;

            }

        }

    }

    //prime indexes of number_array have value 0, others have 1
    print_primes(number_array,size);
    free(number_array);
}