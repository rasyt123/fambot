//
// Created by rasyt on 12/21/2021.
//

#include "Pieces.h"


void Chess::Pieces::setcolor(std::string thecolor) {
    color = thecolor;
}


void Chess::Pieces::settype(char thetype) {
    type = thetype;
}

void Chess::Pieces::setblank(bool val) {
    blank = val;
}

std::string Chess::Pieces::getcolor() {
    return color;
}

char Chess::Pieces::gettype() {
    return type;
}

bool Chess::Pieces::getblank() {
    return blank;
}


