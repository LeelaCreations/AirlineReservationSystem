// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include"Database.h"
#include<sstream>

using namespace std;
using namespace AirlineReseravtion;
int DisplayMenu();
void addFlight(Database& db);
void getFlightSchedule(Database& db);
void getPassengerInfo(Database& db);
vector<string> split(string str, string sep);
char ch;
int main()
{

	Database flightDB;
	while (true)
	{
		int selection = DisplayMenu();
		switch (selection)
		{
		case 1:
			addFlight(flightDB);
			break;
		case 2:
			getFlightSchedule(flightDB);
			break;
		case 3:
			flightDB.displayAllFlights();
			break;
		case 4:
			getPassengerInfo(flightDB);
			break;
		case 5:
			break;
		case 6:
			return 0;			
		}
	}
}
int DisplayMenu()
{
	int selection;
	cout << endl;
	cout << "=================== Welcome to Airline Reservation System =======================" << endl;
	cout << "        1. Reserve a seat" << endl;
	cout << "        2. Flight Schedule" << endl;
	cout << "        3. All Flight Details" << endl;
	cout << "        4. Display Passenger Info" << endl;
	cout << "        5. User Ticket Information" << endl;
	cout << "        6. Exit the Menu" << endl;
	cout << "=================================================================================" << endl;

	cin >> selection;
	return selection;

}
void addFlight(Database& db)
{
	string flightNumber;
	string airways;
	string source;
	string destination;
	int availableSeats;
	string departureDate;
	string departureTime;
	string arrivalDate;
	string arrivalTime;
	int numberofStops;
	vector<string> stopLocation;
	vector<int> stopDuration;
	
	cout << "flightNumber :";
	cin >> flightNumber;

	cout << "airways :";
	cin >> airways;

	cout << "source :";
	cin >> source;

	cout << "destination :";
	cin >> destination;

	cout << "availableSeats :";
	cin >> availableSeats;

	cout << "departureDate :";	
	cin >> departureDate;	
	
	cout << "departureTime :";
	cin >> departureTime;

	cout << "arrivalDate :";
	cin >> arrivalDate;	

	cout << "arrivalTime :";
	cin >> arrivalTime;

	cout << "numberofStops :";
	cin >> numberofStops;
	if (numberofStops > 0) {
		string stoploc;
		int stopdur;
		for (int i = 0; i < numberofStops; i++)
		{
			cout << "enter the" << i + 1 << "th stop location :";
			cin >> stoploc;
			stopLocation.push_back(stoploc);

			cout << "enter the" << i + 1 << "th stop duration :";
			cin >> stopdur;
			stopDuration.push_back(stopdur);

		}
	}
	db.addFlight(flightNumber, airways, source, destination, availableSeats, departureDate, departureTime, arrivalDate, arrivalTime, numberofStops, stopLocation, stopDuration);
}
//split function
vector<string> split(string str, string sep) {
	char* cstr = const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current = strtok_s(cstr, sep.c_str(),NULL);
	while (current != NULL) {
		arr.push_back(current);
		current = strtok_s(NULL, sep.c_str(),NULL);
	}
	return arr;
}
void getFlightSchedule(Database& db)
{
	string flightNumber;
	cout<< "Please enter the Flight Number"<<endl;
	cin >> flightNumber;
	Flight flight= db.getFlightSchedule(flightNumber);
	cout << "FlightNumber : " << flight.getFlightNumber()<<endl;
	cout << "Airways : " << flight.getAirWays() << endl;
	cout << "Source : " << flight.getSource() << endl;
	cout << "Destination : " << flight.getDestination() << endl;
	cout << "Available Seats : " << flight.getAvailableSeats() << endl;
	cout << "Departure Date : " << flight.getDepartureDate()<<" "<<flight.getDepartureTime() << endl;
	cout << "Arrival Date : " << flight.getArrivalDate() << " " << flight.getArrivalTime() << endl;
	int stops = flight.getNumberOfStops();
	cout << "Number of Stops : " << stops << endl;
	auto& stopLocation = flight.getStopLocation();
	auto& stopDuration = flight.getStopDuration();
	for (int i = 0; i < stops; i++)
	{
		cout << "Stop Location :" << stopLocation[i] << " Duration :" << stopDuration[i] << "Minutes" << endl;
	}
		
}
void getPassengerInfo(Database& db)
{
	string emailId;
	cout << "Please enter the emailID" << endl;
	cin >> emailId;
	Passenger passenger = db.getPassengerInfo(emailId);
	cout << "First Name: " << passenger.getFirstName()<<endl;
	cout << "Last Name: " << passenger.getLastName()<<endl;
	cout << "Gender: " << passenger.getGender() << endl;
	cout << "Address: " << passenger.getAddress() << endl;
	cout << "City: " << passenger.getCity() << endl;
	cout << "State: " << passenger.getState() << endl;
	cout << "PostalCode: " << passenger.getPostalCode() << endl;
	cout << "Phone Number: " << passenger.getPhoneNumber() << endl;


}