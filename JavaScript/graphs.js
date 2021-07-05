const prompt = require('prompt-sync')({sigint: true});
"use strict";

class graph{
    constructor(){
        this._connections = {};
        this.totalNodes = 0;
    }

    add(v1=null, v2=null){
        if(this._connections[v1] === undefined)
            this._connections[v1] = [];

        if(v2)
            this._connections[v1].push(v2);
    }

    showAll(){
        for(let person in this._connections){
            process.stdout.write(person + '-> ');
            
            for(let related of this._connections[person] )
                process.stdout.write(related + ', ');
            console.log();
        }
        console.log();
    }

    showSpecific(v1=null, v2=null){
        if(!v2)
            console.log(this._connections[v1]);                 // v2 not defined then show whole array of v1

        return this._connections[v1].find( value => (value == v2), v2);
    }

    delete(v1=null, v2=null){
        if(!v2)
            delete this._connections[v1];                       // v2 not defined then delete the property
        else{
            let index = this._connections[v1].indexOf(v2);
            if(index >= 0)                                      // if v2 found then delete
                this._connections[v1].splice(index, 1);         // from index delete 1 
        }
    }

    DfsUtil(ele, visited){
        visited[ele] = true;
        process.stdout.write(ele + ', ');

        if(this._connections[ele]){
            for(let i of this._connections[ele]){
                if(visited[i] != true)
                    this.DfsUtil(i, visited);
            }
        }
    }

    DFS(ele=null){
        let visited = {};
        this.DfsUtil(ele, visited)
    }
}

let g = new graph();

g.add('ibrahim');
g.add('ibrahim', 'burhan');
g.add('ibrahim', 'arif');
g.add('arif', 'ayesha');
g.add('ayesha', 'fatima');

g.showAll();
// console.log(g.showSpecific('ibrahim', 'burhan'));
// g.delete('ibrahim', 'burhan');
// g.showAll();
// g.DFS('ibrahim');

let g1 = new graph();
g1.add('spain', 'barca');
g1.add('spain', 'madrid');
g1.add('spain', 'atletico');
g1.add('italy', 'juventus');
g1.add('uk', 'arsenal');
g1.add('uk', 'chelsea');

g1.showAll();