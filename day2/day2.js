const fs = require('fs');

const data = fs.readFileSync('./day2.txt')
const lines = data.toString().split(/\n/)

let part1 = 0
lines.forEach(line => {
    const [constraint, letterconstraint, string] = line.split(" ")
    const [lletter, uletter] = constraint.split("-")
    const letter = letterconstraint.charAt(0)
    const lower = parseInt(lletter)
    const upper = parseInt(uletter)
    let count = string.split(letter).length - 1

    if (lower <= count && count <= upper) part1++

})
