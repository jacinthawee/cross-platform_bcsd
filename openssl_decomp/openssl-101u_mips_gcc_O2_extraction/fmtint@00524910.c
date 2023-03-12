
undefined4
fmtint(int *param_1,int *param_2,uint *param_3,uint *param_4,int param_5,int param_6,int param_7,
      int param_8,int param_9,uint param_10)

{
  undefined *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int extraout_v1;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  longlong lVar11;
  char *local_60;
  uint local_5c;
  int local_50;
  char acStack_49 [29];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_9 < 0) {
    param_9 = 0;
  }
  if ((param_10 & 0x40) == 0) {
    if (param_5 < 0) {
      param_6 = -param_6;
      local_5c = 1;
      param_5 = -(uint)(param_6 != 0) - param_5;
      local_50 = 0x2d;
    }
    else if ((param_10 & 2) == 0) {
      local_5c = param_10 & 4;
      if (local_5c == 0) goto LAB_00524bb8;
      local_5c = 1;
      local_50 = 0x20;
    }
    else {
      local_5c = 1;
      local_50 = 0x2b;
    }
  }
  else {
    local_5c = 0;
LAB_00524bb8:
    local_50 = 0;
  }
  if ((param_10 & 8) != 0) {
    if (param_7 == 8) {
      local_60 = "0";
      goto LAB_005249d4;
    }
    if (param_7 == 0x10) {
      local_60 = "0x";
      goto LAB_005249d4;
    }
  }
  local_60 = "";
LAB_005249d4:
  pcVar2 = acStack_49 + 1;
  pcVar7 = pcVar2;
  iVar9 = 0;
  pcVar3 = "0123456789abcdef";
  lVar11 = CONCAT44(param_5,param_6);
  if ((param_10 & 0x20) != 0) {
    pcVar3 = "0123456789ABCDEF";
    lVar11 = CONCAT44(param_5,param_6);
  }
  do {
    iVar8 = iVar9;
    uVar4 = (undefined4)((ulonglong)lVar11 >> 0x20);
    (*(code *)PTR___umoddi3_006a85bc)(uVar4,(int)lVar11,0,param_7);
    iVar9 = iVar8 + 1;
    *pcVar7 = pcVar3[extraout_v1];
    lVar11 = (*(code *)PTR___udivdi3_006a85e8)(uVar4,(int)lVar11,0,param_7);
    if (lVar11 == 0) {
      if (iVar9 != 0x1a) {
        iVar8 = iVar9;
      }
      break;
    }
    pcVar7 = pcVar7 + 1;
  } while (iVar9 != 0x1a);
  acStack_49[iVar8 + 1] = '\0';
  pcVar7 = (char *)(param_9 - iVar8);
  iVar9 = (*(code *)PTR_strlen_006a9a24)(local_60);
  if (param_9 <= iVar8) {
    param_9 = iVar8;
  }
  if ((int)pcVar7 < 0) {
    pcVar7 = (char *)0x0;
  }
  pcVar3 = (char *)(((param_8 - param_9) - local_5c) - iVar9);
  if ((int)pcVar3 < 0) {
    pcVar3 = (char *)0x0;
  }
  if ((param_10 & 0x10) == 0) {
    if ((param_10 & 1) != 0) goto LAB_00524f00;
    for (; pcVar3 != (char *)0x0; pcVar3 = pcVar3 + -1) {
      uVar6 = *param_3;
      uVar5 = *param_4;
      if ((param_2 == (int *)0x0) || (uVar6 != uVar5)) {
LAB_00524c1c:
        if (uVar6 < uVar5) {
          iVar9 = *param_1;
          if (iVar9 == 0) goto LAB_00524d5c;
LAB_00524c34:
          *param_3 = uVar6 + 1;
          *(undefined *)(iVar9 + uVar6) = 0x20;
        }
      }
      else {
        uVar5 = uVar6 + 0x400;
        if (0x7ffffbff < uVar6) goto LAB_00524cc0;
        iVar9 = *param_2;
        *param_4 = uVar5;
        if (iVar9 != 0) {
          iVar9 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(iVar9,uVar5,"b_print.c",0x2fd);
          if (iVar9 == 0) goto LAB_00524cc0;
          uVar6 = *param_3;
          uVar5 = *param_4;
          *param_2 = iVar9;
          goto LAB_00524c1c;
        }
        iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5,"b_print.c",0x2f3);
        *param_2 = iVar9;
        if (iVar9 == 0) goto LAB_00524cc0;
        uVar6 = *param_3;
        if (uVar6 != 0) {
          (*(code *)PTR_memcpy_006a9aec)(iVar9,*param_1);
          uVar6 = *param_3;
        }
        uVar5 = *param_4;
        *param_1 = 0;
        if (uVar6 < uVar5) {
LAB_00524d5c:
          iVar9 = *param_2;
          goto LAB_00524c34;
        }
      }
    }
  }
  else {
    if ((int)pcVar7 < (int)pcVar3) {
      pcVar7 = pcVar3;
    }
    pcVar3 = (char *)0x0;
  }
