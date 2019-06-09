#pragma once

namespace AjaxCatalyst
{
	class Server
	{
	public:
		Server();
		~Server();

		void start();
		void update(const float& delta);
		void pollEvents();
		void draw();
		void stop();

	private:

	};
}