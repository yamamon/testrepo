#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( ASSProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( ASSProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, k1 );
      PROPERTYSLOT_SET_GET( Real, k2 );
      PROPERTYSLOT_SET_GET( Real, k3 );
      PROPERTYSLOT_SET_GET( Real, k4 );
      PROPERTYSLOT_SET_GET( Real, k5 );
      PROPERTYSLOT_SET_GET( Real, k6 );
      PROPERTYSLOT_SET_GET( Real, k7 );
      PROPERTYSLOT_SET_GET( Real, k8 );
      PROPERTYSLOT_SET_GET( Real, k9 );
      PROPERTYSLOT_SET_GET( Real, k10 );
      PROPERTYSLOT_SET_GET( Real, k11 );
      PROPERTYSLOT_SET_GET( Real, k12 );
    }

  ASSProcess()
    :
    k1(0.0),
    k2(0.0),
    k3(0.0),
    k4(0.0),
    k5(0.0),
    k6(0.0),
    k7(0.0),
    k8(0.0),
    k9(0.0),
    k10(0.0),
    k11(0),
    k12(0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, k1 );
      SIMPLE_SET_GET_METHOD( Real, k2 );
      SIMPLE_SET_GET_METHOD( Real, k3 );
      SIMPLE_SET_GET_METHOD( Real, k4 );
      SIMPLE_SET_GET_METHOD( Real, k5 );
      SIMPLE_SET_GET_METHOD( Real, k6 );
      SIMPLE_SET_GET_METHOD( Real, k7 );
      SIMPLE_SET_GET_METHOD( Real, k8 );
      SIMPLE_SET_GET_METHOD( Real, k9 );
      SIMPLE_SET_GET_METHOD( Real, k10 );
      SIMPLE_SET_GET_METHOD( Real, k11 );
      SIMPLE_SET_GET_METHOD( Real, k12 );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Ctrl1 = getVariableReference( "Ctrl" ).getVariable();  
	ATP2 = getVariableReference( "ATP" ).getVariable(); 
	Asp3 = getVariableReference( "Asp" ).getVariable(); 
	PP4 = getVariableReference( "PP" ).getVariable();  
	AMP5 = getVariableReference( "AMP" ).getVariable(); 
	AS6 = getVariableReference( "AS" ).getVariable(); 
	ASS7 = getVariableReference( "ASS" ).getVariable();  
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real Ctrl( Ctrl1->getMolarConc() );
Real ATP( ATP2->getMolarConc() );
Real Asp( Asp3->getMolarConc() );
Real PP( PP4->getMolarConc() );
Real AMP( AMP5->getMolarConc() );
Real AS( AS6->getMolarConc() );
Real ASS( ASS7->getMolarConc() );
Real size(ASS7->getSuperSystem()->getSize());
Real velocity = ( k1 * k3 * k5 * k7 * k9 * k11 * Ctrl * ATP * Asp - k2 * k4 * k6 * k8 * k10 * k12 * PP * AMP * AS ) * ASS; 

Real DENOM = (k2 * k4 * k9 * k11 * (k6 + k7))
	    + (k1 * k4 * k6 * k8 * k11 * Ctrl * PP)
	    + (k1 * k4 * k9 * k11 * (k6 + k7) * Ctrl)
	    + (k2 * k5 * k7 * k9 * k12 * Asp * AS) 
	    + (k2 * k5 * k7 * k9 * k11 * Asp)
	    + (k1 * k3 * k6 * k8 * k11 * Ctrl * ATP * PP) 
	    + (k1 * k3 * k9 * k11 * (k6 + k7) * Ctrl * ATP)
	    + (k1 * k4 * k6 * k8 * k10 * Ctrl * PP * AMP)
	    + (k1 * k5 * k7 * k9 * k11 * Ctrl * Asp)
	    + (k3 * k5 * k7 * k9 * k12 * ATP * Asp * AS)
	    + (k3 * k5 * k7 * k9 * k11 * ATP * Asp)
	    + (k2 * k5 * k7 * k10 * k12 * Asp * AMP * AS)
	    + (k2 * k4 * k9 * k12 * (k6 + k7) * AS)
	    + (k1 * k3 * k6 * k8 * k10 * Ctrl * ATP * PP * AMP)
	    + (k1 * k3 * k5 * ( (k7 * k9) + (k7 * k11) + (k9 * k11) )* Ctrl * ATP * Asp)
	    + (k1 * k3 * k5 * k8 * k11 * Ctrl * ATP * Asp * PP)
	    + (k2 * k4 * k6 * k8 * k11 * PP)
	    + (k1 * k3 * k5 * k7 * k10 * Ctrl * ATP * Asp * AMP)
	    + (k2 * k4 * k6 * k8 * k10 * PP * AMP)
	    + (k3 * k5 * k7 * k10 * k12 * ATP * Asp * AMP * AS)
	    + (k2 * k4 * k6 * k8 * k12 * PP * AS)
	    + (k3 * k6 * k8 * k10 * k12 * ATP * PP * AMP * AS)
	    + (k2 * k4 * k10 * k12 * (k6 + k7) * AMP * AS)
	    + (k2 * k5 * k8 * k10 * k12 * Asp * PP * AMP * AS)
	    + (k8 * k10 * k12 * ( (k2 * k4) + (k2 * k6) + (k4 * k6) )* PP * AMP * AS)
	    + (k1 * k3 * k5 * k8 * k10 * Ctrl * ATP * Asp * PP * AMP)
	    + (k3 * k5 * k8 * k10 * k12 * ATP * Asp * PP * AMP * AS);
velocity /= DENOM;
velocity*=size*N_A;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
    Real k1;
    Real k2;
    Real k3;
    Real k4;
    Real k5;
    Real k6;
    Real k7;
    Real k8;
    Real k9;
    Real k10;
    Real k11;
    Real k12;
    Variable*	Ctrl1;  
    Variable*	ATP2; 
    Variable*	Asp3; 
    Variable*	PP4;  
    Variable*	AMP5; 
    Variable*	AS6; 
    Variable*	ASS7;  
  private:

};

LIBECS_DM_INIT( ASSProcess, Process );

