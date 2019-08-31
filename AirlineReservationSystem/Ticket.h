#pragma once
#include<string>
#include<ctime>
#include<vector>

using namespace std;
namespace AirlineReseravtion {

	class Ticket
	{
	public:
		Ticket() = default;
		Ticket(int confirmationID, const string& firstName, const string& lastName, const string& source, const string& destination,
			const string& seatNumber, const string& flightNumber, const string& departureDate, const string& departureTime);

		//getters and Setters
		void setConfirmationId(const int confirmationID);
		const int getConfirmationId() const;

		void setFirstName(const string& firstName);
		const string& getFirstName() const;

		void setLastName(const string& lastName);
		const string& getLastName() const;

		void setSource(const string& source);
		const string& getSource() const;

		void setDestination(const string& destination);
		const string& getDestination() const;

		void setSeatNumber(const string& seatNumber);
		const string& getSeatNumber() const;

		void setFlightNumber(const string& flightNumber);
		const string& getFlightNumber() const;

		void setDepartureDate(const string& departureDate);
		const string& getDepartureDate() const;

		void setDepartureTime(const string& departuretime);
		const string& getDepartureTime() const;

	private:
		int mConfirmationId;
		string mFirstName;
		string mLastName;
		string mSource;
		string mDestination;
		string mSeatNumber;
		string mFlightNumber;
		string mDepartureDate;
		string mDepartureTime;
	};

}
