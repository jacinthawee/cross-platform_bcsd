
void __regparm3
fmtint_constprop_3(int *param_1_00,uint *param_2_00,uint *param_3_00,int param_1,int param_2,
                  int param_3,int param_4,int param_5,uint param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  bool bVar9;
  longlong lVar10;
  int local_68;
  char *local_4c;
  uint local_44;
  char local_3b [27];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar7 = 0;
  if (-1 < param_5) {
    iVar7 = param_5;
  }
  if ((param_6 & 0x40) == 0) {
    if (param_2 < 0) {
      bVar9 = param_1 != 0;
      param_1 = -param_1;
      local_44 = 1;
      cVar1 = '-';
      param_2 = -(param_2 + (uint)bVar9);
      goto LAB_0811be40;
    }
    if ((param_6 & 2) != 0) {
      local_44 = 1;
      cVar1 = '+';
      goto LAB_0811be40;
    }
    local_44 = param_6 & 4;
    if (local_44 != 0) {
      local_44 = 1;
      cVar1 = ' ';
      goto LAB_0811be40;
    }
  }
  else {
    local_44 = 0;
  }
  cVar1 = '\0';
LAB_0811be40:
  local_4c = "";
  if ((((param_6 & 8) != 0) && (local_4c = "0", param_3 != 8)) && (local_4c = "", param_3 == 0x10))
  {
    local_4c = "0x";
  }
  local_68 = 0;
  pcVar4 = "0123456789abcdef";
  iVar8 = local_68;
  lVar10 = CONCAT44(param_2,param_1);
  if ((param_6 & 0x20) != 0) {
    pcVar4 = "0123456789ABCDEF";
    lVar10 = CONCAT44(param_2,param_1);
  }
  do {
    local_68 = iVar8;
    iVar8 = local_68 + 1;
    iVar5 = __umoddi3(lVar10,param_3,0);
    local_3b[local_68 + 1] = pcVar4[iVar5];
    lVar10 = __udivdi3(lVar10,param_3,0);
  } while (lVar10 != 0 && iVar8 < 0x1a);
  if (iVar8 == 0x1a) {
    iVar8 = local_68;
  }
  local_3b[iVar8 + 1] = '\0';
  iVar5 = iVar7 - iVar8;
  sVar6 = strlen(local_4c);
  if (iVar7 <= iVar8) {
    iVar7 = iVar8;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  iVar7 = ((param_4 - iVar7) - local_44) - sVar6;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  if ((param_6 & 0x10) == 0) {
    if ((param_6 & 1) == 0) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        uVar2 = *param_2_00;
        if (uVar2 < *param_3_00) {
          iVar3 = *param_1_00;
          if (iVar3 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          *param_2_00 = uVar2 + 1;
          *(undefined *)(iVar3 + uVar2) = 0x20;
        }
      }
    }
    else {
      iVar7 = -iVar7;
    }
  }
  else {
    if (iVar5 < iVar7) {
      iVar5 = iVar7;
    }
    iVar7 = 0;
  }
  if ((cVar1 != '\0') && (uVar2 = *param_2_00, uVar2 < *param_3_00)) {
    iVar3 = *param_1_00;
    if (iVar3 == 0) {
code_r0x0811bfc1:
      do {
        invalidInstructionException();
      } while( true );
    }
    *param_2_00 = uVar2 + 1;
    *(char *)(iVar3 + uVar2) = cVar1;
  }
  cVar1 = *local_4c;
  do {
    if (cVar1 == '\0') {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        uVar2 = *param_2_00;
        if (uVar2 < *param_3_00) {
          iVar3 = *param_1_00;
          if (iVar3 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          *param_2_00 = uVar2 + 1;
          *(undefined *)(iVar3 + uVar2) = 0x30;
        }
      }
      while (iVar5 = iVar8, iVar5 != 0) {
        uVar2 = *param_2_00;
        iVar8 = iVar5 + -1;
        if (uVar2 < *param_3_00) {
          iVar3 = *param_1_00;
          if (iVar3 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          cVar1 = local_3b[iVar5];
          *param_2_00 = uVar2 + 1;
          *(char *)(iVar3 + uVar2) = cVar1;
        }
      }
      for (; iVar7 != 0; iVar7 = iVar7 + 1) {
        uVar2 = *param_2_00;
        if (uVar2 < *param_3_00) {
          iVar8 = *param_1_00;
          if (iVar8 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          *param_2_00 = uVar2 + 1;
          *(undefined *)(iVar8 + uVar2) = 0x20;
        }
      }
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    uVar2 = *param_2_00;
    if (uVar2 < *param_3_00) {
      iVar3 = *param_1_00;
      if (iVar3 == 0) goto code_r0x0811bfc1;
      *param_2_00 = uVar2 + 1;
      *(char *)(iVar3 + uVar2) = cVar1;
    }
    local_4c = local_4c + 1;
    cVar1 = *local_4c;
  } while( true );
}

