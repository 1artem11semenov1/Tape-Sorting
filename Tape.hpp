#pragma once
#include "TapeInter.hpp"
#include <fstream>
#include <string>
#include <filesystem>

class Tape: public TapeInter{
public:
    Tape(const std::string& filename, std::ios::openmode mode = std::ios::in | std::ios::out) {
        this->filename = filename;
        if (!std::filesystem::exists(filename)) {
            std::ofstream createFile(filename);  // Создаем файл, если его нет
            createFile<<"";
            createFile.close();
        }
        tapeFile.open(filename, mode);
    }

    void shiftForward(){
        int ch;
        while((ch = tapeFile.get())!=static_cast<int>(' ') && ch!=EOF && !(ch<=static_cast<int>('9') && ch>=static_cast<int>('0'))){
            continue;
        }
        if (ch!=static_cast<int>(' ')){
            tapeFile.seekp(-1,std::ios::cur);
            tapeFile.seekg(-1,std::ios::cur);
            ch = tapeFile.get();
        }
    }
    void shiftBack(){
        int ch;
        while((ch = tapeFile.get())!=static_cast<int>(' ') && tapeFile.tellg()!=0){
            tapeFile.read((char*)&ch,sizeof(int));
            tapeFile.seekp(-2,std::ios::cur);
            tapeFile.seekp(-2,std::ios::cur);
        }
    }
    
    int get(){
        std::string buf = "";
        tapeFile >> buf;

        return stoi(buf);
    }
    void write(int val){
        tapeFile << std::to_string(val) << ' ';
        tapeFile.flush();
    }

    void gotoStart(){
        tapeFile.close();
        tapeFile.open(filename, std::ios::in | std::ios::out);
    }

    bool isEnd() {
        int ch;
        while ((ch = tapeFile.peek()) == ' ') ch = tapeFile.get();
        return (tapeFile.peek() == EOF);
    }

    void fill(){
        while (!(this->isEnd())){
            tapeFile<<" ";
        }
    }
};