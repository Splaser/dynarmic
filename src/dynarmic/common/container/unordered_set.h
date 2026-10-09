// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "dynarmic/common/container/default_hash.h"
#include <boost/unordered/unordered_flat_set.hpp>

namespace Common {

template <class Key, class Hash = Dynarmic::detail::DefaultHash<Key>, class Pred = std::equal_to<Key>,
          class Allocator = std::allocator<Key>>
using unordered_set = boost::unordered::unordered_flat_set<Key, Hash, Pred, Allocator>;

}
