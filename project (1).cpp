#include <iostream>
#include <fstream>
using namespace std;
class product
{
private:
    struct prod
    {
        int ID;
        string name;
        string type;
        int quantity;
        float price;
    };
    prod p;
public:
    void display()
    {
        cout << p.type << '\t' << p.name << '\t' << p.quantity <<'\t' <<p.price <<'\t' << p.ID << endl;
    }
    void newproduct(int x, string y, string z, int w, float t)
    {
        p.ID = x;
        p.name = y;
        p.type = z;
        p.quantity =w;
        p.price = t;
        
    }
    void editquantitiy(int x)
    {
        p.quantity -= x;
    }
    float getprice(int y)
    {
        return p.price*y;
    }
      void display2()
    {
        cout << p.type << '\t' << p.name << '\t' <<p.price <<'\t' << p.ID << endl;
    }
    int getid()
    {
        return p.ID;
    }
    string getname()
    {
        return p.name;
    }
    string gettype()
    {
        return p.type;
    }
    int getquantity()
    {
        return p.quantity;
    }
    float getprice2()
    {
        return p.price;
    }
    
};
class store
{
private:
    product p[1000];
    int index=0;
public:
    store()
    {
        string nam;
        string typ;
        int ID;
        int qua;
        float pric;
        ifstream file;
        file.open("products.txt");
        while(!file.eof())
        {
            file >> ID >> nam >> typ >> qua >> pric;
            p[index].newproduct(ID, nam, typ, qua, pric);
            index++;
        }
        file.close();
        
    }
    void addproduct(string na,string ty,int id,int q,float pr)
    {
        string n=na;
        string typ=ty;
        int ID=id;
        int qua=q;
        float pric=pr;
        ofstream file;
        file.open("products.txt",ios::out|ios::app);
        file << ID  << '\t' << n <<'\t' << typ << '\t'<< qua << '\t' << pr << endl;
        file.close();
    }
    void display()
    {
        for(int i=0; i<index;i++){
            p[i].display();
        }
            
    }
    product addcart(int x)
    {
         return p[x];
    }
    void delet()
    {
        
        string nnn;
        string ty;
        int dd;
        int quaa;
        float prii;
        string t="";
        ofstream file;
        file.open("products.txt",ios::out|ios::trunc);
        for(int i=0;i<index;i++)
        {
            nnn=p[i].getname();
            ty=p[i].gettype();
            dd=p[i].getid();
            quaa=p[i].getquantity();
            prii=p[i].getprice2();
            file << dd <<'\t' << nnn <<'\t' << ty << '\t'<< quaa << '\t' << prii << endl;
        }
        file.close();
    }
};
class Cart
{
private:
    product items[100];
    int actual;
    float to=0;
    store d;
   
public:
    Cart() {
        actual = 0;
    }
    
    void displayItems() {
        for (int i = 0;i < actual;i++){
            items[i].display();
            cout << "================================" << endl;
            
        }
        cout << "the total of the cart:" << to << endl;
       
    }
    void addProduct(int x, int y)
    {
        items[actual]= d.addcart(x);
        items[actual].editquantitiy(y);
        to += items[actual].getprice(y);
        actual++;
    }
    float payment() 
    {
        float t;
        t= to;
        return t;
    }
};
class Ewallet 
{
private:
    struct card
    {   
        string type;
        int card_number;
        int cvv;
        string holder_name;
        float balance=0;
    };
    card r[100];
    int index=0;
    int index2;
        
public:
    Ewallet()
    {
        ifstream file;
        file.open("ewallet.txt");
        while(!file.eof())
        {
            file >> r[index].type >> r[index].card_number >> r[index].cvv >> r[index].holder_name >> r[index].balance;
            index++;
        }
        file.close();
    }
    float add_balance (float amount) 
    {
        r[index2].balance += amount;
        return r[index2].balance;
    }
    void minusbalance(float x)
    {
       r[index2].balance -= x;
    }
    
