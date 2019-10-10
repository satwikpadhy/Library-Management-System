#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;

class book
 {
 	private:
 		char bname[40];
 		int bno;
 		char aname[40];
 	
	public:
 	
	void create_book()
 	 {  
 	    system("cls");
 	 	cout<<"Enter book number :";
 	 	cin>>bno;
 	 	cout<<"Enter book name :";
 	 	cin.get();
		gets(bname);
 	 	cout<<"Enter Author name :";
 	 	gets(aname);
 	 }
 	
 	void show_book()
 	 {
 	 	cout<<"Book Number :"<<bno<<endl;
 	 	cout<<"Book Name :"; puts(bname);
 	 	cout<<"Author Name :"; puts(aname);
 	 }
 	
 	void modify_book()
 	 {  
 	    cout<<"Enter new Book Number:";
 	    cin>>bno;
 	 	cout<<"Enter new book name :";
 	 	cin.get();
 	 	gets(bname);
 	 	cout<<"Enter new author name :";
 	    gets(aname);
 	 }
 	 
 	void bookrepo()
 	 {
 	 	cout<<"Book Number :"<<bno<<endl;
 	 	cout<<"Book Name :" ; puts(bname);
 	 	cout<<"Author Name :"; puts(aname);
 	 }
 	 
 	int booknumber()
 	 {
 	 	return bno;
 	 }
 };


class student
 {
 	private:
 		int admno;
 		char sname[25];
 		int bno;
 		int token;
 		
 	public :
 		void create_s()
 		 {  
 		    system ("cls");
 		 	cout<<"Enter The admission number of the student :";
 		 	cin>>admno;
 		 	cout<<"Enter Student Name :";
 		 	cin.get();
 		 	gets(sname);
 		 	token = 0;
 		 	system ("cls");
 		 	cout<<"New Record Created!";
 		 }
 		
 		void show_s()
 		 {  
 		 	cout<<endl;
			cout<<"Admission Number :"<<admno<<endl;
 		 	cout<<"Student Name :"; puts(sname);
 		 	cout<<"Number of Books Issued :"<<token<<endl;
 		 	cout<<"Book Number :"<<bno<<endl;
 		 }
 		
 		int admissionno()  
          {
		    return admno;
		  }
		char bookno()
		 {
			 return bno;
		 }
		int no_of_books()
		 {
		 	return token;
		 }
		 
		void modifystu()
		 {
		 	system ("cls");
 		 	cout<<"Enter The admission number of the student :";
 		 	cin>>admno;
 		 	cout<<"Enter Student Name :";
 		 	cin.get();
 		 	gets(sname);
 		 	system ("cls");
 		 	cout<<"Record Modified!";
 	     }
		 void addtoken()
 		 {
 		 	token=1;
 		 }
 		 void reset_token()
 		  {
 		  	token =0 ;
 		  	bno=0;
 		  }
 		 void get_bno(int x)
 		  {
 		  	bno= x;
 		  }
 };
 
 
 

 	
 
//################################################################################################################################## 
/*Global Declarations#############################################################################################################
##################################################################################################################################*/ 
 
 fstream f,fd;
 student s;
 book b;
 

//####################################################################################################################################
//Functions Used in the program. #####################################################################################################
//#################################################################################################################################### 		
void startup()
 {
 	system("cls");
 	cout<<"Kendriya Vidylaya No. 2 CRPF Campus, Bhubaneswar \n\nLibrary Management \n\n";
 	system("pause");
 	system("cls");
 }
	
void book_issue()
 {
 	system("cls");
 	int adm,bn,t=0,t1=0;
 	cout<<"Issue a Book"<<endl;
 	cout<<"Enter the Student's Admission Number :";
 	cin>>adm;
 	f.open("students.dat",ios::in|ios::out);
 	fd.open("books.dat",ios::in|ios::out);
 	while(f.read((char*)&s,sizeof(student)))
 	 {
 	 	if(adm==s.admissionno())
 	 	  {
 	 	  	t=1;
 	 	  	if(s.no_of_books()==0)
 	 	  	 {
 	 	  	    cout<<"Enter the Book Number of the book to be issued :";
				cin>>bn;
				while(fd.read((char*)&b,sizeof(book)))	
				 {
				 	if(b.booknumber()==bn)
				 	 { 
				 	    cout<<"Book Details "<<endl;
				 	 	b.show_book();
				 	 	cout<<"\n\nStudent Details \n";
				 	 	s.show_s();
				 	 	s.addtoken();
				 	 	s.get_bno(bn);
				 	 	t1=1;
				 	 	
				 	 	int pos=-1*sizeof(s);
				 	 	f.seekp(pos,ios::cur);
				 	 	f.write((char*)&s,sizeof(student));
				 	 	cout<<"Book Issued Successfully!"<<endl;
				 	 	cout<<"Please Note : Write the Date in the Back of the Book. The book is to be returned within 15 days. Fine Rs5 per day of delay."<<endl;
				 	 }
				 	
			     }
			    if (t1==0)
			     cout<<"Book Not Found!";
 	 	     }
 	 	    else
 	 	     cout<<"You may not have returned previous book.";
 	 	  }
 	 	
 	 }
 	if(t==0)
 	 	 cout<<"Student Not found.";
    system("pause");
    f.close();
    fd.close();
 }

