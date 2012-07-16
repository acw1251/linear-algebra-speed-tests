float add_free( float *data ) {
    return data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7];
}

float add_list( float *data ) {
    return ((((((data[0] + data[1]) + data[2]) + data[3]) + data[4]) + data[5]) + data[6]) + data[7];
}

float add_reverse( float *data ) {
    return data[0] + (data[1] + (data[2] + (data[3] + (data[4] + (data[5] + (data[6] + data[7]))))));
}

float add_tree( float *data ) {
    return ((data[0] + data[1]) + (data[2] + data[3])) + ((data[4] + data[5]) + (data[6] + data[7]));
}

