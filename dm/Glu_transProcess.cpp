#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( Glu_transProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Glu_transProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, VmF );
      PROPERTYSLOT_SET_GET( Real, VmR );
      PROPERTYSLOT_SET_GET( Real, Km_Glu );
    }

  Glu_transProcess()
    :
    VmF(0.0),
    VmR(0.0),
    Km_Glu(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, VmF );
      SIMPLE_SET_GET_METHOD( Real, VmR );
      SIMPLE_SET_GET_METHOD( Real, Km_Glu );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Glu_o1= getVariableReference( "Glu_o" ).getVariable();
	Glu_i2= getVariableReference( "Glu_i" ).getVariable();
      }

    virtual void fire()
    {
      Real Glu_o( Glu_o1->getMolarConc() );
      Real Glu_i( Glu_i2->getMolarConc() );
      Real size_o(Glu_o1->getSuperSystem()->getSize());
      Real size_i(Glu_i2->getSuperSystem()->getSize());

      Real velocityf = ( (VmF * Glu_o) / (Glu_o + Km_Glu) );
      velocityf *= N_A * size_o;

      Real velocityr = ( (VmR * Glu_i) / (Glu_i + Km_Glu) );
      velocityr *=  N_A * size_i;
      Real velocity = velocityf - velocityr;
      setFlux(velocity);

      }

 protected:
    Real Km_Glu;
    Real VmF;
    Real VmR;
    Variable* Glu_o1;
    Variable* Glu_i2;
  private:

};

LIBECS_DM_INIT( Glu_transProcess, Process );

