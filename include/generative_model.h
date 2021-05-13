#pragma once
#include <cell_world.h>

struct predictor {
    virtual cell_world::Move predict_next_move (const std::vector<cellworld::Model_public_state> &) = 0;
};

struct generative_model{
    cell_world::Model_public_state predict_next_state(const std::vector<cellworld::Model_public_state> &);
    cell_world::Map map;
    std::vector<predictor> predictors;
};