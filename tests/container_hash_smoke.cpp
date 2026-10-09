// SPDX-License-Identifier: 0BSD
#include <tuple>
#include <utility>
#include "dynarmic/common/container/unordered_map.h"
#include "dynarmic/common/container/unordered_set.h"
#include "dynarmic/ir/location_descriptor.h"

int main() {
    using Dynarmic::IR::LocationDescriptor;
    Common::unordered_map<LocationDescriptor, int> descriptors;
    descriptors.emplace(LocationDescriptor{0x1234}, 42);
    if (descriptors.at(LocationDescriptor{0x1234}) != 42) return 1;

    Common::unordered_map<std::tuple<bool, size_t, int, int>, int> tuples;
    auto key = std::tuple{true, size_t{4}, -1, 2};
    tuples.emplace(key, 7);
    if (tuples.at(key) != 7) return 2;

    Common::unordered_set<std::pair<u64, u64>> pairs;
    pairs.emplace(1, 2);
    if (!pairs.contains(std::pair<u64, u64>{1, 2})) return 3;

    // Explicit caller-provided hashers must retain priority.
    Common::unordered_set<LocationDescriptor, std::hash<LocationDescriptor>> custom;
    custom.emplace(LocationDescriptor{0x5678});
    if (!custom.contains(LocationDescriptor{0x5678})) return 4;
}
