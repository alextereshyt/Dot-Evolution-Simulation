#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <vector>


struct cell {
	short time;
	short type;
	short strange;
	short terrain;
	short color[3];
};
using namespace sf;

bool check(cell** matrix, int p1, int p2, int size1, int size2) {
	if (p1 >= 0 && p2 >= 0 && p1 < size1 && p2 < size2 && matrix[p1][p2].time != -1)return 0;
	return 1;
}

void display(cell** matrix, RenderWindow& window, int wheel, int x, int y, int res, Event event, Texture cell, int size1, int size2, Font font, Vector2i mousepos, RectangleShape back) {



	window.clear(Color(209, 204, 199, 0));
	window.draw(back);
	int mashtab = res / size1 + wheel;// (size1 / 0.9142857142857143) + wheel; //* 1.11;
	float size = 0.04;// +wheel; //1.11;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
			if (matrix[i][j].time == -1) {
				Sprite sprite;
				sprite.setTexture(cell);
				sprite.setScale(sf::Vector2f(size, size));
				sprite.setColor(Color(0, 0, 0));
				sprite.move((mashtab * i) + x, (mashtab * j) + y);
				window.draw(sprite);
			}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {

			if (mousepos.x > (mashtab * i) + x && mousepos.x <= (mashtab * i) + x + size + 10 && mousepos.y > (mashtab * j) + y && mousepos.y <= (mashtab * j) + y + size + 10 && matrix[i][j].time != 0)
			{

				char texttemp1[100];
				char texttemp2[100];
				strcpy(texttemp1, "Spicie: ");
				_itoa(matrix[i][j].type, texttemp2, 10);
				strcat(texttemp1, texttemp2);
				Text text(texttemp1, font, 20);
				text.setFillColor(Color(0, 0, 0));
				text.setPosition(res + 60, 250);



				strcpy(texttemp1, "Strange: ");
				_itoa(matrix[i][j].strange, texttemp2, 10);
				strcat(texttemp1, texttemp2);
				Text text2(texttemp1, font, 20);
				text2.setFillColor(Color(0, 0, 0));
				text2.setPosition(res + 60, 280);

				strcpy(texttemp1, "Tarrain: ");
				_itoa(matrix[i][j].terrain, texttemp2, 10);
				strcat(texttemp1, texttemp2);
				Text text3(texttemp1, font, 20);
				text3.setFillColor(Color(0, 0, 0));
				text3.setPosition(res + 60, 310);



				Sprite sprite;
				sprite.setTexture(cell);
				sprite.setScale(0.3, 0.3);
				sprite.setColor(Color(matrix[i][j].color[0], matrix[i][j].color[1], matrix[i][j].color[2]));
				sprite.move(res + 10, 250);
				window.draw(text);
				window.draw(text2);
				window.draw(text3);
				window.draw(sprite);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(10);
					while ((sf::Mouse::isButtonPressed(sf::Mouse::Left) == 0))
					{

					}
				}

			}




			if (matrix[i][j].time > 0) {
				Sprite sprite;
				sprite.setTexture(cell);
				sprite.setScale(sf::Vector2f(size, size));
				sprite.setColor(Color(matrix[i][j].color[0], matrix[i][j].color[1], matrix[i][j].color[2]));
				sprite.move((mashtab * i) + x, ((mashtab * j) + y));
				window.draw(sprite);
			}



			else if (matrix[i][j].terrain > 0) {
				Sprite sprite;
				sprite.setTexture(cell);
				sprite.setScale(sf::Vector2f(size, size));
				sprite.setColor(Color(207 - (matrix[i][j].terrain * 2), 202 - (matrix[i][j].terrain * 2), 196 - (matrix[i][j].terrain * 2)));
				sprite.move((mashtab * i) + x, (mashtab * j) + y);
				window.draw(sprite);

			}



		}
	}
}


