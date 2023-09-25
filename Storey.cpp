#include "Storey.h"


Storey::Storey(): source_(serial_number_), uid_(serial_number_){
	std::cout << "Storey::Storey() id = " << uid_ << ", at " << this << std::endl;
	++serial_number_;
}

		
Storey::Storey(const Storey& rhs) : source_(rhs.source_), uid_(serial_number_++){
	std::cout << "Storey::Storey(rhs = id = " << rhs.uid_ << " ), uid = " << uid_ << " at " << this << std::endl;
}

		
Storey::~Storey(){
	std::cout << "Storey::~Storey() id = " << uid_ << ", at " << this << std::endl;
}

	
Storey& Storey::operator=(const Storey& rhs){
	std::cout << "Storey::operator=(rhs = " << rhs << " on " << *this << std::endl;
	if (this != &rhs){
		source_ = rhs.source_;
		uid_ = serial_number_++;
	}
	return *this;
}
		
		
std::ostream& operator<<(std::ostream& out, const Storey storey){      //global operator, friend to access private member
	out << "--Storey " << &storey << "id = " << storey.uid_ << ", NFT = " << storey.source_;
	return out;
} 
