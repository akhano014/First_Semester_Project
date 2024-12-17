#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

long long int getValidatedLongLong(int maxlength, int minlength)
{
    string input;
    long long result;

    while (true)
    {
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(" \t\n\r") == string::npos)
        {
            cout << "\tEmpty input. Please enter a valid number: ";
            continue;
        }

        stringstream ss(input);
        if (ss >> result && ss.eof())
        {

            if (input.length() == maxlength && input.length() == minlength)
            {
                return result;
            }
            else
            {
                cout << "\tError... Invalid Input ... Try again: ";
            }
        }
        else
        {
            cout << "\tInvalid input. Please enter a valid number: ";
        }
    }
}
long int getvalidatedlongInt()
{
    string input;
    double result;

    while (true)
    {
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(" \t\n\r") == string::npos)
        {
            cout << "\tEmpty input. Please enter a valid PIN: ";
            continue;
        }

        stringstream ss(input);
        if (ss >> result && ss.eof())
        {

            if (input.length() == 4)
            {
                return result;
            }
            else
            {
                cout << "\tYour PIN should comsist of 4 digits: ";
            }
        }
        else
        {
            cout << "\tInvalid input. Please enter a valid PIN: ";
        }
    }
}
string getValidatedString()
{
    string input;

    while (true)
    {
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(" \t\n\r") == string::npos)
        {
            cout << "\tEmpty input. Please enter a valid input: ";
            continue;
        }

        return input;
    }
}


void createAccount(string& name, long long int& phoneNumber, long long& cnic, int& pass, string& mail)
{
    cout << "\tEnter Your Name: ";
    name = getValidatedString();

    cout << "\tEnter Your Phone Number (11 digits): ";
    phoneNumber = getValidatedLongLong(11, 11);

    cout << "\tEnter Your Email: ";
    mail = getValidatedString();

    cout << "\tEnter Your CNIC (13 digits): ";
    cnic = getValidatedLongLong(13, 13);

    cout << "\tSet Your 4 digit Account PIN: ";
    pass = getvalidatedlongInt();
}

double withdraw(double& money)
{
    double withdrawAmount;
    cout << endl;

    cout << "\tEnter amount you want to withdraw: ";
    cin >> withdrawAmount;
    if (withdrawAmount < 0)
    {
        cout << "\tPlease enter valid amount";
        return 0;
    }
    cout << "\tAmount withdraw: " << fixed << setprecision(2) << withdrawAmount << endl;

    if (withdrawAmount <= money)
    {
        money -= withdrawAmount;
        cout << "\tYour current balance: " << fixed << setprecision(2) << money << endl;
    }
    else
    {
        cout << "\tLow account balance..." << endl;
    }
    cout << endl;

    return money;
}

double deposit(double& money)
{
    double depositAmount;
    cout << endl;

    cout << "\tEnter amount you want to deposit: ";
    cin >> depositAmount;
    if (depositAmount < 0)
    {
        cout << "\tPlease enter valid amount";
        return 0;
    }
    else
    {
        cout << "\tAmount deposit: " << fixed << setprecision(2) << depositAmount << endl;
        money += depositAmount;
        cout << "\tYour current balance: " << fixed << setprecision(2) << money << endl;
    }
    cout << endl;

    return money;
}

double fundTransfer(double& money)
{
    double transferAmount;
    double transferAccountNumber;
    cout << endl;
    cout << "\tEnter amount you want to transfer: ";
    cin >> transferAmount;
    if (transferAmount < 0)
    {
        cout << "\tPlease enter valid amount";
        return 0;
    }
    cout << "\tEnter account number in which you want to transfer: ";
    cin >> transferAccountNumber;

    if (money >= transferAmount)
    {
        money -= transferAmount;
        cout << "\t** Fund transferred ** " << endl;
    }
    else
    {
        cout << "\tLow account balance..." << endl;
    }
    cout << "\tYour current balance: " << fixed << setprecision(2) << money << endl;
    cout << endl;

    return money;
}

void totalBalance(double money)
{
    cout << "\n\tYour total balance after the transactions: " << fixed << setprecision(2) << money << endl;
    cout << endl;
}

