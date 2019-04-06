open Utils;

let component = ReasonReact.statelessComponent("Login");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header"> <h2 /> </div>
      <p className="App-intro">
        {ReasonReact.string("To get hello, edit")}
        <code> {ReasonReact.string(" src/app.re ")} </code>
        {str("and save to reload.")}
      </p>
    </div>,
};
