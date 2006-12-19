#ifndef _BodyConstraint_h_
#define _BodyConstraint_h_
// BodyConstraint.h
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	AUTHOR: Frank C. Anderson
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//==============================================================================
// INCLUDES
//==============================================================================
#include <OpenSim/Simulation/rdSimulationDLL.h>
#include "PointConstraint.h"
#include <OpenSim/Simulation/SIMM/AbstractBody.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * A class for specifiying point constraints on a body.
 *
 * @author Frank C. Anderson
 * @version 1.0
 */
namespace OpenSim {
class RDSIMULATION_API BodyConstraint
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//==============================================================================
// DATA
//==============================================================================
public:
	AbstractBody *_body;							// BODY ID
	OpenSim::PointConstraint _pc[3];	// POINT CONSTRAINTS (3 MAX, for now)

//==============================================================================
// METHODS
//==============================================================================
public:
	//---------------------------------------------------------------------------
	// CONSTRUCTION
	//---------------------------------------------------------------------------
	virtual ~BodyConstraint();
	BodyConstraint();

	//---------------------------------------------------------------------------
	// SET AND GET
	//---------------------------------------------------------------------------
	int getNC();
	void setBody(OpenSim::AbstractBody *aBody);
	OpenSim::AbstractBody* getBody();
	OpenSim::PointConstraint* getPC(int aI);

	//---------------------------------------------------------------------------
	// CONSTRAINT CONSTRUCTION
	//---------------------------------------------------------------------------
	void setValues(int aN,int aID[],double aV[][3]);
	void constructConstraintsForPoint1();
	void constructConstraintsForPoint2();
	double* findMostOrthogonal(OpenSim::PointConstraint *aPC,double aV[3]);

	//---------------------------------------------------------------------------
	// UTILITY
	//---------------------------------------------------------------------------
	void clear();
	void clearValues();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
};	// END class BodyConstraint
}; //namespace
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // #ifndef __BodyConstraint_h__
