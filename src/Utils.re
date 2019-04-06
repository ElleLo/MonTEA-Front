let str = ReasonReact.string;

let getValueFromEvent = event : string => 
    (
        event
        |> ReactEvent.Form.target
    )##value;