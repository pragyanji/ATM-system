#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdio>
using namespace std;

struct user
{
    int amount, age, userid, otp, atm_balance;
    string name, acc_type, address, atmpin;
} r;

class ATM
{
public:
    string dta[1000];

public:
    void home_page()
    {
        system("color 05");
        cout << "\t\t\t\t\t* * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * *" << endl;
        cout << "\t\t\t\t\t*============================================================*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*||               WEL-COME TO OUR ATM SYSTEM               ||*" << endl;
        cout << "\t\t\t\t\t*||         !  Where Convenience Meets Security  !         ||*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*||    Created & Designed by:                              ||*" << endl;
        cout << "\t\t\t\t\t*||    ----------------------                              ||*" << endl;
        cout << "\t\t\t\t\t*||    @ Pragyan Pandey                                    ||*" << endl;
        cout << "\t\t\t\t\t*||    @ Arina Tuladhar                                    ||*" << endl;
        cout << "\t\t\t\t\t*||    @ Uttam Mukhiya                                     ||*" << endl;
        cout << "\t\t\t\t\t*||    @ Pinky Kumari                                      ||*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*||           PRESS ANY KEY TO ENTER OUR SYSTEM            ||*" << endl;
        cout << "\t\t\t\t\t*||                                                        ||*" << endl;
        cout << "\t\t\t\t\t*============================================================*" << endl;
        cout << "\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * *" << endl;
    }

    void ATM_homepage()
    {
        system("color 04");
        cout << "\t\t\t\t\t\t\t _____________________________________ " << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|      [1]. Admin                     |" << endl;
        cout << "\t\t\t\t\t\t\t|      [2]. User                      |" << endl;
        cout << "\t\t\t\t\t\t\t|      [3]. Exit                      |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|_____________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t\tENTER YOUR CHOICE:";
    }

    void user_homepage()
    {

        cout << "\t\t\t\t\t\t\t _____________________________________ " << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|      [1]. Create new account        |" << endl;
        cout << "\t\t\t\t\t\t\t|      [2]. Login                     |" << endl;
        cout << "\t\t\t\t\t\t\t|      [3]. Search account            |" << endl;
        cout << "\t\t\t\t\t\t\t|      [4]. Delete account            |" << endl;
        cout << "\t\t\t\t\t\t\t|      [5]. Balance Transfer          |" << endl;
        cout << "\t\t\t\t\t\t\t|      [6]. Exit                      |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|_____________________________________|" << endl;
    }

