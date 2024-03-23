#pragma once
class LicenseKey {
private:
	const int MAX_ACTIVATIONS = 3;
	int* activations;
	int key;

public:
	LicenseKey(int key);
	LicenseKey(const LicenseKey& from);
	int activate() const;
	LicenseKey();
};