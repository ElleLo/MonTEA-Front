// Generated by BUCKLESCRIPT VERSION 5.0.0, PLEASE EDIT WITH CARE
'use strict';

var Home = require("./Home.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ServiceWorker = require("./serviceWorker");

((require('./index.css')));

function register_service_worker(prim) {
  ServiceWorker.register();
  return /* () */0;
}

function unregister_service_worker(prim) {
  ServiceWorker.unregister();
  return /* () */0;
}

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, Home.make(/* array */[])), "root");

ServiceWorker.unregister();

exports.register_service_worker = register_service_worker;
exports.unregister_service_worker = unregister_service_worker;
/*  Not a pure module */
