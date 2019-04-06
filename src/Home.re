open Utils;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container mx-auto w-full py-10 flex flex-wrap items-stretch">
      <div className="w-full text-center py-4">
        <div className="py-4">
          <h1 className="py-4"> {str("Welcome to Monash Party Finder, Harry")} </h1>
          <p className="">
            {str(
               "There are lots of great events coming up this week! Here are a selection of the events coming up this week based on your subscriptions.",
             )}
          </p>
          <p className="pb-4"> {str("You have subscribed to the following topics:")} </p>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#social")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#academic")}
          </span>
          <span className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker">
            {str("#free-food")}
          </span>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden  w-full p-4">
        <img className="w-full" src="https://tailwindcss.com/img/card-top.jpg" alt="Sunset in the mountains" />
        <div className="px-6 py-4 border border-grey-light">
          <div className="font-bold text-xl mb-2"> {str("The coldest sunset")} </div>
          <p className="text-grey-darker text-base"> {str("this is a bunch of text lalallalalalala")} </p>
        </div>
        <div className="px-6 py-4">
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#photo")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#travel")}
          </span>
          <span className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker">
            {str("#winter")}
          </span>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden border border-grey-light w-full p-4">
        <img className="w-full" src="https://tailwindcss.com/img/card-top.jpg" alt="Sunset in the mountains" />
        <div className="px-6 py-4 border border-grey-light">
          <div className="font-bold text-xl mb-2"> {str("The coldest sunset")} </div>
          <p className="text-grey-darker text-base"> {str("this is a bunch of text lalallalalalala")} </p>
        </div>
        <div className="px-6 py-4">
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#photo")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
            {str("#travel")}
          </span>
          <span className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker">
            {str("#winter")}
          </span>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img className="w-full" src="https://tailwindcss.com/img/card-top.jpg" alt="Sunset in the mountains" />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str("The coldest sunset")} </div>
            <p className="text-grey-darker text-base"> {str("this is a bunch of text lalallalalalala")} </p>
          </div>
          <div className="px-6 py-4">
            <span
              className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
              {str("#photo")}
            </span>
            <span
              className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
              {str("#travel")}
            </span>
            <span
              className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker">
              {str("#winter")}
            </span>
          </div>
        </div>
      </div>
    </div>,
};
