
undefined4 __regparm3
ssl_cipher_process_rulestr(byte *param_1_00,int **param_2,int **param_3,int **param_1)

{
  byte bVar1;
  char *__s2;
  uint uVar2;
  int **ppiVar3;
  int *piVar4;
  undefined4 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  size_t __n;
  int *piVar12;
  byte *__s1;
  int *piVar13;
  byte *pbVar14;
  bool bVar15;
  byte bVar16;
  int *local_60;
  int local_5c;
  int *local_58;
  uint local_54;
  int *local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  
  bVar16 = 0;
  uVar7 = (uint)*param_1_00;
  local_38 = 1;
LAB_080c7baf:
  cVar6 = (char)uVar7;
  if (cVar6 == '\0') {
    return local_38;
  }
  if (cVar6 == '-') {
    param_1_00 = param_1_00 + 1;
    local_5c = 3;
  }
  else if (cVar6 == '+') {
    param_1_00 = param_1_00 + 1;
    local_5c = 4;
  }
  else if (cVar6 == '!') {
    param_1_00 = param_1_00 + 1;
    local_5c = 2;
  }
  else if (cVar6 == '@') {
    param_1_00 = param_1_00 + 1;
    local_5c = 5;
  }
  else {
    if ((((cVar6 == ':') || (cVar6 == ' ')) || (cVar6 == ';')) || (cVar6 == ',')) {
      uVar7 = (uint)param_1_00[1];
      param_1_00 = param_1_00 + 1;
      goto LAB_080c7baf;
    }
    local_5c = 1;
  }
  local_54 = 0;
  local_3c = 0;
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  local_40 = 0;
  __s1 = param_1_00;
LAB_080c7bf6:
  bVar1 = *__s1;
  param_1_00 = __s1;
  while (((__n = (int)param_1_00 - (int)__s1, (byte)((bVar1 & 0xdf) + 0xbf) < 0x1a ||
          ((byte)(bVar1 - 0x30) < 10)) || ((byte)(bVar1 - 0x2d) < 2))) {
    param_1_00 = param_1_00 + 1;
    bVar1 = *param_1_00;
  }
  if (__n == 0) {
    param_1_00 = param_1_00 + 1;
    ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x493);
    if (local_5c != 5) {
      local_38 = 0;
      goto LAB_080c7cb5;
    }
    goto LAB_080c8058;
  }
  if (local_5c == 5) {
    bVar15 = __n == 8;
    if (!bVar15) goto LAB_080c8058;
    iVar8 = 8;
    pbVar14 = (byte *)"STRENGTH";
    goto code_r0x080c8050;
  }
  if (bVar1 == 0x2b) {
    param_1_00 = param_1_00 + 1;
  }
  piVar10 = *param_1;
  ppiVar3 = param_1;
  if (piVar10 == (int *)0x0) goto LAB_080c7cb5;
  do {
    __s2 = (char *)piVar10[1];
    iVar8 = strncmp((char *)__s1,__s2,__n);
    if ((iVar8 == 0) && (__s2[__n] == '\0')) goto LAB_080c7d00;
    piVar10 = ppiVar3[1];
    ppiVar3 = ppiVar3 + 1;
  } while (piVar10 != (int *)0x0);
  bVar1 = *param_1_00;
  while( true ) {
    if (bVar1 == 0) {
      return local_38;
    }
    uVar7 = (uint)bVar1;
    if (((byte)(uVar7 - 0x20) < 0x1c) && ((0xc001001U >> (uVar7 - 0x20 & 0x1f) & 1) != 0)) break;
    param_1_00 = param_1_00 + 1;
LAB_080c7cb5:
    bVar1 = *param_1_00;
  }
  goto LAB_080c7baf;
  while( true ) {
    iVar8 = iVar8 + -1;
    bVar15 = *__s1 == *pbVar14;
    __s1 = __s1 + (uint)bVar16 * -2 + 1;
    pbVar14 = pbVar14 + (uint)bVar16 * -2 + 1;
    if (!bVar15) break;
code_r0x080c8050:
    if (iVar8 == 0) break;
  }
  if (bVar15) {
    iVar8 = ssl_cipher_strength_sort();
    uVar5 = 0;
    if (iVar8 != 0) {
      uVar5 = local_38;
    }
  }
  else {
LAB_080c8058:
    ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x52c);
    local_38 = 0;
    uVar5 = local_38;
  }
  local_38 = uVar5;
  bVar1 = *param_1_00;
  while( true ) {
    if (bVar1 == 0) {
      return local_38;
    }
    uVar7 = (uint)bVar1;
    if (((byte)(uVar7 - 0x20) < 0x1c) && ((0xc001001U >> (uVar7 - 0x20 & 0x1f) & 1) != 0)) break;
    param_1_00 = param_1_00 + 1;
    bVar1 = *param_1_00;
  }
  goto LAB_080c7baf;
