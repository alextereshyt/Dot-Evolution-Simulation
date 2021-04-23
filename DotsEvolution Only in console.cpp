#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

void ClearScreen()
{
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void displayLand(int matrix[][110][4], int size1, int size2) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ClearScreen();
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (matrix[i][j][3] > 0) {
                SetConsoleTextAttribute(hConsole, matrix[i][j][3]); { if (matrix[i][j][3] - 10 > 0)cout << (matrix[i][j][3]); else cout << (matrix[i][j][3]) << ' '; }
            }
            else { SetConsoleTextAttribute(hConsole, 07); cout << " "; }

        }
        cout << endl;
    }
}
void display(int matrix[][110][4], int size1, int size2, int counts, int colors[]) {
    //system("clear");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ClearScreen();
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++)
            if (matrix[i][j][0] == -1) { SetConsoleTextAttribute(hConsole, 07); cout << "|"; }
            else if (matrix[i][j][0] > 0) {
                if (matrix[i][j][1] != 0) {
                    if (matrix[i][j][1] == 1)  SetConsoleTextAttribute(hConsole, colors[0]);

                    else
                        SetConsoleTextAttribute(hConsole, colors[matrix[i][j][1] + 1]);
                    cout << 'o';

                }
            }
            else { SetConsoleTextAttribute(hConsole, 07); cout << ' '; }
        cout << endl;

    }


}
int check(int matrix[][110][4], int p1, int p2, int size1, int size2) {
    if (p1 >= 0 && p2 >= 0 && matrix[p1][p2][0] != -1 && p1 < size1 && p2 < size2)return 0;
    return 1;
}


