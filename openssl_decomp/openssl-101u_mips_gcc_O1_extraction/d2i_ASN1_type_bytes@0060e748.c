
ASN1_STRING * d2i_ASN1_type_bytes(ASN1_STRING **a,uchar **pp,long length,int type)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  ASN1_STRING *pAVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  stack_st_OPENSSL_BLOCK *a_00;
  ASN1_STRING *pAVar9;
  ASN1_STRING *pAVar10;
  undefined4 *puVar11;
  uchar **ppuVar12;
  ASN1_STRING *pAVar13;
  ASN1_STRING **ppAVar14;
  ASN1_STRING **ppAVar15;
  undefined4 uVar16;
  char *pcVar17;
  ASN1_STRING *pAVar18;
  ASN1_STRING *unaff_s5;
  ASN1_STRING *unaff_s6;
  ASN1_STRING *unaff_s7;
  code *pcVar19;
  uchar *puStack_298;
  int iStack_294;
  undefined *puStack_28c;
  ASN1_STRING *pAStack_288;
  undefined *puStack_284;
  uchar **ppuStack_280;
  char *pcStack_27c;
  char *pcStack_278;
  code *pcStack_274;
  undefined4 uStack_260;
  undefined *puStack_258;
  ASN1_STRING *pAStack_24c;
  undefined4 uStack_248;
  int iStack_244;
  ASN1_STRING *pAStack_240;
  code *pcStack_23c;
  ASN1_STRING *pAStack_218;
  undefined4 *puStack_214;
  undefined *puStack_20c;
  ASN1_STRING *pAStack_208;
  ASN1_STRING **ppAStack_204;
  ASN1_STRING *pAStack_200;
  undefined *puStack_1fc;
  ASN1_STRING *pAStack_1f8;
  ASN1_STRING *pAStack_1f4;
  ASN1_STRING *pAStack_1f0;
  code *pcStack_1ec;
  uchar *puStack_1b8;
  stack_st_OPENSSL_BLOCK *psStack_1b4;
  ASN1_STRING *pAStack_1b0;
  undefined4 uStack_1ac;
  ASN1_STRING *pAStack_198;
  undefined4 uStack_194;
  uchar **ppuStack_190;
  undefined *puStack_188;
  ASN1_STRING *pAStack_17c;
  ASN1_STRING **ppAStack_178;
  ASN1_STRING *pAStack_174;
  uchar **ppuStack_170;
  ASN1_STRING *pAStack_16c;
  uchar **ppuStack_168;
  char *pcStack_164;
  ASN1_STRING *pAStack_160;
  undefined auStack_15c [8];
  undefined auStack_154 [4];
  ASN1_STRING *pAStack_150;
  undefined auStack_14c [8];
  undefined auStack_144 [8];
  uchar *puStack_13c;
  uchar *puStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  ASN1_STRING *pAStack_12c;
  undefined4 uStack_128;
  ASN1_STRING AStack_124;
  ASN1_STRING *pAStack_114;
  ASN1_STRING *pAStack_110;
  ASN1_STRING *pAStack_10c;
  uchar *puStack_108;
  ASN1_STRING *pAStack_104;
  ASN1_STRING *pAStack_100;
  ASN1_STRING AStack_f8;
  ASN1_STRING *pAStack_e8;
  ASN1_STRING *pAStack_e4;
  ASN1_STRING *pAStack_e0;
  uchar *puStack_dc;
  ASN1_STRING *pAStack_d8;
  ASN1_STRING *pAStack_d4;
  uchar *puStack_cc;
  ASN1_STRING *pAStack_c8;
  ASN1_STRING *pAStack_c4;
  ASN1_STRING *pAStack_c0;
  ASN1_STRING *pAStack_bc;
  undefined *puStack_b8;
  ASN1_STRING *pAStack_b4;
  ASN1_STRING *pAStack_b0;
  ASN1_STRING *pAStack_90;
  uchar *puStack_80;
  ASN1_STRING **ppAStack_7c;
  ASN1_STRING *pAStack_78;
  ASN1_STRING **ppAStack_74;
  undefined *puStack_70;
  uchar **ppuStack_6c;
  uchar *puStack_68;
  ASN1_STRING *local_2c;
  ASN1_STRING local_28;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  local_2c = (ASN1_STRING *)*pp;
  pcVar17 = (char *)&local_28.data;
  pAVar9 = &local_28;
  local_28.flags = *(long *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&local_2c,pAVar9,&local_28.type);
  if ((uVar2 & 0x80) == 0) {
    pAVar13 = (ASN1_STRING *)0x99;
    if (0x1f < local_28.type) goto LAB_0060e7d0;
    uVar2 = (*(code *)PTR_ASN1_tag2bit_006a8ce8)();
    if ((type & uVar2) == 0) {
      pAVar13 = (ASN1_STRING *)0xa9;
      goto LAB_0060e7d0;
    }
    if (local_28.type != 3) {
      if (((a == (ASN1_STRING **)0x0) ||
          (length = (long)*a, (ASN1_STRING *)length == (ASN1_STRING *)0x0)) &&
         (length = (*(code *)PTR_ASN1_STRING_new_006a8790)(),
         (ASN1_STRING *)length == (ASN1_STRING *)0x0)) {
        pAVar3 = (ASN1_STRING *)0x0;
        goto LAB_0060e7f8;
      }
      type = 0;
      if ((ASN1_STRING *)local_28.length == (ASN1_STRING *)0x0) {
LAB_0060e874:
        if (*(uchar **)(length + 8) != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        *(int *)(length + 8) = type;
        *(int *)length = local_28.length;
        *(int *)(length + 4) = local_28.type;
        if (a != (ASN1_STRING **)0x0) {
          *a = (ASN1_STRING *)length;
        }
        *pp = (uchar *)local_2c;
        pAVar3 = (ASN1_STRING *)length;
        goto LAB_0060e7f8;
      }
      type = (*(code *)PTR_CRYPTO_malloc_006a7008)
                       ((uchar *)((int)(int *)local_28.length + 1),"a_bytes.c",0x6b);
      pcVar17 = (char *)0x680000;
      if ((uchar *)type != (uchar *)0x0) {
        pAVar9 = local_2c;
        pAVar13 = (ASN1_STRING *)local_28.length;
        (*(code *)PTR_memcpy_006a9aec)(type);
        *(uchar *)(type + local_28.length) = '\0';
        local_2c = (ASN1_STRING *)((int)(int *)local_28.length + (int)&local_2c->length);
        goto LAB_0060e874;
      }
      pcVar17 = "a_bytes.c";
      pAVar13 = (ASN1_STRING *)&DAT_00000041;
      pAVar9 = (ASN1_STRING *)&DAT_00000095;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      if ((a == (ASN1_STRING **)0x0) || ((ASN1_STRING *)length != *a)) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(length);
        pAVar3 = (ASN1_STRING *)0x0;
        goto LAB_0060e7f8;
      }
      goto LAB_0060e7f4;
    }
    pAVar9 = (ASN1_STRING *)pp;
    pAVar13 = (ASN1_STRING *)length;
    pAVar3 = (ASN1_STRING *)(*(code *)PTR_d2i_ASN1_BIT_STRING_006a97f8)(a);
  }
  else {
    pAVar13 = (ASN1_STRING *)0x0;
LAB_0060e7d0:
    pAVar9 = (ASN1_STRING *)&DAT_00000095;
    pcVar17 = "a_bytes.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
LAB_0060e7f4:
    pAVar3 = (ASN1_STRING *)0x0;
  }
