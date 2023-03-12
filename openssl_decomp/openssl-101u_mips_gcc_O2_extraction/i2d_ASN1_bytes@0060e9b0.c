
int i2d_ASN1_bytes(ASN1_STRING *a,uchar **pp,int tag,int xclass)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  stack_st_OPENSSL_BLOCK *psVar6;
  uchar *******pppppppuVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  uchar ********ppppppppuVar11;
  uchar *******pp_00;
  undefined4 *puVar12;
  int *piVar13;
  int **ppiVar14;
  int **ppiVar15;
  undefined4 uVar16;
  uchar ********ppppppppuVar17;
  char *free_func;
  ASN1_STRING *unaff_s0;
  int unaff_s1;
  int unaff_s2;
  uchar **unaff_s3;
  uchar ********unaff_s5;
  uchar ********unaff_s6;
  uchar ********unaff_s7;
  code *pcVar18;
  int iStack_240;
  int iStack_23c;
  undefined *puStack_234;
  uchar ********ppppppppuStack_230;
  undefined *puStack_22c;
  uchar **ppuStack_228;
  char *pcStack_224;
  char *pcStack_220;
  code *pcStack_21c;
  undefined4 uStack_208;
  undefined *puStack_200;
  int iStack_1f4;
  undefined4 uStack_1f0;
  int iStack_1ec;
  uchar *******pppppppuStack_1e8;
  code *pcStack_1e4;
  uchar *******pppppppuStack_1c0;
  undefined4 *puStack_1bc;
  undefined *puStack_1b4;
  uchar ********ppppppppuStack_1b0;
  int **ppiStack_1ac;
  uchar ********ppppppppuStack_1a8;
  undefined *puStack_1a4;
  uchar ********ppppppppuStack_1a0;
  uchar ********ppppppppuStack_19c;
  uchar ********ppppppppuStack_198;
  code *pcStack_194;
  uchar *puStack_160;
  stack_st_OPENSSL_BLOCK *psStack_15c;
  int *piStack_158;
  undefined4 uStack_154;
  uchar ********ppppppppuStack_140;
  undefined4 uStack_13c;
  uchar ********ppppppppuStack_138;
  undefined *puStack_130;
  uchar ********ppppppppuStack_124;
  int *piStack_120;
  uchar ********ppppppppuStack_11c;
  uchar **ppuStack_118;
  uchar ********ppppppppuStack_114;
  uchar ********ppppppppuStack_110;
  char *pcStack_10c;
  uchar ********ppppppppuStack_108;
  uchar ********ppppppppuStack_104;
  uchar ********ppppppppuStack_100;
  uchar *******pppppppuStack_fc;
  uchar ********ppppppppuStack_f8;
  uchar ********ppppppppuStack_f4;
  uchar ********ppppppppuStack_f0;
  uchar *******pppppppuStack_ec;
  uchar *******pppppppuStack_e8;
  undefined4 uStack_e4;
  int iStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  int iStack_d4;
  undefined4 uStack_d0;
  uchar ********ppppppppuStack_cc;
  int iStack_c8;
  uchar ********ppppppppuStack_c4;
  uint uStack_c0;
  uchar ********ppppppppuStack_bc;
  uchar ********ppppppppuStack_b8;
  uchar ********ppppppppuStack_b4;
  int iStack_b0;
  uchar ********ppppppppuStack_ac;
  uchar ********ppppppppuStack_a8;
  uchar ********ppppppppuStack_a0;
  int iStack_9c;
  uchar ********ppppppppuStack_98;
  uint uStack_94;
  uchar ********ppppppppuStack_90;
  uchar ********ppppppppuStack_8c;
  uchar ********ppppppppuStack_88;
  int iStack_84;
  uchar ********ppppppppuStack_80;
  uchar ********ppppppppuStack_7c;
  uchar *puStack_74;
  ASN1_STRING *pAStack_70;
  int iStack_6c;
  int iStack_68;
  uchar **ppuStack_64;
  undefined *puStack_60;
  uchar ********ppppppppuStack_5c;
  uchar ********ppppppppuStack_58;
  uchar ********local_38;
  uchar *local_28;
  int **local_24;
  
  puStack_1a4 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  iVar2 = 0;
  ppppppppuVar11 = (uchar ********)pp;
  ppppppppuStack_230 = (uchar ********)tag;
  ppppppppuVar17 = (uchar ********)xclass;
  iStack_68 = unaff_s2;
  if (a != (ASN1_STRING *)0x0) {
    iStack_68 = tag;
    if (tag == 3) {
      iVar2 = (*(code *)PTR_i2d_ASN1_BIT_STRING_006a97fc)();
      ppppppppuVar11 = (uchar ********)pp;
      ppppppppuVar17 = (uchar ********)xclass;
    }
    else {
      unaff_s5 = (uchar ********)a->length;
      ppppppppuVar11 = unaff_s5;
      iVar2 = (*(code *)PTR_ASN1_object_size_006a83e4)(0);
      unaff_s0 = a;
      unaff_s1 = iVar2;
      unaff_s3 = pp;
      unaff_s6 = (uchar ********)xclass;
      if (pp != (uchar **)0x0) {
        local_28 = *pp;
        ppppppppuVar17 = (uchar ********)tag;
        (*(code *)PTR_ASN1_put_object_006a83e8)(&local_28,tag - 0x10U < 2,unaff_s5);
        ppppppppuStack_230 = (uchar ********)a->length;
        ppppppppuVar11 = (uchar ********)a->data;
        (*(code *)PTR_memcpy_006a9aec)(local_28);
        *pp = local_28 + a->length;
        local_38 = (uchar ********)xclass;
      }
    }
  }
  if (local_24 == *(int ***)puStack_1a4) {
    return iVar2;
  }
  ppiStack_1ac = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppuStack_118 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  puStack_60 = puStack_1a4;
  puStack_130 = &_gp;
  puStack_74 = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  free_func = (char *)ppppppppuVar17;
  ppppppppuStack_1a8 = ppppppppuVar17;
  ppppppppuStack_11c = ppppppppuVar11;
  pAStack_70 = unaff_s0;
  iStack_6c = unaff_s1;
  ppuStack_64 = unaff_s3;
  ppppppppuStack_5c = unaff_s5;
  ppppppppuStack_58 = unaff_s6;
  if (ppiStack_1ac == (int **)0x0) {
LAB_0060ebd4:
    pcStack_220 = (char *)ppppppppuStack_230;
    piStack_158 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_224 = (char *)ppppppppuVar11;
    if (piStack_158 != (int *)0x0) {
      free_func = (char *)&pppppppuStack_fc;
      pcStack_220 = (char *)&ppppppppuStack_100;
      pcStack_224 = (char *)&ppppppppuStack_104;
      ppppppppuStack_108 = (uchar ********)*ppppppppuStack_11c;
      ppppppppuStack_140 = ppppppppuStack_230;
      uVar3 = (**(code **)(puStack_130 + -0x6e30))(&ppppppppuStack_108);
      piVar4 = piStack_158;
      if ((uVar3 & 0x80) == 0) goto LAB_0060ec1c;
      ppppppppuStack_230 = (uchar ********)0x66;
      goto LAB_0060ec2c;
    }
    goto LAB_0060eb90;
  }
  piStack_158 = *ppiStack_1ac;
  free_func = (char *)&pppppppuStack_fc;
  if (piStack_158 == (int *)0x0) goto LAB_0060ebd4;
  ppppppppuStack_108 = (uchar ********)*ppppppppuVar11;
  pcStack_220 = (char *)&ppppppppuStack_100;
  pcStack_224 = (char *)&ppppppppuStack_104;
  ppppppppuStack_140 = ppppppppuStack_230;
  uVar3 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&ppppppppuStack_108);
  piVar4 = piStack_158;
  if ((uVar3 & 0x80) != 0) {
    ppppppppuStack_230 = (uchar ********)0x66;
    if (piStack_158 != *ppiStack_1ac) {
      pcVar18 = *(code **)(puStack_130 + -0x6644);
      goto LAB_0060eb80;
    }
    goto LAB_0060ec50;
  }
