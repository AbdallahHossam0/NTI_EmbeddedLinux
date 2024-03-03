import os
from datetime import datetime

# Create a directory
directory_path = "/home/abdallah/script_excercise"
os.makedirs(directory_path, exist_ok=True)

# Create and write to files
for file_num in range(1, 6):
    file_path = f"{directory_path}/file{file_num}"
    with open(file_path, "w") as file:
        file.write(str(datetime.now()))

# Read and print the contents of the files
for file_num in range(1, 6):
    file_path = f"{directory_path}/file{file_num}"
    print(f"Content of {file_path}:")
    with open(file_path, "r") as file:
        print(file.read())

