#include "hello_world.h"

void HelloWorldInstance::
HandleMessage(const pp::Var& var_message) 
{
    if (!var_message.is_string()) {
        return;
    }
    std::string message = var_message.AsString();

    if (message == "hello") {
        pp::Var var_reply = pp::Var("hello from NaCl");
        PostMessage(var_reply);
    }
}

