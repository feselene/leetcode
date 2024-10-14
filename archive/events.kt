package archive

class Solution {
    fun smallestChair(times: Array<IntArray>, targetFriend: Int): Int {
        val events = mutableListOf<Pair<Int, Pair<Int, Int>>>()

        for (i in times.indices) {
            events.add(Pair(times[i][0], Pair(1, i))) // Arrival event
            events.add(Pair(times[i][1], Pair(0, i))) // Departure event
        }

        events.sortWith(compareBy({ it.first }, { it.second.first }))


        for (event in events) {
            val time = event.first
            val isArrival = event.second.first == 1
            val friendIdx = event.second.second
            if (isArrival) {
                val chair = availableChairs.poll()
                chairAssignment[friendIdx] = chair
                if (friendIdx == targetFriend) {
                    return chair
                }
            }
            else {
                availableChairs.add(chairAssignment[friendIdx]!!)
            }
        }

        return -1;
    }
}