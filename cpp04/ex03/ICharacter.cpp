#include "ICharacter.hpp"

#include <iostream>



ICharacter::ICharacter() {

}

ICharacter::ICharacter(ICharacter const& src) {

  *this = src;
}

ICharacter& ICharacter::operator=(ICharacter const&) {

  return *this;
}

ICharacter::~ICharacter() {

}
