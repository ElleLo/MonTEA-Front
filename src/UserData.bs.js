// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Fetch = require("bs-fetch/src/Fetch.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

var id = /* record */[/* contents */0.0];

function idGenerator(param) {
  id[0] += 1.0;
  return /* () */0;
}

function getProfileData(json) {
  return /* record */[
          /* subTags */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "sub_tags",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* subClubs */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "sub_clubs",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* unsubTags */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "unsub_tags",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* unsubClubs */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "unsub_clubs",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json)
        ];
}

function getEventData(json) {
  return /* record */[
          /* events */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "events",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* sub_tags */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "sub_tags",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* sub_clubs */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "sub_clubs",
                    /* [] */0
                  ]
                ], (function (param) {
                    return Json_decode.array((function (param) {
                                  return Json_decode.array(Json_decode.string, param);
                                }), param);
                  }))(json),
          /* name */Json_decode.at(/* :: */[
                  "result",
                  /* :: */[
                    "name",
                    /* [] */0
                  ]
                ], Json_decode.string)(json)
        ];
}

function getLoginValidation(json) {
  return /* record */[/* validation */Json_decode.field("result", Json_decode.$$int, json)];
}

var Decode = /* module */[
  /* getProfileData */getProfileData,
  /* getEventData */getEventData,
  /* getLoginValidation */getLoginValidation
];

function jsonRpcRequestPayload(method_, params) {
  var payload = { };
  idGenerator(/* () */0);
  payload["jsonrpc"] = "2.0";
  payload["id"] = id[0];
  payload["method"] = method_;
  payload["params"] = params;
  console.log(payload);
  return payload;
}

function fetchData(method_, params, decodeType, update, callback) {
  fetch("http://localhost:4000", Fetch.RequestInit[/* make */0](/* Post */2, {
                    "Content-Type": "application/json",
                    "Access-Control-Allow-Origin": "*",
                    "Access-Control-Allow-Methods": "GET, POST"
                  }, Caml_option.some(JSON.stringify(jsonRpcRequestPayload(method_, params))), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
              return prim.json();
            })).then((function (json) {
            var result = Curry._1(decodeType, json);
            Curry._1(callback, /* tuple */[
                  update,
                  result
                ]);
            return Promise.resolve(/* () */0);
          })).catch((function (err) {
          return Promise.resolve((console.log(err), /* () */0));
        }));
  return /* () */0;
}

exports.id = id;
exports.idGenerator = idGenerator;
exports.Decode = Decode;
exports.jsonRpcRequestPayload = jsonRpcRequestPayload;
exports.fetchData = fetchData;
/* No side effect */
