const fs = require('fs');

const data = fs.readFileSync('./day2.txt')
const lines = data.toString().split(/\n/)

let part1 = 0
let part2 = 0

lines.forEach(line => {
    const [constraint, letterconstraint, string] = line.split(" ")
    const [lletter, uletter] = constraint.split("-")
    const letter = letterconstraint.charAt(0)
    const lower = parseInt(lletter)
    const upper = parseInt(uletter)
    let count = string.split(letter).length - 1

    if (lower <= count && count <= upper) part1++

    count = 0
    if (string.charAt(lower - 1) == letter) count++
    if (string.charAt(upper - 1) == letter) count++
    if (count === 1) part2++
})

console.log(part1, part2)
