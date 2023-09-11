struct str;

struct str_view {
  const char* ptr;
  size_t length;

  str_view ();
  str_view (const char* s);
  str_view (str& s);
  str_view (str_view s, size_t n);
  str_view (const char* s, size_t n);

  auto operator== (str_view other) -> bool;

  auto size () -> size_t;
  auto contains (str_view other) -> bool;
  auto split (char sep) -> lst<str_view>;
  auto trim () -> str_view;
  auto append (str_view other) -> str;
  auto with_null () -> str;

  auto to_int () -> int;
  // static auto from_int (int s) -> str;
  // static auto join (vector<str_view> strs, optional<char> sep = {}) -> str;
};

struct str: str_view {
  char *data;

  str (const char* s);
  str (str& other);
  str (str_view other);
  explicit str (size_t n);
  ~ str ();

  auto operator= (str const& other) -> void;

  auto copy (str_view src, size_t offset = 0) -> void;
};
