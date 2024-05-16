//Libraries
#include <iostream>
using namespace std;

//function prototypes. functions use references (Week 10) so the changes made in the function affect the relevant statuses.
bool Status(int&, int&, int&);
void Play(int, int&, int&);
void feed(int, int&);
void rest(int, int&, int&, int&);


//main function.
int main()
{
	//Defining and initializing variables.
	string name;
	int choice1 = 0;
	int choice2 = 0;
	int hunger = 100;
	int energy = 100;
	int happiness = 100;
	bool alive = true;
	bool quit = false;


	// Greet the user and ask them to name the pet.
	cout << "Welcome to the Cyberpet program. :) " << endl;
	cout << "What would you like to name your cyberpet? " << endl;
	cin >> name;
	cout << endl;
	cout << "Your pets name is " << name << "." << endl;

	//This loop will run for as long as the pet is alive and the user hasn't decided to quit.(Loops weeks 2 and 3)
	do {
		//This is the menu with all the interactions you can have with the pet.
		cout << endl << "What would you like to do? " << endl
			<< "1) Check " << name << "'s status." << endl
			<< "2) Play with " << name << "." << endl
			<< "3) Feed " << name << endl
			<< "4) Let " << name << " rest. " << endl
			<< "5) Quit" << endl;
		cin >> choice1;

		//This switch statement takes in the choice the user inputs and opens a sub-menu based on what the user inputs.(Decision statements week 4)
		switch (choice1) {
		case 1:
			system("CLS");// clears console window for better visibility.(learned from week 10 activity)
			//calls function status that checks and outputs the statuses of the pet and sets alive to false if any reach 0
			alive = Status(hunger, energy, happiness);
			cout << endl;
			break;
		case 2:
			system("CLS");
			//menu options for playing with your pet
			cout << "What do you want to do with " << name << "?" << endl
				<< "1) pet :" << endl << "+5 happiness" << endl
				<< "2) Go for a walk: " << endl << "+10 happiness, -5 energy" << endl
				<< "3) Play Tug-of-War: " << endl << "+15 happiness, -10 energy" << endl
				<< "4) Play fetch: " << endl << "+20 happiness, -15 energy" << endl
				<< "5) Train " << name << ":" << endl << "+20 happiness, -15 energy" << endl;
			cin >> choice2;

			//call play function
			Play(choice2, energy, happiness);
			cout << endl;
			break;
		case 3:
			system("CLS");
			//menu options for feeding your pet
			cout << "What do you want to feed " << name << "?" << endl
				<< "1) Small snack: " << endl << "+5 hunger" << endl
				<< "2) Balanced meal: " << endl << "+10 hunger" << endl
				<< "3) Special treat: " << endl << "+15 hunger" << endl
				<< "4) Gourmet meal: " << endl << "+20 hunger" << endl
				<< "5) Feast: " << endl << "+25 hunger" << endl;
			cin >> choice2;

			// Call feed function
			feed(choice2, hunger);
			cout << endl;
			break;
		case 4:
			system("CLS");
			//menu options for letting the pet rest
			cout << "How would you like to let " << name << " rest?" << endl
				<< "1) Short nap: " << endl << "+10 energy, -5 hunger" << endl
				<< "2) Peaceful rest: " << endl << "+15 energy, -10 hunger" << endl
				<< "3) Luxurious nap: " << endl << "+20 energy, -15 hunger" << endl
				<< "4) Deep sleep: " << endl << "+25 energy, -20 hunger, -5 happiness" << endl
				<< "5) Extended relaxation: " << endl << "+30 energy, -25 hunger, -10 happiness" << endl;
			cin >> choice2;

			// Call rest function
			rest(choice2, energy, hunger, happiness);
			cout << endl;
			break;
		case 5:
			system("CLS");
			quit = true;
			break;
		default:
			cout << "Invalid input." << endl
				<< endl;
			break;
		}

		//checks if the hunger is above zero
		if (hunger <= 0) {
			cout << "Your pet died of hunger." << endl;
			alive = false;
		}
		//checks if energy is above zero
		if (energy <= 0) {
			cout << "Your pet died of exhaustion." << endl;
			alive = false;
		}
		//checks if happiness is above zero
		if (happiness <= 0) {
			cout << "Your pet died of depression." << endl;
			alive = false;
		}

		//checks if quit is true or if alive is false and out puts a statement and returns 0 to exit the program.
		if (quit == true) {
			cout << "Goodbye user. :)" << endl;
			return 0;
		}
		else if (!alive) {
			cout << "Your pet has died. Exiting program. :(" << endl;
			return 0;
		}

	} while (true);// the loop will continue to run forever


}

