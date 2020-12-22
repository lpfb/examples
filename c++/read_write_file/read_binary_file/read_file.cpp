#include <fstream>
#include "read_file.hpp"
#include <iomanip>

readFile::readFile(const char *file) {
    filePath = file;
}

int readFile::OpenFile() {
    cout << "Opening File " << filePath << endl;
    mFile.open(filePath, ios::in | ios::binary);
    if (mFile.is_open()) {
        return 0;
    }

    return -1;
}

int readFile::GetFileSize() {
    if (mFile.is_open()) {
        mFile.seekg(0, std::ios::end);
        mFileSize = mFile.tellg();
        cout << "Size " << mFileSize << endl;
        mFile.seekg(0, std::ios::beg);
        return 0;
    }
    return -1;
}

int readFile::CloseFile() {
    if (mFile.is_open()) {
        mFile.close();
        return 0;
    }
    return -1;
}

int readFile::GetFileContent(char *memBlock) {
    if (mFile.is_open()) {
        mFile.read(memBlock, mFileSize);
        return 0;
    }
    return -1;
}

int readFile::GetFileSlicedContent(char *memBlock, long int *readSliceSize, int maxSliceSize) {
    if (mFile.is_open()) {
        mFile.read(memBlock, maxSliceSize);
        *readSliceSize = mFile.gcount();
        return 0;
    }
    return -1;
}

void readFile::HexDump(char *memBlock, long int memBlockSize) {
    for ( long int j = 1; j < memBlockSize+1; j++) {
        if ((j-1) % 16 == 0 || j == 1) {
            cout << endl;
        }
        cout << std::setfill('0')  << std::setw(2) << std::hex << (int)(unsigned char)(memBlock[j-1]);
        if (j % 2 == 0) {
            cout << " ";
        }
    }

    cout << endl;
    cout << "=======================================" << endl;
    cout << " Memory block size : " << std::dec << memBlockSize << endl;
    cout << "=======================================" << endl;
}
