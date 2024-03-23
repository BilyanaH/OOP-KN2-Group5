#include "LicenseKey.h"

LicenseKey::LicenseKey(int key)
{
	if (key >= 10000000 && key <= 99999999)
	{
		this->key = key;
	}
	else {
		this->key = 10000000;
	}
	activations = new int[1];
	activations[0] = 0;
}

LicenseKey::LicenseKey(const LicenseKey& other)
{
	other.activations[0]++;
	this->activations = other.activations;

	this->key = other.key;
}

int LicenseKey::activate() const
{
	if(activations[0]>MAX_ACTIVATIONS)
	return -1;
	return key;
}
