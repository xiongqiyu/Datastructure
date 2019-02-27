/*
	First name	XXX
	Last name		XXX
	Student ID	XXXXXX (e.g. 01234567)
	Username		XXX (e.g. aaa123)	
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)


#include <iostream>
#include <string>
#include <queue>
#include <stack>

// do not use using namespace std

// do not alter the struct declaration
struct node {
	char id;
	node* north;
	node* south;
	node* east;
	node* west;
};

// do not alter the typedef 
typedef node* nodeptr;

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

void build_basic_maze(nodeptr& start, nodeptr& finish);
// builds the basic maze displayed in page 1

nodeptr traverse_maze(const nodeptr& start, const std::string& path);
// traverses the maze using a predefined path

void solve_interactively(const nodeptr& start, const nodeptr& finish, std::string& path);
// allows the user to solve the maze interactively

nodeptr random_walk(const nodeptr& start, const nodeptr& finish, std::string& path);
// simulates a random walk in the maze 

void solve_queue(const nodeptr& start, const nodeptr& finish, std::string& path);
// an improvement of the random walk: solves the maze using a queue to store the unvisited neighbours of the current node

void solve_stack(const nodeptr& start, const nodeptr& finish, std::string& path);
// an improvement of the random walk: solves the maze using a stack to store the unvisited neighbours of the current node


// you can define and add use additional functions if you might need to

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)
/*int main() {

	// YOUR CODE HERE


	return 0;
}*/




/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

// YOUR CODE HERE
