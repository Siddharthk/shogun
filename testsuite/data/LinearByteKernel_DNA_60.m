name = 'LinearByte'
alphabet = 'DNA'
km_test = [0.840344751, 0.784278178, 0.880228843, 0.490541645, 0.776105208, 0.747336355, 0.936785794, 0.749624786, 0.783297422, 0.976506427, 0.624578349, 0.907036184, 0.417311836, 0.887747975, 1.05578423, 0.853094584, 0.99726577;0.835277509, 0.753711271, 1.04548629, 0.58927112, 0.880065384, 0.76744186, 1.03306338, 0.772836021, 0.702221562, 1.19309013, 0.680644922, 0.960650866, 0.4323501, 0.853584962, 1.08063006, 0.930901256, 1.02031354;0.618693811, 0.52437774, 0.645664611, 0.427773237, 0.60529014, 0.468965005, 0.634549372, 0.487762835, 0.521272011, 0.652693365, 0.335745598, 0.565732967, 0.27559254, 0.6541645, 0.648443421, 0.582242366, 0.665279738;0.545300542, 0.674433465, 0.866498254, 0.593521064, 0.729355821, 0.519310499, 0.785422394, 0.296351883, 0.562790698, 0.687019838, 0.536146816, 0.569165614, 0.303871016, 0.626049484, 0.78656661, 0.717586745, 0.729355821;1.24016643, 0.968006538, 1.22006093, 0.967189241, 1.12100453, 1.07638012, 1.10923546, 0.859959878, 0.979612155, 1.12460064, 0.829556431, 1.1996285, 0.635857047, 1.10400476, 1.34870347, 1.04810164, 1.3030983;0.968006538, 0.922564827, 1.04515937, 0.746682517, 0.885132625, 0.785422394, 1.04875548, 0.738019169, 0.909978453, 0.850806152, 0.742432573, 1.02750576, 0.395081358, 0.987621666, 1.11691805, 1.00805409, 1.1239468;0.731153875, 0.801604874, 0.875161602, 0.506724125, 0.711048369, 0.591396092, 0.834950591, 0.470599599, 0.544646705, 0.817787354, 0.525031577, 0.800624118, 0.35127424, 0.802912549, 0.876469277, 0.832825619, 0.811412438;0.815335463, 0.712682963, 0.916516829, 0.67574114, 0.879738465, 0.7837878, 0.863392525, 0.718240583, 0.675087302, 0.876632736, 0.707452262, 0.933680065, 0.539416004, 0.671491195, 1.10187978, 0.733115387, 1.06068802;0.858815662, 0.796864552, 1.0474478, 0.728865443, 0.892815217, 0.766788023, 0.824162271, 0.673125789, 0.591069173, 0.872219333, 0.685058325, 1.0603611, 0.625232187, 0.692413998, 1.1178988, 0.732951928, 1.00936177;0.601694034, 0.597771008, 0.684077569, 0.731153875, 0.645664611, 0.568838695, 0.656943309, 0.362389479, 0.511627907, 0.611338138, 0.561809941, 0.579463556, 0.326591872, 0.547588974, 0.73524036, 0.604472843, 0.797518389;0.961795081, 0.929430121, 0.998246526, 0.776432127, 0.813700869, 0.804710603, 1.04859202, 0.619838027, 0.920930233, 0.930574337, 0.689798648, 1.01328479, 0.439051936, 0.985823612, 1.08978379, 1.02064046, 1.08063006]
km_train = [1.06052456, 0.913901479, 0.61362657, 0.379062337, 0.967352701, 0.812229735, 0.644193476, 0.795556876, 0.654654878, 0.338197489, 0.847700424;0.913901479, 1.15484063, 0.572107883, 0.559194591, 1.02276544, 0.817623895, 0.796047255, 0.840344751, 0.912430344, 0.464551601, 0.866825173;0.61362657, 0.572107883, 0.47305149, 0.274448325, 0.681298759, 0.589924957, 0.435782748, 0.439705773, 0.409465785, 0.251564009, 0.58649231;0.379062337, 0.559194591, 0.274448325, 0.762864997, 0.742596032, 0.659885578, 0.568184858, 0.585838472, 0.691596701, 0.611174679, 0.625232187;0.967352701, 1.02276544, 0.681298759, 0.742596032, 1.43010625, 1.15353295, 0.840017832, 1.05251505, 1.1074374, 0.781662828, 1.13113901;0.812229735, 0.817623895, 0.589924957, 0.659885578, 1.15353295, 1.26010848, 0.746519058, 0.784114719, 0.85407534, 0.646645367, 1.10596627;0.644193476, 0.796047255, 0.435782748, 0.568184858, 0.840017832, 0.746519058, 0.729192362, 0.616568839, 0.763191916, 0.445426852, 0.770057211;0.795556876, 0.840344751, 0.439705773, 0.585838472, 1.05251505, 0.784114719, 0.616568839, 0.990073557, 0.991217772, 0.628010996, 0.806672115;0.654654878, 0.912430344, 0.409465785, 0.691596701, 1.1074374, 0.85407534, 0.763191916, 0.991217772, 1.26582956, 0.695683186, 0.907690022;0.338197489, 0.464551601, 0.251564009, 0.611174679, 0.781662828, 0.646645367, 0.445426852, 0.628010996, 0.695683186, 0.711702207, 0.654981797;0.847700424, 0.866825173, 0.58649231, 0.625232187, 1.13113901, 1.10596627, 0.770057211, 0.806672115, 0.907690022, 0.654981797, 1.16170592]
data_train = ['38', '28', '14', '7', '20', '38', '18', '22', '10', '10', '23';'35', '39', '23', '2', '21', '1', '23', '29', '37', '1', '20';'32', '11', '21', '24', '26', '41', '27', '15', '14', '2', '36';'6', '20', '8', '38', '17', '3', '24', '13', '8', '25', '1';'19', '27', '6', '7', '34', '13', '16', '35', '39', '3', '1';'5', '41', '3', '28', '17', '25', '33', '9', '35', '13', '30';'14', '7', '13', '22', '39', '20', '15', '17', '23', '25', '24';'40', '28', '14', '0', '24', '6', '8', '23', '0', '7', '23';'10', '16', '7', '34', '34', '32', '4', '41', '38', '40', '27';'6', '8', '7', '11', '33', '32', '22', '23', '36', '34', '39';'21', '26', '34', '0', '34', '36', '13', '2', '0', '4', '25']
seqlen = 60
data_test = ['13', '38', '26', '8', '14', '14', '25', '41', '12', '31', '38', '31', '3', '29', '36', '22', '38';'14', '28', '35', '12', '31', '6', '21', '27', '1', '41', '5', '27', '27', '19', '29', '10', '27';'24', '38', '32', '0', '26', '12', '40', '2', '38', '5', '7', '26', '8', '36', '32', '41', '23';'14', '31', '31', '23', '40', '11', '38', '1', '2', '36', '16', '1', '1', '27', '22', '36', '31';'32', '0', '18', '1', '25', '31', '5', '31', '3', '10', '16', '37', '23', '4', '33', '5', '21';'10', '15', '32', '8', '5', '15', '28', '2', '19', '35', '18', '25', '2', '18', '19', '31', '6';'40', '32', '39', '38', '17', '39', '0', '10', '27', '24', '22', '30', '29', '41', '34', '6', '15';'25', '1', '0', '11', '4', '36', '31', '8', '40', '34', '18', '15', '2', '19', '23', '32', '23';'10', '7', '35', '37', '39', '19', '34', '24', '34', '24', '28', '17', '17', '1', '34', '15', '40';'35', '32', '3', '32', '13', '20', '19', '7', '6', '2', '16', '32', '11', '21', '21', '29', '37';'37', '7', '26', '26', '33', '20', '29', '32', '27', '32', '4', '18', '3', '34', '16', '27', '29']