
size_t ssl_cipher_process_rulestr(byte *param_1,int **param_2,int **param_3,int **param_4)

{
  int **ppiVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char *__s2;
  int *piVar12;
  int *piVar13;
  byte *__s1;
  size_t __n;
  int *piVar14;
  int *piVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  int *local_5c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  size_t local_38;
  uint local_34;
  
  bVar3 = *param_1;
  local_38 = 1;
joined_r0x000650c4:
  do {
    if (bVar3 == 0) {
      return local_38;
    }
    if (bVar3 == 0x2d) {
      param_1 = param_1 + 1;
      iVar10 = 3;
      goto LAB_00065114;
    }
    if (bVar3 == 0x2b) {
      param_1 = param_1 + 1;
      iVar10 = 4;
      goto LAB_00065114;
    }
    if (bVar3 == 0x21) {
      param_1 = param_1 + 1;
      iVar10 = 2;
      goto LAB_00065114;
    }
    if (bVar3 == 0x40) {
      param_1 = param_1 + 1;
      iVar10 = 5;
      goto LAB_00065114;
    }
LAB_000650f6:
    if (bVar3 == 0x3a || bVar3 == 0x20) break;
    iVar10 = 1;
LAB_00065114:
    if (bVar3 == 0x3b || bVar3 == 0x2c) break;
    uVar4 = 0;
    local_34 = 0;
    local_48 = 0;
    local_40 = 0;
    local_3c = 0;
    local_44 = 0;
    __s1 = param_1;
LAB_00065132:
    bVar3 = *__s1;
    param_1 = __s1;
    while( true ) {
      uVar9 = (uint)bVar3;
      uVar6 = uVar9 - 0x30;
      uVar11 = (uVar9 & 0xffffffdf) - 0x41;
      bVar18 = 8 < uVar6;
      bVar16 = uVar6 == 9;
      if (9 < uVar6) {
        bVar18 = 0x18 < uVar11;
        bVar16 = uVar11 == 0x19;
      }
      __n = (int)param_1 - (int)__s1;
      if ((bVar18 && !bVar16) && (1 < uVar9 - 0x2d)) break;
      param_1 = param_1 + 1;
      bVar3 = *param_1;
    }
    if (__n == 0) {
      ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x493);
      param_1 = param_1 + 1;
      local_38 = __n;
      if (iVar10 == 5) {
LAB_000653cc:
        ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x52c);
LAB_000653e6:
        local_38 = 0;
LAB_000653ea:
        bVar3 = *param_1;
        goto joined_r0x000653f0;
      }
LAB_000651a0:
      bVar3 = *param_1;
      if (bVar3 == 0) {
        return local_38;
      }
      bVar16 = 0x1f < bVar3;
      if (bVar3 != 0x20) {
        bVar16 = bVar3 != 0x3a;
      }
      if (!bVar16 || (bVar3 == 0x20 || bVar3 == 0x3b)) goto joined_r0x000650c4;
      while (bVar3 != 0x2c) {
        param_1 = param_1 + 1;
        bVar3 = *param_1;
        if (bVar3 == 0) {
          return local_38;
        }
        bVar16 = 0x1f < bVar3;
        if (bVar3 != 0x20) {
          bVar16 = bVar3 != 0x3a;
        }
        if (!bVar16 || (bVar3 == 0x20 || bVar3 == 0x3b)) goto joined_r0x000650c4;
      }
      goto LAB_000650f6;
    }
    if (iVar10 == 5) {
      if ((__n != 8) || (iVar10 = strncmp((char *)__s1,"STRENGTH",8), iVar10 != 0))
      goto LAB_000653cc;
      iVar10 = ssl_cipher_strength_sort(param_2,param_3);
      if (iVar10 == 0) goto LAB_000653e6;
      goto LAB_000653ea;
    }
    bVar16 = uVar9 == 0x2b;
    if (bVar16) {
      param_1 = param_1 + 1;
    }
    piVar13 = *param_4;
    ppiVar1 = param_4;
    while( true ) {
      if (piVar13 == (int *)0x0) goto LAB_000651a0;
      __s2 = (char *)piVar13[1];
      iVar5 = strncmp((char *)__s1,__s2,__n);
      if ((iVar5 == 0) && (__s2[__n] == '\0')) break;
      ppiVar1 = ppiVar1 + 1;
      piVar13 = *ppiVar1;
    }
    uVar9 = piVar13[3];
    uVar6 = local_44;
    if (((((uVar9 != 0) &&
          ((uVar6 = uVar9, local_44 != 0 && (uVar6 = local_44 & uVar9, (local_44 & uVar9) == 0))))
         || ((local_44 = uVar6, uVar9 = piVar13[4], uVar6 = local_3c, uVar9 != 0 &&
             ((uVar6 = uVar9, local_3c != 0 && (uVar6 = local_3c & uVar9, (local_3c & uVar9) == 0)))
             ))) ||
        ((local_3c = uVar6, uVar9 = piVar13[5], uVar6 = local_40, uVar9 != 0 &&
         ((uVar6 = uVar9, local_40 != 0 && (uVar6 = local_40 & uVar9, (local_40 & uVar9) == 0))))))
       || ((local_40 = uVar6, uVar9 = piVar13[6], uVar6 = local_48, uVar9 != 0 &&
           ((uVar6 = uVar9, local_48 != 0 && (uVar6 = local_48 & uVar9, (local_48 & uVar9) == 0)))))
       ) goto LAB_000651a0;
    local_48 = uVar6;
    uVar6 = piVar13[8];
    if ((uVar6 & 3) != 0) {
      if ((uVar4 & 3) == 0) {
        uVar4 = uVar4 | uVar6 & 3;
      }
      else {
        uVar4 = uVar4 & (uVar6 | 0xfffffffc);
        if ((uVar4 & 3) == 0) goto LAB_000651a0;
      }
    }
    if ((uVar6 & 0x1fc) != 0) {
      if ((uVar4 & 0x1fc) == 0) {
        uVar4 = uVar4 | uVar6 & 0x1fc;
      }
      else {
        uVar4 = uVar4 & (uVar6 | 0xfffffe03);
        if ((uVar4 & 0x1fc) == 0) goto LAB_000651a0;
      }
    }
    uVar6 = local_34;
    if ((((*piVar13 == 0) && (uVar9 = piVar13[7], uVar9 != 0)) && (uVar6 = uVar9, local_34 != 0)) &&
       (uVar6 = local_34 & uVar9, (local_34 & uVar9) == 0)) goto LAB_000651a0;
    local_34 = uVar6;
    __s1 = param_1;
    if (bVar16) goto LAB_00065132;
    if (iVar10 == 3) {
      piVar14 = *param_2;
      piVar13 = *param_3;
      piVar15 = piVar14;
      local_5c = piVar13;
    }
    else {
      piVar13 = *param_2;
      piVar14 = *param_3;
      piVar15 = piVar13;
      local_5c = piVar14;
    }
    if (piVar13 != (int *)0x0 && piVar13 != piVar14) {
      do {
        piVar8 = (int *)piVar13[3];
        piVar7 = (int *)piVar13[4];
        iVar5 = *piVar13;
        piVar12 = piVar8;
        if (iVar10 == 3 || bVar16) {
          piVar12 = piVar7;
        }
        if ((((((local_44 == 0) || ((local_44 & *(uint *)(iVar5 + 0xc)) != 0)) &&
              ((local_3c == 0 || ((local_3c & *(uint *)(iVar5 + 0x10)) != 0)))) &&
             ((local_40 == 0 || ((local_40 & *(uint *)(iVar5 + 0x14)) != 0)))) &&
            ((local_48 == 0 || ((local_48 & *(uint *)(iVar5 + 0x18)) != 0)))) &&
           ((((local_34 == 0 || ((local_34 & *(uint *)(iVar5 + 0x1c)) != 0)) &&
             (((uVar4 & 3) == 0 || ((uVar4 & *(uint *)(iVar5 + 0x20) & 3) != 0)))) &&
            (((uVar4 & 0x1fc) == 0 || ((uVar4 & *(uint *)(iVar5 + 0x20) & 0x1fc) != 0)))))) {
          if (iVar10 == 1) {
            if (piVar13[1] == 0) {
              if (piVar13 != local_5c) {
                if (piVar13 == piVar15) {
                  piVar15 = piVar8;
                }
                if (piVar7 != (int *)0x0) {
                  piVar7[3] = (int)piVar8;
                  piVar8 = (int *)piVar13[3];
                }
                if (piVar8 != (int *)0x0) {
                  piVar8[4] = (int)piVar7;
                }
                local_5c[3] = (int)piVar13;
                piVar13[4] = (int)local_5c;
                piVar13[3] = 0;
                local_5c = piVar13;
              }
              piVar13[1] = 1;
            }
          }
          else if (iVar10 == 4) {
            if ((piVar13[1] != 0) && (piVar13 != local_5c)) {
              if (piVar13 == piVar15) {
                piVar15 = piVar8;
              }
              if (piVar7 != (int *)0x0) {
                piVar7[3] = (int)piVar8;
                piVar8 = (int *)piVar13[3];
              }
              if (piVar8 != (int *)0x0) {
                piVar8[4] = (int)piVar7;
              }
              local_5c[3] = (int)piVar13;
              piVar13[4] = (int)local_5c;
              piVar13[3] = 0;
              local_5c = piVar13;
            }
          }
          else if (iVar10 == 3) {
            if (piVar13[1] != 0) {
              if (piVar13 != piVar15) {
                if (piVar13 == local_5c) {
                  local_5c = piVar7;
                }
                if (piVar8 != (int *)0x0) {
                  piVar8[4] = (int)piVar7;
                  piVar7 = (int *)piVar13[4];
                }
                if (piVar7 != (int *)0x0) {
                  piVar7[3] = (int)piVar8;
                }
                piVar15[4] = (int)piVar13;
                piVar13[3] = (int)piVar15;
                piVar13[4] = 0;
                piVar15 = piVar13;
              }
              piVar13[1] = 0;
            }
          }
          else {
            piVar2 = piVar8;
            if (piVar13 != piVar15) {
              piVar7[3] = (int)piVar8;
              piVar8 = piVar15;
              piVar2 = (int *)piVar13[3];
            }
            if (piVar13 == local_5c) {
              local_5c = piVar7;
            }
            piVar13[1] = 0;
            if (piVar2 != (int *)0x0) {
              piVar2[4] = (int)piVar7;
              piVar7 = (int *)piVar13[4];
            }
            if (piVar7 != (int *)0x0) {
              piVar7[3] = (int)piVar2;
            }
            piVar13[3] = 0;
            piVar13[4] = 0;
            piVar15 = piVar8;
          }
        }
        bVar17 = piVar13 != (int *)0x0;
        bVar18 = piVar13 != piVar14;
        piVar13 = piVar12;
      } while (bVar17 && bVar18);
    }
    *param_2 = piVar15;
    *param_3 = local_5c;
    bVar3 = *param_1;
    if (bVar3 == 0) {
      return local_38;
    }
  } while( true );
  bVar3 = param_1[1];
  param_1 = param_1 + 1;
  goto joined_r0x000650c4;
joined_r0x000653f0:
  if (bVar3 == 0) {
    return local_38;
  }
  bVar16 = 0x1f < bVar3;
  if (bVar3 != 0x20) {
    bVar16 = bVar3 != 0x3a;
  }
  if (!bVar16 || (bVar3 == 0x20 || bVar3 == 0x3b)) goto joined_r0x000650c4;
  if (bVar3 == 0x2c) goto LAB_000650f6;
  param_1 = param_1 + 1;
  bVar3 = *param_1;
  goto joined_r0x000653f0;
}

