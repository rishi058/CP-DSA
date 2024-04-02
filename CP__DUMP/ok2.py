import csv
import random

# CSV file name
csv_file = 'bank_accounts.csv'

def load_accounts():
    """
    Load accounts from the CSV file into the bank_accounts dictionary.
    This version accounts for the header row in the CSV.
    """
    try:
        with open(csv_file, mode='r', newline='') as file:
            reader = csv.DictReader(file)
            return {int(row["Account Number"]): {"name": row["Account Holder Name"], "balance": float(row["Balance"])} for row in reader}
    except FileNotFoundError:
        return {}

def save_account(account_number, name, initial_balance):
    """
    Save a new account to the CSV file, considering the existence of the header.
    """
    try:
        with open(csv_file, mode='r+', newline='') as file:
            # Check if file is empty or has a header
            first_char = file.read(1)
            if not first_char: # File is empty
                writer = csv.writer(file)
                writer.writerow(["Account Number", "Account Holder Name", "Balance"]) # Write header
                writer.writerow([account_number, name, initial_balance])
            else:
                file.seek(0, 2) # Go to the end of the file
                writer = csv.writer(file)
                writer.writerow([account_number, name, initial_balance])
    except FileNotFoundError:
        with open(csv_file, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(["Account Number", "Account Holder Name", "Balance"]) # Write header
            writer.writerow([account_number, name, initial_balance])

def generate_unique_account_number(bank_accounts):
    while True:
        account_number = random.randint(10000000, 99999999)
        if account_number not in bank_accounts:
            return account_number

def create_account(name, initial_balance, bank_accounts):
    account_number = generate_unique_account_number(bank_accounts)
    bank_accounts[account_number] = {'name': name, 'balance': initial_balance}
    save_account(account_number, name, initial_balance)
    print(f"\nAccount created successfully!\nAccount Number: {account_number}\nName: {name}\nInitial Balance: ${initial_balance}")

def main():
    print("Welcome to the Bank Account Creation System")
    bank_accounts = load_accounts()

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
            create_account(name, initial_balance, bank_accounts)
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
