#pragma once
#include<iostream>
#include<vector>
#include"Flight.h"
#include"Passenger.h"
#include"Ticket.h"
namespace AirlineReseravtion {

	class Database {
	public:
		//flight Methods
		Flight& addFlight(const string& flightNumber, const string& airways, const string& source, const string& destination,
			const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
			const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration);

		vector<Flight>& searchFlights(const string& source, const string& destination, const string& departureDate, const int numberOfTravellers);

		Flight& getFlightSchedule(const string& flightNumber);
		void displayAllFlights() const;

		//Passenger Methods
		Passenger& addPassenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
			const string& address, const string& city, const string& state, const string& postalCode,const string& phoneNumber);

		Passenger& getPassengerInfo(const string& emailId);

		//Ticket Methods
		Ticket& addticket(int confirmationID, const string& firstName, const string& lastName, const string& source, const string& destination,
			const string& seatNumber, const string& flightNumber, const string& departureDate, const string& departureTime);
		vector<Ticket>& getTicketInfo(const int confirmationId);

		vector<Flight> mSearchedFlights;
		vector<Ticket> mgetTickets;
	private:
		vector<Flight> mFlights;
		vector<Passenger> mPassengers;
		vector<Ticket> mTickets;
		
	};
}