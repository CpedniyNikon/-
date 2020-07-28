#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

void print(vector<vector<string>> map_)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << map_[i][j] << " ";
		}
		cout << endl;
	}
}

void swap(string& string1, string& string2)
{
	string result = string1;
	string1 = string2;
	string2 = result;
}

bool is_win(vector<vector<string>>map_)
{
	vector<vector<string>> map(4);
	map[0] = { " 1", " 2", " 3", " 4", };
	map[1] = { " 5", " 6", " 7", " 8" };
	map[2] = { " 9", "10", "11", "12" };
	map[3] = { "13", "14", "15", "  " };
	if (map_ == map)
		return true;
	else return false;
}

int main()
{
	int y_position;
	int x_position;

	vector<vector<string>>map_(4, vector<string>(4));
	vector<string>source = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "14","15", "  " };
	random_shuffle(source.begin(), source.end());
	map_[0] = { source[0], source[1], source[2], source[3] };
	map_[1] = { source[4], source[5], source[6], source[7] };
	map_[2] = { source[8], source[9], source[10], source[11] };
	map_[3] = { source[12], source[13], source[14], source[15] };

	print(map_);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map_[i][j] == "  ") {
				y_position = i;
				x_position = j;
				break;
			}
		}
	}

	while (true)
	{
		switch (_getch())
		{
		case 's': {
			if (y_position > 0)
			{
				swap(map_[y_position][x_position], map_[y_position - 1][x_position]);
				y_position--;
				system("cls");
				print(map_);

			}
			break;
		}

		case 'w': {
			if (y_position < 3)
			{
				swap(map_[y_position][x_position], map_[y_position + 1][x_position]);
				y_position++;
				system("cls");
				print(map_);
			}
			break;
		}

		case 'd': {
			if (x_position > 0)
			{
				swap(map_[y_position][x_position], map_[y_position][x_position - 1]);
				x_position--;
				system("cls");
				print(map_);
			}
			break;
		}

		case 'a': {
			if (x_position < 3)
			{
				swap(map_[y_position][x_position], map_[y_position][x_position + 1]);
				x_position++;
				system("cls");
				print(map_);
			}
			break;
		}
		}
		if (is_win(map_))
		{
			system("cls");
			cout << "YOU WON!!!" << endl;
			break;

		}

	}
	if (_getch() == ' ')
	{
	system("cls");
	main();
	}
	return 0;
}