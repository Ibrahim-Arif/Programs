const prompt = require('prompt-sync')({sigint: true});
"use strict";

// console.log("hello world");

//  -------------------------------------------- array, objects, arrow fucntion
// const createObject = (name, age) => {
//     return ( {'name': name, 'age': age} )
// }

// let data = []

// for(let i=0; i<3; i++){
//     let name = prompt('Name: ');
//     let age = prompt('age: ');

//     data.push( createObject(name, age) );
// }

// let search = prompt('Searching name: ');

// for(let i=0; i<data.length; i++){
//     if(data[i].name === search)
//         console.log("Age of", data[i].name, 'is: ', data[i].age)
// }


//      ------------------------------------ rest operation
// function restOperation(...arr){
//     let sum =0;
//     for(let i=0; i<arr.length; i++)
//         sum += arr[i];
//     return sum
// }
// console.log(restOperation(1, 2, 3, 4));


//      ------------------------------------ spread operator
// function test([...arr]){
//     arr[0] = 'changed';
//     console.log(arr);
// }

// let arr2 = [2, 3, 4];
// console.log(arr2);

// test(arr2);
// console.log(arr2);

//     --------------------------- -- distructing an object

// const person = {
//     name: 'ibrahim',
//     age: 20,
//     gender: 'male',
//     study: {
//         clas: 'bscs',
//         semester: 4,
//         university: 'COMSATS'
//     }
// }

// let {name: n, age: a, study: {university: u}} = person;     // destructing object into variables
// console.log(n, a, u);

// const printbasics = function({name}, {clas, university}){       // destructing object inside argument.
//     console.log(name, clas, university);
// }

// printbasics(person, person.study);

// class cat{
//     constructor(name, color){
//         this.fullname = name
//         this.color = color;
//     }

//     speak(){
//         console.log("meowwww")
//     }

//     set fullname(name){
//         let nameparts = name.split(' ');

//         this.firstname = nameparts[0];
//         this.lastname = nameparts[1];
//     }
//     get fullname(){
//         return this.firstname + ' ' + this.lastname; 
//     }
// }

// Object.defineProperty(cat, "breed", 
//     {
//         get: function(){
//             return this.breed;
//         },
//         set: function(value){
//             this.breed = value
//         }
//     })

// let cat1 = new cat('Jason Statham', 'Blue');

// console.log(cat1.fullname);
// cat1.speak();

// cat1.breed = 'Persian';
// console.log(cat1.breed);

// let cat2 = new cat('Tyler Joseph', 'Red');
// console.log(cat2.fullname);

// cat2.breed = 'Russian';
// console.log(cat2.breed);





// let arr = [7, 4, 2 ,11, 1];

// // arr.splice(2, 1, 9, 9);
// console.log(arr);

// let slicedArray = arr.slice(2, 4);
// console.log(slicedArray);

// arr.sort( (a, b) => a-b );      // assending order
// console.log(arr);

// arr.sort( (a, b) => b-a );      // desending order
// console.log(arr);

// console.log("Highest: " + Math.max.apply(null, arr));
// console.log("Lowest: " + Math.min.apply(null, arr));

// let total = 0;
// arr.forEach(value => total+=value);
// console.log(total);

// let arr2 = arr.map(value => value+2);
// console.log(arr2);

// let evenArr = arr.filter(value => !(value % 2) );
// console.log(evenArr);

// let oddArr = arr.filter((value, index) => (arr[index] % 2) );   // value => (value % 2) 
// console.log(oddArr);

// let sum = arr.reduce( (value, total) => total+value, 10);   // 10 is initial value for total
// console.log(sum);

// let isAllNotZero = arr.every(value => value != 0);
// console.log(isAllNotZero);

// arr.push(0);
// let isSomeZero = arr.some(value => value == 0);
// console.log(isSomeZero);

// for(element in arr)              // for in
//     console.log(arr[element]);

// for(element of arr)                 // for of
//     console.log(element);

// try{
//     let i = 5 / 0;
//     console.log(i);
// }catch(err){
//     console.log(err);
// }

// let person = {
//     name: 'ibrahim arif',
//     age: 18,
//     gender: 'male'
// };

// Object.defineProperty(person, 'age', {value: 20});
// console.log(person);

// for(element in person)
//     console.log(element + ": " +person[element]);

// let personArr = Object.values(person);
// for(ele of personArr)
//     console.log(ele);

// let stringPerson = JSON.stringify(person);
// console.log(stringPerson);

function car(model, color, year){
    this.model = model;
    this.color = color;
    this.year  = year;
}

car.prototype.company = 'suzuki';       // it will not display in object printing. 

let c1 = new car('mehran', 'white', 2007);
console.log(c1.company);

let c2 = new car('corola', 'black', 2018);
console.log(c2);

