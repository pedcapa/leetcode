#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution final
{
public:
    std::vector<std::string> uncommonFromSentences(const std::string s1, const std::string s2) const noexcept
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        
        std::unordered_map<std::string, size_t> counter;
        std::stringstream ss1(s1);
        std::string word;
        while (ss1 >> word)
            ++counter[word];
        std::stringstream ss2(s2);
        while (ss2 >> word)
            ++counter[word];
        std::vector<std::string> uncommons;
        uncommons.reserve(counter.size() + 10);
        for (const auto& [word, count] : counter)
            if (count == 1)
                uncommons.push_back(word);
        return uncommons;
    }
};