    void datetime()
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << "\t\t\t\tDATE & TIME: " << dt;
    }

    void write_file(string id)
    {
        string fln = id + ".txt";
        ofstream o;
        o.open(fln);
        o << r.userid << "\t"
          << r.atmpin << "\t"
          << r.name << "\t"
          << r.age << "\t"
          << r.address << "\t"
          << r.acc_type << "\t"
          << r.amount;
        o.close();

        ofstream b;
        b.open("ATM_balance.txt");
        b << r.atm_balance;
        b.close();
    }

    void read_file(string id)
    {
        ifstream p;
        string data;
        p.open(id);
        getline(p, data);
        p.close();
        split(data);
        r.userid = stoi(dta[0]);
        r.atmpin = dta[1];
        r.name = dta[2];
        r.age = stoi(dta[3]);
        r.address = dta[4];
        r.acc_type = dta[5];
        r.amount = stoi(dta[6]);

        ifstream b;
        string money;
        b.open("ATM_balance.txt");
        getline(b, money);
        b.close();
        r.atm_balance = stoi(money);
    }

    void split(string str)
    {
        int a = 0;
        for (int i = 0; i < str.length(); i++)
        {
            string b = "";
            while (str[i] != '\t' && i < str.length())
            {
                b += str[i];
                i++;
            }
            dta[a] = b;
            a++;
        }
    }

    void W_rcpt(int amnt)
    {
        system("CLS");
        cout << endl;
        cout << "\t\t\t\t\t\tTRANSACTION RECEIPT" << endl;
        cout << "\t\t\t\t\t\tPRAGYAN BANK";
        cout << endl
             << endl;
        datetime();
        cout << endl;
        cout << endl;
        cout << "\t\t\t\tWITHDRAW AMOUNT: " << amnt << endl;
        // cout << "\t\t\t\tTRANSACTION CHARGE: 0.00" << endl;
        cout << "\t\t\t\tREMAINING BALANCE: " << r.amount << endl
             << endl;
        cout << "\t\t\t\tThank you for using our ATM" << endl;
    }

    void D_rcpt(int amnt)
    {
        system("CLS");
        cout << endl;
        cout << "\t\t\t\t\t\tTRANSACTION RECEIPT" << endl;
        cout << "\t\t\t\t\t\tPRAGYAN BANK";
        cout << endl
             << endl;
        datetime();
        cout << endl;
        cout << endl;
        cout << "\t\t\t\tDEPOSIT AMOUNT: " << amnt << endl;
        // cout << "\t\t\t\tTRANSACTION CHARGE: 0.00" << endl;
        cout << "\t\t\t\tTOTAL BALANCE: " << r.amount << endl
             << endl;
        cout << "\t\t\t\tThank you for using our ATM" << endl;
    }

    void T_rcpt(int amnt, string suid, string ruid)
    {
        system("CLS");
        cout << endl;
        cout << "\t\t\t\t\t\tTRANSACTION RECEIPT" << endl;
        cout << "\t\t\t\t\t\tPRAGYAN BANK";
        cout << endl
             << endl;
        datetime();
        cout << endl;
        cout << endl;
        cout << "\t\t\t\tTRANSFER AMOUNT: " << amnt << endl;
        cout << "\t\t\t\t" << amnt << " amount Transferred to the user " << ruid << " from user " << suid << endl;
        cout << "\t\t\t\tREMAINING BALANCE: " << r.amount << endl
             << endl;
        cout << "\t\t\t\tThank you for using our ATM" << endl;
    }

    void user_id()
    {

        string pp;
        ifstream file("Userid.txt");
        if (!file)
        {
            ofstream p("Userid.txt");
            p << 10001;
            p.close();

            ifstream ppp("Userid.txt");
            getline(ppp, pp);
            ppp.close();
            cout << "Your User ID is :" << pp << endl;
            r.userid = stoi(pp);
            int b = stoi(pp);
            b++;
            p.open("Userid.txt");
            p << b;
            p.close();
        }
        else
        {
            ifstream ppp("Userid.txt");
            getline(ppp, pp);
            ppp.close();
            cout << "Your User ID is :" << pp << endl;
            r.userid = stoi(pp);
            int b = stoi(pp);
            b++;
            ofstream p("Userid.txt");
            p << b;
            p.close();
        }
    }

    void transaction()
    {
        cout << endl
             << endl
             << "Your transaction is being processed ";
        for (int i = 0; i < 6; i++)
        {

            cout << "."
                 << " ";
            Sleep(500);
        }
        cout << endl
             << endl
             << endl;
    }

    void otpp()
    {
        srand(time(NULL));
        r.otp = (rand() % 999999) + 100000; // Generates OTP
        cout << endl
             << "Your OTP is:";
        cout << r.otp << endl
             << endl;
        cout << "Do not share it with anyone." << endl;
    }
};

class Admin
{
private:
    ATM obj00;

public:
    int admin_pin = 1234, atm_amount;
    string admin_id = "admin";

    void admin_page()
    {

        cout << "\t\t\t\t\t\t\t _____________________________________ " << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|      [1]. Show ATM Balance          |" << endl;
        cout << "\t\t\t\t\t\t\t|      [2]. Add Balance in ATM        |" << endl;
        cout << "\t\t\t\t\t\t\t|      [3]. User Details              |" << endl;
        cout << "\t\t\t\t\t\t\t|      [4]. Exit                      |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t\t|_____________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t\tENTER YOUR CHOICE:";
    }

