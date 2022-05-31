#include "risc0/zkvm/circuit/make_circuit.h"
#include <cstddef>
#include <cstring>
#include <exception>
#include <string>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

namespace {
namespace repr {
struct PtrLen final {
  void *ptr;
  ::std::size_t len;
};
} // namespace repr
} // namespace
} // namespace cxxbridge1

namespace behavior {
class missing {};
missing trycatch(...);

template <typename Try, typename Fail>
static typename ::std::enable_if<
    ::std::is_same<decltype(trycatch(::std::declval<Try>(), ::std::declval<Fail>())),
                 missing>::value>::type
trycatch(Try &&func, Fail &&fail) noexcept try {
  func();
} catch (const ::std::exception &e) {
  fail(e.what());
}
} // namespace behavior
} // namespace rust

extern "C" {
const char *cxxbridge1$exception(const char *, ::std::size_t);
} // extern "C"

namespace risc0 {
namespace circuit {
extern "C" {
::rust::repr::PtrLen risc0$circuit$cxxbridge1$make_circuit(const ::std::string &path) noexcept {
  void (*make_circuit$)(const ::std::string &) = ::risc0::circuit::make_circuit;
  ::rust::repr::PtrLen throw$;
  ::rust::behavior::trycatch(
      [&] {
        make_circuit$(path);
        throw$.ptr = nullptr;
      },
      [&](const char *catch$) noexcept {
        throw$.len = ::std::strlen(catch$);
        throw$.ptr = const_cast<char *>(::cxxbridge1$exception(catch$, throw$.len));
      });
  return throw$;
}
} // extern "C"
} // namespace circuit
} // namespace risc0
