const prompt = require('prompt-sync')({sigint: true});
"use strict";

class queue{
    constructor(){
        this.arr = [];
    }

    enqueue(ele){
        this.arr.push(ele);
    }

    dequeue(){
        let dequeued = this.arr.shift();
        if(dequeued === undefined)
            return 'Queue underflow!\n';
        return dequeued;
    }
}

let q = new queue();
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);

console.log(q.dequeue());
console.log(q.dequeue());
console.log(q.dequeue());
console.log(q.dequeue());