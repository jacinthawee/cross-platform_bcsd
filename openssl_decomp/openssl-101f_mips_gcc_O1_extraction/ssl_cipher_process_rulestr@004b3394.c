
undefined4 ssl_cipher_process_rulestr(char *param_1,int **param_2,int **param_3,int **param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int **ppiVar20;
  uint local_50;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  
  local_34 = 1;
  iVar3 = (int)*param_1;
LAB_004b3404:
  do {
    if (iVar3 == 0) {
      return local_34;
    }
    while (iVar3 != 0x2d) {
      if (iVar3 == 0x2b) {
        param_1 = param_1 + 1;
        iVar17 = 4;
LAB_004b3708:
        if ((0x1b < (iVar3 - 0x20U & 0xff)) || ((0x8001001U >> (iVar3 - 0x20U & 0x1f) & 1) == 0))
        goto LAB_004b3484;
        cVar2 = param_1[1];
      }
      else {
        if (iVar3 == 0x21) {
          param_1 = param_1 + 1;
          iVar17 = 2;
          goto LAB_004b3708;
        }
        if (iVar3 == 0x40) {
          param_1 = param_1 + 1;
          iVar17 = 5;
          goto LAB_004b3708;
        }
        if (iVar3 != 0x3a) {
          iVar17 = 1;
          goto LAB_004b3708;
        }
        cVar2 = param_1[1];
      }
      param_1 = param_1 + 1;
      iVar3 = (int)cVar2;
      if (iVar3 == 0) {
        return local_34;
      }
    }
    param_1 = param_1 + 1;
    iVar17 = 3;
LAB_004b3484:
    local_50 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    cVar2 = *param_1;
    pcVar16 = param_1;
LAB_004b34ac:
    while( true ) {
      uVar11 = (uint)cVar2;
      iVar3 = (int)param_1 - (int)pcVar16;
      if (((0x19 < (uVar11 & 0xdf) - 0x41) && (9 < (uVar11 & 0xff) - 0x30)) &&
         (1 < (uVar11 & 0xff) - 0x2d)) break;
      param_1 = param_1 + 1;
      cVar2 = *param_1;
    }
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xe6,0x118,"ssl_ciph.c",0x493);
      param_1 = param_1 + 1;
      if (iVar17 != 5) {
        local_34 = 0;
        goto LAB_004b3558;
      }
LAB_004b3990:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xe6,0x118,"ssl_ciph.c",0x52c);
      local_34 = 0;
