
undefined4 __regparm3
fmtint(void **param_1_00,void **param_2_00,uint *param_3_00,uint *param_1,int param_2,int param_3,
      int param_4,int param_5,int param_6,uint param_7)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int in_GS_OFFSET;
  bool bVar11;
  longlong lVar12;
  int local_64;
  char *local_58;
  uint local_48;
  int local_40;
  char local_3b [27];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar10 = 0;
  if (-1 < param_6) {
    iVar10 = param_6;
  }
  if ((param_7 & 0x40) == 0) {
    if (param_3 < 0) {
      bVar11 = param_2 != 0;
      param_2 = -param_2;
      local_48 = 1;
      local_40 = 0x2d;
      param_3 = -(param_3 + (uint)bVar11);
    }
    else if ((param_7 & 2) == 0) {
      local_48 = param_7 & 4;
      if (local_48 == 0) goto LAB_0811a408;
      local_48 = 1;
      local_40 = 0x20;
    }
    else {
      local_48 = 1;
      local_40 = 0x2b;
    }
  }
  else {
    local_48 = 0;
LAB_0811a408:
    local_40 = 0;
  }
  local_58 = "";
  if ((((param_7 & 8) != 0) && (local_58 = "0", param_4 != 8)) && (local_58 = "", param_4 == 0x10))
  {
    local_58 = "0x";
  }
  local_64 = 0;
  pcVar2 = "0123456789abcdef";
  iVar8 = local_64;
  lVar12 = CONCAT44(param_3,param_2);
  if ((param_7 & 0x20) != 0) {
    pcVar2 = "0123456789ABCDEF";
    lVar12 = CONCAT44(param_3,param_2);
  }
  do {
    local_64 = iVar8;
    iVar8 = local_64 + 1;
    iVar3 = __umoddi3(lVar12,param_4,0);
    local_3b[local_64 + 1] = pcVar2[iVar3];
    lVar12 = __udivdi3(lVar12,param_4,0);
  } while (lVar12 != 0 && iVar8 < 0x1a);
  if (iVar8 == 0x1a) {
    iVar8 = local_64;
  }
  local_3b[iVar8 + 1] = '\0';
  iVar3 = iVar10 - iVar8;
  sVar4 = strlen(local_58);
  if (iVar10 <= iVar8) {
    iVar10 = iVar8;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar10 = ((param_5 - iVar10) - local_48) - sVar4;
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  if ((param_7 & 0x10) == 0) {
    if ((param_7 & 1) == 0) {
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        sVar4 = *param_3_00;
        uVar9 = *param_1;
        if ((param_2_00 == (void **)0x0) || (sVar4 != uVar9)) {
LAB_0811a5f0:
          if (sVar4 < uVar9) {
            pvVar7 = *param_1_00;
            if (pvVar7 == (void *)0x0) goto LAB_0811a6b0;
LAB_0811a602:
            *param_3_00 = sVar4 + 1;
            *(undefined *)((int)pvVar7 + sVar4) = 0x20;
          }
        }
        else {
          if (0x7ffffbff < sVar4) goto LAB_0811a5a0;
          pvVar7 = *param_2_00;
          uVar9 = sVar4 + 0x400;
          *param_1 = uVar9;
          if (pvVar7 != (void *)0x0) {
            pvVar7 = CRYPTO_realloc(pvVar7,uVar9,"b_print.c",0x2fd);
            if (pvVar7 != (void *)0x0) {
              *param_2_00 = pvVar7;
              sVar4 = *param_3_00;
              uVar9 = *param_1;
              goto LAB_0811a5f0;
            }
            goto LAB_0811a5a0;
          }
          pvVar7 = CRYPTO_malloc(uVar9,"b_print.c",0x2f3);
          *param_2_00 = pvVar7;
          if (pvVar7 == (void *)0x0) goto LAB_0811a5a0;
          sVar4 = *param_3_00;
          if (sVar4 != 0) {
            memcpy(pvVar7,*param_1_00,sVar4);
            sVar4 = *param_3_00;
          }
          uVar9 = *param_1;
          *param_1_00 = (void *)0x0;
          if (sVar4 < uVar9) {
LAB_0811a6b0:
            pvVar7 = *param_2_00;
            goto LAB_0811a602;
          }
        }
      }
    }
    else {
      iVar10 = -iVar10;
    }
  }
  else {
    if (iVar3 < iVar10) {
      iVar3 = iVar10;
    }
    iVar10 = 0;
  }
  if ((local_40 == 0) || (iVar5 = doapr_outch(param_1,local_40), iVar5 != 0)) {
    cVar1 = *local_58;
    while (cVar1 != '\0') {
      iVar5 = doapr_outch(param_1,(int)cVar1);
      if (iVar5 == 0) goto LAB_0811a5a0;
      local_58 = local_58 + 1;
      cVar1 = *local_58;
    }
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      iVar5 = doapr_outch(param_1,0x30);
      if (iVar5 == 0) goto LAB_0811a5a0;
    }
    do {
      if (iVar8 == 0) goto joined_r0x0811a7b8;
      iVar3 = doapr_outch(param_1,(int)local_3b[iVar8]);
      iVar8 = iVar8 + -1;
    } while (iVar3 != 0);
  }
LAB_0811a5a0:
  uVar6 = 0;
LAB_0811a5a2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
joined_r0x0811a7b8:
  if (iVar10 == 0) goto LAB_0811a7f2;
  iVar8 = doapr_outch_constprop_0(param_1);
  if (iVar8 == 0) goto LAB_0811a5a0;
  iVar10 = iVar10 + 1;
  goto joined_r0x0811a7b8;
LAB_0811a7f2:
  uVar6 = 1;
  goto LAB_0811a5a2;
}

