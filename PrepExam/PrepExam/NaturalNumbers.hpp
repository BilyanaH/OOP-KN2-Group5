
#ifndef NATURALNUMBERS_H_ 
#define NATURALNUMBERS_H_ 
class NaturalNumbers {
private:
	unsigned* numbers;
	char* name;
	unsigned length;

public:

	void set_name(const char* name);
	const char* get_name() const;
	void set_numbers(const int* name);
	const int* get_numbers() const;

	NaturalNumbers(unsigned* numbers, const char* name, unsigned length);
	NaturalNumbers();
	NaturalNumbers(const NaturalNumbers& other);
	NaturalNumbers& operator=(const NaturalNumbers& other);
	NaturalNumbers& operator+=(const NaturalNumbers& other);
	NaturalNumbers& operator+(const NaturalNumbers& other);
	NaturalNumbers(NaturalNumbers&& other);
	NaturalNumbers& operator=(NaturalNumbers&& other);

	~NaturalNumbers();


};

#endif

