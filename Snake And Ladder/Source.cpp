#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <string>
#include<algorithm>
#include <SFML/Audio.hpp>
#define max_number_of_items 3


using namespace std;
int score, newScore1, newScore2, newScore3, newScore4, currentScore1, currentScore2, currentScore3, currentScore4, playersCounter = 1, playersNum;
bool direction1 = 0, direction2 = 0, direction3 = 0, direction4 = 0, win = 0;;
sf::Sprite sprite2, sprite3, sprite4, sprite5;
int grid[101] = {};
void board();
void scoree(int, int, int, int);
void boardColor();
void numbers();
void Dice();
void menuu();
void movment();
void generateSnakesAndLadders();
void message(int, int, int, int);
int x_position[101], y_position[101];
sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake & Ladder");

int main()
{
	Dice();
	return 0;
}
//////////////////////////////////drawing the board///////////////////////////////////////////////////////
void board()
{
	int x = 10, x1 = 610, y = 10, y1 = 10, z = 2, x2 = 10, x3 = 10, y2 = 10, y3 = 610, h = 14;
	sf::RectangleShape line;
	line.setSize(sf::Vector2f(610, 3));
	for (int i = 0; i < 11; i++)  //move 10 times
	{
		//drawing horizontal lines
		sf::Vertex linez[] =
		{
			sf::Vertex(sf::Vector2f(x,y)),
			sf::Vertex(sf::Vector2f(x1,y1))

		};

		y += 60;
		y1 += 60;
		z++;
		window.draw(linez, 2, sf::Lines);
		//drawing vertical lines
		sf::Vertex lineh[] =
		{
			sf::Vertex(sf::Vector2f(x2,y2)),
			sf::Vertex(sf::Vector2f(x3,y3))
		};
		x2 += 60;
		x3 += 60;
		h++;
		window.draw(lineh, 2, sf::Lines);
	}
	boardColor();
}
////////////////////////////COLORS//////////////////////////////
void boardColor() {
	sf::VertexArray quadred(sf::Quads, 4);
	// k1 is the up point of rectangel on y-axis 
	// k2 is the down point of rectangel on y-axis 
	// l is  the left point of rectangel on x-axis 
	int k1 = 10, k2 = 70, l = 10;
	for (int i = 0; i < 10; i++) {
		if (i > 0) {
			k1 += 60; k2 += 60;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
			{
				l = 60;
			}
			else
				l = 10;
		}
		for (int j = 0; j < 5; j++) {
			// define it as a rectangle, located at (10, 10) and with size 100x100
			quadred[0].position = sf::Vector2f(l, k1);
			//top left corner of rectangel
			quadred[1].position = sf::Vector2f(l + 60, k1);
			//top right corner of rectangel
			quadred[2].position = sf::Vector2f(l + 60, k2);
			//down right corner of rectangel
			quadred[3].position = sf::Vector2f(l, k2);
			//down left corner of rectandel

			// define its texture area to be a 25x50 rectangle starting at (0, 0)
			quadred[0].color = sf::Color::Black;
			quadred[1].color = sf::Color::Black;
			quadred[2].color = sf::Color::Black;
			quadred[3].color = sf::Color::Black;
			l += 120;

			window.draw(quadred);
		}
	}
	sf::VertexArray quadgreen(sf::Quads, 4);
	// k1 is the up point of rectangel on y-axis 
	// k2 is the down point of rectangel on y-axis 
	// l is  the left point of rectangel on x-axis 
	k1 = 10, k2 = 70, l = 70;

	for (int i = 0; i < 10; i++) {
		if (i > 0) {
			k1 += 60; k2 += 60;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
			{
				l = 10;
			}
			else
				l = 70;
		}
		for (int j = 0; j < 5; j++) {
			// define it as a rectangle, located at (10, 10) and with size 60x70

			quadgreen[0].position = sf::Vector2f(l, k2);
			//top left corner of rectangel
			quadgreen[1].position = sf::Vector2f(l + 60, k2);
			//top right corner of rectangel
			quadgreen[2].position = sf::Vector2f(l + 60, k1);
			//down right corner of rectangel
			quadgreen[3].position = sf::Vector2f(l, k1);
			//down left corner of rectandel

			// define its texture area to be a 60x60 rectangle starting at (10, 10)
			quadgreen[0].color = sf::Color::White;
			quadgreen[1].color = sf::Color::White;
			quadgreen[2].color = sf::Color::White;
			quadgreen[3].color = sf::Color::Black;
			//we will leave onerectagel since width = 60 therefor 60+60=120
			l += 120;

			window.draw(quadgreen);
		}
	}
}
///////////////////////////////// Menu /////////////////////////////////////
void menuu()
{
	sf::Texture  texture;
	if (!texture.loadFromFile("menu1.jpg"))
		cout << ":)\n";
	sf::Sprite spirite;
	spirite.setTexture(texture);
	spirite.setTextureRect({ 0, 0,1000,800 });

	sf::Font fontm;
	if (!fontm.loadFromFile("arial.ttf"))
		cout << "error\n";
	sf::Text menu[max_number_of_items];
	sf::Font fonto;
	if (!fonto.loadFromFile("arial.ttf"))
		cout << "error\n";

	menu[0].setFont(fontm);
	menu[0].setFillColor(sf::Color::Yellow);
	menu[0].setString(" [2] players ");
	menu[0].setCharacterSize(70);
	menu[0].setPosition(sf::Vector2f(450, 200));

	menu[1].setFont(fontm);
	menu[1].setFillColor(sf::Color::Magenta);
	menu[1].setString(" [3] players ");
	menu[1].setCharacterSize(70);
	menu[1].setPosition(sf::Vector2f(338, 290));

	menu[2].setFont(fontm);
	menu[2].setFillColor(sf::Color::Yellow);
	menu[2].setString(" [4] players ");
	menu[2].setCharacterSize(70);
	menu[2].setPosition(sf::Vector2f(226, 380));
	window.draw(spirite);
	for (int i = 0; i < max_number_of_items; i++)
	{
		window.draw(menu[i]);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		playersNum = 2;
		menu[0].setFillColor(sf::Color::Red);
		win = 1;
		//window.display();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		playersNum = 3;
		menu[1].setFillColor(sf::Color::Red);
		win = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		playersNum = 4;
		menu[2].setFillColor(sf::Color::Red);
		win = 1;
	}
	window.display();
}
//////////////////////////////placee for snake and ladder////////////////////////////////
void generateSnakesAndLadders()
{
	srand(time(NULL));//No Collision between snakes and ladders

	int snakeCounter = 1;
	int ladderCounter = 10;

	while (snakeCounter < 6)
	{
		score = rand() % 100 + 1;
		//to sure that there is no snakes on squ.1 or 100 and this square is empty..
		if (score == 1 || score == 100 || grid[score] != 0) continue;

		grid[score] = snakeCounter;

		while (grid[score] != 0 || score == 1 || score == 100)
		{
			score = rand() % 100 + 1;
		}

		grid[score] = snakeCounter;

		snakeCounter++;
	}

	while (ladderCounter < 16)//loop rotate 5 times
	{
		int score = rand() % 100 + 1;

		if (score == 1 || score == 100 || grid[score] != 0) continue;

		grid[score] = ladderCounter;

		while (grid[score] != 0 || score == 1 || score == 100)
		{
			score = rand() % 100 + 1;
		}

		grid[score] = ladderCounter;

		ladderCounter++;
	}
}
////////////////////////////print numbers//////////////////////////////////////////
void numbers()
{
	int  x = 0, x1 = 0, y = 0, y1 = 0, a = 1, a1 = 11, b = 10, b1 = 20;
	char num = '1', num1 = '11';
	//Print the numbers ascending from left to right
	for (int j = 0; j < 5; j++)
	{
		x = 0;
		for (int i = a; i <= b; i++)
		{
			x_position[i] = x + 30;
			y_position[i] = 560 - y;

			if (grid[i] != 0 && grid[i] < 6)
			{
				sf::Text snakei;
				sf::Font font;
				if (!font.loadFromFile("arial.ttf"))
					cout << "error\n";
				snakei.setFont(font);
				snakei.setCharacterSize(20);
				snakei.setPosition(sf::Vector2f(x_position[i], y_position[i]));
				snakei.setString("S" + to_string(grid[i]));
				snakei.setFillColor(sf::Color::Magenta);
				window.draw(snakei);
			}
			else if (grid[i] != 0 && grid[i] < 16)
			{
				sf::Text ladderi;
				sf::Font font;
				if (!font.loadFromFile("arial.ttf"))
					cout << "error\n";
				ladderi.setFont(font);
				ladderi.setCharacterSize(20);
				ladderi.setPosition(sf::Vector2f(x_position[i], y_position[i]));
				ladderi.setString("L" + to_string(grid[i] - 9));//-9-->to print numbers of ladder from 1 to 5
				ladderi.setFillColor(sf::Color::Cyan);
				window.draw(ladderi);
			}
			else
			{
				sf::Font fonti;
				if (!fonti.loadFromFile("arial.ttf"))
					cout << "error\n";
				sf::Text numberi;
				numberi.setFont(fonti);
				numberi.setString(to_string(i));
				numberi.setCharacterSize(20);
				numberi.setPosition(sf::Vector2f(x + 30, 560 - y));
				window.draw(numberi);
			}

			num += 1;
			x += 60;
		}
		a += 20;
		b += 20;
		y += 120;
	}

	//Print the numbers ascending from right to left
	for (int j = 0; j < 5; j++)
	{
		x1 = 0;
		for (int i = a1; i <= b1; i++)
		{
			x_position[i] = 570 - x1;
			y_position[i] = 505 - y1;

			if (grid[i] != 0 && grid[i] < 6)
			{
				sf::Font fontsi;
				sf::Text snakei;
				if (!fontsi.loadFromFile("arial.ttf"))
					cout << "error\n";
				snakei.setFont(fontsi);
				snakei.setCharacterSize(20);
				snakei.setPosition(sf::Vector2f(x_position[i], y_position[i]));
				snakei.setString("S" + to_string(grid[i]));
				snakei.setFillColor(sf::Color::Magenta);
				window.draw(snakei);
			}
			else if (grid[i] != 0 && grid[i] < 16)
			{
				sf::Font fontsi;
				sf::Text ladderi;
				if (!fontsi.loadFromFile("arial.ttf"))
					cout << "error\n";
				ladderi.setFont(fontsi);
				ladderi.setCharacterSize(20);
				ladderi.setPosition(sf::Vector2f(x_position[i], y_position[i]));
				ladderi.setString("L" + to_string(grid[i] - 9));
				ladderi.setFillColor(sf::Color::Cyan);
				window.draw(ladderi);
			}
			else
			{
				sf::Font fonti;
				if (!fonti.loadFromFile("arial.ttf"))
					cout << "error\n";
				sf::Text numberi;
				numberi.setFont(fonti);
				numberi.setString(to_string(i));
				numberi.setCharacterSize(20);
				numberi.setPosition(sf::Vector2f(570 - x1, 505 - y1));
				window.draw(numberi);
			}

			num1 += 1;
			x1 += 60;
		}
		a1 += 20;
		b1 += 20;
		y1 += 120;
	}
}
void scoree(int counter1, int counter2, int counter3, int counter4)
{
	int arrcount[4] = { counter1,counter2,counter3,counter4 };
	sf::Font font1, font2, font3, font4[4];
	sf::Text score[4], playname, leadboard;

	if (!font1.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	if (!font3.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	for (int i = 0; i < 4; i++)
		if (!font4[i].loadFromFile("arial.ttf"))
		{
			//handle error
		}
	leadboard.setFont(font1);
	leadboard.setString("LeaderBoard");
	leadboard.setFillColor(sf::Color::Cyan);
	leadboard.setCharacterSize(40);
	leadboard.setPosition(700, 10);
	window.draw(leadboard);
	int x = 0, y = 0;
	for (int i = 0; i < playersNum; i++)
	{
		if (i == 2)//2 to began from the start of line and continue
		{
			x = 0;
			y++;
		}
		playname.setFont(font3);
		playname.setString("player" + to_string(i + 1));
		playname.setFillColor(sf::Color::Magenta);
		playname.setCharacterSize(40);
		playname.setPosition(830 - 200 * x, 70 + 150 * y);
		score[i].setFont(font4[i]);
		if (arrcount[i] <= 100) {
			string scores = to_string(arrcount[i]);
			score[i].setString(scores);
			score[i].setFillColor(sf::Color::White);
			score[i].setCharacterSize(40);
			score[i].setPosition(860 - 200 * x, 110 + 150 * y);
			window.draw(score[i]);
		}
		else {
			string scores = to_string(100);
			score[i].setString(scores);
			score[i].setFillColor(sf::Color::White);
			score[i].setCharacterSize(40);
			score[i].setPosition(860 - 200 * x, 110 + 150 * y);
			window.draw(score[i]);
		}
		window.draw(playname);
		x++;
	}
}
////////////////////////////////////////movment of snake and ladder//////////////////////////////////////
void movment()
{
	if (playersCounter == 1)
	{
		if (grid[newScore1 + 1] >= 1 && grid[newScore1 + 1] <= 5)//snakes
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore1 + 1] && i != newScore1 + 1 && i < newScore1 + 1)
				{
					sprite2.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore1 = i - 1;
					currentScore1 = i - 1;
					//cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore1 << " " << newScore1 << " snake " << endl;
					break;
				}
			}
		}

		if (grid[newScore1 + 1] >= 10 && grid[newScore1 + 1] <= 15)//ladders
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore1 + 1] && i != newScore1 + 1 && i > newScore1 + 1)
				{
					sprite2.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore1 = i - 1;
					currentScore1 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore1 << " " << newScore1 << " ladder " << endl;
					break;
				}
			}
		}

		if ((newScore1 + 1 >= 11 && newScore1 + 1 <= 20) || (newScore1 + 1 >= 31 && newScore1 + 1 <= 40) || (newScore1 + 1 >= 51 && newScore1 + 1 <= 60) || (newScore1 + 1 >= 71 && newScore1 + 1 <= 80) || (newScore1 + 1 >= 91 && newScore1 + 1 <= 100))
			direction1 = true;
		else direction1 = false;
	}
	else if (playersCounter == 2)
	{
		if (grid[newScore2 + 1] >= 1 && grid[newScore2 + 1] <= 5)//snakes
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore2 + 1] && i != newScore2 + 1 && i < newScore2 + 1)
				{
					sprite3.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore2 = i - 1;
					currentScore2 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore2 << " " << newScore2 << " snake " << endl;
					break;
				}
			}
		}

		if (grid[newScore2 + 1] >= 10 && grid[newScore2 + 1] <= 15)//ladders
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore2 + 1] && i != newScore2 + 1 && i > newScore2 + 1)
				{
					sprite3.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore2 = i - 1;
					currentScore2 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore2 << " " << newScore2 << " ladder " << endl;
					break;
				}
			}
		}

		if ((newScore2 + 1 >= 11 && newScore2 + 1 <= 20) || (newScore2 + 1 >= 31 && newScore2 + 1 <= 40) || (newScore2 + 1 >= 51 && newScore2 + 1 <= 60) || (newScore2 + 1 >= 71 && newScore2 + 1 <= 80) || (newScore2 + 1 >= 91 && newScore2 + 1 <= 100))
			direction2 = true;
		else direction2 = false;
	}

	else if (playersCounter == 3)
	{
		if (grid[newScore3 + 1] >= 1 && grid[newScore3 + 1] <= 5)//snakes
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore3 + 1] && i != newScore3 + 1 && i < newScore3 + 1)
				{
					sprite4.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore3 = i - 1;
					currentScore3 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore3 << " " << newScore3 << " snake " << endl;
					break;
				}
			}
		}
		if (grid[newScore3 + 1] >= 10 && grid[newScore3 + 1] <= 15)//ladders
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore3 + 1] && i != newScore3 + 1 && i > newScore3 + 1)
				{
					sprite4.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore3 = i - 1;
					currentScore3 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore3 << " " << newScore3 << " ladder " << endl;
					break;
				}
			}
		}
		if ((newScore3 + 1 >= 11 && newScore3 + 1 <= 20) || (newScore3 + 1 >= 31 && newScore3 + 1 <= 40) || (newScore3 + 1 >= 51 && newScore3 + 1 <= 60) || (newScore3 + 1 >= 71 && newScore3 + 1 <= 80) || (newScore3 + 1 >= 91 && newScore3 + 1 <= 100))
			direction3 = true;
		else direction3 = false;
	}
	else if (playersCounter == 4)
	{
		if (grid[newScore4 + 1] >= 1 && grid[newScore4 + 1] <= 5)//snakes
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore4 + 1] && i != newScore4 + 1 && i < newScore4 + 1)
				{
					sprite5.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore4 = i - 1;
					currentScore4 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore4 << " " << newScore4 << " snake " << endl;
					break;
				}
			}
		}

		if (grid[newScore4 + 1] >= 10 && grid[newScore4 + 1] <= 15)//ladders
		{
			for (int i = 1; i < 101; i++)
			{
				if (grid[i] == grid[newScore4 + 1] && i != newScore4 + 1 && i > newScore4 + 1)
				{
					sprite5.setPosition(sf::Vector2f(x_position[i] - 20, y_position[i] - 10));
					newScore4 = i - 1;
					currentScore4 = i - 1;
					cout << x_position[i] << " " << y_position[i] << " " << i << " " << currentScore4 << " " << newScore4 << " ladder " << endl;
					break;
				}
			}
		}

		if ((newScore4 + 1 >= 11 && newScore4 + 1 <= 20) || (newScore4 + 1 >= 31 && newScore4 + 1 <= 40) || (newScore4 + 1 >= 51 && newScore4 + 1 <= 60) || (newScore4 + 1 >= 71 && newScore4 + 1 <= 80) || (newScore4 + 1 >= 91 && newScore4 + 1 <= 100))
			direction4 = true;
		else direction4 = false;
	}
}
//////////////////////////////message for the winner one ////////////////////////////////////////
void message(int counter1, int counter2, int counter3, int counter4)
{
	if (counter1 >= 100 || counter2 >= 100 || counter3 >= 100 || counter4 >= 100)
	{
		sf::Font font;
		sf::Text massag;
		if (!font.loadFromFile("arial.ttf"))
		{
			//handle error
		}
		massag.setFont(font);
		if (counter1 >= 100)
			massag.setString("PLAYER 1 CONGRATULATION YOU ARE WINNER !");
		if (counter2 >= 100)
			massag.setString("PLAYER 2 CONGRATULATION YOU ARE WINNER !");
		if (counter3 >= 100)
			massag.setString("PLAYER 3 CONGRATULATION YOU ARE WINNER !");
		if (counter4 >= 100)
			massag.setString("PLAYER 4 CONGRATULATION YOU ARE WINNER !");
		massag.setFillColor(sf::Color::Magenta);
		massag.setCharacterSize(40);
		massag.setPosition(10, 650);
		window.draw(massag);
	}
}
////////////////////////////////////dice rolling//////////////////////////////////////
void Dice()
{
	int counter1 = 1, counter2 = 1, counter3 = 1, counter4 = 1;
	currentScore1 = 0, currentScore2 = 0, currentScore3 = 0, currentScore4 = 0;
	sf::Texture  texture0, texture1, texture2, texture3, texture4, texture5, texture6, player1, player2, player3, player4;

	sf::SoundBuffer diceSound;     //sound of dice 
	if (!diceSound.loadFromFile("dice sound.wav "))
	{
		cout << "error  dice sound ";
	}
	sf::Sound sound;
	sound.setBuffer(diceSound);
	sf::SoundBuffer gamemusic;
	if (!gamemusic.loadFromFile("sea.wav"))
	{
		cout << "error";
	}
	sf::Sound sound1;
	sound1.setBuffer(gamemusic);

	sf::Sprite sprite;
	if (!player1.loadFromFile("player 1.png"))
		cout << "Error";
	sprite2.setTexture(player1);
	sprite2.setPosition(sf::Vector2f(20, 550));
	if (!player2.loadFromFile("player 2.png"))
		cout << "Error";
	sprite3.setTexture(player2);
	sprite3.setPosition(sf::Vector2f(20, 550));
	if (!texture0.loadFromFile("dice.png"))
		cout << ":)\n";
	sprite.setTexture(texture0);
	sprite.setPosition(sf::Vector2f(700, 500));
	//choose random number
	int rando = 0;
	//srand(time(0));
	bool move1 = 0, move2 = 0, move3 = 0, move4 = 0;

	generateSnakesAndLadders();     //caling snakes and ladders

	while (window.isOpen())
	{
		if (win == 0)
		{
			menuu();
			if (!player1.loadFromFile("player 1.png"))
				cout << "Error";
			sprite2.setTexture(player1);
			sprite2.setPosition(sf::Vector2f(20, 550));
			if (!player2.loadFromFile("player 2.png"))
				cout << "Error";
			sprite3.setTexture(player2);
			sprite3.setPosition(sf::Vector2f(20, 550));

			if (playersNum >= 3) {
				if (!player3.loadFromFile("player 3.png"))
					cout << "Error";
				sprite4.setTexture(player3);
				sprite4.setPosition(sf::Vector2f(20, 550));
			}

			if (playersNum == 4)
			{
				if (!player4.loadFromFile("player 4.png"))
					cout << "Error";
				sprite5.setTexture(player4);
				sprite5.setPosition(sf::Vector2f(20, 550));
			}
			continue;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && newScore1 <= 100 && newScore2 <= 100 && newScore3 <= 100 && newScore4 <= 100)
		{
			sound.play();
			int x = sf::Mouse::getPosition().x;
			int y = sf::Mouse::getPosition().y;
			if (x >= 800 && y >= 300)
			{
				sound1.play();

				rando = (rand() % 6) + 1;
				if (rando == 1)
				{
					if (!texture1.loadFromFile("dice 1.png"))
						cout << ":(";
					sprite.setTexture(texture1);
					sprite.setPosition(sf::Vector2f(700, 400));
					/*sf::Vector2f c= player.getPosition();
					if ( sf::Vector2f  > sf::Vector2f(x*add, y));*/
				}
				if (rando == 2)
				{
					if (!texture2.loadFromFile("dice 2.png"))
						cout << ":(";
					sprite.setTexture(texture2);
					sprite.setPosition(sf::Vector2f(700, 400));
				}
				if (rando == 3)
				{
					if (!texture3.loadFromFile("dice 3.png"))
						cout << ":(";
					sprite.setTexture(texture3);
					sprite.setPosition(sf::Vector2f(700, 400));
				}
				if (rando == 4)
				{
					if (!texture4.loadFromFile("dice 4.png"))
						cout << ":(";
					sprite.setTexture(texture4);
					sprite.setPosition(sf::Vector2f(700, 400));
				}
				if (rando == 5)
				{
					if (!texture5.loadFromFile("dice 5.png"))
						cout << ":(";
					sprite.setTexture(texture5);
					sprite.setPosition(sf::Vector2f(700, 400));
				}
				if (rando == 6)
				{
					if (!texture6.loadFromFile("dice 6.png"))
						cout << ":(";
					sprite.setTexture(texture6);
					sprite.setPosition(sf::Vector2f(700, 400));
				}
			}
			if (playersCounter == 1)
				newScore1 = rando + currentScore1, move1 = 1;
			if (playersCounter == 2)
				newScore2 = rando + currentScore2, move2 = 1;
			if (playersCounter == 3)
				newScore3 = rando + currentScore3, move3 = 1;
			if (playersCounter == 4)
				newScore4 = rando + currentScore4, move4 = 1;
		}
		//calling board , players and numbers
		window.clear();
		board();
		numbers();
		if (currentScore1 < 99 && currentScore2 < 99 && currentScore3 < 99 && currentScore4 < 99)
		{
			if (playersCounter == 1)
			{

				if (currentScore1 == newScore1)
				{
					if (move1)
					{
						movment();
						playersCounter = 2;
						move1 = 0;
					}
				}
				if (currentScore1 < newScore1 && direction1 == false)
				{
					if ((currentScore1 + 1) % 10 == 0)//current+1 bec.initialization of count=0
					{
						currentScore1 += 1;
						sprite2.setPosition(sf::Vector2f(sprite2.getPosition().x, sprite2.getPosition().y - 60));
						direction1 = true;
					}
					else if ((currentScore1 + 1) % 10 != 0)
					{
						currentScore1 += 1;

						sprite2.setPosition(sf::Vector2f(sprite2.getPosition().x + 60, sprite2.getPosition().y));
					}
				}
				else if (currentScore1 < newScore1 && direction1 == true)
				{
					if ((currentScore1 + 1) % 10 == 0)
					{
						currentScore1 += 1;

						sprite2.setPosition(sf::Vector2f(sprite2.getPosition().x, sprite2.getPosition().y - 60));
						direction1 = false;
					}
					else if ((currentScore1 + 1) % 10 != 0)
					{
						currentScore1 += 1;
						sprite2.setPosition(sf::Vector2f(sprite2.getPosition().x - 60, sprite2.getPosition().y));
					}
				}
			}
			else if (playersCounter == 2)
			{

				if (currentScore2 == newScore2)
				{
					if (move2)
					{
						movment();
						if (playersNum > 2)
							playersCounter++;
						else
							playersCounter = 1;
						move2 = 0;
					}
				}
				if (currentScore2 < newScore2 && direction2 == false)
				{
					if ((currentScore2 + 1) % 10 == 0)//current+1 bec.initialization of count=0
					{
						currentScore2 += 1;

						sprite3.setPosition(sf::Vector2f(sprite3.getPosition().x, sprite3.getPosition().y - 60));
						direction2 = true;
					}
					else if ((currentScore2 + 1) % 10 != 0)
					{
						currentScore2 += 1;

						sprite3.setPosition(sf::Vector2f(sprite3.getPosition().x + 60, sprite3.getPosition().y));
					}
				}
				else if (currentScore2 < newScore2 && direction2 == true)
				{
					if ((currentScore2 + 1) % 10 == 0)
					{
						currentScore2 += 1;

						sprite3.setPosition(sf::Vector2f(sprite3.getPosition().x, sprite3.getPosition().y - 60));
						direction2 = false;
					}
					else if ((currentScore2 + 1) % 10 != 0)
					{
						currentScore2 += 1;
						sprite3.setPosition(sf::Vector2f(sprite3.getPosition().x - 60, sprite3.getPosition().y));
					}


				}
			}

			else if (playersCounter == 3)
			{
				if (currentScore3 == newScore3)
				{
					if (move3)
					{
						movment();
						if (playersNum == 4)
							playersCounter++;
						else
							playersCounter = 1;
						move3 = 0;
					}
				}
				if (currentScore3 < newScore3 && direction3 == false)
				{
					if ((currentScore3 + 1) % 10 == 0)//current+1 bec.initialization of count=0
					{
						currentScore3 += 1;

						sprite4.setPosition(sf::Vector2f(sprite4.getPosition().x, sprite4.getPosition().y - 60));
						direction3 = true;
					}
					else if ((currentScore3 + 1) % 10 != 0)
					{
						currentScore3 += 1;
						sprite4.setPosition(sf::Vector2f(sprite4.getPosition().x + 60, sprite4.getPosition().y));
					}
				}
				else if (currentScore3 < newScore3 && direction3 == true)
				{
					if ((currentScore3 + 1) % 10 == 0)
					{
						currentScore3 += 1;

						sprite4.setPosition(sf::Vector2f(sprite4.getPosition().x, sprite4.getPosition().y - 60));
						direction3 = false;
					}
					else if ((currentScore3 + 1) % 10 != 0)
					{
						currentScore3 += 1;

						sprite4.setPosition(sf::Vector2f(sprite4.getPosition().x - 60, sprite4.getPosition().y));
					}

				}
			}


			else if (playersCounter == 4)
			{

				if (currentScore4 == newScore4)
				{
					if (move4)
					{
						movment();
						playersCounter = 1;
						move4 = 0;
					}
				}
				if (currentScore4 < newScore4 && direction4 == false)
				{
					if ((currentScore4 + 1) % 10 == 0)//current+1 bec.initialization of count=0
					{
						currentScore4 += 1;

						sprite5.setPosition(sf::Vector2f(sprite5.getPosition().x, sprite5.getPosition().y - 60));
						direction4 = true;
					}
					else if ((currentScore4 + 1) % 10 != 0)
						currentScore4 += 1; {


						sprite5.setPosition(sf::Vector2f(sprite5.getPosition().x + 60, sprite5.getPosition().y));
					}
				}
				else if (currentScore4 < newScore4 && direction4 == true)
				{
					if ((currentScore4 + 1) % 10 == 0)
					{
						currentScore4 += 1;
						sprite5.setPosition(sf::Vector2f(sprite5.getPosition().x, sprite5.getPosition().y - 60));
						direction4 = false;
					}
					else if ((currentScore4 + 1) % 10 != 0)
					{
						currentScore4 += 1;

						sprite5.setPosition(sf::Vector2f(sprite5.getPosition().x - 60, sprite5.getPosition().y));
					}

				}
			}
		}
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite);
		scoree(newScore1 + 1, newScore2 + 1, newScore3 + 1, newScore4 + 1);
		message(newScore1 + 1, newScore2 + 1, newScore3 + 1, newScore4 + 1);
		window.display();
	}
}