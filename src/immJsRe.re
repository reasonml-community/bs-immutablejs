/**
 * Copyright 2004-present Facebook. All Rights Reserved.
 */
module OrderedMap = {
  type t 'key 'value;
  external get : t 'key 'value => 'key => option 'value =
    "" [@@bs.send] [@@bs.return nullable];
  external set : t 'key 'value => 'key => 'value => t 'key 'value = "" [@@bs.send];
  external filter : ('value => 'key => t 'key 'value => Js.boolean) => t 'key 'value =
    "" [@@bs.send.pipe : t 'key 'value];
  external map : ('value => 'key => t 'key 'value => 'value2) => t 'key 'value2 =
    "" [@@bs.send.pipe : t 'key 'value];
  external forEach : t 'key 'value => ('value => 'key => t 'key 'value => unit) => unit =
    "" [@@bs.send];
  external sort : t 'key 'value => ('value => 'value => int) => t 'key 'value = "" [@@bs.send];
  external has : t 'key 'value => 'key => bool = "" [@@bs.send];
  external reduce :
    t 'key 'value =>
    ('reduction => 'value => 'key => t 'key 'value => 'reduction) =>
    'reduction =>
    'reduction =
    "" [@@bs.send];
  external every : ('value => 'key => t 'key 'value => Js.boolean) => bool =
    "" [@@bs.send.pipe : t 'key 'value];
  external toArray : t 'key 'value => array 'value = "" [@@bs.send];
  external fromArray : array ('key, 'value) => t 'key 'value =
    "OrderedMap" [@@bs.module "immutable"];
  external fromDict : Js.Dict.t 'value => t string 'value = "OrderedMap" [@@bs.module "immutable"];
  external empty : unit => t 'key 'value = "OrderedMap" [@@bs.module "immutable"];
  external first : t 'key 'value => option 'value = "" [@@bs.send] [@@bs.return nullable];
  external count : t 'key 'value => int = "" [@@bs.send];
  external size : t 'key 'value => int = "" [@@bs.get];
  external isEmpty : t 'key 'value => bool = "" [@@bs.send];
};

module Map = {
  type t 'key 'value;
  external forEach : t 'key 'value => ('value => 'key => t 'key 'value => unit) => unit =
    "" [@@bs.send];
  external get : t 'key 'value => 'key => option 'value =
    "" [@@bs.send] [@@bs.return nullable];
  external filter : ('value => 'key => t 'key 'value => Js.boolean) => t 'key 'value =
    "" [@@bs.send.pipe : t 'key 'value];
  external map : ('value => 'key => t 'key 'value => 'value2) => t 'key 'value2 =
    "" [@@bs.send.pipe : t 'key 'value];
  external count : t 'key 'value => int = "" [@@bs.send];
  external size : t 'key 'value => int = "" [@@bs.get];
  external reduce :
    t 'key 'value =>
    ('reduction => 'value => 'key => t 'key 'value => 'reduction) =>
    'reduction =>
    'reduction =
    "" [@@bs.send];
  external sort : t 'key 'value => ('value => 'value => int) => t 'key 'value = "" [@@bs.send];
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
  external first : t 'value => option 'value = "" [@@bs.send] [@@bs.return nullable];
  external count : t 'value => int = "" [@@bs.send];
  external push : 'value => t 'value = "" [@@bs.send.pipe : t 'value];
  external isEmpty : t 'value => bool = "" [@@bs.send];
  external map : ('value => int => t 'value => 'value2) => t 'value2 =
    "" [@@bs.send.pipe : t 'value];
};

module Seq = {
  type t 'value;
  external filter : ('value => Js.boolean) => t 'value = "" [@@bs.send.pipe : t 'value];
  external toArray : t 'value => array 'value = "" [@@bs.send];
  external isEmpty : t 'value => bool = "" [@@bs.send];
  external count : t 'value => int = "" [@@bs.send];
  external sort : ('value => 'value => int) => t 'value = "" [@@bs.send.pipe : t 'value];
  external fromArray : array 'value => t 'value = "Seq" [@@bs.module "immutable"];
  external fromList : List.t 'value => t 'value = "Seq" [@@bs.module "immutable"];
  external slice : begin_::int? => end_::int? => t 'value = "" [@@bs.send.pipe : t 'value];
  external join : t 'value => string => string = "" [@@bs.send];
  external map : ('value => int => t 'value => 'value2) => t 'value2 =
    "" [@@bs.send.pipe : t 'value];
};
