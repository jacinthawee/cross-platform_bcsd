
int i2d_ASN1_bytes(ASN1_STRING *a,uchar **pp,int tag,int xclass)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  ASN1_STRING *pAVar4;
  stack_st_OPENSSL_BLOCK *psVar5;
  ASN1_STRING *pAVar6;
  uchar *puVar7;
  int iVar8;
  undefined4 uVar9;
  uchar **pp_00;
  undefined4 *puVar10;
  int *piVar11;
  char *d2i;
  int **ppiVar12;
  undefined4 uVar13;
  char *free_func;
  ASN1_STRING *unaff_s0;
  int *piVar14;
  int unaff_s1;
  int unaff_s2;
  ASN1_STRING *pp_01;
  uchar **unaff_s3;
  ASN1_STRING *unaff_s5;
  ASN1_STRING *unaff_s6;
  uchar **unaff_s7;
  int iStack_1c8;
  int iStack_1c4;
  undefined *puStack_1c0;
  ASN1_STRING *pAStack_1bc;
  undefined *puStack_1b8;
  uchar **ppuStack_1b4;
  ASN1_STRING *pAStack_1b0;
  code *pcStack_1ac;
  undefined4 uStack_198;
  undefined *puStack_190;
  int iStack_184;
  undefined4 uStack_180;
  int iStack_17c;
  uchar *puStack_178;
  code *pcStack_174;
  uchar *puStack_150;
  undefined4 *puStack_14c;
  undefined *puStack_144;
  ASN1_STRING *pAStack_140;
  ASN1_STRING *pAStack_13c;
  ASN1_STRING **ppAStack_138;
  ASN1_STRING *pAStack_134;
  undefined *puStack_130;
  ASN1_STRING *pAStack_12c;
  uchar **ppuStack_128;
  code *pcStack_124;
  uchar *puStack_f0;
  stack_st_OPENSSL_BLOCK *psStack_ec;
  ASN1_STRING *pAStack_e8;
  undefined4 uStack_e4;
  ASN1_STRING *pAStack_c0;
  undefined auStack_bc [8];
  undefined auStack_b4 [8];
  uchar *puStack_ac;
  uchar *puStack_a8;
  undefined4 uStack_a4;
  ASN1_STRING AStack_a0;
  ASN1_STRING *pAStack_90;
  int iStack_8c;
  ASN1_STRING *pAStack_88;
  code *pcStack_84;
  ASN1_STRING *pAStack_80;
  ASN1_STRING *pAStack_7c;
  uchar *puStack_74;
  ASN1_STRING *pAStack_6c;
  int iStack_68;
  int iStack_64;
  uchar **ppuStack_60;
  undefined *puStack_5c;
  ASN1_STRING *pAStack_58;
  ASN1_STRING *pAStack_54;
  int local_38;
  uchar *local_28;
  ASN1_STRING **local_24;
  
  puStack_5c = PTR___stack_chk_guard_006aabf0;
  local_24 = *(ASN1_STRING ***)PTR___stack_chk_guard_006aabf0;
  iVar2 = 0;
  pAStack_134 = (ASN1_STRING *)pp;
  pAStack_e8 = (ASN1_STRING *)tag;
  pAStack_13c = (ASN1_STRING *)xclass;
  iStack_64 = unaff_s2;
  if (a != (ASN1_STRING *)0x0) {
    iStack_64 = tag;
    if (tag == 3) {
      iVar2 = (*(code *)PTR_i2d_ASN1_BIT_STRING_006aa90c)();
      pAStack_134 = (ASN1_STRING *)pp;
      pAStack_13c = (ASN1_STRING *)xclass;
    }
    else {
      unaff_s5 = (ASN1_STRING *)a->length;
      pAStack_134 = unaff_s5;
      iVar2 = (*(code *)PTR_ASN1_object_size_006a94fc)(0);
      unaff_s0 = a;
      unaff_s1 = iVar2;
      unaff_s3 = pp;
      unaff_s6 = (ASN1_STRING *)xclass;
      if (pp != (uchar **)0x0) {
        local_28 = *pp;
        pAStack_13c = (ASN1_STRING *)tag;
        (*(code *)PTR_ASN1_put_object_006a9500)(&local_28,tag - 0x10U < 2,unaff_s5);
        pAStack_e8 = (ASN1_STRING *)a->length;
        pAStack_134 = (ASN1_STRING *)a->data;
        (*(code *)PTR_memcpy_006aabf4)(local_28);
        *pp = local_28 + a->length;
        local_38 = xclass;
      }
    }
  }
  if (local_24 == *(ASN1_STRING ***)puStack_5c) {
    return iVar2;
  }
  ppAStack_138 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  puStack_74 = *(uchar **)PTR___stack_chk_guard_006aabf0;
  free_func = (char *)pAStack_13c;
  pAStack_6c = unaff_s0;
  iStack_68 = unaff_s1;
  ppuStack_60 = unaff_s3;
  pAStack_58 = unaff_s5;
  pAStack_54 = unaff_s6;
  if (ppAStack_138 == (ASN1_STRING **)0x0) {
LAB_0061032c:
    pAStack_1b0 = pAStack_134;
    d2i = (char *)pAStack_e8;
    pAStack_1bc = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAStack_1bc != (ASN1_STRING *)0x0) {
      pAStack_c0 = (ASN1_STRING *)pAStack_134->length;
      free_func = auStack_b4;
      d2i = auStack_bc + 4;
      pAStack_1b0 = (ASN1_STRING *)auStack_bc;
      uVar3 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_c0);
      pAVar6 = pAStack_1bc;
      if ((uVar3 & 0x80) == 0) goto LAB_006100f0;
      pAStack_13c = (ASN1_STRING *)0x66;
      goto LAB_00610378;
    }
    pAVar6 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_1bc = *ppAStack_138;
    free_func = auStack_b4;
    if (pAStack_1bc == (ASN1_STRING *)0x0) goto LAB_0061032c;
    pAStack_c0 = (ASN1_STRING *)pAStack_134->length;
    d2i = auStack_bc + 4;
    pAStack_1b0 = (ASN1_STRING *)auStack_bc;
    uVar3 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_c0);
    pAVar6 = pAStack_1bc;
    if ((uVar3 & 0x80) == 0) {
LAB_006100f0:
      pAStack_1bc = pAVar6;
      unaff_s6 = auStack_bc._4_4_;
      if (auStack_bc._4_4_ == pAStack_13c) {
        if ((uVar3 & 0x20) == 0) {
          if (auStack_bc._0_4_ == (ASN1_STRING *)0x0) {
            if (pAVar6->data == (uchar *)0x0) {
              free_func = (char *)0x0;
              pAVar4 = pAStack_c0;
            }
            else {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              free_func = (char *)0x0;
              pAVar4 = pAStack_c0;
            }
          }
          else {
            if (pAVar6->length < (int)auStack_bc._0_4_) {
              if (pAVar6->data != (uchar *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
LAB_00610428:
              pAStack_e8 = (ASN1_STRING *)0x680000;
              puVar7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                          ((code *)((int)&(auStack_bc._0_4_)->length + 1),
                                           "a_bytes.c",0xd5);
              if (puVar7 == (uchar *)0x0) {
                pAStack_13c = (ASN1_STRING *)&DAT_00000041;
                goto LAB_00610378;
              }
            }
            else {
              puVar7 = pAVar6->data;
              if (puVar7 == (uchar *)0x0) goto LAB_00610428;
            }
            pAStack_1b0 = pAStack_c0;
            d2i = (char *)auStack_bc._0_4_;
            free_func = (char *)(*(code *)PTR_memcpy_006aabf4)(puVar7);
            *(code *)((int)&(auStack_bc._0_4_)->length + (int)(int *)free_func) = (code)0x0;
            pAVar4 = (ASN1_STRING *)((int)&(auStack_bc._0_4_)->length + (int)&pAStack_c0->length);
          }
          pAVar6->length = (int)auStack_bc._0_4_;
          pAVar6->data = (uchar *)free_func;
          pAVar6->type = (int)auStack_bc._4_4_;
          pp_01 = pAStack_13c;
        }
        else {
          pAStack_88 = auStack_bc._0_4_;
          AStack_a0.length = (int)pAStack_c0;
          iStack_8c = local_38;
          if (pAStack_e8 == (ASN1_STRING *)0x0) {
            pcStack_84 = (code *)0x0;
          }
          else {
            pcStack_84 = (code *)((int)&pAStack_e8->length + (int)&pAStack_c0->length);
          }
          pAStack_e8 = (ASN1_STRING *)0x0;
          auStack_b4._4_4_ = (ASN1_STRING **)0x0;
          pp_01 = &AStack_a0;
          puStack_ac = (uchar *)0x0;
          auStack_bc._4_4_ = (ASN1_STRING *)(auStack_b4 + 4);
          uStack_a4 = 0;
          unaff_s7 = &puStack_ac;
          puStack_a8 = (uchar *)0x0;
          AStack_a0.flags = uVar3;
          pAStack_90 = pAStack_13c;
          pAStack_7c = pAStack_134;
          if ((uVar3 & 1) != 0) goto LAB_00610208;
          while (0 < (int)pAStack_88) {
            while( true ) {
              pAStack_80 = (ASN1_STRING *)AStack_a0.length;
              free_func = (char *)pAStack_90;
              pAVar4 = d2i_ASN1_bytes((ASN1_STRING **)auStack_bc._4_4_,(uchar **)pp_01,
                                      (int)pcStack_84 - AStack_a0.length,(int)pAStack_90,iStack_8c);
              if (pAVar4 == (ASN1_STRING *)0x0) {
                AStack_a0.data = &DAT_0000000d;
                goto LAB_00610460;
              }
              iVar2 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                (unaff_s7,(code *)((int)&(*auStack_b4._4_4_)->length +
                                                  (int)&pAStack_e8->length));
              if (iVar2 == 0) {
                AStack_a0.data = &DAT_00000007;
                goto LAB_00610460;
              }
              d2i = (char *)*auStack_b4._4_4_;
              pAStack_1b0 = auStack_b4._4_4_[2];
              (*(code *)PTR_memcpy_006aabf4)(puStack_a8 + (int)pAStack_e8);
              if ((AStack_a0.flags & 1U) == 0) {
                pAStack_88 = (ASN1_STRING *)((int)pAStack_88 - (AStack_a0.length - (int)pAStack_80))
                ;
              }
              pAStack_e8 = (ASN1_STRING *)
                           ((int)&(*auStack_b4._4_4_)->length + (int)&pAStack_e8->length);
              if ((AStack_a0.flags & 1U) == 0) break;
LAB_00610208:
              pAStack_1b0 = (ASN1_STRING *)(pcStack_84 + -AStack_a0.length);
              AStack_a0.type = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(pp_01);
              if (AStack_a0.type != 0) goto LAB_00610230;
            }
          }
LAB_00610230:
          iVar2 = (*(code *)PTR_asn1_const_Finish_006a9518)(pp_01);
          if (iVar2 == 0) {
LAB_00610460:
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x69,AStack_a0.data,"a_bytes.c");
            if (auStack_b4._4_4_ != (ASN1_STRING **)0x0) {
              (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            }
            if (puStack_a8 != (uchar *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
            }
            pAStack_13c = (ASN1_STRING *)0x0;
            unaff_s6 = auStack_bc._4_4_;
            goto LAB_00610378;
          }
          pAVar6->length = (int)pAStack_e8;
          if (pAVar6->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pAVar6->data = puStack_a8;
          pAVar4 = (ASN1_STRING *)AStack_a0.length;
          if (auStack_b4._4_4_ != (ASN1_STRING **)0x0) {
            (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            pAVar4 = (ASN1_STRING *)AStack_a0.length;
          }
        }
        if (ppAStack_138 != (ASN1_STRING **)0x0) {
          *ppAStack_138 = pAVar6;
        }
        pAStack_134->length = (int)pAVar4;
        pAStack_13c = pp_01;
        unaff_s6 = auStack_bc._4_4_;
        goto LAB_00610294;
      }
      pAStack_13c = (ASN1_STRING *)&DAT_000000a8;
LAB_00610378:
      if (ppAStack_138 != (ASN1_STRING **)0x0) goto LAB_00610380;
LAB_0061038c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_1bc);
    }
    else {
      pAStack_13c = (ASN1_STRING *)0x66;
LAB_00610380:
      if (pAStack_1bc != *ppAStack_138) goto LAB_0061038c;
    }
    pAStack_e8 = (ASN1_STRING *)0x680000;
    free_func = "a_bytes.c";
    pAStack_1b0 = (ASN1_STRING *)0x8f;
    d2i = (char *)pAStack_13c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pAVar6 = (ASN1_STRING *)0x0;
  }
LAB_00610294:
  if (puStack_74 == *(uchar **)puStack_130) {
    return (int)pAVar6;
  }
  uStack_e4 = 0x610508;
  puStack_f0 = puStack_74;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_178 = PTR___stack_chk_guard_006aabf0;
  ppuStack_1b4 = &puStack_f0;
  psStack_ec = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  psVar5 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_1b4,(long)pAStack_1b0,d2i,
                        (free_func *)free_func,0x10,0);
  if (psVar5 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pAStack_1b0 = (ASN1_STRING *)&DAT_0000006e;
    d2i = "asn_pack.c";
    ppuStack_1b4 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
  }
  if (psStack_ec == *(stack_st_OPENSSL_BLOCK **)puStack_178) {
    return (int)psVar5;
  }
  pcStack_124 = ASN1_seq_pack;
  psVar5 = psStack_ec;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1b8 = PTR___stack_chk_guard_006aabf0;
  puStack_144 = puStack_178;
  puStack_14c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAStack_140 = pAStack_1bc;
  pAStack_12c = unaff_s6;
  ppuStack_128 = unaff_s7;
  pAVar6 = (ASN1_STRING *)i2d_ASN1_SET(psVar5,(uchar **)0x0,(undefined1 *)ppuStack_1b4,0x10,0,0);
  if (pAVar6 == (ASN1_STRING *)0x0) {
    pp_00 = (uchar **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    puVar7 = (uchar *)0x0;
  }
  else {
    puStack_178 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAVar6,"asn_pack.c",0x5f);
    pAStack_1bc = pAVar6;
    if (puStack_178 == (uchar *)0x0) {
      pp_00 = (uchar **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      puVar7 = (uchar *)0x0;
    }
    else {
      pp_00 = &puStack_150;
      puStack_150 = puStack_178;
      i2d_ASN1_SET(psVar5,pp_00,(undefined1 *)ppuStack_1b4,0x10,0,0);
      if ((ASN1_STRING *)d2i != (ASN1_STRING *)0x0) {
        *(int *)d2i = (int)pAVar6;
      }
      puVar7 = puStack_178;
      if (pAStack_1b0 != (ASN1_STRING *)0x0) {
        pAStack_1b0->length = (int)puStack_178;
      }
    }
  }
  if (puStack_14c == *(undefined4 **)puStack_1b8) {
    return (int)puVar7;
  }
  pcStack_174 = ASN1_unpack_string;
  puVar10 = puStack_14c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1c0 = PTR___stack_chk_guard_006aabf0;
  uStack_180 = puVar10[2];
  ppiVar12 = (int **)*puVar10;
  puVar10 = &uStack_180;
  puStack_190 = &_gp;
  iStack_17c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)pp_00)(0);
  if (iVar2 == 0) {
    ppiVar12 = (int **)&DAT_0000006e;
    uStack_198 = 0x74;
    puVar10 = (undefined4 *)&DAT_00000088;
    iStack_184 = iVar2;
    (**(code **)(puStack_190 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    iVar2 = iStack_184;
  }
  if (iStack_17c == *(int *)puStack_1c0) {
    return iVar2;
  }
  pcStack_1ac = ASN1_pack_string;
  iVar2 = iStack_17c;
  (**(code **)(puStack_190 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppiVar12 == (int **)0x0) {
    piVar14 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar14 != (int *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppiVar12 = (int **)&DAT_00000041;
    uVar9 = 0x81;
LAB_006108f8:
    piVar11 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppiVar12,"asn_pack.c",uVar9);
    piVar14 = (int *)0x0;
  }
  else {
    piVar14 = *ppiVar12;
    if (piVar14 == (int *)0x0) {
      piVar14 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar14 == (int *)0x0) goto LAB_00610928;
      *ppiVar12 = piVar14;
    }
LAB_0061083c:
    iVar8 = (*(code *)puVar10)(iVar2,0);
    *piVar14 = iVar8;
    if (iVar8 == 0) {
      ppiVar12 = (int **)&DAT_00000070;
      uVar9 = 0x88;
      goto LAB_006108f8;
    }
    ppiVar12 = (int **)&DAT_0000008b;
    iStack_1c8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8,"asn_pack.c");
    if (iStack_1c8 == 0) {
      ppiVar12 = (int **)&DAT_00000041;
      piVar11 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      piVar14 = (int *)0x0;
    }
    else {
      piVar11 = &iStack_1c8;
      piVar14[2] = iStack_1c8;
      (*(code *)puVar10)(iVar2,piVar11);
    }
  }
  if (iStack_1c4 == *(int *)puVar1) {
    return (int)piVar14;
  }
  iVar2 = iStack_1c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppiVar12 == (int **)0x0) {
    piVar14 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar14 == (int *)0x0) {
LAB_00610a48:
      uVar13 = 0x41;
      uVar9 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    piVar14 = *ppiVar12;
    if (piVar14 == (int *)0x0) {
      piVar14 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar14 == (int *)0x0) goto LAB_00610a48;
      *ppiVar12 = piVar14;
    }
  }
  if (piVar14[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    piVar14[2] = 0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar2,piVar14 + 2,piVar11);
  *piVar14 = iVar2;
  if (iVar2 == 0) {
    uVar13 = 0x70;
    uVar9 = 0xaa;
  }
  else {
    if (piVar14[2] != 0) {
      return (int)piVar14;
    }
    uVar13 = 0x41;
    uVar9 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar13,"asn_pack.c",uVar9);
  return 0;
}