    void add_balance()
    {
        int t_amount;
        string ppp;

        ifstream file("ATM_balance.txt");
        if (!file)
        {
            ofstream p("ATM_balance.txt");
            p << 100000;
            p.close();

            ifstream prev;
            prev.open("ATM_balance.txt");
            getline(prev, ppp);
            cout << endl
                 << endl
                 << "ATM remaining Balance is:" << stoi(ppp);
            cout << endl
                 << endl
                 << "Enter the Deposit amount:";
            cin >> atm_amount;
            if (atm_amount < 1000)
            {
                cout << "\nDeposit Amount cannot be less than 1000 !!!";
            }
            else
            {
                ifstream pp("ATM_balance.txt");
                getline(pp, ppp);
                t_amount = stoi(ppp) + atm_amount;

                ofstream pa("ATM_balance.txt");
                pa << to_string(t_amount);
                pa.close();
                cout << endl
                     << endl
                     << "ATM Balance added successfully." << endl;

                cout << endl
                     << endl
                     << "New ATM Balance is:" << t_amount;
            }
        }
        else
        {
            ifstream prev;
            prev.open("ATM_balance.txt");
            getline(prev, ppp);
            cout << endl
                 << endl
                 << "ATM remaining Balance is:" << stoi(ppp);
            cout << endl
                 << endl
                 << "Enter the Deposit amount:";
            cin >> atm_amount;
            if (atm_amount < 1000)
            {
                cout << "\nDeposit Amount cannot be less than 1000 !!!";
            }
            else
            {
                ifstream p("ATM_balance.txt");
                getline(p, ppp);
                p.close();
                t_amount = stoi(ppp) + atm_amount;

                ofstream pa("ATM_balance.txt");
                pa << to_string(t_amount);
                pa.close();
                cout << endl
                     << endl
                     << "ATM Balance added successfully." << endl;

                cout << endl
                     << endl
                     << "New ATM Balance is:" << t_amount;
            }
        }
    }

    void show_atm_balance()
    {
        string ppp;
        cout << endl
             << endl;
        obj00.datetime();
        ifstream prev;
        prev.open("ATM_balance.txt");
        getline(prev, ppp);
        cout << endl
             << endl
             << "\t\t\t\tATM  Balance is:" << stoi(ppp);
    }

    void show_user_detail()
    {
        string data;
        string filename = "User_details.txt";
        ifstream file(filename);
        if (file.peek() == ifstream::traits_type::eof())
        {
            cout << "No Users to show." << endl;
        }
        else
        {
            cout << endl
                 << endl;
            obj00.datetime();
            cout << "___________________________________________________" << endl;
            cout << "User_iD   User_name\tAge    Address   Acc_Type " << endl;
            cout << "___________________________________________________" << endl
                 << endl;

            while (getline(file, data))
            {
                cout << data << endl
                     << endl;
            }
            cout << "___________________________________________________" << endl;
        }

        file.close();
    }

    void save_user_details()
    {
        ifstream file("User_details.txt", ios::app | ios::out);

        if (!file)
        {
            ofstream outfile("User_details.txt", ios::app | ios::out);

            outfile << r.userid << "\t"
                    << r.name << "\t"
                    << r.age << "\t"
                    << r.address << "\t"
                    << r.acc_type << endl;
            outfile.close();
        }
        else
        {
            ofstream file("User_details.txt", ios::app | ios::out);

            file << r.userid << "\t"
                 << r.name << "\t"
                 << r.age << "\t"
                 << r.address << "\t"
                 << r.acc_type << endl;
            file.close();
        }
    }

    void delete_user_details(string id)
    {
        string filename = "User_details.txt";
        string searchId = id;

        ifstream inputFile(filename);

        string line;
        int lineNumber = 0;
        bool found = false;

        while (getline(inputFile, line))
        {
            lineNumber++;

            if (line.find(searchId) != string::npos)
            {
                found = true;
                break;
            }
        }

        inputFile.close();

        int lineToDelete = lineNumber;

        ifstream in(filename);

        ofstream tempFile("temp.txt");

        string linee;
        int lineNum = 0;

        while (getline(in, linee))
        {
            lineNum++;

            if (lineNum != lineToDelete)
            {
                tempFile << linee << endl;
            }
        }

        in.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }
};

class User
{

private:
    ATM obj0;
    Admin obj4;

public:
    int dpamount, wdamount;

    void pinchange(string usr)
    {
        int cpin, newpin;

        cout << endl
             << endl
             << "Enter the current PIN:";
    takepin:
        cpin = getch();
        string enpin;
        while (cpin != 13)
        {
            enpin.push_back((char)cpin);
            cout << "*";
            cpin = getch();
        }
        int b = enpin.length();
        if (b < 4 || b > 4)
        {
            cout << endl
                 << endl
                 << "PIN must be 4 digits:";

            goto takepin;
        }
        if (enpin == r.atmpin)
        {
            cout << endl
                 << endl
                 << "Enter the new PIN:";
        takepin1:
            newpin = getch();
            string compin;
            while (newpin != 13)
            {
                compin.push_back((char)newpin);
                cout << "*";
                newpin = getch();
            }
            int c = compin.length();
            if (c < 4 || c > 4)
            {
                cout << endl
                     << endl
                     << "PIN must be 4 digits:";
                goto takepin1;
            }
            
            r.atmpin = compin;
            cout << endl
                 << endl
                 << "PIN changed successfully" << endl;
            obj0.write_file(usr);
            cout << endl
                 << endl
                 << endl
                 << "Press any key to continue." << endl;
            _getch();
        }
        else
        {
            cout << endl
                 << "Incorrect PIN !!!!!" << endl;
            cout << "Please re-enter the current PIN:";
            goto takepin;
        }
    }

