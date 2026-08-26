function maxPower(s) {
    if (!s) return 0;
    let maxStreak = 1, currentStreak = 1;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            currentStreak++;
            maxStreak = Math.max(maxStreak, currentStreak);
        } else {
            currentStreak = 1;
        }
    }
    return maxStreak;
}
