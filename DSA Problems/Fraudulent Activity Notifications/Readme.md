# Fraudulent Activity Notifications

HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to  the 2 x client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days  and a client's total daily expenditures for a period of  days, find and print the number of times the client will receive a notification over all  days.

> #### Problem Link - https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem

## Example

For example, d = 3 and ezpenditures = [10, 20, 30, 40, 50]. On the first three days, they just collect spending data. At day 4. we have trailing expenditures of [10, 20, 30]. The median is 20 and the day's expenditure is 40. Because 40 > 2 x 20, there will be a notice. The next day, our trailing expenditures are [20, 30, 40] and the expenditures are 50. This is less than 2 x 30 so no notice will be sent. Over the period, there was one notice sent.

Note: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. I there is an odd
number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the
average of the two middle values. (Wikipedia)


## Steps

- Step 1: Get the size of expenditure array
- Step 2: Create an freq array of size (no. of expenditure input + 1)
- Step 3: Create for loop and add the frequencies of each expenditure in freq array
- Step 4: When for loop index will be <= number of days given,
- Check if current expenditure is >= median of expenditure of last input days
- Step 5: If Step 4 is true increase number of notifications
- Step 6: Then decrease freq array size by 1
- Step 7: Then add the frequency of current expenditure
- Step 8: Return number of notifications