void book_deposit()
 {  int adm,t=0;
 	system("cls");
 	cout<<"Deposite Book."<<endl;
 	cout<<"Enter the Admission Number of the Student :";
    cin>>adm;
    f.open("students.dat",ios::in|ios::out);
    
    while(f.read((char*)&s,sizeof(student)))
     {
     	if(adm==s.admissionno())
     	 {  
     	    if(s.no_of_books()==1)
     	 	{
			cout<<"Details of the Student :"<<endl;
     	 	s.show_s();
     	    s.reset_token();
     	    int pos=-1*sizeof(s);
			f.seekp(pos,ios::cur);
			f.write((char*)&s,sizeof(student));
			cout<<"Book Return Successfull!"<<endl;
		    }
		    else
		     cout<<"No books Issued.";
		     
		    t=1; 
         }
     }
    if(t==0)
     cout<<"Student Not Found!";
    f.close();
    system("pause");
 }
 
 


//############################################################################################################
//Functions to write To the files#############################################################################
//############################################################################################################




void write_book()
 {
 	char ch;
    f.open("books.dat",ios::out|ios::app);
	do 
	 {
	   b.create_book();
	   f.write((char*)&b,sizeof(book)); 
	   cout<<"Do you want to add more books?(y/n) :";
	   cin>>ch;
     }while(ch=='y'||ch=='Y');
    f.close();
 }
 
void write_stu()
 {
 	char ch;
    f.open("students.dat",ios::out|ios::app);
	do 
	 {
	   s.create_s();
	   f.write((char*)&s,sizeof(student)); 
	   cout<<"Do you want to add more Students?(y/n) :";
	   cin>>ch;
     }while(ch=='y'||ch=='Y');
    f.close();
 }
 
 




//############################################################################################################
//Functions to display all Details############################################################################
//############################################################################################################ 
 
 
 
 
 
void disp_all_b()
 {
   f.open("books.dat",ios::in);
   system("cls");
   while(!f.eof())
    { 
      cout<<endl;
	  f.read((char*)&b,sizeof(book));
	  if(f.eof()) break;
	  b.show_book();
    }
    f.close();
    system("pause");
 }
 

void disp_all_s()
 {
   f.open("students.dat",ios::in);
   system("cls");
   while(!f.eof())
    { 
      cout<<endl;
	  f.read((char*)&s,sizeof(student));
	  if(f.eof()) break;
	  s.show_s();
    }
    f.close();
    system("pause");
 }




//############################################################################################################
//## Functions to display specific Details ###################################################################
//############################################################################################################ 




void disp_spec_b()
 {  
    int scr,t=0;
 	system("cls");
 	f.open("books.dat",ios::in);
 	cout<<"Enter Book Number of the book you want to search for:";
 	cin>>scr;
 	while(!f.eof())
 	{
 	  f.read((char*)&b,sizeof(book));
 	  if(f.eof())
 	 	    break;
 	  if(scr==b.booknumber())
 	 	 { 
		   b.show_book();
		   t=1;
         }
	  
	}
		
	   
	if(t==0)
	    cout<<"Sorry Book Not Found. Try Again.\n";
	  
    f.close();
    system("pause");
}



void disp_spec_s()
 {  
    int scr,t=0;
 	system("cls");
 	f.open("students.dat",ios::in);
 	cout<<"Enter admission Number of the Student you want to search for:";
 	cin>>scr;
 	while(!f.eof())
 	{
 	  f.read((char*)&s,sizeof(student));
 	  if(f.eof())
 	 	    break;
 	  if(scr==s.admissionno())
 	 	 { 
		   s.show_s();
		   t=1;
         }
	  
	}
		
	   
	if(t==0)
	    cout<<"Sorry Student Not Found. Try Again.\n";
	  
    f.close();
    system("pause");
}



//###################################################################################################################################
//### Functions to modify records ###################################################################################################
//###################################################################################################################################




void modify_b()
 { 
   int scr,t=0;
 	system("cls");
 	f.open("books.dat",ios::in|ios::out);
 	cout<<"Enter Book Number of the book you want to modify:";
 	cin>>scr;
 	while(f.read((char*)&b,sizeof(book)))
 	{
 	  
 	  if(scr==b.booknumber())
 	 	 { 
		   b.modify_book();
		   t=1;
		   int pos = -1*sizeof(b);
	       f.seekp(pos,ios::cur);
	       f.write((char*)&b,sizeof(book));  
         }
	  
	}
		
	   
	if(t==0)
	    cout<<"Sorry Book Not Found. Try Again.\n";
	
	f.close();
    system("pause");
    
}


