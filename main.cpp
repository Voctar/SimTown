#include <iostream>

class Building{
	public:
		Building() : id_(-1) {
			std::cout << "Building::Building() at " << this << std::endl;
		}
		Building(int identifier) : id_(identifier) {
			std::cout << "Building::Building( "<<id_<<" ) at " << this << std::endl;
		}
		~Building(){
			std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
		}
		Building& operator=(const Building& rhs){
			if(&rhs != this){
				id_ = rhs.id_;
			}
			return *this;
		}
		void print (std :: ostream& out) const {
			out << "Building " << id_ << " at " << this << std::endl;
		}
	private:
		int id_;
};

int main( int argc, char ** argv){
	std::cout << "Welcome to SimTown! Please enter building IDs (-99 to end)" << std::endl;
	int index = 0;
	Building* street[10];
	for (int i=0; i<10 ; ++i){
		street[i] = nullptr;
	}	
	std::cin >> index;
	int counter = 0;
	while(index!= -99 && counter <10){
		street[counter] = new Building(index);
		street[counter]->print(std::cout);
		std::cin >> index;
		counter++;
	}
	for (int i=0; i<10 ; ++i){
		if(street[i] != nullptr){
			street[i]->print(std::cout);
		}	
	}
	for (int i=0; i<10 ; ++i){
		delete street[i];	
	}
	std::cout<<"Done" << std::endl;
	return 0; // Normal termination
}
