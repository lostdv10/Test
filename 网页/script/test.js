// function pow(a,b) {
//   // return 8; // :) 我们作弊啦！
//   // return a**b;
//   return Math.pow(a,b)
// }

// describe("pow", function() {

//   it("2 raised to power 3 is 8", function() {
//     assert.equal(pow(2, 3), 8);
//   });

//   it("3 raised to power 4 is 81", function() {
//     assert.equal(pow(3, 4), 81);
//   });

// });

export function hi() {
  alert(`Hello`);
}

export function bye() {
  alert(`Bye`);
}

export default function() {
  alert("Module loaded (export default)!");
}