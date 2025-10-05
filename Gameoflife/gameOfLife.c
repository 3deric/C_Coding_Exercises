#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
    int size = 50;
    int data[size][size];
    int temp[size][size];
    
    srand(time(NULL));
    //initialize data array
    for (int i = 0; i < size; i++)
    {
        for (int j =0; j < size; j++)
        {
            // data[i][j] = 0;
            data[i][j] = rand() % 2;
        }
    }

    data[2][2]=1;
    data[3][3]=1;
    data[4][1]=1;
    data[4][2]=1;
    data[4][3]=1;

    for(;;){ 
        //clear the previous rendering
        system("cls"); 

        //draw the data array
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (data[i][j] == 1){
                    printf(" # ");
                }
                else{
                    printf("   ");
                }
            }
            printf("\n");
        }

        //fill the temp array based on rules clockwise
        for (int i = 0; i < size; i++)
        {
            for (int j =0; j < size; j++)
            {
                //initialize neighbour counter
                int neighbours = 0;
                //north
                neighbours+=data[(i-1+size)%size][j];
                //northeast
                neighbours+=data[(i-1+size)%size][(j+1+size)%size];
                //east
                neighbours+=data[i][(j+1+size)%size];
                //southeast
                neighbours+=data[(i+1+size)%size][(j+1+size)%size];
                //south
                neighbours+=data[(i+1+size)%size][j];
                //southwest
                neighbours+=data[(i+1+size)%size][(j-1+size)%size];
                //west
                neighbours+=data[i][(j-1+size)%size];
                //northwest
                neighbours+=data[(i-1+size)%size][(j-1+size)%size];

                if(data[i][j] == 1){
                    if (neighbours >= 2 && neighbours <= 3){
                        temp[i][j] = 1;
                    }
                    else{
                        temp[i][j] = 0;
                    }
                }    
                if(data[i][j] == 0){
                    if (neighbours == 3){
                        temp[i][j] = 1;
                    }
                    else{
                        temp[i][j] = 0;
                    }
                }
            }
        }
        //copy temp array to data array
        for (int i = 0; i < size; i++){
            for (int j =0; j < size; j++){
                data[i][j] = temp[i][j];
            }
        }
        sleep(1);
    }
    return 0;
}


