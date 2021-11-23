// TourismAgency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//the basic class
class Agency
{
protected:
	int offerNumber;
	float price;
	string locality;
	string country;
	int numberOfDays;

public:
	//default constructor
	Agency()
	{
	}

	//constructor with parameters
	Agency(int offerNumber, float price, string locality, string country, int numberOfDays)
	{
		Agency::offerNumber = offerNumber;
		Agency::price = price;
		Agency::locality = locality;
		Agency::country = country;
		Agency::numberOfDays = numberOfDays;
	}

	//destructor
	~Agency()
	{
	}

	//the display() function 
	void display()
	{
		cout << "-------------------------------------" << endl;
		cout << "Offer number: " << Agency::offerNumber << endl;
		cout << "Price: " << Agency::price << endl;
		cout << "Locality: " << Agency::locality << endl;
		cout << "Country: " << Agency::country << endl;
		cout << "Number of days: " << Agency::numberOfDays << endl;
	}

	//this function accesses the private member of the class
	float returnPrice()
	{
		return Agency::price;
	}

	//this function accesses the private member of the class
	int returnOfferNumber()
	{
		return Agency::offerNumber;
	}
};

//the derived class
class SeasideHoliday : public Agency
{
protected:
	string sandType;
	float temperature;

public:
	//default constructor
	SeasideHoliday()
	{
	}

	//constructor with all parameters (+ basic class)
	SeasideHoliday(int offerNumber, float price, string locality, string country, int numberOfDays, string sandType, float temperature) :
		Agency(offerNumber, price, locality, country, numberOfDays)
	{
		SeasideHoliday::sandType = sandType;
		SeasideHoliday::temperature = temperature;
	}

	//destructor
	~SeasideHoliday()
	{
	}

	//the display() function 
	void display()
	{
		//also call the display() function from the base class
		Agency::display();

		cout << "The sand type: " << SeasideHoliday::sandType << endl;
		cout << "The temperature : " << SeasideHoliday::temperature << endl;
	}
};

//the derived class
class MountainHoliday : public Agency
{
protected:
	int altitude;

public:
	//default constructor
	MountainHoliday() 
	{
	}

	//constructor with all parameters (+ basic class)
	MountainHoliday(int offerNumber, float price, string locality, string country, int numberOfDays, int altitude) :
		Agency(offerNumber, price, locality, country, numberOfDays)
	{
		MountainHoliday::altitude = altitude;
	}

	//destructor
	~MountainHoliday()
	{
	}

	//the display() function
	void display()
	{
		//also call the display() function from the base class
		Agency::display();

		cout << "The altitude: " << MountainHoliday::altitude << endl;
	}
};

int main()
{
    //declare the variables
	int offerNumber;
	float price;
	string locality;
	string country;
	int numberOfDays;
	string sandType;
	float temperature;
	float lowestPrice;
	int delete_offerNumber;
	int altitude;

	/* create the matrix of objects with maximum 10 offers
	* the object is the instantiation of the class
	* and the class is a sketch of the object
	*/
	SeasideHoliday objSeaside[10];
	MountainHoliday objMountain[10];
	
	unsigned int totalNrOffers, option;

	do
	{
		cout << "1. Seaside holiday" << endl;
		cout << "2. Show the offers for seaside holidays" << endl;
		cout << "3. Find the lowest price offered for seaside holiday" << endl;
		cout << "4. Delete an offer" << endl;
		cout << "5. Mountain holiday" << endl;
		cout << "6. Display the offers for mountain holiday" << endl;
		cout << "7. Find the lowest price offered for mountain holiday" << endl;
		cout << "0. Exit " << endl;

		cout << "Choose the option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Total number of offers: ";
			cin >> totalNrOffers;

			for (int i = 0; i < totalNrOffers; i++)
			{
				cout << "Offer number: "; cin >> offerNumber;
				cout << "Price: "; cin >> price;
				cout << "Locality: "; cin >> locality;
				cout << "Country: "; cin >> country;
				cout << "Number of days: "; cin >> numberOfDays;
				cout << "The sand type: "; cin >> sandType;
				cout << "The temperature: "; cin >> temperature;

				//the object calls the constructor with the parameters
				objSeaside[i] = SeasideHoliday(offerNumber, price, locality, country, numberOfDays, sandType, temperature);
			}
			break;

		case 2:
			for (int i = 0; i < totalNrOffers; i++)
			{
				//displaying the offers
				objSeaside[i].display();
			}
			break;

		case 3:
			cout << "The offers with the lowest price than ";
			cin >> lowestPrice;

			for (int i = 0; i < totalNrOffers; i++)
			{
				if (objSeaside[i].returnPrice() < lowestPrice)
				{
					objSeaside[i].display();
				}
			}
			break;

		case 4:
			cout << "Enter the offer you want to delete:  ";
			cin >> delete_offerNumber;

			for (int i = 0; i < totalNrOffers; i++)
			{
				if (objSeaside[i].returnOfferNumber() == delete_offerNumber)
				{
					for(int j = i; j < totalNrOffers; j++)
					{
						//overlapping offers
						objSeaside[j] = objSeaside[j + 1];
						//decrementing the number of offers
						totalNrOffers--;
					}
				}
			}
			break;

		case 5:
			cout << "Total number of offers: ";
			cin >> totalNrOffers;

			for (int i = 0; i < totalNrOffers; i++)
			{
				cout << "Offer number: "; cin >> offerNumber;
				cout << "Price: "; cin >> price;
				cout << "Locality: "; cin >> locality;
				cout << "Country: "; cin >> country;
				cout << "Number of days: "; cin >> numberOfDays;
				cout << "Altitude: "; cin >> altitude;

				//the object calls the constructor with the parameters
				objMountain[i] = MountainHoliday(offerNumber, price, locality, country, numberOfDays, altitude);
			}
			break;

		case 6:
			for (int i = 0; i < totalNrOffers; i++)
			{
				//displaying the offers entered
				objMountain[i].display();
			}
			break;

		case 7:
			cout << "The offers with the lowest price than ";
			cin >> lowestPrice;

			for (int i = 0; i < totalNrOffers; i++)
			{
				if (objMountain[i].returnPrice() < lowestPrice)
				{
					objMountain[i].display();
				}
			}
			break;

		case 0:
			break;

		default:
			cout << "The chosen option is wrong." << endl;
			break;
		}

	} while (option != 0);

	_getch();

    return 0;
}