LAB_080c7d00:
  uVar7 = piVar10[3];
  uVar2 = local_40;
  if ((uVar7 != 0) &&
     ((uVar2 = uVar7, local_40 != 0 && (uVar2 = local_40 & uVar7, (local_40 & uVar7) == 0))))
  goto LAB_080c7cb5;
  local_40 = uVar2;
  uVar7 = piVar10[4];
  uVar2 = local_4c;
  if ((uVar7 != 0) &&
     ((uVar2 = uVar7, local_4c != 0 && (uVar2 = local_4c & uVar7, (local_4c & uVar7) == 0))))
  goto LAB_080c7cb5;
  local_4c = uVar2;
  uVar7 = piVar10[5];
  uVar2 = local_48;
  if ((uVar7 != 0) &&
     ((uVar2 = uVar7, local_48 != 0 && (uVar2 = local_48 & uVar7, (local_48 & uVar7) == 0))))
  goto LAB_080c7cb5;
  local_48 = uVar2;
  uVar7 = piVar10[6];
  uVar2 = local_44;
  if ((uVar7 != 0) &&
     ((uVar2 = uVar7, local_44 != 0 && (uVar2 = local_44 & uVar7, (local_44 & uVar7) == 0))))
  goto LAB_080c7cb5;
  local_44 = uVar2;
  uVar7 = piVar10[8];
  if ((uVar7 & 3) != 0) {
    if ((local_54 & 3) == 0) {
      local_54 = local_54 | uVar7 & 3;
    }
    else {
      local_54 = local_54 & (uVar7 | 0xfffffffc);
      if ((local_54 & 3) == 0) goto LAB_080c7cb5;
    }
  }
  if ((uVar7 & 0x1fc) != 0) {
    if ((local_54 & 0x1fc) == 0) {
      local_54 = local_54 | uVar7 & 0x1fc;
    }
    else {
      local_54 = local_54 & (uVar7 | 0xfffffe03);
      if ((local_54 & 0x1fc) == 0) goto LAB_080c7cb5;
    }
  }
  uVar7 = local_3c;
  if ((((*piVar10 == 0) && (uVar2 = piVar10[7], uVar2 != 0)) && (uVar7 = uVar2, local_3c != 0)) &&
     (uVar7 = local_3c & uVar2, (local_3c & uVar2) == 0)) goto LAB_080c7cb5;
  local_3c = uVar7;
  __s1 = param_1_00;
  if (bVar1 != 0x2b) goto LAB_080c7e66;
  goto LAB_080c7bf6;