LAB_00524af4:
  if ((local_50 == 0) || (iVar9 = doapr_outch(param_1,param_2,param_3,param_4,local_50), iVar9 != 0)
     ) {
    cVar10 = *local_60;
joined_r0x00524b04:
    if (cVar10 != '\0') {
      do {
        uVar6 = *param_3;
        uVar5 = *param_4;
        if ((param_2 == (int *)0x0) || (uVar6 != uVar5)) {
LAB_00524b20:
          if (uVar6 < uVar5) {
            iVar9 = *param_1;
            if (iVar9 == 0) goto LAB_00524dd8;
            *param_3 = uVar6 + 1;
            *(char *)(iVar9 + uVar6) = cVar10;
          }
        }
        else {
          uVar5 = uVar6 + 0x400;
          if (0x7ffffbff < uVar6) goto LAB_00524cc0;
          iVar9 = *param_2;
          *param_4 = uVar5;
          if (iVar9 != 0) {
            iVar9 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(iVar9,uVar5,"b_print.c",0x2fd);
            if (iVar9 != 0) {
              uVar6 = *param_3;
              uVar5 = *param_4;
              *param_2 = iVar9;
              goto LAB_00524b20;
            }
            goto LAB_00524cc0;
          }
          iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5,"b_print.c",0x2f3);
          *param_2 = iVar9;
          if (iVar9 == 0) goto LAB_00524cc0;
          uVar6 = *param_3;
          if (uVar6 != 0) {
            (*(code *)PTR_memcpy_006a9aec)(iVar9,*param_1);
            uVar6 = *param_3;
          }
          uVar5 = *param_4;
          *param_1 = 0;
          if (uVar6 < uVar5) goto LAB_00524dd8;
        }
        local_60 = local_60 + 1;
        cVar10 = *local_60;
        if (cVar10 == '\0') break;
      } while( true );
    }
    goto joined_r0x00524e00;
  }
LAB_00524cc0:
  uVar4 = 0;
  goto LAB_00524cc4;
LAB_00524dd8:
  iVar9 = *param_2;
  *param_3 = uVar6 + 1;
  *(char *)(iVar9 + uVar6) = cVar10;
  local_60 = local_60 + 1;
  cVar10 = *local_60;
  goto joined_r0x00524b04;
joined_r0x00524e00:
  if (pcVar7 == (char *)0x0) goto LAB_00524e34;
  iVar9 = doapr_outch(param_1,param_2,param_3,param_4,0x30);
  if (iVar9 == 0) goto LAB_00524cc0;
  pcVar7 = pcVar7 + -1;
  goto joined_r0x00524e00;
LAB_00524e34:
  if (iVar8 == 0) {
LAB_00524ea0:
    do {
      if (pcVar3 == (char *)0x0) goto LAB_00524ec8;
      iVar9 = doapr_outch_constprop_0(param_1,param_2,param_3,param_4);
      if (iVar9 == 0) goto LAB_00524cc0;
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  iVar8 = iVar8 + -1;
  pcVar7 = pcVar2 + iVar8;
  while (iVar9 = doapr_outch(param_1,param_2,param_3,param_4,(int)*pcVar7), iVar9 != 0) {
    pcVar7 = pcVar7 + -1;
    if (iVar8 == 0) goto LAB_00524ea0;
    iVar8 = iVar8 + -1;
  }
  uVar4 = 0;
LAB_00524cc4:
  if (local_2c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00524f00:
  pcVar3 = (char *)-(int)pcVar3;
  goto LAB_00524af4;
LAB_00524ec8:
  uVar4 = 1;
  goto LAB_00524cc4;
}