LAB_004b39b8:
      iVar3 = (int)*param_1;
      if (iVar3 == 0) {
        return local_34;
      }
      while ((0x1b < (iVar3 - 0x20U & 0xff) || ((0xc001001U >> (iVar3 - 0x20U & 0x1f) & 1) == 0))) {
        param_1 = param_1 + 1;
        iVar3 = (int)*param_1;
        if (iVar3 == 0) {
          return local_34;
        }
      }
      goto LAB_004b3404;
    }
    if (iVar17 == 5) {
      if ((iVar3 != 8) ||
         (iVar3 = (*(code *)PTR_strncmp_006aaa7c)(pcVar16,"STRENGTH",8), iVar3 != 0))
      goto LAB_004b3990;
      iVar3 = ssl_cipher_strength_sort(param_2,param_3);
      if (iVar3 == 0) {
        local_34 = 0;
      }
      goto LAB_004b39b8;
    }
    if (uVar11 == 0x2b) {
      param_1 = param_1 + 1;
    }
    piVar19 = *param_4;
    ppiVar20 = param_4;
    while( true ) {
      if (piVar19 == (int *)0x0) goto LAB_004b3558;
      ppiVar20 = ppiVar20 + 1;
      iVar18 = piVar19[1];
      iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar16,iVar18,iVar3);
      if ((iVar4 == 0) && (*(char *)(iVar18 + iVar3) == '\0')) break;
      piVar19 = *ppiVar20;
    }
    uVar5 = piVar19[3];
    uVar8 = local_48;
    if ((((uVar5 == 0) ||
         ((uVar8 = uVar5, local_48 == 0 || (uVar8 = local_48 & uVar5, (local_48 & uVar5) != 0)))) &&
        ((local_48 = uVar8, uVar5 = piVar19[4], uVar8 = local_44, uVar5 == 0 ||
         ((uVar8 = uVar5, local_44 == 0 || (uVar8 = local_44 & uVar5, (local_44 & uVar5) != 0))))))
       && (((local_44 = uVar8, uVar5 = piVar19[5], uVar8 = local_40, uVar5 == 0 ||
            ((uVar8 = uVar5, local_40 == 0 || (uVar8 = local_40 & uVar5, (local_40 & uVar5) != 0))))
           && ((local_40 = uVar8, uVar5 = piVar19[6], uVar8 = local_3c, uVar5 == 0 ||
               ((uVar8 = uVar5, local_3c == 0 || (uVar8 = local_3c & uVar5, (local_3c & uVar5) != 0)
                ))))))) {
      local_3c = uVar8;
      uVar5 = piVar19[8];
      uVar8 = local_50;
      if (((uVar5 & 3) != 0) &&
         ((uVar8 = local_50 | uVar5 & 3, (local_50 & 3) != 0 &&
          (uVar8 = local_50 & (uVar5 | 0xfffffffc), (uVar8 & 3) == 0)))) goto LAB_004b3558;
      local_50 = uVar8;
      if ((uVar5 & 0x1fc) != 0) {
        if ((local_50 & 0x1fc) == 0) {
          local_50 = local_50 | uVar5 & 0x1fc;
        }
        else {
          local_50 = local_50 & (uVar5 | 0xfffffe03);
          if ((local_50 & 0x1fc) == 0) goto LAB_004b3558;
        }
      }
      uVar8 = local_38;
      if ((((*piVar19 == 0) && (uVar5 = piVar19[7], uVar5 != 0)) && (uVar8 = uVar5, local_38 != 0))
         && (uVar8 = local_38 & uVar5, (local_38 & uVar5) == 0)) goto LAB_004b3558;
      local_38 = uVar8;
      if (uVar11 != 0x2b) break;
      cVar2 = *param_1;
      pcVar16 = param_1;
      goto LAB_004b34ac;
    }
