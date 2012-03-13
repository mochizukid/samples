/*
 * 1. pp::CreateModule() => create pp::Module
 *    - called by the browser once when the module is first loaded
 *
 * 2. Module::CreateInstance() => create pp::Instance
 *    - called for every <embed> tag
 *
 *  [JavaScript]                [NaCl module (C++)]
 *  postMessage()     async=>   pp::Instance::HandleMessage()
 *  'message' event   <=async   pp::Instance::PostMessage()
 */

#include <cstdio>
#include <string>
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"

/*
 * HelloWorldInstance
 */
class HelloWorldInstance : public pp::Instance {
public:
    explicit HelloWorldInstance(PP_Instance instance) : pp::Instance(instance) {}
    virtual ~HelloWorldInstance() {}

    virtual void HandleMessage(const pp::Var& var_message);
};

/*
 * HelloWorldModule
 */
class HelloWorldModule : public pp::Module {
public:
    HelloWorldModule() : pp::Module() {}
    virtual ~HelloWorldModule() {}
  
    virtual pp::Instance* CreateInstance(PP_Instance instance) {
        return new HelloWorldInstance(instance);
    }
};

namespace pp {
/*
 * CreateModule
 */
Module* CreateModule() {
    return new HelloWorldModule();
}

} // namespace pp

