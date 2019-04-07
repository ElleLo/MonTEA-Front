open Utils;

let component = ReasonReact.statelessComponent("Map");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container mx-auto w-full py-10 tems-stretch">
      <div className="w-full py-4">
        <div className="p-4 pb-6">
          <h1 className="py-4 font-mono text-orange-dark"> {str("Map")} </h1>
          <p>
            {str(
               "Here is an interactive map of all the events currently happening at Monash, for more information, click on a marker to display the event information.",
             )}
          </p>
        </div>
        <div> <img src="https://i.imgur.com/yt4Uk8X.jpg" /> </div>
      </div>
    </div>,
};
