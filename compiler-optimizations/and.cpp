char and_free( char *data ) {
    return data[0] & data[1] & data[2] & data[3] & data[4] & data[5] & data[6] & data[7];
}

char and_list( char *data ) {
    return ((((((data[0] & data[1]) & data[2]) & data[3]) & data[4]) & data[5]) & data[6]) & data[7];
}

char and_reverse( char *data ) {
    return data[0] & (data[1] & (data[2] & (data[3] & (data[4] & (data[5] & (data[6] & data[7]))))));
}

char and_tree( char *data ) {
    return ((data[0] & data[1]) & (data[2] & data[3])) & ((data[4] & data[5]) & (data[6] & data[7]));
}

