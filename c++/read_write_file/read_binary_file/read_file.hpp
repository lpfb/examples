#include <fstream>
#include <iostream>

using namespace std;

class readFile {
    streampos fileSize;
    ifstream mFile;
    const char *filePath;
  public:
    int mFileSize;
    readFile(const char *file);
    int OpenFile();
    int GetFileSize();
    int CloseFile();
    int GetFileContent(char *memBlock);
    int GetFileSlicedContent(char *memBlock, long int *readSliceSize, int maxSliceSize);
    void HexDump(char *memBlock, long int memBlockSize);
};

