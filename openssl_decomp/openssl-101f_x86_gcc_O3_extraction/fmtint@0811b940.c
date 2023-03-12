
void __regparm3
fmtint(void **param_1_00,void **param_2_00,uint *param_3_00,uint *param_1,int param_2,int param_3,
      int param_4,int param_5,int param_6,uint param_7)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  void *pvVar5;
  uint num;
  int iVar6;
  uint __n;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  longlong lVar9;
  int local_6c;
  int local_68;
  int local_5c;
  char *local_58;
  int local_50;
  uint local_4c;
  char local_3b [27];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar8 = 0;
  if (-1 < param_6) {
    iVar8 = param_6;
  }
  local_6c = param_2;
  local_68 = param_3;
  if ((param_7 & 0x40) == 0) {
    if (param_3 < 0) {
      local_6c = -param_2;
      local_4c = 1;
      local_50 = 0x2d;
      local_68 = -(param_3 + (uint)(param_2 != 0));
      goto LAB_0811b9e0;
    }
    if ((param_7 & 2) != 0) {
      local_4c = 1;
      local_50 = 0x2b;
      goto LAB_0811b9e0;
    }
    local_4c = param_7 & 4;
    if (local_4c != 0) {
      local_4c = 1;
      local_50 = 0x20;
      goto LAB_0811b9e0;
    }
  }
  else {
    local_4c = 0;
  }
  local_50 = 0;
LAB_0811b9e0:
  lVar9 = CONCAT44(local_68,local_6c);
  local_58 = "";
  if ((((param_7 & 8) != 0) && (local_58 = "0", param_4 != 8)) && (local_58 = "", param_4 == 0x10))
  {
    local_58 = "0x";
  }
  pcVar2 = "0123456789abcdef";
  if ((param_7 & 0x20) != 0) {
    pcVar2 = "0123456789ABCDEF";
  }
  iVar7 = 0;
  do {
    iVar6 = iVar7;
    iVar7 = iVar6 + 1;
    iVar3 = __umoddi3(lVar9,param_4,0);
    local_3b[iVar6 + 1] = pcVar2[iVar3];
    lVar9 = __udivdi3(lVar9,param_4,0);
  } while (lVar9 != 0 && iVar7 < 0x1a);
  if (iVar7 == 0x1a) {
    iVar7 = iVar6;
  }
  iVar3 = iVar8 - iVar7;
  local_3b[iVar7 + 1] = '\0';
  sVar4 = strlen(local_58);
  if (iVar8 <= iVar7) {
    iVar8 = iVar7;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar6 = ((param_5 - iVar8) - local_4c) - sVar4;
  iVar8 = 0;
  if (-1 < iVar6) {
    iVar8 = iVar6;
  }
  if ((param_7 & 0x10) == 0) {
    local_5c = iVar8;
    if ((param_7 & 1) == 0) {
      for (; iVar8 = iVar3, local_5c != 0; local_5c = local_5c + -1) {
        doapr_outch_constprop_5(param_1);
      }
    }
    else {
      local_5c = -iVar8;
      iVar8 = iVar3;
    }
  }
  else {
    local_5c = 0;
    if (iVar8 <= iVar3) {
      iVar8 = iVar3;
    }
  }
  if (local_50 != 0) {
    doapr_outch(param_1,local_50);
  }
  cVar1 = *local_58;
  while (cVar1 != '\0') {
    local_58 = local_58 + 1;
    doapr_outch(param_1,(int)cVar1);
    cVar1 = *local_58;
  }
  for (; iVar8 != 0; iVar8 = iVar8 + -1) {
    doapr_outch(param_1,0x30);
  }
joined_r0x0811bbb9:
  if (iVar7 == 0) {
    for (; local_5c != 0; local_5c = local_5c + 1) {
      doapr_outch_constprop_5(param_1);
    }
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  iVar8 = iVar7 + -1;
  __n = *param_3_00;
  cVar1 = local_3b[iVar7];
  iVar7 = iVar8;
  if (param_2_00 == (void **)0x0) goto LAB_0811bce0;
  while (num = *param_1, num <= __n) {
    while (pvVar5 = *param_2_00, pvVar5 != (void *)0x0) {
      *param_1 = num + 0x400;
      pvVar5 = CRYPTO_realloc(pvVar5,num + 0x400,"b_print.c",0x2ed);
      __n = *param_3_00;
      *param_2_00 = pvVar5;
      num = *param_1;
      if (__n < num) goto LAB_0811bc24;
    }
    if (num == 0) {
      *param_1 = 0x400;
      num = 0x400;
    }
    pvVar5 = CRYPTO_malloc(num,"b_print.c",0x2e5);
    __n = *param_3_00;
    *param_2_00 = pvVar5;
    if (__n != 0) {
      memcpy(pvVar5,*param_1_00,__n);
      __n = *param_3_00;
    }
    *param_1_00 = (void *)0x0;
  }
  goto LAB_0811bc24;
LAB_0811bce0:
  if (__n < *param_1) {
LAB_0811bc24:
    pvVar5 = *param_1_00;
    if (pvVar5 == (void *)0x0) {
      pvVar5 = *param_2_00;
    }
    *param_3_00 = __n + 1;
    *(char *)((int)pvVar5 + __n) = cVar1;
  }
  goto joined_r0x0811bbb9;
}