    void addinfo(string t, int number, int cv, string name, float bal)
    {
        r[index].type=t;
        r[index].card_number=number;
        r[index].cvv=cv;
        r[index].holder_name=name;
        r[index].balance=bal;
        ofstream file;
        file.open("ewallet.txt",ios::out|ios::app);
        file << r[index].type << '\t' << r[index].card_number << '\t' << r[index].cvv << '\t' << r[index].holder_name<< '\t' << r[index].balance << endl;
        index++;
        file.close();  
    }
    void save()
    {
        ofstream file;
        file.open("products.txt",ios::out|ios::trunc);
        for(int i=0;i<index;i++)
        {
            r[i].type;
            r[i].card_number;
            r[i].cvv;
            r[i].holder_name;
            r[i].balance;
            file << r[i].type << '\t' << r[i].card_number << '\t' << r[i].cvv << '\t' << r[i].holder_name << '\t' << r[i].balance << endl;
        }
        file.close();
    }

    int checkinfo(int cv)
    {
        for(int i=0;i<index;i++)
        {
            if(cv==r[i].cvv)
            {
                 index2=i;
                 return i;
            }   

        }
        return -1;
             
    }
    void display_value(){
            cout << "this" << r[index2].type << " card which is held by " << r[index2].holder_name << " with number " << r[index2].card_number  << " has a balance of " << r[index2].balance << endl;
        
    }
    
};
class User 
{
private:
    Ewallet a;
    float paymoney=0;
    store pro;
    struct customer
    {
        string nameC;
        string emailC;
        string passwordC;
    };
    customer c[100];
    int index1=0;
    struct employer
    {
        string nameE;
        string emailE;
        string passwordE;
    };
    employer e[10];
    int index2=0;
    
public :   
        User(int x)
        {
           switch(x)
           {
                case 1:
                {
                    string nC;
                    string eC;
                    string pC;
            
                    ifstream fileC;
                     fileC.open("customerdata.txt");
                    while(!fileC.eof())
                    {
                        fileC >> nC >> eC>> pC;
                        c[index1].emailC = eC;
                        c[index1].nameC= nC;
                        c[index1].passwordC= pC;
                        index1 ++;
                    }
                    fileC.close();
                }
                break;
                case 2:
                {
                    string nE;
                    string eE;
                    string pE;
            
                    ifstream fileE;
            
                    fileE.open("employerdata.txt");
                    while(!fileE.eof())
                    {
                        fileE >> nE >> eE >>pE;
                        e[index2].nameE = nE;
                        e[index2].emailE=eE;
                        e[index2].passwordE=pE;
                        index2++;
                    }
                    fileE.close();
                }
           }
          
        }
            bool check(string pass)
            {
                for(int i=0;i<index1;i++)
                {
                    if(pass == c[i].passwordC)
                    {
                        return true;
                    }
                } 
                return 0;
                   
            }
        bool check2(string pass)
        {
            for(int i=0;i<index2;i++)
            {
                if(pass == e[i].passwordE)
                {
                    return true;
                }
                else 
                {
                    return false;
                }
            }
             
        }
        int  checkcard(int cvv)
        {
               return a.checkinfo(cvv);
        }
        void add_new_customer(string nC , string eC , string pC)
        {
            c[index1].nameC = nC;
            c[index1].emailC = eC;
            c[index1].passwordC = pC;
            
            ofstream fileC;
            fileC.open("customerdata.txt",ios::out|ios::app);
            fileC << c[index1].nameC <<'\t' << c[index1].emailC <<'\t' << c[index1].passwordC << endl;
            index1++;
            fileC.close();
            
        }
        void addbalance(float x)
        {
                a.add_balance(x);
        }
        void pay(float x)
        {
              a.minusbalance(x);
        }
        void display()
        {
            a.display_value();
        }
        
