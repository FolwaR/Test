#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{

	class Vector
	{
		public:
			enum Mode {RECT, POL};
			Vector();
			Vector(double n1, double n2, Mode form = RECT);
			void reset(double n1, double n2, Mode form = RECT);
			~Vector();
			double xval() const {return x;};
			double yval() const {return y;};
			double magval() const {return mag;};
			double angval() const {return ang;};
			void polar_mode() {mode = POL;};
			void rect_mode() {mode = RECT;};

			Vector operator+(const Vector &) const;
			Vector operator-(const Vector &) const;
			Vector operator-() const;
			Vector operator*(const double) const;

			friend Vector operator*(const double, const Vector);
			friend std::ostream & operator<<(std::ostream &, const Vector &);


		private:
			double x;
			double y;
			double mag;
			double ang;
			Mode mode;

			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
	};

} // namespace VECTOR end

#endif /* VECTOR_H_ */
