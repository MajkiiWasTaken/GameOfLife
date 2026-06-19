#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

int countAlive(int grid[ROWS][COLS])
{
    int alive = 0;

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            if (grid[y][x] == 1)
                alive++;
        }
    }

    return alive;
}

void printGrid(int grid[ROWS][COLS], int generation)
{
    system("cls");

    printf("Game of Life by MajkiiWasTaken\n\n");

    printf("+");
    for (int x = 0; x < COLS; x++)
        printf("-");
    printf("+\n");

    for (int y = 0; y < ROWS; y++)
    {
        printf("|");

        for (int x = 0; x < COLS; x++)
        {
            if (grid[y][x])
                printf("O");
            else
                printf(" ");
        }

        printf("|\n");
    }

    printf("+");
    for (int x = 0; x < COLS; x++)
        printf("-");
    printf("+\n");

    printf("Generations: %d\n", generation);
    printf("Alive cells: %d\n", countAlive(grid));
}

int countNeighbors(int grid[ROWS][COLS], int x, int y)
{
    int count = 0;

    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
                continue;

            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < COLS && newY >= 0 && newY < ROWS)
            {
                count += grid[newY][newX];
            }
        }
    }

    return count;
}

void nextGeneration(int grid[ROWS][COLS])
{
    int newGrid[ROWS][COLS] = {0};

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            int neighbors = countNeighbors(grid, x, y);

            if (grid[y][x] == 1)
            {
                if (neighbors == 2 || neighbors == 3)
                    newGrid[y][x] = 1;
                else
                    newGrid[y][x] = 0;
            }
            else
            {
                if (neighbors == 3)
                    newGrid[y][x] = 1;
                else
                    newGrid[y][x] = 0;
            }
        }
    }

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            grid[y][x] = newGrid[y][x];
        }
    }
}

void randomizeGrid(int grid[ROWS][COLS])
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            int chance = rand() % 100;

            if (chance < 30)
                grid[y][x] = 1;
            else
                grid[y][x] = 0;
        }
    }
}

int main()
{
    int grid[ROWS][COLS] = {0};
    srand((unsigned int)time(NULL));
    randomizeGrid(grid);
    int generation = 0;

    while (1)
    {
        printGrid(grid, generation);
        nextGeneration(grid);
        generation++;
        Sleep(200);
    }

    return 0;
}