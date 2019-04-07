open Utils;

let component = ReasonReact.statelessComponent("YourEvents");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div className="container mx-auto w-full py-10 tems-stretch">
        <div className="w-full py-4">
          <div className="p-4"> <h1 className="py-4 font-mono text-orange-dark"> {str("Edit event")} </h1> </div>
          <p className="px-4"> {str("Edit your existing event to add more information.")} </p>
        </div>
        <div className="md:w-1/3 overflow-hidden w-full p-4">
          <div className="border border-grey-light">
            <img
              className="h-48"
              src="https://scontent.fcbr1-1.fna.fbcdn.net/v/t1.15752-0/p280x280/56966759_1271879692960761_6424104639007817728_n.png?_nc_cat=108&_nc_ht=scontent.fcbr1-1.fna&oh=14c3fe43347abfd84770679a3faf1fbc&oe=5D4F37CC"
              alt="montea logo"
            />
            <div className="px-6 py-4">
              <div className="font-bold text-xl mb-2"> {str("MonTEA official Launch")} </div>
              <p className="text-grey-darker text-base"> {str("Sun, Apr 7, 12:00pm-14:00pm")} </p>
              <p className="text-grey-darker text-base py-2"> {str("Kenneth Hunt Lawn")} </p>
            </div>
            //              </div>
            <div className="px-6 py-4">
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
                {str("#free-food")}
              </span>
            </div>
          </div>
        </div>
        <div className="flex flex-wrap p-4">
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Event Name *")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3 focus:border-blue focus:shadow"
                value="MonTEA's official launch"
              />
            </div>
          </div>
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Host *")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3 focus:border-blue focus:shadow"
                value="MonTEA crew"
              />
            </div>
          </div>
          <div className="sm:w-1/3 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Start time *")} </p>
              <input
                type_="time"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                value="12:00:00"
              />
            </div>
          </div>
          <div className="sm:w-1/3 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("End time *")} </p>
              <input
                type_="time"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                value="14:00:00"
              />
            </div>
          </div>
          <div className="sm:w-1/3 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Date *")} </p>
              <input
                type_="date"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                value="2019-04-07"
              />
            </div>
          </div>
          <div className="w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Location *")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                value="Kenneth Hunt Lawn"
              />
            </div>
          </div>
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Latitude")} </p>
              <input
                type_="number"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Latitude"
              />
            </div>
          </div>
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Longitude")} </p>
              <input
                type_="number"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Longitude"
              />
            </div>
          </div>
          <div className="w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Description")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Description"
              />
            </div>
          </div>
          <div className="w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Facebook link")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Facebook"
              />
            </div>
          </div>
          <div className="w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Image")} </p>
              <input
                type_="file"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3 pt-1 focus:border-blue focus:shadow"
                accept="image/png, image/jpeg"
              />
            </div>
          </div>
          <div className="w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Tags")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="tags"
              />
            </div>
          </div>
          <div className="flex items-center justify-center w-full">
            <button className="block bg-orange-dark hover:bg-teal text-white font-bold py-2 px-4 rounded">
              {str("Update event")}
            </button>
          </div>
        </div>
      </div>
    </div>,
};
