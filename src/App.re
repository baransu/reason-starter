[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo: string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> {ReasonReact.string(message)} </h2>
      </div>
      <p className="App-intro">
        {ReasonReact.string("To get started, edit")}
        <code> {ReasonReact.string(" src/App.re ")} </code>
        {ReasonReact.string("and save to reload.")}
      </p>
    </div>,
};

/* Wrapping Reason component for JS world. Required only for JS import */

[@bs.deriving abstract]
type jsProps = {message: string};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~message=jsProps->messageGet, [||])
  );