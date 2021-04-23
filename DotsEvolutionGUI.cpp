#include <SFML/Graphics.hpp>
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <windows.h>
#include <time.h>
#include <string.h>
using namespace sf; 

int check(int matrix[][50][4], int p1, int p2, int size1, int size2) {
	if (p1 >= 0 && p2 >= 0 && matrix[p1][p2][0] != -1 && p1 < size1 && p2 < size2)return 0;
	return 1;
}
void ClearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void display(int matrix[][50][4], int size1, int size2, int colors[][3], RenderWindow &window) {
	//system("clear");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	window.clear(Color(207, 202, 196, 0));

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			CircleShape circle(10.f);
			if (matrix[i][j][0] == -1) {
				SetConsoleTextAttribute(hConsole, 07);
				circle.setFillColor(Color(0, 0, 0));
				circle.move(20 * i, 20 * j); 
				window.draw(circle);
			}

			else if (matrix[i][j][0] > 0) {
				if (matrix[i][j][1] != 0) {
					if (matrix[i][j][1] == 1) {
						circle.setFillColor(Color(colors[1][0], colors[1][1], colors[1][2]));
						circle.move(20 * i, 20 * j); 
						window.draw(circle);

					}

					else
					{
						
						circle.setFillColor(Color(colors[matrix[i][j][1] + 1][0], colors[matrix[i][j][1] + 1][1], colors[matrix[i][j][1] + 1][2])); // закрашиваем наш круг 
						circle.move(20 * i, 20 * j); 
						window.draw(circle);
					}


				}
			}
			else if (matrix[i][j][3]>0) {
				circle.setFillColor(Color(207- matrix[i][j][3], 202- matrix[i][j][3], 196- matrix[i][j][3]));
				circle.move(20 * i, 20 * j);
				window.draw(circle);
			
			}
			
			
			else {
				
				circle.setFillColor(Color(207, 202, 196));
				circle.move(20 * i, 20 * j); 
				window.draw(circle); 
			}


		}
	}
	//Sleep(10);

}
void displayLand(int matrix[][50][4], int size1, int size2) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (matrix[i][j][3] > 0) {
				SetConsoleTextAttribute(hConsole, matrix[i][j][3]); { if (matrix[i][j][3] - 10 > 0)std::cout << (matrix[i][j][3]); else std::cout << (matrix[i][j][3]) << ' '; }
			}
			else { SetConsoleTextAttribute(hConsole, 07); std::cout << " "; }

		}
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(hConsole, 07);
}
int main()
{
	//inizial
	srand(time(0));
	int strange[10000];
	for (int s = 0; s < 1000; s++)
	strange[s] = 0;
	const int size1 = 50;
	const int size2 = 50;
	int matrix[size1][size2][4];
	int counts = 2;
	int tempcount = 0;
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
	int colors[10000][3];
	int Slife;
	int Srange;
	int Smutation = 1000;
	int SGen = 1000;
	
	std::cout << "Evolution of spicies simulation by Alex Tereshchuk" << std::endl;
	int setPco, setMode;
	std::cout << "Mode (1 - simulation without any conditions , 2 - wall and isolation , 3 - random conditions ): ";
	std::cin >> setMode;
	std::cout << "Debug pco(1): ";
	std::cin >> setPco;
	std::cout << "Debug srange(10): ";
	std::cin >> Srange;
	std::cout << "Cells life time(3): ";
	std::cin >> Slife;
	
	//start

	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++) {
			matrix[i][j][0] = 0;
			matrix[i][j][1] = 0;
			matrix[i][j][2] = 0;
			matrix[i][j][3] = 0;
		}
	//mode 3
	int Rgo = 0;
	if (setMode == 3) {
		while (Rgo == 0) {
			for (int timegen = 0; timegen < 6; timegen++) {
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
			std::cout << "Do you want to use this pattern(1 - yes , 0 - no): ";
			std::cin >> Rgo;
			if (Rgo == 0)  for (int i = 0; i < size1; i++)
				for (int j = 0; j < size2; j++) {
					matrix[i][j][3] = 0;
				}
		}
		system("CLS");
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
	colors[1][0] = rand() % 255;
	colors[1][1] = rand() % 255;
	colors[1][2] = rand() % 255;
	colors[2][0] = rand() % 255;
	colors[2][1] = rand() % 255;
	colors[2][2] = rand() % 255;
	if (setMode == 2) {
		for (int i = 0; i < size1; i++)
			matrix[i][25][0] = -1;
		matrix[9][25][0] = 0;
		matrix[10][25][0] = 0;
		matrix[11][25][0] = 0;
	}
	system("CLS");
	RenderWindow window(VideoMode(1000, 1000), "Evolution Simulation");
	int wtime = 0;
	while (window.isOpen())
	{
		ClearScreen();
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				wtime--;

			}
		}
		
		display(matrix,size1,size2,colors,window);

		//wall settings
		if (setMode == 2) {
			if (wtime % 300 == 0) {
				matrix[9][25][0] = -1;
				matrix[10][25][0] = -1;
				matrix[11][25][0] = -1;


			}
			if (wtime % 600 == 0) {
				matrix[9][25][0] = 0;
				matrix[10][25][0] = 0;
				matrix[11][25][0] = 0;

			}
		}
		//display all data

		
		std::cout << std::endl << "Year: " << wtime << std::endl;
		std::cout << std::endl << "Count of spicies: " << counts << std::endl;
		/*std::cout << "Strange: ";
		for (int ti = counts - 30; ti < counts; ti++) {
			if (ti >= 0) {
				if (ti == 0)std::cout << "1  ";
				else if (ti == 1)std::cout << "2  ";
				else if (strange[ti - 2] >= 0)
					if (strange[ti - 2] > 9)
						std::cout << strange[ti - 2] << " ";
					else  std::cout << strange[ti - 2] << "  ";
			}
		}std::cout << std::endl;*/

		std::cout << "Debug:    ";
		std::cout << proevo << std::endl;


		//population resources
		temp = 0;
		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++) {
				if (matrix[i][j][0] > 0) {
					temp++;
				}

			}
		std::cout << "Debug count: ";
		std::cout << temp << std::endl;
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
						
						if (matrix[i + r1][j + r2][0] != -1 && matrix[i + r1][j + r2][0] == 0&& check(matrix, i + r1, j + r2, size1, size2) == 0) {
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
					if ((rand() % Smutation == 0&& matrix[i][j + 1][0]!=-1&& matrix[i + 1][j + 1][0]!=-1)) {

						matrix[i][j][0] = wtime + 1;
						matrix[i][j][1] = counts + 1;
						matrix[i][j + 1][0] = wtime + 1;
						matrix[i][j + 1][1] = counts + 1;
						matrix[i + 1][j + 1][0] = wtime + 1;
						matrix[i + 1][j + 1][1] = counts + 1;
						colors[counts + 1][0] =  rand() % 255;
						colors[counts + 1][1] =  rand() % 255;
						colors[counts + 1][2] = rand() % 255;
						
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
							if (matrix[i + p1][j + p2][0] > 0)
								if (matrix[i + p1][j + p2][1] != matrix[i][j][1] && matrix[i + p1][j + p2][2] < matrix[i][j][2] && p1 != 0 && p2 != 0) {
									matrix[i + p1][j + p2][1] = 0; matrix[i + p1][j + p2][0] = 0; matrix[i + p1][j + p2][2] = 0;

								}

						}

				}
			}
		}


		

		
		
		window.display();
		wtime++;
	}

	return 0;
}