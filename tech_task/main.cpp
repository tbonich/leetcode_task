/*!
\file
\brief The file contains an algorithm that searches for a point on a polyline that is closest to a given point.

The file contains classes that characterize geometric objects such as point, line segment and vector.
Function dist_point_segment calculates the shortest distance from a point to a segment and calculates the point of the segment at which this distance is reached.
Function main contains processing of input data for correctness, as well as most of the remaining calculations to solve the problem.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

/**
	\brief Class MyPoint refers to the point in three-dimensional space

	A point is defined by three coordinates x, y, z.
	A point can be specified using coordinates.
	A point can be checked for equality with another point.
 */
class MyPoint {
public:
    double x;  ///< x-coordinate
    double y;  ///< y-coordinate
    double z;  ///< z-coordinate

    /*!
    Creates a point at the given three coordinates
    \param p_x, p_y, p_z Coordinates
    */
    MyPoint(double p_x, double p_y, double p_z) {
        x = p_x;
        y = p_y;
        z = p_z;
    }

    /*!
    Compares a point with a given point
    \param p The point to which we compare
    \return true if points are equal, false otherwise
    */
    bool is_equal(MyPoint* p) {
        return this->x == p->x && this->y == p->y && this->z == p->z;
    }
};

/**
	\brief Class MySegment refers to the segment in three-dimensional space

	A segment is defined by two points.
	A segment can be specified using two endpoints, or by 6 coordinates of two endpoints.
 */
class MySegment {
public:
    MyPoint* p_first;   ///< First endpoint
    MyPoint* p_second;  ///< Second endpoint

    /*!
    Creates a segment bounded by two given endpoints
    \param p_0, p_1 Endpoints
    */
    MySegment(MyPoint* p_0, MyPoint* p_1) {
        p_first = p_0;
        p_second = p_1;
    }

    /*!
    Creates a segment bounded by two endpoints, which are determined by given coordinates
    \param x_f, y_f, z_f Coordinates of the first endpoint
    \param x_s, y_s, z_s Coordinates of the second endpoint
    */
    MySegment(double x_f, double y_f, double z_f, double x_s, double y_s, double z_s) {
        p_first = new MyPoint(x_f, y_f, z_f);
        p_second = new MyPoint(x_s, y_s, z_s);
    }

};

/**
	\brief Class MyVector refers to the vector in three-dimensional space

	A vector is defined by three coordinates x, y, z.
    A vector can be specified using start and end points, by 3 coordinates of vector or by segment, where the vector points from the first endpoint of segment to the second endpoint.
    A vector can be multiplied by a scalar. Can be calculated the scalar and vector product of a vector and a given vector. Vector length can be calculated. A given point can be moved by a vector.
*/
class MyVector {
public:
    double x;  ///< x-coordinate
    double y;  ///< y-coordinate
    double z;  ///< z-coordinate

    /*!
    Creates a vector at the given three coordinates
    \param v_x, v_y, v_z Coordinates
    */
    MyVector(double v_x, double v_y, double v_z) {
        x = v_x;
        y = v_y;
        z = v_z;
    }

    /*!
    Creates a vector at the given start and end points
    \param p_0 Start point
    \param p_1 End point
    */
    MyVector(MyPoint* p_0, MyPoint* p_1) {
        x = p_1->x - p_0->x;
        y = p_1->y - p_0->y;
        z = p_1->z - p_0->z;
    }

    /*!
    Creates a vector at the given segment, where the vector points from the first endpoint of segment to the second endpoint
    \param s Segment
    */
    MyVector(MySegment* s) {
        x = s->p_second->x - s->p_first->x;
        y = s->p_second->y - s->p_first->y;
        z = s->p_second->z - s->p_first->z;
    }

    /*!
    Multiplies a vector by a given scalar
    \param sclr Scalar to multiply by.
    \return A vector resulting from multiplying a vector by a scalar
    */
    MyVector* scalar_multiplication(double sclr) {
        MyVector* new_vec = new MyVector((this->x)*sclr, (this->y)*sclr, (this->z)*sclr);
        return new_vec;
    }

    /*!
    Calculates the scalar product of a vector and a given vector
    \param v Vector that participates in the scalar product
    \return a number that is equal to the scalar product
    */
    double scalar_product(MyVector* v) {
        return (this->x)*(v->x) + (this->y)*(v->y) + (this->z)*(v->z);
    }

    /*!
    Calculates the vector product of a vector and a given vector
    \param v Vector that participates in the vector product
    \return a vector, which is the result of the vector product
    */
    MyVector* vector_product(MyVector* v) {
        MyVector* new_vec = new MyVector((this->y)*(v->z) - (this->z)*(v->y), (this->z)*(v->x) - (this->x)*(v->z), (this->x)*(v->y) - (this->y)*(v->x));
        return new_vec;
    }

    /*!
    Calculates the length of the vector
    \return a number that is equal to the length of the vector
    */
    double length() {
        return sqrt(this->scalar_product(this));
    }

    /*!
    Calculates a new point resulting from moving a given point to a vector.
    \param p Point to be moved.
    \return a point, which is the result of the moving given point by the vector
    */
    MyPoint* move_point(MyPoint* p) {
        MyPoint* new_p = new MyPoint((p->x)+(this->x), (p->y)+(this->y), (p->z)+(this->z));
        return new_p;
    }
};

