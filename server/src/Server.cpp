#include <AjaxCatalyst/Server/Server.h>

AjaxCatalyst::Server::Server(const unsigned short& port)
	: mPort(port)
{}

AjaxCatalyst::Server::~Server() {}

void AjaxCatalyst::Server::start()
{
	mWindow.create(sf::VideoMode(800, 600), "AjaxCatalystServer");
	mListener.listen(mPort);
	mSocketSelector.add(mListener);
}

void AjaxCatalyst::Server::update(const float& delta)
{
	if (mSocketSelector.wait())
	{
		if (mSocketSelector.isReady(mListener))
		{
			// There is an incoming connection
			sf::TcpSocket* client = new sf::TcpSocket();

			if (mListener.accept(*client) == sf::Socket::Done)
			{
				mClients.push_back(client);
				mSocketSelector.add(*client);
			}
			else
			{
				// There's been an error
				delete client;
			}
		}
		else
		{
			// The listener socket is not ready, test all the other sockets
			for (std::list<sf::TcpSocket*>::iterator iterator = mClients.begin();
				iterator != mClients.end();
				++iterator)
			{
				// Dereference the pointer to the client
				sf::TcpSocket& client = **iterator;

				if (mSocketSelector.isReady(client))
				{
					// The client has sent the server some data
					sf::Packet packet;
				}
			}
		}
	}
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
	mSocketSelector.clear();
	mListener.close();
}

const bool & AjaxCatalyst::Server::isRunning() const
{
	return mWindow.isOpen();
}

void AjaxCatalyst::Server::clientConnected()
{

}

void AjaxCatalyst::Server::clientDisconnected()
{

}
