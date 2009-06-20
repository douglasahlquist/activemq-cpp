/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/ConsumerControl.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>
#include <memory>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for ConsumerControl
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ConsumerControl::ConsumerControl()
{
    this->close = false;
    this->consumerId = NULL;
    this->prefetch = 0;
    this->flush = false;
    this->start = false;
    this->stop = false;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerControl::~ConsumerControl()
{
    delete this->consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerControl* ConsumerControl::cloneDataStructure() const {
    std::auto_ptr<ConsumerControl> consumerControl( new ConsumerControl() );

    // Copy the data from the base class or classes
    consumerControl->copyDataStructure( this );

    return consumerControl.release();
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const ConsumerControl* srcPtr = dynamic_cast<const ConsumerControl*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ConsumerControl::copyDataStructure - src is NULL or invalid" );
    }
    this->setClose( srcPtr->isClose() );
    if( srcPtr->getConsumerId() != NULL ) {
        this->setConsumerId(
            dynamic_cast<ConsumerId*>(
                srcPtr->getConsumerId()->cloneDataStructure() ) );
    }
    this->setPrefetch( srcPtr->getPrefetch() );
    this->setFlush( srcPtr->isFlush() );
    this->setStart( srcPtr->isStart() );
    this->setStop( srcPtr->isStop() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ConsumerControl::getDataStructureType() const {
    return ConsumerControl::ID_CONSUMERCONTROL;
}

////////////////////////////////////////////////////////////////////////////////
std::string ConsumerControl::toString() const {

    ostringstream stream;

    stream << "Begin Class = ConsumerControl" << std::endl;
    stream << " Value of ConsumerControl::ID_CONSUMERCONTROL = 17" << std::endl;
    stream << " Value of Close = " << this->isClose() << std::endl;
    stream << " Value of ConsumerId is Below:" << std::endl;
    if( this->getConsumerId() != NULL ) {
        stream << this->getConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Prefetch = " << this->getPrefetch() << std::endl;
    stream << " Value of Flush = " << this->isFlush() << std::endl;
    stream << " Value of Start = " << this->isStart() << std::endl;
    stream << " Value of Stop = " << this->isStop() << std::endl;
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = ConsumerControl" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerControl::equals( const DataStructure* value ) const {
    const ConsumerControl* valuePtr = dynamic_cast<const ConsumerControl*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->isClose() != valuePtr->isClose() ) {
        return false;
    }
    if( this->getConsumerId() != NULL ) {
        if( !this->getConsumerId()->equals( valuePtr->getConsumerId() ) ) {
            return false;
        }
    } else if( valuePtr->getConsumerId() != NULL ) {
        return false;
    }
    if( this->getPrefetch() != valuePtr->getPrefetch() ) {
        return false;
    }
    if( this->isFlush() != valuePtr->isFlush() ) {
        return false;
    }
    if( this->isStart() != valuePtr->isStart() ) {
        return false;
    }
    if( this->isStop() != valuePtr->isStop() ) {
        return false;
    }
    if( !BaseCommand<transport::Command>::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerControl::isClose() const {
    return close;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setClose(bool close ) {
    this->close = close;
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* ConsumerControl::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* ConsumerControl::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setConsumerId(ConsumerId* consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
int ConsumerControl::getPrefetch() const {
    return prefetch;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setPrefetch(int prefetch ) {
    this->prefetch = prefetch;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerControl::isFlush() const {
    return flush;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setFlush(bool flush ) {
    this->flush = flush;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerControl::isStart() const {
    return start;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setStart(bool start ) {
    this->start = start;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerControl::isStop() const {
    return stop;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerControl::setStop(bool stop ) {
    this->stop = stop;
}
