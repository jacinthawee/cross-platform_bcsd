
undefined4 __regparm3
ssl_cipher_process_rulestr(byte *param_1_00,int **param_2,int **param_3,int **param_1)

{
  byte bVar1;
  char *__s2;
  uint uVar2;
  int **ppiVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  size_t __n;
  int *piVar14;
  byte *__s1;
  byte *pbVar15;
  bool bVar16;
  byte bVar17;
  int *local_64;
  int local_60;
  uint local_5c;
  int *local_58;
  int *local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  
  bVar17 = 0;
  uVar6 = (uint)*param_1_00;
  local_3c = 1;
LAB_080c576f:
  cVar5 = (char)uVar6;
  if (cVar5 == '\0') {
    return local_3c;
  }
  if (cVar5 == '-') {
    param_1_00 = param_1_00 + 1;
    local_60 = 3;
  }
  else if (cVar5 == '+') {
    param_1_00 = param_1_00 + 1;
    local_60 = 4;
  }
  else if (cVar5 == '!') {
    param_1_00 = param_1_00 + 1;
    local_60 = 2;
  }
  else if (cVar5 == '@') {
    param_1_00 = param_1_00 + 1;
    local_60 = 5;
  }
  else {
    if ((((cVar5 == ':') || (cVar5 == ' ')) || (cVar5 == ';')) || (cVar5 == ',')) {
      uVar6 = (uint)param_1_00[1];
      param_1_00 = param_1_00 + 1;
      goto LAB_080c576f;
    }
    local_60 = 1;
  }
  local_5c = 0;
  local_40 = 0;
  local_48 = 0;
  local_4c = 0;
  local_50 = 0;
  local_44 = 0;
  __s1 = param_1_00;
LAB_080c57b6:
  bVar1 = *__s1;
  param_1_00 = __s1;
  while (((__n = (int)param_1_00 - (int)__s1, (byte)((bVar1 & 0xdf) + 0xbf) < 0x1a ||
          ((byte)(bVar1 - 0x30) < 10)) || ((byte)(bVar1 - 0x2d) < 2))) {
    param_1_00 = param_1_00 + 1;
    bVar1 = *param_1_00;
  }
  if (__n == 0) {
    param_1_00 = param_1_00 + 1;
    ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x4a8);
    if (local_60 != 5) {
      local_3c = 0;
      goto LAB_080c5875;
    }
    goto LAB_080c5c5f;
  }
  if (local_60 == 5) {
    bVar16 = __n == 8;
    if (!bVar16) goto LAB_080c5c5f;
    iVar7 = 8;
    pbVar15 = (byte *)"STRENGTH";
    goto code_r0x080c5c57;
  }
  if (bVar1 == 0x2b) {
    param_1_00 = param_1_00 + 1;
  }
  piVar8 = *param_1;
  ppiVar3 = param_1;
  if (piVar8 == (int *)0x0) goto LAB_080c5875;
  do {
    __s2 = (char *)piVar8[1];
    iVar7 = strncmp((char *)__s1,__s2,__n);
    if ((iVar7 == 0) && (__s2[__n] == '\0')) goto LAB_080c58c0;
    piVar8 = ppiVar3[1];
    ppiVar3 = ppiVar3 + 1;
  } while (piVar8 != (int *)0x0);
  bVar1 = *param_1_00;
  if (bVar1 == 0) {
    return local_3c;
  }
  while( true ) {
    uVar6 = (uint)bVar1;
    if (((byte)(uVar6 - 0x20) < 0x1c) && ((0xc001001U >> (uVar6 - 0x20 & 0x1f) & 1) != 0)) break;
    param_1_00 = param_1_00 + 1;
LAB_080c5875:
    bVar1 = *param_1_00;
    if (bVar1 == 0) {
      return local_3c;
    }
  }
  goto LAB_080c576f;
  while( true ) {
    iVar7 = iVar7 + -1;
    bVar16 = *__s1 == *pbVar15;
    __s1 = __s1 + (uint)bVar17 * -2 + 1;
    pbVar15 = pbVar15 + (uint)bVar17 * -2 + 1;
    if (!bVar16) break;
code_r0x080c5c57:
    if (iVar7 == 0) break;
  }
  if (bVar16) {
    iVar7 = ssl_cipher_strength_sort();
    uVar4 = 0;
    if (iVar7 != 0) {
      uVar4 = local_3c;
    }
  }
  else {
LAB_080c5c5f:
    ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x544);
    local_3c = 0;
    uVar4 = local_3c;
  }
  local_3c = uVar4;
  bVar1 = *param_1_00;
  while( true ) {
    if (bVar1 == 0) {
      return local_3c;
    }
    uVar6 = (uint)bVar1;
    if (((byte)(uVar6 - 0x20) < 0x1c) && ((0xc001001U >> (uVar6 - 0x20 & 0x1f) & 1) != 0)) break;
    param_1_00 = param_1_00 + 1;
    bVar1 = *param_1_00;
  }
  goto LAB_080c576f;
