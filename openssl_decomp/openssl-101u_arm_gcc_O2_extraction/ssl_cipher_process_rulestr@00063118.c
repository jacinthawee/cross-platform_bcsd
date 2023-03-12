
size_t ssl_cipher_process_rulestr(byte *param_1,int **param_2,int **param_3,int **param_4)

{
  int **ppiVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  byte *__s1;
  char *__s2;
  size_t __n;
  byte bVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int *piVar15;
  bool bVar16;
  bool bVar17;
  int *local_5c;
  uint local_58;
  uint local_50;
  uint local_4c;
  uint local_48;
  size_t local_40;
  uint local_3c;
  
  bVar9 = *param_1;
  local_40 = 1;
joined_r0x0006312c:
  do {
    if (bVar9 == 0) {
      return local_40;
    }
    if (bVar9 == 0x2d) {
      param_1 = param_1 + 1;
      iVar12 = 3;
      goto LAB_00063186;
    }
    if (bVar9 == 0x2b) {
      param_1 = param_1 + 1;
      iVar12 = 4;
      goto LAB_00063186;
    }
    if (bVar9 == 0x21) {
      param_1 = param_1 + 1;
      iVar12 = 2;
      goto LAB_00063186;
    }
    if (bVar9 == 0x40) {
      param_1 = param_1 + 1;
      iVar12 = 5;
      goto LAB_00063186;
    }
LAB_00063166:
    if (bVar9 == 0x3a || bVar9 == 0x20) break;
    iVar12 = 1;
LAB_00063186:
    if (bVar9 == 0x3b || bVar9 == 0x2c) break;
    uVar10 = 0;
    local_3c = 0;
    local_50 = 0;
    local_48 = 0;
    local_4c = 0;
    local_58 = 0;
    __s1 = param_1;
LAB_000631a4:
    bVar9 = *__s1;
    param_1 = __s1;
    while( true ) {
      uVar8 = (uint)bVar9;
      uVar5 = uVar8 - 0x30;
      uVar13 = (uVar8 & 0xffffffdf) - 0x41;
      bVar17 = 8 < uVar5;
      bVar16 = uVar5 == 9;
      if (9 < uVar5) {
        bVar17 = 0x18 < uVar13;
        bVar16 = uVar13 == 0x19;
      }
      __n = (int)param_1 - (int)__s1;
      if ((bVar17 && !bVar16) && (1 < uVar8 - 0x2d)) break;
      param_1 = param_1 + 1;
      bVar9 = *param_1;
    }
    if (__n == 0) {
      ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x4a8);
      param_1 = param_1 + 1;
      local_40 = __n;
      if (iVar12 == 5) {
LAB_00063448:
        ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x544);
LAB_00063462:
        local_40 = 0;
LAB_00063466:
        bVar9 = *param_1;
        goto joined_r0x0006346c;
      }
LAB_0006321a:
      bVar9 = *param_1;
      if (bVar9 == 0) {
        return local_40;
      }
      bVar16 = 0x1f < bVar9;
      if (bVar9 != 0x20) {
        bVar16 = bVar9 != 0x3a;
      }
      if (!bVar16 || (bVar9 == 0x20 || bVar9 == 0x3b)) goto joined_r0x0006312c;
      while (bVar9 != 0x2c) {
        param_1 = param_1 + 1;
        bVar9 = *param_1;
        if (bVar9 == 0) {
          return local_40;
        }
        bVar16 = 0x1f < bVar9;
        if (bVar9 != 0x20) {
          bVar16 = bVar9 != 0x3a;
        }
        if (!bVar16 || (bVar9 == 0x20 || bVar9 == 0x3b)) goto joined_r0x0006312c;
      }
      goto LAB_00063166;
    }
    if (iVar12 == 5) {
      if ((__n != 8) || (iVar12 = strncmp((char *)__s1,"STRENGTH",8), iVar12 != 0))
      goto LAB_00063448;
      iVar12 = ssl_cipher_strength_sort(param_2,param_3);
      if (iVar12 == 0) goto LAB_00063462;
      goto LAB_00063466;
    }
    bVar16 = uVar8 == 0x2b;
    if (bVar16) {
      param_1 = param_1 + 1;
    }
    piVar11 = *param_4;
    ppiVar1 = param_4;
    while( true ) {
      if (piVar11 == (int *)0x0) goto LAB_0006321a;
      __s2 = (char *)piVar11[1];
      iVar3 = strncmp((char *)__s1,__s2,__n);
      if ((iVar3 == 0) && (__s2[__n] == '\0')) break;
      ppiVar1 = ppiVar1 + 1;
      piVar11 = *ppiVar1;
    }
    uVar8 = piVar11[3];
    uVar5 = local_58;
    if (((((uVar8 != 0) &&
          ((uVar5 = uVar8, local_58 != 0 && (uVar5 = local_58 & uVar8, (local_58 & uVar8) == 0))))
         || ((local_58 = uVar5, uVar8 = piVar11[4], uVar5 = local_4c, uVar8 != 0 &&
             ((uVar5 = uVar8, local_4c != 0 && (uVar5 = local_4c & uVar8, (local_4c & uVar8) == 0)))
             ))) ||
        ((local_4c = uVar5, uVar8 = piVar11[5], uVar5 = local_48, uVar8 != 0 &&
         ((uVar5 = uVar8, local_48 != 0 && (uVar5 = local_48 & uVar8, (local_48 & uVar8) == 0))))))
       || ((local_48 = uVar5, uVar8 = piVar11[6], uVar5 = local_50, uVar8 != 0 &&
           ((uVar5 = uVar8, local_50 != 0 && (uVar5 = local_50 & uVar8, (local_50 & uVar8) == 0)))))
       ) goto LAB_0006321a;
    local_50 = uVar5;
    uVar5 = piVar11[8];
    if ((uVar5 & 3) != 0) {
      if ((uVar10 & 3) == 0) {
        uVar10 = uVar10 | uVar5 & 3;
      }
      else {
        uVar10 = uVar10 & (uVar5 | 0xfffffffc);
        if ((uVar10 & 3) == 0) goto LAB_0006321a;
      }
    }
    if ((uVar5 & 0x1fc) != 0) {
      if ((uVar10 & 0x1fc) == 0) {
        uVar10 = uVar10 | uVar5 & 0x1fc;
      }
      else {
        uVar10 = uVar10 & (uVar5 | 0xfffffe03);
        if ((uVar10 & 0x1fc) == 0) goto LAB_0006321a;
      }
    }
    if ((int)(uVar5 << 0x16) < 0) {
      uVar10 = uVar10 | 0x200;
    }
    uVar5 = local_3c;
    if ((((*piVar11 == 0) && (uVar8 = piVar11[7], uVar8 != 0)) && (uVar5 = uVar8, local_3c != 0)) &&
       (uVar5 = local_3c & uVar8, (local_3c & uVar8) == 0)) goto LAB_0006321a;
    local_3c = uVar5;
    __s1 = param_1;
    if (bVar16) goto LAB_000631a4;
    if (iVar12 == 3) {
      piVar14 = *param_2;
      piVar11 = *param_3;
      piVar15 = piVar14;
      local_5c = piVar11;
    }
    else {
      piVar11 = *param_2;
      piVar14 = *param_3;
      piVar15 = piVar11;
      local_5c = piVar14;
    }
    if ((piVar14 != (int *)0x0) && (piVar11 != (int *)0x0)) {
      do {
        piVar7 = (int *)piVar11[3];
        piVar6 = (int *)piVar11[4];
        iVar3 = *piVar11;
        piVar4 = piVar7;
        if (iVar12 == 3 || bVar16) {
          piVar4 = piVar6;
        }
        if (((((((local_58 == 0) || ((local_58 & *(uint *)(iVar3 + 0xc)) != 0)) &&
               ((local_4c == 0 || ((local_4c & *(uint *)(iVar3 + 0x10)) != 0)))) &&
              ((local_48 == 0 || ((local_48 & *(uint *)(iVar3 + 0x14)) != 0)))) &&
             ((local_50 == 0 || ((local_50 & *(uint *)(iVar3 + 0x18)) != 0)))) &&
            ((((local_3c == 0 || ((local_3c & *(uint *)(iVar3 + 0x1c)) != 0)) &&
              (((uVar10 & 3) == 0 || ((uVar10 & *(uint *)(iVar3 + 0x20) & 3) != 0)))) &&
             (((uVar10 & 0x1fc) == 0 || ((uVar10 & *(uint *)(iVar3 + 0x20) & 0x1fc) != 0)))))) &&
           (((uVar10 & 0x200) == 0 || (*(int *)(iVar3 + 0x20) << 0x16 < 0)))) {
          if (iVar12 == 1) {
            if (piVar11[1] == 0) {
              if (piVar11 != local_5c) {
                if (piVar11 == piVar15) {
                  piVar15 = piVar7;
                }
                if (piVar6 != (int *)0x0) {
                  piVar6[3] = (int)piVar7;
                  piVar7 = (int *)piVar11[3];
                }
                if (piVar7 != (int *)0x0) {
                  piVar7[4] = (int)piVar6;
                }
                local_5c[3] = (int)piVar11;
                piVar11[4] = (int)local_5c;
                piVar11[3] = 0;
                local_5c = piVar11;
              }
              piVar11[1] = 1;
            }
          }
          else if (iVar12 == 4) {
            if ((piVar11[1] != 0) && (piVar11 != local_5c)) {
              if (piVar11 == piVar15) {
                piVar15 = piVar7;
              }
              if (piVar6 != (int *)0x0) {
                piVar6[3] = (int)piVar7;
                piVar7 = (int *)piVar11[3];
              }
              if (piVar7 != (int *)0x0) {
                piVar7[4] = (int)piVar6;
              }
              local_5c[3] = (int)piVar11;
              piVar11[4] = (int)local_5c;
              piVar11[3] = 0;
              local_5c = piVar11;
            }
          }
          else if (iVar12 == 3) {
            if (piVar11[1] != 0) {
              if (piVar11 != piVar15) {
                if (piVar11 == local_5c) {
                  local_5c = piVar6;
                }
                if (piVar7 != (int *)0x0) {
                  piVar7[4] = (int)piVar6;
                  piVar6 = (int *)piVar11[4];
                }
                if (piVar6 != (int *)0x0) {
                  piVar6[3] = (int)piVar7;
                }
                piVar15[4] = (int)piVar11;
                piVar11[3] = (int)piVar15;
                piVar11[4] = 0;
                piVar15 = piVar11;
              }
              piVar11[1] = 0;
            }
          }
          else {
            piVar2 = piVar7;
            if (piVar11 != piVar15) {
              piVar6[3] = (int)piVar7;
              piVar7 = piVar15;
              piVar2 = (int *)piVar11[3];
            }
            if (piVar11 == local_5c) {
              local_5c = piVar6;
            }
            piVar11[1] = 0;
            if (piVar2 != (int *)0x0) {
              piVar2[4] = (int)piVar6;
              piVar6 = (int *)piVar11[4];
            }
            if (piVar6 != (int *)0x0) {
              piVar6[3] = (int)piVar2;
            }
            piVar11[3] = 0;
            piVar11[4] = 0;
            piVar15 = piVar7;
          }
        }
      } while ((piVar14 != piVar11) && (piVar11 = piVar4, piVar4 != (int *)0x0));
    }
    *param_2 = piVar15;
    *param_3 = local_5c;
    bVar9 = *param_1;
    if (bVar9 == 0) {
      return local_40;
    }
  } while( true );
  bVar9 = param_1[1];
  param_1 = param_1 + 1;
  goto joined_r0x0006312c;
joined_r0x0006346c:
  if (bVar9 == 0) {
    return local_40;
  }
  bVar16 = 0x1f < bVar9;
  if (bVar9 != 0x20) {
    bVar16 = bVar9 != 0x3a;
  }
  if (!bVar16 || (bVar9 == 0x20 || bVar9 == 0x3b)) goto joined_r0x0006312c;
  if (bVar9 == 0x2c) goto LAB_00063166;
  param_1 = param_1 + 1;
  bVar9 = *param_1;
  goto joined_r0x0006346c;
}

