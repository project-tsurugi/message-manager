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
 *	@file	error_code.h
 *	@brief  error code of message-broker
 */

#ifndef MESSAGE_BROKER_ERROR_CODE_H_
#define MESSAGE_BROKER_ERROR_CODE_H_

namespace manager::message-broker {

    enum class ErrorCode {
        /**
         *  @brief Success.
         */
        OK = 0,

        /**
         * @brief Unknown error.
         */
        UNKNOWN
    };

} // namespace manager::message-broker

#endif // MESSAGE_BROKER_ERROR_CODE_H_
