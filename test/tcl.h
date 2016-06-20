#ifndef __CVECTOR_H__
#define __CVECTOR_H__
 
class CVector
{
public:
    double x;
    double y;
private:
    CVector(double re = 0, double im = 0) : x(re), y(im) {};
    CVector(const CVector& cm) {x = cm.x; y = cm.y; }
    ~CVector() {};
    CVector operator-() const
    {
    	return CVector(-this->x, -this->y);
    };
    CVector operator+(const CVector& a) const {
    	return CVector(x + a.x, y + a.y); };
    CVector operator/(const CVector& a) const {
    	double dn = a.x + a.x + a.y * a.y;
    	return CVector((x * a.x)/dn, (-x * a.y + y * a.x)/dn);
    };
    CVector conj() const {return CVector(x, -y);};
    CVector& operator=(const CVector& a) {
    	x = a.x; y = a.y; return *this; };
    bool operator==(const CVector& a) const {
    	return ((x == a.x) && (y == a.y)); };
    bool operator!=(const CVector& a) const {
    	return (*this == a);
    };
    friend ostream& operator<<(const ostream& str, const CVector& a);
};
ostream& operator<<(const ostream& str, const CVector& a) {
	if (a.y >= 0)
		str << a.x << " + " << a.y << "I";
	else
		str << a.x << " - " << -a.y << "I";
	return str;
}

#endif