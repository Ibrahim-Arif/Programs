#include <iostream>
using namespace std;

class Book{
public:
	int number, numberOfCopies;
	double price;
	string name, publisher, publishDate;
	
	Book(){
		number = numberOfCopies = price = 0;
		name = publisher = publishDate = "";
	}
	Book(int n, int noc, double p, string na, string pub, string pd){
		number = n;
		numberOfCopies = noc;
		price = p;
		name = na;
		publisher = pub;
		publishDate = pd;
	}
	
	void print(){
		cout << "---------------- Book info ----------------" << endl;
		cout << "Number: " << number << endl;
		cout << "Name: " << name << endl;
		cout << "Number of copies: " << numberOfCopies << endl;
		cout << "Price: " << price << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Publish date: " << publishDate << endl;
		cout << endl;
	}
};

int main(int argc, char** argv) {
	int index=0;
	Book books[10];
	
	books[0] = Book(1, 12, 350, "book1", "publisher1", "21/3/2014");
	books[1] = Book(2, 4, 150, "book2", "publisher2", "5/5/2015");
	books[2] = Book(3, 50, 200, "book3", "publisher3", "30/11/1967");
	books[3] = Book(4, 10, 50, "book4", "publisher4", "29/6/2002");
	books[4] = Book(5, 200, 700, "book5", "publisher5", "3/2/2021");
	
	for(int i=0; i<5; i++)
		books[i].print();
	
	string name;
	cout << "Enter book name to search: ";
	cin >> name;
	for(int i=0; i<5; i++){
		if(books[i].name == name){
			cout << "Book number: " << books[i].number << endl;
			cout << "Number of copies: " << books[i].numberOfCopies << endl;
			cout << endl;
		}
	}
	
	cout << "Count of books in library: " << endl;
	for(int i=0; i<5; i++)
		cout << books[i].name << " has " << books[i].numberOfCopies << " copies in library." << endl;
	
	return 0;
}
