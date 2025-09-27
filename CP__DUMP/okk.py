def count_good_special_subsets(n, s):
    MOD = 1000000007
    
    # Helper function to check if a sequence of characters forms a palindrome
    def is_palindrome(chars):
        return chars == chars[::-1]
    
    # Function to generate all possible subsequences with their permutations
    def generate_permutations(curr_indices, used, result):
        # Add current permutation if it forms a palindrome
        if curr_indices:
            chars = [s[i-1] for i in curr_indices]  # Convert 1-based to 0-based indexing
            if is_palindrome(chars):
                result.add(tuple(curr_indices))
        
        # Try adding each unused index
        for i in range(1, n + 1):
            if not used[i]:
                used[i] = True
                curr_indices.append(i)
                generate_permutations(curr_indices, used, result)
                curr_indices.pop()
                used[i] = False
    
    # Set to store all valid permutations
    good_permutations = set()
    
    # Generate all permutations
    used = [False] * (n + 1)
    generate_permutations([], used, good_permutations)
    
    # Count total good permutations
    return len(good_permutations) % MOD

# Read input and process
def main():
    n = int(input())
    s = input().strip()
    result = count_good_special_subsets(n, s)
    print(result)

if __name__ == "__main__":
    main()