open Utils;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container mx-auto w-full py-10 flex flex-wrap items-stretch">
      <div className="w-full text-center py-4">
        <div className="p-4">
          <h1 className="py-4"> {str("Welcome to Monash Party Finder, Harry")} </h1>
          <p className="">
            {str(
               "There are lots of great events coming up this week! Here are a selection of the events coming up this week based on your subscriptions.",
             )}
          </p>
          <p className="pb-4"> {str("You have subscribed to the following topics:")} </p>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
            {str("#social")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
            {str("#academic")}
          </span>
          <span
            className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker">
            {str("#free-food")}
          </span>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img
            className="h-48"
            src="https://scontent.fcbr1-1.fna.fbcdn.net/v/t1.0-9/28059157_946979332131457_7165184541920598166_n.jpg?_nc_cat=109&_nc_ht=scontent.fcbr1-1.fna&oh=5a6594412643437b10c91ba3e8816b7f&oe=5D3E8D49"
            alt="Sunset in the mountains"
          />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str("Monash NZSA Trivia Night")} </div>
            <p className="text-grey-darker text-base"> {str("Sun, Apr 7, 12:00pm-14:00pm")} </p>
            <p className="text-grey-darker text-base py-2"> {str("E359, 20 Chancellors Walk")} </p>
          </div>
          //              </div>
          <div className="px-6 py-4">
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#hello")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#cultural")}
            </span>
          </div>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img
            className="h-48"
            src="https://www.monashclubs.org/CMSModules/Avatars/CMSPages/GetAvatar.aspx?avatarguid=bda7da3e-79c2-4043-a601-c3ec064bb96a&maxsidesize=200"
            alt="Sunset in the mountains"
          />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str("The Timeless Miracle with Br Jafar Hussain")} </div>
            <p className="text-grey-darker text-base"> {str("Sun, Apr 7, 12:00pm-14:00pm")} </p>
            <p className="text-grey-darker text-base py-2"> {str("S1 Lecture Theatre, 16 Rainforest Walk")} </p>
          </div>
          //              </div>
          <div className="px-6 py-4">
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#social")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#paid")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#competitive")}
            </span>
          </div>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img
            className="h-48"
            src="https://www.monashclubs.org/CMSModules/Avatars/CMSPages/GetAvatar.aspx?avatarguid=15e8b216-7b22-4d76-90dc-b7bebd32d0db&maxsidesize=200"
            alt="Sunset in the mountains"
          />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str("Oragami Night")} </div>
            <p className="text-grey-darker text-base"> {str("Sun, Apr 7, 12:00pm-14:00pm")} </p>
            <p className="text-grey-darker text-base py-2"> {str("Japanese Studies Centre Auditorium")} </p>
          </div>
          //              </div>
          <div className="px-6 py-4">
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#social")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#culture")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#free-food")}
            </span>
          </div>
        </div>
      </div>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img
            className="h-48"
            src="https://www.monashclubs.org/CMSModules/Avatars/CMSPages/GetAvatar.aspx?avatarguid=41671f9b-2184-4fb2-bb4e-92f1683a0d74&maxsidesize=200"
            alt="Sunset in the mountains"
          />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str("Tech Industry Night")} </div>
            <p className="text-grey-darker text-base"> {str("un, Apr 7, 12:00pm-14:00pm")} </p>
            <p className="text-grey-darker text-base py-2"> {str("Campus Centre")} </p>
          </div>
          //              </div>
          <div className="px-6 py-4">
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#social")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#academic")}
            </span>
            <span
              className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker  mr-2 mt-2">
              {str("#free-food")}
            </span>
          </div>
        </div>
      </div>
    </div>,
};
