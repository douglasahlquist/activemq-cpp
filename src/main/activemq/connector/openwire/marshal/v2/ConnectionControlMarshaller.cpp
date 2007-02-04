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

#include <activemq/connector/openwire/marshal/v2/ConnectionControlMarshaller.h>

#include <activemq/connector/openwire/commands/ConnectionControl.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
DataStructure* ConnectionControlMarshaller::createObject() const {
    return new ConnectionControl();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char ConnectionControlMarshaller::getDataStructureType() const {
    return ConnectionControl::ID_CONNECTIONCONTROL;
}

///////////////////////////////////////////////////////////////////////////////
void ConnectionControlMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    ConnectionControl* info =
        dynamic_cast<ConnectionControl*>( dataStructure );
    info->setClose( bs->readBoolean() );
    info->setExit( bs->readBoolean() );
    info->setFaultTolerant( bs->readBoolean() );
    info->setResume( bs->readBoolean() );
    info->setSuspend( bs->readBoolean() );
}

///////////////////////////////////////////////////////////////////////////////
int ConnectionControlMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ) {

    ConnectionControl* info =
        dynamic_cast<ConnectionControl*>( dataStructure );

    int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    bs->writeBoolean( info->isClose() );
    bs->writeBoolean( info->isExit() );
    bs->writeBoolean( info->isFaultTolerant() );
    bs->writeBoolean( info->isResume() );
    bs->writeBoolean( info->isSuspend() );

    return rc + 0;
}

///////////////////////////////////////////////////////////////////////////////
void ConnectionControlMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    bs->readBoolean();
    bs->readBoolean();
    bs->readBoolean();
    bs->readBoolean();
    bs->readBoolean();
}

///////////////////////////////////////////////////////////////////////////////
void ConnectionControlMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ) {

    BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    ConnectionControl* info =
        dynamic_cast<ConnectionControl*>( dataStructure );
    info->setClose( dataIn->readBoolean() );
    info->setExit( dataIn->readBoolean() );
    info->setFaultTolerant( dataIn->readBoolean() );
    info->setResume( dataIn->readBoolean() );
    info->setSuspend( dataIn->readBoolean() );
}

///////////////////////////////////////////////////////////////////////////////
void ConnectionControlMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ) {

    ConnectionControl* info =
        dynamic_cast<ConnectionControl*>( dataStructure );
    BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    dataOut->write( info->isClose() );
    dataOut->write( info->isExit() );
    dataOut->write( info->isFaultTolerant() );
    dataOut->write( info->isResume() );
    dataOut->write( info->isSuspend() );
}

