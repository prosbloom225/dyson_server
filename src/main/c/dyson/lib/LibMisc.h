#ifndef LIBMISC_H
#define LIBMISC_H

class LibMisc {
    public:
        static const int TICKRATE = 20;
        static constexpr const char* MODITEMS_JSON = "./src/main/resources/dyson/item/ModItems.json";
        enum items {
            WEAPON,
            ARMOR
        };
};

#endif
