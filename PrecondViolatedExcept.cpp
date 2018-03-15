/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for an object thrown on violation of
 *  precondition.
 *
 *  Adapted from page 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 7 Feb 2018
 *
 *  @version 7.0 */

#include <stdexcept>
#include <string>

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
: std::logic_error(message.c_str() ) {
}
