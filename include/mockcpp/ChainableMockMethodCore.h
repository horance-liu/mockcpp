
#ifndef __MOCKCPP_CHAINABLE_MOCK_METHOD_CORE_H
#define __MOCKCPP_CHAINABLE_MOCK_METHOD_CORE_H

#include <mockcpp/mockcpp.h>

#include <mockcpp/Method.h>
#include <mockcpp/InvocationMockerContainer.h>

#include <string>

MOCKCPP_NS_START

struct Stub;
struct ChainableMockMethodCoreImpl;
struct SelfDescribe;
struct InvokedRecorder;
struct InvocationMockerNamespace;

struct ChainableMockMethodCore
      : public Method,
		  public InvocationMockerContainer
{
public:

    ChainableMockMethodCore(const std::string& name, 
                            InvocationMockerNamespace* ns);
    ~ChainableMockMethodCore();

    // Method
    const Any& 
        invoke( const std::string& nameOfCaller
              , const RefAny& p1 
              , const RefAny& p2
              , const RefAny& p3
              , const RefAny& p4
              , const RefAny& p5
              , const RefAny& p6
              , const RefAny& p7
              , const RefAny& p8
              , const RefAny& p9
              , const RefAny& p10
              , const RefAny& p11
              , const RefAny& p12
              , SelfDescribe* &resultProvider);

    std::string& getName(void) const;

    InvocationMockerNamespace* getNamespace() const;

public:

    // InvocationMockContainer
    InvocationMocker* getInvocationMocker(const std::string& id);
    void addInvocationMocker(InvocationMocker* mocker);
    void addDefaultInvocationMocker(InvocationMocker* mocker);

public:
    // Others
    void reset();
    void verify();

private:

    ChainableMockMethodCoreImpl* This;
};

MOCKCPP_NS_END

#endif

