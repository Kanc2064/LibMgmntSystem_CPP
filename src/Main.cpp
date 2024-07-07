#include <iostream>
#include <string>
#include <vector>
#include "model/Rack.h"
#include "model/Book.h"
#include "services/AddEntitiesToLibrary.h"

using namespace std;

int main()
{

    Rack *rack = new Rack();
    Book *book = new Book();
    AddEntitiesToLibrary *addEntitiesToLibrary = new AddEntitiesToLibrary();

    int numOfRacks;
    int book_id;
    string title;
    string comma_separated_authors;
    string comma_separated_publishers;
    string comma_separated_book_copy_ids;
    string book_copy_id;

    string task;
    cin >> task;
    cout << stoi(task);
    if (task == "create_library")
    {
        cin >> numOfRacks;
        cout << "Created library with " << numOfRacks << " racks" << endl;
    }
    while (true)
    {
        string task1;
        cin >> task1;
        if (task1 == "add_book")
        {
            cin >> book_id >> title >> comma_separated_authors >> comma_separated_publishers >> comma_separated_book_copy_ids;

            // mapping bookid to all data

            vector<string> bookCopyList;
            string temp = "";
            for (int i = 0; i < comma_separated_book_copy_ids.size(); i++)
            {
                if (comma_separated_book_copy_ids[i] == ',')
                {
                    bookCopyList.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp = temp + comma_separated_book_copy_ids[i];
                }
            }
            bookCopyList.push_back(temp);

            for (int i = 0; i < bookCopyList.size(); i++)
            {
                addEntitiesToLibrary->putBookCopyInRack(book_id, bookCopyList[i], numOfRacks, rack);
            }
            cout << endl;
        }
        else if (task1 == "remove_book_copy")
        {
            cin >> book_copy_id;
            rack->remove(book_copy_id);
            cout << endl;
        }
    }

    return 0;
}