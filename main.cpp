#include <iostream>
#include "function.h"
#define NUM 10
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!!!" << endl;
    int data[NUM] = {10, 58, 63, 21, 17, 36, 93, 72, 20, 11};
    qsort(data, NUM, sizeof(int), ascending);
    output(data, NUM);
    qsort(data, NUM, sizeof(int), descending);
    output(data, NUM);

    return 0;
}