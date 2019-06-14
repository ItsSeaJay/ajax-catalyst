#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

namespace AjaxCatalyst
{
	class Client
	{
	public:
		Client();
		~Client();
		
		void start();
		void update(const float& delta);
		void pollEvents();
		void draw();
		void stop();

		const bool& isRunning() const;

	private:
		sf::RenderWindow mWindow;
		sf::TcpSocket mSocket;
	};
}