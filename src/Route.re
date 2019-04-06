type route =
  | Home
  | YourEvents
  | Map
  | Profile
  | NotFound;

type state = {route}; 

type action = 
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | ["home"] => Home
  | ["your-events"] => YourEvents
  | ["map"] => Map
  | ["profile"] => Profile
  | _ => NotFound
  };
  
let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };


let component = ReasonReact.reducerComponent("Route");

let make = (~userId, _children) => {
  ...component,
  reducer,
  initialState: () => {route: Home},
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
        | Home => <Home userId/>
        | YourEvents => <YourEvents />
        | Map => <Map />
        | Profile => <Profile userId/>
        | NotFound => <div className="section">{ReasonReact.string("Page does not exist. ")}</div>
      }
      )
    </div>,
};