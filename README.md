# bs-immutablejs

**Note**: these are **bindings** to the [Immutable.js](https://facebook.github.io/immutable-js/) library. These are only meant to be used to interoperate with existing JavaScript code; In Reason/BS, we have more lightweight immutable (and optionally mutable) data structures by default (list, record, hashmap, set, and upcoming data structures). New Reason/BS projects projects don't need bs-immutablejs.

## Documentation

The source is a [single file](https://github.com/reasonml-community/bs-immutablejs/blob/master/src/immJsRe.re) of BuckleScript `external`s. The API corresponds to Immutable.js' API.

Example usage:

```reason
let greeting = ImmutableJsRe.List.fromArray [|"hello", "world"|];

let extendedGreeting = ImmutableJsRe.List.push "how are you" greeting;

let reallyExtendedGreeting = ImmutableJsRe.List.(
  extendedGreeting
  |> push "I'm fine"
  |> push "thank you"
  |> push "and you?"
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

## Contributing

Prerequisite: `https://github.com/reasonml/reason-cli`.

```
git clone https://github.com/BuckleTypes/bs-immutablejs.git
cd bs-immutablejs
npm install
npm start
```
