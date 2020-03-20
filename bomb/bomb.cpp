#include <SFML/Graphics.hpp>
#include <iostream>
#include<math.h>
#include <iomanip>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
int main(void)
{
	float X = rand() % 600 + 300;
	Sound bumb1;
	SoundBuffer bumb;
	if (bumb.loadFromFile("Data/Bomb.wav") == 0)
	{
		return 0;
	}
	bumb1.setBuffer(bumb);
	RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	window.setFramerateLimit(60);
	bool play = true;
	Texture background, madf3, tal2a, AIM;
	if (background.loadFromFile("Data/background.pnG") == false)
	{
		return 1;
	}
	if (tal2a.loadFromFile("Data/eltl2a.jpg") == false)
	{
		return 1;
	}
	if (madf3.loadFromFile("Data/madf3.png") == false)
	{
		return 1;
	}
	if (AIM.loadFromFile("Data/AIM.JPG") == false)
	{
		return 1;
	}
	Event event;
	bool up = false, down = false, edrb = false;
	RectangleShape aim;
	aim.setSize(Vector2f(50, 50));
	aim.setPosition(X, 470);
	aim.setTexture(&AIM);
	RectangleShape BACKGROUND;
	BACKGROUND.setSize(Vector2f(800, 600));
	BACKGROUND.setPosition(0, 0);
	BACKGROUND.setTexture(&background);
	RectangleShape TAL2A;
	TAL2A.setSize(Vector2f(19, 18));
	TAL2A.setPosition(45, 500);
	TAL2A.setTexture(&tal2a);
	RectangleShape MADF3;
	MADF3.setSize(Vector2f(100, 30));
	MADF3.setPosition(0, 490);
	MADF3.setTexture(&madf3);
	float Xpos = 45, ypos = 500, v0 = 87.485998888, x, j = 0, k = 0;
	//
	Clock clock;
	Time t1;
	int i = 0;
	bool estdam = false;
	while (play)
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				play = false;
			}
			if (edrb == false)
			{

				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
				{
					up = true;
				}
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
				{
					up = false;
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
				{
					down = true;

				}
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
				{
					down = false;
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
				{
					edrb = true;
				}
			}
		}
		if (estdam == false)
		{
			if (up == true && (MADF3.getRotation() > 270 || MADF3.getRotation() == 0))
			{
				MADF3.rotate(-0.5);
				if (MADF3.getRotation() == 0)
					cout << 0;
				else
					cout << -(MADF3.getRotation() - 360) << " ";
				cout << fixed << setprecision(4) << cos(-((MADF3.getRotation() - 360) / 180) * (3.141592653589793)) << Xpos << " " << ypos << endl;
			}
			if (down == true && MADF3.getRotation() >= 270)
			{
				MADF3.rotate(0.5);
				if (MADF3.getRotation() == 0)
					cout << 0;
				else
					cout << -(MADF3.getRotation() - 360) << " ";
				cout << fixed << setprecision(4) << cos(-((MADF3.getRotation() - 360) / 180) * (3.141592653589793)) << Xpos << " " << ypos << endl;
			}
			if (edrb == true)
			{
				if (i == 0) {
					clock.restart();
					bumb1.play();
				}
				i++;
				t1 = clock.getElapsedTime();
				Xpos = (v0 * t1.asSeconds() * cos(-((MADF3.getRotation() - 360) / 180) * (3.141592653589793)));
				ypos = 500 - (v0 * t1.asSeconds() * sin(-((MADF3.getRotation() - 360) / 180) * (3.141592653589793)) - ((4.9) * t1.asSeconds() * t1.asSeconds()));

			}
		}
		if (TAL2A.getPosition().x > 781)
		{
			Xpos = 781;
			estdam = true;
		}
		if (TAL2A.getPosition().y > 500)
		{
			x = TAL2A.getPosition().x;
			ypos = 500;
			Xpos = x;
			estdam = true;
		}
		if (estdam == true && TAL2A.getPosition().y < 500)
		{
			if (k == 0)
				clock.restart();
			k++;
			t1 = clock.getElapsedTime();
			ypos = ypos + (4.9 * t1.asSeconds() * t1.asSeconds());
		}
		TAL2A.setPosition(Xpos, ypos);
		window.clear();
		window.draw(BACKGROUND);
		if (edrb == true)
		{
			window.draw(TAL2A);
		}
		window.draw(MADF3);
		window.draw(aim);
		window.display();
	}
}