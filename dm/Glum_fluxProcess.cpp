#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( Glum_fluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Glum_fluxProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k  );
      PROPERTYSLOT_SET_GET( Real, 	Rate  );
    }

  Glum_fluxProcess()
    :
    k (0.0),
    Rate(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, 	k  );
      SIMPLE_SET_GET_METHOD( Real, 	Rate  );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Glum1= getVariableReference( "Glum" ).getVariable();  
      }

    virtual void fire()
    {
Real Glum( Glum1->getMolarConc() );
 Real size(Glum1->getSuperSystem()->getSize());
Real velocity = k * Glum - Rate;
velocity*= N_A * size;
//cout << "cps velocity = " << velocity << "\n"; 

//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	k ;	
 Real Rate;		       					
    Variable*	Glum1; 
  private:

};

LIBECS_DM_INIT( Glum_fluxProcess, Process );

