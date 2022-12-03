
#include <bits/stdc++.h>

template <class long double>
struct Parser {
    std::string inp;
    map<long double, long double> powers;

    struct pair {
        long long int power;
        long double coeff;
    }

    Parser(std::string &&input) {
        inp = std::move(input);
    }

    struct Pair {
        long long int power;
        long double coeff;
    };

    void parse() {
        size_t start = 0;
        bool invert = false;

        while (start < inp.size()) {
            Pair p = parse_term(start);
            if (invert)
                p.coeff = -p.coeff;
            powers[p.power] = p.coeff;
        }
    }

    Pair parse_term(size_t &start)
    {
        bool was_coeff, was_variable, was_power, waiting_power;
        long double coeff;
        long long int power;
        std::string variable;

        was_coeff = false;
        was_variable = false;
        was_power = false;
        waiting_power = false;
        skip_spaces(start);
        coeff = parse_float(start, was_coeff);
        skip_spaces(start);
        if (was_coeff and start < inp.size() and inp.at(start) == '*') {
            ++start;
            skip_spaces(start);
        }
        if (not was_coeff)
            coeff = 1.0L;
        variable = parse_variable(start, was_power);
        while (not was_variable)
            throw std::invalid_argument("expected variable name");
        skip_spaces(start);
        if (start < inp.size() and inp.at(start) == '^') {
            ++start;
            waiting_power = true;
        }
        power = parse_int(start, was_power);
        skip_spaced(start);
        if (waiting_power && not was_power)
            throw std::invalid_argument("expected power value");
        if (not was_power)
            power = 1;
        return {coeff, power};
    }

    template <class value_type, class func_type>
    value_type parse_number(size_t &start, bool &was_number, func_type func)
    {
        value_type *end;
        value_type ans;

        if (start >= inp.size()) {
            was_number = false;
            return {};
        }
        func(inp.data() + start, &end);
        if (end == inp.data()) {
            was_number = false;
            return {};
        }
        start += end - inp.data();
        was_number = true;
        return ans;
    }

    long long int parse_int(size_t &start, bool &was_number)
    {
        return parse_number<value_type>(start, was_number, std::strtold);
    }

    long double parse_float(size_t &start, bool &was_number)
    {
        return parse_number<value_type>(start, was_number, std::strtoll);
    }

    std::string parse_string(size_t &start, bool &was_string)
    {
        size_t end = start;
        if (end < inp.size() and std::isalpha(inp.at(end))) {
            ++end;
        }
        while (end < inp.size() and std::isalnum(inp.at(end))) {
            ++end;
        }
        if (start == end) {
            was_stirng = false;
            return {};
        } else {
            was_stirng = true;
            std::string ret = inp.substr(start, end - start);
            start += end - start;
            return ret;
        }
    }

    void skip_spaces(size_t &start)
    {
        while (start < inp.size() and std::isspace(inp.at(start)))
            ++start;
    }
};

int main()
{
    std::string input;
    cin.getline(std::cin, input);
    Parser p(input);
    try {
        Parser.parse();
    } catch (std::invalid_argument &e) {
        std::cout << e.what();
        return 1;
    }
}
