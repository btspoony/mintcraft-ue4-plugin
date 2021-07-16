#include "GatewayAPI.h"

namespace mintcraft
{
  FGatewayAPI::FGatewayAPI() : BaseURL(TEXT("http://localhost:8000/"))
  {
    //When the object is constructed, Get the HTTP module
    Http = &FHttpModule::Get();
  }

  bool FGatewayAPI::SendGet()
  {
    return false;
  }

  bool FGatewayAPI::SendPost()
  {
    return false;
  }

  bool FGatewayAPI::SendRequest()
  {
    return false;
  }

  /*Assigned function on successfull http call*/
  void FGatewayAPI::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
  {

    //Create a pointer to hold the json serialized data
    // TSharedPtr JsonObject;

    // //Create a reader pointer to read the json data
    // TSharedRef Reader = TJsonReaderFactory::Create(Response->GetContentAsString());

    // //Deserialize the json data given Reader and the actual object to deserialize
    // if (FJsonSerializer::Deserialize(Reader, JsonObject))
    // {
    //   // TODO handle json response
    //   // //Get the value of the json object by field name
    //   // int32 recievedInt = JsonObject->GetIntegerField("customInt");

    //   // //Output it to the engine
    //   // GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
    // }
  }
}