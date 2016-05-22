#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

class sortableArray{
    int *data;
    int length;
public:
    bool create(int,const char*);
    void print_screen();
    bool print_txt();
    void sort_quick();
    void sort_radix();
    bool sort_counting(int n);
    sortableArray();
    ~sortableArray();
};



#endif // SORTABLEARRAY_H

