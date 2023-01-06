#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int shootx = 26;
int shooty = 55;
char shoot = 23;
int x = 25;
int y = 56;
int ex1 = 1;
int ey1 = 25;
int ex2 = 1;
int ey2 = 75;
int ex3 = 8;
int ey3 = 50;
const int height = 35;
const int width = 121;
char background[height][width] = {{"         ...*...-..|%|----------------------------------------------------------------------------|%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|                                                                            |%|*......*           "},
                                  {"         ...*...-..|%|----------------------------------------------------------------------------|%|*......*           "}};

char user_plane[6][15] = {{"    ^    "},
                          {"   | |   "},
                          {"  ||0||  "},
                          {"|(  .  )|"},
                          {"|--| |--|"},
                          {"  (|||)  "}};
char pitem[6][15] = {
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
};
int enemy1_plane[3][3] = {{219, 219, 219},
                          {208, 178, 208},
                          {32, 177, 32}};
int enemy2_plane[3][3] = {{219, 219, 219},
                          {208, 178, 208},
                          {32, 177, 32}};
int enemy3_plane[3][3] = {{219, 219, 219},
                          {208, 178, 208},
                          {32, 177, 32}};
char enemy1_pitem[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
char enemy2_pitem[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
char enemy3_pitem[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
void draw_back();
void display();
void user_plane_draw();
void user_plane_clear();
void enemy1_plane_draw();
void enemy1_plane_clear();
void enemy2_plane_draw();
void enemy2_plane_clear();
void enemy3_plane_draw();
void enemy3_plane_clear();
void gotoxy(int x, int y);
int direction();
bool enemy1_moving();
bool enemy2_moving();
bool enemy3_moving();
void title();
void menu();

main()
{
    char a = 'k';
    // system("CLS");
    // menu();

    system("CLS");
    display();
    title();

    bool gamerunning = true;
    while (gamerunning)
    {

        Sleep(50);

        if (GetAsyncKeyState(VK_SPACE))
        {
            gotoxy(shootx, shooty);
            background[shootx][shooty] = ' ';
            shootx--;
            gotoxy(shootx, shooty);
            background[shootx][shooty] = shoot;
            cout << background[shootx][shooty];
        }
        if (enemy2_moving() == 1 && enemy1_moving() == 1 && enemy3_moving() == 1)
        {
            gamerunning = true;
        }
        else
        {
            gamerunning = false;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (background[x][y - 1] != '|' || background[x][y - 1] != '-')
            {
                if (background[x][y - 1] == ' ')
                {
                    gotoxy(x, y);
                    user_plane_clear();
                    y--;
                    gotoxy(x, y);
                    user_plane_draw();
                }
            }
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (background[x][y + 1] != '|' || background[x][y + 1] != '-')
            {
                if (background[x][y + 1] == ' ')
                {
                    gotoxy(x, y);
                    user_plane_clear();
                    y++;
                    gotoxy(x, y);
                    user_plane_draw();
                }
            }
        }

        if (GetAsyncKeyState(VK_UP))
        {
            if (background[x - 1][y] != '|' || background[x - 1][y] != '-')
            {
                if (background[x - 1][y] == ' ')
                {
                    gotoxy(x, y);
                    user_plane_clear();
                    x--;
                    gotoxy(x, y);
                    user_plane_draw();
                }
            }
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            if (background[x + 1][y] != '|' || background[x + 1][y] != '-')
            {
                if (background[x + 1][y] == ' ')
                {
                    gotoxy(x, y);
                    user_plane_clear();
                    x++;
                    gotoxy(x, y);
                    user_plane_draw();
                }
            }
        }
    }
}
void display()
{
    draw_back();
    gotoxy(x, y);
    user_plane_draw();
    gotoxy(ex1, ey1);
    enemy1_plane_draw();
    gotoxy(ex2, ey2);
    enemy2_plane_draw();
    gotoxy(ex3, ey3);
    enemy3_plane_draw();
}
void gotoxy(int x, int y)
{
    COORD cor;
    cor.X = y;
    cor.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
void draw_back()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << background[i][j];
        }
        cout << endl;
    }
}
void user_plane_draw()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            gotoxy(x + i, y + j);
            pitem[i][j] = user_plane[i][j];
            cout << user_plane[i][j];
        }
    }
}
void user_plane_clear()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            gotoxy(x + i, y + j);

            pitem[i][j] = ' ';
            cout << pitem[i][j];
        }
    }
}
void enemy1_plane_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex1 + i, ey1 + j);
            enemy1_pitem[i][j] = enemy1_plane[i][j];
            cout << enemy1_pitem[i][j];
        }
        cout << endl;
    }
}
void enemy1_plane_clear()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex1 + i, ey1 + j);

            enemy1_pitem[i][j] = ' ';
            cout << enemy1_pitem[i][j];
        }
    }
}
void enemy2_plane_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex2 + i, ey2 + j);
            enemy2_pitem[i][j] = enemy2_plane[i][j];
            cout << enemy2_pitem[i][j];
        }
        cout << endl;
    }
}
void enemy2_plane_clear()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex2 + i, ey2 + j);
            enemy2_pitem[i][j] = ' ';
            cout << enemy2_pitem[i][j];
        }
    }
}

