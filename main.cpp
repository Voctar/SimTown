#include <iostream>

class Storey {
	public:
		Storey(): source_(serial_number_), uid_(serial_number_){
			std::cout << "Storey::Storey() id = " << uid_ << ", at " << this << std::endl;
			++serial_number_;
		};
		
		Storey( const Storey& rhs);
		
		~Storey(){
			std::cout << "Storey::~Storey() id = " << uid_ << ", at " << this << std::endl;
		};
		
		Storey& operator = (const Storey& rhs);
		
		friend std::ostream& operator<< (std::ostream& out, const Storey storey); //global operator, friend to access private member
	private:
		int source_;
		int uid_; // unique identifier
		static int serial_number_; 
};


int Storey::serial_number_ = 1;

Storey::Storey(const Storey& rhs) : source_(rhs.source_), uid_(serial_number_++){
	std::cout << "Storey::Storey(rhs = id = " << rhs.uid_ << " ), uid = " << uid_ << " at " << this << std::endl;
}

Storey& Storey::operator=(const Storey& rhs){
	std::cout << "Storey::operator=(rhs = " << rhs << " on " << *this << std::endl;
	if (this != &rhs){
		source_ = rhs.source_;
		uid_ = serial_number_++;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Storey storey){
	out << "--Storey " << &storey << "id = " << storey.uid_ << ", NFT = " << storey.source_;
	return out;
}



class Building{
	public:
		Building() : id_(-1), storeys_(nullptr), nb_storeys_(0) {
			std::cout << "Building::Building() at " << this << std::endl;
		}
		
		Building(int identifier, int nb_floors=1) : id_(identifier), storeys_(nullptr), nb_storeys_(nb_floors) {
			storeys_ = new Storey[nb_storeys_];
			std::cout << "Building::Building( "<<id_<<" ) at " << this << std::endl;
		}
		
		Building(const Building& rhs): id_(rhs.id_), nb_storeys_(rhs.nb_storeys_){
			std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) at " << this << std::endl;;
			storeys_ = new Storey[nb_storeys_];
			for(int i=0; i<nb_storeys_; i++){
				storeys_[i] = rhs.storeys_[i];
			}
		}

		~Building(){
			std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
			delete[] storeys_;
		}

		Building& operator = (const Building& rhs){
			std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) on " << this << std::endl;
			if(&rhs != this){
				id_ = rhs.id_;
				if(nb_storeys_ != rhs.nb_storeys_){
					delete[] storeys_;
					storeys_ = new Storey[rhs.nb_storeys_];
				}	
				nb_storeys_ = rhs.nb_storeys_;
				for(int i=0; i<nb_storeys_; i++){
					storeys_[i] = rhs.storeys_[i];
				}
			}
			return *this;
		}

		void print (std :: ostream& out) const {
			out << "Building " << id_ << " at " << this << std::endl;
		}
		
		// FONCTION rajoutant etage au bilduing et renvoie l'adresse de l'étage qu'elle vient d'ajouter Storey* create_and_add_storey()
		// nouvelle version avec réorganisation en différents fichiers Storey.h, Storey.cpp, Building.h, Building.cpp, SimTown.cpp

	private:
		int id_;
		Storey* storeys_;
		int nb_storeys_;
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
