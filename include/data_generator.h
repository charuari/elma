#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H
#include "elma.h"
using namespace elma;

//! A helper class to generate random co-ordinates and temperature as json data for client to send to server.
class DataGenerator{
    public:

        //! The constructor with random generation set to srand(0) for testing purpose, otherwise set to srand(time(NULL)) for true random generation.
        DataGenerator(int min=-5, int max=5): _min(min), _max(max) {
            //srand(time(NULL));
            srand(0);
        }
        json gen(){
            json data;
            data["x"] = _min + rand()%(_max-_min+1);
            data["y"] = _min + rand()%(_max-_min+1);
            double f = (double)rand()/RAND_MAX;
            data["temperature"] = 32 + f*(104-32);
            return data;
        }
    
    private:
        int _max, _min;
};
#endif