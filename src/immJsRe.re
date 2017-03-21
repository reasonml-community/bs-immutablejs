/**
 * Copyright 2004-present Facebook. All Rights Reserved.
 */
module OrderedMap = {
  type t 'key 'value;
  external get : t 'key 'value => 'key => option 'value =
    "" [@@bs.send] [@@bs.return undefined_to_opt];
  external filter : ('value => 'key => t 'key 'value => Js.boolean) => t 'key 'value =
    "" [@@bs.send.pipe : t 'key 'value];
  external map : ('value => 'key => t 'key 'value => 'value2) => t 'key 'value2 =
    "" [@@bs.send.pipe : t 'key 'value];
  external toArray : t 'key 'value => array 'value = "" [@@bs.send];
  external fromArray : array ('key, 'value) => t 'key 'value =
    "OrderedMap" [@@bs.module "immutable"];
  external first : t 'key 'value => option 'value = "" [@@bs.send] [@@bs.return undefined_to_opt];
  external count : t 'key 'value => int = "" [@@bs.send];
  external size : t 'key 'value => int = "" [@@bs.get];
};

module Map = {
  type t 'key 'value;
  external get : t 'key 'value => 'key => Js.undefined 'value = "" [@@bs.send];
  external filter : ('value => 'key => t 'key 'value => Js.boolean) => t 'key 'value =
    "" [@@bs.send.pipe : t 'key 'value];
  external map : ('value => 'key => t 'key 'value => 'value2) => t 'key 'value2 =
    "" [@@bs.send.pipe : t 'key 'value];
  external count : t 'key 'value => int = "" [@@bs.send];
  external size : t 'key 'value => int = "" [@@bs.get];
};

module Set = {
  type t 'value;
  external includes : t 'value => 'value => bool = "" [@@bs.send];
  external contains : t 'value => 'value => bool = "" [@@bs.send];
  external fromArray : array 'value => t 'value = "Set" [@@bs.module "immutable"];
};

module List = {
  type t 'value;
  external filter : ('value => Js.boolean) => t 'value = "" [@@bs.send.pipe : t 'value];
  external forEach : ('value => int => t 'value => Js.boolean) => int =
    "" [@@bs.send.pipe : t 'value];
  external toArray : t 'value => array 'value = "" [@@bs.send];
  external fromArray : array 'value => t 'value = "List" [@@bs.module "immutable"];
  external first : t 'value => option 'value = "" [@@bs.send] [@@bs.return undefined_to_opt];
  external count : t 'value => int = "" [@@bs.send];
  external push : 'value => t 'value = "" [@@bs.send.pipe : t 'value];
  external isEmpty : t 'value => bool = "" [@@bs.send];
  external map : ('value => int => t 'value => 'value2) => t 'value2 =
    "" [@@bs.send.pipe : t 'value];
};
