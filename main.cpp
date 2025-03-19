#include <iostream>
#include <vector>
using namespace std;
// dont use new to create copy of struct
struct book {
    string name ;
    string author;
    string category;
    long long pages;
    double weight_by_kilos;
};

int main()
{
    book b1,b2,b3;
    b1.name = "mickey mouse";
    b1.author = "disney production";
    b1.pages = 500;
    b1.weight_by_kilos = 0.675;
    b1.category = "comic_books";
    b2.name = "donald duck ";
    b2.author = "disney production";
    b2.pages = 300;
    b2.weight_by_kilos = 0.500;
    b2.category = "comic_books ";
    b3.name = "goofy adventures";
    b3.author = "disney production";
    b3.pages = 200;
    b3.weight_by_kilos = 0.2;
    b3.category = "magazines";
        vector < book> books;
        books.push_back(b1);
        books.push_back(b2);
        books.push_back(b3);
        for( auto book: books){
            cout <<book.name<<endl;
        }
//    for(int i=0 ; i<3;++i){
//
//        cout << books[i].name<<" ";
//        cout << books[i].category<<" ";
//        cout << books[i].pages<<" ";
//        cout << books[i].author<<" ";
//        cout << books[i].weight_by_kilos<<endl;
//    }
    return 0;
}
