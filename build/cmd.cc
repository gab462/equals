cmd :: cmd (): program {nullptr}, args {} {}

template <typename ...A>
cmd :: cmd (const char* c, A... a): program {c}, args {c, a..., nullptr} {}

auto
cmd :: execute () -> void {
  // FIXME: Any way other than const_cast?
  execvp (program, const_cast<char* const*>(args.data));
}
