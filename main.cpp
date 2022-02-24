#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "node1.h"

using namespace std;

void show_list(node* display, int position);
// Postcondition: The items on display have been printed to cout (one per line).

node* insertionSort(node* head);
// function to sort a singly linked list using insertion sort

node* sortedInsert(node* sorted_head, node* new_node);



int main(int argc, char** argv) {
	string node_data;
	node* link_list;
	int position=1;
	
	link_list=NULL;	
	// Read from the text file
	ifstream my_file("input.txt");
	
	// Use a while loop together with the getline() function to read the file line by line
	while (getline (my_file, node_data)) {
		list_insert_at(link_list, node_data, position);
		++position;
	}
	// Close the file
	my_file.close();
	
	cout<<"Words in the whole LinkedList"<<endl;
	//Print out the whole list
	show_list(link_list,1);
	
	//Prompt user for the starting and end positions of the sublist
	cout<<"\nChoose the start position of the sublist: ";
	size_t start_position;
	cin>>start_position;
	cout<<"\nChoose the end position of the sublist: ";
	size_t end_position;
	cin>>end_position;
	
	//Extract the sublist from the entire list and print it out
	node* sub_list = list_copy_segment(link_list, start_position, end_position);
	cout<<"\n\nWords in the unsorted sub-LinkedList"<<endl;
	show_list(sub_list, start_position);
	//Sort the sublist and print it out
	sub_list=insertionSort(sub_list);
	cout<<"\n\nWords in the sorted sub-LinkedList"<<endl;
	show_list(sub_list, 1);
	
		
	
	return 0;
}
void show_list(node* display, int position){
	// Library facilities used: iostream.h
	cout<<left<<setw(20)<<"\nPosition"<<left<<setw(20) <<"Word\n---------------------------------------"<< endl;
	//Loop through the list and print the node data
    while (display != NULL){
		cout<<right<<setw(5)<<position<<right<<setw(20) << display->data << endl;
		display = display->link;
		++position;
    }
}



node* insertionSort(node* head){
    node* current_node = head;
    // Initialize sorted linked list
    node* sorted_list = NULL;
    // Traverse the given linked list and insert every node to sorted
    while (current_node != NULL){
    	// Store next node for next iteration
        node* next_node = current_node->link;
        // insert current node in sorted linked list
        sorted_list = sortedInsert(sorted_list,current_node);
        // Update current node
        current_node = next_node;
    }
    return sorted_list;
}

    /*
     * function to insert a new_node in a list. Note that
     * this function expects a pointer to sorted_list as this
     * can modify the head of the input linked list
     * (similar to push())
     */

node* sortedInsert(node* sorted_list, node* new_node){
    /* Special case for the head end */
    if(sorted_list == NULL || sorted_list->data >= new_node->data){
        new_node->link = sorted_list;
        return new_node;
    } else {
        node* current_node = sorted_list;
        //Locate the node before the point of insertion
        while(current_node->link != NULL && current_node->link->data < new_node->data)
            current_node = current_node->link;
        new_node->link = current_node->link;
        current_node->link = new_node;
    }
    return sorted_list;
}
