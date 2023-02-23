#include <iostream>
#include "Item.hpp"

using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1)
{
	this->stock = 0;
	this->price = 0;
	this->sold = 0;
	totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
	this->stock = stock;
	this->price = price;
	this->sold = 0;
	totalItems++;
}

Item::Item(const Item& item) : serialNum(item.serialNum + 1)
{
	this->stock = item.stock;
	this->price = item.price;
	this->sold = item.sold;
	totalItems++;
}

Item::~Item(){

}

int Item::getSerialNum() const
{
	return this->serialNum;
}

int Item::getSold() const
{
	return this->sold;
}

int Item::getPrice() const
{
	return this->price;
}

void Item::addStock(int addedStock)
{
	this->stock += addedStock;
}

void Item::sell(int soldStock)
{
	int sellStock = this->stock - soldStock;
	if (sellStock >= 0)
	{
		this->stock = sellStock;
		totalRevenue += soldStock * this->price;
		this->sold += soldStock;
	}
	else
	{
		this->sold += this->stock;
		totalRevenue += this->stock * this->price;
		this->stock = 0;
	}
}

void Item::setPrice(int newPrice)
{
	this->price = newPrice;
}