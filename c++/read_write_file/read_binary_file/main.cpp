#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include "read_file.hpp"

using namespace std;

void read_entire_file(const char *filePath) {
    readFile file(filePath);
    int ret;

    ret = file.OpenFile();
    cout << "File Open status " << ret << endl;
    file.GetFileSize();
    cout << "File Size " << file.mFileSize << endl;
    char *memblock = new char [file.mFileSize]; // Allocating memory to sotre all file content
    file.GetFileContent(memblock);
    cout << "Getting File content..." << endl;

    for ( int i = 0; i < file.mFileSize; i++) {
        cout << "Char: " << (memblock[i]) << endl;
    }

    delete memblock;
    ret = file.CloseFile();
    cout << "File Closed  status " << ret << endl;
}

void read_file_slices(const char *filePath) {
    readFile file(filePath);
    int ret;
    int sliceSize = 2048;
    long int readSize;
    long int readSizeCnt = 0;

    ret = file.OpenFile();
    cout << "File Open status " << ret << endl;
    file.GetFileSize();
    cout << "File Size " << file.mFileSize << endl;
    char *memblock = new char [sliceSize]; // Allocating memory to sotre all file content
    cout << "Getting File content..." << endl;

    int i = 0;
    do {
        file.GetFileSlicedContent(memblock, &readSize, sliceSize);
        readSizeCnt += readSize;
        file.HexDump(memblock, readSize);
        i++;
    } while (readSize == sliceSize);
    cout << "Total Size: " << std::dec << readSizeCnt << endl;
    cout << "N Slices " << std::dec << i << endl << endl;

    delete memblock;
    ret = file.CloseFile();
    cout << "File Closed  status " << ret << endl;
}

int main()
{
    // read_entire_file("afile.dat");
    read_file_slices("Flex_Y_Perseus_7.2.121.bin");
    return 0;

}
