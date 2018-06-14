# Refract File Server Example

Hello! This project allows you to quickly get started with Reason and the Node version of Refract. This example uses a very alpha version of the framework (native is also planned if the concept proves popular). I'd love to get some feedback on it. If you have any comments, please email me at github@ncthbrt.com. Documentation will focus on the parts that early users have the most trouble with, so the more feedback the better.

Refract is a little different to the middleware driven web-server that I'd imagine many web developers are used to. It is inspired by the approach taken by [SuaveIO](http://suave.io/). The key feature to understand in Refract, is that almost everything is a function.  
Most functions end in a particular shape, a shape that this library calls a `Prism.t`. 

A `Prism.t` is a function which takes in a `HttpContext.t` and returns either `Handled` with an updated `HttpContext`, `Unhandled`, or `Error` with the error that occurred. The uniformity of a Prism allows for composabilty and error handling without a sea of if/else and switch/match statements. 

## A note on syntax extensions

Refract comes with a few syntax extensions which I hope will make reading and writing backends more pleasant. 

Note that right now, the syntax extensions, such as `[%refract.post "/hello/{name:string}/{surname:string}"]`, `let%refract`, and `%refract.await` are only available on OSX. However refract is usable without them. For example:

`[%refract.post /hello/{name:string}/{surname:string}]` is approximately equivalent (without the named parameters) to:
```reason
(f) => Refract.compose(Refract.Request.post, Refract.Request.Pathname.matches(Refract.Request.Pathname.Constant("hello", String(String,End)), f));
```

`let%refract bodyString = Refract.Request.Body.string;` is equivalent to:
```reason
Refract.Request.Body.string(bodyString => /* rest of expression */);
```

Finally `%refract.await Refract.Response.Body.file("world.txt")` is equivalent to 
```reason
Refract.compose(Refract.Response.Body.file("world.txt"), ctx => ({/* Rest of expression */})(ctx));
```

## Build
```
npm run build
```

## Build + Watch

```
npm run start
```

## Installing in other projects

`npm install --save refract-server`

Add `refract-server` to the `bs-dependencies` section of `bsconfig.json`.

Finally to enable the syntax extensions, add `refract-server/ppx` to the `ppx-flags` array.