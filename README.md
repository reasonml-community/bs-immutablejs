# bs-immutablejs

**Note**: these are **bindings** to the [Immutable.js](https://facebook.github.io/immutable-js/) library. These are only meant to be used to interoperate with existing JavaScript code; In OCaml/BuckleScript/Reason, we have more lightweight immutable (and optionally mutable) data structures by default (list, record, hashmap, set, and upcoming data structures).

Starting a new Reason/BuckleScript project with bs-immutablejs is like [TODO: add metaphor to illustrate why it's unnecessary].

## Documentation

No extra docs needed! It's a [single file](https://github.com/BuckleTypes/bs-immutablejs/blob/master/src/immJsRe.re) of `external`s. The API corresponds to Immutable.js' API.

## Contributing

Prerequisite: `https://github.com/reasonml/reason-cli`.

```
git clone https://github.com/BuckleTypes/bs-immutablejs.git
cd bs-immutablejs
npm install
npm start
```
