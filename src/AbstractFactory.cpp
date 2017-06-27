class MazeFactory
{
	public:
		MazeFactory();
		virtual Maze* MakeMaze() const{
			return new Maze;
		}

		virtual Wall* MakeWall() const{
			return new Wall;
		}

		virtual Room* MakeRoom(int n) const{
			return new Room(n);
		}

		virtual Door* MakeDoor(Room* r1, Room r2) const{
			return new Door(r1, r2);
		}
};

Maze* MazeGame::CreateMaze(MazeFactory factory)
{
	Maze* amaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* door = factory.MakeDoor(r1, r2);

	amaze->AddRoom(r1);
	amaze->AddRoom(r2);

	r1->SetSide(North, factory.MakeWall());
	r1->SetSide(South, door);
	r1->SetSide(West, factory.MakeWall());
	r1->SetSide(East, factory.MakeWall());

	r2->SetSide(North, factory.MakeWall());
	r2->SetSide(South, door);
	r2->SetSide(West, factory.MakeWall());
	r2->SetSide(East, factory.MakeWall());

	return amaze;
}

class AbstractProductA{
	public:
		AbstractProductA(){};
		virtual ~AbstractProductA(){};
};

class ConcreteProductA1:public AbstractProductA{
	pulbic:
		ConcreteProductA1(){};
		virtual ~ConcreteProductA1(){};
};

class ConcreteProductA2: public AbstractProductA {
	pulbic:
		ConcreteProductA2(){};
		virtual ~ConcreteProductA2(){};
};

class AbstractProductB{
	public:
		AbstractProductB(){};
		virtual ~AbstractProductB(){};
};

class ConcreteProductB1: public AbstractProductB{
	pulbic:
		ConcreteProductB1(){};
		virtual ~ConcreteProductB1(){};
};

class ConcreteProductB2: public AbstractProductB {
	pulbic:
		ConcreteProductB2(){};
		virtual ~ConcreteProductB2(){};
};

class AbstractFactory{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();
		virtual AbstractProductA* createProductA() = 0;
		virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1:public AbstractFactory{
	public:
		ConcreteFactory();
		~ConcreteFactory();
		virtual AbstractProductA* createProductA();
		virtual AbstractProductB* createProductB();
};

AbstractProductA* ConcreteFactory1::createProductA(){
	return new ConcreteProductA1();	
}

AbstractProductB* ConcreteFactory1::createProductB(){
	return new ConcreteProductB1();	
}
