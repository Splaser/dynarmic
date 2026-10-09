// SPDX-License-Identifier: 0BSD
#pragma once

#include <functional>
#include <tuple>
#include <utility>
#include <boost/container_hash/hash.hpp>

namespace Dynarmic::detail {

// Preserve existing std::hash specializations for Dynarmic descriptor types.
template <typename Key>
struct DefaultHash : std::hash<Key> {};

// Standard tuples and pairs have no std::hash specialization.
template <typename... Ts>
struct DefaultHash<std::tuple<Ts...>> : boost::hash<std::tuple<Ts...>> {};

template <typename First, typename Second>
struct DefaultHash<std::pair<First, Second>> : boost::hash<std::pair<First, Second>> {};

} // namespace Dynarmic::detail
