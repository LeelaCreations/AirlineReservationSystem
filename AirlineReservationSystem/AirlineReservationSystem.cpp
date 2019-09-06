// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include"Database.h"
#include<sstream>
#include<time.h>
using namespace std;
using namespace AirlineReseravtion;
int DisplayMenu();
void addFlight(Database& db);
void getFlightSchedule(Database& db);
void getPassengerInfo(Database& db);
void getTicketInfo(Database& db);
void reserveSeat(Database& db);
bool dateValidation(string date);
bool timevalidation(string time);
bool flightNumberValidation(string flightNumber);
vector<string> split(string str, string sep);
char ch;
int call = 0;
char seatletter[] = { 'A','B','C','D','E','F' };
int confirmationId;
Database flightDB;
int main()
{
	
	while (true)
	{
		int selection = DisplayMenu();
		switch (selection)
		{
		case 1:
			reserveSeat(flightDB);
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
			getTicketInfo(flightDB);
			break;
		case 6:
			addFlight(flightDB);
			break;
		case 7:
			return 0;
		}
	}
}
int DisplayMenu()
{
	srand(time(NULL));
	int selection;
	cout << endl;
	cout << "=================== Welcome to Airline Reservation System =======================" << endl;
	cout << "        1. Reserve a seat" << endl;
	cout << "        2. Flight Schedule" << endl;
	cout << "        3. All Flight Details" << endl;
	cout << "        4. Display Passenger Info" << endl;
	cout << "        5. User Ticket Information" << endl;
	cout << "        6. Add Flight" << endl;
	cout << "        7. Exit the Menu" << endl;
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
	if (flightNumberValidation(flightNumber)) { cout << "Flight Number already exists. Please enter unique number"; return; }
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
	if (dateValidation(departureDate)) {
		cout << "Please enter the valida date";
		return;
	}
	cout << "departureTime :";
	cin >> departureTime;

	cout << "arrivalDate :";
	cin >> arrivalDate;	
	if (dateValidation(arrivalDate)) {
		cout << "Please enter the valida date";
		return;
	}
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
	cout << "Please enter the emailID: ";
	cin >> emailId;
	vector<Passenger> passengers = db.getPassengerInfo(emailId);
	if (passengers.empty()) { cout << "No passenger exists with the email id"; return; }
	for (const auto& passenger : passengers) {
		cout << "First Name: " << passenger.getFirstName() << endl;
		cout << "Last Name: " << passenger.getLastName() << endl;
		cout << "Gender: " << passenger.getGender() << endl;
		cout << "Address: " << passenger.getAddress() << endl;
		cout << "City: " << passenger.getCity() << endl;
		cout << "State: " << passenger.getState() << endl;
		cout << "PostalCode: " << passenger.getPostalCode() << endl;
		cout << "Phone Number: " << passenger.getPhoneNumber() << endl;
	}
	db.mgetPassenger.clear();
}

void getTicketInfo(Database& db)
{
	int confirmationID;
	cout << "PLease enter the confirmationId: ";
	cin >> confirmationID;
	vector<Ticket> tickets = db.getTicketInfo(confirmationID);
	if (tickets.empty()) { cout << "There is no ticket available with that confirmation id"; return; }
	cout << "ConfirmationId FirstName LastName Source Destination SeatNumber FlightNumber DepartureDate DepartureTime" << endl;
	for (const auto& ticket : tickets) {
		cout << ticket.getConfirmationId() << " " << ticket.getFirstName() << " " << ticket.getLastName() <<" "<< ticket.getSource() << " " << ticket.getDestination() << " " << ticket.getSeatNumber() << " " << ticket.getFlightNumber() << " " << ticket.getDepartureDate() << " " << ticket.getDepartureTime() << endl;
	}
	db.mgetTickets.clear();
}

void reserveSeat(Database& db)
{
	int i = call;
	char seatlet = NULL;
	seatlet = seatletter[i];
	vector<Flight> searchedFlights;
	string departureDate;
	string source;
	string destination;
	int numberOfTravellers;

	string flightNumber;
	Flight flightSchedule;

	string FirstName;
	string LastName;
	string Gender;
	string EmailId;
	string Adress;
	string City;
	string State;
	string PostalCode;
	string PhoneNumber;

	string seatNumber;
	


	cout << "Please enter the Source: ";
	cin >> source;
	cout << "Please enter the Destination: ";
	cin >> destination;
	cout << "Please enter the departure date: ";
	cin >> departureDate;
	if (dateValidation(departureDate)) {
		cout << "Please enter the valida date";
		return;
	}
	cout << "Please enter the number of travellers: ";
	cin >> numberOfTravellers;

	
	searchedFlights = db.searchFlights(source, destination, departureDate, numberOfTravellers);
	if (searchedFlights.empty()) { cout << "There are no Flights available"; return; }
	cout << "Available Flights" << endl;
	cout << "--------------------" << endl;
	cout << "flightNumber	airways	  source   destination	availableSeats	departureDate	 arrivalDate	numberofStops" << endl;
	for (const auto& flight : searchedFlights) {
		flight.display();
	}

	cout << "Please choose the Flight number: ";
	cin >> flightNumber;
	bool exists = false;
	for (const auto& flight : searchedFlights) {
		if (flight.getFlightNumber() == flightNumber) { exists = true; }
	}
	if (!exists) { cout << "Please choose flight from above list"; db.mSearchedFlights.clear(); return; }

	confirmationId = rand() % 9000 + 1000;
	//selected Flight details
	flightSchedule = db.getFlightSchedule(flightNumber);
	
	//enter passenger Info
	for (int i = 0; i < numberOfTravellers; i++) {
		cout << "Please enter the Passenger Info" << endl;
		cout << "First Name: ";
		cin >> FirstName;

		cout << "Last Name: ";
		cin >> LastName;

		cout << "Gender: ";
		cin >> Gender;

		cout << "EmailId :";
		cin >> EmailId;

		cout << "Address :";
		cin >> Adress;

		cout << "City :";
		cin >> City;

		cout << "State: ";
		cin >> State;

		cout << "postalCode: ";
		cin >> PostalCode;

		cout << "Phone Number: ";
		cin >> PhoneNumber;

		db.addPassenger(FirstName, LastName, Gender, EmailId, Adress, City, State, PostalCode, PhoneNumber);
		seatNumber = seatlet + to_string(i);
		db.addticket(confirmationId, FirstName, LastName, source, destination, seatNumber, flightNumber, departureDate, flightSchedule.getDepartureTime());
	}
	//Generating 4 digit random confirmationId
	//srand(time(0));
	call = call + 1;
	cout << "your seat(s) are reserved. Your confirmationId: " << confirmationId << endl;
	db.mSearchedFlights.clear();
}
bool dateValidation(string date) {
	stringstream ss(date);
	int year, month, day;
	ss >> month >> ch >> day >> ch >> year;
	if (year < 2019 || month > 12 || day > 31)
		return true;
	else
		return false;
}
bool timevalidation(string time) {
	stringstream ss(time);
	int hrs, mins;
	ss >> hrs >> ch >> mins;
	if (hrs > 23 || mins > 59)
		return true;
	else
		return false;
}
bool flightNumberValidation(string flightNumber)
{
	bool exists = false;
	for (auto& flight : flightDB.GetAllFlights())
	{
		if (flight.getFlightNumber() == flightNumber) {
			exists = true;
		}
	}
	return exists;
}