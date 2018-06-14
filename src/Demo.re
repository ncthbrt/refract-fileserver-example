let prism =
  [%refract.post "/hello/{name:string}/{surname:string}"]((~name, ~surname) => {
    let%refract bodyStr = Refract.Request.Body.string;
    Js.log(bodyStr);
    Js.log2(name, surname);
    %refract.await
    Refract.Response.Body.file("world.txt");
    Js.log("eep");
    Refract.Response.ok;
  });

Refract.Server.start(~port=3002, prism);