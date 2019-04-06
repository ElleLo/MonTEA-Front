let id: ref(float) = ref(0.0);

let idGenerator = () => {
    id := id^ +. 1.0;
};

type loginValidationData = {
    validation: int
};

module Decode = {

let getLoginValidation = json: loginValidationData =>
        Json.Decode.{
            validation: json |> field("result", int)
        }
};

let jsonRpcRequestPayload = (method, params) => {
  let payload = Js.Dict.empty();

  idGenerator();

  Js.Dict.set(payload, "jsonrpc", Js.Json.string("2.0"));
  Js.Dict.set(payload, "id", Js.Json.number(id^));
  Js.Dict.set(payload, "method", Js.Json.string(method));
  Js.Dict.set(payload, "params", Js.Json.stringArray(params));
  Js.log(payload);
  payload
};

let fetchData = (method, params, decodeType, update, callback) => 
    Js.Promise.(
        Fetch.fetchWithInit(
            "http://localhost:4000",
            Fetch.RequestInit.make(
                ~method_=Post,
                ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(jsonRpcRequestPayload(method, params)))),
                ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json", "Access-Control-Allow-Origin" : "*", "Access-Control-Allow-Methods" : "GET, POST"}),
                ()
            )
        )
        |> then_(Fetch.Response.json)
        |> then_(json =>
            json
            |> decodeType
            |> (result => {
                callback((update, result));
                resolve();
                })
        )
        |> catch(err => {
            Js.Promise.resolve(Js.log(err))
            /* Js.log(err); */
            /* error(); */
        })
        |> ignore
    );