#include <iostream>
#include <AjaxCatalyst/Server/Server.h>

int main(int argc, char** argv)
{
	// Use the second command line argument for the port number
	// If no such argument exists, use the default
	unsigned const short port = (argc > 1) ? atoi(argv[1]) : 6567;
	AjaxCatalyst::Server* server = new AjaxCatalyst::Server(port);
	sf::Clock clock;
	sf::Time lag;
	const sf::Time frameLimit = sf::seconds(1.0f / 60.0f); // 60 frames-per-second

	server->start();

	while (server->isRunning())
	{
		// Get how much time has elapsed since the server started
		sf::Time elapsedTime = clock.restart();

		// Accumilate lag depending on how long the frame took to render
		lag += elapsedTime;

		// Perform gameplay functions until there is no lag remaining
		while (lag > frameLimit)
		{
			lag -= frameLimit;

			server->update(frameLimit.asSeconds());
			server->pollEvents();
		}

		server->draw();
	}

	server->stop();

	// Decallocate the memory for the server
	delete server;
	server = nullptr;

	return EXIT_SUCCESS;
}