int main()
{

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    srand(time(0));
    int strange[10000];
    for (int s = 0; s < 1000; s++)
        strange[s] = 0;

    int counts = 2;
    int tempcount = 0;
    const int size1 = 30;
    const int size2 = 100;
    int matrix[size1 + 10][size2 + 10][4];
    int c = 0;
    int r1, r2;
    int temps;
    int temp;
    int tempchar = 0;
    int Fresources = 100;
    int proevo = 3;
    int REtemp = 0;
    int utemp = 1;
    int utemp1 = 1;
    int atemp;
    int colors[10000];
    //settings
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 07);
    int Slife;
    int Srange;
    int Smutation = 1000;
    int SGen = 1000;
    cout << "Evolution of spicies simulation by Alex Tereshchuk" << endl;
    int setPco, setMode;
    cout << "Mode (1 - simulation without any conditions , 2 - wall and isolation , 3 - random conditions ): ";
    cin >> setMode;
    cout << "Debug pco(1): ";
    cin >> setPco;
    cout << "Debug srange(10): ";
    cin >> Srange;
    cout << "Cells life time(3): ";
    cin >> Slife;






    //start

    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++) {
            matrix[i][j][0] = 0;
            matrix[i][j][1] = 0;
            matrix[i][j][2] = 0;
            matrix[i][j][3] = 0;
        }
    // random conditions
    int Rgo = 0;
    if (setMode == 3) {
        while (Rgo == 0) {
            for (int timegen = 0; timegen < 5; timegen++) {
                for (int i = 0; i < size1; i++)
                    for (int j = 0; j < size2; j++) {
                        if (rand() % SGen == 0) {

                            for (int p1 = -1; p1 < 2; p1++)
                                for (int p2 = -1; p2 < 2; p2++)
                                {
                                    if (check(matrix, i + p1, j + p2, size1, size2) == 0) {
                                        matrix[i + p1][j + p2][3] = rand() % 50;
                                    }
                                }
                            //reload
                            for (int i = 0; i < size1; i++) {
                                for (int j = 0; j < size2; j++) {
                                    if (matrix[i][j][3] > 0) {
                                        for (int p1 = -1; p1 < 2; p1++)
                                            for (int p2 = -1; p2 < 2; p2++)
                                            {
                                                if (i + p1 < 0 || j + p2 < 0);
                                                else if (matrix[i + p1][j + p2][3] > 0 && matrix[i + p1][j + p2][3] == matrix[i][j][3])c++;

                                            }

                                        r1 = (rand() % 3 - 1);
                                        r2 = (rand() % 3 - 1);

                                        if (c >= 3) {
                                            while (check(matrix, i + r1, j + r2, size1, size2) && matrix[i + r1][j + r2][3] == 0) {
                                                r1 = (rand() % 3 - 1);
                                                r2 = (rand() % 3 - 1);

                                            }


                                            matrix[i + r1][j + r2][3] = matrix[i][j][3];

                                            c = 0;
                                        }




                                    }
                                }

                            }


                        }

                    }




            }
            displayLand(matrix, size1, size2);
            SetConsoleTextAttribute(hConsole, 07);
            cout << "Do you want to use this pattern(1 - yes , 0 - no): ";
            cin >> Rgo;
            if (Rgo == 0)  for (int i = 0; i < size1; i++)
                for (int j = 0; j < size2; j++) {
                    matrix[i][j][3] = 0;
                }
        }

        system("CLS");
        SetConsoleTextAttribute(hConsole, 07);
    }


    //first gen

    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++) {
            temp = 0;
            for (int p1 = -1; p1 < 2; p1++)
                for (int p2 = -1; p2 < 2; p2++)
                {
                    if (check(matrix, i + p1, j + p2, size1, size2) == 0 && matrix[i + p1][j + p2][3] <= 1) {
                        temp++;
                        matrix[i + p1][j + p2][0] = 500;
                        matrix[i + p1][j + p2][1] = 1;
                        matrix[i + p1][j + p2][2] = 1;

                    }

                }
            if (temp >= 3) { i = size1 - 1; j = size2 - 1; }

        }
    colors[1] = rand() % 200;
    colors[2] = rand() % 200;
    //matrix[0][0][0] = 500;
    //matrix[0][0][1] = 1;
    //matrix[0][0][2] = 1;
    //matrix[2][1][0] = 500;
    //matrix[2][1][1] = 1;
    //matrix[2][1][2] = 1;
    //matrix[1][0][0] = 500;
    //matrix[1][0][1] = 1;
    //matrix[1][0][2] = 1;
    //matrix[0][1][0] = 500;
    //matrix[0][1][1] = 1;
    //matrix[0][1][2] = 1;
    //matrix[2][0][0] = 500;
    //matrix[2][0][1] = 1;
    //matrix[2][0][2] = 1;

    //matrix[16][84][0] = 500;
    //matrix[16][84][1] = 2;
    //matrix[16][84][2] = 2;
    //matrix[17][84][0] = 500;
    //matrix[17][84][1] = 2;
    //matrix[17][84][2] = 2;
    //matrix[16][85][0] = 500;
    //matrix[16][85][1] = 2;
    //matrix[16][85][2] = 2;
    //matrix[15][84][0] = 500;
    //matrix[15][84][1] = 2;
    //matrix[15][84][2] = 2;
    //wall
    if (setMode == 2) {
        for (int i = 0; i < size1; i++)
            matrix[i][30][0] = -1;
        matrix[9][30][0] = 0;
        matrix[10][30][0] = 0;
        matrix[11][30][0] = 0;
    }
    //loop

    for (int wtime = 0;; wtime++) {


        display(matrix, size1, size2, counts, colors);

        //wall settings
        if (setMode == 2) {
            if (wtime % 300 == 0) {
                matrix[9][30][0] = -1;
                matrix[10][30][0] = -1;
                matrix[11][30][0] = -1;


            }
            if (wtime % 600 == 0) {
                matrix[9][30][0] = 0;
                matrix[10][30][0] = 0;
                matrix[11][30][0] = 0;

            }
        }
        //display all data

        SetConsoleTextAttribute(hConsole, 07);
        cout << endl << "Year: " << wtime << endl;
        cout << endl << "Count of spicies: " << counts << endl;
        cout << "Name:    ";

        for (int ti = counts - 30; ti < counts; ti++) {
            if (ti >= 0) {
                SetConsoleTextAttribute(hConsole, colors[ti]);
                cout << "o";
                SetConsoleTextAttribute(hConsole, 07);
                cout << "  ";
            }
        }cout << endl;

        cout << "Strange: ";
        for (int ti = counts - 30; ti < counts; ti++) {
            if (ti >= 0) {
                if (ti == 0)cout << "1  ";
                else if (ti == 1)cout << "2  ";
                else if (strange[ti - 2] >= 0)
                    if (strange[ti - 2] > 9)
                        cout << strange[ti - 2] << " ";
                    else  cout << strange[ti - 2] << "  ";
            }
        }cout << endl;

        cout << "Debug:    ";
        cout << proevo << endl;


        //population resources
        temp = 0;
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++) {
                if (matrix[i][j][0] > 0) {
                    temp++;
                }

            }
        cout << "Debug count: ";
        cout << temp << endl;
        if (temp >= 600)proevo = setPco + 1;
        else  proevo = setPco;

        //reload
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (matrix[i][j][0] > 0 && wtime - matrix[i][j][0] == Slife) {
                    matrix[i][j][0] = 0; matrix[i][j][1] = 0; matrix[i][j][2] = 0;
                }
                else if (matrix[i][j][0] > 0) {
                    for (int p1 = -1; p1 < 2; p1++)
                        for (int p2 = -1; p2 < 2; p2++)
                        {

                            if (check(matrix, p1 + i, p2 + j, size1, size2) == 0 && matrix[i + p1][j + p2][0] > 0 && matrix[i + p1][j + p2][1] == matrix[i][j][1]) {
                                c++;
                            }
                        }

                    r1 = (rand() % 3 - 1);
                    r2 = (rand() % 3 - 1);

                    if (c >= 3) {
                        atemp = 0;
                        for (; atemp = 0;) {
                            r1 = (rand() % 3 - 1);
                            r2 = (rand() % 3 - 1);
                            if (check(matrix, i + r1, j + r2, size1, size2) == 0 && matrix[i][j][2] > matrix[i + r1][j + r2][2])
                                atemp = 1;
                            else if (check(matrix, i + r1, j + r2, size1, size2) == 0 && matrix[i][j][2] > matrix[i + r1][j + r2][2])
                                atemp = 1;
                        }
                        if (matrix[i + r1][j + r2][0] != -1 && matrix[i + r1][j + r2][0] == 0) {
                            if (matrix[i + r1][j + r2][3] == 0) {
                                matrix[i + r1][j + r2][0] = wtime;
                                matrix[i + r1][j + r2][1] = matrix[i][j][1];
                                matrix[i + r1][j + r2][2] = matrix[i][j][2];
                            }
                            else if (matrix[i][j][2] >= matrix[i + r1][j + r2][3] && matrix[i][j][2] <= matrix[i + r1][j + r2][3] + Srange) {
                                matrix[i + r1][j + r2][0] = wtime;
                                matrix[i + r1][j + r2][1] = matrix[i][j][1];
                                matrix[i + r1][j + r2][2] = matrix[i][j][2];

                            }
                        }
                        c = 0;
                    }
                    else if (c <= proevo) {
                        matrix[i][j][0] = 0;
                        matrix[i][j][1] = 0;
                    }



                }
            }

        }
        // mutation
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++) {
                if (matrix[i][j][0] > 0)
                    if ((rand() % Smutation) == 0) {

                        matrix[i][j][0] = wtime + 1;
                        matrix[i][j][1] = counts + 1;
                        matrix[i][j + 1][0] = wtime + 1;
                        matrix[i][j + 1][1] = counts + 1;
                        matrix[i + 1][j + 1][0] = wtime + 1;
                        matrix[i + 1][j + 1][1] = counts + 1;
                        colors[counts + 1] = rand() % 200;
                        counts++;
                        temp = rand() % 15 - 7;
                        if (matrix[i][j][2] + temp > 0) {

                            matrix[i][j + 1][2] = matrix[i][j][2] + temp;
                            matrix[i][j][2] = matrix[i][j][2] + temp;
                            matrix[i + 1][j][2] = matrix[i][j][2] + temp;
                        }
                        else {
                            matrix[i][j][2] = 1; matrix[i][j + 1][2] = 1;
                            matrix[i - 1][j][2] = 1;
                        }

                        strange[tempcount] = matrix[i][j][2];
                        tempcount++;

                    }

            }
        // who is stranger
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (matrix[i][j][0] > 0) {
                    for (int p1 = -1; p1 < 2; p1++)
                        for (int p2 = -1; p2 < 2; p2++)
                        {
                            if (matrix[i + p1][j + p2][2] > 0)
                                if (matrix[i + p1][j + p2][1] != matrix[i][j][1] && matrix[i + p1][j + p2][2] < matrix[i][j][2] && p1 != 0 && p2 != 0) {
                                    matrix[i + p1][j + p2][1] = 0; matrix[i + p1][j + p2][0] = 0; matrix[i + p1][j + p2][2] = 0;

                                }

                        }

                }
            }
        }


    }

}