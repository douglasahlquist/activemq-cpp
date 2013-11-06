/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <decaf/internal/net/https/HttpsHandler.h>

#include <decaf/lang/exceptions/IllegalArgumentException.h>

using namespace decaf;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;
using namespace decaf::internal;
using namespace decaf::internal::net;
using namespace decaf::internal::net::https;

////////////////////////////////////////////////////////////////////////////////
HttpsHandler::~HttpsHandler() {
}

////////////////////////////////////////////////////////////////////////////////
decaf::net::URLConnection* HttpsHandler::openConnection(const decaf::net::URL& url) {
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
decaf::net::URLConnection* HttpsHandler::openConnection(const decaf::net::URL& url,
                                                        const decaf::net::Proxy* proxy) {

    if (proxy == NULL) {
        throw IllegalArgumentException(__FILE__, __LINE__, "proxy object cannot be NULL");
    }

    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
int HttpsHandler::getDefaultPort() const {
    return 80;
}
