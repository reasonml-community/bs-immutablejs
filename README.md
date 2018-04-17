# bs-immutablejs

**Note**: these are **bindings** to the [Immutable.js](https://facebook.github.io/immutable-js/) library. These are only meant to be used to interoperate with existing JavaScript code; In Reason/BS, we have more lightweight immutable (and optionally mutable) data structures by default (list, record, hashmap, set, and upcoming data structures). New Reason/BS projects projects don't need bs-immutablejs.

## Documentation

The source is a [single file](https://github.com/reasonml-community/bs-immutablejs/blob/master/src/immJsRe.re) of BuckleScript `external`s. The API corresponds to Immutable.js' API.

Example usage:

```reason
let greeting = ImmutableJsRe.List.fromArray([|"hello", "world"|]);

let extendedGreeting = ImmutableJsRe.List.push(greeting, "how are you");

let reallyExtendedGreeting =
  ImmutableJsRe.List.(
    extendedGreeting
    |. push("I'm fine")
    |. push("thank you")
    |. push("and you?")
  );
```

Generated code:

```js
var greeting = Immutable.List(/* array */[
      "hello",
      "world"
    ]);
var extendedGreeting = greeting.push("how are you");
extendedGreeting.push("I'm fine").push("thank you").push("and you?");
```

## Transitioning to Idiomatic Reason/BuckleScript Data Structures

Here's a table of Immutable.js data structures and their Reason/BuckleScript equivalents. Reason/BS provide the data structures out of the box.

Immutable.js | Reason/BuckleScript
----|-----
List | List
Map | Map
OrderedMap | [Belt Map](https://bucklescript.github.io/bucklescript/api/Belt.Map.html)
Set | Set
OrderedSet | [Belt Set](https://bucklescript.github.io/bucklescript/api/Belt.Map.html)
Stack | List
Record | Record
Seq | Use `lazy`

## Contributing

Prerequisite: `https://github.com/reasonml/reason-cli`.

```
git clone https://github.com/BuckleTypes/bs-immutablejs.git
cd bs-immutablejs
npm install
npm start
```
