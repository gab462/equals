build_config :: build_config (const char* file): entry {file} {
  this->flags.append ("-Wall");
  this->flags.append ("-Wextra");
  this->flags.append ("-Wshadow");
  this->flags.append ("-pedantic");
}

auto
build_config :: include (str_view directory) -> void {
  includes.append (str {"-I"}.append (directory).with_null ());
}

auto
build_config :: link (str_view library) -> void {
  libraries.append (str {"-l"}.append (library).with_null ());
}

auto
build_config :: define (str_view macro) -> void {
  macros.append (str {"-D"}.append (macro).with_null ());
}

auto
build_config :: run () -> void {
  vec<const char*> v;

  v.resize (4 // compiler, standard, entry and nullptr
            + this->flags.size ()
            + this->includes.size ()
            + this->libraries.size ()
            + this->macros.size ());

  size_t i = 0;

  v[i++] = this->compiler;

  str std =
    str {"-std=c++"}
    .append (this->standard)
    .with_null ();

  v[i++] = std.data;

  for (auto const& f: this->flags)
    v[i++] = f;

  for (auto const& d: this->includes)
    v[i++] = d.data;

  v[i++] = this->entry;

  for (auto const& l: this->libraries)
    v[i++] = l.data;

  for (auto const& m: this->macros)
    v[i++] = m.data;

  v[i] = nullptr;

  cmd c;
  c.program = this->compiler;
  c.args.resize (v.size ());
  c.args = v;

  c.execute ();
}