void enemy3_plane_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex3 + i, ey3 + j);
            enemy3_pitem[i][j] = enemy3_plane[i][j];
            cout << enemy3_pitem[i][j];
        }
        cout << endl;
    }
}
void enemy3_plane_clear()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(ex3 + i, ey3 + j);
            enemy3_pitem[i][j] = ' ';
            cout << enemy3_pitem[i][j];
        }
    }
}

int direction()
{
    srand(time(0));
    int result = (rand() % 4);
    return result;
}
bool enemy1_moving()
{
    int value = direction();
    if (value == 1)
    {
        if (background[ex1][ey1 - 1] != '|' || background[ex1][ey1 - 1] != '-' || background[ex1][ey1 - 1] != '%')
        {
            if (background[ex1][ey1 - 1] == ' ')
            {
                gotoxy(ex1, ey1);
                enemy1_plane_clear();
                ey1--;
                gotoxy(ex1, ey1);
                enemy1_plane_draw();
            }
        }
    }
    if (value == 2)
    {
        if (background[ex1][ey1 + 1] != '|' || background[ex1][ey1 + 1] != '-' || background[ex1][ey1 + 1] != '%')
        {
            if (background[ex1][ey1 + 1] == ' ')
            {
                gotoxy(ex1, ey1);
                enemy1_plane_clear();
                ey1++;
                gotoxy(ex1, ey1);
                enemy1_plane_draw();
            }
        }
    }

    return 1;
}
bool enemy2_moving()
{
    int value = direction();
    if (value == 1)
    {
        if (background[ex2][ey2 - 1] != '|' || background[ex2][ey2 - 1] != '-' || background[ex2][ey2 - 1] != '%')
        {
            if (background[ex2][ey2 - 1] == ' ')
            {
                gotoxy(ex2, ey2);
                enemy2_plane_clear();
                ey2--;
                gotoxy(ex2, ey2);
                enemy2_plane_draw();
            }
        }
    }
    if (value == 2)
    {
        if (background[ex2][ey2 + 1] != '|' || background[ex2][ey2 + 1] != '-' || background[ex2][ey2 + 1] != '%')
        {
            if (background[ex2][ey2 + 1] == ' ')
            {
                gotoxy(ex2, ey2);
                enemy2_plane_clear();
                ey2++;
                gotoxy(ex2, ey2);
                enemy1_plane_draw();
            }
        }
    }

    return 1;
}

bool enemy3_moving()
{
    int value = direction();
    if (value == 1)
    {
        if (background[ex3][ey3 - 1] != '|' || background[ex3][ey3 - 1] != '-' || background[ex3][ey3 - 1] != '%')
        {
            if (background[ex3][ey3 - 1] == ' ')
            {
                gotoxy(ex3, ey3);
                enemy3_plane_clear();
                ey3--;
                gotoxy(ex3, ey3);
                enemy3_plane_draw();
            }
        }
    }
    if (value == 2)
    {
        if (background[ex3][ey3 + 1] != '|' || background[ex3][ey3 + 1] != '-' || background[ex3][ey3 + 1] != '%')
        {
            if (background[ex3][ey3 + 1] == ' ')
            {
                gotoxy(ex3, ey3);
                enemy3_plane_clear();
                ey3++;
                gotoxy(ex3, ey3);
                enemy3_plane_draw();
            }
        }
    }
    if (value == 3)
    {
        if (background[ex3 - 1][ey3] != '|' || background[ex3 - 1][ey3] != '-' || background[ex3 - 1][ey3] != '%')
        {
            if (background[ex3 - 1][ey3] == ' ')
            {
                gotoxy(ex3, ey3);
                enemy3_plane_clear();
                ex3--;
                gotoxy(ex3, ey3);
                enemy3_plane_draw();
            }
        }
    }
    if (value == 4)
    {
        if (background[ex3 + 1][ey3] != '|' || background[ex3 + 1][ey3] != '-' || background[ex3 + 1][ey3] != '%')
        {
            if (background[ex3 + 1][ey3] == ' ')
            {
                gotoxy(ex3, ey3);
                enemy3_plane_clear();
                ex3++;
                gotoxy(ex3, ey3);
                enemy3_plane_draw();
            }
        }
    }

    return 1;
}
void title()
{
    gotoxy(1, 130);
    char a = 3;
    char b = 3;
    char c = 3;

    cout << "Score: ";
    cout << "\n";
    gotoxy(2, 130);
    cout << "LIFE : " << a << b << c;
    cout << "";
    cout << "" << endl;
}

