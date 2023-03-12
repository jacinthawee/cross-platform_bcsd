
undefined4 tls1_ec_nid2curve_id(int param_1)

{
  if (param_1 == 0x2d2) {
    return 2;
  }
  if (param_1 < 0x2d3) {
    if (param_1 == 0x2c7) {
      return 0x12;
    }
    if (param_1 < 0x2c8) {
      if (param_1 == 0x2c4) {
        return 0xf;
      }
      if (param_1 < 0x2c5) {
        if (param_1 == 0x199) {
          return 0x13;
        }
        if (param_1 == 0x19f) {
          return 0x17;
        }
      }
      else {
        if (param_1 == 0x2c5) {
          return 0x10;
        }
        if (param_1 == 0x2c6) {
          return 0x11;
        }
      }
    }
    else {
      if (param_1 == 0x2ca) {
        return 0x16;
      }
      if (param_1 < 0x2cb) {
        if (param_1 == 0x2c8) {
          return 0x14;
        }
        if (param_1 == 0x2c9) {
          return 0x15;
        }
      }
      else {
        if (param_1 == 0x2cc) {
          return 0x19;
        }
        if (param_1 < 0x2cc) {
          return 0x18;
        }
        if (param_1 == 0x2d1) {
          return 1;
        }
      }
    }
  }
  else {
    if (param_1 == 0x2d8) {
      return 8;
    }
    if (param_1 < 0x2d9) {
      if (param_1 == 0x2d5) {
        return 5;
      }
      if (param_1 < 0x2d6) {
        if (param_1 == 0x2d3) {
          return 3;
        }
        if (param_1 == 0x2d4) {
          return 4;
        }
      }
      else {
        if (param_1 == 0x2d6) {
          return 6;
        }
        if (param_1 == 0x2d7) {
          return 7;
        }
      }
    }
    else {
      if (param_1 == 0x2db) {
        return 0xb;
      }
      if (param_1 < 0x2dc) {
        if (param_1 == 0x2d9) {
          return 9;
        }
        if (param_1 == 0x2da) {
          return 10;
        }
      }
      else {
        if (param_1 == 0x2dd) {
          return 0xd;
        }
        if (param_1 < 0x2dd) {
          return 0xc;
        }
        if (param_1 == 0x2de) {
          return 0xe;
        }
      }
    }
  }
  return 0;
}

