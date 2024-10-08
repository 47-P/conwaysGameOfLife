#include <stdio.h>
#include <conio.h> // Including this libray to use _kbhit() function to listen to keys
#include <time.h> // Including this library to generate random numbers between 1 and 0
#include <stdlib.h>

int main(void)
{
    // Defining the variables
    int maxRow, maxColumn, alive = 0, dead = 0, row, column, randomNumber;
    char ch;
    int keyPressed = 0; // A flag to change when a key is pressed


    printf("-- Welcome to Conway's Game of Life --\n\n");
    printf("First, let's admire how beautiful yet simple this game is\n");
    printf("Let's define the grid's rows and columns: \n");
    printf("Enter the number of rows: ");
    scanf("%d", &maxRow);
    printf("Enter the number of columns: ");
    scanf("%d", &maxColumn);

    // Defining the grid
    int grid1[maxRow][maxColumn], grid2[maxRow][maxColumn];

    // populating the grid
    for (row = 0; row < maxRow; row++)
    {
        for (column = 0; column < maxColumn; column++)
        {
            // following two lines of code is to generate a random number between 1 and 0 for populating the grid 
            randomNumber = rand() % 2;

            if (column == 0 || column == maxColumn - 1 || row == 0 || row == maxRow - 1)
            {
                grid1[row][column] = 8;
                grid2[row][column] = 8;
            }

            else if (column % 2 == 0)
            {
                grid1[row][column] = randomNumber;
                grid2[row][column] = randomNumber;
            }

            else
            {
                grid1[row][column] = randomNumber;
                grid2[row][column] = randomNumber;
            }
        }
    }

    printf("\n\nHere is the first generation: \n\n");
    // Printing the grid

    for (row = 0; row < maxRow; row++)
    {
        for (int column = 0; column < maxColumn; column++)
        {
            printf("%d", grid1[row][column]);
        }

        printf("\n");
    }

    printf("\nPress any key to print the next generation: \n\n");

    // Applying game's logic

    while (1)
    {
        // Listening for keyboard to apply the game's logic and print the new grid
        if (_kbhit())
        {
            ch = _getch();
            if (!keyPressed)
            {
                {
                    for (row = 1; row < maxRow - 1; row++)
                    {
                        for (column = 1; column < maxColumn - 1; column++)
                        {
                            for (int r = row - 1; r < row + 2; r++)
                            {
                                for (int c = column - 1; c < column + 2; c++)
                                {
                                    if (r == row && c == column)
                                    {
                                        continue;
                                    }

                                    else if (grid1[r][c] == 1)
                                    {
                                        alive++;
                                    }
                                }
                            }

                            if (alive == 0)
                            {
                                grid2[row][column] = 0;
                            }

                            else if (alive == 1 || alive == 2)
                            {
                                grid2[row][column] == grid1[row][column];
                            }

                            else if (alive == 3)
                            {
                                grid2[row][column] = 1;
                            }

                            else
                            {
                                grid2[row][column] = 0;
                            }

                            alive = 0;
                        }
                    }

                    // Printing the grid

                    for (row = 0; row < maxRow; row++)
                    {
                        for (int column = 0; column < maxColumn; column++)
                        {
                            printf("%d", grid2[row][column]);
                        }

                        printf("\n");
                    }

                    // Creating a copy of grid 2 to apply the game's logic to it agian
                    for (row = 0; row < maxRow; row++)
                    {
                        for (column = 0; column < maxColumn; column++)
                        {
                            grid1[row][column] = grid2[row][column];
                        }
                    }
                }

                keyPressed = 1;
                printf("\nPress any key to print the next generation\n\n");
            }
        }

        else
        {
            keyPressed = 0;
        }

        
    }
}