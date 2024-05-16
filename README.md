# Cyber-Pet
Year1, Semester 1 CMP 104 programming project.

# Cyberpet Program

## Description
This program simulates taking care of a virtual pet, allowing users to interact with it by checking its status, playing with it, feeding it, and letting it rest. The pet's well-being is determined by its hunger, energy, and happiness levels, which are affected by the user's actions.

## How to Use
1. Run the program.
2. Enter a name for your cyberpet.
3. Choose from the following options:
   - **Check Status:** View the current hunger, energy, and happiness levels of your pet.
   - **Play:** Interact with your pet by playing various activities, which affect its happiness and energy levels.
   - **Feed:** Feed your pet to replenish its hunger.
   - **Rest:** Allow your pet to rest to replenish its energy, but it may affect its hunger and happiness.
   - **Quit:** Exit the program.

## Libraries Used
- `iostream`: For input/output operations.
- `string`: For handling strings.
- `cstdlib`: For system-related operations.
- `using namespace std;`: To avoid typing `std::` before standard library functions.

## Functionality
- The program keeps track of the pet's hunger, energy, and happiness levels.
- Users can perform actions that affect the pet's status, such as playing, feeding, and resting.
- The pet's status is displayed after each action, and the program terminates if the pet's levels reach zero.
- The program utilizes functions with references to modify the pet's status directly.

## Function Prototypes
- `bool Status(int&, int&, int&)`: Checks and displays the pet's current status.
- `void Play(int, int&, int&)`: Allows the user to play with the pet, affecting its happiness and energy levels.
- `void feed(int, int&)`: Allows the user to feed the pet to replenish its hunger.
- `void rest(int, int&, int&, int&)`: Allows the pet to rest, replenishing its energy but potentially affecting hunger and happiness.

## Main Function
- Initializes variables for the pet's name, hunger, energy, and happiness levels.
- Displays a menu for user interaction, looping until the user decides to quit or the pet's status becomes critical.
- Handles user input using a switch statement to perform various actions.
- Checks if the pet's levels reach zero and terminates the program if so.

## Function Definitions
- `Status`: Checks and displays the pet's hunger, energy, and happiness levels.
- `Play`: Allows the user to play with the pet, modifying its happiness and energy levels based on the chosen activity.
- `feed`: Allows the user to feed the pet, increasing its hunger based on the chosen food.
- `rest`: Allows the pet to rest, increasing its energy while potentially affecting hunger and happiness.
