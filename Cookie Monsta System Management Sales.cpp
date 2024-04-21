//preprocessor directives
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Define maximum number of transactions
const int MAX_TRANSACTIONS = 70;// Adjust as needed

// Define maximum number of items/transaction
const int MAX_ITEMS_PER_TRANSACTION = 10; // Adjust as needed

// Define the structure to store each item in a transaction
struct TransactionItem {
    string cookieType;
    int quantitySold;
    double pricePerUnit;
};

// DECLARATION of arrays to store sales data
string transactionNo[MAX_TRANSACTIONS];
string customerName[MAX_TRANSACTIONS];
TransactionItem items[MAX_TRANSACTIONS][MAX_ITEMS_PER_TRANSACTION];
int itemsCount[MAX_TRANSACTIONS] = {0}; // Track the number of items in each transaction

// Define the structure to represent a transaction
struct Transaction {
    string transactionNo;
    string customerName;
    TransactionItem items[MAX_ITEMS_PER_TRANSACTION];
    int itemCount; // Track the number of items in the transaction
    double totalRevenue; // Total revenue for the transaction
};

// Array to store all transactions
Transaction transactions[MAX_TRANSACTIONS];

// Function to display cookie types and their corresponding numbers
void displayCookieTypes() {

cout << "\n+========+=========================+=========+" << endl;
cout << "| Number |      Cookie Type        | Prices  |" << endl;
cout << "+========+=========================+=========+" << endl;
cout << "|   1    | Choco Chip              | RM 6.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   2    | Matcha Strawberry       | RM 8.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   3    | Double Chocolate        | RM 7.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   4    | Matcha White Choc Chip  | RM 7.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   5    | Choc And Nut            | RM 8.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   6    | Red Velvet Cheesecake   | RM 8.50 |" << endl;
cout << "+--------+-------------------------+---------+" << endl;
cout << "|   7    | Sea Salt Choc Chip      | RM 6.50 |" << endl;
cout << "+--------+-------------------------+---------+\n" << endl;

}

