//
// Created by viktor on 27.11.22.
//

#pragma once

#include <cmath>

struct point {
    double x;
    double y;

    point() = default;
    point(point const& p) {
        this->x = p.x;
        this->y = p.y;
    }
};

struct vekt {
    point p1;
    point p2;
    double x;
    double y;

    vekt(vekt const&) = default;

    vekt(point const& p1, point const& p2) {
        this->p1 = p1;
        this->p2 = p2;
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    double vp(vekt const& v1, vekt const& v2) {
        return v1.x * v2.y - v1.y * v2.x;
    }

    double sp(vekt const& v1, vekt const& v2) {
        return v1.x  * v2.x + v1.y * v2.y;
    }

    double len() {
        return sqrt(this->x * this->x + this->y * this->y);
    }
};
