//mainfile.cpp

// Include all libraries
#include <sstream>
#include <fstream>
#include <iostream>

// Start main
int main ()
{
	// Declare int, string, stringstream and boolean variables
	int num;
	int times = 0;
	int sum = 0;	
	bool isInteger = true;
	std::ifstream inFile;
	std::ofstream outFile;
	std::string currentLine;
	std::string token;
	std::string token1;
	std::stringstream text;
	std::stringstream converter;
	std::stringstream line;

	inFile.open("input.txt"); // Open input file
	if (inFile.is_open())
	{
		while (getline(inFile, currentLine))
		{
			if (isInteger)
			{
				line.clear();
				line.str("");
				line.str(currentLine); // Assign string to stringstream
				converter.clear();
				converter.str("");
				while(getline(line, token, ',')) // Get integer string from stringstream and pass to string
				{
					converter.str(token); // Pass the token to stringstream
					converter >> num; // Pass the token to int num to convert it to integers
					sum += num; // Sum the integers 
					isInteger = false; // Set the isInteger to false
				}
			}
			else
			{
				text.clear();
				text.str("");
				if (currentLine == "") // If currentLine is empty, print the text below
				{
					text << "This line is invisible, only the smartest one can see it, no string is found here!";	
				}
				else // If currentLine is not empty
				{
					if (sum == 0) // If the sum is zero
					{
						text << "You could've had as many food as you like, but you picked 0!";
					}
					else // If the sum is not zero
					{
						for (int i=0; i < sum - 1; i++)
						{
							text << currentLine << ","; 
						}
						text << currentLine;
					}
				}
				sum = 0; // Reset value of sum
				isInteger = true;
				if (times == 0)
				{
					outFile.open ("output.txt");
					times ++; // Incrementing the number of times opening the output file after first open
				}
				else
				{
					outFile.open ("output.txt", std::ios::app);
				}	

				if (outFile.is_open())
				{
					outFile << text.str() << std::endl; // Pass the string to output file
				}
				else
 				{
					std::cout << "Unable to open output file" << std::endl;
				}

				outFile.close(); // Close output file
			}
		}
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
	
	inFile.close(); // Close input file

	return 0;
} // End main
