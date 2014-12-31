#include <iostream>
using namespace std;

bool arraySame(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] == arr[++i]
	}
	//return true if the array contains all the same character,
	//false if the array contains a character that isn't the same

	return false;
}

bool array2Same(char arr[], int size)
{
	for (int i = 1; i < size; i + 2)
	{
		arr[i] == arr[2 + i]
	}
	//return true if the array contains the same character at all odd indices
	//return false otherwise

	return false;
}

bool array2IndexSame(char arr[][3], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i][1] == arr[i][2] && arr[i][1] == arr[i][3] && arr[i][2] == arr[i][3]
	}
	//input is an array like arr[column][row] where each row is 3 in size
	//Return true if all the elements in the array are the same
	//return false otherwise

	return false;
}

bool array2IndexAnyColumn(char arr[][3], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i][1] == arr[i][2] || arr[i][1] == arr[i][3] || arr[i][2] == arr[i][3]
	}
	//input is an array like arr[column][row] where each row is 3 in size
	//Return true if ANY column is filled with the same character
	//return false otherwise

	return false;
}

int main(void)

{
	//These are were your tests for the functions should go
	//Some tests are provided, but are not comprehensive
	//Feel free to add your own


	char arr[6] = { '1', '5', '1', '1', '1', '1' };
	cout << "Printing arraySame";
	cout << "This should be 0, it is actually " << arraySame(arr, 6) << endl;
	arr[1] = '1';
	cout << "This should be 1, it is actually " << arraySame(arr, 6) << endl;

	char arr2[6] = { '2', '1', '2', '1', '2', '2' };
	cout << "Printing array2Same" << endl;
	cout << "This should be 0, it is actually " << array2Same(arr2, 6) << endl;
	arr2[5] = '1';
	cout << "This should be 1, it is actually " << array2Same(arr2, 6) << endl;


	char arr3[3][3] = { { '1', '1', '1' }, { '1', '1', '2' }, { '1', '1', '1' } };
	cout << "Printing array2IndexSame" << endl;
	cout << "This should be 0, it is actually " << array2IndexSame(arr3, 3) << endl;
	arr3[1][2] = '1';
	cout << "This should be 1, it is actually " << array2IndexSame(arr3, 3) << endl;

	char arr4[3][3] = { { '1', '2', '3' }, { '4', '4', '3' }, { '1', '2', '5' } };
	cout << "Printing array2IndexAnyColumn" << endl;
	cout << "This should be 0, it is actually " << array2IndexAnyColumn(arr4, 3) << endl;
	arr4[1][2] = '4';
	cout << "This should be 1, it is actually " << array2IndexAnyColumn(arr4, 3) << endl;
}