    void deposit(string fln)

    {
        char Rcpt;
        cout << endl
             << endl
             << "Enter the Deposit amount:";
    rd:
        cin >> dpamount;
        if (dpamount <= 0)
        {
            cout << "Deposit amount should be greater than zero !!!" << endl
                 << endl;
            cout << "Re-Enter the deposit amount: ";
            goto rd;
        }
        else
        {
            obj0.transaction();
            r.amount = r.amount + dpamount;
            cout << "Deposit successful." << endl;

            cout << "Do you want to receive receipt(y/n):";
            cin >> Rcpt;
            if (Rcpt == 'y' || Rcpt == 'Y')
            {
                system("color 7F");
                obj0.D_rcpt(dpamount);
            }
            else if (Rcpt == 'n' || Rcpt == 'N')
            {
                cout << dpamount << " amount Deposited successfully." << endl
                     << endl;
                cout << "Thank you for using our ATM." << endl;
            }

            //  cout << "Your new balance is:" << r.amount << endl;
            obj0.write_file(fln);

            cout << endl
                 << "Press any key to continue." << endl;
            _getch();
        }
    }

    void search()
    {
        string uidd;
        int key;

        cout << endl
             << endl
             << "Enter the User ID:";

        cin.ignore();
    takeuid:
        getline(cin, uidd);
        string fln = uidd + ".txt";
        ifstream file(fln);
        if (!file)
        {
            cout << endl
                 << endl
                 << "Entered user ID doesn't exist !!! " << endl
                 << endl;
            cout << "Re-enter the user ID:";
            goto takeuid;
        }
        obj0.read_file(fln);
        cout << endl
             << "Enter PIN:";
    ttake:
        key = getch();
        string epin;
        while (key != 13)
        {
            epin.push_back((char)key);
            cout << "*";
            key = getch();
        }
        int b = epin.length();
        if (b < 4 || b > 4)
        {
            cout << endl
                 << endl
                 << "PIN must be 4 digits:";

            goto ttake;
        }
        if (r.atmpin == epin)
        {
            cout << endl
                 << endl
                 << "User ID"
                 << "\t\t"
                 << "Name"
                 << "\t\t\t"
                 << "Type"
                 << "\t\t"
                 << "Age"
                 << "\t\t"
                 << "Balance" << endl;
            cout << r.userid << "\t\t" << r.name << "\t\t"
                 << r.acc_type << "\t\t" << r.age << "\t\t" << r.amount << endl
                 << endl;
            cout << "Press any key to continue." << endl;
            _getch();
        }
        else
        {
            cout << endl
                 << endl
                 << "Incorrect PIN !!!!!" << endl
                 << endl;
            cout << "Please re-enter the PIN:";
            goto ttake;
        }
    }

    void setpin()
    {
        int abc;
        string newpin;

        cout << "Enter the  OTP:";
    take:
        cin >> abc;
        if (abc == r.otp)
        {

            cout << endl
                 << "Set a 4 digit PIN:";
        pin:
            cin >> newpin;
            // string a = to_string(newpin);
            int length = newpin.length();
            if (length == 4)
            {
                r.atmpin = newpin;
                cout << "PIN setup successfully." << endl
                     << endl;
            }

            else
            {
                cout << "!!! Invalid Input !!!" << endl
                     << endl;
                cout << "Re-enter the PIN:";
                goto pin;
            }
        }
        else
        {
            int A = 1;
            if (A > 3)
            {
                cout << "You have entered wrong OTP 3 times !!!" << endl;
                cout << "Further process Terminated due to security reason" << endl;
                exit(0);
            }
            cout << endl
                 << "Incorrect OTP!!!" << endl
                 << endl;
            cout << "Re-enter the OTP";
            A++;
            goto take;
        }
    }

