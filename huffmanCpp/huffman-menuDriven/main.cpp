#include "include/compress.h"
#include "include/decompress.hpp"

using namespace std;

int main(){
    compress("text.txt","try.txt");
    decompress("text.txt","try.txt");
    return 0;
}