LAB_0060ec1c:
  piStack_158 = piVar4;
  if (ppppppppuVar17 != ppppppppuStack_100) {
    ppppppppuStack_230 = (uchar ********)&DAT_000000a8;
    goto LAB_0060ec2c;
  }
  if ((uVar3 & 0x20) != 0) {
    ppppppppuStack_c4 = (uchar ********)0x0;
    ppppppppuStack_a8 = ppppppppuStack_11c;
    ppppppppuStack_cc = ppppppppuStack_108;
    ppppppppuStack_b4 = ppppppppuStack_104;
    ppppppppuStack_b8 = local_38;
    if (ppppppppuStack_230 == (uchar ********)0x0) {
      iStack_b0 = 0;
    }
    else {
      iStack_b0 = (int)ppppppppuStack_108 + (int)ppppppppuStack_230;
    }
    puStack_1a4 = (undefined *)0x0;
    piStack_120 = (int *)0x0;
    uStack_e4 = 0;
    unaff_s7 = (uchar ********)&ppppppppuStack_cc;
    uStack_dc = 0;
    unaff_s6 = &pppppppuStack_ec;
    iStack_e0 = 0;
    ppppppppuStack_1a8 = (uchar ********)&ppppppppuStack_f0;
    pcStack_10c = "a_bytes.c";
    uVar5 = uVar3 & 1;
    uStack_c0 = uVar3;
    ppppppppuStack_bc = ppppppppuVar17;
    do {
      if (uVar5 == 0) {
        if (0 < (int)ppppppppuStack_b4) goto LAB_0060ed04;
LAB_0060eea4:
        ppppppppuStack_230 = (uchar ********)&ppppppppuStack_cc;
        iVar2 = (**(code **)(puStack_130 + -0x69e4))(ppppppppuStack_230);
        if (iVar2 != 0) {
          *piVar4 = (int)puStack_1a4;
          if (piVar4[2] != 0) {
            (**(code **)(puStack_130 + -0x7f58))();
          }
          piVar4[2] = iStack_e0;
          ppppppppuVar11 = ppppppppuStack_cc;
          if (piStack_120 != (int *)0x0) {
            (**(code **)(puStack_130 + -0x6644))(piStack_120);
            ppppppppuVar11 = ppppppppuStack_cc;
          }
          goto LAB_0060ee40;
        }
LAB_0060ed80:
        if (piStack_120 != (int *)0x0) goto LAB_0060ed88;
        goto LAB_0060ed9c;
      }
      pcStack_224 = (char *)(iStack_b0 - (int)ppppppppuStack_cc);
      iStack_c8 = (**(code **)(puStack_130 + -0x69e0))(unaff_s7);
      if (iStack_c8 != 0) goto LAB_0060eea4;
LAB_0060ed04:
      ppppppppuVar11 = ppppppppuStack_bc;
      ppppppppuStack_124 = ppppppppuStack_b8;
      ppppppppuStack_ac = ppppppppuStack_cc;
      unaff_s5 = (uchar ********)(iStack_b0 - (int)ppppppppuStack_cc);
      piVar9 = piStack_120;
      if ((piStack_120 == (int *)0x0) &&
         (piVar9 = (int *)(**(code **)(puStack_130 + -0x6650))(), piVar9 == (int *)0x0))
      goto LAB_0060ed9c;
      pcStack_224 = (char *)&ppppppppuStack_f4;
      ppppppppuStack_f8 = ppppppppuStack_cc;
      pcStack_220 = (char *)ppppppppuStack_1a8;
      free_func = (char *)unaff_s6;
      ppppppppuStack_140 = unaff_s5;
      uVar3 = (**(code **)(puStack_130 + -0x6e30))(&ppppppppuStack_f8);
      if ((uVar3 & 0x80) != 0) {
        ppppppppuStack_c4 = (uchar ********)0x66;
LAB_0060ed64:
        if (piVar9 != piStack_120) {
          (**(code **)(puStack_130 + -0x6644))(piVar9);
        }
        goto LAB_0060ed80;
      }
      if (ppppppppuVar11 != ppppppppuStack_f0) {
        ppppppppuStack_c4 = (uchar ********)&DAT_000000a8;
        goto LAB_0060ed64;
      }
      if ((uVar3 & 0x20) == 0) {
        if (ppppppppuStack_f4 == (uchar ********)0x0) {
          if (piVar9[2] == 0) {
            unaff_s5 = (uchar ********)0x0;
            ppppppppuStack_cc = ppppppppuStack_f8;
          }
          else {
            unaff_s5 = (uchar ********)0x0;
            (**(code **)(puStack_130 + -0x7f58))();
            ppppppppuStack_cc = ppppppppuStack_f8;
          }
        }
        else {
          if ((*piVar9 < (int)ppppppppuStack_f4) ||
             (unaff_s5 = (uchar ********)piVar9[2], unaff_s5 == (uchar ********)0x0)) {
            pcStack_220 = &DAT_000000e9;
            pcStack_224 = pcStack_10c;
            unaff_s5 = (uchar ********)
                       (**(code **)(puStack_130 + -0x7dd8))((int)ppppppppuStack_f4 + 1);
            if (unaff_s5 == (uchar ********)0x0) {
              ppppppppuStack_c4 = (uchar ********)&DAT_00000041;
              goto LAB_0060ed64;
            }
            if (piVar9[2] != 0) {
              (**(code **)(puStack_130 + -0x7f58))();
            }
          }
          pcStack_220 = (char *)ppppppppuStack_f4;
          (**(code **)(puStack_130 + -0x52f4))(unaff_s5,ppppppppuStack_f8);
          *(undefined *)((int)unaff_s5 + (int)ppppppppuStack_f4) = 0;
          ppppppppuStack_cc = (uchar ********)((int)ppppppppuStack_f8 + (int)ppppppppuStack_f4);
        }
        *piVar9 = (int)ppppppppuStack_f4;
        piVar9[2] = (int)unaff_s5;
        piVar9[1] = (int)ppppppppuVar11;
        ppppppppuVar11 = ppppppppuStack_f4;
      }
      else {
        ppppppppuStack_98 = (uchar ********)0x0;
        ppppppppuStack_a0 = ppppppppuStack_f8;
        ppppppppuStack_88 = ppppppppuStack_f4;
        ppppppppuStack_90 = ppppppppuVar11;
        ppppppppuStack_8c = ppppppppuStack_124;
        if (unaff_s5 == (uchar ********)0x0) {
          iStack_84 = 0;
        }
        else {
          iStack_84 = (int)ppppppppuStack_f8 + (int)unaff_s5;
        }
        ppppppppuStack_114 = (uchar ********)&ppppppppuStack_a0;
        ppppppppuStack_124 = (uchar ********)0x0;
        pppppppuStack_e8 = (uchar *******)0x0;
        unaff_s5 = &pppppppuStack_e8;
        ppppppppuStack_110 = (uchar ********)&ppppppppuStack_98;
        uStack_d8 = 0;
        uStack_d0 = 0;
        iStack_d4 = 0;
        pcStack_224 = (char *)ppppppppuStack_f4;
        uStack_94 = uVar3;
        ppppppppuStack_7c = unaff_s7;
        if ((uVar3 & 1) != 0) goto LAB_0060f054;
        while (pcVar18 = *(code **)(puStack_130 + -0x69e4), 0 < (int)ppppppppuStack_88) {
          while( true ) {
            ppppppppuStack_138 = ppppppppuStack_110;
            ppppppppuStack_140 = ppppppppuStack_8c;
            pcStack_220 = (char *)(iStack_84 - (int)ppppppppuStack_a0);
            ppppppppuStack_80 = ppppppppuStack_a0;
            uStack_13c = 2;
            pcStack_224 = (char *)ppppppppuStack_114;
            free_func = (char *)ppppppppuStack_90;
            iVar2 = int_d2i_ASN1_bytes(unaff_s5);
            if (iVar2 == 0) goto LAB_0060f1ac;
            pcStack_224 = (char *)((int)ppppppppuStack_124 + (int)*pppppppuStack_e8);
            iVar2 = (**(code **)(puStack_130 + -0x72a0))(&uStack_d8);
            if (iVar2 == 0) {
              ppppppppuStack_98 = (uchar ********)&DAT_00000007;
              goto LAB_0060f1ac;
            }
            pcStack_220 = (char *)*pppppppuStack_e8;
            pcStack_224 = (char *)pppppppuStack_e8[2];
            (**(code **)(puStack_130 + -0x52f4))(iStack_d4 + (int)ppppppppuStack_124);
            if ((uStack_94 & 1) == 0) {
              pcStack_224 = (char *)((int)ppppppppuStack_a0 - (int)ppppppppuStack_80);
              ppppppppuStack_88 = (uchar ********)((int)ppppppppuStack_88 - (int)pcStack_224);
            }
            ppppppppuStack_124 = (uchar ********)((int)ppppppppuStack_124 + (int)*pppppppuStack_e8);
            if ((uStack_94 & 1) == 0) break;
LAB_0060f054:
            pcStack_224 = (char *)(iStack_84 - (int)ppppppppuStack_a0);
            iStack_9c = (**(code **)(puStack_130 + -0x69e0))(ppppppppuStack_114);
            if (iStack_9c != 0) {
              pcVar18 = *(code **)(puStack_130 + -0x69e4);
              goto LAB_0060f07c;
            }
          }
        }
LAB_0060f07c:
        iVar2 = (*pcVar18)(ppppppppuStack_114);
        if (iVar2 == 0) {
LAB_0060f1ac:
          if (pppppppuStack_e8 != (uchar *******)0x0) {
            (**(code **)(puStack_130 + -0x6644))();
          }
          if (iStack_d4 != 0) {
            (**(code **)(puStack_130 + -0x7f58))();
          }
          ppppppppuStack_c4 = ppppppppuStack_98;
          goto LAB_0060ed64;
        }
        *piVar9 = (int)ppppppppuStack_124;
        if (piVar9[2] != 0) {
          (**(code **)(puStack_130 + -0x7f58))();
        }
        piVar9[2] = iStack_d4;
        if (pppppppuStack_e8 != (uchar *******)0x0) {
          (**(code **)(puStack_130 + -0x6644))();
        }
        ppppppppuStack_cc = ppppppppuStack_a0;
        ppppppppuVar11 = (uchar ********)*piVar9;
      }
      pcStack_224 = puStack_1a4 + (int)ppppppppuVar11;
      iVar2 = (**(code **)(puStack_130 + -0x72a0))(&uStack_e4);
      if (iVar2 == 0) goto LAB_0060f214;
      pcStack_220 = (char *)*piVar9;
      pcStack_224 = (char *)piVar9[2];
      (**(code **)(puStack_130 + -0x52f4))(puStack_1a4 + iStack_e0);
      uVar5 = uStack_c0 & 1;
      if (uVar5 == 0) {
        pcStack_224 = (char *)((int)ppppppppuStack_cc - (int)ppppppppuStack_ac);
        ppppppppuStack_b4 = (uchar ********)((int)ppppppppuStack_b4 - (int)pcStack_224);
      }
      puStack_1a4 = puStack_1a4 + *piVar9;
      piStack_120 = piVar9;
    } while( true );
  }
  if (ppppppppuStack_104 == (uchar ********)0x0) {
    if (piVar4[2] == 0) {
      ppppppppuStack_230 = (uchar ********)0x0;
      ppppppppuVar11 = ppppppppuStack_108;
    }
    else {
      ppppppppuStack_230 = (uchar ********)0x0;
      (**(code **)(puStack_130 + -0x7f58))();
      ppppppppuVar11 = ppppppppuStack_108;
    }
  }
  else {
    if (*piVar4 < (int)ppppppppuStack_104) {
      pcVar18 = *(code **)(puStack_130 + -0x7dd8);
LAB_0060f228:
      pcStack_220 = &DAT_000000e9;
      pcStack_224 = "a_bytes.c";
      ppppppppuStack_230 = (uchar ********)(*pcVar18)((int)ppppppppuStack_104 + 1);
      if (ppppppppuStack_230 == (uchar ********)0x0) {
        ppppppppuStack_230 = (uchar ********)&DAT_00000041;
        goto LAB_0060ec2c;
      }
      if (piVar4[2] != 0) {
        (**(code **)(puStack_130 + -0x7f58))();
      }
    }
    else {
      ppppppppuStack_230 = (uchar ********)piVar4[2];
      pcVar18 = *(code **)(puStack_130 + -0x7dd8);
      if (ppppppppuStack_230 == (uchar ********)0x0) goto LAB_0060f228;
    }
    pcStack_224 = (char *)ppppppppuStack_108;
    pcStack_220 = (char *)ppppppppuStack_104;
    (**(code **)(puStack_130 + -0x52f4))(ppppppppuStack_230);
    *(undefined *)((int)ppppppppuStack_230 + (int)ppppppppuStack_104) = 0;
    ppppppppuVar11 = (uchar ********)((int)ppppppppuStack_108 + (int)ppppppppuStack_104);
  }
  *piVar4 = (int)ppppppppuStack_104;
  piVar4[2] = (int)ppppppppuStack_230;
  piVar4[1] = (int)ppppppppuVar17;
