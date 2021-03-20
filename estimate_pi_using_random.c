#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//bigger "size" means better estimation
float estimate_pi(int size){

    srand(time(NULL));
    int inside_quarter_circle=0;


    for(int i=0;i<size;i++){
        //generates random float between 0 and 1
        float x= (float)rand()/(float)(RAND_MAX/1);
        float y= (float)rand()/(float)(RAND_MAX/1);

        //If distance of dot to the center is less than or equal 1, this dot is in quarter circle
        if (sqrt(x*x+y*y)<=1){

            inside_quarter_circle++;

        }

    }

    //area of circle is r^2 * pi
    //area of quarter circle is (r^2 * pi)/4
    //total area of square is r^2
    //if we divide the number of dots in circle by total number of dots and multiply by 4, the result will be approximate calculation of pi
    return ((float)inside_quarter_circle/(float)size)*4;


}


int main() {

    printf("%f",estimate_pi(10000000000));
}