name = input("Enter Student Name: ")
roll_no = input("Enter roll no.: ")

marks1 = input("Enter marks of subject 1: ")
marks1 = int(marks1)
marks2 = input("Enter marks of subject 2: ")
marks2 = int(marks2)
marks3 = input("Enter marks of subject 3: ")
marks3 = int(marks3)
sum = (marks1 + marks2 + marks3)
percentage = (sum/300)*100
print(f"Percentage = {percentage}")

max = max(marks1, marks2, marks3)
print(f"Maximum marks are: {max}")
min = min(marks1, marks2, marks3)
