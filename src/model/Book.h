#ifndef Book_H
#define Book_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Book
{
private:
    unordered_map<int, string> bookIdTitleMap;

public:
    void getTitle(int bookId, string title)
    {
        bookIdTitleMap[bookId] = title;
    }
};
#endif