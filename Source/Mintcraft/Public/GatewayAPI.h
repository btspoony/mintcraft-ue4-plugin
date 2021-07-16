#pragma once

#include "CoreMinimal.h"

namespace mintcraft
{
  class FGatewayAPI
  {
  public:
    FGatewayAPI()
      : BaseURL(TEXT("http://localhost:8000/"))
    {}

  public:
    virtual FString& GetBaseURL() { return BaseURL; }

  private:
    FString BaseURL;
  };
}
