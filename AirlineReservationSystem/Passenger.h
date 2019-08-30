#pragma once
#include<string>
#include<ctime>
#include<vector>

using namespace std;
namespace AirlineReseravtion {
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const string& firstName, const string& lastName, const string& gender, const string& emailId,
			const string& address, const string& city, const string& state, const string& postalCode, const string& phoneNumber);		

		//Getters and Setters
		void setFirstName(const string& firstName);
		const string& getFirstName() const;

		void setlastName(const string& lastName);
		const string& getLastName() const;

		void setGender(const string& gender);
		const string& getGender() const;

		void setEmailId(const string& emailId);
		const string& getEmailId() const;

		void setAddress(const string& address);
		const string& getAddress() const;

		void setCity(const string& city);
		const string& getCity() const;

		void setState(const string& state);
		const string& getState() const;

		void setPostalCode(const string& postalCode);
		const string& getPostalCode() const;

		void setPhoneNumber(const string& phoneNumber);
		const string& getPhoneNumber() const;

	private:
		string mFirstName;
		string mLastName;
		string mGender;
		string mEmailId;
		string mAdress;
		string mCity;
		string mState;
		string mPostalCode;
		string mPhoneNumber;
	};


}
