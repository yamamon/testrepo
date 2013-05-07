#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( Flux1Process, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Flux1Process, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k  );
    }

  Flux1Process()
    :
	k (0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, 	k  );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	S= getVariableReference( "S" ).getVariable();  
      }

    virtual void fire()
    {
Real S0( S->getValue() );
Real velocity=k * S0* N_A;
setFlux(velocity);

      }

 protected:
Real	k ;			       					
    Variable*	S; 
  private:

};

LIBECS_DM_INIT( Flux1Process, Process );

