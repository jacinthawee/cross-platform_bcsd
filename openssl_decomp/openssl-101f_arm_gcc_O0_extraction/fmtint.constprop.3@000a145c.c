
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fmtint_constprop_3(int *param_1,uint *param_2,uint *param_3,undefined4 param_4,int param_5,
                       int param_6,int param_7,int param_8,uint param_9,uint param_10)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  bool bVar11;
  longlong lVar12;
  char *local_64;
  uint local_54;
  uint local_4c;
  char acStack_48 [28];
  int local_2c;
  
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  local_2c = __TMC_END__;
  if ((int)(param_10 << 0x19) < 0) {
    local_54 = 0;
    local_4c = 0;
  }
  else if (param_6 < 0) {
    bVar11 = param_5 != 0;
    param_5 = -param_5;
    param_6 = -param_6 - (uint)bVar11;
    local_54 = 1;
    local_4c = 0x2d;
  }
  else if ((int)(param_10 << 0x1e) < 0) {
    local_4c = 0x2b;
    local_54 = 1;
  }
  else {
    local_54 = param_10 & 4;
    local_4c = local_54;
    if (local_54 != 0) {
      local_4c = 0x20;
      local_54 = 1;
    }
  }
  lVar12 = CONCAT44(param_6,param_5);
  if ((int)(param_10 << 0x1c) < 0) {
    if (param_7 == 8) {
      local_64 = "0";
    }
    else {
      local_64 = "0x";
      if (param_7 != 0x10) {
        local_64 = "";
      }
    }
  }
  else {
    local_64 = "";
  }
  if ((param_10 & 0x20) == 0) {
    uVar9 = param_10 & 0x20;
    do {
      uVar6 = uVar9;
      uVar8 = (undefined4)((ulonglong)lVar12 >> 0x20);
      iVar4 = param_7;
      __aeabi_uldivmod((int)lVar12,uVar8,param_7,0);
      uVar9 = uVar6 + 1;
      acStack_48[uVar6] = "0123456789abcdef"[iVar4];
      lVar12 = __aeabi_uldivmod((int)lVar12,uVar8,param_7);
    } while ((int)uVar9 < 0x1a && lVar12 != 0);
  }
  else {
    uVar9 = 0;
    do {
      uVar6 = uVar9;
      uVar8 = (undefined4)((ulonglong)lVar12 >> 0x20);
      iVar4 = param_7;
      __aeabi_uldivmod((int)lVar12,uVar8,param_7,0);
      uVar9 = uVar6 + 1;
      acStack_48[uVar6] = "0123456789ABCDEF"[iVar4];
      lVar12 = __aeabi_uldivmod((int)lVar12,uVar8,param_7);
    } while ((int)uVar9 < 0x1a && lVar12 != 0);
  }
  if (uVar9 == 0x1a) {
    uVar9 = uVar6;
  }
  acStack_48[uVar9] = '\0';
  sVar2 = strlen(local_64);
  uVar6 = param_9 - uVar9;
  if ((int)param_9 <= (int)uVar9) {
    param_9 = uVar9;
  }
  uVar6 = uVar6 & ~((int)uVar6 >> 0x1f);
  uVar3 = ((param_8 - param_9) - local_54) - sVar2;
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)(param_10 << 0x1b) < 0) {
    if ((int)uVar6 < (int)uVar3) {
      uVar6 = uVar3;
    }
    uVar3 = 0;
  }
  if ((int)(param_10 << 0x1f) < 0) {
    uVar3 = -uVar3;
  }
  else if (0 < (int)uVar3) {
    do {
      uVar7 = *param_2;
      if (uVar7 < *param_3) {
        iVar4 = *param_1;
        if (*param_1 == 0) {
          iVar4 = _shift;
        }
        *param_2 = uVar7 + 1;
        *(undefined *)(iVar4 + uVar7) = 0x20;
      }
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  iVar4 = _shift;
  if ((local_54 != 0) && (uVar7 = *param_2, uVar7 < *param_3)) {
    iVar5 = *param_1;
    if (iVar5 == 0) {
      *param_2 = uVar7 + 1;
      *(char *)(iVar4 + uVar7) = (char)local_4c;
    }
    else {
      *param_2 = uVar7 + 1;
      *(char *)(iVar5 + uVar7) = (char)local_4c;
    }
  }
  cVar1 = *local_64;
  while (cVar1 != '\0') {
    uVar7 = *param_2;
    if (uVar7 < *param_3) {
      iVar4 = *param_1;
      if (*param_1 == 0) {
        iVar4 = _shift;
      }
      *param_2 = uVar7 + 1;
      *(char *)(iVar4 + uVar7) = cVar1;
    }
    local_64 = local_64 + 1;
    cVar1 = *local_64;
  }
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    uVar7 = *param_2;
    if (uVar7 < *param_3) {
      iVar4 = *param_1;
      if (*param_1 == 0) {
        iVar4 = _shift;
      }
      *param_2 = uVar7 + 1;
      *(undefined *)(iVar4 + uVar7) = 0x30;
    }
  }
  if (uVar9 != 0) {
    pcVar10 = acStack_48 + uVar9;
    do {
      uVar9 = *param_2;
      pcVar10 = pcVar10 + -1;
      cVar1 = *pcVar10;
      if (uVar9 < *param_3) {
        iVar4 = *param_1;
        if (*param_1 == 0) {
          iVar4 = _shift;
        }
        *param_2 = uVar9 + 1;
        *(char *)(iVar4 + uVar9) = cVar1;
      }
    } while (pcVar10 != acStack_48);
  }
  for (; uVar3 != 0; uVar3 = uVar3 + 1) {
    uVar9 = *param_2;
    if (uVar9 < *param_3) {
      iVar4 = *param_1;
      if (*param_1 == 0) {
        iVar4 = _shift;
      }
      *param_2 = uVar9 + 1;
      *(undefined *)(iVar4 + uVar9) = 0x20;
    }
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