bool deactivateAccount(long long& cnic, int& pass, bool& accountActive, double& amount)
{
    long long checkCnic;
    int checkPass;
    cout << "\tEnter CNIC: ";
    cin >> checkCnic;
    cout << "\tEnter PIN: ";
    cin >> checkPass;
    cout << endl;

    if (amount != 0)
    {
        cout << "\t!Error...Please withdraw all your amount before deactivation of your account" << endl;
        cout << "\t" << endl;
        return false;
    }
    else if (checkCnic == cnic && checkPass == pass)
    {
        accountActive = false;
        cout << "\tYour account has been deactivated successfully." << endl;
        cout << "\t****Thank you for using our Bank****" << endl;
        exit(0);
    }
    else
    {
        cout << "\tInvalid CNIC or PIN. Deactivation failed..." << endl;
        return false;
    }
    cout << endl;
}
void loanmanage(double& amount)
{
    if (amount < 30000)
    {
        cout << "\n\t**Low bank balance!... You are not eligible for a loan" << endl;
    }
    else
    {
        if (amount >= 30000 && amount < 60000)
        {
            cout << "\tYou are eligible for 100,000 of a loan" << endl;
        }
        else if (amount >= 60000 && amount < 100000)
        {
            cout << "\tYou are eligible for 200,000 of a loan" << endl;
        }
        else if (amount >= 100000 && amount < 150000)
        {
            cout << "\tYou are eligible for 500,000 of a loan" << endl;
        }
        else if (amount >= 150000)
        {
            cout << "\tYou are eligible for 700,000 of a loan" << endl;
        }
    }
}
long double loanamount(double& amount, int& count)
{
    char choice;
    char payback;
    long double paybackAmount;

    cout << "\n\t**You cannot apply for a loan more than 5 times" << endl;
    cout << endl;
    for (int i = 1; i <= 5; ++i)
    {
        cout << "\tpress x to exit or any other key to cointinue: ";
        cin >> choice;
        if (choice == 'x' || choice == 'X')
        {
            cout << "\t**Exited Successfully" << endl;
            exit(0);
        }
        cout << "\t\t Application no: " << i << endl;
        cout << endl;
        if (amount >= 30000 && amount < 60000)
        {
            amount += 100000;
            cout << "\tLoan of " << "100000" << " approved. New balance: " << fixed << setprecision(2) << amount << endl;
            count++;
        }
        else if (amount >= 60000 && amount < 100000)
        {
            amount += 200000;
            cout << "\tLoan of " << "200000" << " approved. New balance: " << fixed << setprecision(2) << amount << endl;
            count++;
        }
        else if (amount >= 100000 && amount < 150000)
        {
            amount += 500000;
            cout << "\tLoan of " << "500000" << " approved. New balance: " << fixed << setprecision(2) << amount << endl;
            count++;
        }
        else if (amount >= 150000)
        {
            amount += 700000;
            cout << "\tLoan of " << "700000" << " approved. New balance: " << fixed << setprecision(2) << amount << endl;
            count++;
        }
        else
        {
            cout << "\t**Loan request denied.Please ensure you meet the eligibility criteria." << endl;
        }
    }
    cout << "\t*Loan proccess completed*" << endl;

    return amount;
}
long double loanInterest(double& amount)
{
    double interestRate;
    double interest;
    double interestAmount;
    if (amount >= 110000 && amount < 130000)
    {
        cout << "\tNo interest rate will be applied";
        amount -= 100000;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }
    if (amount >= 130000 && amount < 160000)
    {
        cout << "\tInterest rate will be 5% " << endl;
        interestRate = 5;
        interest = amount * (interestRate / 100);
        interestAmount = 100000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;
    }
    else if (amount >= 160000 && amount < 260000)
    {
        cout << "\tInterest rate will be 10% " << endl;
        interestRate = 10;
        interest = amount * (interestRate / 100);
        interestAmount = 100000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }
    else if (amount >= 260000 && amount < 360000)
    {
        cout << "\tInterest rate will be 15% " << endl;
        interestRate = 10;
        interest = amount * (interestRate / 100);
        interestAmount = 200000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }
    else if (amount >= 360000 && amount < 500000)
    {
        cout << "\tInterest rate will be 18% " << endl;
        interestRate = 15;
        interest = amount * (interestRate / 100);
        interestAmount = 300000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }
    else if (amount >= 500000 && amount < 600000)
    {
        cout << "\tInterest rate will be 20% " << endl;
        interestRate = 18;
        interest = amount * (interestRate / 100);
        interestAmount = 400000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }
    else if (amount >= 600000)
    {
        cout << "\tInterest rate will be 25% " << endl;
        interestRate = 20;
        interest = amount * (interestRate / 100);
        interestAmount = 450000 + interest;
        amount -= interestAmount;
        cout << "\tYour total amount after paying back loan : " << fixed << setprecision(2) << amount << endl;;
    }

    return amount;
}

