#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( GmsProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( GmsProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, Kds );
      PROPERTYSLOT_SET_GET( Real, nHs );
      PROPERTYSLOT_SET_GET( Real, KdA );
      PROPERTYSLOT_SET_GET( Real, nHa );
      PROPERTYSLOT_SET_GET( Real, Kap);
      PROPERTYSLOT_SET_GET( Real, kcat);
    }

  GmsProcess()
    :
    Kds(0.0),
    nHs (0.0),
    KdA(0.0),
    nHa(0.0),
    Kap(0.0),
    kcat(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, Kds  );
      SIMPLE_SET_GET_METHOD( Real, nHs  );
      SIMPLE_SET_GET_METHOD( Real, KdA  );
      SIMPLE_SET_GET_METHOD( Real, nHa  );
      SIMPLE_SET_GET_METHOD( Real, Kap  );
      SIMPLE_SET_GET_METHOD( Real, kcat );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Gln1 = getVariableReference( "Gln" ).getVariable();  
	NH4p2 = getVariableReference( "NH4p" ).getVariable(); 
       	Pi3 = getVariableReference( "Pi" ).getVariable(); 
	Gms4 = getVariableReference( "Gms" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
      Real Gln( Gln1->getMolarConc() );
Real NH4p( NH4p2->getMolarConc() );
Real Pi( Pi3->getMolarConc() );
Real Gms( Gms4->getMolarConc() );
Real size(Gms4->getSuperSystem()->getSize());


Real velocity = ( ( kcat * Gms ) / ( 1 + Kap / NH4p ) ) * ( pow (Gln, nHs) );

Real DENOM = Kds * ( 1 + ( KdA / ( pow (Pi, nHa) ) ) )
	    + ( pow (Gln, nHs) ) * ( 1 + ( KdA / ( pow (Pi, nHa) ) ) );

velocity /= DENOM;

velocity*=size*N_A;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
    Real Kds;
    Real nHs;
    Real KdA;
    Real nHa;
    Real Kap;
    Real kcat;
    Variable*	Gln1;  
    Variable*	NH4p2; 
    Variable*	Pi3;
    Variable*	Gms4;
  private:

};

LIBECS_DM_INIT( GmsProcess, Process );

