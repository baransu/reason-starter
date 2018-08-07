let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => <div> (ReasonReact.string("Hello from React")) </div>,
};

/* Wrapping Reason component to JS world. Required only for JS import*/

let default = ReasonReact.wrapReasonForJs(~component, _props => make([||]));