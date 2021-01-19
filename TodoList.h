#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"
using namespace std;

class TodoList: public TodoListInterface {
public: 
	vector <string> tasks;
	//Constructor
	TodoList() {
		cout << "In Constructor" << endl;
		ifstream infile ("TODOList.txt");
		string line;
		if (infile.is_open())
		{
			while (getline(infile,line))
			{
				cout << line << endl;
				tasks.push_back(line);
			}
			infile.close();
		}
	}    
	//Destructor
	virtual ~TodoList() {
		cout << "In Destructor" << endl;
		ofstream outfile;
		outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tasks.size(); i++){
			cout << tasks[i] << endl;
			outfile << tasks[i] << endl;
		}
		outfile.close();
	}  

	//add    
	virtual void add(string _duedate, string _task) {
		cout << "In add " << _duedate+" " << _task << endl;
		tasks.push_back(_duedate +" "+ _task);
	}    
	
	/*    *   Removes an item from the todo list with the specified task name    *    *   Returns 1 if it removes an item, 0 otherwise    */    
	virtual int remove(string _task){
		cout << "In Remove" << endl;
		for (int i = 0; i < tasks.size(); i++){
			if (_task == tasks.at(i)){
				//DELETE STUFF & RETURN ZERO & have a bool
			}
			//IF BOOL HASNT FLIPPED (NO MATCH) RETURN ZERO
		}
	}
	
	//Print    
	virtual void printTodoList(){
		cout << "In Print" << endl;
		for (int i = 0; i < tasks.size(); i++){
			cout << tasks.at(i) << endl;
		}
	}    
	/*    *   Prints out all items of a todo list with a particular due date (specified by _duedate)    */    
	virtual void printDaysTasks(string _date){
		cout << "In days Tasks" << endl;
		/*if (_date == tasks.at(i)){
			cout << tasks.at(i) << endl;
		}*/
	}
};
	
#endif