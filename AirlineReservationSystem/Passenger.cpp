#include"pch.h"
#include"Passenger.h"
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include "stdafx.h"

namespace AirlineReseravtion {
	Passenger::Passenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
		const string& address, const string& city, const string& state, const string& postalCode, const string& phoneNumber):mFirstName(firstName),mLastName(lastName),mGender(gender),
		mEmailId(emailId),mAdress(address),mCity(city),mState(state),mPostalCode(postalCode),mPhoneNumber(phoneNumber) {}


	void Passenger::setFirstName(const string & firstName)
	{
		mFirstName = firstName;
	}

	const string& Passenger::getFirstName() const
	{
		return mFirstName;
	}

	void Passenger::setlastName(const string & lastName)
	{
		mLastName = lastName;
	}

	const string & Passenger::getLastName() const
	{
		return mLastName;
	}

	void Passenger::setGender(const string & gender)
	{
		mGender = gender;
	}

	const string & Passenger::getGender() const
	{
		return mGender;
	}

	void Passenger::setEmailId(const string & emailId)
	{
		mEmailId = emailId;
	}

	const string & Passenger::getEmailId() const
	{
		return mEmailId;
	}

	void Passenger::setAddress(const string & address)
	{
		mAdress = address;
	}

	const string & Passenger::getAddress() const
	{
		return mAdress;
	}

	void Passenger::setCity(const string & city)
	{
		mCity = city;
	}

	const string & Passenger::getCity() const
	{
		return mCity
	}

	void Passenger::setState(const string & state)
	{
		mState = state;
	}

	const string & Passenger::getState() const
	{
		return mState;
	}

	void Passenger::setPostalCode(const string & postalCode)
	{
		mPostalCode = postalCode;
	}

	const string & Passenger::getPostalCode() const
	{
		return mPostalCode;
	}

	void Passenger::setPhoneNumber(const string & phoneNumber)
	{
		mPhoneNumber = phoneNumber;
	}

	const string & Passenger::getPhoneNumber() const
	{
		return mPhoneNumber;
	}


}