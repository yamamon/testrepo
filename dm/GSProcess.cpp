#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( GSProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( GSProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, Km_Glu );
      PROPERTYSLOT_SET_GET( Real, Km_ATP );
      PROPERTYSLOT_SET_GET( Real, Km_NH4p );
      PROPERTYSLOT_SET_GET( Real, kcat );
    }

  GSProcess()
    :
    Km_Glu(0.0),
    Km_ATP (0.0),
    Km_NH4p(0.0),
    kcat(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, Km_Glu );
      SIMPLE_SET_GET_METHOD( Real, Km_ATP );
      SIMPLE_SET_GET_METHOD( Real, Km_NH4p);
      SIMPLE_SET_GET_METHOD( Real, kcat );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Glu1 = getVariableReference( "Glu" ).getVariable();  
	ATPMg2 = getVariableReference( "ATPMg" ).getVariable(); 
       	NH4p3 = getVariableReference( "NH4p" ).getVariable(); 
	GS4 = getVariableReference( "GS" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real Glu( Glu1->getMolarConc() );
Real ATPMg( ATPMg2->getMolarConc() );
Real NH4p( NH4p3->getMolarConc() );
Real GS( GS4->getMolarConc() );
Real size(GS4->getSuperSystem()->getSize());
Real velocity = kcat * GS * (Glu / (Km_Glu + Glu)) * (ATPMg / (Km_ATP + ATPMg)) * (NH4p / (Km_NH4p + NH4p));


velocity*=size*N_A;

setFlux(velocity);

      }

 protected:
Real    Km_Glu ;
Real    Km_NH4p; 
Real    Km_ATP;
Real    kcat; 
    Variable*	Glu1;  
    Variable*	ATPMg2; 
    Variable*	NH4p3;
    Variable*	GS4;
  private:

};

LIBECS_DM_INIT( GSProcess, Process );

