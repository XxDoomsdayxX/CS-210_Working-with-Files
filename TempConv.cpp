/*
 * TempConv.cpp
 *
 * Date: 02/10/2024
 * Author: Darrell Walker II
 * 
 */



#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Creates a function to convert Fahrenheit to Celsius.
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    // Opens the file from which we want to read the data.
    ifstream inputFile("FahrenheitTemperature.txt");

    // Check if the file is successfully opened.
    if (!inputFile.is_open()) {
        cout << "Unable to open file FahrenheitTemperature.txt";
        return 1;
    }

    //Creates and opens a new file, for the data to be stored in.
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if the output file is successfully opened.
    if (!outputFile.is_open()) {
        cout << "Unable to create output file CelsiusTemperature.txt";
        return 1;
    }

    //Variables to store the data from the file we're reading.
    string city;
    int temperature;
    double celsius;

    // Read data from the file.
    while (!inputFile.eof() && !inputFile.fail()) {
        inputFile >> city;
        inputFile >> temperature;

        //Converts the temperature using the function.
        celsius = fahrenheitToCelsius(temperature);

        //Stores the new data in the file we created.
        outputFile << setprecision(4) << city << " " << celsius << "°C" << endl;

    }

    // Close both the files.
    inputFile.close();
    outputFile.close();

    cout << "Data successfully written to CelsiusTemperature.txt" << endl;

    return 0;
}