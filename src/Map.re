open Utils;

let component = ReasonReact.statelessComponent("Map");

let make = _children => {
    ...component,
    render: _self => 
    <div>
    <div className="flex">
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
    </div>
    <div className="flex">
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
    </div>
    <div className="flex">
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
    </div>
    <div className="flex">
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
    </div>
    <div className="flex">
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
        <div className="w-1/5 bg-grey h-48"></div>
        <div className="w-1/5 bg-grey-light h-48"></div>
    </div>
    </div>
    };
