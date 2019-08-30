#include"pch.h"
#include"Flight.h"
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include "stdafx.h"

namespace AirlineReseravtion {
	Flight::Flight(const string& flightNumber, const string& airways, const string& source, const string& destination,
		const int availableSeats, const string& departureDate, const string& departureTime, const string& arrivalDate, const string& arrivalTime,
		const int numberofStops, vector<string>& stopLocation, vector<int> stopDuration) : mFlightNumber(flightNumber), mAirways(airways), mSource(source),
		mDestination(destination), mAvailableSeats(availableSeats), mDepartureDate(departureDate), mDepartureTime(departureTime), mArrivalDate(arrivalDate),
		mArrivalTime(arrivalTime), mNumberOfStops(numberofStops), mStopLocation(stopLocation), mStopDuration(stopDuration){	}
    
	
	//Getter and Setter for FlightNumber
	void Flight::setFlightNumber(const string& flightNumber)
	{
		mFlightNumber = flightNumber;
	}
	const string& Flight::getFlightNumber() const
	{
		return mFlightNumber;
	}

	//Getter and Setter for Airways
	void Flight::setAirWays(const string& airWays) {
		mAirways = airWays;
	}
	const string& Flight::getAirWays() const {
		return mAirways;
	}

	//Getter and Setter for Source
	void Flight::setSource(const string& source) {
		mSource = source;
	}
	const string& Flight::getSource() const {
		return mSource;
	}

	//Getter and Setter for Destination
	void Flight::setDestination(const string& destination) {
		mDestination = destination;
	}
	const string& Flight::getDestination() const {
		return mDestination;
	}

	//Getter and Setter for availableSeats
	void Flight::setAvailableSeats(const int availableSeats) {
		mAvailableSeats = availableSeats;
	}
	const int Flight::getAvailableSeats() const {
		return mAvailableSeats;
	}

	//Getter and Setter for DepartureDate
	void Flight::setDepartureDate(const string& departureDate) {		
		mDepartureDate = departureDate;
	}
	const string& Flight::getDepartureDate() const {
		return mDepartureDate;
	}

	//Getter and Setter for DepartureTime
	void Flight::setDepartureTime(const string& departureTime) {
		mDepartureTime = departureTime;
	}
	const string& Flight::getDepartureTime() const {
		return mDepartureTime;
	}

	//Getter and Setter for ArrivalDate
	void Flight::setArrivalDate(const string& arrivaldate) {
		mArrivalDate = arrivaldate;
	}
	const string& Flight::getArrivalDate() const {
		return mArrivalDate;
	}

	//Getter and Setter for ArrivalTime
	void Flight::setArrivalTime(const string& arrivalTime)
	{
		mArrivalTime = arrivalTime;
	}
	const string& Flight::getArrivalTime() const {
		return mArrivalTime;
	}

	//Getter and Setter for numberOfStops
	void Flight::setNumberOfStops(const int numberofstops) {
		mNumberOfStops = numberofstops;
	}
	const int Flight::getNumberOfStops() const {
		return mNumberOfStops;
	}

	//Getter and Setter for StopLocation
	void Flight::setStopLocation(const vector<string>& stopLocation) {
		mStopLocation = stopLocation;		
	}
	const vector<string>& Flight::getStopLocation() const {
		return mStopLocation;
	}

	//Getter and Setter for StopDuration
	void Flight::setStopDuration(const vector<int> stopDuration) {
		mStopDuration = stopDuration;
	}
	const vector<int> Flight::getStopDuration() const {
		return mStopDuration;
	}


	void Flight::display() const
	{
		//cout << "flightNumber	airways	  source   destination	availableSeats	departureDate	 arrivalDate	numberofStops"<<endl;
		cout<<"	"<<getFlightNumber()<<"	"<< getAirWays()<< "  " << getSource() << "   " << getDestination() << "	      " << getAvailableSeats() << "   " << getDepartureDate() <<" "<< getDepartureTime() << "	 " << getArrivalDate() <<" "<< getArrivalTime() << "	" << getNumberOfStops() <<endl ;

	}
}