#include "ItemList.h"
#include <iostream>
#include <fstream>
#include <string>

ItemList::ItemList()
{
	/*std::string line;
	std::ifstream fileReader("itemList.txt");
	if (fileReader.is_open())
	{
		while (getline(fileReader, line))
		{
			std::cout << line << '\n';
		}
		fileReader.close();
	}*/

	char l0[] = "N|Longsword|3|3";
	Sword longsword(l0);
	char l1[] = "F|2H  |1   |10 |0     |3  |8   |2  |1  |0    |1    |1      |1     |-4     |0      |A+80 |99";
	char l2[] = "F|1H  |1   |6  |0     |4  |12  |4  |-5 |-2   |-2   |-2     |0     |-7     |-4     |A+105|99";
	longsword.addForm(l1);
	longsword.addForm(l2);
	char l3[] = "D|Sword two hands woah.";
	longsword.setDescription(l3);
	char *token;
	int i;
	int p;
	
	token = strtok(l0, "|");
	i = 0;
	p = 0;
	while (token != NULL)
	{
		if (i == 1)

		i++;
	}

	p = 1;
	token = strtok(l1, "|");


	token = strtok(l2, "|");

	p = 2;
	token = strtok(l3, "|");
}
