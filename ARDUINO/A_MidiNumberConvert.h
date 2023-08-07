// MIDI NOTES --------------------------------------------------------
// CHANNEL ON
int ch1ON = 0x90; int ch2ON = 0x91; int ch3ON = 0x92; int ch4ON = 0x93; int ch5ON = 0x94;
int ch6ON = 0x95; int ch7ON = 0x96; int ch8ON = 0x97; int ch9ON = 0x98; int ch10ON = 0x99;
int ch11ON = 0x9A; int ch12ON = 0x9B; int ch13ON = 0x9C; int ch14ON = 0x9D; int ch15ON = 0x9E; int ch16ON = 0x9F;

// CHANNEL OFF
int ch1OFF = 0x80; int ch2OFF = 0x81; int ch3OFF = 0x82; int ch4OFF = 0x83; int ch5OFF = 0x84;
int ch6OFF = 0x85; int ch7OFF = 0x86; int ch8OFF = 0x87; int ch9OFF = 0x88; int ch10OFF = 0x89;
int ch11OFF = 0x8A; int ch12OFF = 0x8B; int ch13OFF = 0x8C; int ch14OFF = 0x8D; int ch15OFF = 0x8E; int ch16OFF = 0x8F;

// CONTROL CHANGE
int con1 = 0xB0; int con2 = 0xB1; int con3 = 0xB2; int con4 = 0xB3; int con5 = 0xB4;
int con6 = 0xB5; int con7 = 0xB6; int con8 = 0xB7; int con9 = 0xB8; int con10 = 0xB9;
int con11 = 0xBA; int con12 = 0xBB; int con13 = 0xBC; int con14 = 0xBD; int con15 = 0xBE; int con16 = 0xBF;

// PROGRAM CHANGE
int prog1 = 0xC0; int prog2 = 0xC1; int prog3 = 0xC2; int prog4 = 0xC3; int prog5 = 0xC4;
int prog6 = 0xC5; int prog7 = 0xC6; int prog8 = 0xC7; int prog9 = 0xC8; int prog10 = 0xC9;
int prog11 = 0xCA; int prog12 = 0xCB; int prog13 = 0xCC; int prog14 = 0xCD; int prog15 = 0xCE; int prog16 = 0xCF;

// MIDI NUMBER
int num0 = 0x00; int num1 = 0x01; int num2 = 0x02; int num3 = 0x03; int num4 = 0x04; int num5 = 0x05; int num6 = 0x06; int num7 = 0x07; int num8 = 0x08; int num9 = 0x09;
int num10 = 0x0A; int num11 = 0x0B; int num12 = 0x0C; int num13 = 0x0D; int num14 = 0x0E; int num15 = 0x0F; int num16 = 0x10; int num17 = 0x11; int num18 = 0x12; int num19 = 0x13;
int num20 = 0x14; int num21 = 0x15; int num22 = 0x16; int num23 = 0x17; int num24 = 0x18; int num25 = 0x19; int num26 = 0x1A; int num27 = 0x1B; int num28 = 0x1C; int num29 = 0x1D;
int num30 = 0x1E; int num31 = 0x1F; int num32 = 0x20; int num33 = 0x21; int num34 = 0x22; int num35 = 0x23; int num36 = 0x24; int num37 = 0x25; int num38 = 0x26; int num39 = 0x27;
int num40 = 0x28; int num41 = 0x29; int num42 = 0x2A; int num43 = 0x2B; int num44 = 0x2C; int num45 = 0x2D; int num46 = 0x2E; int num47 = 0x2F; int num48 = 0x30; int num49 = 0x31;
int num50 = 0x32; int num51 = 0x33; int num52 = 0x34; int num53 = 0x35; int num54 = 0x36; int num55 = 0x37; int num56 = 0x38; int num57 = 0x39; int num58 = 0x3A; int num59 = 0x3B;
int num60 = 0x3C; int num61 = 0x3D; int num62 = 0x3E; int num63 = 0x3F; int num64 = 0x40; int num65 = 0x41; int num66 = 0x42; int num67 = 0x43; int num68 = 0x44; int num69 = 0x45;
int num70 = 0x46; int num71 = 0x47; int num72 = 0x48; int num73 = 0x49; int num74 = 0x4A; int num75 = 0x4B; int num76 = 0x4C; int num77 = 0x4D; int num78 = 0x4E; int num79 = 0x4F;
int num80 = 0x50; int num81 = 0x51; int num82 = 0x52; int num83 = 0x53; int num84 = 0x54; int num85 = 0x55; int num86 = 0x56; int num87 = 0x57; int num88 = 0x58; int num89 = 0x59;
int num90 = 0x5A; int num91 = 0x5B; int num92 = 0x5C; int num93 = 0x5D; int num94 = 0x5E; int num95 = 0x5F; int num96 = 0x60; int num97 = 0x61; int num98 = 0x62; int num99 = 0x63;
int num100 = 0x64; int num101 = 0x65; int num102 = 0x66; int num103 = 0x67; int num104 = 0x68; int num105 = 0x69; int num106 = 0x6A; int num107 = 0x6B; int num108 = 0x6C; int num109 = 0x6D;
int num110 = 0x6E; int num111 = 0x6F; int num112 = 0x70; int num113 = 0x71; int num114 = 0x72; int num115 = 0x73; int num116 = 0x74; int num117 = 0x75; int num118 = 0x76; int num119 = 0x77;
int num120 = 0x78; int num121 = 0x79; int num122 = 0x7A; int num123 = 0x7B; int num124 = 0x7C; int num125 = 0x7D; int num126 = 0x7E; int num127 = 0x7F;

