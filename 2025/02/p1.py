from typing import List


def split_file(file_path, delimiter=",") -> List[str]:
    with open(file_path, 'r') as file:
        content = file.read()
    return content.split(delimiter)

def invalids(first: str, last: str) -> int:
    invalid_sum = 0
    for num in range(int(first), int(last) + 1):
        length = len(str(num))
        if length % 2 == 0:
            f_half = str(num)[:length // 2]
            s_half = str(num)[length // 2:]

            if f_half == s_half:
                invalid_sum += num
    return invalid_sum


def main():
    file_path = 'input.txt'
    parts = split_file(file_path)
    invalid_sum = 0
    for part in parts:
        first, last = part.strip().split("-")
        
        invalid_sum += invalids(first, last)

    print(f"Sum of invalid numbers: {invalid_sum}")

if __name__ == "__main__":
    main()