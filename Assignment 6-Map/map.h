//Sulav Poudyal
//CS 2413
//3/9/2016
//It contains the data structure and prototype of functions used in the program





#ifndef _MAP
#define _MAP

#include"stdheader.h"

struct _token
{
	char text[101];
};
typedef struct _token key;
typedef struct _token value;

struct _entry
{
	key k;
	value v;
};

typedef struct _entry entry;
struct _oa_entry
{
	int state;
	entry e;
};
typedef struct _oa_entry oaEntry;
struct _oa_hashtable
{
	int *prime;
	oaEntry *array;
	int i;
	int po;
};
typedef struct _oa_hashtable map;
int sameKey(key* k1, key* k2);
void print_table(map* m);
unsigned long hash(unsigned int prime, unsigned char*c, unsigned int length, unsigned long table_size);
map* createMap();
long lookup2(map *m,key k);
value* lookup(map *m,key k);
void define(map *m, key k, value v);
void resize(map *m);
void delete(map*m, key k);
#endif





