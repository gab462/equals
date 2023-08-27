template <typename T>
struct argument {
  T data;
  char option;
};

struct argument_parser {
  list<string_view> inputs;
  list<argument<bool>> flags;
  list<argument<int>> int_options;
  list<argument<string_view>> string_options;

  auto input () -> string_view&;
  auto flag (char option, bool default_value = false) -> bool&;
  auto int_option (char option, int default_value = 0) -> int&;
  auto string_option (char option, string_view default_value = "") -> string_view&;
  auto parse (int argc, char** argv) -> void;
};
