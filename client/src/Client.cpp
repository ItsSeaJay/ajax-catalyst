#include <AjaxCatalyst/Client/Client.h>

AjaxCatalyst::Client::Client()
{}

AjaxCatalyst::Client::~Client()
{}

void AjaxCatalyst::Client::start()
{
	mWindow.create(sf::VideoMode(800, 600), "AjaxCatalystClient");
}

void AjaxCatalyst::Client::update(const float& delta)
{

}

void AjaxCatalyst::Client::pollEvents()
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

void AjaxCatalyst::Client::draw()
{
	mWindow.clear();
	mWindow.display();
}

void AjaxCatalyst::Client::stop()
{

}

const bool& AjaxCatalyst::Client::isRunning() const
{
	return mWindow.isOpen();
}