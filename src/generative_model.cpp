#include <generative_model.h>

using namespace cell_world;
using namespace std;

Model_public_state generative_model::predict_next_state(const vector<Model_public_state> &history) {
    Model_public_state predicted_state;
    auto &last_state = *(history.end());
    for (auto &ag : last_state.agents_state){
        Agent_public_state aps;
        aps.cell = ag.cell;
        auto coord = aps.cell.coordinates;
        auto predicted_move = predictors[ag.agent_index].predict_next_move(history);
        if (map.find(coord + predicted_move)){
            aps.cell = map[coord + predicted_move];
        }
    }
    return ;
}
