#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( SystemNProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( SystemNProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	Km_Gln  );
      PROPERTYSLOT_SET_GET( Real,Km_Na );
      PROPERTYSLOT_SET_GET( Real,Ki_His );
      PROPERTYSLOT_SET_GET( Real, Vmax  );
    }

  SystemNProcess()
    :
    Km_Gln(0.0),
    Km_Na(0.0),
    Ki_His (0.0),
    Vmax(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, Km_Gln );
      SIMPLE_SET_GET_METHOD( Real, Km_Na );
      SIMPLE_SET_GET_METHOD( Real, Ki_His );
      SIMPLE_SET_GET_METHOD( Real, Vmax);
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();  
	Gln_o1 = getVariableReference( "Gln_o" ).getVariable();  
	Gln_i2 = getVariableReference( "Gln_i" ).getVariable(); 
       	Na_o3 = getVariableReference( "Na_o" ).getVariable(); 
	Na_i4 = getVariableReference( "Na_i" ).getVariable(); 
	His_o5 = getVariableReference( "His_o" ).getVariable(); 
	His_i6 = getVariableReference( "His_i" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real Gln_o( Gln_o1->getMolarConc() );
 Real Gln_i( Gln_i2->getMolarConc() );
Real Na_o( Na_o3->getMolarConc() );
Real Na_i( Na_i4->getMolarConc() );
Real His_o( His_o5->getMolarConc() );
Real His_i( His_i6->getMolarConc() );
//Real size(getSuperSystem()->getSize());


Real velocityf = ( (Vmax * Gln_o * Na_o) / 
	( (Gln_o + Km_Gln * (His_o/Ki_His + 1) ) * (Na_o + Km_Na) ) );
 velocityf *= Gln_o1->getSuperSystem()->getSize()*N_A;

Real velocityr = ( (Vmax * Gln_i * Na_i) / 
	( (Gln_i + Km_Gln * (His_i/Ki_His + 1) ) * (Na_i + Km_Na) ) );
 velocityr *=  Gln_i2->getSuperSystem()->getSize()*N_A;
Real velocity = velocityf - velocityr;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	Km_Gln ;
Real	Km_Na ;
 Real Ki_His;
Real	Vmax;
    Variable*	Gln_o1;  
    Variable*	Gln_i2; 
    Variable*	Na_o3;
    Variable*	Na_i4;
    Variable*	His_o5;
    Variable*	His_i6;
  private:

};

LIBECS_DM_INIT( SystemNProcess, Process );

