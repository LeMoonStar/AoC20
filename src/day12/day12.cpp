#include "day12.h"

#include <common.h>
#include <cli.h>
#include <math.h>

static cli* cl;

template<typename T>
struct RectengularCoordinate {
    T x, y;
    RectengularCoordinate(T x, T y) : x(x), y(y) {
    }

    RectengularCoordinate operator+ (const RectengularCoordinate& rhs) {
        return RectengularCoordinate(
            this->x + rhs.x,
            this->y + rhs.y
        );
    }

    RectengularCoordinate operator- (const RectengularCoordinate& rhs) {
        return RectengularCoordinate(
            this->x - rhs.x,
            this->y - rhs.y
        );
    }
    
    RectengularCoordinate operator* (const RectengularCoordinate& rhs) {
        return RectengularCoordinate(
            this->x * rhs.x,
            this->y * rhs.y
        );
    }

    RectengularCoordinate operator* (int rhs) {
        return RectengularCoordinate(
            this->x * rhs,
            this->y * rhs
        );
    }

    RectengularCoordinate operator+= (const RectengularCoordinate& rhs) {
        *this = *this + rhs;
        return *this;
    }

    RectengularCoordinate operator-= (const RectengularCoordinate& rhs) {
        *this = *this - rhs;
        return *this;
    }

    RectengularCoordinate operator*= (const RectengularCoordinate& rhs) {
        *this = *this * rhs;
        return *this;
    }

    RectengularCoordinate operator*= (int rhs) {
        *this = *this * rhs;
        return *this;
    }
};

struct PolarCoordinate {
    long double angle;
    long double radius;
    PolarCoordinate(double ang, double rad) : angle(ang), radius(rad) {
    }

    template<typename T>
    PolarCoordinate(RectengularCoordinate<T> rect)
        : radius( sqrt(rect.x*rect.x + rect.y*rect.y) ),
          angle( atan((long double)rect.y/(long double)rect.x) ) {
    }

    template<typename T>
    RectengularCoordinate<T> toRect() const {
        return RectengularCoordinate<T>(radius*cos(angle), radius*sin(angle));
    }
};

struct Instruction {
    enum class Type {
        UNKNOWN,
        NORTH,
        SOUTH,
        EAST,
        WEST,

        LEFT,
        RIGHT,
        FORWARD
    };

    Type type;
    uint16_t value;

    static std::string getNameOfType(Type t) {
        switch (t) {
        case Type::NORTH:
            return "NORTH  ";
            break;
        case Type::SOUTH:
            return "SOUTH  ";
            break;
        case Type::EAST:
            return "EAST   ";
            break;
        case Type::WEST:
            return "WEST   ";
            break;

        case Type::FORWARD:
            return "FORWARD";
            break;
        case Type::RIGHT:
            return "RIGHT  ";
            break;
        case Type::LEFT:
            return "LEFT   ";
            break;
        default:
            return "UNKNOWN";
            break;
        }
    }

    static Type getTypeFromChar(char c) {
        switch (c) {
        case 'N':
            return Type::NORTH;
            break;
        case 'S':
            return Type::SOUTH;
            break;
        case 'E':
            return Type::EAST;
            break;
        case 'W':
            return Type::WEST;
            break;

        case 'L':
            return Type::LEFT;
            break;
        case 'R':
            return Type::RIGHT;
            break;
        case 'F':
            return Type::FORWARD;
            break;
        default:
            return Type::UNKNOWN;
            break;
        }
    }

    Instruction(std::string str) : type(getTypeFromChar(str[0])){
        value = std::stoi(str.erase(0, 1));
    }

    template<typename T>
    void executePart1(RectengularCoordinate<T>* pos, double* facing) {
        switch (type) {
        case Type::NORTH:
            pos->y += value;
            break;
        case Type::SOUTH:
            pos->y -= value;
            break;
        case Type::EAST:
            pos->x += value;
            break;
        case Type::WEST:
            pos->x -= value;
            break;

        case Type::FORWARD:
            *pos += PolarCoordinate(*facing * (M_PI / 180), value).toRect<T>();
            break;
        case Type::RIGHT:
            *facing -= value;
            break;
        case Type::LEFT:
            *facing += value;
            break;
        default:
            break;
        }
    }

    template<typename T>
    void executePart2(PolarCoordinate* w_pos, RectengularCoordinate<T>* pos) {
        switch (type) {
        case Type::NORTH:
            *w_pos = PolarCoordinate(w_pos->toRect<T>() + RectengularCoordinate<T>(0, -1)*value);
            break;
        case Type::SOUTH:
            *w_pos = PolarCoordinate(w_pos->toRect<T>() + RectengularCoordinate<T>(0, 1)*value);
            break;
        case Type::EAST:
            *w_pos = PolarCoordinate(w_pos->toRect<T>() + RectengularCoordinate<T>(-1, 0)*value);
            break;
        case Type::WEST:
            *w_pos = PolarCoordinate(w_pos->toRect<T>() + RectengularCoordinate<T>(1, 0)*value);
            break;

        case Type::FORWARD:
            *pos += w_pos->toRect<T>()*value;
            
            break;
        case Type::RIGHT:
            w_pos->angle -= value * (M_PI / 180);
            break;
        case Type::LEFT:
            w_pos->angle += value * (M_PI / 180);
            break;
        default:
            break;
        }
    }
};

void day12(cli& c) {
    cl = &c;

    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 12 (https://adventofcode.com/2020/day/12)");
    
    std::vector<Instruction> instructions;
    for (auto it = input.begin(); it != input.end(); ++it)
        if (*it != "") instructions.push_back(Instruction(*it));


    RectengularCoordinate<double> pos(0, 0);
    double facing = 0;
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        it->executePart1<double>(&pos, &facing);
        //c.print(Instruction::getNameOfType(it->type)  + std::to_string(it->value) + " | " + std::to_string(pos.x) + "/" + std::to_string(pos.y) + " | " + std::to_string(facing));
    }

    pos.x = fabs(pos.x);
    pos.y = fabs(pos.y);

    c.print("the solution to part 1 is: " + std::to_string(pos.x + pos.y));



    pos = RectengularCoordinate<double>(0, 0);
    PolarCoordinate waypoint_pos(RectengularCoordinate<double>(1, 10));
    
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        it->executePart2<double>(&waypoint_pos, &pos);
        c.print(Instruction::getNameOfType(it->type) + std::to_string(it->value) + " | " + std::to_string(pos.x) + "/" + std::to_string(pos.y) + " | " + std::to_string(waypoint_pos.toRect<double>().x) + "/" + std::to_string(waypoint_pos.toRect<double>().y));
    }

    pos.x = fabs(pos.x);
    pos.y = fabs(pos.y);

    c.print("the solution to part 2 is: " + std::to_string(pos.x + pos.y));
}