// Function to record sales
void recordSales() {
    // Find the first available index in the transactions array
    int i = 0;
    while (i < MAX_TRANSACTIONS && !transactions[i].transactionNo.empty()) {
        i++;
    }

    if (i == MAX_TRANSACTIONS) {
        cout << "Maximum number of transactions reached. Unable to record new sales." << endl;
        return;
    }

    // Record transaction number
    transactions[i].transactionNo = "T" + to_string(i + 1);

    // Prompt for customer name
    cout << "\nCustomer Name: ";
    cin >> transactions[i].customerName;

    transactions[i].itemCount = 0; // Initialize item count for this transaction
    transactions[i].totalRevenue = 0.0; // Initialize total revenue for this transaction

    // Prompt for items until the user is done
    char choice;
    do {
        displayCookieTypes(); // Display available cookie types
        int cookieChoice;
        cout << "Select Cookie Type (Enter number 1-7): ";
        while (!(cin >> cookieChoice) || cookieChoice < 1 || cookieChoice > 7) {
            cout << "Invalid choice. Please select a number between 1 and 7." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        cout << "Quantity Sold for Cookie Type " << cookieChoice << ": ";
        int quantity;
        while (!(cin >> quantity) || quantity <= 0) {
            cout << "Invalid quantity. Please enter a positive number." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Record the item for the selected cookie type and quantity
        switch (cookieChoice) {
           	case 1:
                transactions[i].items[transactions[i].itemCount].cookieType = "Choc chip";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 6.50;
                break;
            case 2:
                transactions[i].items[transactions[i].itemCount].cookieType = "Matcha strawberry";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 8.50;
                break;
            case 3:
                transactions[i].items[transactions[i].itemCount].cookieType = "Double Choclate";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 7.50;
                break;
            case 4:
                transactions[i].items[transactions[i].itemCount].cookieType = "Matcha White Choc Chip";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 7.50;
                break;
            case 5:
                transactions[i].items[transactions[i].itemCount].cookieType = "Choc And Nut";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 8.50;
                break;
            case 6:
                transactions[i].items[transactions[i].itemCount].cookieType = "Red Velvet Cheesecake";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 8.50;
                break;
            case 7:
                transactions[i].items[transactions[i].itemCount].cookieType = "Sea Salt Choc Chip";
                transactions[i].items[transactions[i].itemCount].pricePerUnit = 8.50;
                break;
            // Add cases for other cookie types
            default:
                cout << "Invalid choice. Item not recorded." << endl;
                continue; // Skip the rest of the loop and start again
        }

        transactions[i].items[transactions[i].itemCount].quantitySold = quantity;
        transactions[i].itemCount++; // Increment item count for this transaction

        cout << "Do you want to add another cookie type? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Calculate total revenue for this transaction
    for (int j = 0; j < transactions[i].itemCount; ++j) {
        double totalPrice = transactions[i].items[j].quantitySold * transactions[i].items[j].pricePerUnit;
        transactions[i].totalRevenue += totalPrice;
    }
}

//Function to calculate total revenue
void calculateTotalRevenue ()
{
	int totalCookiePurchased = 0;
	double totalRevenue = 0.0;

	for (int i = 0; i < MAX_TRANSACTIONS; ++i)
	{
		for (int j = 0; j < transactions[i].itemCount; ++j)
		{
		 	totalCookiePurchased += transactions[i].items[j].quantitySold;
        	double totalRevenue = transactions[i].items[j].quantitySold * transactions[i].items[j].pricePerUnit;
    	}
    		totalRevenue += transactions[i].totalRevenue;
	}
			// Display total revenue for all cookies and total revenue
			cout << " Total Cookies Purchased : " << totalCookiePurchased << endl;
			cout << " Total Revenue: RM " << fixed << setprecision(2) << totalRevenue << endl;
}

// Function to display all sales records
void displaySalesRecords() {
    cout << " === Total Sales Records ===\n" << endl;

    for (int i = 0; i < MAX_TRANSACTIONS; ++i) {
        if (!transactions[i].transactionNo.empty()) {
            cout << "Transaction No: " << transactions[i].transactionNo << endl;
            cout << "Customer Name: " << transactions[i].customerName << endl;

            // Iterate over items in the transaction
            for (int j = 0; j < transactions[i].itemCount; ++j) {
                cout << "Cookie Type: " << transactions[i].items[j].cookieType << endl;
                cout << "Quantity Sold: " << transactions[i].items[j].quantitySold << endl;
                cout << "Price Per Unit: RM " << fixed << setprecision(2) << transactions[i].items[j].pricePerUnit << endl;

                double totalPrice = transactions[i].items[j].quantitySold * transactions[i].items[j].pricePerUnit;
                cout << "Total Price: RM " << totalPrice << endl;
                cout << "-----------------------------------" << endl;
            }
        }
	}
}

// function updated sales record
void updatedSalesRecord(string searchCustomerName) {
    bool foundCustomer = false;

    // loop through all transactions
    for (int i = 0; i < MAX_TRANSACTIONS; ++i) {
        // check if the current transaction matches the provided customer name
        if (transactions[i].customerName == searchCustomerName) {
            foundCustomer = true;

            // display transaction details
            cout << "Transaction No: " << transactions[i].transactionNo << endl;
            cout << "Customer Name: " << transactions[i].customerName << endl;

            // Display items in the transaction along with their indices
            cout << "Items:" << endl;
            for (int j = 0; j < transactions[i].itemCount; ++j) {
                cout << j+1 << ". Cookie Type: " << transactions[i].items[j].cookieType << endl;
            }

            // Ask the user to select which cookiee quantity to update
            int selectedCookieIndex;
            cout << "Select the number of the cookie to update: ";
            while (!(cin >> selectedCookieIndex) || selectedCookieIndex < 1 || selectedCookieIndex > transactions[i].itemCount) {
                cout << "Invalid choice. Please select a number between 1 and " << transactions[i].itemCount << endl;
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }

            // Adjust index to match array indexing
            selectedCookieIndex--;

            // Ask for new quantity
            int newQuantity;
            cout << "Enter the new quantity sold for " << transactions[i].items[selectedCookieIndex].cookieType << ": ";
            cin >> newQuantity;

            // Update quantity sold for the selected cookie
            transactions[i].items[selectedCookieIndex].quantitySold = newQuantity;

            // Recalculate total revenue for the new transaction
            transactions[i].totalRevenue = 0;
            for (int j = 0; j < transactions[i].itemCount; ++j) {
                double totalPrice = transactions[i].items[j].quantitySold * transactions[i].items[j].pricePerUnit;
                transactions[i].totalRevenue += totalPrice;
            }

            // Display success message
            cout << "Successfully updated." << endl;

            // Exit the loop once the record is updated
            break;
        }
    }

    // If the customer name is not found
    if (!foundCustomer) {
        cout << "The customer name is not found" << endl;
    }
}

// Function to find and display sales records for a specific customer
void findSalesByCustomer(string searchCustomerName)
{
    bool found = false;
    cout << "Sales Records for Customer " << searchCustomerName << ":" << endl;
    for (int i = 0; i < MAX_TRANSACTIONS; ++i)
	{
        if (!transactions[i].transactionNo.empty() && transactions[i].customerName == searchCustomerName)
		{
            found = true;
            cout << "Transaction No: " << transactions[i].transactionNo << endl;
            cout << "Customer Name: " << transactions[i].customerName << endl;

            // Iterate over items in the transaction
            for (int j = 0; j < transactions[i].itemCount; ++j)
			{
                cout << "Cookie Type: " << transactions[i].items[j].cookieType << endl;
                cout << "Quantity Sold: " << transactions[i].items[j].quantitySold << endl;
                cout << "Price Per Unit: RM " << fixed << setprecision(2) << transactions[i].items[j].pricePerUnit << endl;

                double totalPrice = transactions[i].items[j].quantitySold * transactions[i].items[j].pricePerUnit;
                cout << "Total Price: RM " << totalPrice << endl;
                cout << "+-----------------------------------+" << endl;
            }
        }
    }

    if (!found)
	{
        cout << "No sales records found for this customer " << searchCustomerName << endl;
    }
}

int main() {
    // Main function to handle user interaction and menu display
    int choice;
    string searchCustomerName; // Moved declaration outside switch
    string searchTransactionNo; // Moved declaration outside switch

cout <<" +====== Welcome To Cookie Monsta Sales Management Systems! ======+\n";

    // the staff enter their name for record
string Fullname;
    cout << "\nPlease Enter Your Staff Name: ";
    getline (cin, Fullname);
    cout << "\nWelcome, " << Fullname;


    string mainmenu;
    do {
    //The user refer this ASCII table to enter the option
cout << "\n+----------------------------------------+" << endl;
cout << "| COOKIE MONSTA SALES MANAGEMENT SYSTEMS |" << endl;
cout << "+----------------------------------------+" << endl;
cout << "|      1      |       Record Sales       |" << endl;
cout << "|      2      |  Calculate Total Revenue |" << endl;
cout << "|      3      |  Display Sales Records   |" << endl;
cout << "|      4      |  Find Sales By Customer  |" << endl;
cout << "|      5      |   Update Sales Record    |" << endl;
cout << "|      6      |         Exit             |" << endl;
cout << "+----------------------------------------+" << endl;

// the staff enter the number to select the option for menu
    cout << "\n Select The Number (Enter Number 1-6): ";
    cin >> choice;

    // the systems will detect what user choose
     string mainmenu;
      switch (choice) {
        case 1:
            mainmenu = "Record Sales";
             recordSales();
            break;
        case 2:
            mainmenu = "Calculate Total Revenue";
            calculateTotalRevenue () ;
            break;
        case 3:
            mainmenu = "Display Sales Records";
            displaySalesRecords ();
            break;
        case 4:
            cout << " Enter the customer name to be find: ";
            cin >> searchCustomerName;
            findSalesByCustomer(searchCustomerName);
            break;
        case 5:
            cout << " Enter the customer name to be update: ";
            cin >> searchCustomerName;
             updatedSalesRecord(searchCustomerName);
            break;
        case 6:
            mainmenu = "Thank you for using COOKIE MONSTA Sales Management System!\n";
            break;

            //if the systems detect other from the option will get error message
            default:
            cout << "Invalid Choice, Please try again\n"<< endl;
            break;

    }

    cout << "\nYou Select "<< mainmenu << endl;

    } while (choice != 6);

    return 0;

}
