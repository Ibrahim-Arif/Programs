const prompt = require('prompt-sync')({sigint: true});
"use strict";

let createNode = (v) =>{
    return {value: v, left: null, right: null};
}

class BST{
    constructor(){
        this.root = null;
    }

    insertUtil(curr, n){
        if(n.value > curr.value){
            if(curr.right === null)
                curr.right = n;
            else
                this.insertUtil(curr.right, n);
        }
        if(n.value < curr.value){
            if(curr.left === null)
                curr.left = n;
            else
                this.insertUtil(curr.left, n)
        }
    }

    insert(value){
        let newNode = createNode(value);

        if(this.root === null)
            this.root = newNode;
        else
            this.insertUtil(this.root, newNode);
    }

    traverse(curr = this.root){
        if(curr.left !== null)
            this.traverse(curr.left);
        
        console.log(curr.value);

        if(curr.right !== null)
            this.traverse(curr.right);
    }

    search(curr = this.root, v){        // errors
        if(curr != null){
            if(curr.value == v){
                console.log('value found!!');
                return;
            }
            else if(curr.value > v)
                this.search(curr.left, v);
            else if(curr.value < v)
                this.search(curr.right, v);
        }
        else{
            console.log('value not found!!');
            return;
        }
    }
}

let tree = new BST();

tree.insert(5);
tree.insert(3);
tree.insert(7);
tree.insert(9);

tree.traverse();

tree.search(51);