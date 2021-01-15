#include "GeometricProgressionGenerator.h"

GeomGenerator::GeomGenerator(float first, float max, int factor) : initial(first), border(max), multiplier(factor), value(new float(first)) {
}

GeomGenerator::~GeomGenerator() {
	delete value;
}

bool GeomGenerator::operator!=(GeomGenerator const &other) const
{
	return *value != *other;
}

bool GeomGenerator::operator==(GeomGenerator const &other) const
{
	return *value == *other.value;
}

typename GeomGenerator::reference GeomGenerator::operator*() const
{
	return *value;
}

GeomGenerator &GeomGenerator::operator++()
{
	float previous_value = *value;
	delete value;
	value = new float(previous_value*multiplier);
	return *this;
}

GeomGenerator::const_iterator GeomGenerator::begin() const {
	return const_iterator(this->initial, this->border, this->multiplier);
}

GeomGenerator::const_iterator GeomGenerator::end() const {
	return const_iterator(this->border, this->border, this->multiplier);
}
