#include "Size.h"
#include <sstream>
std::string Size::to_string() const
{
	std::ostringstream s;
	s << h << " x " << w;
	return s.str();
}

std::ostream& operator << (std::ostream& stream, Size a) {
	stream << a.to_string();
	return stream;
}
