//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2005 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef VMIME_NET_TIMEOUTHANDLER_HPP_INCLUDED
#define VMIME_NET_TIMEOUTHANDLER_HPP_INCLUDED


#include "vmime/types.hpp"


namespace vmime {
namespace net {


/** A class to manage time-out in messaging services.
  */

class timeoutHandler : public object
{
public:

	virtual ~timeoutHandler() { }

	/** Called to test if the time limit has been reached.
	  *
	  * @return true if the time-out delay is elapsed
	  */
	virtual const bool isTimeOut() = 0;

	/** Called to reset the time-out counter.
	  */
	virtual void resetTimeOut() = 0;

	/** Called when the time limit has been reached (when
	  * isTimeOut() returned true).
	  *
	  * @return true to continue (and reset the time-out)
	  * or false to cancel the current operation
	  */
	virtual const bool handleTimeOut() = 0;
};


/** A class to create 'timeoutHandler' objects.
  */

class timeoutHandlerFactory
{
public:

	virtual ~timeoutHandlerFactory() { }

	virtual ref <timeoutHandler> create() = 0;
};


} // net
} // vmime


#endif // VMIME_NET_TIMEOUTHANDLER_HPP_INCLUDED