/*!
Calculates the shortest distance from a point to a segment and calculates the point of the segment at which this distance is reached
\param p Point from which the distance is calculated
\param s Segment to which the distance is calculated
\return pair of two values the shortest distance (double) from a point to a segment and the point (MyPoint) at which this distance is reached.
*/
pair<double, MyPoint*> dist_point_segment(MyPoint* p, MySegment* s) {
    MyVector* pf_p = new MyVector(s->p_first, p);
    MyVector* ps_p = new MyVector(s->p_second, p);
    MyVector* pf_ps = new MyVector(s);
    double scl_pr = pf_p->scalar_product(pf_ps);
    if (scl_pr <= 0) {
        return make_pair(pf_p->length(), s->p_first);
    }
    double scl_tmp = pf_ps->scalar_product(pf_ps);
    if (scl_pr >= scl_tmp) {
        return make_pair(ps_p->length(), s->p_second);
    }
    MyPoint* new_p = pf_ps->scalar_multiplication(scl_pr/scl_tmp)->move_point(s->p_first);
    MyVector* newp_p = new MyVector(new_p, p);
    return make_pair(newp_p->length(), new_p);
}

/*!
Searches for a point on a polyline that is closest to a given point and outputs the number of such points in the console, as well as the points themselves, indicating the segment number.
Processes input data for correctness. It is considered that if there is at least one point in a polyline, then the shortest distance from a given point to the polyline does not exceed the distance from a given point to this one point.
\param argc Count of input data
\param argv Input array
\return 0 if there were no errors in input data
\return -1 if there were insufficient amount of input data
\return -2 if there were invalid coordinate argument
\return -3 if there were out of range for a double in coordinate argument
\return -4 if file does not exist
\return -5 if the file contains incorrect data at the first point of the polyline
*/
int main(int argc, char* argv[])
{
    if (argc<5) {
        cerr << "Insufficient amount of input data\n";
        return -1;
    }
    double p_x, p_y, p_z;
    try {
        p_x = stod(argv[2]);
    } catch (const std::invalid_argument&) {
        cerr << "Argument x-coordinate is invalid\n";
        return -2;
    } catch (const std::out_of_range&) {
        cerr << "Argument x-coordinate is out of range for a double\n";
        return -3;
    }
    try {
        p_y = stod(argv[3]);
    } catch (const std::invalid_argument&) {
        cerr << "Argument y-coordinate is invalid\n";
        return -2;
    } catch (const std::out_of_range&) {
        cerr << "Argument y-coordinate is out of range for a double\n";
        return -3;
    }
    try {
        p_z = stod(argv[4]);
    } catch (const std::invalid_argument&) {
        cerr << "Argument z-coordinate is invalid\n";
        return -2;
    } catch (const std::out_of_range&) {
        cerr << "Argument z-coordinate is out of range for a double\n";
        return -3;
    }
    MyPoint* target = new MyPoint(p_x, p_y, p_z);
    ifstream fin(argv[1]);
    double p1_x, p1_y, p1_z;
    double p2_x, p2_y, p2_z;
    double dist_p_p1;
    vector<pair<long int, MyPoint*>> res;
    long int res_count = 1;
    long int segm_count = 1;
    bool flag = false;
    if (fin.is_open()){
        if (!(fin >> p1_x)) {
            cerr << "Incorrect data at the first point of the polyline\n";
            return -5;
        }
        if (!(fin >> p1_y)) {
            cerr << "Incorrect data at the first point of the polyline\n";
            return -5;
        }
        if (!(fin >> p1_z)) {
            cerr << "Incorrect data at the first point of the polyline\n";
            return -5;
        }
        MyPoint* p1 = new MyPoint(p1_x, p1_y, p1_z);
        MyVector* p1_p = new MyVector(p1, target);
        dist_p_p1 = p1_p->length();
        res.push_back(make_pair(1, p1));
        while (fin >> p2_x >> p2_y >> p2_z) {
            flag = false;
            MyPoint* p2 = new MyPoint(p2_x, p2_y, p2_z);
            MySegment* segm = new MySegment(p1, p2);
            pair<double, MyPoint*> tmp = dist_point_segment(target, segm);
            if (tmp.first < dist_p_p1) {
                res.clear();
                res.push_back(make_pair(segm_count, tmp.second));
                dist_p_p1 = tmp.first;
                res_count = 1;
            } else if (tmp.first == dist_p_p1) {
                for (auto elem:res) {
                    if (tmp.second->is_equal(elem.second)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    res.push_back(make_pair(segm_count, tmp.second));
                    res_count++;
                }
            }
            p1 = p2;
            segm_count++;
        }
    }
    fin.close();
    if(res.empty()) {
        cerr << "File does not exist\n";
        return -4;
    }
    cout << "Count of nearest points on the polyline to given point " << res_count << endl;
    for (auto i = 0; i<res_count; i++) {
        cout << "segment " << res[i].first << " point " << res[i].second->x << " " << res[i].second->y << " " << res[i].second->z << endl;
    }
    return 0;
}
