#ifndef AddEntitiesToLibrary_H
#define AddEntitiesToLibrary_H

#include <iostream>
#include <string>
#include "../model/Rack.h"

class AddEntitiesToLibrary
{

public:
    void putBookCopyInRack(int book_id, string bookCopyID, int numOfRacks, Rack *rack)
    {
        rack->addBookToRack(book_id, bookCopyID, numOfRacks);
        return;
    }
};

#endif