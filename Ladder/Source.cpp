#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Main.hpp"
#include <Windows.h>
#define SYMORDER 15
#define FATNESS 5
#define WIDTH 1920
#define HEIGHT 1080
void LadderPaint(sf::RenderWindow& Window, sf::RectangleShape Line, float StartX, float StartY, float EndX, float EndY, int OrderSym);

int main()
{
	sf::RenderWindow Window(sf::VideoMode(WIDTH, HEIGHT), "Ladder");
	Window.setActive(false);
	int SymOrder = 1;
	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				Window.close();
		}
		Window.clear(sf::Color::White);
		sf::RectangleShape Line;
		LadderPaint(Window, Line, 0,HEIGHT,WIDTH, 0, SymOrder);
		Window.draw(Line);
		Window.display();
		SymOrder %= (SYMORDER+1);
		SymOrder++;
		Sleep(200);
	}
}
void LadderPaint(sf::RenderWindow& Window,sf::RectangleShape Line, float StartX, float StartY,float EndX,float EndY ,int OrderSym)
{
	if (OrderSym == NULL)
		return;
	float CurrentSigment = EndX - StartX;
	float LenLine = CurrentSigment / 3;
	float PosY = (StartY-EndY) / 2;
	Line.setPosition(sf::Vector2f(CurrentSigment/3+StartX, PosY+EndY));
	Line.setSize(sf::Vector2f(LenLine, FATNESS));
	Line.setFillColor(sf::Color::Red);
	Window.draw(Line);
	LadderPaint(Window, Line, EndX - LenLine, PosY + EndY, EndX, EndY, OrderSym - 1);
	LadderPaint(Window, Line, StartX,StartY,LenLine+StartX,PosY+EndY,OrderSym-1);
}