// This program will use multiple functions to calculate the amount of money to deposit in
// a savings account in order to obtain a specified amount of money in a number of years.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std ;

double readFutureValue() ;  // Prototype for the function that will read and validate the future value input.
double readInterestRate() ;  // Prototype for the function that will read and validate the annual interest rate input.
int readNumberOfYears() ;  // Prototype for the function that will read and validate the number of years input.
double presentValue( double, double, int ) ;  // Prototype for the function that will calculate the present value of money deposited.
void displayResults( double, double, double, int ) ; // Prototype for the function that will display the results to the user.

    // Main function.
int main()
{
        // Declare variables used for this function.
    double futureValue ;  // To hold the amount of money that will be obtained in the future after receiving interest.
    double interestRate ;  // To hold the rate at which the deposited money will increase each year.
    int numberYears ;  // To hold the number of years that the deposited money will be left in the savings account.
    double presentDeposit;  // To hold the amount of money to deposit today.

        // Call the function for reading and validating the future value input and store the returned value.
    futureValue = readFutureValue() ;

        // Call the function for reading and validating the annual interest rate input and store the returned value.
    interestRate = readInterestRate() / 100.0 ;  // Convert the value to a decimal of the percentage.

        // Call the function for reading and validating the number of years input and store the returned value.
    numberYears = readNumberOfYears() ;

        // Call the function for calculating the present value of money deposited and store the returned value.
    presentDeposit = presentValue( futureValue, interestRate, numberYears ) ;

        // Call the function that will display the results of the calculations to the user.
    displayResults( presentDeposit, futureValue, interestRate, numberYears ) ;

    return 0 ;
}

    // Function for reading and validating the future value input.
double readFutureValue()
{
        // Declare variables.
    double futureValue ;  // To hold the amount of money that will be obtained in the future after receiving interest.

        // Ask the user to enter the future value.
    cout << "Enter future value" ;
    cin >> futureValue ;
    cout << endl ;

        // Validate the input
    while ( futureValue <= 0.0 )
    {
            // Display error message.
        cout << "The future value must be greater than zero" << endl ;

            // Ask the user to enter the future value again.
        cout << "Enter future value" ;
        cin >> futureValue ;
        cout << endl ;
    }

        // Return the entered value to the calling function.
    return futureValue ;
}

    // Function for reading and validating the annual interest rate input.
double readInterestRate()
{
        // Declare variables.
    double interestRate ;  // To hold the rate at which the deposited money will increase each year.

        // Ask the user to enter the annual interest rate.
    cout << "Enter annual interest rate" ;
    cin >> interestRate ;
    cout << endl ;

        // Validate the input.
    while ( interestRate <= 0.0 )
    {
            // Display error message.
        cout << "The annual interest rate must be greater than zero" << endl ;

            // Ask the user to enter the annual interest rate again.
        cout << "Enter annual interest rate" ;
        cin >> interestRate ;
        cout << endl ;
    }

        // Return the entered value to the calling function.
    return interestRate ;
}

    // Function for reading and validating the number of years input.
int readNumberOfYears()
{
        // Declare variables.
    int numberYears ;  // To hold the number of years that the deposited money will be left in the savings account.

        // Ask the user to enter the number of years.
    cout << "Enter number of years" ;
    cin >> numberYears ;
    cout << endl ;

        // Validate the input.
    while ( numberYears <= 0.0 )
    {
            // Display error message.
        cout << "The number of years must be greater than zero" << endl ;

            // Ask the user to enter the number of years again.
        cout << "Enter number of years" ;
        cin >> numberYears ;
        cout << endl ;
    }

        // Return the entered value to the calling function.
    return numberYears ;
}

    // Function for calculating the present value of money deposited.
double presentValue( double futureValue, double interestRate, int numberYears )
{
        // Declare variables.
    double presentDeposit ;  // To hold the amount of money to deposit today.

        // Calculate the present value of money deposited.
    presentDeposit = futureValue /  pow( interestRate + 1.0 , numberYears )  ;

        // Return the result to the calling function.
    return presentDeposit ;
}

    // Function for displaying the inputted and calculated results to the user.
void displayResults( double presentDeposit, double futureValue, double interestRate, int numberYears )
{
        // Set desired output formatting for numbers.
    cout << setprecision(2) << fixed << showpoint ;

        // Display the present and future values to the user.
    cout << "Present value: $" << presentDeposit << endl ;
    cout << "Future value: $" << futureValue << endl ;

        // Set desired output formatting for numbers.
    cout << setprecision(3) << fixed << showpoint ;

        // Display the annual interest rate and number of years to the user.
    cout << "Annual interest rate: " << ( interestRate * 100.0 ) << "%" << endl ;
    cout << "Years: " << numberYears << endl ;
}
