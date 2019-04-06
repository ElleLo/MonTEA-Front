
open Utils;
open UserData;

type state = {
  username: string,
  password: string,
  userId: int,
  loginError: string,
}

type action =
    | Fetch(string, array(string))
    | Fetched((state, loginValidationData))
    | SetUsername(string)
    | SetPassword(string)

let component = ReasonReact.reducerComponent("Login");

let reducer = (action, state) =>
    switch(action){
        | Fetch(method, params) => ReasonReact.SideEffects(self => fetchData(
            method, 
            params, 
            Decode.getLoginValidation, 
            state, 
            payload => self.send(Fetched(payload))
            ))
        | Fetched((_state, payload)) => ReasonReact.UpdateWithSideEffects({
            ...state,
            loginError: {
                    payload.validation == 0? 
                        "Invalid Login Details"
                        : ""
                },
            userId: {payload.validation}
            }, 
        (self) =>
                self.state.loginError == ""?
                    {
                        ReactDOMRe.renderToElementWithId(<App/>, "root",);
                        ReasonReact.Router.push("/home");
                    }
                    : ()
        )
        | SetUsername(username) => ReasonReact.Update({...state, username})
        | SetPassword(password) => ReasonReact.Update({...state, password})
    }

let make = _children => {
  ...component,
  initialState: () => {
    username: "",
    password: "",
    loginError: "",
    userId: -1
    },
  reducer,
  render: self =>
    <div className="App">
      <div className="container mx-auto h-full flex justify-center items-center">
        <div className="w-1/2 text-center py-4">
          <h1 className="font-hairline mb-6 text-center"> {str("Login to Party Finder")} </h1>
          <div className="border-teal p-8 border-t-12 bg-white mb-6 rounded-lg shadow-lg">
          {
            self.state.loginError == ""?
            <p></p>
            : <p className="font-sans text-lg text-red-dark text-center">{str("Invalid login details")}</p>
          }
          
            <div className="mb-4">
              <label className="font-bold text-grey-darker block mb-2"> {str("Username or Email")} </label>
              <input
                className="block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow"
                type_="text"
                placeholder="Your Username"
                onChange={ e => self.send(SetUsername(getValueFromEvent(e)))}
              />
            </div>
            <div className="mb-4">
              <label className="font-bold text-grey-darker block mb-2"> {str("Password")} </label>
              <input
                type_="text"
                placeholder="Password"
                className="block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow"
                onChange={ e => self.send(SetPassword(getValueFromEvent(e)))}
              />
            </div>
            <div className="flex items-center justify-center">
              <button className="block bg-teal-dark hover:bg-teal text-white font-bold py-2 px-4 rounded"
              onClick={_e => self.send(Fetch("authenticate_user", [|self.state.username, self.state.password|]))}
              >
                {str("Login")}
              </button>
            </div>
          </div>
        </div>
      </div>
    </div>,
};