// SHOW CONTROL --------------------------------------------------------
// DEVICE ID
int dev0 = 0x00; int dev1 = 0x01; int dev2 = 0x02; int dev3 = 0x03; int dev4 = 0x04; int dev5 = 0x05; int dev6 = 0x06; int dev7 = 0x07; int dev8 = 0x08; int dev9 = 0x09;
int dev10 = 0x0A; int dev11 = 0x0B; int dev12 = 0x0C; int dev13 = 0x0D; int dev14 = 0x0E; int dev15 = 0x0F; int dev16 = 0x10; int dev17 = 0x11; int dev18 = 0x12; int dev19 = 0x13;
int dev20 = 0x14; int dev21 = 0x15; int dev22 = 0x16; int dev23 = 0x17; int dev24 = 0x18; int dev25 = 0x19; int dev26 = 0x1A; int dev27 = 0x1B; int dev28 = 0x1C; int dev29 = 0x1D;
int dev30 = 0x1E; int dev31 = 0x1F; int dev32 = 0x20; int dev33 = 0x21; int dev34 = 0x22; int dev35 = 0x23; int dev36 = 0x24; int dev37 = 0x25; int dev38 = 0x26; int dev39 = 0x27;
int dev40 = 0x28; int dev41 = 0x29; int dev42 = 0x2A; int dev43 = 0x2B; int dev44 = 0x2C; int dev45 = 0x2D; int dev46 = 0x2E; int dev47 = 0x2F; int dev48 = 0x30; int dev49 = 0x31;
int dev50 = 0x32; int dev51 = 0x33; int dev52 = 0x34; int dev53 = 0x35; int dev54 = 0x36; int dev55 = 0x37; int dev56 = 0x38; int dev57 = 0x39; int dev58 = 0x3A; int dev59 = 0x3B;
int dev60 = 0x3C; int dev61 = 0x3D; int dev62 = 0x3E; int dev63 = 0x3F; int dev64 = 0x40; int dev65 = 0x41; int dev66 = 0x42; int dev67 = 0x43; int dev68 = 0x44; int dev69 = 0x45;
int dev70 = 0x46; int dev71 = 0x47; int dev72 = 0x48; int dev73 = 0x49; int dev74 = 0x4A; int dev75 = 0x4B; int dev76 = 0x4C; int dev77 = 0x4D; int dev78 = 0x4E; int dev79 = 0x4F;
int dev80 = 0x50; int dev81 = 0x51; int dev82 = 0x52; int dev83 = 0x53; int dev84 = 0x54; int dev85 = 0x55; int dev86 = 0x56; int dev87 = 0x57; int dev88 = 0x58; int dev89 = 0x59;
int dev90 = 0x5A; int dev91 = 0x5B; int dev92 = 0x5C; int dev93 = 0x5D; int dev94 = 0x5E; int dev95 = 0x5F; int dev96 = 0x60; int dev97 = 0x61; int dev98 = 0x62; int dev99 = 0x63;
int dev100 = 0x64; int dev101 = 0x65; int dev102 = 0x66; int dev103 = 0x67; int dev104 = 0x68; int dev105 = 0x69; int dev106 = 0x6A; int dev107 = 0x6B; int dev108 = 0x6C; int dev109 = 0x6D;
int dev110 = 0x6E; int dev111 = 0x6F; int dev112 = 0x70; int dev113 = 0x71; int dev114 = 0x72; int dev115 = 0x73; int dev116 = 0x74; int dev117 = 0x75; int dev118 = 0x76; int dev119 = 0x77;
int dev120 = 0x78; int dev121 = 0x79; int dev122 = 0x7A; int dev123 = 0x7B; int dev124 = 0x7C; int dev125 = 0x7D; int dev126 = 0x7E; int dev127 = 0x7F;
int devALL = 0x7F;

// FORMAT --------------------
int form0 = 0x00; //RESERVED
int form1 = 0x01; //LIGHTING -----
int form2 = 0x02; //MOVING LIGHTS
int form3 = 0x03; //COLOR CHANGERS
int form4 = 0x04; //STROBES
int form5 = 0x05; //LASERS
int form6 = 0x06; //CHASERS

int form10 = 0x10; //SOUND -----
int form11 = 0x11; //MUSIC
int form12 = 0x12; //CD PLAYERS
int form13 = 0x13; //EPROM PLAYBACK
int form14 = 0x14; //AUDIO TAPE MACHINES
int form15 = 0x15; //INTERCOMS
int form16 = 0x16; //AMPLIFIERS
int form17 = 0x17; //AUDIO EFFECTS DEVICES
int form18 = 0x18; //EQUALISERS

int form20 = 0x20; //MACHINERY -----
int form21 = 0x21; //RIGGING
int form22 = 0x22; //FLYS
int form23 = 0x23; //LIFTS
int form24 = 0x24; //TURNTABLES
int form25 = 0x25; //TRUSSES
int form26 = 0x26; //ROBOTS
int form27 = 0x27; //ANIMATION
int form28 = 0x28; //FLOATS
int form29 = 0x29; //BREAKAWAYS
int form2A = 0x2A; //BARGES


// COMAND --------------------
int com0 = 0x00; //RESERVED
int GO = 0x01; //GO
int STOP = 0x02; //STOP
int RESUME = 0x03; //RESUME
int TIMEDGO = 0x04; //TIMED GO
int LOAD = 0x05; //LOAD
int SET = 0x06; //SET
int FIRE = 0x07; //FIRE
int ALLOFF = 0x08; //ALL OFF
int RESTORE = 0x09; //RESTORE
int RESET = 0xA; //RESET
int GOOFF = 0x0B; //GO OFF

// CUE NUMBER --------------------
int cue0 = 0x30;
int cue1 = 0x31;
