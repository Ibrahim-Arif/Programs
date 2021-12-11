const prompt = require('prompt-sync')({sigint: true});
"use strict";

class stack{
    constructor(){
        this.arr = [];
    }

    pushIn(ele) {
        this.arr.push(ele);
    }

    popOut(){
        let popped = this.arr.pop();

        if(popped === undefined)
            return 'Stack underflow!\n';

        return popped;
    }
}

let s = new stack();
let s2 = new stack();

s.pushIn(1);
s.pushIn(2);
s.pushIn(3);

s2.pushIn(7);
s2.pushIn(8);
s2.pushIn(9);

console.log(s.popOut());
console.log(s.popOut());
console.log(s.popOut());
console.log(s.popOut());

console.log(s2.popOut());
console.log(s2.arr);