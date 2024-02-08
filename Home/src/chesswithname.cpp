#include <graphics.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
// this is a chess game (i used name instead of symbol)
//  lets play
vector<vector<string>> board(8, vector<string>(8, "      "));
string whitep, blackp, previous = "";
int k = 1, pc, pr, flag;
void drawChessPiece(int x, int y, string s)
{
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    setcolor(14);
    if (s == "PAWN  ")
    {
        char temp[] = "P";
        outtextxy(x, y, temp);
    }
    else if (s == "KING  ")
    {
        char temp[] = "K";
        outtextxy(x, y, temp);
    }
    else if (s == "KNIGHT")
    {
        char temp[] = "N";
        outtextxy(x, y, temp);
    }
    else if (s == "BISHOP")
    {
        char temp[] = "B";
        outtextxy(x, y, temp);
    }
    else if (s == "QUEEN ")
    {
        char temp[] = "Q";
        outtextxy(x, y, temp);
    }
    else if (s == "ROOK  ")
    {
        char temp[] = "R";
        outtextxy(x, y, temp);
    }

    setcolor(8);
    if (s == "pawn  ")
    {
        char temp[] = "P";
        outtextxy(x, y, temp);
    }
    else if (s == "king  ")
    {
        char temp[] = "K";
        outtextxy(x, y, temp);
    }
    else if (s == "knight")
    {
        char temp[] = "N";
        outtextxy(x, y, temp);
    }
    else if (s == "bishop")
    {
        char temp[] = "B";
        outtextxy(x, y, temp);
    }
    else if (s == "queen ")
    {
        char temp[] = "Q";
        outtextxy(x, y, temp);
    }
    else if (s == "rook  ")
    {
        char temp[] = "R";
        outtextxy(x, y, temp);
    }
}

void printboard()
{
    cleardevice();
    setcolor(4);
    rectangle(406, 70, 1130, 794);
    rectangle(405, 69, 1131, 795);
    rectangle(404, 68, 1132, 796);
    rectangle(403, 67, 1133, 797);
    rectangle(402, 66, 1134, 798);
    //   settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    //   char temp[]="1";
    //   setcolor(4);
    //    outtextxy(408-40,72+30,temp);
    for (int j = 0; j < 8; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < 8; i++)
            {

                if (i % 2 == 0)
                {
                    setfillstyle(1, 15);
                    bar(408 + i * 90, 72 + j * 90, 408 + (i + 1) * 90, 72 + (j + 1) * 90);
                }
                else
                {
                    setfillstyle(1, 0);
                    bar(408 + i * 90, 72 + j * 90, 408 + (i + 1) * 90, 72 + (j + 1) * 90);
                }
            }
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (i % 2 != 0)
                {
                    setfillstyle(1, 15);
                    bar(408 + i * 90, 72 + j * 90, 408 + (i + 1) * 90, 72 + (j + 1) * 90);
                }
                else
                {
                    setfillstyle(1, 0);
                    bar(408 + i * 90, 72 + j * 90, 408 + (i + 1) * 90, 72 + (j + 1) * 90);
                }
            }
        }
    }
}
void printboardw()
{

    printboard();
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (board[j][i] == "PAWN  ")
            {

                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "ROOK  ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "KNIGHT")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "QUEEN ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "KING  ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "BISHOP")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "pawn  ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "rook  ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "knight")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "queen ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "king  ")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "bishop")
            {
                drawChessPiece(408 + i * 90 + 36 - 10, 72 + j * 90 + 36 - 10, board[j][i]);
            }
        }
    }
}
void printboardb()
{
    printboard();
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (board[j][i] == "PAWN  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "ROOK  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "KNIGHT")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "QUEEN ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "KING  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "BISHOP")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "pawn  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "rook  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "knight")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "queen ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "king  ")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
            else if (board[j][i] == "bishop")
            {
                drawChessPiece(408 + (7 - i) * 90 + 36 - 10, 72 + (7 - j) * 90 + 36 - 10, board[j][i]);
            }
        }
    }
}
void rotateright()
{
    // Step 1: Transpose the matrix
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            swap(board[i][j], board[j][i]);
        }
    }
}

void rotateboard()
{
    reverse(board.begin(), board.end());
    for (int i = 0; i < 8; i++)
    {
        reverse(board[i].begin(), board[i].end());
    }
}
void printpathw()
{
    setcolor(4);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "  *   ")
            {
                // cleardevice();
                // char arr[10];
                // string x = to_string(i);
                // sprintf(arr,"%c",x[0]);
                // outtextxy(50,50,arr);

                // char brr[10];
                // string y = to_string(j);
                // sprintf(brr,"%c",y[0]);
                // outtextxy(100,50,brr);
                rectangle(408 + j * 90 + 10 + 1, 72 + i * 90 + 10 + 1, 408 + (j + 1) * 90 - 10 - 1, 72 + (i + 1) * 90 - 10 - 1);
                rectangle(408 + j * 90 + 10 + 2, 72 + i * 90 + 10 + 2, 408 + (j + 1) * 90 - 10 - 2, 72 + (i + 1) * 90 - 10 - 2);
            }
        }
    }
}
void printpathb()
{
    setcolor(4);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "  *   ")
            {
                // cleardevice();
                // char arr[10];
                // string x = to_string(i);
                // sprintf(arr,"%c",x[0]);
                // outtextxy(50,50,arr);

                // char brr[10];
                // string y = to_string(j);
                // sprintf(brr,"%c",y[0]);
                // outtextxy(100,50,brr);
                rectangle(408 + (7 - j) * 90 + 10 + 1, 72 + (7 - i) * 90 + 10 + 1, 408 + (7 - j + 1) * 90 - 10 - 1, 72 + (7 - i + 1) * 90 - 10 - 1);
                rectangle(408 + (7 - j) * 90 + 10 + 2, 72 + (7 - i) * 90 + 10 + 2, 408 + (7 - j + 1) * 90 - 10 - 2, 72 + (7 - i + 1) * 90 - 10 - 2);
            }
        }
    }
}

void removepathw()
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "  *   ")
            {
                if ((i + j) % 2 == 0)
                    setcolor(15);
                else
                    setcolor(0);
                rectangle(408 + j * 90 + 10 + 1, 72 + i * 90 + 10 + 1, 408 + (j + 1) * 90 - 10 - 1, 72 + (i + 1) * 90 - 10 - 1);
                rectangle(408 + j * 90 + 10 + 2, 72 + i * 90 + 10 + 2, 408 + (j + 1) * 90 - 10 - 2, 72 + (i + 1) * 90 - 10 - 2);
            }
        }
    }
}
void removepathb()
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "  *   ")
            {
                if ((i + j) % 2 == 0)
                    setcolor(15);
                else
                    setcolor(0);
                rectangle(408 + (7 - j) * 90 + 10 + 1, 72 + (7 - i) * 90 + 10 + 1, 408 + (7 - j + 1) * 90 - 10 - 1, 72 + (7 - i + 1) * 90 - 10 - 1);
                rectangle(408 + (7 - j) * 90 + 10 + 2, 72 + (7 - i) * 90 + 10 + 2, 408 + (7 - j + 1) * 90 - 10 - 2, 72 + (7 - i + 1) * 90 - 10 - 2);
            }
        }
    }
}

void setpreviousmove(int p, int q, int r, int s)
{
    previous = "";
    previous += ('A' + q);
    previous += to_string(8 - p);
    previous += '-';
    previous += ('A' + s);
    previous += to_string(8 - r);
}

bool white(int x, int y)
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;

    if (board[x][y] == "PAWN  " || board[x][y] == "ROOK  " || board[x][y] == "KNIGHT" || board[x][y] == "BISHOP" || board[x][y] == "QUEEN " | board[x][y] == "KING  ")
        return true;
    else
        return false;
}
bool black(int x, int y)
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (board[x][y] == "pawn  " || board[x][y] == "rook  " || board[x][y] == "knight" || board[x][y] == "bishop" || board[x][y] == "king  " || board[x][y] == "queen ")
        return true;
    else
        return false;
}
bool blackpawnthreat(int x, int y)
{
    if (x - 1 >= 0 && y + 1 <= 7 && board[x - 1][y + 1] == "pawn  ")
        return true;
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == "pawn  ")
        return true;

    return false;
}
bool blackknightthreat(int x, int y)
{
    if (black(x + 2, y + 1) && board[x + 2][y + 1] == "knight")
        return true;
    else if (black(x + 2, y - 1) && board[x + 2][y - 1] == "knight")
        return true;
    else if (black(x - 2, y + 1) && board[x - 2][y + 1] == "knight")
        return true;
    else if (black(x - 2, y - 1) && board[x - 2][y - 1] == "knight")
        return true;
    else if (black(x + 1, y + 2) && board[x + 1][y + 2] == "knight")
        return true;
    else if (black(x + 1, y - 2) && board[x + 1][y - 2] == "knight")
        return true;
    else if (black(x - 1, y + 2) && board[x - 1][y + 2] == "knight")
        return true;
    else if (black(x - 1, y - 2) && board[x - 1][y + 2] == "knight")
        return true;

    return false;
}

