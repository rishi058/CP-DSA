def process_event_queue(arrival_times):
    queue = []
    last_process_time = 0
    
    for time in sorted(arrival_times):
        # Process people in the queue
        while queue and queue[0] + 300 <= time:
            last_process_time = queue.pop(0) + 300
        
        # Remove people who have been in the queue for more than 300 seconds
        queue = [t for t in queue if t + 300 > time]
        
        # If queue length is 10 or less, add the person to the queue
        if len(queue) <= 10:
            queue.append(time)
    
    # Process remaining people in the queue
    while queue:
        last_process_time = queue.pop(0) + 300
    
    return last_process_time

# Test cases
print(process_event_queue([1, 6, 9, 502]))  # Should output 1201
print(process_event_queue([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]))  # Should output 3601