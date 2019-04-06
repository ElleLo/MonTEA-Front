let str = ReasonReact.string;

let getValueFromEvent = event : string => 
    (
        event
        |> ReactEvent.Form.target
    )##value;

let getButtonValueFromEvent = event : string => 
    (
        event
        |> ReactEvent.Mouse.target
    )##value;

let incrementId = (i) => {
        i := i^ + 1;
}