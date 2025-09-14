#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8

char world[SIZE][SIZE];
int world_temp[SIZE][SIZE];


void randomize_world()
{
    srand(time(NULL)); 
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            world[x][y] = (rand()%10 < 8) ?  '_' :'X';
            printf("%c ", world[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void transform_world()
{
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            world_temp[x][y] = (world[x][y] == 'X') ? 0 : 1;
            //printf("%i ", world_temp[x][y]);
        }
        //printf("\n");
    }
    //printf("\n\n");
}

void measure_squares()
{
    int largest = 0;
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if(world_temp[x][y]>0)
            {
                int w = (x > 0) ? world_temp[x-1][y] : 0;
                int nw = ((x > 0) && (y > 0)) ? world_temp[x-1][y-1] : 0;
                int n = (y > 0) ? world_temp[x][y-1] : 0;
                world_temp[x][y] += w<nw? (w<n?w:n) : (nw<n?nw:n);
                if (world_temp[x][y] > largest)
                {
                    largest = world_temp[x][y];
                }
            }
            printf("%i ", world_temp[x][y]);
        }
        printf("\n");
    }
    printf("\nThe largest square has a size of %i\n", largest);
}

int main()
{
    randomize_world();
    transform_world();
    measure_squares();
    return 0;
}