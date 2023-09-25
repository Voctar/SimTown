#ifndef STOREY
#define STOREY

class Storey {
	public:
		Storey();
		
		Storey(const Storey& rhs);
		
		~Storey();

		Storey& operator = (const Storey& rhs);
		
		friend std::ostream& operator<< (std::ostream& out, const Storey storey); //global operator, friend to access private member

	private:
		int source_;
		int uid_; // unique identifier
		static int serial_number_; 
};


int Storey::serial_number_ = 1;

#endif