#pragma once

#include <list>
#include <mutex>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

namespace AjaxCatalyst
{
	class Server
	{
	public:
		Server(const unsigned short& port);
		~Server();

		void start();
		void update(const float& delta);
		void pollEvents();
		void draw();
		void stop();

		const bool& isRunning() const;

	private:
		sf::RenderWindow mWindow;
		sf::TcpListener mListener;
		sf::SocketSelector mSocketSelector;

		std::list<sf::TcpSocket*> mClients;
		std::mutex mMutex;

		const unsigned short mPort;

		void clientConnected();
		void clientDisconnected();

	};
}