#include <SFML/Window.hpp>
#include <AjaxCatalyst/Client/Client.h>

int main(int argc, char** argv)
{
	AjaxCatalyst::Client* client = new AjaxCatalyst::Client();
	sf::Clock clock;
	sf::Time lag = sf::Time::Zero;
	const sf::Time frameLimit = sf::seconds(1.0f / 60.0f); // 60 frames-per-second

	return EXIT_SUCCESS;
}