LAB_0060e7f8:
  if ((ASN1_STRING *)local_28.flags == *(ASN1_STRING **)puStack_70) {
    return pAVar3;
  }
  pAVar3 = (ASN1_STRING *)local_28.flags;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1fc = PTR___stack_chk_guard_006a9ae8;
  ppAStack_7c = *(ASN1_STRING ***)PTR___stack_chk_guard_006a9ae8;
  pAVar4 = (ASN1_STRING *)0x0;
  pAVar10 = pAVar9;
  pAStack_288 = pAVar13;
  pAVar18 = (ASN1_STRING *)pcVar17;
  pAStack_c0 = (ASN1_STRING *)puStack_70;
  pAStack_78 = (ASN1_STRING *)length;
  ppAStack_74 = a;
  ppuStack_6c = pp;
  puStack_68 = (uchar *)type;
  if (pAVar3 != (ASN1_STRING *)0x0) {
    pAStack_c0 = pAVar13;
    if (pAVar13 == (ASN1_STRING *)0x3) {
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_i2d_ASN1_BIT_STRING_006a97fc)();
      pAVar10 = pAVar9;
      pAVar18 = (ASN1_STRING *)pcVar17;
    }
    else {
      unaff_s5 = (ASN1_STRING *)pAVar3->length;
      pAVar10 = unaff_s5;
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_object_size_006a83e4)(0);
      length = (long)pAVar3;
      a = (ASN1_STRING **)pAVar4;
      pp = (uchar **)pAVar9;
      unaff_s6 = (ASN1_STRING *)pcVar17;
      if (pAVar9 != (ASN1_STRING *)0x0) {
        puStack_80 = (uchar *)pAVar9->length;
        pAVar18 = pAVar13;
        (*(code *)PTR_ASN1_put_object_006a83e8)
                  (&puStack_80,pAVar13 + -1 < (ASN1_STRING *)&SUB_00000002,unaff_s5);
        pAStack_288 = (ASN1_STRING *)pAVar3->length;
        pAVar10 = (ASN1_STRING *)pAVar3->data;
        (*(code *)PTR_memcpy_006a9aec)(puStack_80);
        pAVar9->length = (int)(puStack_80 + pAVar3->length);
        pAStack_90 = (ASN1_STRING *)pcVar17;
      }
    }
  }
  if (ppAStack_7c == *(ASN1_STRING ***)puStack_1fc) {
    return pAVar4;
  }
  ppAStack_204 = ppAStack_7c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppuStack_170 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = puStack_1fc;
  puStack_188 = &_gp;
  puStack_cc = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = (char *)pAVar18;
  pAStack_200 = pAVar18;
  pAStack_174 = pAVar10;
  pAStack_c8 = (ASN1_STRING *)length;
  pAStack_c4 = (ASN1_STRING *)a;
  pAStack_bc = (ASN1_STRING *)pp;
  pAStack_b4 = unaff_s5;
  pAStack_b0 = unaff_s6;
  if (ppAStack_204 == (ASN1_STRING **)0x0) {
LAB_0060ebd4:
    pcStack_278 = (char *)pAStack_288;
    pAStack_1b0 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_27c = (char *)pAVar10;
    if (pAStack_1b0 != (ASN1_STRING *)0x0) {
      pcVar17 = auStack_154;
      pcStack_278 = auStack_15c + 4;
      pcStack_27c = auStack_15c;
      pAStack_160 = (ASN1_STRING *)pAStack_174->length;
      pAStack_198 = pAStack_288;
      uVar2 = (**(code **)(puStack_188 + -0x6e30))(&pAStack_160);
      pAVar9 = pAStack_1b0;
      if ((uVar2 & 0x80) == 0) goto LAB_0060ec1c;
      pAStack_288 = (ASN1_STRING *)0x66;
      goto LAB_0060ec2c;
    }
    goto LAB_0060eb90;
  }
  pAStack_1b0 = *ppAStack_204;
  pcVar17 = auStack_154;
  if (pAStack_1b0 == (ASN1_STRING *)0x0) goto LAB_0060ebd4;
  pAStack_160 = (ASN1_STRING *)pAVar10->length;
  pcStack_278 = auStack_15c + 4;
  pcStack_27c = auStack_15c;
  pAStack_198 = pAStack_288;
  uVar2 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pAStack_160);
  pAVar9 = pAStack_1b0;
  if ((uVar2 & 0x80) != 0) {
    pAStack_288 = (ASN1_STRING *)0x66;
    if (pAStack_1b0 != *ppAStack_204) {
      pcVar19 = *(code **)(puStack_188 + -0x6644);
      goto LAB_0060eb80;
    }
    goto LAB_0060ec50;
  }
