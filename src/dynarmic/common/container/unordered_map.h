// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "dynarmic/common/container/default_hash.h"
#include <boost/unordered/unordered_flat_map.hpp>

namespace Common {

template <class Key, class T, class Hash = Dynarmic::detail::DefaultHash<Key>, class Pred = std::equal_to<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
using unordered_map = boost::unordered::unordered_flat_map<Key, T, Hash, Pred, Allocator>;

}
