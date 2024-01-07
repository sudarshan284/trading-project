#include <bits/stdc++.h>
using namespace std;

class Account
{
    int dogeCoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int dogeCoin_value;
    int bitcoin_value;
    int crypto_invest;
    int crypto_return;
    vector<pair<string, int>> transactions;

public:
    bool Deposit(int money)
    {
        deposit += money;
        balance += money;
        transactions.push_back({"Deposited", money});
        return true;
    }
    void Get_account_information()
    {
        cout << "Money Details: \n";
        cout << "Bank Balance" << balance << endl;
        cout << "Dogecoin:" << dogeCoin << endl;
        cout << "Bitcoin:" << bitcoin << endl;
    }

    bool Withdraw(int money)
    {
        if (money > balance)
        {
            return false;
        }

        withdraw += money;
        balance += money;
        transactions.push_back({"Withdrawal: ", money});
        return true;
    }
    // Buy Crypto
    bool buy_crypto()
    {
        int option;
        cout << "Want to purchase dogecoin press 1 else "
                "for bitcoin press 2\n";
        cin >> option;

        if (total_equity != 0)
        {
            srand(time(NULL));
            int luck = rand();

            if (luck % 251 == 0)
            {
                if (option == 1)
                {
                    dogeCoin += 1;
                    balance -= dogeCoin_value;
                    crypto_invest += (dogeCoin)*dogeCoin_value;
                }
                else
                {
                    bitcoin += 1;
                    balance -= bitcoin_value;
                    crypto_invest += bitcoin_value;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        return true;
    }
    bool sell_crypto()
    {
        int option;
        cout << "Want to sell dogecoin press 1 else for "
                "bitcoin press 2\n";
        cin >> option;

        if (option == 2)
        {
            if (bitcoin == 0)
                return false;
            crypto_return += bitcoin_value;
            balance += bitcoin_value;
            transactions.push_back(
                {"Bitcoin Sold:", bitcoin_value});
            bitcoin -= 1;
        }
        else
        {
            if (dogeCoin == 0)
                return false;
            crypto_return += dogeCoin_value;
            balance += dogeCoin_value;
            transactions.push_back(
                {"Dogecoin Sold:", dogeCoin_value});
            dogeCoin -= 1;
        }
        return true;
    }

    void History()
    {
        cout << "Displaying All transactions\n";
        for (auto it : transactions)
        {
            cout << it.first << " " << it.second << endl;
        }

        char temp;
        cout << "Do you want to clear all transactions:";
        cin >> temp;

        int no = transactions.size();

        // Clearing All transactions
        if (temp == 'Y')
        {
            transactions.clear();
            cout << "Total transactions cleared:" << no
                 << endl;
        }
        else
        {
            cout << "Total transaction:" << no << endl;
        }
    }

    Account()
    {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;

        balance = 50000;
        dogeCoin = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        dogeCoin_value = 100;
        bitcoin_value = 500;
    }
};

int main()
{

    Account person;
    int amount, choice;
    bool check;
    while (1)
    {

        cout << "  "
                "******************************************"
                "*****************************  \n";

        cout << endl;
        cout << "Press 1 if want to have your Account Info "
             << endl;
        cout << "Press 2 if want to Deposit your money "
             << endl;
        cout << "Press 3 if want to withdraw your money "
             << endl;
        cout << "Press 4 if want to know your history "
             << endl;
        cout << "Press 5 if want to know your Buy Crypto "
             << endl;
        cout << "Press 6 if want to know your Sell Crypto "
             << endl;
        cout << "Else press any invalid key for exit \n"
             << endl;

        cout << "  "
                "******************************************"
                "*****************************  \n";

        cin >> choice;
        int ans;

        switch (choice)
        {
        case 1:
            person.Get_account_information();
            break;

        case 2:
            cout << "Enter amount to deposit : ";
            cin >> amount;
            ans = person.Deposit(amount);
            if (ans)
                cout << "Successfully deposited money"
                     << endl;
            else
                cout << "Failed\n";

            break;

        case 3:
            cout << "Enter amount to withdrawn : ";
            cin >> amount;
            ans = person.Withdraw(amount);

            if (ans)
                cout << "Successfully withdrawn Amount"
                     << endl;
            else
                cout << "Not Enough Balance\n";

            break;

        case 4:
            person.History();
            break;

        case 5:
            ans = person.buy_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Better Luck next time\n";
            break;

        case 6:
            ans = person.sell_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Not Enough CryptoCoin\n";
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}