LAB_0060ec1c:
  pAStack_1b0 = pAVar9;
  if (pAVar18 != auStack_15c._4_4_) {
    pAStack_288 = (ASN1_STRING *)&DAT_000000a8;
    goto LAB_0060ec2c;
  }
  if ((uVar2 & 0x20) != 0) {
    AStack_124.data = (uchar *)0x0;
    pAStack_100 = pAStack_174;
    AStack_124.length = (int)pAStack_160;
    pAStack_10c = auStack_15c._0_4_;
    pAStack_110 = pAStack_90;
    if (pAStack_288 == (ASN1_STRING *)0x0) {
      puStack_108 = (uchar *)0x0;
    }
    else {
      puStack_108 = (uchar *)((int)&pAStack_288->length + (int)&pAStack_160->length);
    }
    puStack_1fc = (undefined *)0x0;
    ppAStack_178 = (ASN1_STRING **)0x0;
    puStack_13c = (uchar *)0x0;
    unaff_s7 = &AStack_124;
    uStack_134 = 0;
    unaff_s6 = (ASN1_STRING *)auStack_144;
    puStack_138 = (uchar *)0x0;
    pAStack_200 = (ASN1_STRING *)(auStack_14c + 4);
    pcStack_164 = "a_bytes.c";
    uVar5 = uVar2 & 1;
    AStack_124.flags = uVar2;
    pAStack_114 = pAVar18;
    do {
      if (uVar5 == 0) {
        if (0 < (int)pAStack_10c) goto LAB_0060ed04;
LAB_0060eea4:
        pAStack_288 = &AStack_124;
        iVar7 = (**(code **)(puStack_188 + -0x69e4))(pAStack_288);
        if (iVar7 != 0) {
          pAVar9->length = (int)puStack_1fc;
          if (pAVar9->data != (uchar *)0x0) {
            (**(code **)(puStack_188 + -0x7f58))();
          }
          pAVar9->data = puStack_138;
          pAVar13 = (ASN1_STRING *)AStack_124.length;
          if (ppAStack_178 != (ASN1_STRING **)0x0) {
            (**(code **)(puStack_188 + -0x6644))(ppAStack_178);
            pAVar13 = (ASN1_STRING *)AStack_124.length;
          }
          goto LAB_0060ee40;
        }
LAB_0060ed80:
        if (ppAStack_178 != (ASN1_STRING **)0x0) goto LAB_0060ed88;
        goto LAB_0060ed9c;
      }
      pcStack_27c = (char *)(puStack_108 + -AStack_124.length);
      AStack_124.type = (**(code **)(puStack_188 + -0x69e0))(unaff_s7);
      if (AStack_124.type != 0) goto LAB_0060eea4;
LAB_0060ed04:
      pAVar13 = pAStack_114;
      pAStack_17c = pAStack_110;
      pAStack_104 = (ASN1_STRING *)AStack_124.length;
      unaff_s5 = (ASN1_STRING *)(puStack_108 + -AStack_124.length);
      ppAVar15 = ppAStack_178;
      if ((ppAStack_178 == (ASN1_STRING **)0x0) &&
         (ppAVar15 = (ASN1_STRING **)(**(code **)(puStack_188 + -0x6650))(),
         ppAVar15 == (ASN1_STRING **)0x0)) goto LAB_0060ed9c;
      pcStack_27c = auStack_154 + 8;
      pAStack_150 = (ASN1_STRING *)AStack_124.length;
      pcStack_278 = (char *)pAStack_200;
      pcVar17 = (char *)unaff_s6;
      pAStack_198 = unaff_s5;
      uVar2 = (**(code **)(puStack_188 + -0x6e30))(auStack_154 + 4);
      if ((uVar2 & 0x80) != 0) {
        AStack_124.data = (uchar *)0x66;
LAB_0060ed64:
        if (ppAVar15 != ppAStack_178) {
          (**(code **)(puStack_188 + -0x6644))(ppAVar15);
        }
        goto LAB_0060ed80;
      }
      if (pAVar13 != auStack_14c._4_4_) {
        AStack_124.data = &DAT_000000a8;
        goto LAB_0060ed64;
      }
      if ((uVar2 & 0x20) == 0) {
        if (auStack_14c._0_4_ == (ASN1_STRING *)0x0) {
          if (ppAVar15[2] == (ASN1_STRING *)0x0) {
            unaff_s5 = (ASN1_STRING *)0x0;
            AStack_124.length = (int)pAStack_150;
          }
          else {
            unaff_s5 = (ASN1_STRING *)0x0;
            (**(code **)(puStack_188 + -0x7f58))();
            AStack_124.length = (int)pAStack_150;
          }
        }
        else {
          if (((int)*ppAVar15 < (int)auStack_14c._0_4_) ||
             (unaff_s5 = ppAVar15[2], unaff_s5 == (ASN1_STRING *)0x0)) {
            pcStack_278 = &DAT_000000e9;
            pcStack_27c = pcStack_164;
            unaff_s5 = (ASN1_STRING *)
                       (**(code **)(puStack_188 + -0x7dd8))
                                 ((uchar *)((int)&(auStack_14c._0_4_)->length + 1));
            if (unaff_s5 == (ASN1_STRING *)0x0) {
              AStack_124.data = &DAT_00000041;
              goto LAB_0060ed64;
            }
            if (ppAVar15[2] != (ASN1_STRING *)0x0) {
              (**(code **)(puStack_188 + -0x7f58))();
            }
          }
          pcStack_278 = (char *)auStack_14c._0_4_;
          (**(code **)(puStack_188 + -0x52f4))(unaff_s5,pAStack_150);
          *(uchar *)((int)&(auStack_14c._0_4_)->length + (int)&unaff_s5->length) = '\0';
          AStack_124.length = (int)((int)&(auStack_14c._0_4_)->length + (int)&pAStack_150->length);
        }
        *ppAVar15 = auStack_14c._0_4_;
        ppAVar15[2] = unaff_s5;
        ppAVar15[1] = pAVar13;
        pAVar13 = auStack_14c._0_4_;
      }
      else {
        AStack_f8.data = (uchar *)0x0;
        AStack_f8.length = (int)pAStack_150;
        pAStack_e0 = auStack_14c._0_4_;
        pAStack_e8 = pAVar13;
        pAStack_e4 = pAStack_17c;
        if (unaff_s5 == (ASN1_STRING *)0x0) {
          puStack_dc = (uchar *)0x0;
        }
        else {
          puStack_dc = (uchar *)((int)&unaff_s5->length + (int)&pAStack_150->length);
        }
        pAStack_16c = &AStack_f8;
        pAStack_17c = (ASN1_STRING *)0x0;
        auStack_144._4_4_ = (ASN1_STRING **)0x0;
        unaff_s5 = (ASN1_STRING *)(auStack_144 + 4);
        ppuStack_168 = &AStack_f8.data;
        uStack_130 = 0;
        uStack_128 = 0;
        pAStack_12c = (ASN1_STRING *)0x0;
        pcStack_27c = (char *)auStack_14c._0_4_;
        AStack_f8.flags = uVar2;
        pAStack_d4 = unaff_s7;
        if ((uVar2 & 1) != 0) goto LAB_0060f054;
        while (pcVar19 = *(code **)(puStack_188 + -0x69e4), 0 < (int)pAStack_e0) {
          while( true ) {
            ppuStack_190 = ppuStack_168;
            pAStack_198 = pAStack_e4;
            pcStack_278 = (char *)(puStack_dc + -AStack_f8.length);
            pAStack_d8 = (ASN1_STRING *)AStack_f8.length;
            uStack_194 = 2;
            pcStack_27c = (char *)pAStack_16c;
            pcVar17 = (char *)pAStack_e8;
            iVar7 = int_d2i_ASN1_bytes(unaff_s5);
            if (iVar7 == 0) goto LAB_0060f1ac;
            pcStack_27c = (char *)((int)&(*auStack_144._4_4_)->length + (int)&pAStack_17c->length);
            iVar7 = (**(code **)(puStack_188 + -0x72a0))(&uStack_130);
            if (iVar7 == 0) {
              AStack_f8.data = &DAT_00000007;
              goto LAB_0060f1ac;
            }
            pcStack_278 = (char *)*auStack_144._4_4_;
            pcStack_27c = (char *)auStack_144._4_4_[2];
            (**(code **)(puStack_188 + -0x52f4))
                      ((uchar *)((int)&pAStack_17c->length + (int)&pAStack_12c->length));
            if ((AStack_f8.flags & 1U) == 0) {
              pcStack_27c = (char *)(AStack_f8.length - (int)pAStack_d8);
              pAStack_e0 = (ASN1_STRING *)((int)pAStack_e0 - (int)pcStack_27c);
            }
            pAStack_17c = (ASN1_STRING *)
                          ((int)&(*auStack_144._4_4_)->length + (int)&pAStack_17c->length);
            if ((AStack_f8.flags & 1U) == 0) break;
LAB_0060f054:
            pcStack_27c = (char *)(puStack_dc + -AStack_f8.length);
            AStack_f8.type = (**(code **)(puStack_188 + -0x69e0))(pAStack_16c);
            if (AStack_f8.type != 0) {
              pcVar19 = *(code **)(puStack_188 + -0x69e4);
              goto LAB_0060f07c;
            }
          }
        }
LAB_0060f07c:
        iVar7 = (*pcVar19)(pAStack_16c);
        if (iVar7 == 0) {
LAB_0060f1ac:
          if (auStack_144._4_4_ != (ASN1_STRING **)0x0) {
            (**(code **)(puStack_188 + -0x6644))();
          }
          if (pAStack_12c != (ASN1_STRING *)0x0) {
            (**(code **)(puStack_188 + -0x7f58))();
          }
          AStack_124.data = AStack_f8.data;
          goto LAB_0060ed64;
        }
        *ppAVar15 = pAStack_17c;
        if (ppAVar15[2] != (ASN1_STRING *)0x0) {
          (**(code **)(puStack_188 + -0x7f58))();
        }
        ppAVar15[2] = pAStack_12c;
        if (auStack_144._4_4_ != (ASN1_STRING **)0x0) {
          (**(code **)(puStack_188 + -0x6644))();
        }
        AStack_124.length = AStack_f8.length;
        pAVar13 = *ppAVar15;
      }
      pcStack_27c = puStack_1fc + (int)pAVar13;
      iVar7 = (**(code **)(puStack_188 + -0x72a0))(&puStack_13c);
      if (iVar7 == 0) goto LAB_0060f214;
      pcStack_278 = (char *)*ppAVar15;
      pcStack_27c = (char *)ppAVar15[2];
      (**(code **)(puStack_188 + -0x52f4))(puStack_138 + (int)puStack_1fc);
      uVar5 = AStack_124.flags & 1;
      if (uVar5 == 0) {
        pcStack_27c = (char *)(AStack_124.length - (int)pAStack_104);
        pAStack_10c = (ASN1_STRING *)((int)pAStack_10c - (int)pcStack_27c);
      }
      puStack_1fc = puStack_1fc + (int)*ppAVar15;
      ppAStack_178 = ppAVar15;
    } while( true );
  }
  if (auStack_15c._0_4_ == (ASN1_STRING *)0x0) {
    if (pAVar9->data == (uchar *)0x0) {
      pAStack_288 = (ASN1_STRING *)0x0;
      pAVar13 = pAStack_160;
    }
    else {
      pAStack_288 = (ASN1_STRING *)0x0;
      (**(code **)(puStack_188 + -0x7f58))();
      pAVar13 = pAStack_160;
    }
  }
  else {
    if (pAVar9->length < (int)auStack_15c._0_4_) {
      pcVar19 = *(code **)(puStack_188 + -0x7dd8);
LAB_0060f228:
      pcStack_278 = &DAT_000000e9;
      pcStack_27c = "a_bytes.c";
      pAStack_288 = (ASN1_STRING *)(*pcVar19)((uchar *)((int)&(auStack_15c._0_4_)->length + 1));
      if (pAStack_288 == (ASN1_STRING *)0x0) {
        pAStack_288 = (ASN1_STRING *)&DAT_00000041;
        goto LAB_0060ec2c;
      }
      if (pAVar9->data != (uchar *)0x0) {
        (**(code **)(puStack_188 + -0x7f58))();
      }
    }
    else {
      pAStack_288 = (ASN1_STRING *)pAVar9->data;
      pcVar19 = *(code **)(puStack_188 + -0x7dd8);
      if (pAStack_288 == (ASN1_STRING *)0x0) goto LAB_0060f228;
    }
    pcStack_27c = (char *)pAStack_160;
    pcStack_278 = (char *)auStack_15c._0_4_;
    (**(code **)(puStack_188 + -0x52f4))(pAStack_288);
    *(uchar *)((int)&(auStack_15c._0_4_)->length + (int)&pAStack_288->length) = '\0';
    pAVar13 = (ASN1_STRING *)((int)&(auStack_15c._0_4_)->length + (int)&pAStack_160->length);
  }
  pAVar9->length = (int)auStack_15c._0_4_;
  pAVar9->data = (uchar *)pAStack_288;
  pAVar9->type = (int)pAVar18;
