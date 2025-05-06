#pragma once
#include <fstream>

class TapeInter{
protected:
    std::fstream tapeFile;
    std::string filename;
public:
    virtual void shiftForward() = 0;
    virtual void shiftBack() = 0;
    virtual int get() = 0;
    virtual void write(int) = 0;
    virtual void gotoStart() = 0;
    virtual void fill() = 0;
    virtual bool isEnd() = 0;
};