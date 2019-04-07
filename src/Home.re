open Utils;
open UserData;

let tableKey: ref(int) = ref(0);

type eventInfo = {
  event_id: string,
  event_name: string,
  event_date: string,
  event_startTime: string,
  event_endTime: string,
  event_image: string,
  event_host: string,
  event_tags: array(string),
  event_venue: string
}

type state = {
  data: option(eventsData),
  events: array(array(eventInfo)),
  name: string,
  sub_tags: array(array(string)),
  sub_clubs: array(array(string)),
};

type action =
  | Fetch(string, array(string))
  | Fetched((state, eventsData));

let component = ReasonReact.reducerComponent("Home");

let createEventArray = eventList => {
  ArrayLabels.length(eventList) === 0
    ? [|
      {
        event_id: "-1",
        event_name: "",
        event_date: "",
        event_startTime: "",
        event_endTime: "",
        event_image: "",
        event_host: "",
        event_tags: [||],
        event_venue: ""
    }|]
    :Array.map(array => {
        event_id: array[0],
        event_name: array[1],
        event_date: array[7],
        event_startTime: array[5],
        event_endTime: array[6],
        event_image: array[9],
        event_host: array[3],
        event_tags: {
          Js.String.split(",", Js.String.slice(0, Js.String.length(array[10])-1, array[10]))
          },
          event_venue: array[4]
    }, eventList)

};

let reducer = (action, state) =>
  switch (action) {
  | Fetch(method, params) =>
    ReasonReact.SideEffects(
      self => fetchData(method, params, Decode.getEventData, state, payload => self.send(Fetched(payload))),
    )
  | Fetched((_state, payload)) =>
    ReasonReact.Update({
      data: Some(payload),
      events: {
        [|payload.events[0][0] != "-1" ? createEventArray(payload.events) : createEventArray([||])|];
      },
      name: payload.name,
      sub_tags: payload.sub_tags,
      sub_clubs: payload.sub_clubs,
    })
  };

module EventItem = {
  let component = ReasonReact.statelessComponent("EventItem");

  let make = (~item, _children) => {
    // let make = (_children) => {
    ...component,
    render: _self =>
      <div className="md:w-1/3 overflow-hidden w-full p-4">
        <div className="border border-grey-light">
          <img className="h-48" src={item.event_image} />
          <div className="px-6 py-4">
            <div className="font-bold text-xl mb-2"> {str(item.event_name)} </div>
            <p className="text-grey-darker text-base"> {str(item.event_date ++ ", " ++ item.event_startTime ++ " - " ++ item.event_endTime)} </p>
            <p className="text-grey-darker text-base py-2"> {str(item.event_venue)} </p>

          </div>
          <div className="px-6 py-4">
            {Array.map(
               item => {
                 incrementId(tableKey);
                 <span
                   key={string_of_int(tableKey^)}
                   className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2">
                   {str("#" ++ item)}
                 </span>;
               },
               item.event_tags,
             )
             |> ReasonReact.array}
          </div>
        </div>
      </div>,
  };
};

let make = (~userId, _children) => {
  ...component,
  initialState: () => {data: None, events: [||], name: "(Loading User)", sub_tags: [||], sub_clubs: [||]},
  reducer,
  didMount: self => self.send(Fetch("chronological_order_events", [|userId|])),
  render: self =>
    <div className="container mx-auto w-full py-10 flex flex-wrap items-stretch">
      <div className="w-full text-center py-4">
        <div className="p-4">
          <h1 className="py-4 font-mono text-orange-dark"> {str("Welcome to MONTEA, " ++ self.state.name)} </h1>
          <p className="">
            {str(
               "There are lots of great events coming up this week! Here are a selection of the events coming up this week based on your subscriptions.",
             )}
          </p>
          <p className="pb-4"> {str("You have subscribed to the following topics:")} </p>
          {self.state.sub_clubs == [||]
             ? <div />
             : self.state.sub_clubs[0][0] == "-1" && self.state.sub_tags[0][0] == "-1"
                 ? <div className="w-full text-center py-4">
                     {str("There are no clubs for you to subscribe to.")}
                   </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-red-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2"
                         onClick={e =>
                           self.send(Fetch("get_tagged_events", [|userId, getButtonValueFromEvent(e)|]))
                         }>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.sub_clubs,
                   )
                   |> ReasonReact.array}
          {self.state.sub_tags == [||]
             ? <div className="w-full text-center py-4">
                 <i className="fas fa-spinner fa-pulse" />
                 <p> {str("Loading subscriptions..")} </p>
               </div>
             : self.state.sub_clubs[0][0] == "-1" && self.state.sub_tags[0][0] == "-1"
                 ? <div className="w-full text-center py-4">
                     {str("There are no clubs for you to subscribe to.")}
                   </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-blue-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2"
                         onClick={e =>
                           self.send(Fetch("get_tagged_events", [|userId, getButtonValueFromEvent(e)|]))
                         }>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.sub_tags,
                   )
                   |> ReasonReact.array}
          <button
            className="inline-block bg-green-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2"
            onClick={_e => self.send(Fetch("chronological_order_events", [|userId|]))}>
            {str("Show All Events")}
          </button>
        </div>
      </div>
      {self.state.events == [||]
         ? <div className="w-full text-center py-4">
             <i className="fas fa-spinner fa-pulse" />
             <p> {str("Loading Events..")} </p>
           </div>
         : self.state.events[0][0].event_id == "-1"
             ? <div className="w-full text-center py-4"> {str("No events available!")} </div>
             : Array.map(
                 arrayOfArrays =>
                   Array.map(
                     array => {
                       incrementId(tableKey);
                       <EventItem key={string_of_int(tableKey^)} item=array />;
                     },
                     arrayOfArrays,
                   )
                   |> ReasonReact.array,
                 self.state.events,
               )
               |> ReasonReact.array}
    </div>,
};
