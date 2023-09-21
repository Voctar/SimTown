#include <iostream>

class Storey {
	public:
		Storey(): source_(serial_number_), uid_(serial_number_){
			std::cout << "Storey::Storey() id = " << uid_ << ", at " << this << std::endl;
			++serial_number_;
		};
		Storey( const Storey& rhs);
		~Storey();
		Storey& operator = (const Storey& rhs);
	private:
		int source_;
		int uid_; // unique identifier
		static int serial_number_; 
};

int Storey::serial_number_ = 1;
Storey::Storey(const Storey& rhs) : source_(rhs.source_), uid_(serial_number_++){
	std::cout << "Storey::Storey(rhs = id = " << rhs.uid_ << " ), uid = " << uid_ << " at " << this << std::endl;
}


class Building{
	public:
		Building() : id_(-1) {
			std::cout << "Building::Building() at " << this << std::endl;
		}
		Building(int identifier) : id_(identifier) {
			std::cout << "Building::Building( "<<id_<<" ) at " << this << std::endl;
		}
		Building(const Building& rhs): id_(rhs.id_){
			std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) at " << this << std::endl;
		}
		~Building(){
			std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
		}
		Building& operator = (const Building& rhs){
			std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) on " << this << std::endl;
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
	std::cout << "Welcome to SimTown! Please enter the street size." << std::endl;
	int size = 0;
	std::cin>> size;


	Building* street = new Building[size];
	for (int ib=0; ib<size ; ++ib){
		street[ib] = Building(ib);
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
	Building city_hall(1000);
	Building new_city_hall(city_hall); // Test copy constructor
	street[size-1] = new_city_hall;
	}
	for (int i=0; i<size ; ++i){
			street[i].print(std::cout);
	}

	delete[] street;
	std::cout<<"Done" << std::endl;
	return 0; // Normal termination
}
