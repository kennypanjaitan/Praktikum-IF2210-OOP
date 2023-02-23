#include <iostream>
#include "SpacingGuildShip.hpp"

using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : serialNum(producedShips + 1), maxPassengerCap(50), guildNavigatorCount(3)
{
	this->passengerCount = 0;
	this->spiceStock = 50;
	this->operatingGuildNavigator = this->guildNavigatorCount;
	producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips + 1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount)
{
	this->passengerCount = 0;
	this->spiceStock = spiceStock;
	this->operatingGuildNavigator = this->guildNavigatorCount;
	producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& sgs) : serialNum(producedShips + 1), maxPassengerCap(sgs.maxPassengerCap), guildNavigatorCount(sgs.guildNavigatorCount)
{
	this->passengerCount = sgs.passengerCount;
	this->spiceStock = sgs.spiceStock;
	this->operatingGuildNavigator = this->guildNavigatorCount;
	producedShips++;
}

SpacingGuildShip::~SpacingGuildShip()
{}

int SpacingGuildShip::getShipSerialNum() const
{
	this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
	this->passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
	if (this->operatingGuildNavigator > 0)
	{
		this->totalGuildTravel += distance/(E*E * this->operatingGuildNavigator);
		this->operatingGuildNavigator--;
	}
}

void SpacingGuildShip::boarding(int addedPassengers)
{
	int add = addedPassengers + this->passengerCount;
	if (add >= this->maxPassengerCap)
	{
		this->passengerCount = this->maxPassengerCap;
	}
	else
	{
		this->passengerCount = add;
	}
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
	int drop = this->passengerCount - droppedPassengers;
	if (drop <= 0)
	{
		this->passengerCount = 0;
	}
	else
	{
		this->passengerCount = drop;
	}
}

void SpacingGuildShip::refreshNavigator(int n)
{
	int nAdd = n * GUILD_NAVIGATOR_SPICE_DOSE;
	int inactive = this->guildNavigatorCount - this->operatingGuildNavigator;
	if (nAdd > this->spiceStock)
	{
		this->spiceStock -= nAdd;
		if (n < inactive)
		{
			this->operatingGuildNavigator += n;
		}
		else
		{
			this->operatingGuildNavigator += inactive;
		}
	}
	else
	{
		this->spiceStock -= (this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE) * GUILD_NAVIGATOR_SPICE_DOSE;
		this->operatingGuildNavigator += (this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE);
	}
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
	this->spiceStock += addedSpice;
}