#pragma once

enum class Suit {
	Hearts,
	Diamonds,
	Clubs,
	Spades

class SuitHelper{
public:
	SuitHelper() {}

	static const char* ToString(Suit suit);
};