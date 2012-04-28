#include <stdio.h>
#include "parser.h"

/*int main(int argc, char **argv) {
    if (argc < 2) {
        printf ("Please enter the location of the log file to parse. ");
        printf ("%s path/to/file\n", argv[0]);
        return 0;
    }
    
    //open_file(argv[1]);
    return 0;
}*/
#include <mongo.h>

void insert_data(mongo * conn);

int main(int argc, char **argv) {
    const char * db = "steve_srwc";
    mongo conn[1];
    mongo_cursor cursor[1];
    //bson query[1];
    //bson_iterator it[1];

    if (argc < 3) {
        printf ("Please execute with %s username password\n", argv[0]);
        return 0;    
    }
    
    if (mongo_connect( conn, "ds029817.mongolab.com", 29817 )!= MONGO_OK) {
        printf ("connection failed\n");
        exit(1);
    } else {
        printf ("connected ok\n");
    }

    if (mongo_cmd_authenticate(conn, db, argv[1], argv[2])==MONGO_OK) {
        printf ("authenticated ok\n");
    } else {
        printf ("authentication failed\n");
    }

    mongo_cursor_init(cursor, conn, "steve_srwc.srwc_player");
    while (mongo_cursor_next(cursor) == MONGO_OK) {
        bson_print(&cursor->current);
    }
    
    insert_data(conn);
    mongo_cursor_init(cursor, conn, "steve_srwc.srwc_player");
    
    while (mongo_cursor_next(cursor) == MONGO_OK) {
        bson_print(&cursor->current);
    }

    mongo_cursor_destroy(cursor);
    mongo_destroy( conn );

    return 0;
}

void insert_data(mongo * conn) {
    const int frags = 33;
    const int deaths = 21;
    const double ratio = frags / deaths;
    bson b[1];
    bson_init(b);

    bson_append_new_oid(b, "_id");
    bson_append_string(b, "Name", "KANKERNAP");
    bson_append_int(b, "Frags", frags);
    bson_append_int(b, "Deaths", deaths);
    bson_append_double(b, "KillDeathRatio", ratio);
    bson_finish(b);

    if (mongo_insert(conn, "steve_srwc.srwc_player", b) != MONGO_OK) {
        printf("insert_data != ok\n");
    }
    bson_destroy(b);
}
