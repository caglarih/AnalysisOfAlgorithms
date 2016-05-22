#ifndef SCORELIST
#define SCORELIST

class scorelist{
    int* data;
    int selected;
public:
    scorelist();
    ~scorelist();
    void create(int);
    int find_applicant(int);
    void print_sc();
    void print_fl(int);
};

#endif // SCORELIST

