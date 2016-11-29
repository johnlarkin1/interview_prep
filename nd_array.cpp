#include <iostream>

using namespace std;

#define X 5
#define Y 3
#define Z 2
int array3D[X][Y][Z];

void printNDArray(int *arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout << *(arr+i) << endl;
	}
}

int main()
{
	//Generate Multidimensional Array Going From 1 to MAX
	int val=1;
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			for(int k=0;k<Z;k++)
			{
				array3D[i][j][k] = val;
				val++;
			}
		}
	}
	
	//Pass pointer to first value in array and the size.
	int size = X*Y*Z;
	printNDArray(&array3D[0][0][0], size);
}
