#pragma once
#include<iostream>
#include<vector>
#include"Flight.h"
namespace AirlineReseravtion {

	class Database {
	public:
		Flight& addFlight(const string& flightNumber, const string& airways, const string& source, const string& destination,
			const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
			const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration);
		Flight& getFlightSchedule(const string& flightNumber);

		void displayAllFlights() const;

	private:
		vector<Flight> mFlights;
	};
}