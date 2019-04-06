[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo: string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~userId, _children) => {
  ...component,
  render: _self =>
    <div className="App flex mb-5">
      <div className="md:w-1/5">
        <Menu />
      </div>
      <div className="md:w-4/5">
        <Route userId/>
      </div>
    </div>,
};