void displayLand(cell** matrix, int size1, int size2) {
	system("CLS");

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (i % (size1 / 64) == 0 && j % (size2 / 64) == 0) {
				if (matrix[i][j].terrain > 0) {
					{ if (matrix[i][j].terrain - 10 > 0)std::cout << (matrix[i][j].terrain); else std::cout << (matrix[i][j].terrain) << ' '; }
				}
				else { std::cout << " "; }
			}

		}if (i % (size1 / 64) == 0)
			std::cout << std::endl;
	}

}
void kill(cell* cell) {
	cell->type = 0;
	cell->strange = 0;
	cell->time = 0;

}

RectangleShape addPixel(sf::Vector2f position, sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue)
{
	sf::RectangleShape pixel;
	pixel.setSize({ 1.f, 1.f });
	pixel.setFillColor({ red, green, blue });
	pixel.setPosition(position);
	return pixel;
}
int main()
{
	//inizial
	srand(time(0));




	//int colors[10000][3];
	short counts = 2;
	short  tempcount = 0;
	short c = 0;
	short  r1, r2;
	short  temps;
	short  temp = 0;
	short  tempchar = 0;
	short  Fresources = 100;
	short  proevo = 3;
	short  REtemp = 0;
	short  utemp = 1;
	short  utemp1 = 1;
	short  atemp;
	short  Slife;

	int Srange;
	int Smutation = 30000;
	int SGen = 2000;
	int wheel = 0;

	int wtime = 0;
	int fre = 0;
	int soundMode = 0;
	float cameraMovementSpeed = 30;
	int maxPop;
	int res;
	char texttemp1[100];
	char texttemp2[100];
	int temptxt;
	int size;
	int mashtab;
	int tmp1;
	int setFrameLImit;
	//sound.setLoop(true);
	std::cout << "Evolution of spicies simulation by Alex Tereshchuk v3" << std::endl;
	int setPco = 1, setMode;
	std::cout << "Mode (1 - simulation without any conditions , 2 - wall and isolation , 3 - random conditions ): ";
	std::cin >> setMode;


	if (setMode == 3) {
		std::cout << "Debug srange(10): ";
		std::cin >> Srange;
	}
	int size1 = 256; int size2 = 256;
	/*std::cout << "Enter matrix size (128,128): ";
	std::cin >> size1>> size2;*/
	int x = 90 /*size1 / float(4.266666666666667)*/, y = 90;
	cell** matrix = new cell * [size1];
	for (int i = 0; i < size1; i++)
		matrix[i] = new cell[size2];


	std::cout << "Cells life time(3): ";
	std::cin >> Slife;
	std::cout << "Max count of population(" << (size1 * size2) / 4 << "): ";
	std::cin >> maxPop;
	if (maxPop == 0)maxPop = size1 * size2;
	std::cout << "Display resolution(1000): ";
	std::cin >> res;
	std::cout << "Enable sound (1 - yes , 0 - no): ";
	std::cin >> soundMode;
	std::cout << "Framerate limit (30): ";
	std::cin >> setFrameLImit;
	std::cout << "ESC to exit\n";

	//sound
	sf::SoundBuffer buffer;
	sf::SoundBuffer music;
	sf::Sound sound;
	if (soundMode) {
		if (!buffer.loadFromFile("sound1.wav"))
			std::cout << "Missing soundfile\n";

		sound.setBuffer(buffer);


	}

	sf::Sound music1;
	if (soundMode) {
		if (!music.loadFromFile("music.ogg"))
			std::cout << "Missing soundfile\n";

		music1.setBuffer(music);

		music1.setLoop(true);

	}


	//start
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++) {
			matrix[i][j].time = 0;
			matrix[i][j].type = 0;
			matrix[i][j].strange = 0;
			matrix[i][j].terrain = 0;
		}

	//mode 3
	int Rgo = 0;
	if (setMode == 3) {
		while (Rgo == 0) {
			for (int timegen = 0; timegen < 1; timegen++) {
				for (int i = 0; i < size1; i++)
					for (int j = 0; j < size2; j++) {
						if (rand() % SGen == 0) {

							for (int p1 = -1; p1 < 2; p1++)
								for (int p2 = -1; p2 < 2; p2++)
								{
									if (check(matrix, i + p1, j + p2, size1, size2) == 0) {
										matrix[i + p1][j + p2].terrain = rand() % 30;
									}
								}
							//reload
							for (int i = 0; i < size1; i++) {
								for (int j = 0; j < size2; j++) {
									if (matrix[i][j].terrain > 0) {
										for (int p1 = -1; p1 < 2; p1++)
											for (int p2 = -1; p2 < 2; p2++)
											{
												if (i + p1 < 0 || j + p2 < 0);
												else if (check(matrix, i + p1, j + p2, size1, size2) == 0 && matrix[i + p1][j + p2].terrain > 0 && matrix[i + p1][j + p2].terrain == matrix[i][j].terrain)c++;

											}

										r1 = (rand() % 3 - 1);
										r2 = (rand() % 3 - 1);

										if (c >= 3) {

											if (check(matrix, i + r1, j + r2, size1, size2) == 0 && matrix[i + r1][j + r2].terrain == 0)
												matrix[i + r1][j + r2].terrain = matrix[i][j].terrain;

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
					matrix[i][j].terrain = 0;
				}
		}

	}
	//music start
	music1.play();



	//first gen
	int first_color[4];
	first_color[0] = rand() % 255;
	first_color[1] = rand() % 255;
	first_color[3] = rand() % 255;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++) {
			temp = 0;
			for (int p1 = -1; p1 < 2; p1++)
				for (int p2 = -1; p2 < 2; p2++)
				{
					if (check(matrix, i + p1, j + p2, size1, size2) == 0 && matrix[i + p1][j + p2].terrain <= 1) {
						temp++;
						matrix[i + p1][j + p2].time = 500;
						matrix[i + p1][j + p2].type = 1;
						matrix[i + p1][j + p2].strange = 1;
						matrix[i + p1][j + p2].color[0] = first_color[0];
						matrix[i + p1][j + p2].color[1] = first_color[1];
						matrix[i + p1][j + p2].color[2] = first_color[2];

					}

				}
			if (temp >= 3) { i = size1 - 1; j = size2 - 1; }

		}
	//colors[1][0] = rand() % 255;
	//colors[1][1] = rand() % 255;
	//colors[1][2] = rand() % 255;
	//colors[2][0] = rand() % 255;
	//colors[2][1] = rand() % 255;
	//colors[2][2] = rand() % 255;
	if (setMode == 2) {
		for (int i = 0; i < size1; i++)
			matrix[i][size2 / 2].time = -1;
		matrix[9][size2 / 2].time = 0;
		matrix[10][size2 / 2].time = 0;
		matrix[11][size2 / 2].time = 0;
	}


	RectangleShape back(sf::Vector2f(res + 610, res));
	back.setFillColor(sf::Color(224, 221, 218));
	back.move(res, 0);
	RenderWindow window(VideoMode(res + 610, res), "Evolution Simulation v3");
	std::vector<sf::RectangleShape> pixels;
	sf::Vector2i mousepos = sf::Mouse::getPosition(window);
	//Drawing
	Texture cell;
	if (!cell.loadFromFile("cell.png"))
	{
		std::cout << "Missing cell.png\n";
	}
	cell.setSmooth(true);
	//text 


	Font font;
	font.loadFromFile("prstart.ttf");

	while (window.isOpen())
	{






		//wall settings
		if (setMode == 2) {
			if (wtime % 300 == 0) {
				matrix[9][size2 / 2].time = -1;
				matrix[10][size2 / 2].time = -1;
				matrix[11][size2 / 2].time = -1;


			}
			if (wtime % 600 == 0) {
				matrix[9][size2 / 2].time = 0;
				matrix[10][size2 / 2].time = 0;
				matrix[11][size2 / 2].time = 0;

			}
		}
		//display all data

		strcpy(texttemp1, "Gen: ");
		_itoa(wtime, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		Text text(texttemp1, font, 20);
		text.setFillColor(Color::Black);
		text.setPosition(res + 10, 0);


		strcpy(texttemp1, "Count of spicies: ");
		_itoa(counts, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		Text text2(texttemp1, font, 20);
		text2.setFillColor(Color::Black);
		text2.setPosition(res + 10, 30);




		//population resources




		strcpy(texttemp1, "Count of living cells: ");
		_itoa(temp, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		Text text4(texttemp1, font, 20);

		if (temp >= maxPop) {
			proevo = setPco + 1; Slife = 3; text4.setFillColor(Color::Red);
		}
		else if (temp > maxPop - 50 && temp < maxPop) {
			text4.setFillColor(Color(148, 35, 35));
		}
		else {
			proevo = setPco; text4.setFillColor(Color::Black);
		}
		text4.setPosition(res + 10, 60);

		strcpy(texttemp1, "Mutation chance: ");
		_itoa(Smutation, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		strcat(texttemp1, " / 1");
		Text text5(texttemp1, font, 20);
		text5.setFillColor(Color(0, 0, 0));
		text5.setPosition(res + 10, 90);
		temp = 0;

		strcpy(texttemp1, "Cell life time: ");
		_itoa(Slife, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		Text text6(texttemp1, font, 20);
		text6.setFillColor(Color(0, 0, 0));
		text6.setPosition(res + 10, 120);
		strcpy(texttemp1, "Matrix size: ");
		_itoa(size1, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		strcat(texttemp1, " / ");
		_itoa(size2, texttemp2, 10);
		strcat(texttemp1, texttemp2);
		Text text7(texttemp1, font, 20);
		text7.setFillColor(Color(0, 0, 0));
		text7.setPosition(res + 10, 150);
		//reload and ++
		for (int i = 0; i < size2; i++) {
			for (int j = 0; j < size2; j++) {
				if (matrix[i][j].time > 0 && wtime - matrix[i][j].time == Slife) {
					kill(&matrix[i][j]);
				}
				else if (matrix[i][j].time > 0) {
					for (int p1 = -1; p1 < 2; p1++)
						for (int p2 = -1; p2 < 2; p2++)
						{

							if (check(matrix, p1 + i, p2 + j, size1, size2) == 0 && matrix[i + p1][j + p2].time > 0 && matrix[i + p1][j + p2].type == matrix[i][j].type) {
								c++;
							}
						}
					//matrix[i][j].size = c - 1;





					if (c >= 3) {
						r1 = (rand() % 3 - 1);
						r2 = (rand() % 3 - 1);
						if (check(matrix, i + r1, j + r2, size1, size2) == 0 && matrix[i + r1][j + r2].time == 0) {
							if (matrix[i + r1][j + r2].terrain == 0 || matrix[i][j].strange >= matrix[i + r1][j + r2].terrain && matrix[i][j].strange <= matrix[i + r1][j + r2].terrain + Srange) {
								matrix[i + r1][j + r2].time = wtime;
								matrix[i + r1][j + r2].type = matrix[i][j].type;
								matrix[i + r1][j + r2].strange = matrix[i][j].strange;
								matrix[i + r1][j + r2].color[0] = matrix[i][j].color[0];
								matrix[i + r1][j + r2].color[1] = matrix[i][j].color[1];
								matrix[i + r1][j + r2].color[2] = matrix[i][j].color[2];

							}

						}
						c = 0;
					}
					else if (c <= proevo) {
						kill(&matrix[i][j]);
					}



				}
			}

		}
		// mutation and strange
		int new_color[3];
		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++) {
				if (matrix[i][j].time > 0) {
					if ((rand() % Smutation == 0)) {
						temp = rand() % 15 - 7;
						for (int p1 = 0; p1 < 2; p1++)
							for (int p2 = 0; p2 < 2; p2++) {
								if (check(matrix, i + p1, j + p2, size1, size2) == 0) {


									if (matrix[i + p1][j + p2].strange + temp > 0)

										matrix[i + p1][j + p2].strange = matrix[i + p1][j + p2].strange + temp;
									else matrix[i + p1][j + p2].strange = 0;


									matrix[i + p1][j + p2].time = wtime + 2;
									matrix[i + p1][j + p2].type = counts + 1;



									//colors
									if (p1 == 0 && p2 == 0) {
										new_color[0] = (matrix[i][j].color[0] + rand() % 255) / 2;
										new_color[1] = (matrix[i][j].color[1] + rand() % 255) / 2;
										new_color[2] = (matrix[i][j].color[2] + rand() % 255) / 2;
									}
									matrix[i + p1][j + p2].color[0] = new_color[0];
									matrix[i + p1][j + p2].color[1] = new_color[1];
									matrix[i + p1][j + p2].color[2] = new_color[2];





								}
							}
						sound.setPitch(rand() % 5 + 2);
						sound.play();
						counts++;
						tempcount++;
					}
				}





			}

		temp = 0;
		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++) {
				if (matrix[i][j].time > 0) {



					for (int p1 = -1; p1 < 2; p1++)
						for (int p2 = -1; p2 < 2; p2++)
						{
							if (check(matrix, i + p1, j + p2, size1, size2) == 0 && matrix[i + p1][j + p2].time > 0) {
								if (matrix[i + p1][j + p2].type != matrix[i][j].type && matrix[i + p1][j + p2].strange < matrix[i][j].strange) {

									matrix[i + p1][j + p2].type = 0; matrix[i + p1][j + p2].time = 0; matrix[i + p1][j + p2].type = 0;

								}
								temp++;
							}

						}

				}
			}


		for (const auto& pixel : pixels)
		{
			window.draw(pixel);
		}

		wtime++;
		Event event;
		window.setFramerateLimit(setFrameLImit);
		while (window.pollEvent(event))
		{
			mousepos = sf::Mouse::getPosition(window);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				delete[] matrix; std::terminate; return 0;

			}
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				for (int i = 0; i < size1; i++)
					for (int j = 0; j < size2; j++) {
						kill(&matrix[i][j]);

					}
				for (int i = 0; i < size1; i++)
					for (int j = 0; j < size2; j++) {
						temp = 0;
						for (int p1 = -1; p1 < 2; p1++)
							for (int p2 = -1; p2 < 2; p2++)
							{
								if (check(matrix, i + p1, j + p2, size1, size2) == 0 && matrix[i + p1][j + p2].terrain <= 1) {
									temp++;
									matrix[i + p1][j + p2].time = 500;
									matrix[i + p1][j + p2].type = 1;
									matrix[i + p1][j + p2].strange = 1;

								}

							}
						if (temp >= 3) { i = size1 - 1; j = size2 - 1; }

					}
			}
			else if (Keyboard::isKeyPressed(Keyboard::P))
			{
				wtime--;
				if (wtime <= 0) wtime = 0;

			}
			else if (Keyboard::isKeyPressed(Keyboard::C))
			{


				window.display();
				while (Keyboard::isKeyPressed(Keyboard::V) == 0) {


				}

			}


			else if (Keyboard::isKeyPressed(Keyboard::F))
			{
				int x = 90, y = 90;
				wheel = 0;
			}

			if (event.type == sf::Event::MouseWheelMoved)
			{

				wheel = wheel + event.mouseWheel.delta;
				//if (wheel > 0)wheel = 0;
				//if (wheel < -5)wheel = -5;
			}
		}
		//camera move
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			y = y + cameraMovementSpeed;
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			y = y - cameraMovementSpeed;
		}
		else if (Keyboard::isKeyPressed(Keyboard::A))
		{
			x = x + cameraMovementSpeed;
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			x = x - cameraMovementSpeed;
		}


		display(matrix, window, wheel, x, y, res, event, cell, size1, size2, font, mousepos, back);
		window.draw(text);
		window.draw(text2);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);

		window.display();
	}
	delete[] matrix;
	return 0;

}
