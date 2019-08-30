#pragma once
#include<string>
#include<ctime>
#include<vector>

using namespace std;

namespace AirlineReseravtion {

	
	class Flight
	{
	private:

		string mFlightNumber;
		string mAirways;
		string mSource;
		string mDestination;
		int mAvailableSeats;
		string mDepartureDate;
		string mArrivalDate;
		string mDepartureTime;
		string mArrivalTime;
		int mNumberOfStops;
		vector<string> mStopLocation;
		vector<int> mStopDuration;

	public:
		Flight() = default;
		Flight(const string& flightNumber, const string& airways, const string& source, const string& destination,
			const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
			const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration);
		void display() const;

		//Getters and Setters

		void setFlightNumber(const string& flightNumber);
		const string& getFlightNumber() const;

		void setAirWays(const string& airWays);
		const string& getAirWays() const;

		void setSource(const string& source);
		const string& getSource() const;

		void setDestination(const string& destination);
		const string& getDestination() const;

		void setAvailableSeats(const int availableSeats);
		const int getAvailableSeats() const;

		void setDepartureDate(const string& departureDate);
		const string& getDepartureDate() const;

		void setDepartureTime(const string& departureTime);
		const string& getDepartureTime() const;

		void setArrivalDate(const string& arrivaldate);
		const string& getArrivalDate() const;

		void setArrivalTime(const string& arrivalTime);
		const string& getArrivalTime() const;

		void setNumberOfStops(const int numberofstops);
		const int getNumberOfStops() const;

		void setStopLocation(const vector<string>& stopLocation);
		const vector<string>& getStopLocation() const;

		void setStopDuration(const vector<int> stopDuration);
		const vector<int> getStopDuration() const;

	};
}