void modify_s()
 { 
   int scr,t=0;
 	system("cls");
 	f.open("students.dat",ios::in|ios::out);
 	cout<<"Enter Admission Number of the Student you want to modify:";
 	cin>>scr;
 	while(f.read((char*)&s,sizeof(student)))
 	{
 	  
 	  if(scr==s.admissionno())
 	 	 { 
		   s.modifystu();
		   t=1;
		   int pos = -1*sizeof(s);
	       f.seekp(pos,ios::cur);
	       f.write((char*)&s,sizeof(student));  
         }
	  
	}
		
	   
	if(t==0)
	    cout<<"Sorry Student Not Found. Try Again.\n";
	
	f.close();
    system("pause");
    
}


/*##################################################################################################################################
##### Functions to Delete Records ##################################################################################################
##################################################################################################################################*/




void del_b()
 {  system("cls");
    int bn;
 	cout<<"Enter the Book Number of the book you want to remove :";
 	cin>>bn;
 	fd.open("temp.dat", ios::out);
 	f.open("books.dat", ios::in|ios::out);
 	f.seekg(0,ios::beg);
 	while(f.read((char*)&b,sizeof(book)))
 	 {
 	 	if(bn!=b.booknumber())
 	 	 {
 	 	 	fd.write((char*)&b,sizeof(book));
 	 	 }
 	 }
 	f.close();
 	fd.close();
 	remove("books.dat");
 	rename("temp.dat","books.dat");
 	cout<<"\nBook Deleted";
 	system("pause");
 }
 
void del_s()
 {  system("cls");
    int bn;
 	cout<<"Enter the Admission Number of the Student you want to remove :";
 	cin>>bn;
 	fd.open("temp.dat", ios::out);
 	f.open("students.dat", ios::in|ios::out);
 	f.seekg(0,ios::beg);
 	while(f.read((char*)&s,sizeof(student)))
 	 {
 	 	if(bn!=s.admissionno())
 	 	 {
 	 	 	fd.write((char*)&s,sizeof(student));
 	 	 }
 	 }
 	f.close();
 	fd.close();
 	remove("students.dat");
 	rename("temp.dat","students.dat");
 	cout<<"\nStudent Record Deleted";
 	system("pause");
 }
 	
 	
 	
 	
 	
 	
 	
 	
 	
//####################################################################################################################################
//Function for Admin Menu############################################################################################################
//###################################################################################################################################	
 	
 
void admin_menu()
{   int ch;
	do {
		system("cls");
	    cout<<"Administration Menu\n";
	    cout<<"\n1.Create Student Record.";
	    cout<<"\n2.Display all Student Record";
	    cout<<"\n3.Display Specific Student Record";
	    cout<<"\n4.Modify Student Record";
	    cout<<"\n5.Delete Student Record";
	    cout<<"\n6.Add new Book";
	    cout<<"\n7.Display All Books";
	    cout<<"\n8.Display Specific book";
	    cout<<"\n9.Modify Book";
	    cout<<"\n10.Delete Book";
	    cout<<"\n11.Return to main menu";
	    cout<<"\nEnter Option (1-11) :";
	    cin>>ch;
	
	    switch (ch)
        {
          case 1: write_stu(); break;	
		  case 2: disp_all_s(); break;
		  case 3: disp_spec_s(); break;
		  case 4: modify_s(); break;
		  case 5: del_s(); break;
		  case 6: write_book(); break;
		  case 7: disp_all_b(); break;
		  case 8: disp_spec_b(); break;
		  case 9: modify_b(); break;
		  case 10: del_b(); break;
		  case 11: break;
	      default : cout<<"Wrong Choice"; break;
		}
    }while(ch!=11);
}



/*##################################################################################################################################
## Main Function ###################################################################################################################
##################################################################################################################################*/



int main()
 {  
    int ch;
 	startup();
 	do
 	{   system("cls");
 		cout<<" \t\t Main Menu \n";
 		cout<<"1. Book Issue \n";
 		cout<<"2. Book Deposit \n";
 		cout<<"3. Administration Menu \n";
 		cout<<"4. Exit \n Select option (1-4)";
 		
 		cin>>ch;
 		system("cls");
 		switch(ch)
 		 {
 		 	case 1 : book_issue();
 		 	         break;
 		 	case 2 : book_deposit();
 		 	         break;
 		 	case 3 : admin_menu();
 		 	         break;
 		 	case 4 : break;
 		 	case 5 : cout<<"Wrong Option. Please try again.";
 		 }
 		 	
 	}while(ch!=4);
 }
