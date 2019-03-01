#include "interact.h"

Interact::Interact() {
    base = new Base();
    is_on = true;
    init();
}

void Interact::clear() {
    std::cout << "\x1B[2J\x1B[H";
}

int Interact::init() {
    while(is_on) {
        clear();
        draw_main_choose();
    }
    return 0;
}

void Interact::draw_main_choose() {
    std::cout << "Please, choose what's next: \n" <<
         "1. Add OEF record;\n"             <<
         "2. Show all present records;\n"   <<
         "3. Find particular record;\n"     <<
         "4. Load database from file; \n"   <<
         "5. Save database;\n"              <<
         "6. Exit.\n";
    int decision;
    while(!(std::cin >> decision || (decision < 1 && decision > 6))){
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (decision) {
        case 1:
            draw_add();
            break;            
        case 2:
            draw_base();
            break;
        case 3:
            draw_find();
            break;
        case 4:
            draw_load();
            break;
        case 5:
            draw_save();
            break;
        case 6:
            is_on = false;
            break;
    }


}

void Interact::draw_add() {
    clear();
    std::string name, compName;
    int type;
    float op_price, avg_change;
    std::cout << "Enter the name: \n" << std::endl;
    std::cin >> name;
    std::cout << "Enter the company name: \n";
    std::cin >>compName;
    std::cout << "Enter the type: (1)interval, (2)open, (3)closed\n";
    while(!(std::cin >> type || (type > 0 && type < 4))){
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter the opening price: \n";
    while(!(std::cin >> op_price)){
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter the average price change:\n";
    while(!(std::cin >> avg_change)){
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    base->add(name,compName,op_price, avg_change, type);
    
}


void Interact::draw_base() {    
    if(base->getList().size() == 0)
        std::cout << "The base is empty!"<< std::endl;
    else {
        for (auto &it : base->getList()) {
            std::cout << it.get_name() << "  " << it.get_comp_name() << "  " << it.get_type() << " "
                  << it.get_op_price() << "  " << it.get_avg_change() << std::endl;
        }
    }

    std::cout << "\n\nType something to continue...\n";
    std::string s;
    std::cin >> s;
}

int Interact::draw_found(std::string name, float price) {
        std::cout << "This record found:  "   << 
         name << "  " << price << std::endl   <<
              "\nWhat should we do next?\n"   <<
              "1. Delete it;\n"               << 
              "2. Change it;\n"               <<
              "3. Nothing, I'm just watching\n";
    int dec;
    std::cin >> dec; 
    return dec;
}


void Interact::draw_find() {
    clear();
    std::cout << "Please, choose which field should I find: \n" <<
         "1. Name;\n"             <<
         "2. Company name;\n"   <<
         "3. Number in database;\n"     <<
         "4. Return me back\n"; 

    int decision;
    while(!(std::cin >> decision) || (decision < 1 || decision > 4)){
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch(decision) {
        case 1:
            search_sequence(byName);
            break;
        case 2:
            search_sequence(byComp);
            break;
        case 3:
            search_sequence(byNum);
            break;
        case 4:
            break;
    }

}

void Interact::search_sequence(search_type type) {
    clear();
    if (type == byName) {
        std::string searchName;
        std::cout << "Enter the name:\n";
        std::cin >> searchName;
        int count = 0;
        for(auto & it : base->getList()){
            if (it.get_name() == searchName)
                switch (draw_found(it.get_name(), it.get_op_price())) {
                    case 1:
                        base->getList().erase(base->getList().begin() + count);
                        break; 
                    case 2:
                        std::cout << "Nah, maybe next time";
                        break;
                    case 3:
                        break;
                } 
            count++;
        }
    }
    else if (type == byComp){
        std::string searchName;
        std::cout << "Enter the company name:\n";
        std::cin >> searchName;
        int count = 0;
        for(auto & it : base->getList()){
            if (it.get_comp_name() == searchName)
                draw_found(it.get_name(), it.get_op_price());
            count++;
        }
    }
    else {
        int num;
        std::cout << "Enter the record number:\n";
        std::cin >> num;
        if(num > base->getList().size())
            std::cout << "That's too much";
        else {
            draw_found(base->getList()[num].get_name(), base->getList()[num].get_op_price());
        }
    }
     

}

void Interact::draw_load() {

	if (!base->getList().empty()) base->getList().clear();
	std::cout << "Enter the file name to load: ";
	std::string fileName; std::cin >> fileName;
	std::ifstream file(fileName.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
            int type;
            float openingPrice;
            float avgChange;
            std::string name;
            std::string companyName;
			file >> type;
			file >> openingPrice; 
			file >> avgChange;
			file >> name; 
			file >> companyName;
			if (file.eof()) break;
			base->add(name, companyName, openingPrice, avgChange, type);
		}
	}
}

void Interact::draw_save() {
	if (!base->getList().empty()) {
		std::cout << "Enter the file name to save: ";
		std::string fileName; std::cin >> fileName;
		std::ofstream file(fileName.c_str());
		for (int i = 0; i < base->getList().size(); i++) {
			file << base->getList()[i].get_type() << std::endl;
			file << base->getList()[i].get_op_price() << std::endl;
			file << base->getList()[i].get_avg_change() << std::endl;
			file << base->getList()[i].get_name() << std::endl;
			file << base->getList()[i].get_comp_name() << std::endl;
		}
	} else std::cout << "The list is empty.";
	std::cin.get();
}
