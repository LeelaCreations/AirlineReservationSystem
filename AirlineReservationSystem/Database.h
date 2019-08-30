#pragma once
#include<iostream>
#include<vector>
#include"Flight.h"
#include"Passenger.h"
namespace AirlineReseravtion {

	class Database {
	public:
		Flight& addFlight(const string& flightNumber, const string& airways, const string& source, const string& destination,
			const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
			const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration);
		Flight& getFlightSchedule(const string& flightNumber);

		void displayAllFlights() const;

		Passenger& addPassenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
			const string& address, const string& city, const string& state, const string& postalCode,const string& phoneNumber);

		Passenger& getPassengerInfo(const string& emailId);
	private:
		vector<Flight> mFlights;
		vector<Passenger> mPassengers;
	};
}