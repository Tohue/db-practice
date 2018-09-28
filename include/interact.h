#ifndef _INTERACT_H_
#define _INTERACT_H_

#include "base.h"
#include "OEF.h"
#include <iostream>
#include <algorithm>

enum search_type {byName, byComp, byNum};
class Interact {
    private:
        bool is_on;
        Base * base;
    public:
        void clear();
        Interact();
        int init();
        void draw_main_choose();
        void draw_add();
        void draw_base();
        void draw_find();
        void search_sequence(search_type type);
        int draw_found(std::string name, float price);
        void draw_load();
        void draw_save();
};


#endif