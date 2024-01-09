#include <print>

std::tuple<int, int, int> findDigitNumbers(const std::string &text, size_t pos)
{
    for (int i = 0; i + pos < text.size(); ++i)
    {
        if (text[pos + i] < '0' || text[pos + i] > '9')
            continue;

        int start = pos + i;
        int num = text[pos + i] - '0';

        for (i = i + 1; i + pos < text.size(); ++i)
        {
            if (text[pos + i] >= '0' && text[pos + i] <= '9')
            {
                num = num * 10 + text[pos + i] - '0';
                continue;
            }

            return std::make_tuple(start, (int)pos + i, num);
        }
    }

    return std::make_tuple(-1, -1, 0);
}

int main()
{
    std::println("hello world in c++23.");
    std::string input{"..248..4.$.244#...344..24.."};

    size_t pos{};

    while (true)
    {
        auto [start, end, num] = findDigitNumbers(input, pos);
        if (start < 0)
            break;

        std::print("[{},{},{}] ", start, end, num);
        pos = end + 1;
    }

    std::println("finished.");
    return 0;
}
