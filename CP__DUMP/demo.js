class Auth{
    api = "url...";
    constructor(){
        console.log(this.api);
    }
}

class Login extends Auth{
    child_api = this.api + "/login";

    constructor(){
        super();
        console.log(this.child_api);
    }
}

let obj = new Login();
// console.log(obj.child_api);