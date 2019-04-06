open Utils;

type state ={
    clickedMenu: string
}

type action = 
| Clicked(string)

let component = ReasonReact.reducerComponent("Menu");

let reducer = (action, _state) =>{
switch(action){
    | Clicked(clickedMenu) => ReasonReact.Update({clickedMenu: clickedMenu})
    }
}  

let make = _children => {
  ...component,
  initialState: () => {clickedMenu: "Home"},
  reducer,
  render: self =>
    <div
      className="w-full md:w-1/5 bg-black md:bg-black px-2 text-center fixed pin-b md:pt-8 md:pin-t md:pin-l h-16 md:h-screen md:border-r-4 md:border-grey-dark">
      <div className="md:relative mx-auto lg:float-right lg:px-6">
        <ul className="list-reset flex flex-row md:flex-col text-center md:text-left">
          <li className="mr-3 flex-1">
            <a
              href="#"
              className={(self.state.clickedMenu == "Home") ? "block py-1 md:py-3 pl-1 align-middle text-white no-underline border-b-2 border-orange-dark" : "block py-1 md:py-3 pl-1 align-middle text-grey-darkest no-underline hover:text-orange border-b-2 border-grey-darkest md:border-black hover:border-orange"}
              onClick={_e => {ReasonReact.Router.push("/home"); self.send(Clicked("Home"))}}>
              <i className="fas fa-home pr-0 md:pr-3" />
              <span
                className="pb-1 md:pb-0 text-xs md:text-base text-grey-dark md:text-grey-light block md:inline-block">
                {str("home")}
              </span>
            </a>
          </li>
          <li className="mr-3 flex-1">
            <a
              href="#"
              className={(self.state.clickedMenu == "YourEvents") ? "block py-1 md:py-3 pl-1 align-middle text-white no-underline border-b-2 border-orange-dark" : "block py-1 md:py-3 pl-1 align-middle text-grey-darkest no-underline hover:text-orange border-b-2 border-grey-darkest md:border-black hover:border-orange"}
              onClick={_e => {ReasonReact.Router.push("/your-events"); self.send(Clicked("YourEvents"))}}>
              <i className="fas fa-calendar-day pr-0 md:pr-3" />
              <span
                className="pb-1 md:pb-0 text-xs md:text-base text-grey-dark md:text-grey-light block md:inline-block">
                {str("Your Events")}
              </span>
            </a>
          </li>
          <li className="mr-3 flex-1">
            <a
              href="#"
              className={(self.state.clickedMenu == "Map") ? "block py-1 md:py-3 pl-1 align-middle text-white no-underline border-b-2 border-orange-dark" : "block py-1 md:py-3 pl-1 align-middle text-grey-darkest no-underline hover:text-orange border-b-2 border-grey-darkest md:border-black hover:border-orange"}
              onClick={_e => {ReasonReact.Router.push("/map"); self.send(Clicked("Map"))}}
              >
              <i className="fas fa-map-marked pr-0 md:pr-3" />
              <span
                className="pb-1 md:pb-0 text-xs md:text-base text-grey-dark md:text-grey-light block md:inline-block">
                {str("Map")}
              </span>
            </a>
          </li>
          <li className="mr-3 flex-1">
            <a
              href="#"
              className={(self.state.clickedMenu == "Profile") ? "block py-1 md:py-3 pl-1 align-middle text-white no-underline border-b-2 border-orange-dark" : "block py-1 md:py-3 pl-1 align-middle text-grey-darkest no-underline hover:text-orange border-b-2 border-grey-darkest md:border-black hover:border-orange"}
              onClick={_e => {ReasonReact.Router.push("/profile"); self.send(Clicked("Profile"))}}>
              <i className="fas fa-user pr-0 md:pr-3" />
              <span
                className="pb-1 md:pb-0 text-xs md:text-base text-grey-dark md:text-grey-light block md:inline-block">
                {str("Profile")}
              </span>
            </a>
          </li>
        </ul>
      </div>
    </div>,
};
