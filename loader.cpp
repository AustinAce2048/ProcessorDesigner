#ifndef designerHeader
#define designerHeader
#endif

void LoadPreSavedFunctions (std::vector<Function>& functions) {
    Gate and1 = {{175, 50}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {3, 0}, false, true}}, false, 3};
    Gate and2 = {{175, 175}, AND, std::vector<ConnectorData> {{{0, 0}, {2, 1}, true, true}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {3, 1}, false, true}}, false, 3};
    Gate not1 = {{25, 150}, NOT, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {1, 0}, false, true}}, false, 2};
    Gate or1 = {{300, 100}, OR, std::vector<ConnectorData> {{{0, 0}, {0, 2}, true, true}, {{0, 0}, {1, 2}, true, true}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    functions.push_back ({"2:1 Multiplexer", {and1, and2, not1, or1}, {0, 0}, {300, 300}});

    Gate and3 = {{0, 25}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    Gate xor1 = {{0, 125}, XOR, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    functions.push_back ({"Half Adder", {and3, xor1}, {0, 0}, {50, 150}});

    Gate xor2 = {{0, 225}, XOR, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {1, 1}, false, true}}, false, 3};
    Gate xor3 = {{175, 225}, XOR, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {0, 2}, true, true}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    Gate and4 = {{125, 125}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {0, 2}, true, true}, {{0, 0}, {4, 1}, false, true}}, false, 3};
    Gate and5 = {{125, 25}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, true}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {4, 0}, false, true}}, false, 3};
    Gate or2 = {{250, 50}, OR, std::vector<ConnectorData> {{{0, 0}, {3, 2}, true, true}, {{0, 0}, {2, 2}, true, true}, {{0, 0}, {-1, 0}, false, false}}, false, 3};
    functions.push_back ({"Full Adder", {xor2, xor3, and4, and5, or2}, {0, 0}, {300, 300}});
}