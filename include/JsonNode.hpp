//
// Created by Bibenpreet Cheema on 11/2/26.
//

#pragma once
#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stdexcept>

struct JsonType;

using JsonArray = std::vector<std::unique_ptr<JsonType>>;
using JsonObject = std::unordered_map<std::string, std::unique_ptr<JsonType>>;

struct JsonType : std::variant<
    std::monostate,
    int,
    double,
    bool,
    std::string,
    JsonArray,
    JsonObject
> {
    using variant::variant;
};

struct JsonNode {
    std::string key;
    JsonType value;
};



