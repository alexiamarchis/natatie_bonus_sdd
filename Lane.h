#pragma once
class Lane {
private:
	int id;
	int length;
public:
	Lane();
	Lane(int id, int length);
	Lane(const Lane& other);
	~Lane();

	Lane& operator=(const Lane& other);
	bool operator<(const Lane& other) const;
	bool operator>(const Lane& other) const;
	bool operator==(const Lane& other) const;

	int getId() const;
	int getLength() const;

	void setId(int newId);
	void setLength(int newLength);
};
#pragma once
