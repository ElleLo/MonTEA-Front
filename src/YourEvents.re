open Utils;

let component = ReasonReact.statelessComponent("YourEvents");

let make = _children => {
  ...component,
  render: _self =>
    <div>
        {str("Events")}
    </div>,
};