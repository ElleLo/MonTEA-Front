open Utils;

let component = ReasonReact.statelessComponent("Login");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="container mx-auto h-full flex justify-center items-center">
        <div className="w-1/2 text-center py-4">
          <h1 className="font-hairline mb-6 text-center"> {str("Login to Party Finder")} </h1>
          <div className="border-teal p-8 border-t-12 bg-white mb-6 rounded-lg shadow-lg">
            <div className="mb-4">
              <label className="font-bold text-grey-darker block mb-2"> {str("Username or Email")} </label>
              <input
                className="block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow"
                type_="text"
                placeholder="Your Username"
              />
            </div>
            <div className="mb-4">
              <label className="font-bold text-grey-darker block mb-2"> {str("Password")} </label>
              <input
                type_="text"
                placeholder="Password"
                className="block appearance-none w-full bg-white border border-grey-light hover:border-grey px-2 py-2 rounded shadow"
              />
            </div>
            <div className="flex items-center justify-center">
              <button className="block bg-teal-dark hover:bg-teal text-white font-bold py-2 px-4 rounded">
                {str("Login")}
              </button>
            </div>
          </div>
        </div>
      </div>
    </div>,
};
