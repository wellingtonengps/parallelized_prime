
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include "PrimeGenerator.h"

using namespace std;

int PrimeGenerator::Generator(int a, int b)
{


    bool isPrime;

    list<int> primes;

    for(int i = a; i <= b; i++)
    {
        if((i == 1) || (i == 0))
        {
            continue;
        }

        isPrime = true;

        for(int j = 2; j <= (i / 2); ++j)
        {
            if((i % j) == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
        {
            primes.push_back(i);
        }
    }

    ofstream outputFile("primes.txt");

    if(outputFile.is_open())
    {
        list<int>::iterator it;

        for (it = primes.begin(); it != primes.end(); ++it)
        {
            outputFile << *it << " ";
        }

        outputFile.close();
    }
    else
    {
        cout << "Erro ao gravar o arquivo final" << endl;
    }

    return 0;
}