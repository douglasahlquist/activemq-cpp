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

#include <activemq/connector/openwire/marshal/v2/KeepAliveInfoMarshaller.h>

#include <activemq/connector/openwire/commands/KeepAliveInfo.h>

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
DataStructure* KeepAliveInfoMarshaller::createObject() const {
    return new KeepAliveInfo();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char KeepAliveInfoMarshaller::getDataStructureType() const {
    return KeepAliveInfo::ID_KEEPALIVEINFO;
}

///////////////////////////////////////////////////////////////////////////////
void KeepAliveInfoMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

}

///////////////////////////////////////////////////////////////////////////////
int KeepAliveInfoMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ) {

    int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );

    return rc + 0;
}

///////////////////////////////////////////////////////////////////////////////
void KeepAliveInfoMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

}

///////////////////////////////////////////////////////////////////////////////
void KeepAliveInfoMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ) {

    BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
}

///////////////////////////////////////////////////////////////////////////////
void KeepAliveInfoMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ) {

    BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

}