    void balanceinquiry(string fln)
    {
        system("color 7F");
        cout << endl;
        cout << "\t\t\t\t\t\tTRANSACTION RECEIPT" << endl;
        cout << "\t\t\t\t\t\t  BALANCE ENQUIRY" << endl
             << endl;
        cout << "\t\t\t\t\t      BANK NAME: PRAGYAN BANK" << endl
             << endl;
        obj0.datetime();
        obj0.read_file(fln);
        cout << "\t\t\t\tACCOUNT HOLDER'S NAME:" << r.name << endl
             << endl;
        cout << "\t\t\t\tAVAILABLE BALANCE is:" << r.amount << endl
             << endl
             << endl
             << endl;
        cout << "Press any key to continue." << endl;
        _getch();
    }

    void deleteacc()
    {
        int aa;
        string uid;
        int key;
        cout << endl
             << endl
             << "Enter the User ID:";
        cin.ignore();
    takeuidd:
        getline(cin, uid);
        string fln = uid + ".txt";
        ifstream file(fln);
        if (!file)
        {
            cout << endl
                 << "Entered user ID doesn't exist !!! " << endl
                 << endl;
            cout << "Re-enter the user ID:";

            goto takeuidd;
        }
        file.close();
        obj0.read_file(fln);
        cout << endl
             << "Enter PIN:";
    ptake:
        key = getch();
        string epin;
        while (key != 13)
        {
            epin.push_back((char)key);
            cout << "*";
            key = getch();
        }

        int b = epin.length();
        if (b < 4 || b > 4)
        {
            cout << endl
                 << endl
                 << "PIN must be 4 digits:";

            goto ptake;
        }
        if (r.atmpin == epin)
        {
            cout << endl
                 << endl
                 << "User ID"
                 << "\t\t"
                 << "Name"
                 << "\t\t\t"
                 << "Type"
                 << "\t\t"
                 << "Age"
                 << "\t\t"
                 << "Balance" << endl;
            cout << r.userid << "\t\t" << r.name << "\t\t"
                 << r.acc_type << "\t\t" << r.age << "\t\t" << r.amount << endl;

            char a;
            cout << endl
                 << "Do you wanna delete this account (y/n)?";
            cin >> a;
            const char *flnn = fln.c_str();
            if (a == 'y' || a == 'Y')
            {
                if (remove(flnn) != 0)
                {
                    cout << endl
                         << "Error deleting account!!!" << endl
                         << endl
                         << endl;
                    cout << "Press any key to continue." << endl;
                    _getch();
                }
                else
                {
                    cout << endl
                         << "Account deleted successfully." << endl
                         << endl
                         << endl;

                    obj4.delete_user_details(uid);

                    cout << "Press any key to continue." << endl;
                    _getch();
                }
            }
            else
            {
                cout << endl
                     << "Your account is safe. " << endl
                     << endl
                     << endl;
                cout << "Press any key to continue." << endl;
                _getch();
            }
        }
        else
        {
            cout << endl
                 << endl
                 << "Incorrect PIN !!!!!" << endl;
            cout << endl
                 << "Please re-enter the PIN:";
            goto ptake;
        }
    }

