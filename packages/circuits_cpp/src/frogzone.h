#ifndef FROGZONE_H
#define FROGZONE_H

#define NUM_OBSTACLES 96
#define NUM_PLAYERS 4
#define NUM_ITEMS 10
#define NUM_MONSTERS 6

#define HEIGHT 64
#define WIDTH 64

struct Coord {
    unsigned char x;
    unsigned char y;

    bool operator==(Coord rhs) {
        return (x == rhs.x) && (y == rhs.y);
    }
};

struct Coords5 {
    Coord values[5];
};

enum Direction {
    Up,
    Down,
    Left,
    Right,
};

struct Obstacles100 {
    Coord values[NUM_OBSTACLES + NUM_PLAYERS];
};

struct PlayerData {
    Coord loc;
    unsigned char hp;
    unsigned char atk;
};


struct PlayerWithId {
    unsigned char id;
    PlayerData data;
};

struct ItemData {
    Coord loc;
    unsigned char hp;
    unsigned char atk;
    bool is_consumed;
};

struct ItemWithId {
    unsigned char id;
    ItemData data;
};

struct Items {
    ItemData values[NUM_ITEMS];
};

struct ItemsWithId {
    ItemWithId values[NUM_ITEMS];
};

struct MonsterData {
    Coord loc;
    unsigned char hp;
    unsigned char atk;
};

struct MonsterWithId {
    unsigned char id;
    MonsterData data;
};

struct Monsters {
    MonsterData values[NUM_MONSTERS];
};

struct MonstersWithId {
    MonsterWithId values[NUM_MONSTERS];
};

struct ApplyMoveOut {
    PlayerData player_data;
    Items items;
    Monsters monsters;
};

struct PlayersWithId {
    PlayerWithId values[NUM_PLAYERS];
};

enum EntityType {
    Invalid,// 0b000
    Player, // 0b001
    Item,   // 0b010
    Monster,// 0b011
    None,   // 0b100
};

struct CellData {
    EntityType entity_type;
    unsigned char entity_id;
    unsigned char hp;
    unsigned char atk;

    CellData() {
        entity_type = None;
        entity_id = 0;
        hp = 0;
        atk = 0;
    }
};

struct CellDatas5 {
    CellData values[5];
};

CellData get_cell_no_check(
                           Coord coord,
                           MonstersWithId monsters,
                           ItemsWithId items,
                           PlayersWithId players);
bool invalid_coord_x(
                 Coord player_coord,
                 Coord query_coord
                 );
bool invalid_coord_y(
                 Coord player_coord,
                 Coord query_coord
                 );
bool invalid_coord(
                 Coord player_coord,
                 Coord query_coord
                 );

ApplyMoveOut apply_move(
                        PlayerData player_data,
                        Direction direction,
                        Obstacles100 obstacles,
                        Monsters monsters,
                        Items items);

CellData get_cell(
                  Coord player_coord,
                  Coord query_coord,
                  MonstersWithId monsters,
                  ItemsWithId items,
                  PlayersWithId players
                  );

CellDatas5 get_five_cells(
                          Coord player_coord,
                          Coords5 query_coords,
                          MonstersWithId monsters,
                          ItemsWithId items,
                          PlayersWithId players
                         );

CellDatas5 get_cross_cells(
                          Coord player_coord,
                          MonstersWithId monsters,
                          ItemsWithId items,
                          PlayersWithId players
                         );

CellDatas5 get_horizontal_cells(
                          Coord player_coord,
                          Coord query_coord,
                          MonstersWithId monsters,
                          ItemsWithId items,
                          PlayersWithId players
                         );

CellDatas5 get_vertical_cells(
                          Coord player_coord,
                          Coord query_coord,
                          MonstersWithId monsters,
                          ItemsWithId items,
                          PlayersWithId players
                         );

#endif  // FROGZONE_H
