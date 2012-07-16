int add_free( int *data ) {
    return data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7];
}

int add_list( int *data ) {
    return ((((((data[0] + data[1]) + data[2]) + data[3]) + data[4]) + data[5]) + data[6]) + data[7];
}

int add_reverse( int *data ) {
    return data[0] + (data[1] + (data[2] + (data[3] + (data[4] + (data[5] + (data[6] + data[7]))))));
}

int add_tree( int *data ) {
    return ((data[0] + data[1]) + (data[2] + data[3])) + ((data[4] + data[5]) + (data[6] + data[7]));
}

