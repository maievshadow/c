enum Direction {North, South, East, West};
class MapSite{
	public:
		virtual void enter() = 0;
};

class Room : public MapSite {
	public:
		Room(int roomNo);
		Mapsite* getSide(Direction) const;
		void setSide(Direction, Mapsite*);
		virtual void enter();
	private:
		MapSite* _sides[4];
		int _roomNmber;
};

class Wall: public MapSite{
	public:
		Wall();
		virtual void enter();
};

class Door: public  MapSite{
	public:
		Door(Room* = 0, Room* =0);
		virtual void enter();
		Room* OtherSideFrom(Room *);
	private:
		Room* _room2;
		Room* _room2;
		bool _isOpen;
};

class Maze{
	public:
		Maze();
		void AddRoom(Room*);
		Room* RoomNo(int) const;
	private:
		_a;
};

class MazeGame{
	public:
		Maze* createMaze();
}

Maze* MazeGame:: createMaze()
{
	Maze* amaze = new Maze();
	Room* r1 = new Room(1);
	Room* r2 = new Room(2);
	Door* door = new Door(r1, r2);

	amaze->AddRoom(r1);
	amaze->AddRoom(r2);

	r1->setSide(North, new Wall);
	r1->setSide(East, door);
	r1->setSide(South, new Wall);
	r1->setSide(West, new Wall);

	r2->setSide(North, new Wall);
	r2->setSide(East, door);
	r2->setSide(South, new Wall);
	r2->setSide(West, new Wall);

	return amaze;
}

