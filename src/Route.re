type route =
  | App
  | NotFound;

type state = {route}; 

type action = 
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | ["app"] => App
  | _ => NotFound
  };
  
let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };


let component = ReasonReact.reducerComponent("Route");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: App},
  didMount: (self) => {
    let watchId =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> mapUrlToRoute))
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watchId));
  },
  render: self =>
    <div className="container scrollable-x column is-10">
      (switch (self.state.route){
        | App => <App />
        | NotFound => <div className="section">{ReasonReact.string("Page does not exist. ")}</div>
      }
      )
    </div>,
};