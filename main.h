//
// Created by viktor on 27.11.22.
//

#pragma once

#include <cmath>
#include <vector>

struct point {
    double x;
    double y;

    point() = default;
    point(point const& p) {
        this->x = p.x;
        this->y = p.y;
    }

    point(double x, double y) {
        this->x = x;
        this->y = y;
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

    vekt(double x, double y, point const& p) {
        this->p1 = p;
        this->x = x;
        this->y = y;
        this->p2 = point(this->x + this->p1.x, this->y + this->p1.y);
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

    point middle() {
        return point(this->p1.x + (this->p2.x - this->p1.x) / 2., this->p1.y + (this->p2.y - this->p1.y) / 2.);
    }

    vekt normalize() {
        return vekt(this->x / this->len(), this->y / this->len(), this->p1);
    }
};

std::vector<point> maxRectangleInTriangle(std::vector<point> const& triangle) {
    vekt v1 = vekt(triangle[0], triangle[1]), v2 = vekt(triangle[1], triangle[2]), v3 = vekt(triangle[2], triangle[0]);
    point s1 = v1.middle(), s2 = v2.middle();
    vekt v3n = v3.normalize();

}
