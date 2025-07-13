#ifndef DIE_H
#define DIE_H

class Die{

    private:
        int sides; 

    public:
        Die();

        Die(int num_sides);

        int roll(); // returns the value rolled 
};

#endif