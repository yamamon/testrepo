#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( OCTProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( OCTProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k1  );
      PROPERTYSLOT_SET_GET( Real, 	k2  );
      PROPERTYSLOT_SET_GET( Real, 	k3  );
      PROPERTYSLOT_SET_GET( Real, 	k4  );
      PROPERTYSLOT_SET_GET( Real, 	k5  );
      PROPERTYSLOT_SET_GET( Real, 	k6  );
       PROPERTYSLOT_SET_GET( Real, 	k7  );
       PROPERTYSLOT_SET_GET( Real, 	k8  );
    }

  OCTProcess()
    :
	k1 (0.0),			
	k2(0.0),				
	k3 (0.0),			
	k4  (0.0),				
	k5  (0.0),			
	k6 (0.0),			
	k7 (0.0),			
	k8  (0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, 	k1  );
      SIMPLE_SET_GET_METHOD( Real, 	k2  );
      SIMPLE_SET_GET_METHOD( Real, 	k3  );
      SIMPLE_SET_GET_METHOD( Real, 	k4  );
      SIMPLE_SET_GET_METHOD( Real, 	k5  );
      SIMPLE_SET_GET_METHOD( Real, 	k6  );
       SIMPLE_SET_GET_METHOD( Real, 	k7  );
       SIMPLE_SET_GET_METHOD( Real, 	k8  );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	CP1= getVariableReference( "CP" ).getVariable();  
	Orn2= getVariableReference( "Orn" ).getVariable(); 
       Ctrl3= getVariableReference( "Ctrl" ).getVariable();  
	Pi4= getVariableReference( "Pi" ).getVariable(); 
	OCT5= getVariableReference( "OCT" ).getVariable(); 
      }

    virtual void fire()
    {
Real CP( CP1->getMolarConc() );
Real Orn( Orn2->getMolarConc() );
Real Ctrl( Ctrl3->getMolarConc() );
Real Pi( Pi4->getMolarConc() );
Real OCT( OCT5->getMolarConc() );
 Real size_NA=Orn2->getSuperSystem()->getSize()*N_A;

Real velocity = ( (k1 * k3 * k5 * k7 * CP * Orn) 
	       - (k2 * k4 * k6 * k8 * Pi * Ctrl) ) * OCT; 

// -> M/s^4

Real DENOM = ( (k2 * k7 * (k4 + k5)) 
	    + (k1 * k7 * (k4 + k5) * CP) 
	    + (k2 * k8 * (k4 + k5) * Pi) 
	    + (k3 * k5 * k7 * Orn) 
	    + (k2 * k4 * k6 * Ctrl) 
	    + (k1 * k3 * (k5 + k7) * CP * Orn) 
	    + (k6 * k8 * (k2 + k4) * Pi * Ctrl) 
	    + (k1 * k4 * k6 * CP * Ctrl) 
	    + (k1 * k3 * k6 * CP * Orn * Ctrl) 
	    + (k3 * k5 * k8 * Orn * Pi) 
	    + (k3 * k6 * k8 * Orn * Pi * Ctrl) );

// -> 1/s^3

velocity /= DENOM;
//cout << "cps velocity = " << velocity << "\n"; 
velocity *=  size_NA;

//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	k1 ;			
Real	k2;				
Real	k3 ;			
Real	k4  ;				
Real	k5  ;			
Real	k6 ;			
Real	k7 ;			
Real	k8  ;					
    Variable*	CP1;  
    Variable*	Orn2; 
    Variable*	Ctrl3; 
    Variable*	Pi4; 
    Variable*	OCT5; 
  private:

};

LIBECS_DM_INIT( OCTProcess, Process );

