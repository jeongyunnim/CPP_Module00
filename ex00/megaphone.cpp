#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string	sentence;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		sentence += argv[i];
	}
	for (std::string::iterator it = sentence.begin(); it != sentence.end(); it++)
	{
		std::cout << static_cast<char>(std::toupper(*it));
	}
	std::cout << std::endl;
	return 0;
}