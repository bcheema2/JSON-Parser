//
// Created by Bibenpreet Cheema on 11/1/26.
//

#pragma once
#include "include/JsonNode.hpp"
#include <variant>
#include <vector>
#include <stdexcept>

class JsonContainer {
    std::vector<JsonType> elements;

public:
    JsonContainer() = default;
    ~JsonContainer() = default;

    // Non const for writing and resizing dynamically
    JsonType& operator[](size_t index) {
        if (index >= elements.size()) {
            elements.resize(index + 1);
        }
        return elements[index];
    }
    //Const operator[] for reading only
    const JsonType& operator[](size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("JsonNode::[]");
        }
        return elements[index];
    }

    //Helper methods
    [[nodiscard]] size_t size() const {return elements.size();}
    [[nodiscard]] bool empty() const {return elements.empty();}
    void push_back(JsonType&& value) {elements.push_back(std::move(value));}
};
