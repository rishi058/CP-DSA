import heapq

def max_k(n, arr, c, d):
    max_k = -1
    for k in range(1, d + 1):
        total_points = 0
        available_exercises = [-x for x in arr]  # Max heap for exercises
        heapq.heapify(available_exercises)
        last_performed = [-k] * n  # Last day each exercise was performed
        
        for day in range(d):
            # Find the best exercise that can be performed today
            while available_exercises:
                best_exercise = -heapq.heappop(available_exercises)
                exercise_index = arr.index(best_exercise)
                if day - last_performed[exercise_index] >= k:
                    total_points += best_exercise
                    last_performed[exercise_index] = day
                    heapq.heappush(available_exercises, -best_exercise)
                    break
            else:
                # No exercise can be performed today
                continue
        
        if total_points >= c:
            max_k = k
        else:
            break
    
    return max_k

# Example usage:
n = 2
arr = [100, 10]
c = 20
d = 10
print(max_k(n, arr, c, d))  # Output should be 2