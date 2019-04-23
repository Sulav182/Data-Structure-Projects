//Sulav Poudyal
//3/9/16
//Data Structures 2413
//This file contains all the necessary function definitions of the program



#include"map.h"


unsigned long hash(unsigned int prime, unsigned char*c, unsigned int length, unsigned long table_size)
{
	unsigned long a=0;
	unsigned int i =0;
	for(i=0;i<length; i++)
		a=prime*a+c[i];
	return a%table_size;
}

map* createMap()
{
	//printf("In Map: line 2\n");

	map *m=(map*)malloc(sizeof(map));
	m->i=2;

	memset(m,0,sizeof(m->prime[m->i]));
	int primes[9];
	primes[0] =2;
	primes[1]=3;
	primes[2]=5;
	primes[3]=7;
	primes[4]=13;
	primes[5]=29;
	primes[6]=59;
	primes[7]=113;
	primes[8]=223;
	m->prime = (int*)malloc(sizeof(int)*9);
	//printf("In Map: line 2\n");
	int j =0;
	for(j;j<9;j++)
		m->prime[j]=primes[j];

	//printf("In Map: line 3\n");
	int i;
	m->array=(oaEntry*)malloc(sizeof(oaEntry)*m->prime[m->i]);
	//printf("In Map: line 4\n");
	for(i = 0; i < m->prime[m->i]; i++){
		//printf("Assigning state to 1\n");
		m->array[i].state = 1;
	}

	int k;
	///printf("After create\n");
	//for(k = 0; k < m->prime[m->i]; k++){
	//	printf("State: %d\n",m->array[k].state);
	//}
	//printf("In Map: line 5\n");
	m->po=0;
	return m;

}
//void memset((void*),int a, int num)
int sameKey(key *k1, key *k2)
{
	if(strcmp(k1->text,k2->text)==0)
		return 1;
	else
		return 0;
}

value *lookup(map *m,key k)
{
	long index = lookup2(m,k);
	printf("Index after lookup2 %d\n",index);
	if(index==-1)
	{
		printf("Entry for Key:%s Not Found\n",(char*) &k);
		return NULL;
	}
	else
	{
		printf("Entry for Key:%s Found At Index:%d\n",(char*)&k, index);
		return &m->array[index].e.v;
	}
}


long lookup2(map *m,key k)
{
	//printf("Index we got before loop %d\n",index);
	int l;
	//printf("printing out states upon entering lookup2\n");
	//for(l = 0; l < m->prime[m->i]; l++){
	//	printf("state: %d\n", m->array[l].state);
	//}
	int a=0;
	unsigned long start = hash(m->prime[m->i-1],(unsigned char*)&k, sizeof(key), m->prime[m->i]);
	unsigned long offset = 1 + hash(m->prime[m->i-2],(unsigned char*)&k,sizeof(key), m->prime[m->i]);
	unsigned long index = start;
	//printf("index %d\n", index);
	if(offset==0)
		offset=1;


	//printf("%d\n",m->array[index].state);
	//	for(a;a<(m->prime[m->i]);a++)
	//printf("Offset: %d ",offset);
	//printf("State: %d\n",m->array[a].state);
	//printf("Index we got before loop %d\n",index);
	while (m->array[index].state!=1)
	{
		printf("** Looking For Key:%s At Index:%d OFFSET:%d\n",(char*)&k,index,offset);
		//printf("m->array[index].state = %d\n", m->array[index].state);
		if(m->array[index].state==2)
		{
			if(sameKey(&k,&m->array[index].e.k)==1)
			{
				printf("Keys are the same");
				return index;
			}
		}
		//Test
		offset++;
		if(offset > 10){
					break;
		}

		index=(index+offset)%m->prime[m->i];

	}
	//printf("Exited while.\n");
	return -1;

}

void define(map *m, key k, value v)
{

	long index = lookup2(m,k);
	//printf("In Define: line 2\n");
	if(index>-1)
	{
		m->array[index].e.v = v;
		printf("Updating Entry For Key:%s At Index:%d\n", (char*) &k,index);
		return;
	}
	//printf("In Define: line 3\n");
	unsigned long start = hash(m->prime[m->i-1],(unsigned char*)&k, sizeof(key),m->prime[m->i]);
	unsigned long offset = 1 + hash(m->prime[m->i-2],(unsigned char*)&k, sizeof(key),m->prime[m->i]);
	index = start;
	if(offset==0)
		offset=1;
	//printf("In Define: line 4\n");
	while(m->array[index].state!=1)
	{
		//printf("You are here\n");
		//printf("In Define: line 5 index is %d \n",index);
		if(m->array[index].state==3)
		{
			m->array[index].e.k = k;
			m->array[index].e.v=v;
			m->array[index].state = 2;
			printf("Creating Entry For Key:%s At PO Index:%d\n",(char*) &k,index);
			return;
		}
		//Test
		offset++;
		if(offset > 10){
			break;
		}

		index = (index + offset)% m->prime[m->i];

	}
	//printf("In Define: line 6\n");

	m->array[index].e.k = k;
	m->array[index].e.v = v;
	m->array[index].state = 2;
	printf("Creating Entry For Key:%s At NO Index:%d\n", (char*) &k,index);
	m->po++;
	//printf("State: %d\n",m->array[index].state);
	if(m->po > m->prime[m->i]/2)
		resize(m);

}

void resize(map *m)
{
	oaEntry *old = m->array;
	unsigned long oldSize = m->prime[m->i];
	m->i++;
	m->po=0;
	printf("RESIZING: FROM:%d TO:%d\n", m->prime[m->i-1],m->prime[m->i]);
	m->array = (oaEntry*) malloc(sizeof(oaEntry)*m->prime[m->i]);
	int j = 0;
	for(j;j<m->prime[m->i];j++){
		//printf("goodbye\n");
		m->array[j].state=1;
	}
	int i=0;
	for(i;i<oldSize;i++)
	{
		//printf("hello\n");
		if(old[i].state==2)
			define(m,old[i].e.k,old[i].e.v);
	}
	free(old);
	printf("DONE RESIZING\n");
}

void delete(map*m, key k)
{
	long index = lookup2(m,k);
	if (index==-1)
		printf("Entry for Key:%s Not Found\n",(char*)&k);
	else
	{
		m->array[index].state=3;
		printf("Deleting Entry for Key:%s At Index:%d\n",(char*)&k,index);
	}
}


void print_table(map* m)
{
	int i=0;
	for(i;i<m->prime[m->i];i++)
		printf("Key %s, Value %s, State %d\n",m->array[i].e.k.text,m->array[i].e.v.text, m->array[i].state);

}








