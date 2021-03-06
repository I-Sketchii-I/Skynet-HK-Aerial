// Skynet HK-Aerial.cpp
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int randomNum = rand();
	int enemyLocation = (randomNum % 64) + 1;
	int ping = 1, searchGridHighNumber = 64, searchGridLowNumber = 1;
	int targetLocationPrediction = 0;
	bool isHit = false;
	
	//Start Message
	cout << "INITIALIZING... START\n\nWelcome to the SKYNET HK-Aerial Drone Demo!\n\nThe enemy is at locale #" << enemyLocation << " on grid 8x8 with 64 locales\n\nTest in Progress..";

	//"do-while" loop to carry out the search and update variables as needed during the search
	do
	{
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		cout << "\n\nSkynet HK-Aerial sending out signal ping #" << ping;
		
		if (targetLocationPrediction == enemyLocation) {
			cout << "\n\nEnemy was at locale #" << enemyLocation;
			cout << "\nTarget neutralized at locale #" << targetLocationPrediction;
			cout << "\nSkynet HK-Aerial System v0.0.1 took " << ping << " attempts to find and neutralize the enemy\n\n";
			isHit = true;
			break;
		}
		if (targetLocationPrediction < enemyLocation) {
			cout << "\n\nThe target's predicted location of locale #" << searchGridLowNumber << " was lower than the enemy's actual position at locale #" << enemyLocation;
			searchGridLowNumber = targetLocationPrediction;
			ping++;
		}
		if (targetLocationPrediction > enemyLocation) {
			cout << "\n\nThe target's predicted location of locale #" << searchGridHighNumber << " was higher than the enemy's actual position at locale #" << enemyLocation;
			searchGridHighNumber = targetLocationPrediction;
			ping++;
		}


	} while (isHit == false && targetLocationPrediction <= 64);
}