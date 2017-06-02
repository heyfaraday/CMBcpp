#pragma once

class Alm_Base {

private:

    unsigned int n_mod;
    long double** array_cos;
    long double** array_sin;

public:

    Alm_Base(unsigned int n_mod_input);

    virtual ~Alm_Base();

    unsigned int get_n_mod() const;

    long double at_cos(unsigned int l, unsigned int m) const;

    void to_cos(unsigned int l, unsigned int m, long double value);

    long double at_sin(unsigned int l, unsigned int m) const;

    void to_sin(unsigned int l, unsigned int m, long double value);

    void fout(std::string name_cos, std::string name_sin) const;

    void fin(std::string name_cos, std::string name_sin);

    void fout_8(std::string name_cos, std::string name_sin) const;

};
