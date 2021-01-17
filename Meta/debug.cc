template<class T> struct beg_end { T b, e; };
template<class T> beg_end<T> range(T i, T j) { return beg_end<T>{i, j}; }
template<class T> auto sfinae(T* p) -> decltype(std::cerr << *p, nullptr);
template<class T> char sfinae(...);
struct debug {
#ifdef LOCAL
    ~debug() { std::cerr << '\n'; }
    template<class T>
    typename std::enable_if<sizeof sfinae<T>(nullptr) != 1, debug&>::type operator<<(T x) {
        std::cerr << std::boolalpha << x;
        return *this;
    }
    template<class T>
    typename std::enable_if<sizeof sfinae<T>(nullptr) == 1, debug&>::type operator<<(T x) {
        return *this << range(begin(x), end(x));
    }
    template<class T, class U>
    debug& operator<<(std::pair <T, U> p) {
        return *this << "(" << p.first << ", " << p.second << ")";
    }
    template<class T>
    debug& operator<<(beg_end<T> container) {
        *this << "[";
        for (auto it = container.b; it != container.e; ++it)
            *this << ", " + 2 * (it == container.b) << *it;
        return *this << "]";
    }
#else
    template<class T> debug& operator<<(const T&) { return *this; }
#endif
};
#define im(...) "{" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "} "
