import java.io.File

fun main() {
    // Part 1
    var ret = 0
    var groupSet : MutableSet<Char> = mutableSetOf()
    File("./input.txt").forEachLine innerFunc1@ {
        if (it.isEmpty()) {
            ret += groupSet.size
            groupSet = mutableSetOf()
            return@innerFunc1
        }
        for (i in it.indices) {
            groupSet.add(it.get(i))
        }
    }
    ret += groupSet.size
    println("Part 1 Sum: " + ret)

    // Part 2
    ret = 0
    var groupMap : MutableMap<Char, Int> = mutableMapOf()
    var groupSize = 0
    File("./input.txt").forEachLine innerFunc2@ {
        if (it.isEmpty()) {
            var sum = 0
            groupMap.forEach { _, v ->
                if (v == groupSize) {
                    sum += 1
                }
            }
            ret += sum
            groupMap = mutableMapOf()
            groupSize = 0
            return@innerFunc2
        }
        groupSize += 1
        for (i in it.indices) {
            val key = it.get(i)
            groupMap.putIfAbsent(key, 0)
            groupMap[key] = groupMap[key]!! + 1
        }
    }

    var sum = 0
    groupMap.forEach { _, v ->
        if (v == groupSize) {
            sum += 1
        }
    }
    ret += sum

    println("Part 2 Sum: " + ret)
}