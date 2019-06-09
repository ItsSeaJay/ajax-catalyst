#include <iostream>

int main(int argc, char** argv)
{
	// Use the second command line argument for the port number
	// If no such argument exists, use the default
	unsigned const short port = (argc > 1) ? atoi(argv[1]) : 6567;

	std::cout << port;

	return EXIT_SUCCESS;
}