#pragma once
class Card
{
public:
	Card();
	~Card();
	void setValue(int a);
	void setActive(bool a);
	void setFound(bool a);
	int getValue();
	bool getActive();
	bool getFound();
	void draw();

private:
	int m_value;
	bool m_active;
	bool m_found;
};