int main()
{
    string name, mail;
    int pass;
    long long cnic, phoneNumber;
    int option;
    double amount = 0;
    char checkBalance, loan;
    bool accountActive = true;
    char choice;
    int count = 0, count1 = 0, count2 = 0, count3 = 0;

    long long checkCnic;
    int checkPass;
    char Choice;

    cout << "\033[31m";
    cout << endl;
    cout << "\t  __        __   _                            _____       ____              _      __  __                                              _     ____            _                  " << endl;
    cout << "\t  \\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__   | __ )  __ _ _ __ | | __ |  \\/  | __ _ _ __   __ _  __ _ _ __ ___   ___ _ __ | |_  / ___| _   _ ___| |_ ___ _ __ ___   " << endl;
    cout << "\t   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\  |  _ \\ / _` | '_ \\| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` | '_ ` _ \\ / _ \\ '_ \\| __| \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  " << endl;
    cout << "\t    \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) | | |_) | (_| | | | |   <  | |  | | (_| | | | | (_| | (_| | | | | | |  __/ | | | |_   ___) | |_| \\__ \\ ||  __/ | | | | | " << endl;
    cout << "\t     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|   |_|\\___/  |____/ \\__,_|_| |_|_|\\_\\ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |_| |_| |_|\\___|_| |_|\\__| |____/ \\__, |___/\\__\\___|_| |_| |_| " << endl;
    cout << "\t                                                                                                           |___/                                  |___/                        " << endl;
    cout << "\033[0m";


    cout << "\033[31m";
    cout << "\t\t\t\t\t/==============================================================================================\\" << endl;
    cout << "\t\t\t\t\t||  ____            _     _             _   _               ____                               ||" << endl;
    cout << "\t\t\t\t\t|| |  _ \\ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __   |  _ \\ _ __ ___   ___ ___  ___ ___  ||" << endl;
    cout << "\t\t\t\t\t|| | |_) / _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\  | |_) | '__/ _ \\ / __/ _ \\/ __/ __| ||" << endl;
    cout << "\t\t\t\t\t|| |  _ <  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | | |  __/| | | (_) | (_|  __/\\__ \\__ \\ ||" << endl;
    cout << "\t\t\t\t\t|| |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_| |_|   |_|  \\___/ \\___\\___||___/___/ ||" << endl;
    cout << "\t\t\t\t\t||           |___/                                                                             ||" << endl;
    cout << "\t\t\t\t\t/==============================================================================================/" << endl;
    cout << "\033[0m";

    cout << " " << endl;
    createAccount(name, phoneNumber, cnic, pass, mail);
    cout << endl;

    cout << "\t*********************************" << endl;
    cout << "\t*\t\t\t\t*" << endl;
    cout << "\t*\tACCOUNT DETAILS\t\t*" << endl;
    cout << "\t*\t\t\t\t*" << endl;
    cout << "\t*********************************" << endl;
    cout << "\t" << endl;
    cout << endl;
    cout << "\tYour name: " << name << endl;
    cout << "\tYour phone number: +92" << phoneNumber << endl;
    cout << "\tYour Email: " << mail << endl;
    cout << "\tYour CNIC: " << cnic << endl;
    cout << "\tYour account PIN: " << pass << endl;
    cout << endl;
    cout << " " << endl;
    cout << "\t*Your account has been created successfully*" << endl;
    cout << "\t\t\t***" << endl;
    cout << endl;
    cout << "\tEnter initial deposit for transactions: ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "\tPlease enter valid amount";
        return 0;
    }
    else
    {
        cin.ignore();
        cout << "" << endl;
        cout << "\t*************************" << endl;
        cout << "\t*\t\t\t*" << endl;
        cout << "\t*\t  LOGIN\t\t*" << endl;
        cout << "\t*\t\t\t*" << endl;
        cout << "\t*************************" << endl;
        cout << endl;
        cout << "\tEnter CNIC: ";
        cin >> checkCnic;
        cout << "\tEnter Your PIN: ";
        cin >> checkPass;
        cin.ignore();
        cout << "" << endl;
        if (checkCnic != cnic || checkPass != pass)
        {
            cout << "\t** Wrong CNIC or password **" << endl;
            return 0;
        }
        cout << "" << endl;
        cout << "\t\t  SELECT YOUR TRANSACTION" << endl;
        cout << "" << endl;
        do
        {
            cout << "\t*************************************************" << endl;
            cout << "\t* Press 1 to withdraw\t\t\t\t*" << endl;
            cout << "\t* Press 2 to Deposit\t\t\t\t*" << endl;
            cout << "\t* Press 3 to transfer funds\t\t\t*" << endl;
            cout << "\t* Press 4 to Deactivate account\t\t\t*" << endl;
            cout << "\t* Press 5 to see your transaction history\t*" << endl;
            cout << "\t* Press 0 to exit\t\t\t\t*" << endl;
            cout << "\t*\t\t\t\t\t\t*" << endl;
            cout << "\t*************************************************" << endl;
            cout << " " << endl;
            cout << "\tEnter your choice: ";
            cin >> option;
            cin.ignore();

            {
                switch (option)
                {
                case 1:
                    amount = withdraw(amount);
                    count++;
                    break;
                case 2:
                    amount = deposit(amount);
                    count1++;
                    break;
                case 3:
                    amount = fundTransfer(amount);
                    count2++;
                    break;
                case 4:
                    if (deactivateAccount(cnic, pass, accountActive, amount))
                    {
                        break;
                    }
                    break;
                case 5:
                    cout << endl;
                    cout << "\t***** TRANSACTION HISTORY ******" << endl;
                    cout << "\n\tNumber of Withdrawals: " << count;
                    cout << "\n\tNumber of Deposits: " << count1;
                    cout << "\n\tNumber of Funds transfer: " << count2 << endl;
                    cout << endl;
                    cout << "\t\t*******************" << endl;
                    cout << " " << endl;
                    break;

                case 0:
                    cout << "\tExited Successfully..." << endl;
                    cout << " " << endl;
                    break;
                default:
                    cout << "\tInvalid option... Kindly select from above options." << endl;
                    cout << " " << endl;
                    break;
                }
            }
            if (!accountActive)
            {
                cout << "\tAccount deactivated. Press x to exit: " << endl;
                cin >> Choice;
                cin.ignore();
            }


        } while (option != 0);

        cout << "\n\tDo you want to check your current balance (y/n): " << endl;
        cin >> checkBalance;

        if (checkBalance == 'y' || checkBalance == 'Y')
        {
            totalBalance(amount);
        }

        cout << "\tDo you want to apply for a loan (y/n): " << endl;
        cin >> loan;

        if (loan == 'y' || loan == 'Y') {
            if (!accountActive) {
                cout << "\n\t** Your bank account is deactivated... You cannot apply for a loan. **" << endl;
            }
            else {
                if (amount >= 30000) {
                    cout << "" << endl;
                    cout << "\t\t   LOAN APPLICATION " << endl;
                    cout << "" << endl;
                    cout << endl;

                    loanmanage(amount);
                    loanamount(amount, count3);
                }
                else {
                    cout << "\t** Minimum balance required = 30,000 **" << endl;
                    cout << "\t** Your Balance is below 30,000. Loan request denied. **" << endl;
                    exit(0);
                }


                cout << "\n\tDo you want to pay back the loan amount (y/n) : " << endl;
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    loanInterest(amount);
                }
                else {
                    cout << "\n\tYou have not selected to pay back the loan at this time." << endl;
                }
            }
        }
        else {
            cout << "\tLoan application process skipped." << endl;
        }

        cout << "\n\n\t\t\t*****$*****" << endl;
        cout << "\t\t BANK STATEMENT " << endl;
        cout << "" << endl;
        cout << endl;
        cout << "\t********* Account status***********" << endl;
        if (accountActive == true) {
            cout << "\t***********Active ***********" << endl;
        }
        else
            cout << "\tDeactivated ***********" << endl;
        cout << endl;
        cout << "\t**************** TRANSACTION HISTORY ******" << endl;
        cout << "\n\tNumber of Withdrawals: " << count;
        cout << "\n\tNumber of Deposits: " << count1;
        cout << "\n\tNumber of Funds transfer: " << count2 << endl;
        cout << endl;
        cout << "\t\t*******************" << endl;
        cout << "   " << endl;
        cout << "\t*********** Loan Status ***********" << endl;
        cout << "\tNumber of loans applied: " << count3;
        cout << "   " << endl;
    }

    return 0;
}