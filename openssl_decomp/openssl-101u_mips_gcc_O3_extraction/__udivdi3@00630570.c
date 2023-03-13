
ulonglong __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_3 == 0) {
    uVar2 = countLeadingZeros(param_4);
    if (param_1 < param_4) {
      uVar6 = param_4 >> 0x10;
      if (uVar2 != 0) {
        uVar6 = param_2 >> (-uVar2 & 0x1f);
        param_4 = param_4 << (uVar2 & 0x1f);
        param_2 = param_2 << (uVar2 & 0x1f);
        param_1 = uVar6 | param_1 << (uVar2 & 0x1f);
        uVar6 = param_4 >> 0x10;
      }
      if (uVar6 == 0) {
        trap(7);
      }
      uVar8 = param_1 / uVar6;
      uVar2 = (param_4 & 0xffff) * uVar8;
      if (uVar6 == 0) {
        trap(7);
      }
      uVar3 = param_2 >> 0x10 | param_1 % uVar6 << 0x10;
      uVar7 = uVar8;
      if (uVar3 < uVar2) {
        uVar3 = uVar3 + param_4;
        uVar7 = uVar8 - 1;
        if ((param_4 <= uVar3) && (uVar3 < uVar2)) {
          uVar7 = uVar8 - 2;
          uVar3 = uVar3 + param_4;
        }
      }
      if (uVar6 == 0) {
        trap(7);
      }
      uVar9 = (uVar3 - uVar2) / uVar6;
      uVar8 = (param_4 & 0xffff) * uVar9;
      if (uVar6 == 0) {
        trap(7);
      }
      uVar6 = param_2 & 0xffff | (uVar3 - uVar2) % uVar6 << 0x10;
      uVar3 = param_4 + uVar6;
      uVar2 = uVar9;
      if (((uVar6 < uVar8) && (uVar2 = uVar9 - 1, param_4 <= uVar3)) && (uVar3 < uVar8)) {
        uVar2 = uVar9 - 2;
      }
      uVar6 = 0;
      uVar2 = uVar7 << 0x10 | uVar2;
LAB_0063066c:
      return CONCAT44(uVar6,uVar2);
    }
    uVar2 = countLeadingZeros(param_4);
    if (param_4 == 0) {
      trap(7);
      param_4 = 1 / 0;
      uVar2 = countLeadingZeros(param_4);
    }
    if (uVar2 == 0) {
      param_1 = param_1 - param_4;
      uVar6 = param_4 >> 0x10;
      uVar7 = 1;
      uVar3 = param_4 & 0xffff;
    }
    else {
      param_4 = param_4 << (uVar2 & 0x1f);
      uVar6 = param_4 >> 0x10;
      uVar8 = param_1 >> (0x20 - uVar2 & 0x1f);
      if (uVar6 == 0) {
        trap(7);
      }
      uVar9 = uVar8 / uVar6;
      uVar7 = param_2 >> (0x20 - uVar2 & 0x1f);
      uVar3 = param_4 & 0xffff;
      param_2 = param_2 << (uVar2 & 0x1f);
      uVar7 = uVar7 | param_1 << (uVar2 & 0x1f);
      uVar2 = uVar3 * uVar9;
      if (uVar6 == 0) {
        trap(7);
      }
      uVar4 = uVar7 >> 0x10 | uVar8 % uVar6 << 0x10;
      uVar5 = uVar4 - uVar2;
      uVar8 = uVar9;
      if (uVar4 < uVar2) {
        uVar4 = uVar4 + param_4;
        uVar8 = uVar9 - 1;
        if ((param_4 <= uVar4) && (uVar4 < uVar2)) {
          uVar8 = uVar9 - 2;
          uVar4 = uVar4 + param_4;
        }
        uVar5 = uVar4 - uVar2;
      }
      if (uVar6 == 0) {
        trap(7);
      }
      uVar9 = uVar5 / uVar6;
      uVar2 = uVar3 * uVar9;
      if (uVar6 == 0) {
        trap(7);
      }
      param_1 = uVar7 & 0xffff | uVar5 % uVar6 << 0x10;
      uVar7 = uVar9;
      if (param_1 < uVar2) {
        param_1 = param_1 + param_4;
        uVar7 = uVar9 - 1;
        if ((param_4 <= param_1) && (param_1 < uVar2)) {
          uVar7 = uVar9 - 2;
          param_1 = param_1 + param_4;
        }
      }
      param_1 = param_1 - uVar2;
      uVar7 = uVar8 << 0x10 | uVar7;
    }
    if (uVar6 == 0) {
      trap(7);
    }
    uVar8 = param_1 / uVar6;
    uVar2 = uVar8 * uVar3;
    if (uVar6 == 0) {
      trap(7);
    }
    uVar4 = param_2 >> 0x10 | param_1 % uVar6 << 0x10;
    uVar5 = uVar4 - uVar2;
    uVar9 = uVar8;
    if (uVar4 < uVar2) {
      uVar4 = uVar4 + param_4;
      uVar9 = uVar8 - 1;
      if ((param_4 <= uVar4) && (uVar4 < uVar2)) {
        uVar4 = uVar4 + param_4;
        uVar9 = uVar8 - 2;
      }
      uVar5 = uVar4 - uVar2;
    }
    if (uVar6 == 0) {
      trap(7);
    }
    uVar2 = uVar5 / uVar6;
    if (uVar6 == 0) {
      trap(7);
    }
    uVar6 = param_2 & 0xffff | uVar5 % uVar6 << 0x10;
    uVar8 = param_4 + uVar6;
    if (uVar6 < uVar2 * uVar3) {
      if ((uVar8 < param_4) || (uVar2 * uVar3 <= uVar8)) {
        uVar2 = uVar9 << 0x10 | uVar2 - 1;
        goto LAB_00630788;
      }
      uVar2 = uVar2 - 2;
    }
    uVar2 = uVar9 << 0x10 | uVar2;
LAB_00630788:
    return CONCAT44(uVar7,uVar2);
  }
  if (param_1 < param_3) {
    return 0;
  }
  uVar6 = countLeadingZeros(param_3);
  if (uVar6 == 0) {
    if (param_1 <= param_3) {
      return (ulonglong)(param_2 < param_4) ^ 1;
    }
    return 1;
  }
  uVar7 = 0x20 - uVar6;
  uVar2 = param_1 >> (uVar7 & 0x1f);
  uVar8 = param_4 >> (uVar7 & 0x1f) | param_3 << (uVar6 & 0x1f);
  uVar3 = uVar8 >> 0x10;
  if (uVar3 == 0) {
    trap(7);
  }
  uVar4 = uVar2 / uVar3;
  uVar7 = param_2 >> (uVar7 & 0x1f) | param_1 << (uVar6 & 0x1f);
  uVar9 = (uVar8 & 0xffff) * uVar4;
  if (uVar3 == 0) {
    trap(7);
  }
  uVar2 = uVar7 >> 0x10 | uVar2 % uVar3 << 0x10;
  uVar5 = uVar4;
  if (uVar2 < uVar9) {
    uVar2 = uVar2 + uVar8;
    uVar5 = uVar4 - 1;
    if ((uVar8 <= uVar2) && (uVar2 < uVar9)) {
      uVar2 = uVar2 + uVar8;
      uVar5 = uVar4 - 2;
    }
  }
  if (uVar3 == 0) {
    trap(7);
  }
  uVar10 = (uVar2 - uVar9) / uVar3;
  uVar4 = (uVar8 & 0xffff) * uVar10;
  if (uVar3 == 0) {
    trap(7);
  }
  uVar7 = uVar7 & 0xffff | (uVar2 - uVar9) % uVar3 << 0x10;
  uVar2 = uVar10;
  if (uVar7 < uVar4) {
    uVar7 = uVar7 + uVar8;
    uVar2 = uVar10 - 1;
    if ((uVar8 <= uVar7) && (uVar7 < uVar4)) {
      uVar7 = uVar7 + uVar8;
      uVar2 = uVar10 - 2;
    }
  }
  uVar2 = uVar5 << 0x10 | uVar2;
  lVar1 = (ulonglong)uVar2 * (ulonglong)(param_4 << (uVar6 & 0x1f));
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  if (uVar8 <= uVar7 - uVar4) {
    if (uVar7 - uVar4 != uVar8) goto LAB_00630884;
    uVar6 = (uint)(param_2 << (uVar6 & 0x1f) < (uint)lVar1);
    if (uVar6 == 0) goto LAB_0063066c;
  }
  uVar2 = uVar2 - 1;
LAB_00630884:
  return (ulonglong)uVar2;
}

