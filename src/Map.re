open Utils;

let component = ReasonReact.statelessComponent("Map");

let make = _children => {...component, render: _self => <div> {str("Map")} </div>};