//Function definitions.
//This function checks and displays the current status of the pets' hunger, energy and happiness meters.
bool Status(int& hunger, int& energy, int& happiness) {
	//checks hunger.
	if (hunger >= 100) {
		hunger = 100;
		cout << "Your pet is full." << endl;
	}
	else if (hunger >= 70 && hunger < 100) {
		cout << "Your pet is well fed." << endl;
	}
	else if (hunger >= 50 && hunger < 70) {
		cout << "Your pet is slightly peckish." << endl;
	}
	else if (hunger >= 30 && hunger < 50) {
		cout << "Your pet is Hungry." << endl;
	}
	else if (hunger >= 1 && hunger < 30) {
		cout << "Your pet is starving!" << endl;
	}
	else if (hunger <= 0) {
		cout << "Your pet died of hunger." << endl;
		return false;
	}

	//checks energy.
	if (energy >= 100) {
		energy = 100;
		cout << "Your pet is wide awake." << endl;
	}
	else if (energy >= 70 && energy < 100) {
		cout << "Your pet is awake" << endl;
	}
	else if (energy >= 50 && energy < 70) {
		cout << "Your pet is a bit tired" << endl;
	}
	else if (energy >= 30 && energy < 50) {
		cout << "Your pet is very tired" << endl;
	}
	else if (energy >= 1 && energy < 30) {
		cout << "Your pet is exhausted!" << endl;
	}
	else if (energy <= 0) {
		cout << "Your pet died of exhaustion." << endl;
		return false;
	}

	//checks happiness.
	if (happiness >= 100) {
		happiness = 100;
		cout << "Your pet is ecstatic." << endl;
	}
	else if (happiness >= 70 && happiness < 100) {
		cout << "Your pet is happy." << endl;
	}
	else if (happiness >= 50 && happiness < 70) {
		cout << "Your pet is content" << endl;
	}
	else if (happiness >= 30 && happiness < 50) {
		cout << "Your pet is sad" << endl;
	}
	else if (happiness >= 1 && happiness < 30) {
		cout << "Your pet is depressed!" << endl;
	}
	else if (happiness <= 0) {
		cout << "Your pet died of depression." << endl;
		return false;
	}

	//return true to alive variable.
	return true;
}

//This function allows you to play with the pet increasing its happiness based on your choice at the cost of energy.
void Play(int choice, int& energy, int& happiness) {
	switch (choice) {
	case 1:
		std::cout << "You pet your pet, its happier. " << endl;
		happiness += 5;
		break;
	case 2:
		std::cout << "You took your pet out for a walk, its happier." << endl;
		happiness += 10;
		energy -= 5;
		break;
	case 3:
		std::cout << "You played tug of war with your pet, its happier." << endl;
		happiness += 15;
		energy -= 10;
		break;
	case 4:
		std::cout << "You played fetch with your pet, its happier." << endl;
		happiness += 20;
		energy -= 15;
		break;
	case 5:
		std::cout << "You had a training session with your pet, its happier." << endl;
		happiness += 25;
		energy -= 20;
		break;
	default:
		std::cout << "Invalid choice." << endl;
	}
	//ensure happiness dosent reach above 100.
	if (happiness >= 100) {
		happiness = 100;
	}
}

//this function allows the pet too rest replenishing its energy at the cost of hunger and happiness.
void rest(int choice, int& energy, int& hunger, int& happiness) {
	switch (choice) {
	case 1:
		cout << "Your pet takes a short nap to recharge." << endl;
		energy += 10;
		hunger -= 5;
		break;
	case 2:
		cout << "Your pet enjoys a peaceful rest." << endl;
		energy += 15;
		hunger -= 10;
		break;
	case 3:
		cout << "Your pet takes a long nap." << endl;
		energy += 20;
		hunger -= 15;
		break;
	case 4:
		cout << "Your pet goes to sleep." << endl;
		energy += 25;
		hunger -= 20;
		happiness -= 5; // Decrease happiness slightly while sleeping.
		break;
	case 5:
		cout << "You pet enters a deep sleep." << endl;
		energy += 30;
		hunger -= 25;
		happiness -= 10; // Decrease happiness during deep sleep.
		break;
	default:
		cout << "Invalid choice. " << endl;
		
	}
	cout << "Invalid choice. Please choose a number between 1 and 5." << endl;
	//ensure energy dosent reach above 100.
	if (energy >= 100) {
		energy = 100;
	}
}

//This function allows you to feed the pet to replenish hunger.
void feed(int choice, int& hunger) {
	switch (choice) {
	case 1:
		cout << "You fed your pet a small snack." << endl;
		hunger += 5;
		break;
	case 2:
		cout << "You gave your pet a balanced meal." << endl;
		hunger += 10;
		break;
	case 3:
		cout << "You fed your pet a full meal." << endl;
		hunger += 15;
		break;
	case 4:
		cout << "You prepared a gourmet meal for your pet." << endl;
		hunger += 20;
		break;
	case 5:
		cout << "You put out a feast for your pet." << endl;
		hunger += 25;
		break;
	default:
		cout << "Invalid choice. " << endl;
	}

	//ensure hunger dosent reach above 100.
	if (hunger >= 100) {
		hunger = 100;
	}
}