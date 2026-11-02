
jobs = [
    ('A', 2, 100),
    ('B', 1, 19),
    ('C', 2, 27),
    ('D', 1, 25),
    ('E', 3, 15)
]

# Sort jobs according to profit in descending order
jobs.sort(key=lambda x: x[2], reverse=True)

max_deadline = max(job[1] for job in jobs)

# Create empty time slots
slots = [None] * max_deadline

total_profit = 0

# Schedule jobs
for job in jobs:
    job_id, deadline, profit = job

    for i in range(min(deadline, max_deadline) - 1, -1, -1):
        if slots[i] is None:
            slots[i] = job_id
            total_profit += profit
            break

print("Scheduled Jobs:", [job for job in slots if job is not None])
print("Total Profit:", total_profit)
