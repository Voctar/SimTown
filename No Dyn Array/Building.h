#ifndef BUILDING
#define BUILDING
#include <iostream>

// forward declaration
class Storey;

class Building{
	public:
		Building();
		
		Building(int identifier, int nb_floors=1);
		
		Building(const Building& rhs);

		~Building();

		Building& operator = (const Building& rhs);
		
		Storey* create_and_add_storey();

		friend std::ostream& operator<<(std::ostream& out, const Building& building);

//		Storey operator [] (int etage) const {
//			return storeys_[etage];
//		}

	private:
		int id_;
		Storey* storeys_;
		int nb_storeys_;
		void clone_storeys(Storey* to, Storey* from);

};

#endif

