
undefined8 __divdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  uint uVar7;
  int extraout_r1_00;
  int extraout_r1_01;
  uint uVar8;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  if ((int)param_2 < 0) {
    bVar14 = param_1 != 0;
    param_1 = -param_1;
    uVar12 = 0xffffffff;
    param_2 = -param_2 - (uint)bVar14;
  }
  else {
    uVar12 = 0;
  }
  if ((int)param_4 < 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar12 = ~uVar12;
    param_4 = -param_4 - (uint)bVar14;
  }
  if (param_4 == 0) {
    if (param_2 < param_3) {
      uVar9 = count_leading_zeroes(param_3);
      if (uVar9 != 0) {
        param_3 = param_3 << (uVar9 & 0xff);
        param_2 = param_1 >> (0x20 - uVar9 & 0xff) | param_2 << (uVar9 & 0xff);
        param_1 = param_1 << (uVar9 & 0xff);
      }
      uVar11 = param_3 >> 0x10;
      iVar3 = __udivsi3(param_2,uVar11);
      __aeabi_uidivmod(param_2,uVar11);
      uVar9 = (param_3 & 0xffff) * iVar3;
      uVar7 = param_1 >> 0x10 | extraout_r1 << 0x10;
      iVar10 = iVar3;
      if (uVar7 <= uVar9 && uVar9 - uVar7 != 0) {
        bVar14 = CARRY4(uVar7,param_3);
        uVar7 = uVar7 + param_3;
        iVar10 = iVar3 + -1;
        if ((bVar14 == false) && (uVar7 <= uVar9 && uVar9 - uVar7 != 0)) {
          iVar10 = iVar3 + -2;
          uVar7 = uVar7 + param_3;
        }
      }
      uVar4 = __udivsi3(uVar7 - uVar9,uVar11);
      __aeabi_uidivmod(uVar7 - uVar9,uVar11);
      uVar11 = (param_3 & 0xffff) * uVar4;
      uVar9 = param_1 & 0xffff | extraout_r1_00 << 0x10;
      uVar7 = uVar4;
      if (uVar9 <= uVar11 && uVar11 - uVar9 != 0) {
        uVar7 = uVar4 - 1;
        if ((CARRY4(uVar9,param_3) == false) &&
           (uVar9 + param_3 <= uVar11 && uVar11 - (uVar9 + param_3) != 0)) {
          uVar7 = uVar4 - 2;
        }
      }
      uVar9 = 0;
      param_4 = uVar7 | iVar10 << 0x10;
    }
    else {
      if (param_3 == 0) {
        param_3 = __udivsi3(1,0);
      }
      uVar9 = count_leading_zeroes(param_3);
      if (uVar9 == 0) {
        iVar3 = param_2 - param_3;
        uVar11 = param_3 >> 0x10;
        uVar4 = param_3 & 0xffff;
        uVar9 = 1;
      }
      else {
        param_3 = param_3 << (uVar9 & 0xff);
        uVar7 = param_2 >> (0x20 - uVar9 & 0xff);
        uVar11 = param_3 >> 0x10;
        uVar8 = param_1 >> (0x20 - uVar9 & 0xff);
        param_1 = param_1 << (uVar9 & 0xff);
        uVar4 = param_3 & 0xffff;
        iVar3 = __udivsi3(uVar7,uVar11);
        uVar8 = uVar8 | param_2 << (uVar9 & 0xff);
        __aeabi_uidivmod(uVar7,uVar11);
        uVar9 = uVar4 * iVar3;
        uVar7 = uVar8 >> 0x10 | extraout_r1_03 << 0x10;
        iVar10 = iVar3;
        if (uVar7 <= uVar9 && uVar9 - uVar7 != 0) {
          bVar14 = CARRY4(uVar7,param_3);
          uVar7 = uVar7 + param_3;
          iVar10 = iVar3 + -1;
          if ((bVar14 == false) && (uVar7 <= uVar9 && uVar9 - uVar7 != 0)) {
            iVar10 = iVar3 + -2;
            uVar7 = uVar7 + param_3;
          }
        }
        uVar6 = __udivsi3(uVar7 - uVar9,uVar11);
        __aeabi_uidivmod(uVar7 - uVar9,uVar11);
        uVar13 = uVar4 * uVar6;
        uVar7 = uVar8 & 0xffff | extraout_r1_04 << 0x10;
        uVar9 = uVar6;
        if (uVar7 <= uVar13 && uVar13 - uVar7 != 0) {
          bVar14 = CARRY4(uVar7,param_3);
          uVar7 = uVar7 + param_3;
          uVar9 = uVar6 - 1;
          if ((bVar14 == false) && (uVar7 <= uVar13 && uVar13 - uVar7 != 0)) {
            uVar9 = uVar6 - 2;
            uVar7 = uVar7 + param_3;
          }
        }
        iVar3 = uVar7 - uVar13;
        uVar9 = uVar9 | iVar10 << 0x10;
      }
      iVar5 = __udivsi3(iVar3,uVar11);
      __aeabi_uidivmod(iVar3,uVar11);
      uVar7 = uVar4 * iVar5;
      uVar8 = param_1 >> 0x10 | extraout_r1_01 << 0x10;
      iVar10 = iVar5;
      if (uVar8 <= uVar7 && uVar7 - uVar8 != 0) {
        bVar14 = CARRY4(uVar8,param_3);
        uVar8 = uVar8 + param_3;
        iVar10 = iVar5 + -1;
        if ((bVar14 == false) && (uVar8 <= uVar7 && uVar7 - uVar8 != 0)) {
          iVar10 = iVar5 + -2;
          uVar8 = uVar8 + param_3;
        }
      }
      uVar6 = __udivsi3(uVar8 - uVar7,uVar11);
      __aeabi_uidivmod(uVar8 - uVar7,uVar11);
      uVar4 = uVar4 * uVar6;
      uVar11 = param_1 & 0xffff | extraout_r1_02 << 0x10;
      uVar7 = uVar6;
      if (uVar11 <= uVar4 && uVar4 - uVar11 != 0) {
        uVar7 = uVar6 - 1;
        if ((CARRY4(uVar11,param_3) == false) &&
           (uVar11 + param_3 <= uVar4 && uVar4 - (uVar11 + param_3) != 0)) {
          uVar7 = uVar6 - 2;
        }
      }
      param_4 = uVar7 | iVar10 << 0x10;
    }
  }
  else if (param_2 < param_4) {
    uVar9 = 0;
    param_4 = uVar9;
  }
  else {
    uVar7 = count_leading_zeroes(param_4);
    if (uVar7 == 0) {
      bVar15 = param_4 < param_2;
      bVar14 = param_4 == param_2;
      if (!bVar15) {
        bVar14 = param_3 == param_1;
      }
      bVar2 = param_3 < param_1;
      if ((bVar15 || bVar2) || bVar14) {
        param_1 = 1;
      }
      if ((!bVar15 && !bVar2) && !bVar14) {
        param_1 = 0;
      }
      uVar9 = param_1;
      if ((bVar15 || bVar2) || bVar14) {
        uVar9 = uVar7;
      }
      if ((bVar15 || bVar2) || bVar14) {
        param_4 = 1;
      }
      if ((!bVar15 && !bVar2) && !bVar14) {
        param_4 = uVar9;
      }
    }
    else {
      uVar11 = 0x20 - uVar7;
      uVar9 = param_2 >> (uVar11 & 0xff);
      uVar4 = param_3 >> (uVar11 & 0xff) | param_4 << (uVar7 & 0xff);
      uVar8 = uVar4 >> 0x10;
      uVar6 = param_1 >> (uVar11 & 0xff) | param_2 << (uVar7 & 0xff);
      iVar3 = __udivsi3(uVar9,uVar8);
      __aeabi_uidivmod(uVar9,uVar8);
      uVar9 = (uVar4 & 0xffff) * iVar3;
      uVar11 = uVar6 >> 0x10 | extraout_r1_05 << 0x10;
      iVar10 = iVar3;
      if (uVar11 <= uVar9 && uVar9 - uVar11 != 0) {
        bVar14 = CARRY4(uVar11,uVar4);
        uVar11 = uVar11 + uVar4;
        iVar10 = iVar3 + -1;
        if ((bVar14 == false) && (uVar11 <= uVar9 && uVar9 - uVar11 != 0)) {
          iVar10 = iVar3 + -2;
          uVar11 = uVar11 + uVar4;
        }
      }
      uVar13 = __udivsi3(uVar11 - uVar9,uVar8);
      __aeabi_uidivmod(uVar11 - uVar9,uVar8);
      uVar11 = (uVar4 & 0xffff) * uVar13;
      uVar9 = uVar6 & 0xffff | extraout_r1_06 << 0x10;
      param_4 = uVar13;
      if (uVar9 <= uVar11 && uVar11 - uVar9 != 0) {
        bVar14 = CARRY4(uVar9,uVar4);
        uVar9 = uVar9 + uVar4;
        param_4 = uVar13 - 1;
        if ((bVar14 == false) && (uVar9 <= uVar11 && uVar11 - uVar9 != 0)) {
          param_4 = uVar13 - 2;
          uVar9 = uVar9 + uVar4;
        }
      }
      param_4 = param_4 | iVar10 << 0x10;
      lVar1 = (ulonglong)param_4 * (ulonglong)(param_3 << (uVar7 & 0xff));
      uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
      if (uVar4 <= uVar9 - uVar11) {
        uVar9 = (uint)(uVar9 - uVar11 == uVar4);
        if ((uint)lVar1 <= param_1 << (uVar7 & 0xff)) {
          uVar9 = 0;
        }
        if (uVar9 == 0) goto LAB_001233c8;
      }
      param_4 = param_4 - 1;
      uVar9 = 0;
    }
  }
LAB_001233c8:
  if (uVar12 != 0) {
    bVar14 = param_4 != 0;
    param_4 = -param_4;
    uVar9 = -uVar9 - (uint)bVar14;
  }
  return CONCAT44(uVar9,param_4);
}