LAB_0060ee40:
  if (ppAStack_204 != (ASN1_STRING **)0x0) {
    *ppAStack_204 = pAVar9;
  }
  pAStack_174->length = (int)pAVar13;
  goto LAB_0060eb94;
LAB_0060f214:
  AStack_124.data = &DAT_00000007;
  ppAStack_178 = ppAVar15;
LAB_0060ed88:
  (**(code **)(puStack_188 + -0x6644))(ppAStack_178);
LAB_0060ed9c:
  pAStack_288 = (ASN1_STRING *)AStack_124.data;
  if (puStack_138 != (uchar *)0x0) {
    (**(code **)(puStack_188 + -0x7f58))();
    pAStack_288 = (ASN1_STRING *)AStack_124.data;
  }
LAB_0060ec2c:
  pcVar19 = *(code **)(puStack_188 + -0x6644);
  if ((ppAStack_204 == (ASN1_STRING **)0x0) || (*ppAStack_204 != pAStack_1b0)) {
LAB_0060eb80:
    (*pcVar19)(pAStack_1b0);
    if (pAStack_288 != (ASN1_STRING *)0x0) {
LAB_0060ec50:
      pcVar19 = *(code **)(puStack_188 + -0x6eac);
      goto LAB_0060ec58;
    }
  }
  else if (pAStack_288 != (ASN1_STRING *)0x0) {
    pcVar19 = *(code **)(puStack_188 + -0x6eac);
LAB_0060ec58:
    pcStack_27c = (char *)0x8f;
    pcVar17 = "a_bytes.c";
    pAStack_198 = (ASN1_STRING *)0xaf;
    pcStack_278 = (char *)pAStack_288;
    (*pcVar19)(0xd);
    pAVar9 = (ASN1_STRING *)0x0;
    goto LAB_0060eb94;
  }