    void transfer()
    {
        string susrid, rusrid;
        int key, tamount;
        char trcpt;
        cout << endl
             << "Enter the sender User ID:";
    takesusrid:
        cin >> susrid;
        string sfln = susrid + ".txt";
        ifstream sfile(sfln);
        if (!sfile)
        {
            cout << endl
                 << endl
                 << "Entered user ID doesn't exist !!! " << endl
                 << endl;
            cout << "Re-enter the user ID:";

            goto takesusrid;
        }
        sfile.close();
        obj0.read_file(sfln);
        cout << endl
             << "Enter PIN:";
    got:
        key = getch();

        string epin;
        while (key != 13)
        {
            epin.push_back((char)key);
            cout << "*";
            key = getch();
        }

        int b = epin.length();
        if (b < 4 || b > 4)
        {
            cout << endl
                 << endl
                 << "PIN must be 4 digits:";

            goto got;
        }

        if (r.atmpin == epin)
        {
            cout << endl
                 << endl
                 << "Your Balance is:" << r.amount << endl;
            cout << endl
                 << "Enter the receiver User ID:";
        takerusrid:
            cin >> rusrid;

            string rfln = rusrid + ".txt";
            ifstream rfile(rfln);
            if (!rfile)
            {
                cout << endl
                     << "Entered user ID doesn't exist !!! " << endl
                     << endl;
                cout << "Re-enter the user ID:";

                goto takerusrid;
            }
            else
            {
                cout << endl
                     << "Enter the transfer amount:";
            takeblnc:
                cin >> tamount;
                obj0.read_file(sfln);
                if (tamount < r.amount)
                {
                    obj0.read_file(rfln);
                    r.amount = r.amount + tamount;
                    obj0.write_file(rusrid);

                    obj0.read_file(sfln);
                    r.amount = r.amount - tamount;

                    cout << "\nDo you want to receive receipt(y/n):";
                    cin >> trcpt;
                    if (trcpt == 'y' || trcpt == 'Y')
                    {
                        system("color 7F");
                        obj0.T_rcpt(tamount, susrid, rusrid);
                    }
                    else if (trcpt == 'n' || trcpt == 'N')
                    {
                        cout << endl
                             << "Rs." << tamount << " is transferred successfully." << endl;
                        cout << endl
                             << "Your New balance is:" << r.amount << endl
                             << endl;
                        cout << "Thank you for using our ATM." << endl;
                    }

                    obj0.write_file(susrid);
                }
                else
                {
                    cout << endl
                         << endl
                         << "Insufficient Balance to transfer!!!" << endl
                         << endl;
                    cout << "Re-Enter the balance:";
                    goto takeblnc;
                }
            }
            rfile.close();
        }
        else
        {
            cout << endl
                 << endl
                 << "Incorrect PIN!!!" << endl
                 << endl;
            cout << "Re-enter PIN:";
            goto got;
        }
        cout << endl
             << endl
             << "Press any key to continue." << endl;
        _getch();
    }

    void fastcash()
    {
        system("CLS");

        cout << "\t\t\t\t\t\t _____________________________________ " << endl;
        cout << "\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t|  [1]. 500               [4]. 5000   |" << endl;
        cout << "\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t|  [2]. 1000              [5]. 10000  |" << endl;
        cout << "\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t|  [3]. 2000              [6]. 15000  |" << endl;
        cout << "\t\t\t\t\t\t|                                     |" << endl;
        cout << "\t\t\t\t\t\t|_____________________________________|" << endl
             << endl;

        cout << "\t\t\tENTER YOUR CHOICE:";
    }

    void withdraw(string uname, int amt)
    {
        char receipt;
        obj0.transaction();
        if (amt <= r.amount && amt <= r.atm_balance)
        {
            r.amount = r.amount - amt;
            r.atm_balance = r.atm_balance - amt;
            cout << "Do you wanna receive receipt(y/n):";
            cin >> receipt;
            if (receipt == 'y' || receipt == 'Y')
            {
                system("color 7F");
                obj0.W_rcpt(amt);
            }
            else if (receipt == 'n' || receipt == 'N')
            {
                cout << amt << endl
                     << " amount withdrawl successfully." << endl
                     << endl;
                cout << "Thank you for using our ATM." << endl;
            }
            obj0.write_file(uname);

            cout << endl
                 << endl
                 << "Press any key to continue." << endl;
            _getch();
        }
        else if (amt > r.amount || amt > r.atm_balance)
        {
            if (amt > r.amount && amt > r.atm_balance)
            {
                cout << endl
                     << endl
                     << "!!! Insufficient Balance in your Account and ATM !!!" << endl;

                cout << endl
                     << endl
                     << "Press any key to continue." << endl;
                _getch();
            }

            else if (amt > r.amount)
            {
                cout << endl
                     << endl
                     << "!!! Insufficient Balance in your account !!!" << endl;

                cout << endl
                     << endl
                     << "Press any key to continue." << endl;
                _getch();
            }
            else if (amt > r.atm_balance)
            {
                cout << endl
                     << endl
                     << "!!! Insufficient Balance in the ATM !!!" << endl;

                cout << endl
                     << endl
                     << "Press any key to continue." << endl;
                _getch();
            }
        }
    }

