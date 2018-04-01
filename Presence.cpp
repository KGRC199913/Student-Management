#include "Presence.h"
#include <iostream>


Presence::Presence() {
	for (auto&& i : this->check_in) {
		i = false;
	}
}
Presence::Presence(string ID, string name, bool check_in[10]) {
	this->ID = ID;
	this->name = name;
	for (int i = 0; i < 10; ++i) {
		this->check_in[i] = check_in[i];
	}
}