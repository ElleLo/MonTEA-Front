open Utils;

let component = ReasonReact.statelessComponent("CreateEvent");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div className="container mx-auto w-full py-10 tems-stretch">
        <div className="w-full py-4">
          <div className="p-4"> <h1 className="py-4 font-mono text-orange-dark"> {str("Create event")} </h1> </div>
          <p className="px-4">
            {str("Create events for your club or by yourself. Items marked with asterisk must be filled.")}
          </p>
        </div>
        <div className="flex flex-wrap p-4">
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Event Name *")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Event Name"
              />
            </div>
          </div>
          <div className="sm:w-1/2 w-full mb-4">
            <div className="sm:p-3">
              <p className="text-left pb-2"> {str("Host *")} </p>
              <input
                type_="text"
                name="name"
                className="flex flex-wrap w-full  leading-normal w-px border h-10 border-grey-light rounded px-3  focus:border-blue focus:shadow"
                placeholder="Host name"
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
                placeholder="Start time"
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
                placeholder="End time"
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
                placeholder="Date time"
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
                placeholder="Location"
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
          <div className="flex items-center justify-center w-full">
            <button className="block bg-orange-dark hover:bg-teal text-white font-bold py-2 px-4 rounded">
              {str("Create event")}
            </button>
          </div>
        </div>
      </div>
    </div>,
};
