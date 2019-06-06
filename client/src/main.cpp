#include <SFML/Window.hpp>

int main(int argc, char** argv)
{
	sf::Window window(sf::VideoMode(800, 600), "AjaxCatalystClient");

	while (window.isOpen())
	{
		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}

	return EXIT_SUCCESS;
}