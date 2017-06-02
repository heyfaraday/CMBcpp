#pragma once

class Map_Base {

private:

    unsigned int n_pix;
    long double** array;

public:

    Map_Base(unsigned int n_pix_input);

    virtual ~Map_Base();

    unsigned int get_n_pix() const;

    long double at(unsigned int i, unsigned int j) const;

    void to(unsigned int i, unsigned int j, long double value);

    long double at_border(unsigned int i, unsigned int j) const;

    void to_border(unsigned int i, unsigned int j, long double value);

    void fout(std::string name) const;

    void fin(std::string name);

    void fout_8(std::string name) const;

};
