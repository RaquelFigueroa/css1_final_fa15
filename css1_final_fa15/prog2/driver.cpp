// Name: Raquel Figueora
// Date: 17 December 2015
// 

#include <iostream>//cin, cout
#include <fstream>//ifstream, ofstream
#include <cstdlib>//exit()

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);

int main()
{
	string elf[R][C] = {};
	int zCount = 0;//counter for zombies

	ifstream fin;
	fin.open("northpole.txt");
	if(fin.fail())
	{
		cout << "northpole.txt failed to open.\n";
		exit(1);
	}

	ofstream fout;
	fout.open("status.txt");
	if (fout.fail())
	{
		cout << "status.txt failed to open.\n";
		exit(1);
	}
	
	fillArray(fin, elf);//fills array with northpole txt data

	fout << "Name: Raquel Figueroa\n";

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			zCount = 0;//restart zombie counter

			if (elf[i][j] == "@")
			{
				if ((j != 0) && (elf[i][j-1] == "!"))
				{
					zCount++;
				}//accounts for first column

				if ((j != C-1) && (elf[i][j+1] == "!"))
				{
					zCount++;
				}//accounts for last column

				if ((i != 0) && (elf[i-1][j] == "!"))
				{
					zCount++;
				}//accounts for first row

				if ((i != R-1) && (elf[i+1][j] == "!"))
				{
					zCount++;
				}//accounts for last row
			}//end elf checker if

			if (zCount == 3)
				{
					fout << "elf[" << i << "][" << j << "]: " << "Run!\n";
				}
			else if (zCount == 4)
				{
					fout << "elf[" << i << "][" << j << "]: " << "Munch!\n";
				}
		}//end inner for loop
	}//end outer for loop
	
	fin.close();
	fout.close();
	return 0;
}//end int main()

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string val;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A_in >> S[i][j];
		}
	}
	return;
}//end fillArray




 
