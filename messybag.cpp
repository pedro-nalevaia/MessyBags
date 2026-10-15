#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>

//globals
std::vector<std::string> bag;
std::vector<std::string> hand;

//functions
void print_interface();

void take_from_bag();
void add();

void inspect_vec(std::vector<std::string> my_vec);

void fill_with_hand();

int main(){
	bag = {};

	srand(time(0));
	while (1){
		print_interface();
	}
}

void print_interface()
{

	std::printf("\n");
	std::printf("Bag has %zu elements\n",bag.size());
	std::printf("\n");
	std::printf("1 - Take from bag\n");
	std::printf("2 - Add element\n");
	std::printf("3 - Inspect elements in bag\n");
	std::printf("4 - Inspect elements in hand\n");
	std::printf("5 - fill bag with hand\n");

	int input;
	std::cin >> input;

	switch (input){
	case 1:
		take_from_bag();
		return;
	case 2:
		add();
		return;
	case 3:
		inspect_vec(bag);
		return;
	case 4:
		inspect_vec(hand);
		return;
	case 5:
		fill_with_hand();
		return;
	default:
		return;
	}
	printf("returning from input cases");
	return;
}
void fill_with_hand()
{
	for (int i = hand.size()-1; i >= 0; i--)
	{
		bag.push_back(hand[i]);
		hand.erase(hand.begin() + i);
	}
}

void take_from_bag(){
	if (bag.size() == 0)
	{
		std::printf("bag is empty! \n");
		return;
	}

	int rand_el = rand() % bag.size();
	std::printf("you got %s", bag[rand_el].c_str());

	hand.push_back(bag[rand_el]);
	bag.erase(bag.begin() + rand_el);
	return;
}
void add(){
	std::printf("Name of the element:");
	std::string name;
	std::cin >> name;
	bag.push_back(name);
	printf("finishing putting, abin, returning...");
	return;
}
void print_vec(std::vector<std::string> my_vec){
	for (int i = 0; i < my_vec.size(); i++)
	{
		printf("(%d) - %s\n", i, my_vec[i].c_str());
	}
}

void remove_element(std::vector<std::string> my_vec){
	printf("which?\n");

	bool valid = false;
	while (true){
		int which;
		std::cin >> which;

		if (which < my_vec.size())
		{
			my_vec.erase(my_vec.begin() + which);
			return;
		}
	}
}

void inspect_vec(std::vector<std::string> my_vec){
	print_vec(my_vec);
	printf("1 - OK\n");
	printf("2 - RemoveElement\n");

	int input;
	std::cin >> input;

	switch (input){
		case 1:
			return;
		case 2:
			remove_element(my_vec);
			return;
	}
}

