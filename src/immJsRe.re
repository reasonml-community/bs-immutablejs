/***
 * Copyright 2004-present Facebook. All Rights Reserved.
 */
module OrderedMap = {
  type t('key, 'value);
  [@bs.send] [@bs.return nullable]
  external get : (t('key, 'value), 'key) => option('value) = "";
  [@bs.send]
  external set : (t('key, 'value), 'key, 'value) => t('key, 'value) = "";
  [@bs.send]
  external filter :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => bool) =>
    t('key, 'value) =
    "";
  [@bs.send]
  external map :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => 'value2) =>
    t('key, 'value2) =
    "";
  [@bs.send]
  external forEach :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => unit) => unit =
    "";
  [@bs.send]
  external sort :
    (t('key, 'value), ('value, 'value) => int) => t('key, 'value) =
    "";
  [@bs.send] external has : (t('key, 'value), 'key) => bool = "";
  [@bs.send]
  external reduce :
    (
      t('key, 'value),
      ('reduction, 'value, 'key, t('key, 'value)) => 'reduction,
      'reduction
    ) =>
    'reduction =
    "";
  [@bs.send]
  external every :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => bool) => bool =
    "";
  [@bs.send] external toArray : t('key, 'value) => array('value) = "";
  [@bs.module "immutable"]
  external fromArray : array(('key, 'value)) => t('key, 'value) =
    "OrderedMap";
  [@bs.module "immutable"]
  external fromDict : Js.Dict.t('value) => t(string, 'value) = "OrderedMap";
  [@bs.module "immutable"]
  external empty : unit => t('key, 'value) = "OrderedMap";
  [@bs.send] [@bs.return nullable]
  external first : t('key, 'value) => option('value) = "";
  [@bs.send] external count : t('key, 'value) => int = "";
  [@bs.get] external size : t('key, 'value) => int = "";
  [@bs.send] external isEmpty : t('key, 'value) => bool = "";
};

module Set = {
  type t('value);
  [@bs.send] external includes : (t('value), 'value) => bool = "";
  [@bs.send] external contains : (t('value), 'value) => bool = "";
  [@bs.module "immutable"]
  external fromArray : array('value) => t('value) = "Set";
};

module OrderedSet = {
  type t('value);
  [@bs.send]
  external map :
    (t('value), ('value, 'value, t('value)) => 'value2) => t('value2) =
    "";
  [@bs.module "immutable"]
  external fromArray : array('value) => t('value) = "OrderedSet";
  [@bs.send] external toArray : t('value) => array('value) = "";
  [@bs.send] external add : (t('value), 'value) => t('value) = "";
  [@bs.send] external remove : (t('value), 'value) => t('value) = "";
  [@bs.send] external has : (t('value), 'value) => bool = "";
  [@bs.get] external size : t('value) => int = "";
  [@bs.send] external first : t('value) => 'value = "";
};

module List = {
  type t('value);
  [@bs.send] external filter : (t('value), 'value => bool) => t('value) = "";
  [@bs.send]
  external forEach : (t('value), ('value, int, t('value)) => bool) => int =
    "";
  [@bs.send] external toArray : t('value) => array('value) = "";
  [@bs.module "immutable"]
  external fromArray : array('value) => t('value) = "List";
  [@bs.send] [@bs.return nullable]
  external first : t('value) => option('value) = "";
  [@bs.send] external count : t('value) => int = "";
  [@bs.send] external push : (t('value), 'value) => t('value) = "";
  [@bs.send] external isEmpty : t('value) => bool = "";
  [@bs.send]
  external map :
    (t('value), ('value, int, t('value)) => 'value2) => t('value2) =
    "";
};

module Seq = {
  type t('value);
  [@bs.send] external filter : (t('value), 'value => bool) => t('value) = "";
  [@bs.send] external toArray : t('value) => array('value) = "";
  [@bs.send] external isEmpty : t('value) => bool = "";
  [@bs.send] external count : t('value) => int = "";
  [@bs.send]
  external sort : (t('value), ('value, 'value) => int) => t('value) = "";
  [@bs.module "immutable"]
  external fromArray : array('value) => t('value) = "Seq";
  [@bs.module "immutable"]
  external fromList : List.t('value) => t('value) = "Seq";
  [@bs.send]
  external slice :
    (t('value), ~begin_: int=?, ~end_: int=?, unit) => t('value) =
    "";
  [@bs.send] external join : (t('value), string) => string = "";
  [@bs.send] external take : (t('value), int) => t('value) = "";
  [@bs.send]
  external map :
    (t('value1), ('value, int, t('value)) => 'value2) => t('value2) =
    "";
};

module Map = {
  type t('key, 'value);
  [@bs.send]
  external forEach :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => unit) => unit =
    "";
  [@bs.send] [@bs.return nullable]
  external get : (t('key, 'value), 'key) => option('value) = "";
  [@bs.send]
  external filter :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => bool) =>
    t('key, 'value) =
    "";
  [@bs.send]
  external map :
    (t('key, 'value), ('value, 'key, t('key, 'value)) => 'value2) =>
    t('key, 'value2) =
    "";
  [@bs.send] external count : t('key, 'value) => int = "";
  [@bs.get] external size : t('key, 'value) => int = "";
  [@bs.send]
  external reduce :
    (
      t('key, 'value),
      ('reduction, 'value, 'key, t('key, 'value)) => 'reduction,
      'reduction
    ) =>
    'reduction =
    "";
  [@bs.send]
  external sort :
    (t('key, 'value), ('value, 'value) => int) => t('key, 'value) =
    "";
  [@bs.send] external valueSeq : t('key, 'value) => Seq.t('value) = "";
};