LAB_0060ee40:
  if (ppiStack_1ac != (int **)0x0) {
    *ppiStack_1ac = piVar4;
  }
  *ppppppppuStack_11c = (uchar *******)ppppppppuVar11;
  goto LAB_0060eb94;
LAB_0060f214:
  ppppppppuStack_c4 = (uchar ********)&DAT_00000007;
  piStack_120 = piVar9;
LAB_0060ed88:
  (**(code **)(puStack_130 + -0x6644))(piStack_120);
LAB_0060ed9c:
  ppppppppuStack_230 = ppppppppuStack_c4;
  if (iStack_e0 != 0) {
    (**(code **)(puStack_130 + -0x7f58))();
    ppppppppuStack_230 = ppppppppuStack_c4;
  }
LAB_0060ec2c:
  pcVar18 = *(code **)(puStack_130 + -0x6644);
  if ((ppiStack_1ac == (int **)0x0) || (*ppiStack_1ac != piStack_158)) {
LAB_0060eb80:
    (*pcVar18)(piStack_158);
    if (ppppppppuStack_230 != (uchar ********)0x0) {
LAB_0060ec50:
      pcVar18 = *(code **)(puStack_130 + -0x6eac);
      goto LAB_0060ec58;
    }
  }
  else if (ppppppppuStack_230 != (uchar ********)0x0) {
    pcVar18 = *(code **)(puStack_130 + -0x6eac);
LAB_0060ec58:
    pcStack_224 = (char *)0x8f;
    free_func = "a_bytes.c";
    ppppppppuStack_140 = (uchar ********)0xaf;
    pcStack_220 = (char *)ppppppppuStack_230;
    (*pcVar18)(0xd);
    piVar4 = (int *)0x0;
    goto LAB_0060eb94;
  }
