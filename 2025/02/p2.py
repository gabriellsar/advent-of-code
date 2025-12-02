from typing import List
import re


def split_file(file_path, delimiter=",") -> List[str]:
    with open(file_path, 'r') as file:
        content = file.read()
    return content.split(delimiter)

def invalids(first: int, last: int) -> int:
    invalid_sum = 0 
    regex = r"^(\d+)\1+$"

    for num in range(first, last + 1):
        match = re.fullmatch(regex, str(num))
        if match != None:
            invalid_sum+=num

    return invalid_sum


def main():
    file_path = 'input.txt'
    parts = split_file(file_path)
    invalid_sum = 0
    for part in parts:
        parts = part.strip().split("-")
        first, last = list(map(int, parts))
        invalid_sum += invalids(first, last)

    print(f"Sum of invalid numbers: {invalid_sum}")

if __name__ == "__main__":
    main()