bool blackrookorqueenthreat(int x, int y)
{
    for (int i = x + 1; i <= 7; i++)
    {
        if (board[i][x] == "rook  " || board[i][x] == "queen ")
        {
            return true;
        }
        else if (black(i, x) || white(i, x))
        {
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (board[i][x] == "rook  " || board[i][x] == "queen ")
        {
            return true;
        }
        else if (black(i, x) || white(i, x))
        {
            break;
        }
    }
    for (int i = y + 1; i <= 7; i++)
    {
        if (board[x][i] == "rook  " || board[x][i] == "queen ")
        {
            return true;
        }
        else if (black(x, i) || white(x, i))
        {
            break;
        }
    }

    for (int i = y - 1; i >= 0; i--)
    {
        if (board[x][i] == "rook  " || board[x][i] == "queen ")
        {
            return true;
        }
        else if (black(x, i) || white(x, i))
        {
            break;
        }
    }

    return false;
}

bool blackbishoporqueenthreat(int x, int y)
{
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++)
    {
        if (board[i][j] == "bishop" || board[i][j] == "queen ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == "bishop" || board[i][j] == "queen ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--)
    {
        if (board[i][j] == "bishop" || board[i][j] == "queen ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++)
    {
        if (board[i][j] == "bishop" || board[i][j] == "queen ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    return false;
}
/*bool blackkingthreat(int x, int y)
{
    if (x - 1 >= 0 && board[x][pc] == "king  ")
        return true;
    if (x + 1 <= 7 && board[x][pc] == "king  ")
        return true;
    if (y - 1 >= 0 && board[pr][y] == "king  ")
        return true;
    if (y + 1 <= 7 && board[pr][y] == "king  ")
        return true;

    if (x - 1 >= 0 && y - 1 >= 0 && board[x][y] == "king  ")
        return true;
    if (x - 1 >= 0 && y + 1 <= 7 && board[x][y] == "king  ")
        return true;
    if (x + 1 <= 7 && y - 1 >= 0 && board[x][y] == "king  ")
        return true;
    if (x + 1 <= 7 && y + 1 <= 7 && board[x][y] == "king  ")
        return true;

    return false;
}*/
bool blackthreat(int x, int y)
{
    if (blackpawnthreat(x, y) || blackknightthreat(x, y) || blackrookorqueenthreat(x, y) || blackbishoporqueenthreat(x, y) /*|| blackkingthreat(x, y)*/)
        return true;

    return false;
}
bool whitepawnthreat(int x, int y)
{
    if (x + 1 <= 7 && y + 1 <= 7 && board[x + 1][y + 1] == "PAWN  ")
        return true;
    if (x + 1 <= 7 && y - 1 >= 0 && board[x + 1][y - 1] == "PAWN  ")
        return true;

    return false;
}
bool whiteknightthreat(int x, int y)
{
    if (white(x + 2, y + 1) && board[x + 2][y + 1] == "KNIGHT")
        return true;
    else if (white(x + 2, y - 1) && board[x + 2][y - 1] == "KNIGHT")
        return true;
    else if (white(x - 2, y + 1) && board[x - 2][y + 1] == "KNIGHT")
        return true;
    else if (white(x - 2, y - 1) && board[x - 2][y - 1] == "KNIGHT")
        return true;
    else if (white(x + 1, y + 2) && board[x + 1][y + 2] == "KNIGHT")
        return true;
    else if (white(x + 1, y - 2) && board[x + 1][y - 2] == "KNIGHT")
        return true;
    else if (white(x - 1, y + 2) && board[x - 1][y + 2] == "KNIGHT")
        return true;
    else if (white(x - 1, y - 2) && board[x - 1][y + 2] == "KNIGHT")
        return true;

    return false;
}
bool whiterookorqueenthreat(int x, int y)
{
    for (int i = x + 1; i <= 7; i++)
    {
        if (board[i][y] == "ROOK  " || board[i][y] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, y) || white(i, y))
        {
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (board[i][y] == "ROOK  " || board[i][y] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, x) || white(i, x))
        {
            break;
        }
    }

    for (int i = y + 1; i <= 7; i++)
    {
        if (board[x][i] == "ROOK  " || board[x][i] == "QUEEN ")
        {
            return true;
        }
        else if (black(x, i) || white(x, i))
        {
            break;
        }
    }

    for (int i = y - 1; i >= 0; i--)
    {
        if (board[x][i] == "ROOK  " || board[x][i] == "QUEEN ")
        {
            return true;
        }
        else if (black(x, i) || white(x, i))
        {
            break;
        }
    }

    return false;
}
bool whitebishoporqueenthreat(int x, int y)
{
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++)
    {
        if (board[i][j] == "BISHOP" || board[i][j] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == "BISHOP" || board[i][j] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--)
    {
        if (board[i][j] == "BISHOP" || board[i][j] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++)
    {
        if (board[i][j] == "BISHOP" || board[i][j] == "QUEEN ")
        {
            return true;
        }
        else if (black(i, j) || white(i, j))
        {
            break;
        }
    }

    return false;
}
/*bool whitekingthreat(int x, int y)
{
    if (x - 1 >= 0 && board[x][pc] == "KING  ")
        return true;
    if (x + 1 <= 7 && board[x][pc] == "KING  ")
        return true;
    if (y - 1 >= 0 && board[pr][y] == "KING  ")
        return true;
    if (y + 1 <= 7 && board[pr][y] == "KING  ")
        return true;

    if (x - 1 >= 0 && y - 1 >= 0 && board[x][y] == "KING  ")
        return true;
    if (x - 1 >= 0 && y + 1 <= 7 && board[x][y] == "KING  ")
        return true;
    if (x + 1 <= 7 && y - 1 >= 0 && board[x][y] == "KING  ")
        return true;
    if (x + 1 <= 7 && y + 1 <= 7 && board[x][y] == "KING  ")
        return true;

    return false;
}*/
bool whitethreat(int x, int y)
{
    if (whitepawnthreat(x, y) || whiteknightthreat(x, y) || whiterookorqueenthreat(x, y) || whitebishoporqueenthreat(x, y) /*|| whitekingthreat(x, y)*/)
        return true;

    return false;
}
bool whitecheck()
{
    int x = -1, y = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "KING  ")
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == -1 && y == -1)
    {
        return false;
    }

    if (blackthreat(x, y))
    {
        return true;
    }

    return false;
}
bool issavingwhitecheck(int x, int y)
{
    string temp1, temp2, temp3;
    temp1 = board[pr][pc];
    temp2 = board[x][y];
    board[x][y] = temp1;
    board[pr][pc] = "      ";
    if (!whitecheck())
    {

        if (temp2 == "      ")
        {
            board[x][y] = "  *   ";
            printpathw();
        }
        else
            board[x][y] = temp2;
        board[pr][pc] = temp1;
        return true;
    }
    board[x][y] = temp2;
    board[pr][pc] = temp1;
    return false;
}
bool canwhitesave()
{

    if (board[pr][pc] == "KING  ")
    {
        bool tempflag = false;
        if (pr + 1 <= 7 && !white(pr + 1, pc))
        {
            if (!blackthreat(pr + 1, pc))
            {
                if (board[pr + 1][pc] == "      ")
                {
                    board[pr + 1][pc] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pr - 1 >= 0 && !white(pr - 1, pc))
        {
            if (!blackthreat(pr - 1, pc))
            {
                if (board[pr - 1][pc] == "      ")
                {
                    board[pr - 1][pc] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pc + 1 <= 7 && !white(pr, pc + 1))
        {
            if (!blackthreat(pr, pc + 1))
            {
                if (board[pr][pc + 1] == "      ")
                {
                    board[pr][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pc - 1 >= 0 && !white(pr, pc - 1))
        {
            if (!blackthreat(pr, pc - 1))
            {
                if (board[pr][pc - 1] == "      ")
                {
                    board[pr][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr - 1 >= 0 && pc - 1 >= 0 && !white(pr - 1, pc - 1))
        {

            if (!blackthreat(pr - 1, pc - 1))
            {
                if (board[pr - 1][pc - 1] == "      ")
                {
                    board[pr - 1][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr - 1 >= 0 && pc + 1 >= 0 && !white(pr - 1, pc + 1))
        {
            if (!blackthreat(pr - 1, pc + 1))
            {
                if (board[pr - 1][pc + 1] == "      ")
                {
                    board[pr - 1][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr + 1 <= 7 && pc - 1 >= 0 && !white(pr + 1, pc - 1))
        {

            if (!blackthreat(pr + 1, pc - 1))
            {
                if (board[pr + 1][pc - 1] == "      ")
                {
                    board[pr + 1][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr + 1 <= 7 && pc + 1 <= 7 && !white(pr + 1, pc + 1))
        {
            if (!blackthreat(pr + 1, pc + 1))
            {
                if (board[pr + 1][pc + 1] == "      ")
                {
                    board[pr + 1][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (tempflag)
        {
            printpathw();
            return tempflag;
        }
    }
    else if (board[pr][pc] == "PAWN  ")
    {
        if (pr - 1 >= 0 && board[pr - 1][pc] == "      ")
        {
            if (issavingwhitecheck(pr - 1, pc))
                return true;
        }
        if (pr == 6 && board[pr - 2][pc] == "      " && board[pr - 1][pc] == "      ")
        {
            if (issavingwhitecheck(pr - 2, pc))
                return true;
        }
        if (pr - 1 >= 0 && pc - 1 >= 0 && black(pr - 1, pc - 1))
        {
            if (issavingwhitecheck(pr - 1, pc - 1))
                return true;
        }
        if (pr - 1 >= 0 && pc + 1 <= 7 && black(pr - 1, pc + 1))
        {
            if (issavingwhitecheck(pr - 1, pc + 1))
                return true;
        }
    }

    else if (board[pr][pc] == "BISHOP")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }
    }

    else if (board[pr][pc] == "ROOK  ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (issavingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (issavingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (issavingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (issavingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }
    }
    else if (board[pr][pc] == "QUEEN ")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (issavingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (issavingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (issavingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (issavingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (issavingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }
    }
    else if (board[pr][pc] == "KNIGHT")
    {
        if (pr + 2 <= 7 && pc + 1 <= 7 && !white(pr + 2, pc + 1))
        {
            if (issavingwhitecheck(pr + 2, pc + 1))
                return true;
        }
        if (pr + 2 <= 7 && pc - 1 >= 0 && !white(pr + 2, pc - 1))
        {
            if (issavingwhitecheck(pr + 2, pc - 1))
                return true;
        }
        if (pr - 2 >= 0 && pc + 1 <= 7 && !white(pr - 2, pc + 1))
        {
            if (issavingwhitecheck(pr - 2, pc + 1))
                return true;
        }
        if (pr - 2 >= 0 && pc - 1 >= 0 && !white(pr - 2, pc - 1))
        {
            if (issavingwhitecheck(pr - 2, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 2 <= 7 && !white(pr + 1, pc + 2))
        {
            if (issavingwhitecheck(pr + 1, pc + 2))
                return true;
        }
        if (pr - 1 >= 0 && pc + 2 <= 7 && !white(pr - 1, pc + 2))
        {
            if (issavingwhitecheck(pr - 1, pc + 2))
                return true;
        }
        if (pr + 1 <= 7 && pc - 2 >= 0 && !white(pr + 1, pc - 2))
        {
            if (issavingwhitecheck(pr + 1, pc - 2))
                return true;
        }
        if (pr - 1 >= 0 && pc - 2 >= 0 && !white(pr - 1, pc - 2))
        {
            if (issavingwhitecheck(pr - 1, pc - 2))
                return true;
        }
    }

    return false;
}
bool canwhitemove()
{
    if (board[pr][pc] == "      ")
        return false;

    if (board[pr][pc] == "PAWN  ")
    {
        if (pr > 0)
        {
            if (pc == 0 && board[pr - 1][pc] != "      " && (board[pr - 1][pc + 1] == "     " || white(pr - 1, pc + 1)))
                return false;
            else if (pc == 7 && board[pr - 1][pc] != "      " && (board[pr - 1][pc - 1] == "     " || white(pr - 1, pc - 1)))
                return false;
            else if (pc > 0 && pc < 7 && board[pr - 1][pc] != "      " && (board[pr - 1][pc + 1] == "      " || white(pr - 1, pc + 1)) && (board[pr - 1][pc - 1] == "      " || white(pr - 1, pc - 1)))
                return false;

            return true;
        }
        else
        {
            return false;
        }
    }
    else if (board[pr][pc] == "ROOK  ")
    {
        if (pr + 1 <= 7 && !white(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !white(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !white(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !white(pr, pc - 1))
            return true;

        return false;
    }
    else if (board[pr][pc] == "KNIGHT")
    {
        if (pr + 2 <= 7 && pc - 1 >= 0 && !white(pr + 2, pc - 1))
            return true;
        if (pr + 2 <= 7 && pc + 1 <= 7 && !white(pr + 2, pc + 1))
            return true;
        if (pr - 2 >= 0 && pc - 1 >= 0 && !white(pr - 2, pc - 1))
            return true;
        if (pr - 2 >= 0 && pc + 1 <= 7 && !white(pr - 2, pc + 1))
            return true;

        if (pc + 2 <= 7 && pr - 1 >= 0 && !white(pr - 1, pc + 2))
            return true;
        if (pc + 2 <= 7 && pr + 1 <= 7 && !white(pr + 1, pc + 2))
            return true;
        if (pc - 2 >= 0 && pr - 1 >= 0 && !white(pr - 1, pc - 2))
            return true;
        if (pc - 2 >= 0 && pr + 1 <= 7 && !white(pr + 1, pc - 2))
            return true;

        return false;
    }

    else if (board[pr][pc] == "BISHOP")
    {
        if (pr + 1 <= 7 && pc + 1 <= 7 && !white(pr + 1, pc + 1))
            return true;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !white(pr + 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !white(pr - 1, pc + 1))
            return true;
        if (pr - 1 >= 0 && pc - 1 >= 0 && !white(pr - 1, pc - 1))
            return true;

        return false;
    }
    else if (board[pr][pc] == "QUEEN ")
    {
        if (pr + 1 <= 7 && !white(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !white(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !white(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !white(pr, pc - 1))
            return true;

        if (pr + 1 <= 7 && pc + 1 <= 7 && !white(pr + 1, pc + 1))
            return true;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !white(pr + 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !white(pr - 1, pc + 1))
            return true;
        if (pr - 1 >= 0 && pc - 1 >= 0 && !white(pr - 1, pc - 1))
            return true;

        return false;
    }

    else if (board[pr][pc] == "KING  ")
    {
        if (pr + 1 <= 7 && !white(pr + 1, pc) && !blackthreat(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !white(pr - 1, pc) && !blackthreat(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !white(pr, pc + 1) && !blackthreat(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !white(pr, pc - 1) && !blackthreat(pr, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc - 1 >= 0 && !white(pr - 1, pc - 1) && !blackthreat(pr - 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !white(pr - 1, pc + 1) && !blackthreat(pr - 1, pc + 1))
            return true;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !white(pr + 1, pc - 1) && !blackthreat(pr + 1, pc - 1))
            return true;
        if (pr + 1 <= 7 && pc + 1 <= 7 && !white(pr + 1, pc + 1) && !blackthreat(pr + 1, pc + 1))
            return true;
        return false;
    }
}
void showwhitemoves()
{

    if (board[pr][pc] == "PAWN  ")
    {
        if (pr == 6 && board[pr - 2][pc] == "      " && board[pr - 1][pc] == "      ")
        {
            board[pr - 2][pc] = "  *   ";
            board[pr - 1][pc] = "  *   ";
        }
        else if (pr != 0 && board[pr - 1][pc] == "      ")
            board[pr - 1][pc] = "  *   ";
    }
    else if (board[pr][pc] == "ROOK  ")
    {
        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "KNIGHT")
    {

        if (pr + 2 <= 7 && pc - 1 >= 0 && board[pr + 2][pc - 1] == "      ")
            board[pr + 2][pc - 1] = "  *   ";
        if (pr + 2 <= 7 && pc + 1 <= 7 && board[pr + 2][pc + 1] == "      ")
            board[pr + 2][pc + 1] = "  *   ";
        if (pr - 2 >= 0 && pc - 1 >= 0 && board[pr - 2][pc - 1] == "      ")
            board[pr - 2][pc - 1] = "  *   ";
        if (pr - 2 >= 0 && pc + 1 <= 7 && board[pr - 2][pc + 1] == "      ")
            board[pr - 2][pc + 1] = "  *   ";

        if (pc + 2 <= 7 && pr - 1 >= 0 && board[pr - 1][pc + 2] == "      ")
            board[pr - 1][pc + 2] = "  *   ";
        if (pc + 2 <= 7 && pr + 1 <= 7 && board[pr + 1][pc + 2] == "      ")
            board[pr + 1][pc + 2] = "  *   ";
        if (pc - 2 >= 0 && pr - 1 >= 0 && board[pr - 1][pc - 2] == "      ")
            board[pr - 1][pc - 2] = "  *   ";
        if (pc - 2 >= 0 && pr + 1 <= 7 && board[pr + 1][pc - 2] == "      ")
            board[pr + 1][pc - 2] = "  *   ";
    }

    else if (board[pr][pc] == "BISHOP")
    {
        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "QUEEN ")
    {
        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "KING  ")
    {
        if (pr + 1 <= 7 && board[pr + 1][pc] == "      " && !blackthreat(pr + 1, pc))
            board[pr + 1][pc] = "  *   ";
        if (pr - 1 >= 0 && board[pr - 1][pc] == "      " && !blackthreat(pr - 1, pc))
            board[pr - 1][pc] = "  *   ";
        if (pc + 1 <= 7 && board[pr][pc + 1] == "      " && !blackthreat(pr, pc + 1))
            board[pr][pc + 1] = "  *   ";
        if (pc - 1 >= 0 && board[pr][pc - 1] == "      " && !blackthreat(pr, pc - 1))
            board[pr][pc - 1] = "  *   ";
        if (pr + 1 <= 7 && pc + 1 <= 7 && board[pr + 1][pc + 1] == "      " && !blackthreat(pr + 1, pc + 1))
            board[pr + 1][pc + 1] = "  *   ";
        if (pr + 1 <= 7 && pc - 1 >= 0 && board[pr + 1][pc - 1] == "      " && !blackthreat(pr + 1, pc - 1))
            board[pr + 1][pc - 1] = "  *   ";

        if (pr - 1 >= 0 && pc + 1 <= 7 && board[pr - 1][pc + 1] == "      " && !blackthreat(pr - 1, pc + 1))
            board[pr - 1][pc + 1] = "  *   ";
        if (pr - 1 >= 0 && pc - 1 >= 0 && board[pr - 1][pc - 1] == "      " && !blackthreat(pr - 1, pc - 1))
            board[pr - 1][pc - 1] = "  *   ";
    }

    printpathw();
}
bool savingwhitecheck(int x,int y)
{

    string temp1, temp2, temp3;
    temp1 = board[pr][pc];
    temp2 = board[x][y];
    board[x][y] = temp1;
    board[pr][pc] = "      ";
    if (!whitecheck())
    {


            board[x][y] = temp2;
        board[pr][pc] = temp1;
        return true;
    }
    board[x][y] = temp2;
    board[pr][pc] = temp1;
    return false;
}
bool canwhitemovetosavecheck()
{
    if (board[pr][pc] == "KING  ")
    {
        bool tempflag = false;
        if (pr + 1 <= 7 && !white(pr + 1, pc))
        {
            if (!blackthreat(pr + 1, pc))
            {
                return true;
            }
        }
        else if (pr - 1 >= 0 && !white(pr - 1, pc))
        {
            if (!blackthreat(pr - 1, pc))
            {
                return true;
            }
        }
        else if (pc + 1 <= 7 && !white(pr, pc + 1))
        {
            if (!blackthreat(pr, pc + 1))
            {
                return true;
            }
        }
        else if (pc - 1 >= 0 && !white(pr, pc - 1))
        {
            if (!blackthreat(pr, pc - 1))
            {
                return true;
            }
        }

        else if (pr - 1 >= 0 && pc - 1 >= 0 && !white(pr - 1, pc - 1))
        {

            if (!blackthreat(pr - 1, pc - 1))
            {
                return true;
            }
        }

        else if (pr - 1 >= 0 && pc + 1 >= 0 && !white(pr - 1, pc + 1))
        {
            if (!blackthreat(pr - 1, pc + 1))
            {
                return true;
            }
        }

        else if (pr + 1 <= 7 && pc - 1 >= 0 && !white(pr + 1, pc - 1))
        {

            if (!blackthreat(pr + 1, pc - 1))
            {
                return true;
            }
        }

        else if (pr + 1 <= 7 && pc + 1 <= 7 && !white(pr + 1, pc + 1))
        {
            if (!blackthreat(pr + 1, pc + 1))
            {
                return true;
            }
        }

        return false;
    }

    else if (board[pr][pc] == "PAWN  ")
    {
        if (pr - 1 >= 0 && board[pr - 1][pc] == "      ")
        {
            if (savingwhitecheck(pr - 1, pc))
                return true;
        }
        if (pr == 6 && board[pr - 2][pc] == "      " && board[pr - 1][pc] == "      ")
        {
            if (savingwhitecheck(pr - 2, pc))
                return true;
        }
        if (pr - 1 >= 0 && pc - 1 >= 0 && black(pr - 1, pc - 1))
        {
            if (savingwhitecheck(pr - 1, pc - 1))
                return true;
        }
        if (pr - 1 >= 0 && pc + 1 <= 7 && black(pr - 1, pc + 1))
        {
            if (savingwhitecheck(pr - 1, pc + 1))
                return true;
        }
    }

    else if (board[pr][pc] == "BISHOP")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }
    }

    else if (board[pr][pc] == "ROOK  ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (savingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (savingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (savingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (savingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (savingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (savingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (savingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (savingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }
    }
    else if (board[pr][pc] == "QUEEN ")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingwhitecheck(i, j))
                    return true;
            }
            else
            {
                if (black(i, j))
                {
                    if (savingwhitecheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (savingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (savingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (savingwhitecheck(i, pc))
                    return true;
            }
            else
            {
                if (black(i, pc))
                {
                    if (savingwhitecheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (savingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (savingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (savingwhitecheck(pr, i))
                    return true;
            }
            else
            {
                if (black(pr, i))
                {
                    if (savingwhitecheck(pr, i))
                        return true;
                }
                break;
            }
        }
    }
    else if (board[pr][pc] == "KNIGHT")
    {
        if (pr + 2 <= 7 && pc + 1 <= 7 && !white(pr + 2, pc + 1))
        {
            if (savingwhitecheck(pr + 2, pc + 1))
                return true;
        }
        if (pr + 2 <= 7 && pc - 1 >= 0 && !white(pr + 2, pc - 1))
        {
            if (savingwhitecheck(pr + 2, pc - 1))
                return true;
        }
        if (pr - 2 >= 0 && pc + 1 <= 7 && !white(pr - 2, pc + 1))
        {
            if (savingwhitecheck(pr - 2, pc + 1))
                return true;
        }
        if (pr - 2 >= 0 && pc - 1 >= 0 && !white(pr - 2, pc - 1))
        {
            if (savingwhitecheck(pr - 2, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 2 <= 7 && !white(pr + 1, pc + 2))
        {
            if (savingwhitecheck(pr + 1, pc + 2))
                return true;
        }
        if (pr - 1 >= 0 && pc + 2 <= 7 && !white(pr - 1, pc + 2))
        {
            if (savingwhitecheck(pr - 1, pc + 2))
                return true;
        }
        if (pr + 1 <= 7 && pc - 2 >= 0 && !white(pr + 1, pc - 2))
        {
            if (savingwhitecheck(pr + 1, pc - 2))
                return true;
        }
        if (pr - 1 >= 0 && pc - 2 >= 0 && !white(pr - 1, pc - 2))
        {
            if (savingwhitecheck(pr - 1, pc - 2))
                return true;
        }
    }

    return false;
}

bool validwhiteplace(int x, int y)
{
    if (board[x][y] == "PAWN  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x - 1 && pc == y + 1 && black(pr, pc))
            return true;
        else if (pr == x - 1 && pc == y - 1 && black(pr, pc))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "ROOK  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr < 7 && black(pr, pc) && (board[pr + 1][pc] == "  *   " || board[pr + 1][pc] == "ROOK  "))
            return true;
        else if (pr > 0 && black(pr, pc) && (board[pr - 1][pc] == "  *   " || board[pr - 1][pc] == "ROOK  "))
            return true;
        else if (pc < 7 && black(pr, pc) && (board[pr][pc + 1] == "  *   " || board[pr][pc + 1] == "ROOK  "))
            return true;
        else if (pc > 0 && black(pr, pc) && (board[pr][pc - 1] == "  *   " || board[pr][pc - 1] == "ROOK  "))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "BISHOP")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr < 7 && pc < 7 && black(pr, pc) && (board[pr + 1][pc + 1] == "  *   " || board[pr + 1][pc + 1] == "BISHOP"))
            return true;
        else if (pr < 7 && pc > 0 && black(pr, pc) && (board[pr + 1][pc - 1] == "  *   " || board[pr + 1][pc - 1] == "BISHOP"))
            return true;
        else if (pr > 0 && pc < 7 && black(pr, pc) && (board[pr - 1][pc + 1] == "  *   " || board[pr - 1][pc + 1] == "BISHOP"))
            return true;
        else if (pr > 0 && pc > 0 && black(pr, pc) && (board[pr - 1][pc - 1] == "  *   " || board[pr - 1][pc - 1] == "BISHOP"))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "KNIGHT")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x + 1 && pc == y + 2 && black(pr, pc))
            return true;
        else if (pr == x + 1 && pc == y - 2 && black(pr, pc))
            return true;
        else if (pr == x - 1 && pc == y + 2 && black(pr, pc))
            return true;
        else if (pr == x - 1 && pc == y - 2 && black(pr, pc))
            return true;
        else if (pr == x + 2 && pc == y + 1 && black(pr, pc))
            return true;
        else if (pr == x + 2 && pc == y - 1 && black(pr, pc))
            return true;
        else if (pr == x - 2 && pc == y + 1 && black(pr, pc))
            return true;
        else if (pr == x - 2 && pc == y - 1 && black(pr, pc))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "QUEEN ")
    {

        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr >= 0 && pc >= 0 && black(pr, pc) && (board[pr + 1][pc + 1] == "  *   " || board[pr + 1][pc + 1] == "QUEEN "))
            return true;
        else if (pr >= 0 && pc <= 7 && black(pr, pc) && (board[pr + 1][pc - 1] == "  *   " || board[pr + 1][pc - 1] == "QUEEN "))
            return true;
        else if (pr <= 7 && pc >= 0 && black(pr, pc) && (board[pr - 1][pc + 1] == "  *   " || board[pr - 1][pc + 1] == "QUEEN "))
            return true;
        else if (pr <= 7 && pc <= 7 && black(pr, pc) && (board[pr - 1][pc - 1] == "  *   " || board[pr - 1][pc - 1] == "QUEEN "))
            return true;
        else if (pr >= 0 && black(pr, pc) && (board[pr + 1][pc] == "  *   " || board[pr + 1][pc] == "QUEEN "))
            return true;
        else if (pr <= 7 && black(pr, pc) && (board[pr - 1][pc] == "  *   " || board[pr - 1][pc] == "QUEEN "))
            return true;
        else if (pc >= 0 && black(pr, pc) && (board[pr][pc + 1] == "  *   " || board[pr][pc + 1] == "QUEEN "))
            return true;
        else if (pc <= 7 && black(pr, pc) && (board[pr][pc - 1] == "  *   " || board[pr][pc - 1] == "QUEEN "))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "KING  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x + 1 && black(pr, pc))
            return true;
        else if (pr == x - 1 && black(pr, pc))
            return true;
        else if (pc == y + 1 && black(pr, pc))
            return true;
        else if (pc == y - 1 && black(pr, pc))
            return true;
        else
            return false;
    }
    return true;
}

bool movewhite(int x1, int y1, int x2, int y2)
{
    int x = pr, y = pc;
    int f = 1;
    int px1, px2, py1, py2, ppr, ppc;
    while (f)
    {
        px1 = x1;
        px2 = x2;
        py1 = y1;
        py2 = y2;
        ppr = pr;
        ppc = pc;
        if (kbhit()) // Check if a key is pressed
        {
            char ch = getch(); // Get the pressed key
            switch (ch)
            {
            case 72: // Up arrow key
            {
                if (pr > 0)
                {
                    pr--;
                }
                else
                {
                    pr = 7;
                }
                if (y1 > 72 + 90)
                {
                    y1 -= 90;
                    y2 -= 90;
                }
                else
                {
                    y1 = 72 + 7 * 90 + 10;
                    y2 = 72 + 8 * 90 - 10;
                }

                break;
            }
            case 80: // Down arrow key
            {
                if (pr < 7)
                {
                    pr++;
                }
                else
                {
                    pr = 0;
                }
                if (y2 < 72 + 90 * 7)
                {
                    y2 += 90;
                    y1 += 90;
                }
                else
                {
                    y1 = 72 + 10;
                    y2 = 72 + 90 - 10;
                }
                break;
            }
            case 77: // Right arrow key
            {
                if (pc < 7)
                {
                    pc++;
                }
                else
                {
                    pc = 0;
                }

                if (x2 < 408 + 90 * 7)
                {
                    x1 += 90;
                    x2 += 90;
                }
                else
                {
                    x1 = 408 + 10;
                    x2 = 408 + 90 - 10;
                }
                break;
            }

            case 75: // Left arrow key
            {
                if (pc > 0)
                {
                    pc--;
                }
                else
                {
                    pc = 7;
                }
                if (x1 > 408 + 90)
                {
                    x1 -= 90;
                    x2 -= 90;
                }
                else
                {
                    x1 = 408 + 90 * 7 + 10;
                    x2 = 408 + 90 * 8 - 10;
                }
                break;
            }
            case 13: // Enter key
            {
                if (x == pr && y == pc)
                {
                    removepathw();
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (board[i][j] == "  *   ")
                                board[i][j] = "      ";
                        }
                    }

                    return false;
                }
                if (!white(pr, pc) && validwhiteplace(x, y))
                {
                    setpreviousmove(x, y, pr, pc);
                    removepathw();

                    if ((x + y) % 2 == 0)
                    {

                        setfillstyle(1, 15);
                    }
                    else
                    {
                        setfillstyle(1, 0);
                    }

                    bar(408 + y * 90, 72 + x * 90, 408 + (y + 1) * 90, 72 + (x + 1) * 90);
                    // drawChessPiece(408 + pc * 90 + 36 - 10, 72 + pr * 90 + 36 - 10, board[x][y]);

                    if ((pr + pc) % 2 != 0)
                    {
                        setcolor(0);
                        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                        rectangle(x1, y1, x2, y2);
                    }
                    else
                    {
                        setcolor(15);
                        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                        rectangle(x1, y1, x2, y2);
                    }

                    board[pr][pc] = board[x][y];
                    board[x][y] = "      ";
                    pr = 2;
                    pc = 7;
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (board[i][j] == "  *   ")
                                board[i][j] = "      ";
                        }
                    }
                    return true;
                    f = 0;
                }
                break;
            }
            }

            if ((pr + pc) % 2 == 0)
            {
                setcolor(0);
                rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                rectangle(px1, py1, px2, py2);
            }
            else
            {
                setcolor(15);
                rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                rectangle(px1, py1, px2, py2);
            }

            setcolor(5);
            // rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
            rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
            rectangle(x1, y1, x2, y2);
        }
    }
}

bool blackcheck()
{
    int x = -1, y = -1;

    // Find the position of the black king on the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == "king  ")
            {
                x = i;
                y = j;
            }
        }
    }

    // If black king is not found, it's not in check
    if (x == -1 && y == -1)
    {
        return false;
    }

    // Check if the black king is under threat
    if (whitethreat(x, y))
    {
        return true;
    }

    return false;
}

bool issavingblackcheck(int x, int y)
{
    string temp1, temp2, temp3;
    temp1 = board[pr][pc];
    temp2 = board[x][y];
    board[x][y] = temp1;
    board[pr][pc] = "      ";
    if (!blackcheck())
    {

        if (temp2 == "      ")
        {
            board[x][y] = "  *   ";
            printpathb();
        }
        else
            board[x][y] = temp2;
        board[pr][pc] = temp1;
        return true;
    }
    board[x][y] = temp2;
    board[pr][pc] = temp1;
    return false;
}

bool canblacksave()
{
    if (board[pr][pc] == "king  ")
    {
        bool tempflag = false;
        if (pr + 1 <= 7 && !black(pr + 1, pc))
        {
            if (!whitethreat(pr + 1, pc))
            {
                if (board[pr + 1][pc] == "      ")
                {
                    board[pr + 1][pc] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pr - 1 >= 0 && !black(pr - 1, pc))
        {
            if (!whitethreat(pr - 1, pc))
            {
                if (board[pr - 1][pc] == "      ")
                {
                    board[pr - 1][pc] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pc + 1 <= 7 && !black(pr, pc + 1))
        {
            if (!whitethreat(pr, pc + 1))
            {
                if (board[pr][pc + 1] == "      ")
                {
                    board[pr][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (pc - 1 >= 0 && !black(pr, pc - 1))
        {
            if (!whitethreat(pr, pc - 1))
            {
                if (board[pr][pc - 1] == "      ")
                {
                    board[pr][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr - 1 >= 0 && pc - 1 >= 0 && !black(pr - 1, pc - 1))
        {

            if (!whitethreat(pr - 1, pc - 1))
            {
                if (board[pr - 1][pc - 1] == "      ")
                {
                    board[pr - 1][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr - 1 >= 0 && pc + 1 >= 0 && !black(pr - 1, pc + 1))
        {
            if (!whitethreat(pr - 1, pc + 1))
            {
                if (board[pr - 1][pc + 1] == "      ")
                {
                    board[pr - 1][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr + 1 <= 7 && pc - 1 >= 0 && !black(pr + 1, pc - 1))
        {

            if (!whitethreat(pr + 1, pc - 1))
            {
                if (board[pr + 1][pc - 1] == "      ")
                {
                    board[pr + 1][pc - 1] = "  *   ";
                }
                tempflag = true;
            }
        }

        if (pr + 1 <= 7 && pc + 1 <= 7 && !black(pr + 1, pc + 1))
        {
            if (!whitethreat(pr + 1, pc + 1))
            {
                if (board[pr + 1][pc + 1] == "      ")
                {
                    board[pr + 1][pc + 1] = "  *   ";
                }
                tempflag = true;
            }
        }
        if (tempflag)
        {
            printpathb();
            return true;
        }
        return false;
    }
    else if (board[pr][pc] == "pawn  ")
    {
        if (pr + 1 <= 7 && board[pr + 1][pc] == "      ")
        {
            if (issavingblackcheck(pr + 1, pc))
                return true;
        }
        if (pr == 1 && board[pr + 2][pc] == "      " && board[pr + 1][pc] == "      ")
        {
            if (issavingblackcheck(pr + 2, pc))
                return true;
        }
        if (pr + 1 <= 7 && pc - 1 >= 0 && white(pr + 1, pc - 1))
        {
            if (issavingblackcheck(pr + 1, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 1 <= 7 && white(pr + 1, pc + 1))
        {
            if (issavingblackcheck(pr + 1, pc + 1))
                return true;
        }
    }

    else if (board[pr][pc] == "bishop")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        return false;
    }

    else if (board[pr][pc] == "rook  ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (issavingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (issavingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (issavingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (issavingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        return false;
    }
    else if (board[pr][pc] == "queen ")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (issavingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (issavingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (issavingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (issavingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (issavingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (issavingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (issavingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (issavingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        return false;
    }
    else if (board[pr][pc] == "knight")
    {
        if (pr + 2 <= 7 && pc + 1 <= 7 && !black(pr + 2, pc + 1))
        {
            if (issavingblackcheck(pr + 2, pc + 1))
                return true;
        }
        if (pr + 2 <= 7 && pc - 1 >= 0 && !black(pr + 2, pc - 1))
        {
            if (issavingblackcheck(pr + 2, pc - 1))
                return true;
        }
        if (pr - 2 >= 0 && pc + 1 <= 7 && !black(pr - 2, pc + 1))
        {
            if (issavingblackcheck(pr - 2, pc + 1))
                return true;
        }
        if (pr - 2 >= 0 && pc - 1 >= 0 && !black(pr - 2, pc - 1))
        {
            if (issavingblackcheck(pr - 2, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 2 <= 7 && !black(pr + 1, pc + 2))
        {
            if (issavingblackcheck(pr + 1, pc + 2))
                return true;
        }
        if (pr - 1 >= 0 && pc + 2 <= 7 && !black(pr - 1, pc + 2))
        {
            if (issavingblackcheck(pr - 1, pc + 2))
                return true;
        }
        if (pr + 1 <= 7 && pc - 2 >= 0 && !black(pr + 1, pc - 2))
        {
            if (issavingblackcheck(pr + 1, pc - 2))
                return true;
        }
        if (pr - 1 >= 0 && pc - 2 >= 0 && !black(pr - 1, pc - 2))
        {
            if (issavingblackcheck(pr - 1, pc - 2))
                return true;
        }
        return false;
    }

    return false;
}
void showblackmoves()
{
    if (board[pr][pc] == "pawn  ")
    {
        if (pr == 1 && board[pr + 2][pc] == "      " && board[pr + 1][pc] == "      ")
        {
            board[pr + 2][pc] = "  *   ";
            board[pr + 1][pc] = "  *   ";
        }
        else if (pr != 7 && board[pr + 1][pc] == "      ")
            board[pr + 1][pc] = "  *   ";
    }
    else if (board[pr][pc] == "rook  ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "knight")
    {
        if (pr - 2 >= 0 && pc - 1 >= 0 && board[pr - 2][pc - 1] == "      ")
            board[pr - 2][pc - 1] = "  *   ";
        if (pr - 2 >= 0 && pc + 1 <= 7 && board[pr - 2][pc + 1] == "      ")
            board[pr - 2][pc + 1] = "  *   ";
        if (pr + 2 <= 7 && pc - 1 >= 0 && board[pr + 2][pc - 1] == "      ")
            board[pr + 2][pc - 1] = "  *   ";
        if (pr + 2 <= 7 && pc + 1 <= 7 && board[pr + 2][pc + 1] == "      ")
            board[pr + 2][pc + 1] = "  *   ";

        if (pc - 2 >= 0 && pr - 1 >= 0 && board[pr - 1][pc - 2] == "      ")
            board[pr - 1][pc - 2] = "  *   ";
        if (pc - 2 >= 0 && pr + 1 <= 7 && board[pr + 1][pc - 2] == "      ")
            board[pr + 1][pc - 2] = "  *   ";
        if (pc + 2 <= 7 && pr - 1 >= 0 && board[pr - 1][pc + 2] == "      ")
            board[pr - 1][pc + 2] = "  *   ";
        if (pc + 2 <= 7 && pr + 1 <= 7 && board[pr + 1][pc + 2] == "      ")
            board[pr + 1][pc + 2] = "  *   ";
    }
    else if (board[pr][pc] == "bishop")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "queen ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
                board[i][pc] = "  *   ";
            else
                break;
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }
        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
                board[pr][i] = "  *   ";
            else
                break;
        }

        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
                board[i][j] = "  *   ";
            else
                break;
        }
    }
    else if (board[pr][pc] == "king  ")
    {
        if (pr - 1 >= 0 && !whitethreat(pr - 1, pc) && board[pr - 1][pc] == "      ")
            board[pr - 1][pc] = "  *   ";
        if (pr + 1 <= 7 && !whitethreat(pr + 1, pc) && board[pr + 1][pc] == "      ")
            board[pr + 1][pc] = "  *   ";
        if (pc - 1 >= 0 && !whitethreat(pr, pc - 1) && board[pr][pc - 1] == "      ")
            board[pr][pc - 1] = "  *   ";
        if (pc + 1 <= 7 && !whitethreat(pr, pc + 1) && board[pr][pc + 1] == "      ")
            board[pr][pc + 1] = "  *   ";
        if (pr + 1 <= 7 && pc + 1 <= 7 && !whitethreat(pr + 1, pc + 1) && board[pr + 1][pc + 1] == "      ")
            board[pr + 1][pc + 1] = "  *   ";
        if (pr + 1 <= 7 && pc - 1 >= 0 && !whitethreat(pr + 1, pc - 1) && board[pr + 1][pc - 1] == "      ")
            board[pr + 1][pc - 1] = "  *   ";
        if (pr - 1 >= 0 && pc + 1 <= 7 && !whitethreat(pr - 1, pc + 1) && board[pr - 1][pc + 1] == "      ")
            board[pr - 1][pc + 1] = "  *   ";
        if (pr - 1 >= 0 && pc - 1 >= 0 && !whitethreat(pr - 1, pc - 1) && board[pr - 1][pc - 1] == "      ")
            board[pr - 1][pc - 1] = "  *   ";
    }

    printpathb();
}
bool savingblackcheck(int x, int y)
{
    string temp1, temp2, temp3;
    temp1 = board[pr][pc];
    temp2 = board[x][y];
    board[x][y] = temp1;
    board[pr][pc] = "      ";
    if (!blackcheck())
    {

        board[x][y] = temp2;
        board[pr][pc] = temp1;
        return true;
    }
    board[x][y] = temp2;
    board[pr][pc] = temp1;
    return false;
}
bool canblackmovetosavecheck()
{
    if (board[pr][pc] == "king  ")
    {
        if (pr + 1 <= 7 && !black(pr + 1, pc))
        {
            if (!whitethreat(pr + 1, pc))
            {
                return true;
            }
        }
        else if (pr - 1 >= 0 && !black(pr - 1, pc))
        {
            if (!whitethreat(pr - 1, pc))
            {
                return true;
            }
        }
        else if (pc + 1 <= 7 && !black(pr, pc + 1))
        {
            if (!whitethreat(pr, pc + 1))
            {
                return true;
            }
        }
        else if (pc - 1 >= 0 && !black(pr, pc - 1))
        {
            if (!whitethreat(pr, pc - 1))
            {
                return true;
            }
        }

        else if (pr - 1 >= 0 && pc - 1 >= 0 && !black(pr - 1, pc - 1))
        {

            if (!whitethreat(pr - 1, pc - 1))
            {
                return true;
            }
        }

        else if (pr - 1 >= 0 && pc + 1 >= 0 && !black(pr - 1, pc + 1))
        {
            if (!whitethreat(pr - 1, pc + 1))
            {
                return true;
            }
        }

        else if (pr + 1 <= 7 && pc - 1 >= 0 && !black(pr + 1, pc - 1))
        {

            if (!whitethreat(pr + 1, pc - 1))
            {
                return true;
            }
        }

        else if (pr + 1 <= 7 && pc + 1 <= 7 && !black(pr + 1, pc + 1))
        {
            if (!whitethreat(pr + 1, pc + 1))
            {
                return true;
            }
        }
        return false;
    }

    else if (board[pr][pc] == "pawn  ")
    {
        if (pr + 1 <= 7 && board[pr + 1][pc] == "      ")
        {
            if (savingblackcheck(pr + 1, pc))
                return true;
        }
        if (pr == 1 && board[pr + 2][pc] == "      " && board[pr + 1][pc] == "      ")
        {
            if (savingblackcheck(pr + 2, pc))
                return true;
        }
        if (pr + 1 <= 7 && pc - 1 >= 0 && white(pr + 1, pc - 1))
        {
            if (savingblackcheck(pr + 1, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 1 <= 7 && white(pr + 1, pc + 1))
        {
            if (savingblackcheck(pr + 1, pc + 1))
                return true;
        }
    }

    else if (board[pr][pc] == "bishop")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        return false;
    }

    else if (board[pr][pc] == "rook  ")
    {
        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (savingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (savingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (savingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (savingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (savingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (savingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (savingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (savingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        return false;
    }
    else if (board[pr][pc] == "queen ")
    {
        for (int i = pr + 1, j = pc + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1, j = pc - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1, j = pc + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (board[i][j] == "      ")
            {
                if (savingblackcheck(i, j))
                    return true;
            }
            else
            {
                if (white(i, j))
                {
                    if (savingblackcheck(i, j))
                        return true;
                }
                break;
            }
        }

        for (int i = pr + 1; i <= 7; i++)
        {
            if (board[i][pc] == "      ")
            {
                if (savingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (savingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pr - 1; i >= 0; i--)
        {
            if (board[i][pc] == "      ")
            {
                if (savingblackcheck(i, pc))
                    return true;
            }
            else
            {
                if (white(i, pc))
                {
                    if (savingblackcheck(i, pc))
                        return true;
                }
                break;
            }
        }

        for (int i = pc + 1; i <= 7; i++)
        {
            if (board[pr][i] == "      ")
            {
                if (savingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (savingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        for (int i = pc - 1; i >= 0; i--)
        {
            if (board[pr][i] == "      ")
            {
                if (savingblackcheck(pr, i))
                    return true;
            }
            else
            {
                if (white(pr, i))
                {
                    if (savingblackcheck(pr, i))
                        return true;
                }
                break;
            }
        }

        return false;
    }
    else if (board[pr][pc] == "knight")
    {
        if (pr + 2 <= 7 && pc + 1 <= 7 && !black(pr + 2, pc + 1))
        {
            if (savingblackcheck(pr + 2, pc + 1))
                return true;
        }
        if (pr + 2 <= 7 && pc - 1 >= 0 && !black(pr + 2, pc - 1))
        {
            if (savingblackcheck(pr + 2, pc - 1))
                return true;
        }
        if (pr - 2 >= 0 && pc + 1 <= 7 && !black(pr - 2, pc + 1))
        {
            if (savingblackcheck(pr - 2, pc + 1))
                return true;
        }
        if (pr - 2 >= 0 && pc - 1 >= 0 && !black(pr - 2, pc - 1))
        {
            if (savingblackcheck(pr - 2, pc - 1))
                return true;
        }
        if (pr + 1 <= 7 && pc + 2 <= 7 && !black(pr + 1, pc + 2))
        {
            if (savingblackcheck(pr + 1, pc + 2))
                return true;
        }
        if (pr - 1 >= 0 && pc + 2 <= 7 && !black(pr - 1, pc + 2))
        {
            if (savingblackcheck(pr - 1, pc + 2))
                return true;
        }
        if (pr + 1 <= 7 && pc - 2 >= 0 && !black(pr + 1, pc - 2))
        {
            if (savingblackcheck(pr + 1, pc - 2))
                return true;
        }
        if (pr - 1 >= 0 && pc - 2 >= 0 && !black(pr - 1, pc - 2))
        {
            if (savingblackcheck(pr - 1, pc - 2))
                return true;
        }
        return false;
    }

    return false;
}

bool canblackmove()
{

    if (board[pr][pc] == "      ")
        return false;
    if (board[pr][pc] == "pawn  ")
    {
        if (pr < 7)
        {
            if (pc == 0 && board[pr + 1][pc] != "      " && (board[pr + 1][pc + 1] == "     " || black(pr + 1, pc + 1)))
                return false;
            else if (pc == 7 && board[pr + 1][pc] != "      " && (board[pr + 1][pc - 1] == "     " || black(pr + 1, pc - 1)))
                return false;
            else if (pc > 0 && pc < 7 && board[pr + 1][pc] != "      " && (board[pr + 1][pc + 1] == "      " || black(pr + 1, pc + 1)) && (board[pr + 1][pc - 1] == "      " || black(pr + 1, pc - 1)))
                return false;

            return true;
        }
        else
        {
            return false;
        }
    }
    else if (board[pr][pc] == "rook  ")
    {
        if (pr + 1 <= 7 && !black(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !black(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !black(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !black(pr, pc - 1))
            return true;

        return false;
    }
    else if (board[pr][pc] == "knight")
    {
        if (pr + 2 <= 7 && pc - 1 >= 0 && !black(pr + 2, pc - 1))
            return true;
        if (pr + 2 <= 7 && pc + 1 <= 7 && !black(pr + 2, pc + 1))
            return true;
        if (pr - 2 >= 0 && pc - 1 >= 0 && !black(pr - 2, pc - 1))
            return true;
        if (pr - 2 >= 0 && pc + 1 <= 7 && !black(pr - 2, pc + 1))
            return true;

        if (pc + 2 <= 7 && pr - 1 >= 0 && !black(pr - 1, pc + 2))
            return true;
        if (pc + 2 <= 7 && pr + 1 <= 7 && !black(pr + 1, pc + 2))
            return true;
        if (pc - 2 >= 0 && pr - 1 >= 0 && !black(pr - 1, pc - 2))
            return true;
        if (pc - 2 >= 0 && pr + 1 <= 7 && !black(pr + 1, pc - 2))
            return true;

        return false;
    }
    else if (board[pr][pc] == "bishop")
    {
        if (pr + 1 <= 7 && pc + 1 <= 7 && !black(pr + 1, pc + 1))
            return true;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !black(pr + 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !black(pr - 1, pc + 1))
            return true;
        if (pr - 1 >= 0 && pc - 1 >= 0 && !black(pr - 1, pc - 1))
            return true;

        return false;
    }
    else if (board[pr][pc] == "queen ")
    {
        if (pr + 1 <= 7 && !black(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !black(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !black(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !black(pr, pc - 1))
            return true;

        if (pr + 1 <= 7 && pc + 1 <= 7 && !black(pr + 1, pc + 1))
            return true;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !black(pr + 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !black(pr - 1, pc + 1))
            return true;
        if (pr - 1 >= 0 and pc - 1 >= 0 && !black(pr - 1, pc - 1))
            return true;

        return false;
    }
    else if (board[pr][pc] == "king  ")
    {
        if (pr + 1 <= 7 && !black(pr + 1, pc) && !whitethreat(pr + 1, pc))
            return true;
        if (pr - 1 >= 0 && !black(pr - 1, pc) && !whitethreat(pr - 1, pc))
            return true;
        if (pc + 1 <= 7 && !black(pr, pc + 1) && !whitethreat(pr, pc + 1))
            return true;
        if (pc - 1 >= 0 && !black(pr, pc - 1) && !whitethreat(pr, pc - 1))
            return true;
        if (pr + 1 <= 7 && pc + 1 <= 7 && !black(pr + 1, pc + 1) && !whitethreat(pr + 1, pc - 1))
            return false;
        if (pr + 1 <= 7 && pc - 1 >= 0 && !black(pr + 1, pc - 1) && !whitethreat(pr + 1, pc - 1))
            return true;
        if (pr - 1 >= 0 && pc + 1 <= 7 && !black(pr - 1, pc + 1) && !whitethreat(pr - 1, pc + 1))
            return false;
        if (pr - 1 >= 0 && pc - 1 >= 0 && !black(pr - 1, pc - 1) && !whitethreat(pr - 1, pc + 1))
            return true;

        return false;
    }
    return false;
}
bool validblackplace(int x, int y)
{
    if (board[x][y] == "pawn  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x + 1 && pc == y + 1 && white(pr, pc))
            return true;
        else if (pr == x + 1 && pc == y - 1 && white(pr, pc))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "rook  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr < 7 && white(pr, pc) && (board[pr + 1][pc] == "  *   " || board[pr + 1][pc] == "rook  "))
            return true;
        else if (pr > 0 && white(pr, pc) && (board[pr - 1][pc] == "  *   " || board[pr - 1][pc] == "rook  "))
            return true;
        else if (pc < 7 && white(pr, pc) && (board[pr][pc + 1] == "  *   " || board[pr][pc + 1] == "rook  "))
            return true;
        else if (pc > 0 && white(pr, pc) && (board[pr][pc - 1] == "  *   " || board[pr][pc - 1] == "rook  "))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "bishop")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr < 7 && pc < 7 && white(pr, pc) && (board[pr + 1][pc + 1] == "  *   " || board[pr + 1][pc + 1] == "bishop"))
            return true;
        else if (pr < 7 && pc > 0 && white(pr, pc) && (board[pr + 1][pc - 1] == "  *   " || board[pr + 1][pc - 1] == "bishop"))
            return true;
        else if (pr > 0 && pc < 7 && white(pr, pc) && (board[pr - 1][pc + 1] == "  *   " || board[pr - 1][pc + 1] == "bishop"))
            return true;
        else if (pr > 0 && pc > 0 && white(pr, pc) && (board[pr - 1][pc - 1] == "  *   " || board[pr - 1][pc - 1] == "bishop"))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "knight")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x + 1 && pc == y + 2 && white(pr, pc))
            return true;
        else if (pr == x + 1 && pc == y - 2 && white(pr, pc))
            return true;
        else if (pr == x - 1 && pc == y + 2 && white(pr, pc))
            return true;
        else if (pr == x - 1 && pc == y - 2 && white(pr, pc))
            return true;
        else if (pr == x + 2 && pc == y + 1 && white(pr, pc))
            return true;
        else if (pr == x + 2 && pc == y - 1 && white(pr, pc))
            return true;
        else if (pr == x - 2 && pc == y + 1 && white(pr, pc))
            return true;
        else if (pr == x - 2 && pc == y - 1 && white(pr, pc))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "queen ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr < 7 && white(pr, pc) && (board[pr + 1][pc] == "  *   " || board[pr + 1][pc] == "queen "))
            return true;
        else if (pr > 0 && white(pr, pc) && (board[pr - 1][pc] == "  *   " || board[pr - 1][pc] == "queen "))
            return true;
        else if (pc < 7 && white(pr, pc) && (board[pr][pc + 1] == "  *   " || board[pr][pc + 1] == "queen "))
            return true;
        else if (pc > 0 && white(pr, pc) && (board[pr][pc - 1] == "  *   " || board[pr][pc - 1] == "queen "))
            return true;
        else if (pr < 7 && pc < 7 && white(pr, pc) && (board[pr + 1][pc + 1] == "  *   " || board[pr + 1][pc + 1] == "queen "))
            return true;
        else if (pr < 7 && pc > 0 && white(pr, pc) && (board[pr + 1][pc - 1] == "  *   " || board[pr + 1][pc - 1] == "queen "))
            return true;
        else if (pr > 0 && pc < 7 && white(pr, pc) && (board[pr - 1][pc + 1] == "  *   " || board[pr - 1][pc + 1] == "queen "))
            return true;
        else if (pr > 0 && pc > 0 && white(pr, pc) && (board[pr - 1][pc - 1] == "  *   " || board[pr - 1][pc - 1] == "queen "))
            return true;
        else
            return false;
    }
    else if (board[x][y] == "king  ")
    {
        if (board[pr][pc] == "  *   ")
            return true;
        else if (pr == x + 1 && white(pr, pc))
            return true;
        else if (pr == x - 1 && white(pr, pc))
            return true;
        else if (pc == y + 1 && white(pr, pc))
            return true;
        else if (pc == y - 1 && white(pr, pc))
            return true;
        else
            return false;
    }
    return true;
}

bool moveblack(int x1, int y1, int x2, int y2)
{

    int x = pr, y = pc;
    int f = 1;
    int px1, px2, py1, py2, ppr, ppc;
    while (f)
    {
        px1 = x1;
        px2 = x2;
        py1 = y1;
        py2 = y2;
        ppr = pr;
        ppc = pc;
        if (kbhit()) // Check if a key is pressed
        {
            char ch = getch(); // Get the pressed key
            switch (ch)
            {
            case 72: // Up arrow key
            {
                if (pr < 7)
                {
                    pr++;
                }
                else
                {
                    pr = 0;
                }
                if (y1 > 72 + 90)
                {
                    y1 -= 90;
                    y2 -= 90;
                }
                else
                {
                    y1 = 72 + 7 * 90 + 10;
                    y2 = 72 + 8 * 90 - 10;
                }

                break;
            }
            case 80: // Down arrow key
            {
                if (pr > 0)
                {
                    pr--;
                }
                else
                {
                    pr = 7;
                }
                if (y2 < 72 + 90 * 7)
                {
                    y2 += 90;
                    y1 += 90;
                }
                else
                {
                    y1 = 72 + 10;
                    y2 = 72 + 90 - 10;
                }
                break;
            }
            case 77: // Right arrow key
            {
                if (pc > 0)
                {
                    pc--;
                }
                else
                {
                    pc = 7;
                }

                if (x2 < 408 + 90 * 7)
                {
                    x1 += 90;
                    x2 += 90;
                }
                else
                {
                    x1 = 408 + 10;
                    x2 = 408 + 90 - 10;
                }
                break;
            }

            case 75: // Left arrow key
            {
                if (pc < 7)
                {
                    pc++;
                }
                else
                {
                    pc = 0;
                }
                if (x1 > 408 + 90)
                {
                    x1 -= 90;
                    x2 -= 90;
                }
                else
                {
                    x1 = 408 + 90 * 7 + 10;
                    x2 = 408 + 90 * 8 - 10;
                }
                break;
            }
            case 13: // Enter key
            {
                if (x == pr && y == pc)
                {
                    removepathb();
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (board[i][j] == "  *   ")
                                board[i][j] = "      ";
                        }
                    }

                    return false;
                }
                if (!black(pr, pc) && validblackplace(x, y))
                {
                    setpreviousmove(x, y, pr, pc);
                    removepathb();

                    if ((x + y) % 2 == 0)
                    {

                        setfillstyle(1, 15);
                    }
                    else
                    {
                        setfillstyle(1, 0);
                    }

                    bar(408 + (7 - y) * 90, 72 + (7 - x) * 90, 408 + ((7 - y) + 1) * 90, 72 + ((7 - x) + 1) * 90);
                    // drawChessPiece(408 + (7 - pc) * 90 + 36 - 10, 72 + (7 - pr) * 90 + 36 - 10, board[x][y]);

                    if ((pr + pc) % 2 != 0)
                    {
                        setcolor(0);
                        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                        rectangle(x1, y1, x2, y2);
                    }
                    else
                    {
                        setcolor(15);
                        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                        rectangle(x1, y1, x2, y2);
                    }

                    board[pr][pc] = board[x][y];
                    board[x][y] = "      ";
                    pr = 2;
                    pc = 7;
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (board[i][j] == "  *   ")
                                board[i][j] = "      ";
                        }
                    }
                    return true;
                    f = 0;
                }
                break;
            }
            }

            if ((pr + pc) % 2 == 0)
            {
                setcolor(0);
                rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                rectangle(px1, py1, px2, py2);
            }
            else
            {
                setcolor(15);
                rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                rectangle(px1, py1, px2, py2);
            }

            setcolor(5);
            // rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
            rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
            rectangle(x1, y1, x2, y2);
        }
    }
}
bool blackischeckmate()
{
    if (!blackcheck())
        return false;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (black(i, j))
            {
                pr = i;
                pc = j;
                if (canblackmovetosavecheck())
                {

                    return false;
                }
            }
        }
    }
    return true;
}
bool whiteischeckmate()
{
    if (!whitecheck())
        return false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (white(i, j))
            {
                pr = i;
                pc = j;
                if (canwhitemovetosavecheck())
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    board[0][0] = "rook  ";
    board[0][1] = "knight";
    board[0][2] = "bishop";
    board[0][3] = "queen ";
    board[0][4] = "king  ";
    board[0][5] = "bishop";
    board[0][6] = "knight";
    board[0][7] = "rook  ";

    board[1][0] = "pawn  ";
    board[1][1] = "pawn  ";
    board[1][2] = "pawn  ";
    board[1][3] = "pawn  ";
    board[1][4] = "pawn  ";
    board[1][5] = "pawn  ";
    board[1][6] = "pawn  ";
    board[1][7] = "pawn  ";

    board[7][0] = "ROOK  ";
    board[7][1] = "KNIGHT";
    board[7][2] = "BISHOP";
    board[7][3] = "QUEEN ";
    board[7][4] = "KING  ";
    board[7][5] = "BISHOP";
    board[7][6] = "KNIGHT";
    board[7][7] = "ROOK  ";

    board[6][0] = "PAWN  ";
    board[6][1] = "PAWN  ";
    board[6][2] = "PAWN  ";
    board[6][3] = "PAWN  ";
    board[6][4] = "PAWN  ";
    board[6][5] = "PAWN  ";
    board[6][6] = "PAWN  ";
    board[6][7] = "PAWN  ";

    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file
    int height = GetSystemMetrics(SM_CYSCREEN);
    int width = GetSystemMetrics(SM_CXSCREEN);
    initwindow(width, height, "", -3, -3);

    int x1, y1, x2, y2, k = 1, c = 0;
    int px1 = 0, py1 = 0, px2 = 0, py2 = 0;

    setcolor(4);
    // rectangle(100, 50, 1400, 800);
    // rectangle(100 - 1, 50 - 1, 1400 + 1, 800 + 1);
    // rectangle(100 - 1 - 1, 50 - 1 - 1, 1400 + 1 + 1, 800 + 1 + 1);
    // rectangle(100 - 1 - 1 - 1, 50 - 1 - 1 - 1, 1400 + 1 + 1 + 1, 800 + 1 + 1 + 1);
    // rectangle(100 - 1 - 1 - 1 - 1, 50 - 1 - 1 - 1 - 1, 1400 + 1 + 1 + 1 + 1, 800 + 1 + 1 + 1 + 1);
    // settextstyle(BOLD_FONT, HORIZ_DIR, 8);
    // outtextxy(408 + 2 * 90, 72 + 45, "CHESS");
    // setcolor(5);
    // settextstyle(SCRIPT_FONT, HORIZ_DIR, 5);
    // outtextxy(408 + 2 * 90 - 50, 72 + 45 + 60, "Two player game");

    // setcolor(5);
    // settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    // outtextxy(200, 72 +3*90, "> White player enter your name -");
    // readimagefile("bpawn.png",0,0,320,320);

    // getch();

    settextstyle(BOLD_FONT, HORIZ_DIR, 6);

    while (1)
    {
       
        if (whiteischeckmate())
        {
            flag = -1;
            break;
        }
        x1 = 408 + 10;
        y1 = 72 + 450 + 10;
        x2 = 408 + 90 - 10;
        y2 = 72 + 450 + 90 - 10;
        pr = 5;
        pc = 0;

        // cleardevice();
        delay(200);
        printboardw();
        setcolor(5);
        // rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
        rectangle(x1, y1, x2, y2);
 if(whitecheck())
        {
        setcolor(4);
        char arr[] = "CHECK";
        outtextxy(50, 300, arr);
        }
        while (k % 2)
        {

            px1 = x1;
            px2 = x2;
            py1 = y1;
            py2 = y2;
            if (kbhit()) // Check if a key is pressed
            {
                char ch = getch(); // Get the pressed key
                switch (ch)
                {
                case 72: // Up arrow key
                {
                    if (pr > 0)
                    {
                        pr--;
                    }
                    else
                    {
                        pr = 7;
                    }
                    if (y1 > 72 + 90)
                    {
                        y1 -= 90;
                        y2 -= 90;
                    }
                    else
                    {
                        y1 = 72 + 7 * 90 + 10;
                        y2 = 72 + 8 * 90 - 10;
                    }

                    break;
                }
                case 80: // Down arrow key
                {
                    if (pr < 7)
                    {
                        pr++;
                    }
                    else
                    {
                        pr = 0;
                    }
                    if (y2 < 72 + 90 * 7)
                    {
                        y2 += 90;
                        y1 += 90;
                    }
                    else
                    {
                        y1 = 72 + 10;
                        y2 = 72 + 90 - 10;
                    }
                    break;
                }
                case 77: // Right arrow key
                {
                    if (pc < 7)
                    {
                        pc++;
                    }
                    else
                    {
                        pc = 0;
                    }

                    if (x2 < 408 + 90 * 7)
                    {
                        x1 += 90;
                        x2 += 90;
                    }
                    else
                    {
                        x1 = 408 + 10;
                        x2 = 408 + 90 - 10;
                    }
                    break;
                }

                case 75: // Left arrow key
                {
                    if (pc > 0)
                    {
                        pc--;
                    }
                    else
                    {
                        pc = 7;
                    }
                    if (x1 > 408 + 90)
                    {
                        x1 -= 90;
                        x2 -= 90;
                    }
                    else
                    {
                        x1 = 408 + 90 * 7 + 10;
                        x2 = 408 + 90 * 8 - 10;
                    }
                    break;
                }
                case 13: // Enter key
                {
                    if (whitecheck())
                    {
                        if (canwhitesave())
                        {

                            if (movewhite(x1, y1, x2, y2))
                                k++;
                        }
                    }
                    else
                    {
                        string temp;
                        temp = board[pr][pc];
                        board[pr][pc] = "      ";
                        if (whitecheck())
                        {
                            board[pr][pc] = temp;
                            if (canwhitemovetosavecheck())
                            {
                                if (movewhite(x1, y1, x2, y2))
                                    k++;
                            }
                        }
                        else
                        {
                            board[pr][pc] = temp;
                            if (canwhitemove())
                            {
                                showwhitemoves();

                                if (movewhite(x1, y1, x2, y2))
                                    k++;
                            }
                        }
                    }

                    break;
                }
                }
                if (k % 2)
                {
                    if ((pr + pc) % 2 == 0)
                    {
                        setcolor(0);
                        rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                        rectangle(px1, py1, px2, py2);
                    }
                    else
                    {
                        setcolor(15);
                        rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                        rectangle(px1, py1, px2, py2);
                    }
                    setcolor(5);
                    // rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                    rectangle(x1, y1, x2, y2);
                }
            }
        }

        if (blackischeckmate())
        {
            flag = 1;
            break;
        }
        x1 = 408 + 10;
        y1 = 72 + 450 + 10;
        x2 = 408 + 90 - 10;
        y2 = 72 + 450 + 90 - 10;
        pr = 2;
        pc = 7;

        delay(200);
        printboardb();
        setcolor(5);
        rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
        rectangle(x1, y1, x2, y2);
         if(blackcheck())
        {
        setcolor(4);
        char arr[] = "CHECK";
        outtextxy(50, 300, arr);
        }
        while (k % 2 == 0)
        {

            px1 = x1;
            px2 = x2;
            py1 = y1;
            py2 = y2;
            if (kbhit()) // Check if a key is pressed
            {
                char ch = getch(); // Get the pressed key
                switch (ch)
                {
                case 72: // Up arrow key
                {
                    if (pr < 7)
                    {
                        pr++;
                    }
                    else
                    {
                        pr = 0;
                    }
                    if (y1 > 72 + 90)
                    {
                        y1 -= 90;
                        y2 -= 90;
                    }
                    else
                    {
                        y1 = 72 + 7 * 90 + 10;
                        y2 = 72 + 8 * 90 - 10;
                    }

                    break;
                }
                case 80: // Down arrow key
                {
                    if (pr > 0)
                    {
                        pr--;
                    }
                    else
                    {
                        pr = 7;
                    }
                    if (y2 < 72 + 90 * 7)
                    {
                        y2 += 90;
                        y1 += 90;
                    }
                    else
                    {
                        y1 = 72 + 10;
                        y2 = 72 + 90 - 10;
                    }
                    break;
                }
                case 77: // Right arrow key
                {
                    if (pc > 0)
                    {
                        pc--;
                    }
                    else
                    {
                        pc = 7;
                    }

                    if (x2 < 408 + 90 * 7)
                    {
                        x1 += 90;
                        x2 += 90;
                    }
                    else
                    {
                        x1 = 408 + 10;
                        x2 = 408 + 90 - 10;
                    }
                    break;
                }

                case 75: // Left arrow key
                {
                    if (pc < 7)
                    {
                        pc++;
                    }
                    else
                    {
                        pc = 0;
                    }
                    if (x1 > 408 + 90)
                    {
                        x1 -= 90;
                        x2 -= 90;
                    }
                    else
                    {
                        x1 = 408 + 90 * 7 + 10;
                        x2 = 408 + 90 * 8 - 10;
                    }
                    break;
                }
                case 13: // Enter key
                {
                    if (blackcheck())
                    {
                        if (canblacksave())
                        {
                            if (moveblack(x1, y1, x2, y2))

                                k++;
                        }
                    }
                    else
                    {
                        string temp;
                        temp = board[pr][pc];
                        board[pr][pc] = "      ";
                        if (blackcheck())
                        {
                            board[pr][pc] = temp;
                            if (canblackmovetosavecheck())
                            {
                                if (moveblack(x1, y1, x2, y2))
                                    k++;
                            }
                        }
                        else
                        {
                            board[pr][pc] = temp;
                            if (canblackmove())
                            {

                                showblackmoves();

                                if (moveblack(x1, y1, x2, y2))
                                    k++;
                            }
                        }
                    }

                    printpathw();

                    break;
                }
                }
                if (k % 2 == 0)
                {
                    if ((pr + pc) % 2 == 0)
                    {
                        setcolor(0);
                        rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                        rectangle(px1, py1, px2, py2);
                    }
                    else
                    {
                        setcolor(15);
                        rectangle(px1 - 1, py1 - 1, px2 + 1, py2 + 1);
                        rectangle(px1, py1, px2, py2);
                    }
                    setcolor(5);
                    // rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
                    rectangle(x1, y1, x2, y2);
                }
            }
        }
    }

    if (flag == 1)
    {

        setcolor(4);
        char arr[] = "CHECK MATE";
        outtextxy(50, 300, arr);
        char brr[] = "WHITE WINS";
        outtextxy(50, 380, brr);
    }
    else if (flag == -1)
    {
        setcolor(4);
        char arr[] = "CHECK MATE";
        outtextxy(80, 300, arr);
        char brr[] = "BLACK WINS";
        outtextxy(80, 380, brr);
    }
    delay(1000);
    getch();
    getch();
    // cin.ignore();
    cleardevice();
    // closegraph();

    return 0;
}
