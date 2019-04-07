open Utils;
open UserData;

[%bs.raw {|require('./app.css')|}];

let tableKey: ref(int) = ref(0);

type state = {
  data: option(profileData),
  subTags: array(array(string)),
  subClubs: array(array(string)),
  unsubTags: array(array(string)),
  unsubClubs: array(array(string)),
  sub_loading: bool,
};

type action =
  | Fetch(string, array(string))
  | Fetched((state, profileData))
  | ChangeLoadingStatus;

let component = ReasonReact.reducerComponent("Profile");

let reducer = (action, state) =>
  switch (action) {
  | Fetch(method, params) =>
    ReasonReact.SideEffects(
      self => fetchData(method, params, Decode.getProfileData, state, payload => self.send(Fetched(payload))),
    )
  | Fetched((_state, payload)) =>
    ReasonReact.Update({
      data: Some(payload),
      subTags: payload.subTags,
      subClubs: payload.subClubs,
      unsubTags: payload.unsubTags,
      unsubClubs: payload.unsubClubs,
      sub_loading: false,
    })
  | ChangeLoadingStatus => ReasonReact.Update({...state, sub_loading: !state.sub_loading})
  };

let make = (~userId, _children) => {
  ...component,
  initialState: () => {
    data: None,
    subTags: [||],
    subClubs: [||],
    unsubTags: [||],
    unsubClubs: [||],
    sub_loading: false,
  },
  reducer,
  didMount: self => self.send(Fetch("get_profile_data", [|userId|])),
  render: self =>
    <div className="container mx-auto h-full w-full py-10 flex flex-wrap items-stretch">
      {self.state.sub_loading
         ? <img
             className="flex-initial"
             src="https://cdn.discordapp.com/attachments/436508647468564491/564131352467996693/shibainu_loading.gif"
           />
         : <div />}
      <div className="w-full py-4">
        <div className="p-4"> <h1 className="py-4 font-mono text-orange-dark"> {str("Profile")} </h1> </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Subscribed tags")} </h2>
        <div className="p-2">
          {self.state.subTags == [||]
             ? <div className="w-full text-center py-4">
                 <i className="fas fa-spinner fa-pulse" />
                 <p> {str("Loading data..")} </p>
               </div>
             : self.state.subTags[0][0] == "-1"
                 ? <div className="w-full text-center py-4"> {str("You are not subscribed to any tags.")} </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2"
                         onClick={e => {
                           self.send(ChangeLoadingStatus);
                           self.send(Fetch("remove_sub_tags", [|userId, getButtonValueFromEvent(e)|]));
                         }}>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.subTags,
                   )
                   |> ReasonReact.array}
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Subscribed clubs")} </h2>
        <div className="p-2">
          {self.state.subClubs == [||]
             ? <div className="w-full text-center py-4">
                 <i className="fas fa-spinner fa-pulse" />
                 <p> {str("Loading data..")} </p>
               </div>
             : self.state.subClubs[0][0] == "-1"
                 ? <div className="w-full text-center py-4"> {str("You are not subscribed to any clubs.")} </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-orange-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2"
                         onClick={e => {
                           self.send(ChangeLoadingStatus);
                           self.send(Fetch("remove_sub_clubs", [|userId, getButtonValueFromEvent(e)|]));
                         }}>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.subClubs,
                   )
                   |> ReasonReact.array}
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Unsubscribed tags")} </h2>
        <div className="p-2">
          {self.state.unsubTags == [||]
             ? <div className="w-full text-center py-4">
                 <i className="fas fa-spinner fa-pulse" />
                 <p> {str("Loading data..")} </p>
               </div>
             : self.state.unsubTags[0][0] == "-1"
                 ? <div className="w-full text-center py-4">
                     {str("There are no tags for you to subscribe to.")}
                   </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2"
                         onClick={e => {
                           self.send(ChangeLoadingStatus);
                           self.send(Fetch("update_sub_tags", [|userId, getButtonValueFromEvent(e)|]));
                         }}>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.unsubTags,
                   )
                   |> ReasonReact.array}
        </div>
      </div>
      <div className="w-full p-4 text-left">
        <h2> {str("Unsubscribed clubs")} </h2>
        <div className="p-2">
          {self.state.unsubClubs == [||]
             ? <div className="w-full text-center py-4">
                 <i className="fas fa-spinner fa-pulse" />
                 <p> {str("Loading data..")} </p>
               </div>
             : self.state.unsubClubs[0][0] == "-1"
                 ? <div className="w-full text-center py-4">
                     {str("There are no clubs for you to subscribe to.")}
                   </div>
                 : Array.map(
                     item => {
                       incrementId(tableKey);
                       <button
                         key={string_of_int(tableKey^)}
                         value={Array.get(item, 0)}
                         className="inline-block bg-grey-lighter rounded-full px-3 py-1 text-sm font-semibold text-grey-darker mr-2 mt-2"
                         onClick={e => {
                           self.send(ChangeLoadingStatus);
                           self.send(Fetch("update_sub_clubs", [|userId, getButtonValueFromEvent(e)|]));
                         }}>
                         {str("#" ++ item[1])}
                       </button>;
                     },
                     self.state.unsubClubs,
                   )
                   |> ReasonReact.array}
        </div>
      </div>
    </div>,
};
