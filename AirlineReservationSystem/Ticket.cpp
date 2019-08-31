#include"pch.h"
#include"Ticket.h"
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include "stdafx.h"

namespace AirlineReseravtion {
	Ticket::Ticket(int confirmationID, const string& firstName, const string& lastName, const string& source, const string& destination,
		const string& seatNumber, const string& flightNumber, const string& departureDate, const string& departureTime):mConfirmationId(confirmationID),mFirstName(firstName),mLastName(lastName),mSource(source),
		mDestination(destination),mSeatNumber(seatNumber),mFlightNumber(flightNumber),mDepartureDate(departureDate),mDepartureTime(departureTime){}

	void Ticket::setConfirmationId(const int confirmationID)
	{
		mConfirmationId = confirmationID;
	}

	const int Ticket::getConfirmationId() const
	{
		return mConfirmationId;
	}

	void Ticket::setFirstName(const string & firstName)
	{
		mFirstName = firstName;
	}

	const string & Ticket::getFirstName() const
	{
		return mFirstName;
	}

	void Ticket::setLastName(const string & lastName)
	{
		mLastName = lastName;
	}

	const string & Ticket::getLastName() const
	{
		return mLastName;
	}

	void Ticket::setSource(const string & source)
	{
		mSource = source;
	}

	const string & Ticket::getSource() const
	{
		return mSource;
	}

	void Ticket::setDestination(const string & destination)
	{
		mDestination = destination;
	}

	const string & Ticket::getDestination() const
	{
		return mDestination;
	}

	void Ticket::setSeatNumber(const string & seatNumber)
	{
		mSeatNumber = seatNumber;
	}

	const string & Ticket::getSeatNumber() const
	{
		return mSeatNumber;
	}

	void Ticket::setFlightNumber(const string & flightNumber)
	{
		mFlightNumber = flightNumber;
	}

	const string & Ticket::getFlightNumber() const
	{
		return mFlightNumber;
	}

	void Ticket::setDepartureDate(const string & departureDate)
	{
		mDepartureDate = departureDate;
	}

	const string & Ticket::getDepartureDate() const
	{
		return mDepartureDate;
	}

	void Ticket::setDepartureTime(const string & departuretime)
	{
		mDepartureTime = departuretime;
	}

	const string & Ticket::getDepartureTime() const
	{
		return mDepartureTime;
	}

}