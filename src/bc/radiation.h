//<license>
/*
   This file is part of Behmeth.
   Author: Behram Kapadia, wiowou@hotmail.com

    Behmeth is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Behmeth is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Behmeth.  If not, see <http://www.gnu.org/licenses/>.
*/

//</license>

#ifndef _MATH_MODEL_BC_RADIATION_h
#define _MATH_MODEL_BC_RADIATION_h

#include "model/attribute.h"
#include "model/boundaryCondition.h"
#include "interp/orthoLinTerp.h"
#include "eng/material.h"
#include "model/domain.h"
#include "../thermalDOF.h"

namespace math{
namespace model{
namespace fvm{
namespace att{

#ifdef MYDEBUG
  class RadiationTest;
#endif //MYDEBUG

class Radiation : public Attribute
{

public:
  double emis;
  double shapeFact;
  const static double stephBoltz;
protected:

private:


#ifdef MYDEBUG
  friend class RadiationTest;
#endif //MYDEBUG
};

}/*att*/ }/*fvm*/ }/*model*/ }/*math*/ 


namespace math{
namespace model{
namespace fvm{
namespace bc{

#ifdef MYDEBUG
  class RadiationTest;
#endif //MYDEBUG

class Radiation : public BoundaryCondition
{

public:
  Radiation()
  {
    TSurrCell = nullptr;
  }
  void Apply( Face* f1);
  OrthoLinTerp<4> Tsurr;
  Cell* TSurrCell;
protected:

private:


#ifdef MYDEBUG
  friend class RadiationTest;
#endif //MYDEBUG
};

}/*bc*/ }/*fvm*/ }/*model*/ }/*math*/ 

#endif /*_MATH_MODEL_BC_RADIATION_h */
