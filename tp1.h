//attacks
#define FIRE_ATTACK 1.2
#define WATER_ATTACK 1.0
#define NORMAL_ATTACK 1.0
#define GRASS_ATTACK 0.9
#define PSY_ATTACK 1.1

//HP
#define FIRE_HP 93.0
#define WATER_HP 100.0
#define NORMAL_HP 102.0
#define GRASS_HP 103.0
#define PSY_HP 93.0

//colors
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_F     "\x1b[41m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_F  "\x1b[43m"
#define AZUL_F      "\x1b[44m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_F   "\x1b[47m"

//pokemons struct
typedef struct{
    int control;
    char type[10];
    float hp;
    float attack;
}pokemons;


//prototypes
int RandInt(int lower, int upper,int count); 
void initializeMatriz(pokemons **matriz, int rows, int cols, int cPokemons);
void viewMatriz(pokemons **matriz, int rows, int cols);
void makePPM(pokemons **matriz, int rows, int cols, int turn);
void attacks(pokemons **matriz, int rows, int cols);
void setPokemon(pokemons **matriz, int rows, int cols, char type);
float damageBooster(char type1, char type2);
void viewResults(pokemons **matriz, int rows, int cols, int cPokemons);
void help(void);
pokemons **grid_create(int rows, int cols);
int validatePosicion(int rows, int cols, int i, int j);
void subAttack(pokemons **matriz, int actualRow, int actualCol, int attackRow, int attackCol);
int fParser(int argc, char **argv, int *rows, int *cols, int *n, int *maxTurns, int *mode, int *cPokemons);