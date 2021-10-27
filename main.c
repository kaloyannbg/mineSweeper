#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void putMines(int array[][COLS], int rows);
void printMines(int array[][COLS], int rows);
void checkWin(int array[][COLS], int rows, char rowChoice, char colChoice);

static int foundMines = 0;

int main()
{

    srand(time(0));

    int minesArray[ROWS][COLS] = {0};

    char rowChoice = 0;

    char colChoice = 0;

    putMines(minesArray, ROWS);

    system("color 1F");

    do
    {
        system("cls");

        printf("\n\n -- Kaloyan Angelov -- MineSweeper -- \n");

        printf("\n -- MINES IS EQUAL TO ROWS, IN THIS CASE WE HAVE %d MINES (*) \n", ROWS);

        printf("\n -- If you don\'t found mine, you will see: [ ] , if you find mine you will see [*]");

        printf("\n\n");

        printMines(minesArray, ROWS);

        printf(" \n -- Please enter your choice like this [1][B] or 0 next A -- \n");

        printf("  -- Please enter row: ");

        scanf("%c", &rowChoice);

        fflush(stdin);

        printf("  -- Please enter col: ");

        scanf("%c", &colChoice);

        fflush(stdin);

        checkWin(minesArray, ROWS, rowChoice, colChoice);

        printf("\n\n");

        system("pause");

    } while (foundMines != ROWS);
}

void checkWin(int array[][COLS], int rows, char rowChoice, char colChoice)
{

    static int attempts = 0;

    int iRowChoice = rowChoice - '0';

    printf(" YOUR CHOICE: %d %c ", iRowChoice, colChoice);

    int iColChoice = 0;

    switch (colChoice)
    {
    case 'A':
    case 'a':
        iColChoice = 0;
        break;
    case 'B':
    case 'b':
        iColChoice = 1;
        break;
    case 'C':
    case 'c':
        iColChoice = 2;
        break;
    case 'D':
    case 'd':
        iColChoice = 3;
        break;
    case 'E':
    case 'e':
        iColChoice = 4;
        break;
    default:
        printf(" \n Invalid Choice! \n");
        return;
        break;
    }

    // printf(" %d %d ", iRowChoice, iColChoice);

    if (array[iRowChoice][iColChoice] == 1)
    {
        printf("\n WHOOP@YOU SWEEP MINE AT COORDINATES: [%d][%c] \n", iRowChoice, colChoice);
        array[iRowChoice][iColChoice] = 3;
        foundMines++;
    }
    else if (array[iRowChoice][iColChoice] == 0)
    {
        printf("\n ATTEMPT@YOU DON\'T FOUND MINE AT: [%d][%c] \n", iRowChoice, colChoice);
        array[iRowChoice][iColChoice] = 4;
        attempts++;
    }

    printf(" Mines found: %d  |  Attempts: %d", foundMines, attempts);

    if (foundMines == ROWS)
    {
        printf("\n -- CONGRATZ! You find all mines. Bye! --\n");
    }
}

void putMines(int array[][COLS], int rows)
{

    int randomCol = 0;

    for (int i = 0; i < rows; i++)
    {
        randomCol = rand() % COLS;
        array[i][randomCol] = 1;
    }
}

void printMines(int array[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {

        printf("  %d  ", i);

        int checked = 0;

        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] == 0)
            {
                printf(" [O] ", array[i][j]);
            }
            else if (array[i][j] == 1)
            {
                printf(" [O] ", array[i][j]);
            }
            else if (array[i][j] == 3)
            {
                printf(" [*] ");
            }
            else if (array[i][j] == 4)
            {
                printf(" [ ] ");
            }
        }

        printf("\n\n");
    }

    int charA = 65;
    printf("     ");
    for (int i = 65; i < charA + COLS; i++)
    {
        printf("  %c  ", i);
    }
}
