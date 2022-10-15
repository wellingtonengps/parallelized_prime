#include <iostream>
#include "Parallelized.h"
#include <chrono>
using namespace std;

int main() {



    Parallelized* parallelized = new Parallelized();
    parallelized->Thread();



    delete parallelized;

    return 0;
}