LAB_080c58c0:
  uVar6 = piVar8[3];
  uVar11 = local_44;
  if ((uVar6 != 0) &&
     ((uVar11 = uVar6, local_44 != 0 && (uVar11 = local_44 & uVar6, (local_44 & uVar6) == 0))))
  goto LAB_080c5875;
  local_44 = uVar11;
  uVar6 = piVar8[4];
  uVar11 = local_50;
  if ((uVar6 != 0) &&
     ((uVar11 = uVar6, local_50 != 0 && (uVar11 = local_50 & uVar6, (local_50 & uVar6) == 0))))
  goto LAB_080c5875;
  local_50 = uVar11;
  uVar6 = piVar8[5];
  uVar11 = local_4c;
  if ((uVar6 != 0) &&
     ((uVar11 = uVar6, local_4c != 0 && (uVar11 = local_4c & uVar6, (local_4c & uVar6) == 0))))
  goto LAB_080c5875;
  local_4c = uVar11;
  uVar6 = piVar8[6];
  uVar11 = local_48;
  if ((uVar6 != 0) &&
     ((uVar11 = uVar6, local_48 != 0 && (uVar11 = local_48 & uVar6, (local_48 & uVar6) == 0))))
  goto LAB_080c5875;
  local_48 = uVar11;
  uVar6 = piVar8[8];
  if ((uVar6 & 3) != 0) {
    if ((local_5c & 3) == 0) {
      local_5c = local_5c | uVar6 & 3;
    }
    else {
      local_5c = local_5c & (uVar6 | 0xfffffffc);
      if ((local_5c & 3) == 0) goto LAB_080c5875;
    }
  }
  if ((uVar6 & 0x1fc) != 0) {
    if ((local_5c & 0x1fc) == 0) {
      local_5c = local_5c | uVar6 & 0x1fc;
    }
    else {
      local_5c = local_5c & (uVar6 | 0xfffffe03);
      if ((local_5c & 0x1fc) == 0) goto LAB_080c5875;
    }
  }
  uVar11 = local_5c | 0x200;
  if ((uVar6 & 0x200) == 0) {
    uVar11 = local_5c;
  }
  uVar6 = local_40;
  if ((((*piVar8 == 0) && (uVar2 = piVar8[7], uVar2 != 0)) && (uVar6 = uVar2, local_40 != 0)) &&
     (uVar6 = local_40 & uVar2, (local_40 & uVar2) == 0)) goto LAB_080c5875;
  local_40 = uVar6;
  __s1 = param_1_00;
  local_5c = uVar11;
  if (bVar1 != 0x2b) goto LAB_080c5a46;
  goto LAB_080c57b6;
