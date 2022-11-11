#ifndef designerHeader
#define designerHeader
#endif

void LoadPreSavedFunctions (std::vector<Function>& functions) {
    Gate and1 = {{175, 50}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {3, 0}, false, true}}, false, 3};
    Gate and2 = {{175, 175}, AND, std::vector<ConnectorData> {{{0, 0}, {2, 1}, true, true}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {3, 1}, false, true}}, false, 3};
    Gate not1 = {{25, 150}, NOT, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {1, 0}, false, true}}, false, 2};
    Gate or1 = {{300, 100}, OR, std::vector<ConnectorData> {{{0, 0}, {0, 2}, true, true}, {{0, 0}, {1, 2}, true, true}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    functions.push_back ({"2:1 Multiplexer", {and1, and2, not1, or1}, {0, 0}, {300, 300}});
}