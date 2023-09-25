#ifndef BUILDING
#define BUILDING

class Building{
	public:
		Building();
		
		Building(int identifier, int nb_floors=1);
		
		Building(const Building& rhs);

		~Building();

		Building& operator = (const Building& rhs);

		void print (std :: ostream& out) const ;
		
		Storey* create_and_add_storey();

	private:
		int id_;
		Storey* storeys_;
		int nb_storeys_;
		void clone_storeys(Storey* storeys, Storey* other_storeys, int other_storeys_lengh);

};

#endif