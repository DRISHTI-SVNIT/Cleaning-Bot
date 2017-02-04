#include "movingArray.h"

void init_movingArray(int arraySize, int n) 
{
	int i;
	for(i = 0;i<arraySize;i++){
		movArray[i][n] = 0;
		movArray[i][n+2]=0;
	}
	size[n] = arraySize;
	size[n+2] = arraySize;

	index[n] = 0;
	index[n+2] = 0;

	total[n]=0;
	total[n+2]=0;
}

void addElement(float element, int n,int v)
 {
	total[n+v] -= movArray[index[n+v]][n+v];

	movArray[index[n+v]][n+v] = element;
	total[n+v] += element;
	index[n+v]++;
	if(index[n+v] == size[n+v]) {
		index[n+v] = 0;
	}
}
float getTotal(int n,int v) {
	return total[n+v];
}

float getAverage(int n,int v) {
	return  total[n+v] / size[n+v];
}

// returns f(t - x) th element
float getElement(int x, int n,int v) {
	return movArray[index[n+v] - x][n+v];
}
