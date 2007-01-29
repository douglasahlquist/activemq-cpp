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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_DESTINATIONINFO_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_DESTINATIONINFO_H_

// Turn off warning message for ignored exception specification
#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <activemq/connector/openwire/commands/BaseCommand.h>
#include <activemq/connector/openwire/commands/ConnectionId.h>
#include <activemq/connector/openwire/commands/ActiveMQDestination.h>
#include <activemq/connector/openwire/commands/BrokerId.h>
#include <vector>
#include <string>

namespace activemq{
namespace connector{
namespace openwire{
namespace commands{

    /*
     *
     *  Command and marshalling code for OpenWire format for ${className}
     *
     *
     *  NOTE!: This file is autogenerated - do not modify!
     *         if you need to make a change, please see the Java Classes
     *         in the activemq-openwire-generator module
     *
     */
    class DestinationInfo : public BaseCommand
    {
    protected:

        ConnectionId* connectionId;
        ActiveMQDestination* destination;
        unsigned char operationType;
        long long timeout;
        std::vector<BrokerId*> brokerPath;

    public:

        const static unsigned char ID_DESTINATIONINFO = 8;

    public:

        DestinationInfo();
        virtual ~DestinationInfo();

        /**
         * Get the unique identifier that this object and its own
         * Marshaller share.
         * @returns new DataStructure type copy.
         */
        virtual unsigned char getDataStructureType() const;

        /**
         * Clone this object and return a new instance that the
         * caller now owns, this will be an exact copy of this one
         * @returns new copy of this object.
         */
        virtual DataStructure* cloneDataStructure() const;

        /**
         * Copy the contents of the passed object into this objects
         * members, overwriting any existing data.
         * @return src - Source Object
         */
        virtual void copyDataStructure( const DataStructure* src );

        virtual const ConnectionId* getConnectionId() const;
        virtual ConnectionId* getConnectionId();
        virtual void setConnectionId( ConnectionId* connectionId );

        virtual const ActiveMQDestination* getDestination() const;
        virtual ActiveMQDestination* getDestination();
        virtual void setDestination( ActiveMQDestination* destination );

        virtual const unsigned char getOperationType() const;
        virtual unsigned char getOperationType();
        virtual void setOperationType( unsigned char operationType );

        virtual const long long getTimeout() const;
        virtual long long getTimeout();
        virtual void setTimeout( long long timeout );

        virtual const std::vector<BrokerId*>& getBrokerPath() const;
        virtual std::vector<BrokerId*>& getBrokerPath();
        virtual void setBrokerPath( const std::vector<BrokerId*>& brokerPath );

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_DESTINATIONINFO_H_*/

