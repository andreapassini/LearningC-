#include "iostream"
#include "vector"

class Animal{
private:
    std::string name;
public:
    void Eat(const Animal& prey){

    }
};

class Player{
    std::string name;
    int health;
    int xp;

    void Talk(std::string text_to_say);
    bool is_dead();

};

class Account{
    double balance;

    bool Withdraw(double amount);
    bool Deposit(double amount);

public:
    std::string name;
};

int main(){
/*
    Player frank;
    Player hero;

    Player *enemy = new Player();
    free(enemy);
*/
    Account frank_account;

    Account jim_account;
    jim_account.name;

    Account* my_account = new Account();
    my_account->name;
    (*my_account).name;



    free(my_account);

    Account accounts[] {frank_account, jim_account};
    std::vector<Account> accountsVec {frank_account};
    accountsVec.push_back(jim_account);



}