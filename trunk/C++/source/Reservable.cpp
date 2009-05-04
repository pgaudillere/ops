#include "Reservable.h"
#include "ReferenceHandler.h"
namespace ops
{

	Reservable::Reservable():
		nrOfReservations(0)
	{
	}
	void Reservable::setReferenceHandler(ReferenceHandler* refHandler)
	{
		referenceHandler = refHandler;
	}
	ReferenceHandler* Reservable::getReferenceHandler()
	{
		return referenceHandler;
	}
	void Reservable::reserve()
	{
		nrOfReservations++;
		referenceHandler->onNewEvent(this, ReserveInfo(this, nrOfReservations));
	}
	void Reservable::unreserve()
	{
		nrOfReservations--;
		referenceHandler->onNewEvent(this, ReserveInfo(this, nrOfReservations));
	}
	int Reservable::getNrOfReservations()
	{
		return nrOfReservations;
	}
	Reservable::~Reservable()
	{
		//TODO: Should we do a check here?
	}



}