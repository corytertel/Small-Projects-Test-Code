#include <cstdio>
#include <stdexcept>

enum class AccountDatabaseType {
    InMemory,
};

struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void set_amount(unsigned long long acc_id, unsigned long long amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    InMemoryAccountDatabase() = default;
    ~InMemoryAccountDatabase() = default;

    void set_amount(unsigned long long acc_id, unsigned long long amount) override {
        printf("Setting account %llu to $%llu\n", acc_id, amount);   
    }
};

struct Bank {
    //Constructor
    Bank(AccountDatabaseType ad_type) {
        switch(ad_type) {
        case AccountDatabaseType::InMemory: {
            account_database = new InMemoryAccountDatabase;
        } break;
        default: {
            throw std::logic_error("Unknown AccountDatabaseType");
        } }
    }

    //Destructor
    ~Bank() {
        delete account_database;
    }

    //Copy Constructor
    Bank(const Bank& other) = default;

    //Move Constructor
    Bank(Bank&& other) noexcept = default;

    //Copy Assignment Operator
    Bank& operator=(const Bank& other) = default;

    //Move Assignment Operator
    Bank& operator=(Bank&& other) noexcept = default;

    //Sets Amount of a Bank Account
    void set_amount(unsigned long long acc_id, unsigned long long amount) {
        account_database->set_amount(acc_id, amount);
    }

private:
    AccountDatabase* account_database;
};

int main(int argc, char** argv) {
    Bank bank{ AccountDatabaseType::InMemory };
    bank.set_amount(0L, 50);
    bank.set_amount(2L, 100);
    return 0;
}
