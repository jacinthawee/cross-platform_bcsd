
ASN1_STRING * d2i_ASN1_type_bytes(ASN1_STRING **a,uchar **pp,long length,int type)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  ASN1_STRING *pAVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  stack_st_OPENSSL_BLOCK *a_00;
  ASN1_STRING *pAVar8;
  undefined4 *puVar9;
  uchar **ppuVar10;
  ASN1_STRING *pAVar11;
  char *d2i;
  ASN1_STRING **ppAVar12;
  ASN1_STRING **ppAVar13;
  undefined4 uVar14;
  char *pcVar15;
  uchar *puVar16;
  ASN1_STRING *unaff_s5;
  ASN1_STRING *unaff_s6;
  uchar **unaff_s7;
  uchar *puStack_220;
  int iStack_21c;
  undefined *puStack_218;
  ASN1_STRING *pAStack_214;
  undefined *puStack_210;
  uchar **ppuStack_20c;
  ASN1_STRING *pAStack_208;
  code *pcStack_204;
  undefined4 uStack_1f0;
  undefined *puStack_1e8;
  ASN1_STRING *pAStack_1dc;
  undefined4 uStack_1d8;
  int iStack_1d4;
  ASN1_STRING *pAStack_1d0;
  code *pcStack_1cc;
  ASN1_STRING *pAStack_1a8;
  undefined4 *puStack_1a4;
  undefined *puStack_19c;
  ASN1_STRING *pAStack_198;
  ASN1_STRING *pAStack_194;
  ASN1_STRING **ppAStack_190;
  ASN1_STRING *pAStack_18c;
  undefined *puStack_188;
  ASN1_STRING *pAStack_184;
  uchar **ppuStack_180;
  code *pcStack_17c;
  uchar *puStack_148;
  stack_st_OPENSSL_BLOCK *psStack_144;
  ASN1_STRING *pAStack_140;
  undefined4 uStack_13c;
  ASN1_STRING *pAStack_118;
  undefined auStack_114 [8];
  undefined auStack_10c [8];
  uchar *puStack_104;
  uchar *puStack_100;
  undefined4 uStack_fc;
  ASN1_STRING AStack_f8;
  ASN1_STRING *pAStack_e8;
  ASN1_STRING *pAStack_e4;
  ASN1_STRING *pAStack_e0;
  code *pcStack_dc;
  ASN1_STRING *pAStack_d8;
  ASN1_STRING *pAStack_d4;
  uchar *puStack_cc;
  ASN1_STRING *pAStack_c4;
  ASN1_STRING *pAStack_c0;
  ASN1_STRING *pAStack_bc;
  ASN1_STRING *pAStack_b8;
  undefined *puStack_b4;
  ASN1_STRING *pAStack_b0;
  ASN1_STRING *pAStack_ac;
  ASN1_STRING *pAStack_90;
  ASN1_STRING *pAStack_80;
  ASN1_STRING **ppAStack_7c;
  ASN1_STRING *pAStack_78;
  ASN1_STRING **ppAStack_74;
  undefined *puStack_70;
  uchar **ppuStack_6c;
  uchar *puStack_68;
  ASN1_STRING *local_2c;
  ASN1_STRING local_28;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_2c = (ASN1_STRING *)*pp;
  pcVar15 = (char *)&local_28.data;
  pAVar8 = &local_28;
  local_28.flags = *(long *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_ASN1_get_object_006a9514)(&local_2c,pAVar8,&local_28.type);
  if ((uVar2 & 0x80) == 0) {
    pAVar11 = (ASN1_STRING *)0x99;
    if (0x1f < local_28.type) goto LAB_0060fd58;
    uVar2 = (*(code *)PTR_ASN1_tag2bit_006a9e08)();
    if ((type & uVar2) == 0) {
      pAVar11 = (ASN1_STRING *)0xa9;
      goto LAB_0060fd58;
    }
    if (local_28.type != 3) {
      if (((a == (ASN1_STRING **)0x0) ||
          (length = (long)*a, (ASN1_STRING *)length == (ASN1_STRING *)0x0)) &&
         (length = (*(code *)PTR_ASN1_STRING_new_006a98b4)(),
         (ASN1_STRING *)length == (ASN1_STRING *)0x0)) {
        pAVar3 = (ASN1_STRING *)0x0;
        goto LAB_0060fd80;
      }
      type = 0;
      if ((ASN1_STRING *)local_28.length == (ASN1_STRING *)0x0) {
LAB_0060fdfc:
        if (*(uchar **)(length + 8) != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        *(int *)(length + 8) = type;
        *(int *)length = local_28.length;
        *(int *)(length + 4) = local_28.type;
        if (a != (ASN1_STRING **)0x0) {
          *a = (ASN1_STRING *)length;
        }
        *pp = (uchar *)local_2c;
        pAVar3 = (ASN1_STRING *)length;
        goto LAB_0060fd80;
      }
      type = (*(code *)PTR_CRYPTO_malloc_006a8108)
                       ((code *)((int)(int *)local_28.length + 1),"a_bytes.c",0x68);
      pcVar15 = (char *)0x680000;
      if ((uchar *)type != (uchar *)0x0) {
        pAVar8 = local_2c;
        pAVar11 = (ASN1_STRING *)local_28.length;
        (*(code *)PTR_memcpy_006aabf4)(type);
        *(uchar *)(type + local_28.length) = '\0';
        local_2c = (ASN1_STRING *)((int)(int *)local_28.length + (int)&local_2c->length);
        goto LAB_0060fdfc;
      }
      pcVar15 = "a_bytes.c";
      pAVar11 = (ASN1_STRING *)&DAT_00000041;
      pAVar8 = (ASN1_STRING *)&DAT_00000095;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      if ((a == (ASN1_STRING **)0x0) || ((ASN1_STRING *)length != *a)) {
        (*(code *)PTR_ASN1_STRING_free_006a98bc)(length);
        pAVar3 = (ASN1_STRING *)0x0;
        goto LAB_0060fd80;
      }
      goto LAB_0060fd7c;
    }
    pAVar8 = (ASN1_STRING *)pp;
    pAVar11 = (ASN1_STRING *)length;
    pAVar3 = (ASN1_STRING *)(*(code *)PTR_d2i_ASN1_BIT_STRING_006aa908)(a);
  }
  else {
    pAVar11 = (ASN1_STRING *)0x0;
LAB_0060fd58:
    pAVar8 = (ASN1_STRING *)&DAT_00000095;
    pcVar15 = "a_bytes.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
LAB_0060fd7c:
    pAVar3 = (ASN1_STRING *)0x0;
  }
LAB_0060fd80:
  if ((ASN1_STRING *)local_28.flags == *(ASN1_STRING **)puStack_70) {
    return pAVar3;
  }
  pAVar3 = (ASN1_STRING *)local_28.flags;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_b4 = PTR___stack_chk_guard_006aabf0;
  ppAStack_7c = *(ASN1_STRING ***)PTR___stack_chk_guard_006aabf0;
  pAVar4 = (ASN1_STRING *)0x0;
  pAStack_18c = pAVar8;
  pAStack_140 = pAVar11;
  pAStack_194 = (ASN1_STRING *)pcVar15;
  pAStack_bc = (ASN1_STRING *)puStack_70;
  pAStack_78 = (ASN1_STRING *)length;
  ppAStack_74 = a;
  ppuStack_6c = pp;
  puStack_68 = (uchar *)type;
  if (pAVar3 != (ASN1_STRING *)0x0) {
    pAStack_bc = pAVar11;
    if (pAVar11 == (ASN1_STRING *)0x3) {
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_i2d_ASN1_BIT_STRING_006aa90c)();
      pAStack_18c = pAVar8;
      pAStack_194 = (ASN1_STRING *)pcVar15;
    }
    else {
      unaff_s5 = (ASN1_STRING *)pAVar3->length;
      pAStack_18c = unaff_s5;
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_object_size_006a94fc)(0);
      length = (long)pAVar3;
      a = (ASN1_STRING **)pAVar4;
      pp = (uchar **)pAVar8;
      unaff_s6 = (ASN1_STRING *)pcVar15;
      if (pAVar8 != (ASN1_STRING *)0x0) {
        pAStack_80 = (ASN1_STRING *)pAVar8->length;
        pAStack_194 = pAVar11;
        (*(code *)PTR_ASN1_put_object_006a9500)
                  (&pAStack_80,pAVar11 + -1 < (ASN1_STRING *)&SUB_00000002,unaff_s5);
        pAStack_140 = (ASN1_STRING *)pAVar3->length;
        pAStack_18c = (ASN1_STRING *)pAVar3->data;
        (*(code *)PTR_memcpy_006aabf4)(pAStack_80);
        pAVar8->length = (int)((int)&pAStack_80->length + pAVar3->length);
        pAStack_90 = (ASN1_STRING *)pcVar15;
      }
    }
  }
  if (ppAStack_7c == *(ASN1_STRING ***)puStack_b4) {
    return pAVar4;
  }
  ppAStack_190 = ppAStack_7c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_188 = PTR___stack_chk_guard_006aabf0;
  puStack_cc = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pcVar15 = (char *)pAStack_194;
  pAStack_c4 = (ASN1_STRING *)length;
  pAStack_c0 = (ASN1_STRING *)a;
  pAStack_b8 = (ASN1_STRING *)pp;
  pAStack_b0 = unaff_s5;
  pAStack_ac = unaff_s6;
  if (ppAStack_190 == (ASN1_STRING **)0x0) {
LAB_0061032c:
    pAStack_208 = pAStack_18c;
    d2i = (char *)pAStack_140;
    pAStack_214 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAStack_214 != (ASN1_STRING *)0x0) {
      pAStack_118 = (ASN1_STRING *)pAStack_18c->length;
      pcVar15 = auStack_10c;
      d2i = auStack_114 + 4;
      pAStack_208 = (ASN1_STRING *)auStack_114;
      uVar2 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_118);
      pAVar8 = pAStack_214;
      if ((uVar2 & 0x80) == 0) goto LAB_006100f0;
      pAStack_194 = (ASN1_STRING *)0x66;
      goto LAB_00610378;
    }
    pAVar8 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_214 = *ppAStack_190;
    pcVar15 = auStack_10c;
    if (pAStack_214 == (ASN1_STRING *)0x0) goto LAB_0061032c;
    pAStack_118 = (ASN1_STRING *)pAStack_18c->length;
    d2i = auStack_114 + 4;
    pAStack_208 = (ASN1_STRING *)auStack_114;
    uVar2 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_118);
    pAVar8 = pAStack_214;
    if ((uVar2 & 0x80) == 0) {
LAB_006100f0:
      pAStack_214 = pAVar8;
      unaff_s6 = auStack_114._4_4_;
      if (auStack_114._4_4_ == pAStack_194) {
        if ((uVar2 & 0x20) == 0) {
          if (auStack_114._0_4_ == (ASN1_STRING *)0x0) {
            if (pAVar8->data == (uchar *)0x0) {
              pcVar15 = (char *)0x0;
              pAVar11 = pAStack_118;
            }
            else {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              pcVar15 = (char *)0x0;
              pAVar11 = pAStack_118;
            }
          }
          else {
            if (pAVar8->length < (int)auStack_114._0_4_) {
              if (pAVar8->data != (uchar *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
LAB_00610428:
              pAStack_140 = (ASN1_STRING *)0x680000;
              puVar16 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                           ((code *)((int)&(auStack_114._0_4_)->length + 1),
                                            "a_bytes.c",0xd5);
              if (puVar16 == (uchar *)0x0) {
                pAStack_194 = (ASN1_STRING *)&DAT_00000041;
                goto LAB_00610378;
              }
            }
            else {
              puVar16 = pAVar8->data;
              if (puVar16 == (uchar *)0x0) goto LAB_00610428;
            }
            pAStack_208 = pAStack_118;
            d2i = (char *)auStack_114._0_4_;
            pcVar15 = (char *)(*(code *)PTR_memcpy_006aabf4)(puVar16);
            *(code *)((int)&(auStack_114._0_4_)->length + (int)(int *)pcVar15) = (code)0x0;
            pAVar11 = (ASN1_STRING *)((int)&(auStack_114._0_4_)->length + (int)&pAStack_118->length)
            ;
          }
          pAVar8->length = (int)auStack_114._0_4_;
          pAVar8->data = (uchar *)pcVar15;
          pAVar8->type = (int)auStack_114._4_4_;
          pAVar3 = pAStack_194;
        }
        else {
          pAStack_e0 = auStack_114._0_4_;
          AStack_f8.length = (int)pAStack_118;
          pAStack_e4 = pAStack_90;
          if (pAStack_140 == (ASN1_STRING *)0x0) {
            pcStack_dc = (code *)0x0;
          }
          else {
            pcStack_dc = (code *)((int)&pAStack_140->length + (int)&pAStack_118->length);
          }
          pAStack_140 = (ASN1_STRING *)0x0;
          auStack_10c._4_4_ = (ASN1_STRING **)0x0;
          pAVar3 = &AStack_f8;
          puStack_104 = (uchar *)0x0;
          auStack_114._4_4_ = (ASN1_STRING *)(auStack_10c + 4);
          uStack_fc = 0;
          unaff_s7 = &puStack_104;
          puStack_100 = (uchar *)0x0;
          AStack_f8.flags = uVar2;
          pAStack_e8 = pAStack_194;
          pAStack_d4 = pAStack_18c;
          if ((uVar2 & 1) != 0) goto LAB_00610208;
          while (0 < (int)pAStack_e0) {
            while( true ) {
              pAStack_d8 = (ASN1_STRING *)AStack_f8.length;
              pcVar15 = (char *)pAStack_e8;
              pAVar11 = d2i_ASN1_bytes((ASN1_STRING **)auStack_114._4_4_,(uchar **)pAVar3,
                                       (int)pcStack_dc - AStack_f8.length,(int)pAStack_e8,
                                       (int)pAStack_e4);
              if (pAVar11 == (ASN1_STRING *)0x0) {
                AStack_f8.data = &DAT_0000000d;
                goto LAB_00610460;
              }
              iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                (unaff_s7,(code *)((int)&(*auStack_10c._4_4_)->length +
                                                  (int)&pAStack_140->length));
              if (iVar5 == 0) {
                AStack_f8.data = &DAT_00000007;
                goto LAB_00610460;
              }
              d2i = (char *)*auStack_10c._4_4_;
              pAStack_208 = auStack_10c._4_4_[2];
              (*(code *)PTR_memcpy_006aabf4)(puStack_100 + (int)pAStack_140);
              if ((AStack_f8.flags & 1U) == 0) {
                pAStack_e0 = (ASN1_STRING *)((int)pAStack_e0 - (AStack_f8.length - (int)pAStack_d8))
                ;
              }
              pAStack_140 = (ASN1_STRING *)
                            ((int)&(*auStack_10c._4_4_)->length + (int)&pAStack_140->length);
              if ((AStack_f8.flags & 1U) == 0) break;
LAB_00610208:
              pAStack_208 = (ASN1_STRING *)(pcStack_dc + -AStack_f8.length);
              AStack_f8.type = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(pAVar3);
              if (AStack_f8.type != 0) goto LAB_00610230;
            }
          }
LAB_00610230:
          iVar5 = (*(code *)PTR_asn1_const_Finish_006a9518)(pAVar3);
          if (iVar5 == 0) {
LAB_00610460:
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x69,AStack_f8.data,"a_bytes.c");
            if (auStack_10c._4_4_ != (ASN1_STRING **)0x0) {
              (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            }
            if (puStack_100 != (uchar *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
            }
            pAStack_194 = (ASN1_STRING *)0x0;
            unaff_s6 = auStack_114._4_4_;
            goto LAB_00610378;
          }
          pAVar8->length = (int)pAStack_140;
          if (pAVar8->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pAVar8->data = puStack_100;
          pAVar11 = (ASN1_STRING *)AStack_f8.length;
          if (auStack_10c._4_4_ != (ASN1_STRING **)0x0) {
            (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            pAVar11 = (ASN1_STRING *)AStack_f8.length;
          }
        }
        if (ppAStack_190 != (ASN1_STRING **)0x0) {
          *ppAStack_190 = pAVar8;
        }
        pAStack_18c->length = (int)pAVar11;
        pAStack_194 = pAVar3;
        unaff_s6 = auStack_114._4_4_;
        goto LAB_00610294;
      }
      pAStack_194 = (ASN1_STRING *)&DAT_000000a8;
LAB_00610378:
      if (ppAStack_190 != (ASN1_STRING **)0x0) goto LAB_00610380;
LAB_0061038c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_214);
    }
    else {
      pAStack_194 = (ASN1_STRING *)0x66;
LAB_00610380:
      if (pAStack_214 != *ppAStack_190) goto LAB_0061038c;
    }
    pAStack_140 = (ASN1_STRING *)0x680000;
    pcVar15 = "a_bytes.c";
    pAStack_208 = (ASN1_STRING *)0x8f;
    d2i = (char *)pAStack_194;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pAVar8 = (ASN1_STRING *)0x0;
  }
LAB_00610294:
  if (puStack_cc == *(uchar **)puStack_188) {
    return pAVar8;
  }
  uStack_13c = 0x610508;
  puStack_148 = puStack_cc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAStack_1d0 = (ASN1_STRING *)PTR___stack_chk_guard_006aabf0;
  ppuStack_20c = &puStack_148;
  psStack_144 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  pAVar8 = (ASN1_STRING *)
           d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_20c,(long)pAStack_208,d2i,
                        (free_func *)pcVar15,0x10,0);
  if (pAVar8 == (ASN1_STRING *)0x0) {
    pAStack_208 = (ASN1_STRING *)&DAT_0000006e;
    d2i = "asn_pack.c";
    ppuStack_20c = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
  }
  if (psStack_144 == *(stack_st_OPENSSL_BLOCK **)pAStack_1d0) {
    return pAVar8;
  }
  pcStack_17c = ASN1_seq_pack;
  a_00 = psStack_144;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_210 = PTR___stack_chk_guard_006aabf0;
  puStack_19c = (undefined *)pAStack_1d0;
  puStack_1a4 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAStack_198 = pAStack_214;
  pAStack_184 = unaff_s6;
  ppuStack_180 = unaff_s7;
  pAVar8 = (ASN1_STRING *)i2d_ASN1_SET(a_00,(uchar **)0x0,(undefined1 *)ppuStack_20c,0x10,0,0);
  if (pAVar8 == (ASN1_STRING *)0x0) {
    ppAVar13 = (ASN1_STRING **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    pAVar8 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_1d0 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAVar8,"asn_pack.c",0x5f);
    pAStack_214 = pAVar8;
    if (pAStack_1d0 == (ASN1_STRING *)0x0) {
      ppAVar13 = (ASN1_STRING **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      pAVar8 = (ASN1_STRING *)0x0;
    }
    else {
      ppAVar13 = &pAStack_1a8;
      pAStack_1a8 = pAStack_1d0;
      i2d_ASN1_SET(a_00,(uchar **)ppAVar13,(undefined1 *)ppuStack_20c,0x10,0,0);
      if ((ASN1_STRING *)d2i != (ASN1_STRING *)0x0) {
        *(int *)d2i = (int)pAVar8;
      }
      pAVar8 = pAStack_1d0;
      if (pAStack_208 != (ASN1_STRING *)0x0) {
        pAStack_208->length = (int)pAStack_1d0;
      }
    }
  }
  if (puStack_1a4 == *(undefined4 **)puStack_210) {
    return pAVar8;
  }
  pcStack_1cc = ASN1_unpack_string;
  puVar9 = puStack_1a4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_218 = PTR___stack_chk_guard_006aabf0;
  uStack_1d8 = puVar9[2];
  ppAVar12 = (ASN1_STRING **)*puVar9;
  puVar9 = &uStack_1d8;
  puStack_1e8 = &_gp;
  iStack_1d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar8 = (ASN1_STRING *)(*(code *)ppAVar13)(0);
  if (pAVar8 == (ASN1_STRING *)0x0) {
    ppAVar12 = (ASN1_STRING **)&DAT_0000006e;
    uStack_1f0 = 0x74;
    puVar9 = (undefined4 *)&DAT_00000088;
    pAStack_1dc = pAVar8;
    (**(code **)(puStack_1e8 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    pAVar8 = pAStack_1dc;
  }
  if (iStack_1d4 == *(int *)puStack_218) {
    return pAVar8;
  }
  pcStack_204 = ASN1_pack_string;
  iVar5 = iStack_1d4;
  (**(code **)(puStack_1e8 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_21c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppAVar12 == (ASN1_STRING **)0x0) {
    pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar8 != (ASN1_STRING *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppAVar13 = (ASN1_STRING **)&DAT_00000041;
    uVar7 = 0x81;
LAB_006108f8:
    ppuVar10 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppAVar13,"asn_pack.c",uVar7);
    pAVar8 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar8 = *ppAVar12;
    if (pAVar8 == (ASN1_STRING *)0x0) {
      pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar8 == (ASN1_STRING *)0x0) goto LAB_00610928;
      *ppAVar12 = pAVar8;
    }
LAB_0061083c:
    iVar6 = (*(code *)puVar9)(iVar5,0);
    pAVar8->length = iVar6;
    if (iVar6 == 0) {
      ppAVar13 = (ASN1_STRING **)&DAT_00000070;
      uVar7 = 0x88;
      goto LAB_006108f8;
    }
    ppAVar13 = (ASN1_STRING **)&DAT_0000008b;
    puStack_220 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar6,"asn_pack.c");
    if (puStack_220 == (uchar *)0x0) {
      ppAVar13 = (ASN1_STRING **)&DAT_00000041;
      ppuVar10 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      pAVar8 = (ASN1_STRING *)0x0;
    }
    else {
      ppuVar10 = &puStack_220;
      pAVar8->data = puStack_220;
      (*(code *)puVar9)(iVar5,ppuVar10);
    }
  }
  if (iStack_21c == *(int *)puVar1) {
    return pAVar8;
  }
  iVar5 = iStack_21c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppAVar13 == (ASN1_STRING **)0x0) {
    pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar8 == (ASN1_STRING *)0x0) {
LAB_00610a48:
      uVar14 = 0x41;
      uVar7 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    pAVar8 = *ppAVar13;
    if (pAVar8 == (ASN1_STRING *)0x0) {
      pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar8 == (ASN1_STRING *)0x0) goto LAB_00610a48;
      *ppAVar13 = pAVar8;
    }
  }
  if (pAVar8->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar8->data = (uchar *)0x0;
  }
  iVar5 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar5,&pAVar8->data,ppuVar10);
  pAVar8->length = iVar5;
  if (iVar5 == 0) {
    uVar14 = 0x70;
    uVar7 = 0xaa;
  }
  else {
    if (pAVar8->data != (uchar *)0x0) {
      return pAVar8;
    }
    uVar14 = 0x41;
    uVar7 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar14,"asn_pack.c",uVar7);
  return (ASN1_STRING *)0x0;
}

