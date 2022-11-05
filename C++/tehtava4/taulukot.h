#pragma once

extern bool naytto[16][12];

namespace taulukot
{
	void luoTaulukko();
	void kaannaTaulukko();
	void setLed(int x, int y, bool val);
	void printLed();
	void clearLed();
}