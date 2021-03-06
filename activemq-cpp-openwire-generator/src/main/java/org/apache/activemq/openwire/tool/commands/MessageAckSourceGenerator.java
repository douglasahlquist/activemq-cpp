/**
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
package org.apache.activemq.openwire.tool.commands;

import java.io.PrintWriter;

public class MessageAckSourceGenerator extends CommandSourceGenerator {

    protected void generateAdditionalConstructors( PrintWriter out ) {

        out.println("////////////////////////////////////////////////////////////////////////////////");
        out.println("MessageAck::MessageAck(const Pointer<Message>& message, int ackType, int messageCount) :");
        out.println("    " + generateInitializerList() + " {");
        out.println("");
        out.println("    this->ackType = (unsigned char)ackType;");
        out.println("    this->destination = message->getDestination();");
        out.println("    this->lastMessageId = message->getMessageId();");
        out.println("    this->messageCount = messageCount;");
        out.println("}");
        out.println("");
        out.println("////////////////////////////////////////////////////////////////////////////////");
        out.println("MessageAck::MessageAck(const Pointer<MessageDispatch>& dispatch, int ackType, int messageCount) :");
        out.println("    " + generateInitializerList() + " {");
        out.println("");
        out.println("    this->ackType = (unsigned char)ackType;");
        out.println("    this->consumerId = dispatch->getConsumerId();");
        out.println("    this->destination = dispatch->getDestination();");
        out.println("    this->lastMessageId = dispatch->getMessage()->getMessageId();");
        out.println("    this->messageCount = messageCount;");
        out.println("}");
        out.println("");

        super.generateAdditionalConstructors(out);
    }
}