LAB_004b3558:
    iVar3 = (int)*param_1;
    if (iVar3 == 0) {
      return local_34;
    }
    while ((0x1b < (iVar3 - 0x20U & 0xff) || ((0xc001001U >> (iVar3 - 0x20U & 0x1f) & 1) == 0))) {
      param_1 = param_1 + 1;
      iVar3 = (int)*param_1;
      if (iVar3 == 0) {
        return local_34;
      }
    }
  } while( true );
  bVar1 = iVar17 == 3;
  if (bVar1) {
    piVar14 = *param_2;
    piVar6 = *param_3;
    piVar19 = piVar6;
    piVar13 = piVar14;
  }
  else {
    piVar6 = *param_2;
    piVar19 = *param_3;
    piVar14 = piVar6;
    piVar13 = *param_3;
  }
  if ((piVar6 != (int *)0x0) && (piVar13 != piVar6)) {
    piVar10 = (int *)piVar6[4];
    piVar9 = (int *)piVar6[3];
    iVar3 = *piVar6;
    piVar15 = piVar10;
    if (!bVar1) {
      piVar15 = piVar9;
    }
    if (local_48 == 0) goto LAB_004b383c;
    do {
      piVar7 = piVar6;
      if ((local_48 & *(uint *)(iVar3 + 0xc)) != 0) goto LAB_004b383c;
      while( true ) {
        piVar6 = piVar15;
        if (piVar13 == piVar7) goto LAB_004b3938;
        piVar10 = (int *)piVar6[4];
        piVar9 = (int *)piVar6[3];
        iVar3 = *piVar6;
        piVar15 = piVar10;
        if (!bVar1) {
          piVar15 = piVar9;
        }
        if (local_48 != 0) break;
LAB_004b383c:
        piVar7 = piVar6;
        if ((((((local_44 == 0) || ((local_44 & *(uint *)(iVar3 + 0x10)) != 0)) &&
              ((local_40 == 0 || ((local_40 & *(uint *)(iVar3 + 0x14)) != 0)))) &&
             ((local_3c == 0 || ((local_3c & *(uint *)(iVar3 + 0x18)) != 0)))) &&
            ((local_38 == 0 || ((local_38 & *(uint *)(iVar3 + 0x1c)) != 0)))) &&
           ((((local_50 & 3) == 0 || ((*(uint *)(iVar3 + 0x20) & 3 & local_50) != 0)) &&
            (((local_50 & 0x1fc) == 0 || ((*(uint *)(iVar3 + 0x20) & 0x1fc & local_50) != 0)))))) {
          if (iVar17 == 1) {
            if (piVar6[1] == 0) {
              if (piVar19 != piVar6) {
                if (piVar14 == piVar6) {
                  piVar14 = piVar9;
                }
                if (piVar10 != (int *)0x0) {
                  piVar10[3] = (int)piVar9;
                  piVar9 = (int *)piVar6[3];
                }
                if (piVar9 != (int *)0x0) {
                  piVar9[4] = (int)piVar10;
                }
                piVar19[3] = (int)piVar6;
                piVar6[4] = (int)piVar19;
                piVar6[3] = 0;
              }
              piVar6[1] = 1;
              piVar19 = piVar6;
            }
          }
          else if (iVar17 == 4) {
            if ((piVar6[1] != 0) && (piVar19 != piVar6)) {
              if (piVar14 == piVar6) {
                piVar14 = piVar9;
              }
              if (piVar10 != (int *)0x0) {
                piVar10[3] = (int)piVar9;
                piVar9 = (int *)piVar6[3];
              }
              if (piVar9 != (int *)0x0) {
                piVar9[4] = (int)piVar10;
              }
              piVar19[3] = (int)piVar6;
              piVar6[4] = (int)piVar19;
              piVar6[3] = 0;
              piVar19 = piVar6;
            }
          }
          else if (iVar17 == 3) {
            if (piVar6[1] != 0) {
              if (piVar14 != piVar6) {
                if (piVar19 == piVar6) {
                  piVar19 = piVar10;
                }
                if (piVar9 != (int *)0x0) {
                  piVar9[4] = (int)piVar10;
                  piVar10 = (int *)piVar6[4];
                }
                if (piVar10 != (int *)0x0) {
                  piVar10[3] = (int)piVar9;
                }
                piVar14[4] = (int)piVar6;
                piVar6[3] = (int)piVar14;
                piVar6[4] = 0;
              }
              piVar6[1] = 0;
              piVar14 = piVar6;
            }
          }
          else {
            piVar12 = piVar9;
            if (piVar14 != piVar6) {
              piVar10[3] = (int)piVar9;
              piVar9 = piVar14;
              piVar12 = (int *)piVar6[3];
            }
            piVar6[1] = 0;
            if (piVar19 == piVar6) {
              piVar19 = piVar10;
            }
            if (piVar12 != (int *)0x0) {
              piVar12[4] = (int)piVar10;
              piVar10 = (int *)piVar6[4];
            }
            if (piVar10 != (int *)0x0) {
              piVar10[3] = (int)piVar12;
            }
            piVar6[3] = 0;
            piVar6[4] = 0;
            piVar14 = piVar9;
          }
        }
      }
    } while( true );
  }
LAB_004b3938:
  *param_2 = piVar14;
  *param_3 = piVar19;
  iVar3 = (int)*param_1;
  if (iVar3 == 0) {
    return local_34;
  }
  goto LAB_004b3404;
}

