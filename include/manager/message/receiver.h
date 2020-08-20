/*
 * Copyright 2020 tsurugi project.
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

#include "manager/message/status.h"
#include "manager/message/message.h"

namespace manager::message
{
    class Message;

    class Receiver
    {
        public:
            /**
             * @brief Derived class of this Receiver class will receive
             * an instance of Message class
             * and will get MessageId using message->get_id() method.
             * @param [in] message an instance of Message class that Receiver will receive.
             * @return an instance of Status class.
             * A primary error code and a secondary error code must be set.
             */
            virtual Status receive_message(Message *message) = 0;
    };

}; // namespace manager::message

#endif // RECEIVER_H