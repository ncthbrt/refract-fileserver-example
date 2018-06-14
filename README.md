# Refract File Server Example

Hello! This project allows you to quickly get started with Reason and the Node version of Refract. 

Note that right now, the syntax extensions, such as `[%refract.post "/hello/{name:string}/{surname:string}"]`, `let%refract`, and `%refract.await` are only available on OSX. Refract is usable without them. 

`[%refract.post /hello/{name:string}/{surname:string}]` is approximately equivalent to:
```reason
(f) => Refract.compose(Refract.Request.post, Refract.Request.Pathname.matches(Refract.Request.Pathname.Constant("hello", String(String,End)), f));
```

`let%refract bodyString = Refract.Request.Body.string;` is equivalent to:
```reason
Refract.Request.Body.string(bodyString => /* rest of expression */);
```

Finally `%refract.await Refract.Response.Body.file("world.txt")` is equivalent to 
```reason
Refract.compose(Refract.Response.Body.file("world.txt"), /* Rest of expression */);
```

# Build
```
npm run build
```

# Build + Watch

```
npm run start
```
