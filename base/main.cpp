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
		// get string line by line from the input file
		while (getline(inFile, currentLine))
		{
			//If loop to deal with integers and strings in the file
			if (isInteger)
			{
				line.clear();
				line.str("");
				line.str(currentLine); // Assign the string to stringstream 
				while (getline(line, token, ',')) // Pass integer by integer to string
				{
					converter.clear();
					converter.str("");
					converter.str(token); // Assign the integer string to stringstream
					converter >> num; // Pass the integer from string to an int variable
					sum += num; // Sum the integers
				}
					isInteger = false; // Set isInteger to false to deal with strings later
				
			}
			else 
			{
				text.clear();
				text.str("");
				for (int i=0; i<sum-1; i++) // For loop to insert the correct number of string
				{
					// Assign string to stringstream and append comma
					text << currentLine << ",";
				}
				text << currentLine; 
				sum = 0; // Reset value of sum
				isInteger = true; // Reset isInteger before going to next line
				if (times == 0) // When calling for the first time, a new output file is opened
				{
					outFile.open("output.txt");
					times ++;
				}
				else // After opening the file once, use append mode
				{
					outFile.open("output.txt", std::ios::app);
				}

				if (outFile.is_open())
				{
					// Pass the string to the output file
					outFile << text.str() << std::endl;
				}
				else
				{
					std::cout << "Unable to open output file" << std::endl;
				}
				outFile.close(); // Close the output file
			}
		} // End while loop
	} // End if loop
	else
	{
		std::cout << "Unable to open file" << std::endl;	
	}
	
	inFile.close(); // Close input file

	return 0;
} // End main
			
			 	
