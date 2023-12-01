def total_beauty(arr):
    n = len(arr)
    total_beauty = 0

    # Iterate over each bit position (0 to 30)
    for i in range(31):
        count_set_bits = 0

        for num in arr:
            # Check if the bit at the current position is set
            if num & (1 << i):
                count_set_bits += 1

        total_beauty += count_set_bits * (n - count_set_bits) * (1 << i)

    return total_beauty

# Read input
n = int(input())
beauty_values = [int(input()) for _ in range(n)]

# Calculate and print the result
result = total_beauty(beauty_values)
print(result)
