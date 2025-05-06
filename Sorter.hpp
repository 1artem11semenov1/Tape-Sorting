#pragma once
#include "Tape.hpp"

class Sorter{
    Tape* inpTape;
    Tape* outTape;
    int N;
public:
    Sorter(Tape* i, Tape* o, int N){
        inpTape = i;
        outTape = o;
        this->N = N;
    }

    void natMergeSort(){
        Tape* tmp1 = new Tape("tmp/tmp1.txt");
        Tape* tmp2 = new Tape("tmp/tmp2.txt");
        bool isSorted = false;

        while (!isSorted){
           inpTape->gotoStart();
            tmp1->gotoStart();
            tmp2->gotoStart();

            Tape* cur = tmp1;
            int curVal = inpTape->get();
            for (int i = 0; i < N-1; ++i) {
                int geted = inpTape->get();
                if (geted >= curVal) {
                    cur->write(curVal);
                } else {
                    cur->write(curVal);
                    cur = (cur==tmp1)? tmp2 : tmp1;   
                }
                curVal = geted;
            }
            cur->write(curVal);
            tmp1->fill();
            tmp2->fill();

            inpTape->gotoStart();
            tmp1->gotoStart();
            tmp2->gotoStart();
            isSorted = true;
            
            bool istmp1End = false;
            bool istmp2End = false;
            if (!(tmp1->isEnd())) {curVal = tmp1->get();}
            else {istmp1End = true;}
            int curVal2 = 0;
            if (!(tmp2->isEnd())) {curVal2 = tmp2->get();}
            else {istmp2End = true;}
            for (int i = 0; i < N-1; ++i) {
                if (istmp1End || istmp2End) break;
                if (curVal<=curVal2){
                    inpTape->write(curVal);
                    if (!(tmp1->isEnd())) {curVal = tmp1->get();}
                    else {istmp1End = true;}
                } else{
                    isSorted = false;
                    inpTape->write(curVal2);
                    if (!(tmp2->isEnd())) {curVal2 = tmp2->get();}
                    else {istmp2End = true;}
                }
            }
            if (istmp1End){cur = tmp2;curVal = curVal2;}
            else if (istmp2End) {cur = tmp1;}
            do{
                inpTape->write(curVal);
                if (!(cur->isEnd())) {curVal = cur->get();}
            }while(!(cur->isEnd()));
        }
        
        inpTape->gotoStart();
        do{
            outTape->write(inpTape->get());
        }while(!(inpTape->isEnd()));
    }
};