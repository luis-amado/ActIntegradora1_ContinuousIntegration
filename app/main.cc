#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "parte1_1.h"
#include "parte1_2.h"
#include "parte2.h"
#include "parte3.h"

using namespace std;

int main()
{
    cout << "Parte 1:" << endl;
    part1_1("transmission1.txt", "mcode1.txt");
    part1_1("transmission1.txt", "mcode2.txt");
    part1_1("transmission1.txt", "mcode3.txt");
    part1_2("transmission2.txt", "mcode1.txt");
    part1_2("transmission2.txt", "mcode2.txt");
    part1_2("transmission2.txt", "mcode3.txt");

    cout << endl;
    cout << "Parte 2:" << endl;
    manacher("transmission1.txt");
    manacher("transmission2.txt");

    cout << "Parte 3:" << endl;
    part3("transmission1.txt", "transmission2.txt");
}
