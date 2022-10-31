#include <iostream>
#include "UnsortedType.h"
#include "UnsortedType.cpp"

class string;


class studentInfo{
public:
    int ID;
    string name;
    double cgpa;
    studentInfo(){
        ID = 0;
        name = " ";
        cgpa = 0.0;
    }

    studentInfo(int i , std::string n, double c){
        ID = i;
        name = n;
        cgpa = c;
    }
    bool operator == (studentInfo &other){
        return ID == other.ID && name==other.name && cgpa==other.cgpa;
    }
    bool operator!=(studentInfo &other){
        return ID!=other.ID || name!=other.name || cgpa!= other.cgpa;
    }
}
void print(){
    std :: cout << ID << " , " << name << " , " << cgpa << endl;
}

};






int main() {
    UnsortedType<int > list;
    list.InsertItem(5);
    list.InsertItem(7);
    list.InsertItem(6);
    list.InsertItem(9);

    int ad ;

    for( int  i =0 ; i < list.LengthIs() ; i++ ) {
        list.GetNextItem(ad);
        std :: cout << ad << " " ;

    }
   std :: cout << \n << list.LengthIs() << endl;

    list.InsertItem(1);
    list.ResetList();
    for (int i =0 ; i < list.LengthIs(); i ++ ){
        list.GetNextItem(ad);
        std::cout<<ad<< " ";
    }


    ad=4;
    bool f;
    list.RetrieveItem(ad,f);
    if(f) std::cout<<"\nItem is found\n";
    else std ::cout << "\nItem is not found\n";

    ad = 5 ;
    list.RetrieveItem(ad,f);
    if(f) std ::cout<< "Item is found\n";
    else std :: cout << "Item is not found\n";

    ad=9 ;
    list.RetrieveItem(ad,f);
    if(f) std ::cout<< "Item is found\n";
    else std :: cout << "Item is not found\n";

    ad=10;
    list.RetrieveItem(ad,f);
    if(f) std ::cout<< "Item is found\n";
    else std :: cout << "Item is not found\n";


    if (list.IsFull()) std :: cout << "List is Full\n";
    else std :: cout << "List is not Full \n";

    list.DeleteItem(5);

    if (list.IsFull()) std :: cout << "List is Full\n";
    else std :: cout << "List is not full\n";

    list.DeleteItem(1);

    list.ResetList();
    for (int i=0; i<list.LengthIs(); i++){
        list.GetNextItem(ad);
        std :: cout << ad << " ";

    }
    std :: cout << \n;

UnsortedType<studentInfo>students;
studentInfo s1(15234, "Jon", 2.6);
studentInfo s2(13732, "Tyrion",3.9);
studentInfo s3(13569,"Sandor", 1.2);
studentInfo s4(15467, "Ramsey", 3.1);
studentInfo s5(16285 , "Arya", 3.1);


students.InsertItem(s1);
students.InsertItem(s2);
students.InsertItem(s3)
students.InsertItem(s4);
students.InsertItem(s5);

students.DeleteItem(s4);


students.Retrieveltem(s3,f);
if (f){
    std :: cout << "Item is Found\n";
    s3.print();
} else {
    std :: cout << "Item is not found \n";

}

studentInfo s;
for (int i=0; i<students.LengthIs(); i++ ){
    students.GetNextItem(s);
    s.print();
}


     return 0;
}
