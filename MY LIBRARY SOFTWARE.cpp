//                                 *****LIBRARY 
//                                            SHOP
//                                                PROJECT*****

//                      GAURAV  MEHRA
#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<conio.h>

using namespace std;
//
//                                   BOOK SHOP
//
class bookshop
{
	char bname[100];
	char auname[100];
	int  price;
	int  qty;
	     public:
	     	void purchase();
	     	void booksale();
	     	void search1();
	     	void booklist();
	     	void printdata();
};
//
//                                  SCHOOL/COLLAGE LIBRARY
//
class library
{
   char auname[100];
   char bname[100];
   int  bid;
   char sname[100];
   char fname[100];
   long int phn;
   int  imm,idd,iyy;
   int  smm,sdd,syy;
        public:
        void bookinfo();
		void bookdata();
		void newstudent();
		void studentdata();
		void search2();
		void is_sb_book();
		void is_sb_booklist();	
};
//
//                                   LIBRARY SOCEITY
//
class libraryshop
{
    char sname[100];
	long int phn;
	char fname[100];
	char add[100];
	     public:
		 void studentdata();
		 void newstudent();
		 void search3();
};
//
//                                  BOOK SHOP CLASS FUNCTION
//
void bookshop::printdata()
{   
    system("CLS");
    int sno=1;
    cout<<"\nSr no. :"<<sno<<"\tBook name :"<<bname<<"\tAuther name :"<<auname<<"\tPrice :"<<price<<"\tQuantity :"<<qty<<"\tTotal price : "<<(qty*price);
    sno++;
}
void bookshop::purchase()
{
	cout<<"\n\n\n\n\n\n\t\t***********purchase book*********";
	cout<<"\n\t\t\tEnter book name : ";
	cin.ignore();
	cin.getline(bname, 99);
	fflush(stdin);
	cout<<"\n\t\t\tEnter auther name of book : ";
	cin.getline(auname, 99);
	fflush(stdin);
	cout<<"\n\t\t\tPrice of singal book : ";
	cin>>price;
	cout<<"\n\t\t\tQuantity of book : ";
	cin>>qty;
	cout<<"\n\t\t\tTotal price : "<<(qty*price);
    ofstream fout;
       fout.open("backdataP1.txt",ios::binary|ios::app);
       fout.write((char*)this,sizeof(*this));
       fout.close();
}
void bookshop::search1()
{  int x;
	char A[100];
    cout<<"\n\n\n\n\n\n\t\t\t****Select Search Mode*** : ";
    cout<<"\n\n\t\t\t1 : By Book Name .\n\n\t\t\t2 : By Author Name .";
    cout<<"\n\n\t\t\t3 : Go back";
    cout<<"\n\n\t\t\tEnter : ";
	cin>>x;
    ifstream fin;
    switch (x)
    {
	  case 1 :
	cout<<"\n\t\t\tEnter book Name : ";
	cin.ignore();
	cin.getline(A,99);
	fflush(stdin);
    fin.open("backdataS1.txt",ios::app|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
    	if(!strcmp(A,bname))
    	{
    		printdata();
    		getch();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	break;
      case 2 :
	cout<<"\n\t\t\tEnter Author Name : ";
	cin.ignore();
	cin.getline(A,99);
	fflush(stdin);
    fin.open("backdataS1.txt",ios::app|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
    	if(!strcmp(A,auname))
    	{
    		printdata();
    		getch();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	break;
	case 3 :
		
		break;
    default :
   	cout<<"INVALID";
   	getch();
   	system("CLS");
   	search1();
	break;
}
}
void bookshop::booksale()
{    
   cout<<"\n\n\n\t\t\t***********Book which sale*********";
	cout<<"\n\t\tEnter book name which sale : ";
	cin.ignore();
	cin.getline(bname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter auther name of book : ";
	cin.getline(auname,99);
	fflush(stdin);
	cout<<"\n\t\tPrice of single book\t:";
	cin>>price;
    cout<<"\n\t\tQuantity of book\t:";
	cin>>qty;
	cout<<"\n\t\tTotal price\t:"<<(qty*price);
	ofstream fout ;
    fout.open("backdataS1.txt",ios::binary|ios::app);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void bookshop::booklist()
{
	int x,sno=1;
	system("cls");
	cout<<"\n\n\n\n\t\t*****Book list*******";
	cout<<"\n\t\t**Select mode**";
	cout<<"\n\t\t1 : purchse book list";
	cout<<"\n\t\t2 : sale book list";
	cout<<"\n\t\tEenter :- ";
	cin>>x;
	system("cls");
	ifstream fin ;
	switch(x)
	{
	case 1 :
        fin.open("backdataP1.txt",ios::binary|ios::app);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
        cout<<"\n"<<sno<<"\tBook name : "<<bname<<"\tAuther name : "<<auname<<"\tQuantity : "<<qty<<"\tPrice : "<<price<<"\tTotal price : "<<(qty*price);
        sno++;
	    fin.read((char*)this,sizeof(*this));
	    }
	    fin.close();
	    break;
	case 2 :	
        fin.open("backdataS1.txt",ios::binary|ios::app);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
        cout<<"\n"<<sno<<"\tBook name : "<<bname<<"\tAuther name : "<<auname<<"\tQuantity : "<<qty<<"\tPrice : "<<price<<"\tTotal price : "<<(qty*price);
        sno++;
	    fin.read((char*)this,sizeof(*this));
	    }
	    fin.close();
	    break;
	default :
	    cout<<"\n\t\tPress enter key again";
	    getch();
	    system("cls");
	    booklist();
	    break;
	}
	
}
//
//                                LIBRARY CLASS FUNCTION
//	
void library::bookinfo()
{
	cout<<"\n\n\n\n\n\n\t\t**********BOOK ENTRY**********";
	cout<<"\n\t\tEnter Book name : ";
	cin.ignore();
	cin.getline(bname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter Auther name : ";
	cin.ignore();
	cin.getline(auname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter Accession number : ";
	cin>>bid;
	ofstream fout ;
    fout.open("backdataBK2.txt",ios::binary|ios::app);
    fout.write((char*)this,sizeof(*this));
    fout.close();	
}
void library::bookdata()
{ 
    system("cls");
    int sno=1;
    cout<<"\nSr no. :"<<sno<<"\tAccession no. :"<<bid<<"\tBook name :"<<bname<<"\tAuther name :"<<auname;
    sno++;
}
void library::newstudent()
{
	cout<<"\n\n\n\n\n\n\t\t**********NEW STUDENT**********";
	cout<<"\n\t\tEnter student name : ";
	cin.ignore();
	cin.getline(sname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter father name : ";
	cin.ignore();
	cin.getline(fname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter phn number : ";
	cin>>phn;
	ofstream fout ;
    fout.open("backdataSTU2.txt",ios::binary|ios::app);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void library::studentdata()
{   
    int sno=1;
	system("cls");
    cout<<"\nSr no. :"<<sno<<"\tStudent data :"<<sname<<"\tFather name :"<<fname<<"\tPhone no. :"<<phn;
    sno++;
}
void library::search2()
{
	int x;
	char A[100];
    cout<<"\n\n\n\n\n\n\t\t\t****Select Search Mode*** :";
	cout<<"\n\t\t1 : Student list";
	cout<<"\n\t\t2 : Book list";
	cout<<"\n\t\t3 : Go back";
	cout<<"\n\t\tEnter :--";
	cin>>x;
	ifstream fin;
	switch(x)
	{
		case 1 :
	cout<<"\n\t\t\tEnter student Name : ";
	cin.ignore();
	cin.getline(A,99);
	fflush(stdin);
    fin.open("backdataSTU2.txt",ios::app|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
    	if(!strcmp(A,sname))
    	{
    		studentdata();
    		getch();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	break;
        case 2 :
	cout<<"\n\t\t\tEnter book Name : ";
	cin.ignore();
	cin.getline(A,99);
	fflush(stdin);
    fin.open("backdataBK2.txt",ios::app|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
    	if(!strcmp(A,bname))
    	{
    		bookdata();
    		getch();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	break;
	case 3 :
		
		break;
	}
}
void library::is_sb_book()
{
	    int i,acc;
	    cout<<"\n\t\t\t****Select Search Mode***";
	    cout<<"\n\t\t1 : Issue book";
	    cout<<"\n\t\t2 : Submit book";
	    cin>>i;
	    switch(i)
	    {
		case 1 :
	    cout<<"\n\n\n\n\n\n\t\t********book issue***********";
		cout<<"\n\t\tEnter book name : ";
	    cin.ignore();
		cin.getline(bname,99);
	    fflush(stdin);
		cout<<"\n\t\tEnter book auther name : ";
//		cin.ignore();
		cin.getline(auname,99);
		fflush(stdin);
		cout<<"\n\t\tEnter accession number : ";
		cin>>bid;
		cout<<"\n\t\tEnter student name : ";
		cin.ignore();
		cin.getline(sname,99);
		fflush(stdin);
		cout<<"\n\t\tEnter student father name : ";
//		cin.ignore();
		cin.getline(fname,99);
		fflush(stdin);	
		cout<<"\n\t\tEnter issue date (mm_dd_yy) : ";
		cin>>imm>>idd>>iyy;
		break;
		
		case 2 :
			cout<<"\n\t\tEnter accession number of submition book : ";
		    cin>>acc;
		    ifstream fin;
		    fin.open("backdataIS2.txt",ios::app|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
        	if(acc==bid)
        	{
        		cout<<"\n\n\n\n\n\n\t\t********book submit***********";
    	    	cout<<"\n\n\n\n\n\t\tBook name : "<<bname;
    	    	cout<<"\n\t\tAuther name : "<<auname;
    	    	cout<<"\n\t\tAccession no. : "<<bid;
    	    	cout<<"\n\t\tStudent name : "<<sname;
    	    	cout<<"\n\t\tFather name : "<<fname;
    	    	cout<<"\n\t\tEnter submit date (mm_dd_yy) : ";
		        cin>>smm>>sdd>>syy;
		    }
		    fin.read((char*)this,sizeof(*this));
        	}
	        fin.close();
		}
    	ofstream fout;
    	fout.open("backdataIS2.txt",ios::binary|ios::app);
        fout.write((char*)this,sizeof(*this));
	    fout.close();
}
void library::is_sb_booklist()
{
      int sno=1,i;
	ifstream fin ;
    fin.open("backdataIS2.txt",ios::binary|ios::app);
    cout<<"\n\n\n\n\t\t****Select Mode***";
    cout<<"\n\n\n\n\t\t1 : Issue book :--";
	cout<<"\n\t\t2 : Submit book :--";
	cout<<"\n\t\tEnter :--";
	cin>>i;
	switch(i)
	{
	case 1 :
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
         cout<<"\nSr no. "<<sno<<"\tAuther name : "<<auname<<"\tBook name : "<<bname<<"\tAccession no. : "<<bid<<"\tStudent name : "<<sname<<"\tFather name : "<<fname<<"\tIssue date : "<<imm<<"/"<<idd<<"/"<<iyy;
        sno++;
        fin.read((char*)this,sizeof(*this));
		}
	    fin.close();
	    break;	
    case 2 :
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
       {
       cout<<"\nSr no. "<<sno<<"\tAuther name : "<<auname<<"\tBook name : "<<bname<<"\tAccession no. : "<<bid<<"\tStudent name : "<<sname<<"\tFather name : "<<fname<<"\tSubmit date : "<<smm<<"/"<<sdd<<"/"<<syy;
       sno++;
       fin.read((char*)this,sizeof(*this));
	   }
	   fin.close();
	   break;
    }
}
//
//                                   LIBRARY SHOP FUNCTION
//
void libraryshop::newstudent()
{
	cout<<"\n\n\n\n\n\n\t\t**********NEW STUDENT**********";
	cout<<"\n\t\tEnter student name : "<<endl;
	cin.getline(sname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter phone number : ";
	cin>>phn;
	cout<<"\n\t\tEnter father name : "<<endl;
	cin.getline(fname,99);
	fflush(stdin);
	cout<<"\n\t\tEnter address of student : "<<endl;
	cin.getline(add,99);
	fflush(stdin);
	ofstream fout ;
    fout.open("backdata3.txt",ios::binary|ios::app);
    fout.write((char*)this,sizeof(*this));
	fout.close();
}
void libraryshop::studentdata()
{  
    int sno=1;
    cout<<"\n\n\n\n\n\n\t\t***********Student data**************";
	ifstream fin;
	fin.open("backdata3.txt",ios::binary|ios::app);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
	cout<<"\n"<<sno<<"\tStudent name : "<<sname<<"\tPhone number : "<<phn<<"\tFather name : "<<fname<<"\tAddress : "<<add;
    sno++;
    fin.read((char*)this,sizeof(*this));
    }
	fin.close();
}
void libraryshop::search3()
{  
    int x;
	char A[100];
    cout<<"\n\n\n\n\n\n\t\t\t****Select Search Mode*** :";
	cout<<"\n\t\t\tEnter student Name : "<<endl;
	cin.getline(A,99);
	fflush(stdin);
	system("cls");
	ifstream fin;
    fin.open("backdata3.txt",ios::app|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
    	if(!strcmp(A,sname))
    	{
    		studentdata();
    		getch();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}

//                             CLASS START

class start
{
	public:
   void start1()
   { 
    int i;
	bookshop b;
	cout<<"\n\n\n\n\n\n\t\t***************BOOK SHOP****************";
    cout<<"\n\t\t\tEnter your choise :- ";
    cout<<"\n\t\t\t1). Purchase Book";
    cout<<"\n\t\t\t2). Search Book";
    cout<<"\n\t\t\t3). Sale Book";
    cout<<"\n\t\t\t4). book purchase or sale List";
    cout<<"\n\t\t\t5). Go Back";
	cout<<"\n\t\t\tEnter  : ";
    cin>>i;
    system("CLS");
    switch(i)
    {
    	case 1 :
    		b.purchase();
    		getch();
    		system("CLS");
    	    start1();
			break;
    	case 2 :
    		b.search1();
    		getch();
    		system("CLS");
    	    start1();
			break;
    	case 3 :
    		b.booksale();
    		getch();
    		system("CLS");
    	    start1();
			break;
    	case 4 :
    		b.booklist();
    		getch();
    		system("CLS");
    	    start1();
			break;
    	case 5 :
    		
    	break;
    	default :
    		cout<<"invalid";
    		start1();
			break;
	}
}
   void start2()
   { 
    int i;
   	library  l;
    cout<<"\n\n\n\n\n\t\t\t*************SCHOOL OR COLLAGE LIBRARY****************";
    cout<<"\n\t\tenter your choise";
    cout<<"\n\t\t1 : Information of book in library";
    cout<<"\n\t\t2 : list of book in library";
    cout<<"\n\t\t3 : new student entry book";
    cout<<"\n\t\t4 : book or student search";
    cout<<"\n\t\t5 : book issue or submit";
    cout<<"\n\t\t6 : book issue or submit list";
    cout<<"\n\t\t7 : Go back";
    cout<<"\n\t\tenter : ";
    cin>>i;
    system("cls");
    switch(i)
    {
    	case 1 :
    		l.bookinfo();
    		getch();
    		system("CLS");
    	    start2();
    		break;
    	case 2 :
    		{
    		ifstream fin;
    		fin.open("backdataBK2.txt",ios::app|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
    		   l.bookdata();
		    }
		    fin.read((char*)this,sizeof(*this));
	        fin.close();
    		system("CLS");
    	    start2();
    		break;
    	    }
    	case 3 :
    		l.newstudent();
    		getch();
    		system("CLS");
    	    start2();
    		break;
    	case 4 :
    		l.search2();
    		getch();
    		system("CLS");
    	    start2();
    		break;
    	case 5 :
    		l.is_sb_book();
    		getch();
    		system("CLS");
    	    start2();
    		break;
    	case 6 :
		    l.is_sb_booklist();
    		getch();
    		system("CLS");
    	    start2();
    		break;
    	case 7 :
    		
		break;
		
    	default :
    		cout<<"invalid";
    		start2();
    		break;
	}
}
   void start3()
{
   	int i;
   	libraryshop ls;
   	cout<<"\n\n\n\n\n\t\t\t**************LIBRARY****************";
    cout<<"\n\t\tenter your choise";
    cout<<"\n\t\t1 : new student entry ";
    cout<<"\n\t\t2 : student data search";
    cout<<"\n\t\t3 : show student data";
    cout<<"\n\t\t4 : Go back";
    cout<<"\n\t\tenter  : ";
    cin>>i;
    system("cls");
    switch(i)
    {
    	case 1 :
    		ls.newstudent();
    		getch();
    		system("CLS");
    	    start3();
    		break;
    	case 2 :
    		ls.search3();
    		getch();
    		system("CLS");
    	    start3();
    		break;
    	case 3 :
    		ls.studentdata();
    		getch();
    		system("CLS");
    	    start3();
    		break;
    	case 4 :
    		  
		break;
    	default :
    		cout<<"invalid";
    		break;
	}
}

};

//                       MAIN FUNCTION

int main()
{   
    start s;
    int c;
    cout<<"\n\n\n\n\n\n\t\t**************************************************\n";
     cout<<"\n\t\t***           WELCOME TO LIBRARY               ***\n";
     cout<<"\n\t\t**************************************************\n";
     cout<<"\n\t\t\tChoose Your Work  :-";
     cout<<"\n\t\t\t 1). FOR BOOK SHOP";
     cout<<"\n\t\t\t 2). FOR SCHOOL COLLAGE LIBRARY";
     cout<<"\n\t\t\t 3). FOR LIBRARY SHOP";
     cout<<"\n\t\t\t 4). EXIT";
     cout<<"\n\t\t\tEnter:- ";
     cin>>c;
     switch(c)
	 {
	 	case 1:
	 		system("CLS");
	 		s.start1();
	 		main();
	 		break;
	 	case 2 :
	 		system("CLS");
	 		s.start2();
	 		break;
	 	case 3 :
	 		system("CLS");
	 		s.start3();
	 		break;
	 	case 4 :
	 		system("CLS");
	 		cout<<"EXIT";
	 	    break;
		default :
			system("CLS");
			cout<<"Invalid";
			getch();
			main();
			break;	 	
     } 	
}