LAB_0060eb90:
  pAVar9 = (ASN1_STRING *)0x0;
LAB_0060eb94:
  if (puStack_cc == *ppuStack_170) {
    return pAVar9;
  }
  uStack_1ac = 0x60f2d8;
  puStack_1b8 = puStack_cc;
  (**(code **)(puStack_188 + -0x5330))();
  pAStack_240 = (ASN1_STRING *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_280 = &puStack_1b8;
  psStack_1b4 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  pAVar9 = (ASN1_STRING *)
           d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_280,(long)pcStack_27c,pcStack_278,
                        (free_func *)pcVar17,0x10,0);
  if (pAVar9 == (ASN1_STRING *)0x0) {
    pcStack_27c = &DAT_0000006e;
    pcStack_278 = "asn_pack.c";
    ppuStack_280 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_1b4 == *(stack_st_OPENSSL_BLOCK **)pAStack_240) {
    return pAVar9;
  }
  pcStack_1ec = ASN1_seq_pack;
  a_00 = psStack_1b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_284 = PTR___stack_chk_guard_006a9ae8;
  puStack_20c = (undefined *)pAStack_240;
  puStack_214 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pAStack_208 = pAStack_288;
  pAStack_1f8 = unaff_s5;
  pAStack_1f4 = unaff_s6;
  pAStack_1f0 = unaff_s7;
  pAVar9 = (ASN1_STRING *)i2d_ASN1_SET(a_00,(uchar **)0x0,(undefined1 *)ppuStack_280,0x10,0,0);
  if (pAVar9 == (ASN1_STRING *)0x0) {
    ppAVar15 = (ASN1_STRING **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    pAVar9 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_240 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAVar9,"asn_pack.c",0x62);
    pAStack_288 = pAVar9;
    if (pAStack_240 == (ASN1_STRING *)0x0) {
      ppAVar15 = (ASN1_STRING **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      pAVar9 = (ASN1_STRING *)0x0;
    }
    else {
      ppAVar15 = &pAStack_218;
      pAStack_218 = pAStack_240;
      i2d_ASN1_SET(a_00,(uchar **)ppAVar15,(undefined1 *)ppuStack_280,0x10,0,0);
      if ((ASN1_STRING *)pcStack_278 != (ASN1_STRING *)0x0) {
        *(int *)pcStack_278 = (int)pAVar9;
      }
      pAVar9 = pAStack_240;
      if ((ASN1_STRING *)pcStack_27c != (ASN1_STRING *)0x0) {
        *(int *)pcStack_27c = (int)pAStack_240;
      }
    }
  }
  if (puStack_214 == *(undefined4 **)puStack_284) {
    return pAVar9;
  }
  pcStack_23c = ASN1_unpack_string;
  puVar11 = puStack_214;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_28c = PTR___stack_chk_guard_006a9ae8;
  uStack_248 = puVar11[2];
  ppAVar14 = (ASN1_STRING **)*puVar11;
  puVar11 = &uStack_248;
  puStack_258 = &_gp;
  iStack_244 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar9 = (ASN1_STRING *)(*(code *)ppAVar15)(0);
  if (pAVar9 == (ASN1_STRING *)0x0) {
    ppAVar14 = (ASN1_STRING **)&DAT_0000006e;
    uStack_260 = 0x79;
    puVar11 = (undefined4 *)&DAT_00000088;
    pAStack_24c = pAVar9;
    (**(code **)(puStack_258 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    pAVar9 = pAStack_24c;
  }
  if (iStack_244 == *(int *)puStack_28c) {
    return pAVar9;
  }
  pcStack_274 = ASN1_pack_string;
  iVar7 = iStack_244;
  (**(code **)(puStack_258 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_294 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppAVar14 == (ASN1_STRING **)0x0) {
    pAVar9 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar9 != (ASN1_STRING *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppAVar15 = (ASN1_STRING **)&DAT_00000041;
    ppuVar12 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    pAVar13 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar9 = *ppAVar14;
    if (pAVar9 == (ASN1_STRING *)0x0) {
      pAVar9 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_0060f754;
      *ppAVar14 = pAVar9;
    }
LAB_0060f614:
    iVar6 = (*(code *)puVar11)(iVar7,0);
    pAVar9->length = iVar6;
    if (iVar6 == 0) {
      ppAVar15 = (ASN1_STRING **)&DAT_00000070;
      ppuVar12 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppAVar15 = (ASN1_STRING **)&DAT_00000092;
      puStack_298 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar6,"asn_pack.c");
      if (puStack_298 != (uchar *)0x0) {
        ppuVar12 = &puStack_298;
        pAVar9->data = puStack_298;
        (*(code *)puVar11)(iVar7,ppuVar12);
        pAVar13 = pAVar9;
        goto LAB_0060f670;
      }
      ppAVar15 = (ASN1_STRING **)&DAT_00000041;
      ppuVar12 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppAVar14 == (ASN1_STRING **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar9);
      pAVar13 = (ASN1_STRING *)0x0;
    }
    else {
      pAVar13 = *ppAVar14;
      if (pAVar13 == (ASN1_STRING *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar9);
        *ppAVar14 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar13 = (ASN1_STRING *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_294 == *(int *)puVar1) {
    return pAVar13;
  }
  iVar7 = iStack_294;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppAVar15 == (ASN1_STRING **)0x0) {
    pAVar9 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar9 == (ASN1_STRING *)0x0) {
LAB_0060f874:
      uVar16 = 0x41;
      uVar8 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    pAVar9 = *ppAVar15;
    if (pAVar9 == (ASN1_STRING *)0x0) {
      pAVar9 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_0060f874;
      *ppAVar15 = pAVar9;
    }
  }
  if (pAVar9->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    pAVar9->data = (uchar *)0x0;
  }
  iVar7 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar7,&pAVar9->data,ppuVar12);
  pAVar9->length = iVar7;
  if (iVar7 == 0) {
    uVar16 = 0x70;
    uVar8 = 0xba;
  }
  else {
    if (pAVar9->data != (uchar *)0x0) {
      return pAVar9;
    }
    uVar16 = 0x41;
    uVar8 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar16,"asn_pack.c",uVar8);
  return (ASN1_STRING *)0x0;
}

