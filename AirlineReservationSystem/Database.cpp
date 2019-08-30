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
}