LAB_0060eb90:
  piVar4 = (int *)0x0;
LAB_0060eb94:
  if (puStack_74 == *ppuStack_118) {
    return (int)piVar4;
  }
  uStack_154 = 0x60f2d8;
  puStack_160 = puStack_74;
  (**(code **)(puStack_130 + -0x5330))();
  pppppppuStack_1e8 = (uchar *******)PTR___stack_chk_guard_006a9ae8;
  ppuStack_228 = &puStack_160;
  psStack_15c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  psVar6 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_228,(long)pcStack_224,pcStack_220,
                        (free_func *)free_func,0x10,0);
  if (psVar6 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pcStack_224 = &DAT_0000006e;
    pcStack_220 = "asn_pack.c";
    ppuStack_228 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_15c == (stack_st_OPENSSL_BLOCK *)*pppppppuStack_1e8) {
    return (int)psVar6;
  }
  pcStack_194 = ASN1_seq_pack;
  psVar6 = psStack_15c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_22c = PTR___stack_chk_guard_006a9ae8;
  puStack_1b4 = (undefined *)pppppppuStack_1e8;
  puStack_1bc = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppppppppuStack_1b0 = ppppppppuStack_230;
  ppppppppuStack_1a0 = unaff_s5;
  ppppppppuStack_19c = unaff_s6;
  ppppppppuStack_198 = unaff_s7;
  ppppppppuVar11 =
       (uchar ********)i2d_ASN1_SET(psVar6,(uchar **)0x0,(undefined1 *)ppuStack_228,0x10,0,0);
  if (ppppppppuVar11 == (uchar ********)0x0) {
    pp_00 = (uchar *******)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    pppppppuVar7 = (uchar *******)0x0;
  }
  else {
    pppppppuStack_1e8 =
         (uchar *******)(*(code *)PTR_CRYPTO_malloc_006a7008)(ppppppppuVar11,"asn_pack.c",0x62);
    ppppppppuStack_230 = ppppppppuVar11;
    if (pppppppuStack_1e8 == (uchar *******)0x0) {
      pp_00 = (uchar *******)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      pppppppuVar7 = (uchar *******)0x0;
    }
    else {
      pp_00 = (uchar *******)&pppppppuStack_1c0;
      pppppppuStack_1c0 = pppppppuStack_1e8;
      i2d_ASN1_SET(psVar6,(uchar **)pp_00,(undefined1 *)ppuStack_228,0x10,0,0);
      if ((uchar ********)pcStack_220 != (uchar ********)0x0) {
        *(uchar *********)pcStack_220 = ppppppppuVar11;
      }
      pppppppuVar7 = pppppppuStack_1e8;
      if ((uchar ********)pcStack_224 != (uchar ********)0x0) {
        *(uchar ********)pcStack_224 = pppppppuStack_1e8;
      }
    }
  }
  if (puStack_1bc == *(undefined4 **)puStack_22c) {
    return (int)pppppppuVar7;
  }
  pcStack_1e4 = ASN1_unpack_string;
  puVar12 = puStack_1bc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_234 = PTR___stack_chk_guard_006a9ae8;
  uStack_1f0 = puVar12[2];
  ppiVar14 = (int **)*puVar12;
  puVar12 = &uStack_1f0;
  puStack_200 = &_gp;
  iStack_1ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)pp_00)(0);
  if (iVar2 == 0) {
    ppiVar14 = (int **)&DAT_0000006e;
    uStack_208 = 0x79;
    puVar12 = (undefined4 *)&DAT_00000088;
    iStack_1f4 = iVar2;
    (**(code **)(puStack_200 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    iVar2 = iStack_1f4;
  }
  if (iStack_1ec == *(int *)puStack_234) {
    return iVar2;
  }
  pcStack_21c = ASN1_pack_string;
  iVar2 = iStack_1ec;
  (**(code **)(puStack_200 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_23c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppiVar14 == (int **)0x0) {
    piVar4 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar4 != (int *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppiVar15 = (int **)&DAT_00000041;
    piVar13 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    piVar9 = (int *)0x0;
  }
  else {
    piVar4 = *ppiVar14;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar4 == (int *)0x0) goto LAB_0060f754;
      *ppiVar14 = piVar4;
    }
LAB_0060f614:
    iVar8 = (*(code *)puVar12)(iVar2,0);
    *piVar4 = iVar8;
    if (iVar8 == 0) {
      ppiVar15 = (int **)&DAT_00000070;
      piVar13 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppiVar15 = (int **)&DAT_00000092;
      iStack_240 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar8,"asn_pack.c");
      if (iStack_240 != 0) {
        piVar13 = &iStack_240;
        piVar4[2] = iStack_240;
        (*(code *)puVar12)(iVar2,piVar13);
        piVar9 = piVar4;
        goto LAB_0060f670;
      }
      ppiVar15 = (int **)&DAT_00000041;
      piVar13 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppiVar14 == (int **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar4);
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = *ppiVar14;
      if (piVar9 == (int *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar4);
        *ppiVar14 = (int *)0x0;
      }
      else {
        piVar9 = (int *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_23c == *(int *)puVar1) {
    return (int)piVar9;
  }
  iVar2 = iStack_23c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppiVar15 == (int **)0x0) {
    piVar4 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar4 == (int *)0x0) {
LAB_0060f874:
      uVar16 = 0x41;
      uVar10 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    piVar4 = *ppiVar15;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar4 == (int *)0x0) goto LAB_0060f874;
      *ppiVar15 = piVar4;
    }
  }
  if (piVar4[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    piVar4[2] = 0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar2,piVar4 + 2,piVar13);
  *piVar4 = iVar2;
  if (iVar2 == 0) {
    uVar16 = 0x70;
    uVar10 = 0xba;
  }
  else {
    if (piVar4[2] != 0) {
      return (int)piVar4;
    }
    uVar16 = 0x41;
    uVar10 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar16,"asn_pack.c",uVar10);
  return 0;
}

