
void fmtint(void **param_1,void **param_2,uint *param_3,uint *param_4,int param_5,int param_6,
           int param_7,int param_8,uint param_9,uint param_10)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  bool bVar12;
  longlong lVar13;
  uint local_68;
  char *local_60;
  uint local_50;
  uint local_4c;
  char acStack_48 [28];
  int local_2c;
  
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  local_2c = __stack_chk_guard;
  if ((int)(param_10 << 0x19) < 0) {
    local_68 = 0;
    local_50 = local_68;
    local_4c = local_68;
  }
  else if (param_6 < 0) {
    bVar12 = param_5 != 0;
    param_5 = -param_5;
    param_6 = -param_6 - (uint)bVar12;
    local_50 = 1;
    local_4c = 0x2d;
  }
  else if ((int)(param_10 << 0x1e) < 0) {
    local_4c = 0x2b;
    local_50 = 1;
  }
  else {
    local_50 = param_10 & 4;
    local_4c = local_50;
    if (local_50 != 0) {
      local_4c = 0x20;
      local_50 = 1;
    }
  }
  lVar13 = CONCAT44(param_6,param_5);
  if ((int)(param_10 << 0x1c) < 0) {
    if (param_7 == 8) {
      local_60 = "0";
    }
    else {
      local_60 = "0x";
      if (param_7 != 0x10) {
        local_60 = "";
      }
    }
  }
  else {
    local_60 = "";
  }
  if ((param_10 & 0x20) == 0) {
    uVar9 = param_10 & 0x20;
    do {
      uVar10 = uVar9;
      uVar8 = (undefined4)((ulonglong)lVar13 >> 0x20);
      iVar5 = param_7;
      __aeabi_uldivmod((int)lVar13,uVar8,param_7,0);
      uVar9 = uVar10 + 1;
      acStack_48[uVar10] = "0123456789abcdef"[iVar5];
      lVar13 = __aeabi_uldivmod((int)lVar13,uVar8,param_7);
    } while ((int)uVar9 < 0x1a && lVar13 != 0);
  }
  else {
    uVar9 = 0;
    do {
      uVar10 = uVar9;
      uVar8 = (undefined4)((ulonglong)lVar13 >> 0x20);
      iVar5 = param_7;
      __aeabi_uldivmod((int)lVar13,uVar8,param_7,0);
      uVar9 = uVar10 + 1;
      acStack_48[uVar10] = "0123456789ABCDEF"[iVar5];
      lVar13 = __aeabi_uldivmod((int)lVar13,uVar8,param_7);
    } while ((int)uVar9 < 0x1a && lVar13 != 0);
  }
  if (uVar9 == 0x1a) {
    uVar9 = uVar10;
  }
  acStack_48[uVar9] = '\0';
  sVar2 = strlen(local_60);
  uVar10 = param_9 - uVar9;
  if ((int)param_9 <= (int)uVar9) {
    param_9 = uVar9;
  }
  uVar10 = uVar10 & ~((int)uVar10 >> 0x1f);
  uVar3 = ((param_8 - param_9) - local_50) - sVar2;
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)(param_10 << 0x1b) < 0) {
    if ((int)uVar10 < (int)uVar3) {
      uVar10 = uVar3;
    }
    uVar3 = 0;
  }
  param_10 = param_10 & 1;
  if (param_10 == 0) {
    if (0 < (int)uVar3) {
      do {
        uVar6 = *param_3;
        uVar7 = *param_4;
        if ((param_2 != (void **)0x0) && (uVar6 == uVar7)) {
          if (0x7ffffbff < uVar6) goto LAB_0009fac4;
          pvVar4 = *param_2;
          uVar6 = uVar6 + 0x400;
          *param_4 = uVar6;
          if (pvVar4 == (void *)0x0) {
            pvVar4 = CRYPTO_malloc(uVar6,"b_print.c",0x2f3);
            *param_2 = pvVar4;
            if (pvVar4 == (void *)0x0) goto LAB_0009fac4;
            uVar6 = *param_3;
            if (uVar6 != 0) {
              memcpy(pvVar4,*param_1,uVar6);
              uVar6 = *param_3;
            }
            uVar7 = *param_4;
            *param_1 = (void *)0x0;
          }
          else {
            pvVar4 = CRYPTO_realloc(pvVar4,uVar6,"b_print.c",0x2fd);
            if (pvVar4 == (void *)0x0) goto LAB_0009fac4;
            uVar6 = *param_3;
            uVar7 = *param_4;
            *param_2 = pvVar4;
          }
        }
        if (uVar6 < uVar7) {
          pvVar4 = *param_1;
          if (pvVar4 == (void *)0x0) {
            pvVar4 = *param_2;
          }
          *param_3 = uVar6 + 1;
          *(undefined *)((int)pvVar4 + uVar6) = 0x20;
        }
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  else {
    uVar3 = -uVar3;
  }
  if ((local_50 == 0) || (iVar5 = doapr_outch(param_1,param_2,param_3,param_4,local_4c), iVar5 != 0)
     ) {
    cVar1 = *local_60;
    while (cVar1 != '\0') {
      iVar5 = doapr_outch(param_1,param_2,param_3,param_4,cVar1);
      if (iVar5 == 0) goto LAB_0009fac0;
      local_60 = local_60 + 1;
      cVar1 = *local_60;
    }
    for (; uVar10 != 0; uVar10 = uVar10 - 1) {
      iVar5 = doapr_outch(param_1,param_2,param_3,param_4,0x30);
      if (iVar5 == 0) goto LAB_0009fac0;
    }
    if (uVar9 != 0) {
      pcVar11 = acStack_48 + uVar9;
      do {
        pcVar11 = pcVar11 + -1;
        uVar9 = uVar9 - 1;
        iVar5 = doapr_outch(param_1,param_2,param_3,param_4,*pcVar11);
        if (iVar5 == 0) goto LAB_0009fac0;
      } while (uVar9 != 0);
    }
    for (; uVar3 != 0; uVar3 = uVar3 + 1) {
      iVar5 = doapr_outch_constprop_0(param_1,param_2,param_3,param_4);
      if (iVar5 == 0) goto LAB_0009fac0;
    }
    param_10 = 1;
  }
  else {
LAB_0009fac0:
    param_10 = 0;
  }
LAB_0009fac4:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_10);
}