LAB_080c5a46:
  if (local_60 == 3) {
    local_64 = *param_2;
    piVar8 = *param_3;
    local_54 = piVar8;
    local_58 = local_64;
  }
  else {
    local_64 = *param_3;
    piVar8 = *param_2;
    local_54 = local_64;
    local_58 = piVar8;
  }
  piVar12 = (int *)0x0;
  while ((piVar9 = piVar8, piVar9 != (int *)0x0 && (piVar12 != local_64))) {
    piVar10 = (int *)piVar9[4];
    piVar13 = (int *)piVar9[3];
    iVar7 = *piVar9;
    piVar8 = piVar10;
    if (local_60 != 3) {
      piVar8 = piVar13;
    }
    piVar12 = piVar9;
    if ((((((local_44 == 0) || ((*(uint *)(iVar7 + 0xc) & local_44) != 0)) &&
          ((local_50 == 0 || ((*(uint *)(iVar7 + 0x10) & local_50) != 0)))) &&
         ((local_4c == 0 || ((*(uint *)(iVar7 + 0x14) & local_4c) != 0)))) &&
        (((local_48 == 0 || ((*(uint *)(iVar7 + 0x18) & local_48) != 0)) &&
         ((((local_40 == 0 || ((*(uint *)(iVar7 + 0x1c) & local_40) != 0)) &&
           (((uVar11 & 3) == 0 || ((uVar11 & *(uint *)(iVar7 + 0x20) & 3) != 0)))) &&
          (((uVar11 & 0x1fc) == 0 || ((uVar11 & *(uint *)(iVar7 + 0x20) & 0x1fc) != 0)))))))) &&
       (((uVar11 & 0x200) == 0 || ((*(byte *)(iVar7 + 0x21) & 2) != 0)))) {
      if (local_60 == 1) {
        if (piVar9[1] == 0) {
          if (piVar9 != local_54) {
            if (piVar9 == local_58) {
              local_58 = piVar13;
            }
            if (piVar10 != (int *)0x0) {
              piVar10[3] = (int)piVar13;
              piVar13 = (int *)piVar9[3];
            }
            if (piVar13 != (int *)0x0) {
              piVar13[4] = (int)piVar10;
            }
            local_54[3] = (int)piVar9;
            piVar9[4] = (int)local_54;
            piVar9[3] = 0;
            local_54 = piVar9;
          }
          piVar9[1] = 1;
        }
      }
      else if (local_60 == 4) {
        if ((piVar9[1] != 0) && (piVar9 != local_54)) {
          if (piVar9 == local_58) {
            local_58 = piVar13;
          }
          if (piVar10 != (int *)0x0) {
            piVar10[3] = (int)piVar13;
            piVar13 = (int *)piVar9[3];
          }
          if (piVar13 != (int *)0x0) {
            piVar13[4] = (int)piVar10;
          }
          local_54[3] = (int)piVar9;
          piVar9[4] = (int)local_54;
          piVar9[3] = 0;
          local_54 = piVar9;
        }
      }
      else if (local_60 == 3) {
        if (piVar9[1] != 0) {
          if (piVar9 != local_58) {
            if (piVar9 == local_54) {
              local_54 = piVar10;
            }
            if (piVar13 != (int *)0x0) {
              piVar13[4] = (int)piVar10;
              piVar10 = (int *)piVar9[4];
            }
            if (piVar10 != (int *)0x0) {
              piVar10[3] = (int)piVar13;
            }
            local_58[4] = (int)piVar9;
            piVar9[3] = (int)local_58;
            piVar9[4] = 0;
            local_58 = piVar9;
          }
          piVar9[1] = 0;
        }
      }
      else {
        piVar14 = piVar13;
        if (piVar9 != local_58) {
          piVar10[3] = (int)piVar13;
          piVar13 = local_58;
          piVar14 = (int *)piVar9[3];
        }
        piVar9[1] = 0;
        if (piVar9 == local_54) {
          local_54 = piVar10;
        }
        if (piVar14 != (int *)0x0) {
          piVar14[4] = (int)piVar10;
          piVar10 = (int *)piVar9[4];
        }
        if (piVar10 != (int *)0x0) {
          piVar10[3] = (int)piVar14;
        }
        piVar9[3] = 0;
        piVar9[4] = 0;
        local_58 = piVar13;
      }
    }
  }
  *param_2 = local_58;
  *param_3 = local_54;
  uVar6 = (uint)*param_1_00;
  if (*param_1_00 == 0) {
    return local_3c;
  }
  goto LAB_080c576f;
}

