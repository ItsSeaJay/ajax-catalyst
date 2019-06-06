#include <SFML/Window.hpp>
#include <AjaxCatalyst/Client/Client.h>

int main(int argc, char** argv)
{
	AjaxCatalyst::Client* client = new AjaxCatalyst::Client();
	sf::Clock clock;
	sf::Time lag = sf::Time::Zero;
	const sf::Time frameLimit = sf::seconds(1.0f / 60.0f); // 60 frames-per-second

	client->start();

	while (client->isRunning())
	{
		// Get how much time has elapsed since the game started
		sf::Time elapsedTime = clock.restart();

		// Accumilate lag depending on how long the frame took to render
		lag += elapsedTime;

		// Perform gameplay functions until there is no lag remaining
		while (lag > frameLimit)
		{
			lag -= frameLimit;

			client->update(frameLimit.asSeconds());
			client->pollEvents();
		}

		client->draw();
	}

	client->stop();

	// Deallocate the memory for the client
	delete client;
	client = nullptr;

	return EXIT_SUCCESS;
}