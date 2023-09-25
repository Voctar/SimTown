#include "Building.h"
#include "Storey.h"


Building::Building() : id_(-1), storeys_(nullptr), nb_storeys_(0) {
	std::cout << "Building::Building() at " << this << std::endl;
}


Building::Building(int identifier, int nb_floors=1) : id_(identifier), storeys_(nullptr), nb_storeys_(nb_floors) {
	storeys_ = new Storey[nb_storeys_];
	std::cout << "Building::Building( "<<id_<<" ) at " << this << std::endl;
}


Building::Building(const Building& rhs): id_(rhs.id_), nb_storeys_(rhs.nb_storeys_){
	std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) at " << this << std::endl;;
	storeys_ = new Storey[nb_storeys_];
	clone_storeys(storeys_, rhs.storeys_, rhs.nb_storeys_);
}


Building::~Building(){
	std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
	delete[] storeys_;
}


Building& Building::operator = (const Building& rhs){
	std::cout << "Building::Building(rhs =  "<< &rhs << ", id_ = " <<rhs.id_<<" ) on " << this << std::endl;
	if(&rhs != this){
		id_ = rhs.id_;
		if(nb_storeys_ != rhs.nb_storeys_){
			delete[] storeys_;
			storeys_ = new Storey[rhs.nb_storeys_];
		}	
		nb_storeys_ = rhs.nb_storeys_;
		clone_storeys(storeys_, rhs.storeys_, rhs.nb_storeys_);
	}
	return *this;
}


void Building::print (std :: ostream& out) const {
	out << "Building " << id_ << " at " << this << std::endl;
}


Storey* Building::create_and_add_storey(){
	Storey* new_storeys = new Storey[nb_storeys_+1];
	clone_storeys(new_storeys, storeys_, nb_storeys_);
	delete[] storeys_;
	storeys_ = new_storeys;
	nb_storeys_++;
	return &storeys_[nb_storeys_-1];
}


void Building::clone_storeys(Storey* storeys, Storey* other_storeys, int other_storeys_lengh){   // other_storeys_lengh should be <= storeys lengh (assert later ?)
	for(int i=0; i<other_storeys_lengh; i++){
		storeys[i] = other_storeys[i];
	}
}