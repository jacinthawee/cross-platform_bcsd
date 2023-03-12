
ulonglong __umoddi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_3 != 0) {
    if (param_1 < param_3) {
      return CONCAT44(param_1,param_2);
    }
    uVar9 = countLeadingZeros(param_3);
    if (uVar9 == 0) {
      if ((param_1 <= param_3) && (param_2 < param_4)) {
        return CONCAT44(param_1,param_2);
      }
      return CONCAT44((param_1 - param_3) - (uint)(param_2 < param_2 - param_4),param_2 - param_4);
    }
    uVar4 = 0x20 - uVar9;
    uVar3 = param_1 >> (uVar4 & 0x1f);
    uVar5 = param_4 >> (uVar4 & 0x1f) | param_3 << (uVar9 & 0x1f);
    uVar7 = uVar5 >> 0x10;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar11 = uVar3 / uVar7;
    uVar2 = param_2 >> (uVar4 & 0x1f) | param_1 << (uVar9 & 0x1f);
    param_4 = param_4 << (uVar9 & 0x1f);
    uVar8 = (uVar5 & 0xffff) * uVar11;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar10 = uVar2 >> 0x10 | uVar3 % uVar7 << 0x10;
    param_2 = param_2 << (uVar9 & 0x1f);
    uVar3 = uVar11;
    if (uVar10 < uVar8) {
      uVar10 = uVar10 + uVar5;
      uVar3 = uVar11 - 1;
      if ((uVar5 <= uVar10) && (uVar10 < uVar8)) {
        uVar10 = uVar10 + uVar5;
        uVar3 = uVar11 - 2;
      }
    }
    if (uVar7 == 0) {
      trap(7);
    }
    uVar12 = (uVar10 - uVar8) / uVar7;
    uVar11 = (uVar5 & 0xffff) * uVar12;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar8 = uVar2 & 0xffff | (uVar10 - uVar8) % uVar7 << 0x10;
    uVar7 = uVar12;
    if (uVar8 < uVar11) {
      uVar8 = uVar8 + uVar5;
      uVar7 = uVar12 - 1;
      if ((uVar5 <= uVar8) && (uVar8 < uVar11)) {
        uVar8 = uVar8 + uVar5;
        uVar7 = uVar12 - 2;
      }
    }
    uVar8 = uVar8 - uVar11;
    lVar1 = (ulonglong)(uVar3 << 0x10 | uVar7) * (ulonglong)param_4;
    uVar7 = (uint)lVar1;
    uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
    if (uVar3 <= uVar8) {
      iVar6 = uVar8 - uVar3;
      if (uVar8 != uVar3) goto LAB_006316f8;
      if (uVar7 <= param_2) {
        iVar6 = 0;
        goto LAB_006316f8;
      }
    }
    param_4 = uVar7 - param_4;
    iVar6 = uVar8 - ((uVar3 - uVar5) - (uint)(uVar7 < param_4));
    uVar7 = param_4;
LAB_006316f8:
    uVar3 = iVar6 - (uint)(param_2 < param_2 - uVar7);
    return CONCAT44(uVar3 >> (uVar9 & 0x1f),
                    uVar3 << (uVar4 & 0x1f) | param_2 - uVar7 >> (uVar9 & 0x1f));
  }
  if (param_1 < param_4) {
    uVar9 = countLeadingZeros(param_4);
    if (uVar9 != 0) {
      uVar7 = param_2 >> (-uVar9 & 0x1f);
      param_4 = param_4 << (uVar9 & 0x1f);
      param_2 = param_2 << (uVar9 & 0x1f);
      param_1 = uVar7 | param_1 << (uVar9 & 0x1f);
    }
    uVar7 = param_4 >> 0x10;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar3 = (param_4 & 0xffff) * (param_1 / uVar7);
    if (uVar7 == 0) {
      trap(7);
    }
    uVar5 = param_2 >> 0x10 | param_1 % uVar7 << 0x10;
    if (uVar5 < uVar3) {
      uVar5 = uVar5 + param_4;
      if ((param_4 <= uVar5) && (uVar5 < uVar3)) {
        uVar5 = uVar5 + param_4;
      }
    }
    if (uVar7 == 0) {
      trap(7);
    }
    uVar4 = (param_4 & 0xffff) * ((uVar5 - uVar3) / uVar7);
    if (uVar7 == 0) {
      trap(7);
    }
    uVar7 = param_2 & 0xffff | (uVar5 - uVar3) % uVar7 << 0x10;
    if ((uVar4 <= uVar7) || (uVar7 = uVar7 + param_4, uVar7 < param_4)) goto LAB_006314d0;
    param_4 = uVar7 + param_4;
  }
  else {
    uVar9 = countLeadingZeros(param_4);
    if (param_4 == 0) {
      trap(7);
      param_4 = 1 / 0;
      uVar9 = countLeadingZeros(param_4);
    }
    if (uVar9 == 0) {
      param_1 = param_1 - param_4;
      uVar7 = param_4 >> 0x10;
      uVar4 = param_4 & 0xffff;
    }
    else {
      param_4 = param_4 << (uVar9 & 0x1f);
      uVar7 = param_4 >> 0x10;
      uVar3 = param_1 >> (0x20 - uVar9 & 0x1f);
      if (uVar7 == 0) {
        trap(7);
      }
      uVar4 = param_4 & 0xffff;
      uVar5 = param_2 >> (0x20 - uVar9 & 0x1f) | param_1 << (uVar9 & 0x1f);
      uVar8 = uVar4 * (uVar3 / uVar7);
      if (uVar7 == 0) {
        trap(7);
      }
      uVar3 = uVar5 >> 0x10 | uVar3 % uVar7 << 0x10;
      param_2 = param_2 << (uVar9 & 0x1f);
      if (uVar3 < uVar8) {
        uVar3 = uVar3 + param_4;
        if ((param_4 <= uVar3) && (uVar3 < uVar8)) {
          uVar3 = uVar3 + param_4;
        }
      }
      if (uVar7 == 0) {
        trap(7);
      }
      uVar2 = uVar4 * ((uVar3 - uVar8) / uVar7);
      if (uVar7 == 0) {
        trap(7);
      }
      uVar3 = uVar5 & 0xffff | (uVar3 - uVar8) % uVar7 << 0x10;
      param_1 = uVar3 - uVar2;
      if (uVar3 < uVar2) {
        uVar3 = uVar3 + param_4;
        if ((param_4 <= uVar3) && (uVar3 < uVar2)) {
          uVar3 = uVar3 + param_4;
        }
        param_1 = uVar3 - uVar2;
      }
    }
    if (uVar7 == 0) {
      trap(7);
    }
    uVar3 = (param_1 / uVar7) * uVar4;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar5 = param_2 >> 0x10 | param_1 % uVar7 << 0x10;
    if (uVar5 < uVar3) {
      uVar5 = uVar5 + param_4;
      if ((param_4 <= uVar5) && (uVar5 < uVar3)) {
        uVar5 = uVar5 + param_4;
      }
    }
    if (uVar7 == 0) {
      trap(7);
    }
    uVar4 = ((uVar5 - uVar3) / uVar7) * uVar4;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar7 = param_2 & 0xffff | (uVar5 - uVar3) % uVar7 << 0x10;
    if ((uVar4 <= uVar7) || (uVar7 = uVar7 + param_4, uVar7 < param_4)) goto LAB_006314d0;
    param_4 = uVar7 + param_4;
  }
  if (uVar7 < uVar4) {
    uVar7 = param_4;
  }
LAB_006314d0:
  return (ulonglong)(uVar7 - uVar4 >> (uVar9 & 0x1f));
}