    void create_acc()
    {
        char a;
        do
        {
            system("color 0E");
            cout << endl
                 << "Enter the following data:" << endl
                 << endl;
            cout << "Full Name:";
            cin.ignore();
            getline(cin, r.name);
            cout << endl
                 << "Age:";
            cin >> r.age;
            if (r.age < 18)
            {
                cout << "You are under age." << endl;
                cout << "Sorry you cannot create account." << endl;
                exit(0);
            }
            else
            {
                cout << endl
                     << "Address:";
                cin.ignore();
                getline(cin, r.address);
                cout << endl
                     << "Account type:";
                // cin.ignore();
                getline(cin, r.acc_type);

                cout << endl
                     << "!!! Deposite should be atleast 1000 rupees !!!" << endl
                     << endl
                     << "Deposite amount:";
            amt:
                cin >> r.amount;
                if (r.amount < 1000)
                {
                    cout << endl
                         << "Deposite should be atleast Thousand !!!!" << endl;
                    cout << endl
                         << "Re-enter the Deposit amount:";
                    goto amt;
                }
                cout << endl
                     << endl;
                obj0.otpp();
                cout << endl
                     << endl;
                setpin();
                cout << endl
                     << endl;

                obj0.user_id();

                obj0.write_file(to_string(r.userid));

                obj4.save_user_details();

                cout << endl
                     << endl
                     << "Do you want to add another [y/n]:";
                cin >> a;
            }

        } while (a == 'y');
    }
};

