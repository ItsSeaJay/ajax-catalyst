#include <AjaxCatalyst/Server/Server.h>

AjaxCatalyst::Server::Server() {}

AjaxCatalyst::Server::~Server() {}

void AjaxCatalyst::Server::start()
{
	mWindow.create(sf::VideoMode(800, 600), "AjaxCatalystServer");
}

void AjaxCatalyst::Server::update(const float& delta)
{

}

void AjaxCatalyst::Server::pollEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
}

void AjaxCatalyst::Server::draw()
{
	mWindow.clear();
	mWindow.display();
}

void AjaxCatalyst::Server::stop()
{
	
}

const bool & AjaxCatalyst::Server::isRunning() const
{
	return mWindow.isOpen();
}
