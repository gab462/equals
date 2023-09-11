auto
arg_parser :: input () -> str_view& {
  return this->inputs.append ({});
}

auto
arg_parser :: flag (char option, bool default_value) -> bool& {
  return this->flags.append ({
    default_value,
    option,
  }).data;
}

auto
arg_parser :: int_option (char option, int default_value) -> int& {
  return this->int_options.append ({
    default_value,
    option,
  }).data;
}

auto
arg_parser :: string_option (char option, str_view default_value) -> str_view& {
  return this->str_options.append ({
    default_value,
    option,
  }).data;
}

auto
arg_parser :: parse (int argc, char** argv) -> void {
  size_t input_n = 0;

  for (int i = 1; i < argc; ++i) {
    str_view arg = argv[i];

    if (arg.ptr[0] != '-') {
      assert (input_n < this->inputs.size ());

      this->inputs[input_n++] = arg;
    } else {
      // FIXME: Less ugly way to do this

      bool processed = false;

      for (auto& option: this->flags) {
        if (arg.ptr[1] == option.option) {
          option.data = !option.data;

          processed = true;
          break;
        }
      }

      if (processed)
        continue;

      for (auto& option: this->int_options) {
        if (arg.ptr[1] == option.option) {
          assert (i + 1 < argc);

          str_view value = argv[++i];
          option.data = value.to_int ();

          processed = true;
          break;
        }
      }

      if (processed)
        continue;

      for (auto& option: this->str_options) {
        if (arg.ptr[1] == option.option) {
          assert (i + 1 < argc);

          str_view value = argv[++i];
          option.data = value;

          processed = true;
          break;
        }
      }

      // Option in none of the lists, invalid
      assert (processed);
    }
  }

  assert (input_n == this->inputs.size ());
}
