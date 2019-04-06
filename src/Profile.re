open Utils;

let component = ReasonReact.statelessComponent("Profile");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container mx-auto w-full py-10 flex flex-wrap items-stretch">
      <div className="w-full py-4">
        <div className="p-4"> <h1 className="py-4"> {str("Profile")} </h1> </div>
        <p> {str("Here you can manage your subscriptions to particular events")} </p>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Current tags")} </h2>
        <div className="p-2">
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#social")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#culture")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#academic")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#free-food")}
          </span>
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Current clubs")} </h2>
        <div className="p-2">
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#monash-sausage-club")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#monash-japanese-club")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#monash-new-zealand-student-association")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#monash-university-islamic-society")}
          </span>
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Other tags")} </h2>
        <div className="p-2">
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#competitive")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#charity/volunteering")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#spiritual")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#free-drinks")}
          </span>
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Other clubs")} </h2>
        <div className="p-2">
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#phantom-blood-club")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#kbbq-club")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#dog-appreciation-society")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#msg-noodle-club")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#keep-hydrated-club")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#sleep-deprived-at-monash")}
          </span>
          <span
            className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2">
            {str("#monash-sausage-hunters")}
          </span>
        </div>
      </div>
    </div>,
};
