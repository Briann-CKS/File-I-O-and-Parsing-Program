//main.cpp

// Include the libraries
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

// Start main
int main ()
{
	// Declare int variables and boolean variable
	int num;
	int times =0;
	int sum = 0;
	bool isInteger = true;
	//Declare string and stringstream variable
	std::string currentLine;
	std::string token;
	std::string token1;
	std::stringstream text; 
	std::stringstream converter;
	std::stringstream line;
	//Declare input and output file stream
	std::ifstream inFile;
	std::ofstream outFile;
	
	// Open input file
	inFile.open ("input.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, currentLine))
		{
			if (isInteger)
			{
				line.clear();
				line.str("");
				line.str(currentLine);
				converter.clear();
				converter.str("");
				while (getline(line, token, ','))
				{
					converter.str(token);
					converter >> num; 
					sum += num;
					isInteger = false;
				}
			}
			else
			{
				text.clear();
				text.str("");
				for (int i=0; i<sum-1; i++)
				{
					text << currentLine << ",";
				}
				text << currentLine;
				sum = 0;
				isInteger = true;
				if (times == 0)
				{
					outFile.open("output.txt");
					times ++;
				}
				else
				{
					outFile.open("output.txt", std::ios::app);
				}

				if (outFile.is_open())
				{
					outFile << text.str() << std::endl;
				}
				else
				{
					std::cout << "Unable to open output file" << std::endl;
				}
				outFile.close();
			}
		}
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;	
	}
	
	inFile.close();

	return 0;
}
			
			 	
