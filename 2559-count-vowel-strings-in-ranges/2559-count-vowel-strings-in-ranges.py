class Solution:
    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        prefix = [0] * (len(words) + 1)

        for i, word in enumerate(words):
            is_valid = word[0] in vowels and word[-1] in vowels
            prefix[i + 1] = prefix[i] + (1 if is_valid else 0)

        return [prefix[r + 1] - prefix[l] for l, r in queries]