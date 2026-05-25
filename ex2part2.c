#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// sunarthsh pou epanaferei ton pinaka sthn arxikh tou katastash meta apo kathe guro
void reset(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
// sunarthsh h opoia kanei check an exoume nikh se seira sthlh h diagonio

int check(char board[3][3], char playerSymbol)
{
    // check nikh se seira h sthlh

    for (int i = 0; i < 3; i++)
    {
        if ((board[0][0] == playerSymbol && board[0][1] == playerSymbol && board[0][2] == playerSymbol) ||
            (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol))
        {
            return 1; // Win
        }
    }

    if ((board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) ||
        (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol))
    {
        return 1; // Win
    }

    return 0; // No win
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int move;
    int currentPlayer = 1;
    int wins1 = 0;
    int wins2 = 0;
    char user1[30], user2[30];

    // kalosorisma sto paixnidi
    printf("WELCOME TO TIC-TAC-TOE\n");

    // eisagogi onomaton
    printf("Player number 1, what's your name\n");
    scanf("%s", user1);
    printf("Player number 2, what's your name\n");
    scanf("%s", user2);
    if (strlen(user1) == 0 || strlen(user2) == 0)
    {
        printf("Player names cannot be empty.\n");
        return 1;
    }

    // ektuponoume ton pinaka ths 3x3
    while (wins1 < 10 && wins2 < 10)
    {
        printf("\nCurrent Score - Player 1: %d, Player 2: %d\n", wins1, wins2);

        // ektuposh ths trexousas katastashs tou pinaka
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf(" %c ", board[i][j]);
                if (j < 2)
                {
                    printf("|");
                }
            }
            printf("\n");
            if (i < 2)
            {
                printf("-----------\n");
            }
        }

        // mhnuma gia eisagogi kinhshs apo ton xrhsth
        printf("\nPlayer %d, enter your move (1-9): ", currentPlayer);

        // check an h kinhsh einai efikth
        while (1)
        {
            if (currentPlayer == 1)
            {
                scanf("%d", &move);
                if (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O')
                {
                    printf("Invalid move. Try again: ");
                }
                else
                {
                    board[(move - 1) / 3][(move - 1) % 3] = 'X';
                    break;
                }
            }
            else
            {
                move = rand() % 9 + 1;
                if (board[(move - 1) / 3][(move - 1) % 3] == ' ')
                {
                    board[(move - 1) / 3][(move - 1) % 3] = 'O';
                    printf("Computer chose position %d\n", move);
                    break;
                }
            }
        }

        // allagh tou pinaka me bash thn epilogh tou
        char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';

        // elegxos gia thn nikh
        if (check(board, playerSymbol))
        {
            printf("\nPlayer %d wins this round!\n", currentPlayer);
            if (currentPlayer == 1)
            {
                wins1++;
            }
            else
            {
                wins2++;
            }

            // epanafora tou pinaka gia ton epomeno guro
            reset(board);

            // diakoph ths while an kapoios kerdisei
            continue;
        }

        // elegxos gia isopalia

        int draw = 1;
        for (int i = 0; i < 3 && draw; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    draw = 0;
                    break;
                }
            }
        }

        if (draw)
        {
            printf("\nThe game is a draw!\n");

            // epanafora gia tou pinaka gia ton epomeno guro
            reset(board);
        }
        else
        {
            // allaxe ston allo paixth
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    // ekyupose to trexon score
    printf("\nFinal Score - Player 1: %d, Player 2: %d\n", wins1, wins2);
    // Print the name of the winner
    if (wins1 > wins2)
    {
        printf("%s is the overall winner!\n", user1);
    }
    else if (wins2 > wins1)
    {
        printf("Player 2 (%s) is the overall winner!\n", user2);
    }
    else
    {
        printf("It's a tie! No overall winner.\n");
    }
    return 0;
}