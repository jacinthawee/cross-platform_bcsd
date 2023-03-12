
ulonglong __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
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
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = __udivsi3(1,0);
      }
      uVar10 = count_leading_zeroes(param_3);
      if (uVar10 == 0) {
        iVar9 = param_2 - param_3;
        uVar11 = param_3 >> 0x10;
        uVar4 = param_3 & 0xffff;
        uVar10 = 1;
        uVar7 = param_1;
      }
      else {
        param_3 = param_3 << (uVar10 & 0xff);
        uVar4 = param_2 >> (0x20 - uVar10 & 0xff);
        uVar7 = param_1 << (uVar10 & 0xff);
        uVar11 = param_3 >> 0x10;
        uVar8 = param_1 >> (0x20 - uVar10 & 0xff) | param_2 << (uVar10 & 0xff);
        iVar9 = __udivsi3(uVar4,uVar11);
        __aeabi_uidivmod(uVar4,uVar11);
        uVar4 = param_3 & 0xffff;
        uVar10 = uVar4 * iVar9;
        uVar5 = uVar8 >> 0x10 | extraout_r1_05 << 0x10;
        iVar3 = iVar9;
        if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
          bVar13 = CARRY4(uVar5,param_3);
          uVar5 = uVar5 + param_3;
          iVar3 = iVar9 + -1;
          if ((bVar13 == false) && (uVar5 <= uVar10 && uVar10 - uVar5 != 0)) {
            iVar3 = iVar9 + -2;
            uVar5 = uVar5 + param_3;
          }
        }
        uVar6 = __udivsi3(uVar5 - uVar10,uVar11);
        __aeabi_uidivmod(uVar5 - uVar10,uVar11);
        uVar12 = uVar4 * uVar6;
        uVar5 = uVar8 & 0xffff | extraout_r1_06 << 0x10;
        uVar10 = uVar6;
        if (uVar5 <= uVar12 && uVar12 - uVar5 != 0) {
          bVar13 = CARRY4(uVar5,param_3);
          uVar5 = uVar5 + param_3;
          uVar10 = uVar6 - 1;
          if ((bVar13 == false) && (uVar5 <= uVar12 && uVar12 - uVar5 != 0)) {
            uVar10 = uVar6 - 2;
            uVar5 = uVar5 + param_3;
          }
        }
        iVar9 = uVar5 - uVar12;
        uVar10 = uVar10 | iVar3 << 0x10;
      }
      iVar3 = __udivsi3(iVar9,uVar11);
      __aeabi_uidivmod(iVar9,uVar11);
      uVar5 = uVar4 * iVar3;
      uVar8 = uVar7 >> 0x10 | extraout_r1_01 << 0x10;
      iVar9 = iVar3;
      if (uVar8 <= uVar5 && uVar5 - uVar8 != 0) {
        bVar13 = CARRY4(uVar8,param_3);
        uVar8 = uVar8 + param_3;
        iVar9 = iVar3 + -1;
        if ((bVar13 == false) && (uVar8 <= uVar5 && uVar5 - uVar8 != 0)) {
          iVar9 = iVar3 + -2;
          uVar8 = uVar8 + param_3;
        }
      }
      uVar6 = __udivsi3(uVar8 - uVar5,uVar11);
      __aeabi_uidivmod(uVar8 - uVar5,uVar11);
      uVar4 = uVar4 * uVar6;
      uVar11 = uVar7 & 0xffff | extraout_r1_02 << 0x10;
      uVar7 = uVar6;
      if (uVar11 <= uVar4 && uVar4 - uVar11 != 0) {
        uVar7 = uVar6 - 1;
        if ((CARRY4(uVar11,param_3) == false) &&
           (uVar11 + param_3 <= uVar4 && uVar4 - (uVar11 + param_3) != 0)) {
          uVar7 = uVar6 - 2;
        }
      }
      return CONCAT44(uVar10,uVar7 | iVar9 << 0x10);
    }
    uVar10 = count_leading_zeroes(param_3);
    if (uVar10 != 0) {
      param_3 = param_3 << (uVar10 & 0xff);
      param_2 = param_1 >> (0x20 - uVar10 & 0xff) | param_2 << (uVar10 & 0xff);
      param_1 = param_1 << (uVar10 & 0xff);
    }
    uVar11 = param_3 >> 0x10;
    iVar3 = __udivsi3(param_2,uVar11);
    __aeabi_uidivmod(param_2,uVar11);
    uVar10 = (param_3 & 0xffff) * iVar3;
    uVar7 = param_1 >> 0x10 | extraout_r1 << 0x10;
    iVar9 = iVar3;
    if (uVar7 <= uVar10 && uVar10 - uVar7 != 0) {
      bVar13 = CARRY4(uVar7,param_3);
      uVar7 = uVar7 + param_3;
      iVar9 = iVar3 + -1;
      if ((bVar13 == false) && (uVar7 <= uVar10 && uVar10 - uVar7 != 0)) {
        iVar9 = iVar3 + -2;
        uVar7 = uVar7 + param_3;
      }
    }
    uVar4 = __udivsi3(uVar7 - uVar10,uVar11);
    __aeabi_uidivmod(uVar7 - uVar10,uVar11);
    uVar11 = (param_3 & 0xffff) * uVar4;
    uVar7 = param_1 & 0xffff | extraout_r1_00 << 0x10;
    uVar10 = uVar4;
    if (uVar7 <= uVar11 && uVar11 - uVar7 != 0) {
      uVar10 = uVar4 - 1;
      if ((CARRY4(uVar7,param_3) == false) &&
         (uVar7 + param_3 <= uVar11 && uVar11 - (uVar7 + param_3) != 0)) {
        uVar10 = uVar4 - 2;
      }
    }
    uVar7 = 0;
    uVar10 = uVar10 | iVar9 << 0x10;
  }
  else if (param_2 < param_4) {
    uVar7 = 0;
    uVar10 = uVar7;
  }
  else {
    uVar11 = count_leading_zeroes(param_4);
    if (uVar11 != 0) {
      uVar10 = 0x20 - uVar11;
      uVar7 = param_2 >> (uVar10 & 0xff);
      uVar5 = param_3 >> (uVar10 & 0xff) | param_4 << (uVar11 & 0xff);
      uVar8 = uVar5 >> 0x10;
      uVar4 = param_2 << (uVar11 & 0xff) | param_1 >> (uVar10 & 0xff);
      iVar3 = __udivsi3(uVar7,uVar8);
      __aeabi_uidivmod(uVar7,uVar8);
      uVar10 = (uVar5 & 0xffff) * iVar3;
      uVar7 = uVar4 >> 0x10 | extraout_r1_03 << 0x10;
      iVar9 = iVar3;
      if (uVar7 <= uVar10 && uVar10 - uVar7 != 0) {
        bVar13 = CARRY4(uVar7,uVar5);
        uVar7 = uVar7 + uVar5;
        iVar9 = iVar3 + -1;
        if ((bVar13 == false) && (uVar7 <= uVar10 && uVar10 - uVar7 != 0)) {
          iVar9 = iVar3 + -2;
          uVar7 = uVar7 + uVar5;
        }
      }
      uVar6 = __udivsi3(uVar7 - uVar10,uVar8);
      __aeabi_uidivmod(uVar7 - uVar10,uVar8);
      uVar8 = (uVar5 & 0xffff) * uVar6;
      uVar7 = uVar4 & 0xffff | extraout_r1_04 << 0x10;
      uVar10 = uVar6;
      if (uVar7 <= uVar8 && uVar8 - uVar7 != 0) {
        bVar13 = CARRY4(uVar7,uVar5);
        uVar7 = uVar7 + uVar5;
        uVar10 = uVar6 - 1;
        if ((bVar13 == false) && (uVar7 <= uVar8 && uVar8 - uVar7 != 0)) {
          uVar10 = uVar6 - 2;
          uVar7 = uVar7 + uVar5;
        }
      }
      uVar10 = uVar10 | iVar9 << 0x10;
      lVar1 = (ulonglong)uVar10 * (ulonglong)(param_3 << (uVar11 & 0xff));
      uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
      if (uVar4 <= uVar7 - uVar8) {
        uVar7 = (uint)(uVar7 - uVar8 == uVar4);
        if ((uint)lVar1 <= param_1 << (uVar11 & 0xff)) {
          uVar7 = 0;
        }
        if (uVar7 == 0) goto LAB_00124a46;
      }
      return (ulonglong)(uVar10 - 1);
    }
    bVar14 = param_4 < param_2;
    bVar13 = param_4 == param_2;
    if (!bVar14) {
      bVar13 = param_3 == param_1;
    }
    bVar2 = param_3 < param_1;
    uVar7 = param_1;
    if ((bVar14 || bVar2) || bVar13) {
      uVar7 = 1;
    }
    if ((!bVar14 && !bVar2) && !bVar13) {
      uVar7 = 0;
    }
    if ((bVar14 || bVar2) || bVar13) {
      uVar7 = uVar11;
    }
    if ((bVar14 || bVar2) || bVar13) {
      param_1 = 1;
    }
    uVar10 = param_1;
    if ((!bVar14 && !bVar2) && !bVar13) {
      uVar10 = uVar7;
    }
  }
LAB_00124a46:
  return CONCAT44(uVar7,uVar10);
}

