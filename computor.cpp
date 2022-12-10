
#include <iostream>
#include <map>
#include <cmath>
#include <complex>

struct Parser {
    std::string inp;
    std::map<long long int, long double> powers;

    struct Pair {
        long long int power;
        long double coeff;
    };

    Parser(const std::string &input) {
        inp = input;
    }

    void parse() {
        size_t start = 0;
        bool invert = false;
        bool negative = false;

        while (start < inp.size()) {
            skip_spaces(start);
            if (start < inp.size() and inp.at(start) == '+')
                ++start;
            else if (start < inp.size() and inp.at(start) == '-') {
                ++start;
                negative = true;
            }
            skip_spaces(start);
            Pair p = parse_term(start);
            if (invert)
                negative = not negative;
            if (negative)
                p.coeff = -p.coeff;
            powers[p.power] += p.coeff;
            if (start < inp.size() and inp.at(start) == '=') {
                if (invert)
                    throw std::invalid_argument("only one '=' can be in equation");
                invert = true;
                ++start;
                skip_spaces(start);
            }
        }
    }

    Pair parse_term(size_t &start) {
        bool was_coeff, was_variable, was_power, waiting_power, waiting_var;
        long double coeff = NAN;
        long long int power = -1;
        std::string variable;

        was_coeff = false;
        was_variable = false;
        was_power = false;
        waiting_power = false;
        waiting_var = false;

        skip_spaces(start);
        coeff = parse_float(start, was_coeff);
        std::cout << "parsed coef " << coeff << std::endl;;
        skip_spaces(start);
        if (was_coeff and start < inp.size() and inp.at(start) == '*') {
            ++start;
            skip_spaces(start);
            waiting_var = true;
        }
        if (not was_coeff)
            coeff = 1.0L;
        variable = parse_string(start, was_variable);
        std::cout << "parsed var " << variable << std::endl;
        if (not was_variable and waiting_var)
            throw std::invalid_argument("expected variable name");
        skip_spaces(start);
        if (start < inp.size() and inp.at(start) == '^') {
            if (was_variable) {
                ++start;
                waiting_power = true;
            } else {
                throw std::invalid_argument("cannot apply power without variable");
            }
        }
        if (waiting_power) {
            power = parse_int(start, was_power);
            std::cout << "parsed power " << power << std::endl;
            skip_spaces(start);
            if (waiting_power && not was_power)
                throw std::invalid_argument("expected power value");
        }
        if (not was_power) {
            if (not was_variable)
                power = 0;
            else
                power = 1;
        }
        return {power, coeff};
    }

    long long int parse_int(size_t &start, bool &was_number)
    {
        char *end;
        long long int ans;

        if (start >= inp.size()) {
            was_number = false;
            return {};
        }
        ans = std::strtoll(inp.data() + start, &end, 10);
        if (end == inp.data() + start) {
            was_number = false;
            return {};
        }
        start += end - inp.data() - start;
        was_number = true;
        return ans;
    }

    long double parse_float(size_t &start, bool &was_number)
    {
        char *end;
        long double ans;

        if (start >= inp.size()) {
            was_number = false;
            return {};
        }
        ans = std::strtold(inp.data() + start, &end);
        if (end == inp.data() + start) {
            was_number = false;
            return {};
        }
        start += end - inp.data() - start;
        was_number = true;
        return ans;
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
            was_string = false;
            return {};
        } else {
            was_string = true;
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

class Solver
{
public:
    Solver(const std::map<long long int, long double> &powers)
        : powers(powers)
    {}

    void check()
    {
        for (auto it = powers.rbegin(); it != powers.rend(); ++it) {
            if (it->first >= 3 and std::abs(it->second) < 1e-10) {
                std::stringstream ss;
                ss << "cannot solve equation of " << it->first << " order";
                throw std::invalid_argument(ss.str());
            }
        }
    }

    void solve() {
        long double a, b, c;

        a = powers.at(2);
        b = powers.at(1);
        c = powers.at(0);
        std::complex<long double> disk;
        disk = b * b - 4 * a * c;
        ld_disk = disk.real();
        disk = std::sqrt(disk);
        first = (-b + disk) / (2 * a);
        second = (-b - disk) / (2 * a);
    }

    const std::map<long long int, long double> &powers;
    std::complex<long double> first;
    std::complex<long double> second;
    long double ld_disk;
};

class Printer
{
    Printer(std::complex<long double> _x1, std::complex<long double> _x2, long double _disk)
        : x1(_x1), x2(_x2), disk(_disk)
    {
        std::stringstream x1ss, x2ss, diskss;

        if (std::abs(disk) < EPS) {
            is_equal_roots = true;
            is_complex_roots = false;
        } else if (disk < 0) {
            is_equal_roots = false;
            is_complex_roots = true;
        } else {
            is_equal_roots = false;
            is_complex_roots = false;
        }

        if (is_complex_roots) {
            x1ss << ""
        }

    }

    void print_disk()
    {

    }

    void print_roots()
    {

    }

    long double EPS = 1e-6;
    std::string disk_str;
    std::string x1_str;
    std::string x2_str;
    std::complex<long double> x1, x2;
    long double disk;
    bool is_complex_roots;
    bool is_rational_roots;
    bool is_equal_roots;
};

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "expected equation argument\n";
        return 1;
    } else if (argc > 2) {
        std::cout << "extra arguments ignored\n";
    }
    Parser p(argv[1]);
    try {
        p.parse();
        for (const auto i : p.powers) {
            std::cout << i.second << "x^" << i.first << " + ";
        }
        std::cout << std::endl;
        Solver s(p.powers);
        s.check();
        s.solve();
        Printer pr(s.first, s.second, s.ld_disk);
        pr.print_disk()
        pr.print_roots();
        std::cout << s.first << ' ' << s.second << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
