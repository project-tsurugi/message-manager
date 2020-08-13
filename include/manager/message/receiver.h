/*
 * Copyright 2019-2020 tsurugi project.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *	@file	receiver.h
 *	@brief  the receiver class that handle message
 */

#ifndef RECEIVER_H
#define RECEIVER_H

#include "manager/message/error_code.h"
#include "manager/message/message.h"

namespace manager::message
{
    class Message;

    class Receiver
    {
        public:
            virtual manager::message::ErrorCode receive_message(Message *message) = 0;
    };

}; // namespace manager::message

#endif // RECEIVER_H
