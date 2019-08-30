#include"pch.h"
#include<stdexcept>
#include"Database.h"

namespace AirlineReseravtion {

	Flight& Database::addFlight(const string& flightNumber, const string& airways, const string& source, const string& destination,
		const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
		const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration){
		Flight theFlight(flightNumber, airways, source, destination, availableSeats, departureDate, departureTime, arrivalDate, arrivalTime, numberofStops, stopLocation, stopDuration);

		mFlights.push_back(theFlight);
		return mFlights[mFlights.size() - 1];
	}

	Flight& Database::getFlightSchedule(const string& flightNumber)
	{
		for (auto& flight : mFlights)
		{
			if (flight.getFlightNumber() == flightNumber) {
				return flight;
			}
		}
		throw logic_error("No Flight found");
	}

	void Database::displayAllFlights() const
	{
		cout << "flightNumber	airways	  source   destination	availableSeats	departureDate	 arrivalDate	numberofStops" << endl;
		for (const auto& flight : mFlights) {
			flight.display();
		}
	}

	//Passenger Class Methods

	Passenger& Database::addPassenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
		const string& address, const string& city, const string& state, const string& postalCode, const string& phoneNumber) {

		Passenger thePassenger(firstName, lastName, gender, emailId, address, city, state, postalCode, phoneNumber);
		mPassengers.push_back(thePassenger);
		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& Database::getPassengerInfo(const string& emailID)
	{
		for (auto& passenger : mPassengers)
		{
			if (passenger.getEmailId() == emailID){ return passenger; }
				
		}
		throw logic_error("No Passenger found");
	}
}