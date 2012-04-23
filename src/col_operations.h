#ifndef COLLECTION_OPERATIONS_H
#define COLLECTION_OPERATIONS_H

#include <mongo.h>

typedef struct Record {
    char * oid;
    char * name;
    int frags;
    int deaths;
    double ratio;
};

typedef struct Settings {
    mongo * connection;
    char * username;
    char * password;
};

int initialise_mongo(const char * db_url, const char * username, const char * pw);
void insert_record(mongo * conn, const char * collection, struct Record r);
void update_record(mongo * conn, const char * collection, struct Record r);
void print_collection(mongo * conn, const char * collection);
void find_single_record(mongo * conn, const char * collection, void * to_find);
void find_multiple_records(mongo * conn, const char * collection, void * to_find);

#endif