        void add_new_employer (string nE , string eE , string pE)
        {
            e[index2].nameE = nE;
            e[index2].emailE = eE;
            e[index2].passwordE = pE;
            
            ofstream fileE;
            fileE.open("employerdata.txt",ios::out|ios::app);
            fileE << e[index2].nameE  << e[index2].emailE << e[index2].passwordE << endl;
            index2++;
            fileE.close();
           
        }
        void newproduct()
        {
                string n;
                string typ;
                int ID;
                int qua;
                float pric;
                cout << "The name of the product=";
                cin >> n;
                cout << "The type of the product=";
                cin >> typ;
                cout << "The ID of product=";
                cin >> ID;
                cout << "The quantity of the product=";
                cin >> qua;
                cout << "The price of the product=";
                cin >> pric;
                pro.addproduct(n,typ,ID,qua,pric);
            }  

};
int main()
{
    store runn;
    store run;
    char op;
    char op1;
    char Len1;
    char yess;
    char Len;
    char ttt;
    int vv;
    char yes;
    int choice1;
    cout << "1-sign in" << endl;
    cout << "2- sign up" << endl;
    cout << "Enter your choice:";
    cin >> choice1;
    switch(choice1)
    {
        case 1:
        {
            int choice2;
            cout << "1-customer" << endl;
            cout << "2-adimn" << endl;
            cout << "Enter your choice";
            cin >> choice2;
        switch(choice2)
            {
                case 1:
                {
                    User c(1);
                    string name;
                    string password;
                    cout << "Enter your name:";
                    cin >> name;
                    cout << "Enter your password:";
                    cin >> password;
                        if (c.check(password)== 1)
                        {
                            cout << "The password is correct" << endl;
                        }
                        else
                        {   
                            while(c.check(password)==0)
                            {
                                cout << "The password is uncorrect" << endl;
                                cout << "Enter your password:";
                                cin >> password;
                                c.check(password);
                            }    
                        }
                        do{
                            
                            
                            run.display();
                            Cart d1;
                            do
                            {
                                
                                int q;
                                int an;
                                cout << "selcet your product and please write its number in the table:";
                                cin >> q;
                                cout << "Enter your quantity:";
                                cin >> an;
                                d1.addProduct(q,an);
                                cout << "if you want to continue shoppping press y, if not press n:";
                                cin >> yes;
                            }while ( yes == 'y');
                                d1.displayItems();
                                cout << "============================================="<< endl;
                                
                                cout << "Enter your cvv:";
                                cin >> vv;
                                    if (c.checkcard(vv) == -1)
                                     {
                                        while(c.checkcard(vv) == -1)
                                        {
                                            cout << "The cvv is uncorrect" << endl;
                                            cout << "Enter your cvv";
                                            cin >> vv;
                                            c.checkcard(vv);
                                        }  
                                    }
                                    else
                                    {   
                                      cout << "The cvv is correct" << endl;
                                    }
                                c.display();
                                int choice3;
                                cout << "1-chrage your balane" << endl;
                                cout << "2-pay" << endl;
                                cout << "Enter your Choice:";
                                cin >> choice3;
                                do{
                                    
                                    switch (choice3)
                                    {
                                        case 1:
                                        {
                                            int num;
                                            cout << "Enter the amount you want to add:";
                                            cin >> num;
                                            c.addbalance(num);
                                        }
                                        break;
                                        case 2:
                                        {
                                            int num2;
                                            cout << "Enter the amount to paid:";
                                            cin >> num2;
                                            c.pay(num2);
                                        }
                                    }
                                    cout << "if you want to pay or chrage your balance press y, if no press n:" << endl;
                                    cin >> Len;
                                }while(Len == 'y');
                                cout << "The payment was successful!" << endl;
                                cout << "Do you to shop again press y, if no press n to exit:";
                                cin >> op;
                            }while(op =='y');
                                c.display();
                                run.delet(); 
                                return 0;

                }
                    break;
                    case 2:
                    {   
                        User e(2); 
                        string name;
                        string password;
                        cout << "Enter your name:";
                        cin >> name;
                        cout << "Enter your password:";
                        cin >> password;
                        if (e.check(password)== 1)
                        {
                            cout << "The password is correct" << endl;
                        }
                        else
                        {   while(e.check(password)==0)
                            {
                                cout << "The password is uncorrect" << endl;
                                cout << "Enter your password:";
                                cin >> password;
                                e.check(password);
                            }    
                        }
                        do
                        {
                            store g;
                            int ID;
                            string name;
                            string type;
                            int quan;
                            float pri;
                            
                            cout << "Enter the product ID:";
                            cin >> ID;
                            cout << "Enter the product tpye:";
                            cin >> type;
                            cout << "Enter the prodduct name:";
                            cin >> name;
                            cout << "Enter the product quantity:";
                            cin >> quan;
                            cout << "Enter the product price:";
                            cin >> pri;
                            g.addproduct(name, type, ID, quan, pri);
                            cout << " Do you want to continue press y,if no press n:";
                            cin >> ttt;

                        }while(ttt== 'y');
                    }
            }
        }
        break;
        case 2:
        {
                 		User f(1);
            					string name;
            					string email;
                    			string password;
                    		    cout << "Enter your name:"<<endl;
                    		    cin >> name;
                    		    cout<<"Enter your email"<<endl;
                    		    cin>> email;
                    		    cout << "Enter your password:"<<endl;
                    		    cin >> password;
                        	    f.add_new_customer ( name , email , password);
                                Ewallet ee;
                                string cname;
                                int cnum;
                                int ccvv;
                                string typp;
                                float bl;
                                cout << "Enter the name on the card:";
                                cin >> cname;
                                cout << "Enter the type of the card:";
                                cin>> typp;
                                cout << "Enter the number of the card:";
                                cin >> cnum;
                                cout << "Enter the cvv of the card:";
                                cin >> ccvv;
                                cout << "Enter the Balance of the card:";
                                cin >> bl;
                                ee.addinfo(typp, cnum,ccvv,cname,bl);
                                do
                                {
                                    
                                    runn.display();
                                    Cart d11;
                                    do
                                    {
                                        
                                        int qq;
                                        int ann;
                                        cout << "selcet your product and please write its number in the table:";
                                        cin >> qq;
                                        cout << "Enter your quantity:";
                                        cin >> ann;
                                        d11.addProduct(qq,ann);
                                        cout << "if you want to continue shoppping press y, if not press n:";
                                        cin >> yess;
                                    }while (yess == 'y');
                                    d11.displayItems();
                                    cout << "============================================="<< endl;
                                    int vvv;
                                    cout << "Enter your cvv:";
                                    cin >> vvv;
                                    if (f.checkcard(vvv)== -1)
                                        {
                                            while(f.checkcard(vvv)==0)
                                            {
                                                cout << "The cvv is uncorrect" << endl;
                                                cout << "Enter your cvv";
                                                cin >> vv;
                                                f.checkcard(vvv);
                                            }  
                                        }
                                    else
                                        {   
                                            cout << "The cvv is correct" << endl;
                                        }
                                    f.display();
                                    int choice33;
                                    cout << "1-chrage your balane" << endl;
                                    cout << "2-pay" << endl;
                                    cout << "Enter your Choice:";
                                    cin >> choice33;
                                    do
                                    {
                                        
                                        switch (choice33)
                                        {
                                            case 1:
                                            {
                                                int num22;
                                                cout << "Enter the amount you want to add:";
                                                cin >> num22;
                                                f.addbalance(num22);
                                            }
                                            break;
                                            case 2:
                                            {
                                                int num23;
                                                cout << "Enter the amount to paid:";
                                                cin >> num23;
                                                f.pay(num23);
                                            }
                                        }
                                        cout << "if you want to pay or chrage your balance press y, if no press n:";
                                        cin >> Len1;
                                    }while(Len1 == 'y');
                                    cout << "The payment was successful!" << endl;
                                        f.display();
                                    cout << "Do you to shop again press y, if no press n to exit:";
                                    cin >> op1;
                                }while(op1 =='y');
                                    runn.delet(); 
                                    return 0;
						}
                    
    }    
    
}
