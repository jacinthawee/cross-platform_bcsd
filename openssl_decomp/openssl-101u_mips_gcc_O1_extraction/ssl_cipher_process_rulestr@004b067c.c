
undefined4 ssl_cipher_process_rulestr(char *param_1,int **param_2,int **param_3,int **param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  char *pcVar18;
  int iVar19;
  int iVar20;
  int **ppiVar21;
  int *piVar22;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  
  local_34 = 1;
  iVar3 = (int)*param_1;
LAB_004b06e8:
  do {
    if (iVar3 == 0) {
      return local_34;
    }
    while (iVar3 != 0x2d) {
      if (iVar3 == 0x2b) {
        param_1 = param_1 + 1;
        iVar19 = 4;
LAB_004b09e4:
        if ((0x1b < (iVar3 - 0x20U & 0xff)) || ((0x8001001U >> (iVar3 - 0x20U & 0x1f) & 1) == 0))
        goto LAB_004b076c;
        cVar2 = param_1[1];
      }
      else {
        if (iVar3 == 0x21) {
          param_1 = param_1 + 1;
          iVar19 = 2;
          goto LAB_004b09e4;
        }
        if (iVar3 == 0x40) {
          param_1 = param_1 + 1;
          iVar19 = 5;
          goto LAB_004b09e4;
        }
        if (iVar3 != 0x3a) {
          iVar19 = 1;
          goto LAB_004b09e4;
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
    iVar19 = 3;
LAB_004b076c:
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    cVar2 = *param_1;
    pcVar18 = param_1;
    uVar17 = 0;
LAB_004b0794:
    while( true ) {
      uVar12 = (uint)cVar2;
      iVar3 = (int)param_1 - (int)pcVar18;
      if (((0x19 < (uVar12 & 0xdf) - 0x41) && (9 < (uVar12 & 0xff) - 0x30)) &&
         (1 < (uVar12 & 0xff) - 0x2d)) break;
      param_1 = param_1 + 1;
      cVar2 = *param_1;
    }
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xe6,0x118,"ssl_ciph.c",0x4a8);
      param_1 = param_1 + 1;
      if (iVar19 != 5) {
        local_34 = 0;
        goto LAB_004b0840;
      }
LAB_004b0c84:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xe6,0x118,"ssl_ciph.c",0x544);
      local_34 = 0;
LAB_004b0cac:
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
      goto LAB_004b06e8;
    }
    if (iVar19 == 5) {
      if ((iVar3 != 8) ||
         (iVar3 = (*(code *)PTR_strncmp_006a9970)(pcVar18,"STRENGTH",8), iVar3 != 0))
      goto LAB_004b0c84;
      iVar3 = ssl_cipher_strength_sort(param_2,param_3);
      if (iVar3 == 0) {
        local_34 = 0;
      }
      goto LAB_004b0cac;
    }
    if (uVar12 == 0x2b) {
      param_1 = param_1 + 1;
    }
    piVar22 = *param_4;
    ppiVar21 = param_4;
    while( true ) {
      if (piVar22 == (int *)0x0) goto LAB_004b0840;
      ppiVar21 = ppiVar21 + 1;
      iVar20 = piVar22[1];
      iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar18,iVar20,iVar3);
      if ((iVar4 == 0) && (*(char *)(iVar20 + iVar3) == '\0')) break;
      piVar22 = *ppiVar21;
    }
    uVar5 = piVar22[3];
    uVar6 = local_48;
    if (((((uVar5 == 0) ||
          ((uVar6 = uVar5, local_48 == 0 || (uVar6 = local_48 & uVar5, (local_48 & uVar5) != 0))))
         && ((local_48 = uVar6, uVar5 = piVar22[4], uVar6 = local_44, uVar5 == 0 ||
             ((uVar6 = uVar5, local_44 == 0 || (uVar6 = local_44 & uVar5, (local_44 & uVar5) != 0)))
             ))) &&
        ((local_44 = uVar6, uVar5 = piVar22[5], uVar6 = local_40, uVar5 == 0 ||
         ((uVar6 = uVar5, local_40 == 0 || (uVar6 = local_40 & uVar5, (local_40 & uVar5) != 0))))))
       && ((local_40 = uVar6, uVar5 = piVar22[6], uVar6 = local_3c, uVar5 == 0 ||
           ((uVar6 = uVar5, local_3c == 0 || (uVar6 = local_3c & uVar5, (local_3c & uVar5) != 0)))))
       ) {
      local_3c = uVar6;
      uVar6 = piVar22[8];
      if ((uVar6 & 3) != 0) {
        if ((uVar17 & 3) == 0) {
          uVar17 = uVar17 | uVar6 & 3;
        }
        else {
          uVar17 = uVar17 & (uVar6 | 0xfffffffc);
          if ((uVar17 & 3) == 0) goto LAB_004b0840;
        }
      }
      if ((uVar6 & 0x1fc) != 0) {
        if ((uVar17 & 0x1fc) == 0) {
          uVar17 = uVar17 | uVar6 & 0x1fc;
        }
        else {
          uVar17 = uVar17 & (uVar6 | 0xfffffe03);
          if ((uVar17 & 0x1fc) == 0) goto LAB_004b0840;
        }
      }
      uVar5 = local_38;
      if ((((*piVar22 == 0) && (uVar7 = piVar22[7], uVar7 != 0)) && (uVar5 = uVar7, local_38 != 0))
         && (uVar5 = local_38 & uVar7, (local_38 & uVar7) == 0)) goto LAB_004b0840;
      local_38 = uVar5;
      if (uVar12 != 0x2b) break;
      cVar2 = *param_1;
      pcVar18 = param_1;
      uVar17 = uVar17 | uVar6 & 0x200;
      goto LAB_004b0794;
    }
LAB_004b0840:
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
  bVar1 = iVar19 == 3;
  if (bVar1) {
    piVar16 = *param_2;
    piVar8 = *param_3;
    piVar22 = piVar8;
    piVar15 = piVar16;
  }
  else {
    piVar8 = *param_2;
    piVar22 = *param_3;
    piVar16 = piVar8;
    piVar15 = *param_3;
  }
  if ((piVar15 != (int *)0x0) && (piVar8 != (int *)0x0)) {
    piVar11 = (int *)piVar8[4];
    piVar10 = (int *)piVar8[3];
    iVar3 = *piVar8;
    piVar14 = piVar11;
    if (!bVar1) {
      piVar14 = piVar10;
    }
    if (local_48 == 0) goto LAB_004b0b18;
    do {
      piVar9 = piVar8;
      if ((local_48 & *(uint *)(iVar3 + 0xc)) != 0) goto LAB_004b0b18;
      while( true ) {
        piVar8 = piVar14;
        if ((piVar15 == piVar9) || (piVar8 == (int *)0x0)) goto LAB_004b0c2c;
        piVar11 = (int *)piVar8[4];
        piVar10 = (int *)piVar8[3];
        iVar3 = *piVar8;
        piVar14 = piVar11;
        if (!bVar1) {
          piVar14 = piVar10;
        }
        if (local_48 != 0) break;
LAB_004b0b18:
        piVar9 = piVar8;
        if ((((((local_44 == 0) || ((local_44 & *(uint *)(iVar3 + 0x10)) != 0)) &&
              ((local_40 == 0 || ((local_40 & *(uint *)(iVar3 + 0x14)) != 0)))) &&
             ((local_3c == 0 || ((local_3c & *(uint *)(iVar3 + 0x18)) != 0)))) &&
            ((local_38 == 0 || ((local_38 & *(uint *)(iVar3 + 0x1c)) != 0)))) &&
           (((((uVar17 & 3) == 0 || ((uVar17 & *(uint *)(iVar3 + 0x20) & 3) != 0)) &&
             (((uVar17 & 0x1fc) == 0 || ((uVar17 & *(uint *)(iVar3 + 0x20) & 0x1fc) != 0)))) &&
            (((uVar17 & 0x200 | uVar6 & 0x200) == 0 || ((*(uint *)(iVar3 + 0x20) & 0x200) != 0))))))
        {
          if (iVar19 == 1) {
            if (piVar8[1] == 0) {
              if (piVar22 != piVar8) {
                if (piVar16 == piVar8) {
                  piVar16 = piVar10;
                }
                if (piVar11 != (int *)0x0) {
                  piVar11[3] = (int)piVar10;
                  piVar10 = (int *)piVar8[3];
                }
                if (piVar10 != (int *)0x0) {
                  piVar10[4] = (int)piVar11;
                }
                piVar22[3] = (int)piVar8;
                piVar8[4] = (int)piVar22;
                piVar8[3] = 0;
              }
              piVar8[1] = 1;
              piVar22 = piVar8;
            }
          }
          else if (iVar19 == 4) {
            if ((piVar8[1] != 0) && (piVar22 != piVar8)) {
              if (piVar16 == piVar8) {
                piVar16 = piVar10;
              }
              if (piVar11 != (int *)0x0) {
                piVar11[3] = (int)piVar10;
                piVar10 = (int *)piVar8[3];
              }
              if (piVar10 != (int *)0x0) {
                piVar10[4] = (int)piVar11;
              }
              piVar22[3] = (int)piVar8;
              piVar8[4] = (int)piVar22;
              piVar8[3] = 0;
              piVar22 = piVar8;
            }
          }
          else if (iVar19 == 3) {
            if (piVar8[1] != 0) {
              if (piVar16 != piVar8) {
                if (piVar22 == piVar8) {
                  piVar22 = piVar11;
                }
                if (piVar10 != (int *)0x0) {
                  piVar10[4] = (int)piVar11;
                  piVar11 = (int *)piVar8[4];
                }
                if (piVar11 != (int *)0x0) {
                  piVar11[3] = (int)piVar10;
                }
                piVar16[4] = (int)piVar8;
                piVar8[3] = (int)piVar16;
                piVar8[4] = 0;
              }
              piVar8[1] = 0;
              piVar16 = piVar8;
            }
          }
          else {
            piVar13 = piVar10;
            if (piVar16 != piVar8) {
              piVar11[3] = (int)piVar10;
              piVar10 = piVar16;
              piVar13 = (int *)piVar8[3];
            }
            piVar8[1] = 0;
            if (piVar22 == piVar8) {
              piVar22 = piVar11;
            }
            if (piVar13 != (int *)0x0) {
              piVar13[4] = (int)piVar11;
              piVar11 = (int *)piVar8[4];
            }
            if (piVar11 != (int *)0x0) {
              piVar11[3] = (int)piVar13;
            }
            piVar8[3] = 0;
            piVar8[4] = 0;
            piVar16 = piVar10;
          }
        }
      }
    } while( true );
  }
LAB_004b0c2c:
  *param_2 = piVar16;
  *param_3 = piVar22;
  iVar3 = (int)*param_1;
  if (iVar3 == 0) {
    return local_34;
  }
  goto LAB_004b06e8;
}

