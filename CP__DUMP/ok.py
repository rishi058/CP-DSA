import random

# This dictionary will store the bank accounts
bank_accounts = {}

def create_account(name, initial_balance):
    account_number = generate_unique_account_number()
    
    bank_accounts[account_number] = {'name': name, 'balance': initial_balance}
    
    print(f"\nAccount created successfully!\nAccount Number: {account_number}\nName: {name}\nInitial Balance: ${initial_balance}")
    return account_number

def generate_unique_account_number():
    while True:
        account_number = random.randint(10000000, 99999999)
        if account_number not in bank_accounts:
            return account_number

def main():
    print("Welcome to the Bank Account Creation System")
    while True:
        print("\nMain Menu:")
        print("1. Create a new bank account")
        print("2. View all accounts")
        print("3. Exit")
        user_choice = input("Please select an option (1-3): ")
        
        if user_choice == "1":
            name = input("Enter the account holder's name: ")
            while True:
                try:
                    initial_balance = float(input("Enter the initial balance: $"))
                    break
                except ValueError:
                    print("Invalid amount. Please enter a valid number.")
            create_account(name, initial_balance)
        elif user_choice == "2":
            if bank_accounts:
                print("\nAll accounts:")
                for account_number, info in bank_accounts.items():
                    print(f"Account Number: {account_number}, Name: {info['name']}, Balance: ${info['balance']}")
            else:
                print("\nNo accounts to display.")
        elif user_choice == "3":
            print("Thank you for using the Bank Account Creation System. Goodbye!")
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    main()
