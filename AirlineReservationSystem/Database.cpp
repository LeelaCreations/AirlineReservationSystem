#include"pch.h"
#include<stdexcept>
#include"Database.h"

namespace AirlineReseravtion {
	//Flight class Methods implementation
	Flight& Database::addFlight(const string& flightNumber, const string& airways, const string& source, const string& destination,
		const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
		const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration){
		Flight theFlight(flightNumber, airways, source, destination, availableSeats, departureDate, departureTime, arrivalDate, arrivalTime, numberofStops, stopLocation, stopDuration);

		mFlights.push_back(theFlight);
		return mFlights[mFlights.size() - 1];		
	}

	vector<Flight>& Database::searchFlights(const string & source, const string & destination, const string & departureDate, const int numberOfTravellers)
	{
		for (auto& flight : mFlights)
		{
			if (flight.getSource() == source && flight.getDestination() == destination && flight.getDepartureDate() == departureDate && flight.getAvailableSeats() >= numberOfTravellers)
			{
				mSearchedFlights.push_back(flight);
			}
		}
		return mSearchedFlights;
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
	vector<Flight>& Database::GetAllFlights()
	{
		return mFlights;
	}
	void Database::displayAllFlights() const
	{
		cout << "flightNumber	airways	  source   destination	availableSeats	departureDate	 arrivalDate	numberofStops" << endl;
		for (const auto& flight : mFlights) {
			flight.display();
		}
	}

	//Passenger Class Methods Implementation

	Passenger& Database::addPassenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
		const string& address, const string& city, const string& state, const string& postalCode, const string& phoneNumber) {

		Passenger thePassenger(firstName, lastName, gender, emailId, address, city, state, postalCode, phoneNumber);
		mPassengers.push_back(thePassenger);
		return mPassengers[mPassengers.size() - 1];
	}

	vector<Passenger>& Database::getPassengerInfo(const string& emailID)
	{
		for (auto& passenger : mPassengers)
		{
			if (passenger.getEmailId() == emailID){ mgetPassenger.push_back(passenger); }
				
		}
		return mgetPassenger;
		throw logic_error("No Passenger found");
	}

	//Ticket class Methods Impleamentation

	Ticket& Database::addticket(int confirmationID, const string& firstName, const string& lastName, const string& source, const string& destination,
		const string& seatNumber, const string& flightNumber, const string& departureDate, const string& departureTime) {

		Ticket theTicket(confirmationID, firstName, lastName, source, destination, seatNumber, flightNumber, departureDate, departureTime);
		mTickets.push_back(theTicket);
		return mTickets[mTickets.size() - 1];
	}

	vector<Ticket>& Database::getTicketInfo(const int confirmationId)
	{
		for (auto& ticket : mTickets)
		{
			if (ticket.getConfirmationId() == confirmationId)
			{
				mgetTickets.push_back(ticket);
			}
		}
		return mgetTickets;
		throw logic_error("No Ticket found");
	}
}