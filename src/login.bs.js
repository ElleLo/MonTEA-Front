// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var App = require("./app.bs.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Utils = require("./Utils.bs.js");
var React = require("react");
var UserData = require("./UserData.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Login");

function reducer(action, state) {
  switch (action.tag | 0) {
    case 0 : 
        var params = action[1];
        var method_ = action[0];
        return /* SideEffects */Block.__(1, [(function (self) {
                      return UserData.fetchData(method_, params, UserData.Decode[/* getLoginValidation */0], state, (function (payload) {
                                    return Curry._1(self[/* send */3], /* Fetched */Block.__(1, [payload]));
                                  }));
                    })]);
    case 1 : 
        var payload = action[0][1];
        var match = payload[/* validation */0] !== -1 || payload[/* validation */0] !== -2;
        var match$1 = payload[/* validation */0] === -1;
        var tmp;
        if (match$1) {
          tmp = "Invalid Login Details";
        } else {
          var match$2 = payload[/* validation */0] === -2;
          tmp = match$2 ? "This account has been deactivated" : "";
        }
        return /* UpdateWithSideEffects */Block.__(2, [
                  /* record */[
                    /* username */state[/* username */0],
                    /* password */state[/* password */1],
                    /* userId */match ? payload[/* validation */0] : 0,
                    /* loginError */tmp
                  ],
                  (function (self) {
                      var match = self[/* state */1][/* loginError */3] === "";
                      if (match) {
                        ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, App.make(/* array */[])), "root");
                        return ReasonReact.Router[/* push */0]("/home");
                      } else {
                        return /* () */0;
                      }
                    })
                ]);
    case 2 : 
        return /* Update */Block.__(0, [/* record */[
                    /* username */action[0],
                    /* password */state[/* password */1],
                    /* userId */state[/* userId */2],
                    /* loginError */state[/* loginError */3]
                  ]]);
    case 3 : 
        return /* Update */Block.__(0, [/* record */[
                    /* username */state[/* username */0],
                    /* password */action[0],
                    /* userId */state[/* userId */2],
                    /* loginError */state[/* loginError */3]
                  ]]);
    
  }
}

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* loginError */3] === "";
              return React.createElement("div", {
                          className: "App"
                        }, React.createElement("div", {
                              className: "container mx-auto h-full flex justify-center items-center"
                            }, React.createElement("div", {
                                  className: "w-1/2 text-center py-4"
                                }, React.createElement("h1", {
                                      className: "font-hairline mb-6 text-center"
                                    }, Utils.str("Login to Party Finder")), React.createElement("div", {
                                      className: "border-teal p-8 border-t-12 bg-white mb-6 rounded-lg shadow-lg"
                                    }, match ? React.createElement("p", undefined) : React.createElement("p", {
                                            className: "font-sans text-lg text-red-dark text-center"
                                          }, Utils.str("Error")), React.createElement("div", {
                                          className: "mb-4"
                                        }, React.createElement("label", {
                                              className: "font-bold text-grey-darker block mb-2"
                                            }, Utils.str("Username or Email")), React.createElement("input", {
                                              className: "block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow",
                                              placeholder: "Your Username",
                                              type: "text"
                                            })), React.createElement("div", {
                                          className: "mb-4"
                                        }, React.createElement("label", {
                                              className: "font-bold text-grey-darker block mb-2"
                                            }, Utils.str("Password")), React.createElement("input", {
                                              className: "block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow",
                                              placeholder: "Password",
                                              type: "text"
                                            })), React.createElement("div", {
                                          className: "flex items-center justify-center"
                                        }, React.createElement("button", {
                                              className: "block bg-teal-dark hover:bg-teal text-white font-bold py-2 px-4 rounded",
                                              onClick: (function (_e) {
                                                  ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, App.make(/* array */[])), "root");
                                                  return ReasonReact.Router[/* push */0]("/home");
                                                })
                                            }, Utils.str("Login")))))));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* username */"",
                      /* password */"",
                      /* userId */-1,
                      /* loginError */""
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */reducer,
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.reducer = reducer;
exports.make = make;
/* component Not a pure module */
