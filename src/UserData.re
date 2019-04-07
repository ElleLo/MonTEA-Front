let id: ref(float) = ref(0.0);

let idGenerator = () => {
    id := id^ +. 1.0;
};

type loginValidationData = {
    validation: int
};

type eventsData = {
    events: array(array(string)),
    sub_tags: array(array(string)),
    sub_clubs: array(array(string)),
    name: string
};

type profileData = {
    subTags: array(array(string)),
    subClubs: array(array(string)),
    unsubTags: array(array(string)),
    unsubClubs: array(array(string))

};

module Decode = {

let getProfileData = json: profileData =>
    Json.Decode.{
        subTags: json |> at(["result", "sub_tags"], array(array(string))),
        subClubs:  json |> at(["result", "sub_clubs"], array(array(string))),
        unsubTags:  json |> at(["result", "unsub_tags"], array(array(string))),
        unsubClubs:  json |> at(["result", "unsub_clubs"], array(array(string))),
    }

let getEventData = json: eventsData =>
    Json.Decode.{
        events: json |> at(["result", "events"], array(array(string))),
        sub_tags: json |> at(["result", "sub_tags"], array(array(string))),
        sub_clubs: json |> at(["result", "sub_clubs"], array(array(string))),
        name: json |> at(["result", "name"], string),
    }

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
            "http://104.248.39.188:4000",
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