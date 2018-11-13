#pragma once

#include <string>
#include <vector>
#include <map>

#include "../exception.h"
#include "abstractprotocolhandler.h"


#define KEY_REQUEST_VERSION     "jsonrpc"
#define JSON_RPC_VERSION2        "2.0"

namespace jsonrpc
{
    class RpcProtocolServerV2 : public AbstractProtocolHandler
    {
        public:
            RpcProtocolServerV2(IProcedureInvokationHandler &handler);

            void HandleJsonRequest(const Json::Value& request, Json::Value& response);
            bool ValidateRequestFields(const Json::Value &val);
            void WrapResult(const Json::Value& request, Json::Value& response, Json::Value& retValue);
            void WrapError(const Json::Value& request, int code, const std::string &message, Json::Value& result);
            void WrapException(const Json::Value& request, const JsonRpcException exception, Json::Value& result);
            procedure_t GetRequestType(const Json::Value& request);

        private:
            void HandleSingleRequest(const Json::Value& request, Json::Value& response);
            void HandleBatchRequest(const Json::Value& requests, Json::Value& response);
    };

} /* namespace jsonrpc */
