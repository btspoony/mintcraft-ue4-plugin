#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"

namespace mintcraft
{
  class FGatewayAPI
  {
  public:
    FGatewayAPI();
    ~FGatewayAPI(){};

  public:
    virtual FString &GetBaseURL() { return BaseURL; }

    bool SendGet();

    bool SendPost();

  private:
    /*Assign this function to call when the GET request processes sucessfully*/
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    /** send http request */
    bool SendRequest();

  private:
    FHttpModule *Http;

    // base url of the gateway
    FString BaseURL;
  };
}