int main()
{
    ATM obj1;
    Admin obj2;
    User obj3;

    int choice, Atmchoice, adminchoice, key;
    static int B = 0;
    system("CLS");
    obj1.home_page();
    _getch();
gett:
    system("CLS");
    obj1.ATM_homepage();

    cin >> Atmchoice;

    if (Atmchoice == 1)
    {
        system("CLS");

        string login_id;
        int pass;
        cout << endl
             << "Enter the login_id:";
        cin.ignore();
    getid:
        getline(cin, login_id);
        if (login_id != obj2.admin_id)
        {
            cout << endl
                 << "Entered login_id is incorrect" << endl;
            cout << endl
                 << "Re-enter the Login_id:";
            goto getid;
        }
        else
        {
            cout << endl
                 << "Enter login_pin:";
        logkey:
            pass = getch();
            string password;
            while (pass != 13)
            {
                password.push_back((char)pass);
                cout << "*";
                pass = getch();
            }

            int passkey = password.length();
            if (passkey != 4)
            {
                cout << endl
                     << endl
                     << "Login PIN must be of 4 digits:";
                goto logkey;
            }

            if (stoi(password) == obj2.admin_pin)
            {
                cout << endl;
            tgate:
                system("CLS");
                obj2.admin_page();

                cin >> adminchoice;
                switch (adminchoice)
                {
                case 1:
                    obj1.transaction();
                    system("CLS");
                    obj2.show_atm_balance();
                    cout << endl
                         << endl
                         << "Press any key to continue." << endl;
                    _getch();
                    goto tgate;
                    break;
                case 2:
                    obj1.transaction();
                    system("CLS");
                    obj2.add_balance();
                    cout << endl
                         << endl
                         << "Press any key to continue." << endl;
                    _getch();
                    goto tgate;
                    break;
                case 3:
                    obj1.transaction();
                    system("CLS");
                    cout << endl
                         << "\t\t\tUser Details:" << endl
                         << endl;
                    obj2.show_user_detail();
                    cout << endl
                         << endl
                         << "Press any key to continue." << endl;
                    _getch();
                    goto tgate;
                    break;
                case 4:
                    goto gett;
                }
            }
            else
            {
                cout << endl
                     << "Entered login_pin is incorrect." << endl;
                cout << endl
                     << "Please Re-enter the login_pin:";
                goto logkey;
            }
        }
    }
    else if (Atmchoice == 2)
    {
    take1:
        system("CLS");
        system("color A0");
        obj1.user_homepage();
        cout << "\t\t\tENTER YOUR CHOICE:";
        cin >> choice;

        if (choice == 1)
        {
            system("CLS");
            cout << endl;
            obj3.create_acc();
            goto take1;
        }
        else if (choice == 2)
        {
            int key;
            string urid;

            cout << endl
                 << endl
                 << "Enter your user ID:\n ";
            cin.ignore();
        get:
            getline(cin, urid);
            string fln = urid + ".txt";
            ifstream file(fln);
            if (!file)
            {
                cout << "Entered user ID doesn't exist !!! " << endl
                     << endl;
                cout << "Re-enter the user ID:";
                goto get;
            }
            else
            {
                obj1.read_file(fln);
                cout << endl
                     << "Enter pin:" << endl;
            take3:
                key = getch();
                string enteredPin;
                while (key != 13)
                {
                    enteredPin.push_back((char)key);
                    cout << "*";
                    key = getch();
                }
                int keypin = enteredPin.length();
                if (keypin < 4 || keypin > 4)
                {
                    cout << endl
                         << endl
                         << "PIN must be 4 digits:" << endl;
                    goto take3;
                }

                if (enteredPin == r.atmpin)
                {

                take4:
                    system("CLS");
                    system("color A0");
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\t\t _____________________________________ " << endl;
                    cout << "\t\t\t\t\t\t\t|                                     |" << endl;
                    cout << "\t\t\t\t\t\t\t|                                     |" << endl;
                    cout << "\t\t\t\t\t\t\t|                                     |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [1]. Balance Inquiry           |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [2]. Fast Cash                 |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [3]. Cash Withdrawl            |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [4]. Cash Deposit              |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [5]. Pin Change                |" << endl;
                    cout << "\t\t\t\t\t\t\t|      [6]. Log out                   |" << endl;
                    cout << "\t\t\t\t\t\t\t|                                     |" << endl;
                    cout << "\t\t\t\t\t\t\t|                                     |" << endl;
                    cout << "\t\t\t\t\t\t\t|_____________________________________|" << endl
                         << endl;
                    cout << "\t\t\tENTER YOUR CHOICE:";

                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        system("CLS");
                        obj1.transaction();
                        obj3.balanceinquiry(fln);
                        goto take4;
                        break;

                    case 2:
                        obj1.transaction();
                        obj3.fastcash();
                        int b;
                        cin >> b;
                        if (b == 1)
                        {
                            obj3.withdraw(urid, 500);
                            goto take4;
                        }

                        else if (b == 3)
                        {
                            obj3.withdraw(urid, 2000);
                            goto take4;
                        }

                        else if (b == 2)
                        {
                            obj3.withdraw(urid, 1000);
                            goto take4;
                        }

                        else if (b == 4)
                        {
                            obj3.withdraw(urid, 5000);
                            goto take4;
                        }

                        else if (b == 5)
                        {
                            obj3.withdraw(urid, 10000);
                            goto take4;
                        }

                        else if (b == 6)
                        {
                            obj3.withdraw(urid, 15000);
                            goto take4;
                        }
                        break;
                        // obj2.save_user_details();

                    case 3:
                        obj1.transaction();
                    here:
                        cout << endl
                             << endl;
                        cout << "Enter the amount you want to withdraw:";
                        cin >> obj3.wdamount;

                        obj3.withdraw(urid, obj3.wdamount);
                        goto take4;

                        break;

                    case 4:
                        obj1.transaction();
                        obj3.deposit(urid);
                        goto take4;
                        break;

                    case 5:
                        obj1.transaction();
                        obj3.pinchange(urid);
                        goto take4;
                        break;
                    case 6:
                        goto take1;
                        break;
                    default:
                        cout << "Invalid input!!!!!" << endl;
                        goto take4;
                        break;
                    }
                }

                else
                {
                    ++B;
                    if (B > 2)
                    {
                        cout << "You have entered wrong pin 3 times !!!" << endl;
                        cout << "Try again after 15 minutes." << endl;
                        Sleep(500000);
                        exit(0);
                    }
                    cout << endl
                         << "Incorrect pin!!" << endl;
                    cout << endl
                         << "Re-enter the pin:";

                    goto take3;
                }
            }
        }
        else if (choice == 3)
        {
            system("CLS");
            obj1.transaction();
            obj3.search();
            goto take1;
        }
        else if (choice == 4)
        {
            system("CLS");
            obj1.transaction();
            obj3.deleteacc();
            goto take1;
        }
        else if (choice == 5)
        {
            system("CLS");
            obj1.transaction();
            obj3.transfer();
            goto take1;
        }
        else if (choice == 6)
        {
            goto gett;
        }
        else
        {
            cout << "Invalid input!!!!";
            goto take1;
        }
    }
    else
    {
        system("CLS");
        system("color D6");
        cout << endl
             << endl
             << endl
             << "\t\t\t\tThank you for using our ATM.";
        exit(0);
    }
}
