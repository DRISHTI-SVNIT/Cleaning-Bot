
#ifndef movingArray
#define movingArray

#define maxN 4
#define maxArraySize 10

int size[maxN];
float movArray[maxArraySize][maxN];
int (index[maxN]);
float total[maxN];

void init_movingArray(int arraySize, int n);
void addElement(float element, int n,int v);
float getTotal(int n,int v);
float getAverage(int n,int v);
float getElement(int x, int n,int v);


#endif