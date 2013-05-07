#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( CPSProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( CPSProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	kcat  );
      PROPERTYSLOT_SET_GET( Real, 	KmA1  );
      PROPERTYSLOT_SET_GET( Real, 	KmA2  );
      PROPERTYSLOT_SET_GET( Real, 	KmB  );
      PROPERTYSLOT_SET_GET( Real, 	KmN  );
      PROPERTYSLOT_SET_GET( Real, 	KmG  );
       PROPERTYSLOT_SET_GET( Real, 	KsA1  );
       PROPERTYSLOT_SET_GET( Real, 	KsA2  );
       PROPERTYSLOT_SET_GET( Real, 	KsB  );
        PROPERTYSLOT_SET_GET( Real, 	KsG  );
       PROPERTYSLOT_SET_GET( Real, 	KsM  );
       PROPERTYSLOT_SET_GET( Real, 	KmdA2  );
       PROPERTYSLOT_SET_GET( Real, 	KmdB  );
       PROPERTYSLOT_SET_GET( Real, 	KmdN  );
    }

  CPSProcess()
    :
	KmA1 (0.0),			
	KmA2(0.0),				
	KmB (0.0),			
	KmN  (0.0),				
	KmG  (0.0),			
	KsA1 (0.0),			
	KsA2 (0.0),			
	KsB  (0.0),			
	KsG (0.0),			
	KsM  (0.0),			
	KmdA2 (0.0),			
	KmdB  (0.0),			
	KmdN  (0.0),			
	kcat  (0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, 	kcat  );
      SIMPLE_SET_GET_METHOD( Real, 	KmA1  );
      SIMPLE_SET_GET_METHOD( Real, 	KmA2  );
      SIMPLE_SET_GET_METHOD( Real, 	KmB  );
      SIMPLE_SET_GET_METHOD( Real, 	KmN  );
      SIMPLE_SET_GET_METHOD( Real, 	KmG  );
       SIMPLE_SET_GET_METHOD( Real, 	KsA1  );
       SIMPLE_SET_GET_METHOD( Real, 	KsA2  );
       SIMPLE_SET_GET_METHOD( Real, 	KsB  );
        SIMPLE_SET_GET_METHOD( Real, 	KsG  );
       SIMPLE_SET_GET_METHOD( Real, 	KsM  );
       SIMPLE_SET_GET_METHOD( Real, 	KmdA2  );
       SIMPLE_SET_GET_METHOD( Real, 	KmdB  );
       SIMPLE_SET_GET_METHOD( Real, 	KmdN  );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	NH4p1= getVariableReference( "NH4p" ).getVariable();   
	HCO32= getVariableReference( "HCO3" ).getVariable(); 
       ATPMg3= getVariableReference( "ATPMg" ).getVariable(); 
	Mg24= getVariableReference( "Mg2" ).getVariable();  
	AG5= getVariableReference( "AG" ).getVariable();   
	CPSI6= getVariableReference( "CPSI" ).getVariable();  
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real NH4p( NH4p1->getMolarConc() );
Real HCO3( HCO32->getMolarConc() );
Real ATPMg( ATPMg3->getMolarConc() );
Real Mg2( Mg24->getMolarConc());
Real AG( AG5->getMolarConc() );
Real CPSI( CPSI6->getMolarConc() );
 Real size(size=NH4p1->getSuperSystem()->getSize());

Real velocity = kcat * CPSI;
Real DENOM = 1 
	+ ( (KmA1 + KmA2)/ATPMg ) 
	+ (KmG/AG) 
	+ (KmB/HCO3) 
	+ (KmN/NH4p)
	+ ( (KmA1 * KsG)/(ATPMg * AG) ) 
	+ ( (KmA1 * KsM)/(ATPMg * Mg2) )
	+ ( ( (KmA2 + KmdA2) * KsB + (KsA1 * KmdB) )/(ATPMg * HCO3) )
	+ ( (KsA2 * KmN)/(ATPMg * NH4p) ) 
	+ ( (KsG * KmdB)/(AG * HCO3) )
	+ ( ( (KsA1 * KsG * KmdB) + (KmdA2 * KsG * KsB) )/(ATPMg * AG * HCO3) )
	+ ( (KmA1 * KsM * KsG)/(ATPMg * Mg2 * AG) )
	+ ( (KsA1 * KsM * KmB)/(ATPMg * Mg2 * HCO3) )
	+ ( (KsA2 * KsB * (KmN + KmdN) )/(ATPMg * HCO3 * NH4p) )
	+ ( (KsA1 * KsM * KsG * KmdB)/(ATPMg * Mg2 * AG * HCO3) )
	+ ( (KsA2 * KsG * KsB * KmdN)/(ATPMg * AG * HCO3 * NH4p) )
	+ ( (KsA1 * KmdA2 * KsB)/( pow(ATPMg, 2) * HCO3) )
	+ ( (KsA1 * KmdA2 * KsG * KsB)/( pow(ATPMg, 2) * AG * HCO3) )
	+ ( (KsA1 * KmdA2 * KsM * KsB)/( pow(ATPMg, 2) * Mg2 * HCO3) )
	+ ( (KsA1 * KsA2 * KsB * KmdN)/( pow(ATPMg, 2) * HCO3 * NH4p) )
	+ ( (KsA1 * KmdA2 * KsM * KsG * KsB)
		/( pow(ATPMg, 2) * Mg2 * AG * HCO3) )
	+ ( (KsA1 * KsA2 * KsM * KsB * KmdN)
		/( pow(ATPMg, 2) * Mg2 * HCO3 * NH4p) )
	+ ( (KsA1 * KsA2 * KsG * KsB * KmdN)
		/( pow(ATPMg, 2)  * AG * HCO3 * NH4p) )
	+ ( (KsA1 * KsA2 * KsM * KsG * KsB * KmdN) 
		/( pow(ATPMg, 2) * Mg2 * AG * HCO3 * NH4p) );

velocity /= DENOM;
//cout << "cps velocity = " << velocity << "\n"; 
velocity *= N_A * size;

//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	KmA1 ;			
Real	KmA2;				
Real	KmB ;			
Real	KmN  ;				
Real	KmG  ;			
Real	KsA1 ;			
Real	KsA2 ;			
Real	KsB  ;			
Real	KsG ;			
Real	KsM  ;			
Real	KmdA2 ;			
Real	KmdB  ;			
Real	KmdN  ;			
Real	kcat  ;			
    Variable*	NH4p1;  
    Variable*	HCO32; 
    Variable*	ATPMg3; 
    Variable*	Mg24; 
    Variable*	AG5; 
    Variable*	CPSI6; 
  private:

};

LIBECS_DM_INIT( CPSProcess, Process );

