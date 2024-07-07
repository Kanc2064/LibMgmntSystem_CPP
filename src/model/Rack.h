#ifndef Rack_H
#define Rack_H

#include <iostream>
#include <string>
#include <map>

using namespace std;
// struct pair_hash
// {
//     template <class T1, class T2>
//     std::size_t operator()(const std::pair<T1, T2> &pair) const
//     {
//         auto hash1 = std::hash<T1>{}(pair.first);
//         auto hash2 = std::hash<T2>{}(pair.second);
//         return hash1 ^ (hash2 << 1); // Better hash combination
//     }
// };

class Rack
{
private:
    // std::unordered_map<int, std::pair<int, std::string>> bookStoragePlace;
    map<int, pair<int, string>> bookStoragePlace;

public:
    void addBookToRack(int book_id, string bookCopyId, int numOfRacks)
    {
        for (int i = 0; i < numOfRacks; i++)
        {
            if (bookStoragePlace.size() == 0 || bookStoragePlace.find(i + 1) == bookStoragePlace.end())
            {
                bookStoragePlace[i + 1] = {book_id, bookCopyId};
                cout << i + 1 << " ";
                break;
            }
        }
    }
    void remove(string book_copy_id)
    {
        for (auto it : bookStoragePlace)
        {
            if (it.second.second == book_copy_id)
            {
                cout << "removed from " << it.first;
                bookStoragePlace.erase(it.first);
            }
        }
    }
};

#endif