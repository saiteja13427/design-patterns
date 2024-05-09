//
// Created by saiteja on 7/1/24.
//

#ifndef DESIGN_PATTERNS_PERSON_H
#define DESIGN_PATTERNS_PERSON_H

class PersonBuilder;

class person {
    //address
    std::string street_address, post_code, city;

    //employement
    std::string company_name, position;
    int annual_income{0};

    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};


#endif //DESIGN_PATTERNS_PERSON_H
