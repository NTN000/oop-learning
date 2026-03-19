    #THINK AND PYTHON, CHAPTER 1:
    #Exercise 1.2: 

#1: How many seconds are there in 42 minutes and 42 seconds?
minutes = 42
seconds = 42
total_seconds = (minutes * 60) + seconds
print(total_seconds)

#2: How many miles are there in 10 kilometers? Hint: there are 1.61 kilometers in a mile.
kilometers = 10
miles = kilometers / 1.61
print(miles)

#3: If you run a 10 kilometer race in 42 minutes and 42 seconds, what is your average pace (time per mile)?
race_distance_km = 10
race_time_minutes = 42
race_time_seconds = 42

# Convert race time to seconds
total_race_time = (race_time_minutes * 60) + race_time_seconds

# Convert race distance to miles
race_distance_miles = race_distance_km / 1.61

# Calculate average pace in seconds per mile
average_pace = total_race_time / race_distance_miles
print(average_pace)