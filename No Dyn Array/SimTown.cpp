#include <iostream>
#include <Building.h>

int main( int argc, char ** argv){
	std::cout << "Welcome to SimTown! Please enter the street size." << std::endl;
	int size = 0;
	int nb_etage = 7;
	std::cin>> size;


	Building* street = new Building[size];
	for (int ib=0; ib<size ; ++ib){
		street[ib] = Building(ib, nb_etage);
	}

// resize array
	{
	Building *bigger_street = new Building[size+1];
	for (int i=0; i<size; i++){
		bigger_street[i] = street[i];
	}
	delete[] street;
	++size;
	street = bigger_street;
	}
	{
	Building city_hall(1000, nb_etage);
	Building new_city_hall(city_hall); // Test copy constructor
	street[size-1] = new_city_hall;
	}
	for (int i=0; i<size ; ++i){
			street[i].print(std::cout);
	}

//affichage street
//	for (int i=0; i<nb_etage; i++){
//		for (int j=0; j<size; j++){
//			std::cout << "###### " << &street[j][i] << " ######";
//		}
//	}



//	Storey* new_storey_city_hall=street[size-1].create_and_add_storey();
//	std::cout <<"000000000000000000000000000000000000000000000000000000000000000000000000000000000000   "<<*new_storey_city_hall<<std::endl;
//	street[size-1].print(std::cout);
	delete[] street;
	std::cout<<"Done" << std::endl;
	return 0; // Normal termination
}