LAB_080c7e66:
  if (local_5c == 3) {
    local_60 = *param_2;
    piVar10 = *param_3;
    local_50 = piVar10;
    local_58 = local_60;
  }
  else {
    piVar10 = *param_2;
    local_60 = *param_3;
    local_50 = local_60;
    local_58 = piVar10;
  }
  piVar13 = piVar10;
  while ((piVar4 = piVar13, piVar10 != (int *)0x0 && (piVar10 != local_60))) {
    piVar9 = (int *)piVar4[4];
    piVar11 = (int *)piVar4[3];
    iVar8 = *piVar4;
    piVar13 = piVar9;
    if (local_5c != 3) {
      piVar13 = piVar11;
    }
    piVar10 = piVar4;
    if (((((local_40 == 0) || ((*(uint *)(iVar8 + 0xc) & local_40) != 0)) &&
         ((local_4c == 0 || ((*(uint *)(iVar8 + 0x10) & local_4c) != 0)))) &&
        ((local_48 == 0 || ((*(uint *)(iVar8 + 0x14) & local_48) != 0)))) &&
       (((local_44 == 0 || ((*(uint *)(iVar8 + 0x18) & local_44) != 0)) &&
        ((((local_3c == 0 || ((*(uint *)(iVar8 + 0x1c) & local_3c) != 0)) &&
          (((local_54 & 3) == 0 || ((local_54 & *(uint *)(iVar8 + 0x20) & 3) != 0)))) &&
         (((local_54 & 0x1fc) == 0 || ((local_54 & *(uint *)(iVar8 + 0x20) & 0x1fc) != 0)))))))) {
      if (local_5c == 1) {
        if (piVar4[1] == 0) {
          if (piVar4 != local_50) {
            if (piVar4 == local_58) {
              local_58 = piVar11;
            }
            if (piVar9 != (int *)0x0) {
              piVar9[3] = (int)piVar11;
              piVar11 = (int *)piVar4[3];
            }
            if (piVar11 != (int *)0x0) {
              piVar11[4] = (int)piVar9;
            }
            local_50[3] = (int)piVar4;
            piVar4[4] = (int)local_50;
            piVar4[3] = 0;
            local_50 = piVar4;
          }
          piVar4[1] = 1;
        }
      }
      else if (local_5c == 4) {
        if ((piVar4[1] != 0) && (piVar4 != local_50)) {
          if (piVar4 == local_58) {
            local_58 = piVar11;
          }
          if (piVar9 != (int *)0x0) {
            piVar9[3] = (int)piVar11;
            piVar11 = (int *)piVar4[3];
          }
          if (piVar11 != (int *)0x0) {
            piVar11[4] = (int)piVar9;
          }
          local_50[3] = (int)piVar4;
          piVar4[4] = (int)local_50;
          piVar4[3] = 0;
          local_50 = piVar4;
        }
      }
      else if (local_5c == 3) {
        if (piVar4[1] != 0) {
          if (piVar4 != local_58) {
            if (piVar4 == local_50) {
              local_50 = piVar9;
            }
            if (piVar11 != (int *)0x0) {
              piVar11[4] = (int)piVar9;
              piVar9 = (int *)piVar4[4];
            }
            if (piVar9 != (int *)0x0) {
              piVar9[3] = (int)piVar11;
            }
            local_58[4] = (int)piVar4;
            piVar4[3] = (int)local_58;
            piVar4[4] = 0;
            local_58 = piVar4;
          }
          piVar4[1] = 0;
        }
      }
      else {
        piVar12 = piVar11;
        if (piVar4 != local_58) {
          piVar9[3] = (int)piVar11;
          piVar11 = local_58;
          piVar12 = (int *)piVar4[3];
        }
        piVar4[1] = 0;
        if (piVar4 == local_50) {
          local_50 = piVar9;
        }
        if (piVar12 != (int *)0x0) {
          piVar12[4] = (int)piVar9;
          piVar9 = (int *)piVar4[4];
        }
        if (piVar9 != (int *)0x0) {
          piVar9[3] = (int)piVar12;
        }
        piVar4[3] = 0;
        piVar4[4] = 0;
        local_58 = piVar11;
      }
    }
  }
  *param_2 = local_58;
  *param_3 = local_50;
  uVar7 = (uint)*param_1_00;
  if (*param_1_00 == 0) {
    return local_38;
  }
  goto LAB_080c7baf;
}

