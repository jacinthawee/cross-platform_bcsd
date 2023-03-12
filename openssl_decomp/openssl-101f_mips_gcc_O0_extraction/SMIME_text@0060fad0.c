
int SMIME_text(BIO *in,BIO *out)

{
  undefined *puVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  uint uVar4;
  ASN1_STRING **ppAVar5;
  undefined4 *puVar6;
  stack_st_OPENSSL_BLOCK *psVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  ASN1_STRING *pAVar11;
  char *d2i;
  int **ppiVar12;
  int **ppiVar13;
  undefined4 uVar14;
  char *in_a3;
  char *pcVar15;
  uchar *puVar16;
  ASN1_STRING *unaff_s0;
  int *piVar17;
  ASN1_STRING *pp;
  int unaff_s4;
  ASN1_STRING *unaff_s5;
  ASN1_STRING *unaff_s6;
  uchar **unaff_s7;
  int iStack_1268;
  int iStack_1264;
  undefined *puStack_1260;
  ASN1_STRING *pAStack_125c;
  undefined *puStack_1258;
  uchar **ppuStack_1254;
  ASN1_STRING *pAStack_1250;
  code *pcStack_124c;
  undefined4 uStack_1238;
  undefined *puStack_1230;
  int iStack_1224;
  undefined4 uStack_1220;
  int iStack_121c;
  int *piStack_1218;
  code *pcStack_1214;
  int *piStack_11f0;
  undefined4 *puStack_11ec;
  undefined *puStack_11e4;
  ASN1_STRING *pAStack_11e0;
  ASN1_STRING *pAStack_11dc;
  ASN1_STRING **ppAStack_11d8;
  ASN1_STRING *pAStack_11d4;
  undefined *puStack_11d0;
  ASN1_STRING *pAStack_11cc;
  uchar **ppuStack_11c8;
  code *pcStack_11c4;
  uchar *puStack_1190;
  stack_st_OPENSSL_BLOCK *psStack_118c;
  ASN1_STRING *pAStack_1188;
  undefined4 uStack_1184;
  ASN1_STRING *pAStack_1160;
  undefined auStack_115c [8];
  undefined auStack_1154 [8];
  uchar *puStack_114c;
  uchar *puStack_1148;
  undefined4 uStack_1144;
  ASN1_STRING AStack_1140;
  ASN1_STRING *pAStack_1130;
  ASN1_STRING *pAStack_112c;
  ASN1_STRING *pAStack_1128;
  undefined *puStack_1124;
  ASN1_STRING *pAStack_1120;
  ASN1_STRING *pAStack_111c;
  uchar *puStack_1114;
  ASN1_STRING **ppAStack_110c;
  undefined4 *puStack_1108;
  ASN1_STRING *pAStack_1104;
  code *pcStack_1100;
  undefined *puStack_10fc;
  ASN1_STRING *pAStack_10f8;
  ASN1_STRING *pAStack_10f4;
  ASN1_STRING *pAStack_10d8;
  int *piStack_10c8;
  ASN1_STRING **ppAStack_10c4;
  ASN1_STRING **ppAStack_10c0;
  undefined4 *puStack_10bc;
  undefined *puStack_10b8;
  ASN1_STRING *pAStack_10b4;
  ASN1_STRING *pAStack_10b0;
  ASN1_STRING *pAStack_1074;
  undefined auStack_1070 [4];
  ASN1_STRING *pAStack_106c;
  ASN1_STRING AStack_1068;
  BIO *pBStack_1058;
  undefined *puStack_1054;
  int iStack_1050;
  code *pcStack_104c;
  undefined4 local_1038;
  undefined *local_1030;
  char *local_1028 [3];
  ASN1_STRING aAStack_101c [256];
  undefined4 *local_1c;
  
  puStack_1054 = PTR___stack_chk_guard_006aabf0;
  local_1030 = &_gp;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAVar2 = (ASN1_STRING *)mime_parse_hdr();
  if (pAVar2 == (ASN1_STRING *)0x0) {
    ppAStack_110c = (ASN1_STRING **)0xcf;
    in_a3 = "asn_mime.c";
    local_1038 = 0x246;
    pcStack_1100 = (code *)0xd5;
    (**(code **)(local_1030 + -0x6eb0))(0xd);
    uVar4 = 0;
  }
  else {
    local_1028[0] = "content-type";
    iVar3 = (**(code **)(local_1030 + -0x6e74))(pAVar2,local_1028);
    if ((iVar3 < 0) || (unaff_s4 = (**(code **)(local_1030 + -0x7fbc))(pAVar2,iVar3), unaff_s4 == 0)
       ) {
LAB_0060fc68:
      ppAStack_110c = (ASN1_STRING **)0xce;
      in_a3 = "asn_mime.c";
      local_1038 = 0x24a;
      (**(code **)(local_1030 + -0x6eb0))(0xd,0xd5);
    }
    else {
      if (*(int *)(unaff_s4 + 4) == 0) goto LAB_0060fc68;
      iVar3 = (**(code **)(local_1030 + -0x52c0))(*(int *)(unaff_s4 + 4),"text/plain");
      if (iVar3 == 0) {
        (**(code **)(local_1030 + -0x7d88))(pAVar2,mime_hdr_free);
        while( true ) {
          ppAStack_110c = (ASN1_STRING **)0x1000;
          pcStack_1100 = (code *)aAStack_101c;
          iVar3 = (**(code **)(local_1030 + -0x7924))(in);
          if (iVar3 < 1) break;
          (**(code **)(local_1030 + -0x7fcc))(out,aAStack_101c,iVar3);
        }
        uVar4 = (uint)(iVar3 == 0);
        unaff_s0 = aAStack_101c;
        goto LAB_0060fbd8;
      }
      in_a3 = "asn_mime.c";
      local_1038 = 0x24f;
      (**(code **)(local_1030 + -0x6eb0))(0xd,0xd5,0xcd);
      ppAStack_110c = *(ASN1_STRING ***)(unaff_s4 + 4);
      (**(code **)(local_1030 + -0x6c7c))(2,"type: ");
    }
    pcStack_1100 = mime_hdr_free;
    (**(code **)(local_1030 + -0x7d88))(pAVar2);
    uVar4 = 0;
    unaff_s0 = pAVar2;
  }
LAB_0060fbd8:
  if (local_1c == *(undefined4 **)puStack_1054) {
    return uVar4;
  }
  pcStack_104c = d2i_ASN1_type_bytes;
  puStack_1108 = local_1c;
  (**(code **)(local_1030 + -0x5328))();
  puStack_10b8 = PTR___stack_chk_guard_006aabf0;
  pAStack_1074 = (ASN1_STRING *)*(int *)pcStack_1100;
  pcVar15 = auStack_1070 + 8;
  pAVar2 = (ASN1_STRING *)auStack_1070;
  AStack_1068.type = *(int *)PTR___stack_chk_guard_006aabf0;
  AStack_1068.data = (uchar *)unaff_s0;
  AStack_1068.flags = (long)in;
  pBStack_1058 = out;
  iStack_1050 = unaff_s4;
  uVar4 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_1074,pAVar2,auStack_1070 + 4);
  if ((uVar4 & 0x80) == 0) {
    pAVar11 = (ASN1_STRING *)0x99;
    if (0x1f < (int)pAStack_106c) goto LAB_0060fd58;
    uVar4 = (*(code *)PTR_ASN1_tag2bit_006a9e08)();
    if (((uint)in_a3 & uVar4) == 0) {
      pAVar11 = (ASN1_STRING *)0xa9;
      goto LAB_0060fd58;
    }
    if (pAStack_106c != (ASN1_STRING *)0x3) {
      if (((puStack_1108 == (undefined4 *)0x0) ||
          (ppAStack_110c = (ASN1_STRING **)*puStack_1108, ppAStack_110c == (ASN1_STRING **)0x0)) &&
         (ppAStack_110c = (ASN1_STRING **)(*(code *)PTR_ASN1_STRING_new_006a98b4)(),
         ppAStack_110c == (ASN1_STRING **)0x0)) {
        ppAVar5 = (ASN1_STRING **)0x0;
        goto LAB_0060fd80;
      }
      in_a3 = (char *)0x0;
      if (auStack_1070 == (undefined  [4])0x0) {
LAB_0060fdfc:
        if (ppAStack_110c[2] != (ASN1_STRING *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        ppAStack_110c[2] = (ASN1_STRING *)in_a3;
        *ppAStack_110c = (ASN1_STRING *)auStack_1070;
        ppAStack_110c[1] = pAStack_106c;
        if (puStack_1108 != (undefined4 *)0x0) {
          *puStack_1108 = ppAStack_110c;
        }
        *(int *)pcStack_1100 = (int)pAStack_1074;
        ppAVar5 = ppAStack_110c;
        goto LAB_0060fd80;
      }
      in_a3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                ((undefined *)((int)(int *)auStack_1070 + 1),"a_bytes.c",0x68);
      pcVar15 = (char *)0x680000;
      if ((ASN1_STRING *)in_a3 != (ASN1_STRING *)0x0) {
        pAVar2 = pAStack_1074;
        pAVar11 = (ASN1_STRING *)auStack_1070;
        (*(code *)PTR_memcpy_006aabf4)(in_a3);
        *(undefined *)((int)(int *)auStack_1070 + (int)(int *)in_a3) = 0;
        pAStack_1074 = (ASN1_STRING *)((int)(int *)auStack_1070 + (int)&pAStack_1074->length);
        goto LAB_0060fdfc;
      }
      pcVar15 = "a_bytes.c";
      pAVar11 = (ASN1_STRING *)&DAT_00000041;
      pAVar2 = (ASN1_STRING *)&DAT_00000095;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      if ((puStack_1108 == (undefined4 *)0x0) || (ppAStack_110c != (ASN1_STRING **)*puStack_1108)) {
        (*(code *)PTR_ASN1_STRING_free_006a98bc)(ppAStack_110c);
        ppAVar5 = (ASN1_STRING **)0x0;
        goto LAB_0060fd80;
      }
      goto LAB_0060fd7c;
    }
    pAVar2 = (ASN1_STRING *)pcStack_1100;
    pAVar11 = (ASN1_STRING *)ppAStack_110c;
    ppAVar5 = (ASN1_STRING **)(*(code *)PTR_d2i_ASN1_BIT_STRING_006aa908)(puStack_1108);
  }
  else {
    pAVar11 = (ASN1_STRING *)0x0;
LAB_0060fd58:
    pAVar2 = (ASN1_STRING *)&DAT_00000095;
    pcVar15 = "a_bytes.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
LAB_0060fd7c:
    ppAVar5 = (ASN1_STRING **)0x0;
  }
LAB_0060fd80:
  if ((ASN1_STRING **)AStack_1068.type == *(ASN1_STRING ***)puStack_10b8) {
    return (int)ppAVar5;
  }
  ppAVar5 = (ASN1_STRING **)AStack_1068.type;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_10fc = PTR___stack_chk_guard_006aabf0;
  ppAStack_10c4 = *(ASN1_STRING ***)PTR___stack_chk_guard_006aabf0;
  puVar6 = (undefined4 *)0x0;
  pAStack_11d4 = pAVar2;
  pAStack_1188 = pAVar11;
  pAStack_11dc = (ASN1_STRING *)pcVar15;
  pAStack_1104 = (ASN1_STRING *)puStack_10b8;
  ppAStack_10c0 = ppAStack_110c;
  puStack_10bc = puStack_1108;
  pAStack_10b4 = (ASN1_STRING *)pcStack_1100;
  pAStack_10b0 = (ASN1_STRING *)in_a3;
  if (ppAVar5 != (ASN1_STRING **)0x0) {
    pAStack_1104 = pAVar11;
    if (pAVar11 == (ASN1_STRING *)0x3) {
      puVar6 = (undefined4 *)(*(code *)PTR_i2d_ASN1_BIT_STRING_006aa90c)();
      pAStack_11d4 = pAVar2;
      pAStack_11dc = (ASN1_STRING *)pcVar15;
    }
    else {
      unaff_s5 = *ppAVar5;
      pAStack_11d4 = unaff_s5;
      puVar6 = (undefined4 *)(*(code *)PTR_ASN1_object_size_006a94fc)(0);
      ppAStack_110c = ppAVar5;
      puStack_1108 = puVar6;
      pcStack_1100 = (code *)pAVar2;
      unaff_s6 = (ASN1_STRING *)pcVar15;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        piStack_10c8 = (int *)pAVar2->length;
        pAStack_11dc = pAVar11;
        (*(code *)PTR_ASN1_put_object_006a9500)
                  (&piStack_10c8,pAVar11 + -1 < (ASN1_STRING *)&SUB_00000002,unaff_s5);
        pAStack_1188 = *ppAVar5;
        pAStack_11d4 = ppAVar5[2];
        (*(code *)PTR_memcpy_006aabf4)(piStack_10c8);
        pAVar2->length = (int)piStack_10c8 + (int)*ppAVar5;
        pAStack_10d8 = (ASN1_STRING *)pcVar15;
      }
    }
  }
  if (ppAStack_10c4 == *(ASN1_STRING ***)puStack_10fc) {
    return (int)puVar6;
  }
  ppAStack_11d8 = ppAStack_10c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_11d0 = PTR___stack_chk_guard_006aabf0;
  puStack_1114 = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pcVar15 = (char *)pAStack_11dc;
  pAStack_10f8 = unaff_s5;
  pAStack_10f4 = unaff_s6;
  if (ppAStack_11d8 == (ASN1_STRING **)0x0) {
LAB_0061032c:
    pAStack_1250 = pAStack_11d4;
    d2i = (char *)pAStack_1188;
    pAStack_125c = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAStack_125c != (ASN1_STRING *)0x0) {
      pAStack_1160 = (ASN1_STRING *)pAStack_11d4->length;
      pcVar15 = auStack_1154;
      d2i = auStack_115c + 4;
      pAStack_1250 = (ASN1_STRING *)auStack_115c;
      uVar4 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_1160);
      pAVar2 = pAStack_125c;
      if ((uVar4 & 0x80) == 0) goto LAB_006100f0;
      pAStack_11dc = (ASN1_STRING *)0x66;
      goto LAB_00610378;
    }
    pAVar2 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_125c = *ppAStack_11d8;
    pcVar15 = auStack_1154;
    if (pAStack_125c == (ASN1_STRING *)0x0) goto LAB_0061032c;
    pAStack_1160 = (ASN1_STRING *)pAStack_11d4->length;
    d2i = auStack_115c + 4;
    pAStack_1250 = (ASN1_STRING *)auStack_115c;
    uVar4 = (*(code *)PTR_ASN1_get_object_006a9514)(&pAStack_1160);
    pAVar2 = pAStack_125c;
    if ((uVar4 & 0x80) == 0) {
LAB_006100f0:
      pAStack_125c = pAVar2;
      unaff_s6 = auStack_115c._4_4_;
      if (auStack_115c._4_4_ == pAStack_11dc) {
        if ((uVar4 & 0x20) == 0) {
          if (auStack_115c._0_4_ == (ASN1_STRING *)0x0) {
            if (pAVar2->data == (uchar *)0x0) {
              pcVar15 = (char *)0x0;
              pAVar11 = pAStack_1160;
            }
            else {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              pcVar15 = (char *)0x0;
              pAVar11 = pAStack_1160;
            }
          }
          else {
            if (pAVar2->length < (int)auStack_115c._0_4_) {
              if (pAVar2->data != (uchar *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
LAB_00610428:
              pAStack_1188 = (ASN1_STRING *)0x680000;
              puVar16 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                           ((undefined *)((int)&(auStack_115c._0_4_)->length + 1),
                                            "a_bytes.c",0xd5);
              if (puVar16 == (uchar *)0x0) {
                pAStack_11dc = (ASN1_STRING *)&DAT_00000041;
                goto LAB_00610378;
              }
            }
            else {
              puVar16 = pAVar2->data;
              if (puVar16 == (uchar *)0x0) goto LAB_00610428;
            }
            pAStack_1250 = pAStack_1160;
            d2i = (char *)auStack_115c._0_4_;
            pcVar15 = (char *)(*(code *)PTR_memcpy_006aabf4)(puVar16);
            *(undefined *)((int)&(auStack_115c._0_4_)->length + (int)(int *)pcVar15) = 0;
            pAVar11 = (ASN1_STRING *)
                      ((int)&(auStack_115c._0_4_)->length + (int)&pAStack_1160->length);
          }
          pAVar2->length = (int)auStack_115c._0_4_;
          pAVar2->data = (uchar *)pcVar15;
          pAVar2->type = (int)auStack_115c._4_4_;
          pp = pAStack_11dc;
        }
        else {
          pAStack_1128 = auStack_115c._0_4_;
          AStack_1140.length = (int)pAStack_1160;
          pAStack_112c = pAStack_10d8;
          if (pAStack_1188 == (ASN1_STRING *)0x0) {
            puStack_1124 = (undefined *)0x0;
          }
          else {
            puStack_1124 = (undefined *)((int)&pAStack_1188->length + (int)&pAStack_1160->length);
          }
          pAStack_1188 = (ASN1_STRING *)0x0;
          auStack_1154._4_4_ = (ASN1_STRING **)0x0;
          pp = &AStack_1140;
          puStack_114c = (uchar *)0x0;
          auStack_115c._4_4_ = (ASN1_STRING *)(auStack_1154 + 4);
          uStack_1144 = 0;
          unaff_s7 = &puStack_114c;
          puStack_1148 = (uchar *)0x0;
          AStack_1140.flags = uVar4;
          pAStack_1130 = pAStack_11dc;
          pAStack_111c = pAStack_11d4;
          if ((uVar4 & 1) != 0) goto LAB_00610208;
          while (0 < (int)pAStack_1128) {
            while( true ) {
              pAStack_1120 = (ASN1_STRING *)AStack_1140.length;
              pcVar15 = (char *)pAStack_1130;
              pAVar11 = d2i_ASN1_bytes((ASN1_STRING **)auStack_115c._4_4_,(uchar **)pp,
                                       (int)puStack_1124 - AStack_1140.length,(int)pAStack_1130,
                                       (int)pAStack_112c);
              if (pAVar11 == (ASN1_STRING *)0x0) {
                AStack_1140.data = &DAT_0000000d;
                goto LAB_00610460;
              }
              iVar3 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                (unaff_s7,(undefined *)
                                          ((int)&(*auStack_1154._4_4_)->length +
                                          (int)&pAStack_1188->length));
              if (iVar3 == 0) {
                AStack_1140.data = &DAT_00000007;
                goto LAB_00610460;
              }
              d2i = (char *)*auStack_1154._4_4_;
              pAStack_1250 = auStack_1154._4_4_[2];
              (*(code *)PTR_memcpy_006aabf4)(puStack_1148 + (int)pAStack_1188);
              if ((AStack_1140.flags & 1U) == 0) {
                pAStack_1128 = (ASN1_STRING *)
                               ((int)pAStack_1128 - (AStack_1140.length - (int)pAStack_1120));
              }
              pAStack_1188 = (ASN1_STRING *)
                             ((int)&(*auStack_1154._4_4_)->length + (int)&pAStack_1188->length);
              if ((AStack_1140.flags & 1U) == 0) break;
LAB_00610208:
              pAStack_1250 = (ASN1_STRING *)(puStack_1124 + -AStack_1140.length);
              AStack_1140.type = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(pp);
              if (AStack_1140.type != 0) goto LAB_00610230;
            }
          }
LAB_00610230:
          iVar3 = (*(code *)PTR_asn1_const_Finish_006a9518)(pp);
          if (iVar3 == 0) {
LAB_00610460:
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x69,AStack_1140.data,"a_bytes.c");
            if (auStack_1154._4_4_ != (ASN1_STRING **)0x0) {
              (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            }
            if (puStack_1148 != (uchar *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
            }
            pAStack_11dc = (ASN1_STRING *)0x0;
            unaff_s6 = auStack_115c._4_4_;
            goto LAB_00610378;
          }
          pAVar2->length = (int)pAStack_1188;
          if (pAVar2->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pAVar2->data = puStack_1148;
          pAVar11 = (ASN1_STRING *)AStack_1140.length;
          if (auStack_1154._4_4_ != (ASN1_STRING **)0x0) {
            (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            pAVar11 = (ASN1_STRING *)AStack_1140.length;
          }
        }
        if (ppAStack_11d8 != (ASN1_STRING **)0x0) {
          *ppAStack_11d8 = pAVar2;
        }
        pAStack_11d4->length = (int)pAVar11;
        pAStack_11dc = pp;
        unaff_s6 = auStack_115c._4_4_;
        goto LAB_00610294;
      }
      pAStack_11dc = (ASN1_STRING *)&DAT_000000a8;
LAB_00610378:
      if (ppAStack_11d8 != (ASN1_STRING **)0x0) goto LAB_00610380;
LAB_0061038c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_125c);
    }
    else {
      pAStack_11dc = (ASN1_STRING *)0x66;
LAB_00610380:
      if (pAStack_125c != *ppAStack_11d8) goto LAB_0061038c;
    }
    pAStack_1188 = (ASN1_STRING *)0x680000;
    pcVar15 = "a_bytes.c";
    pAStack_1250 = (ASN1_STRING *)0x8f;
    d2i = (char *)pAStack_11dc;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pAVar2 = (ASN1_STRING *)0x0;
  }
LAB_00610294:
  if (puStack_1114 == *(uchar **)puStack_11d0) {
    return (int)pAVar2;
  }
  uStack_1184 = 0x610508;
  puStack_1190 = puStack_1114;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piStack_1218 = (int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_1254 = &puStack_1190;
  psStack_118c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  psVar7 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_1254,(long)pAStack_1250,d2i,
                        (free_func *)pcVar15,0x10,0);
  if (psVar7 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pAStack_1250 = (ASN1_STRING *)&DAT_0000006e;
    d2i = "asn_pack.c";
    ppuStack_1254 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
  }
  if (psStack_118c == (stack_st_OPENSSL_BLOCK *)*piStack_1218) {
    return (int)psVar7;
  }
  pcStack_11c4 = ASN1_seq_pack;
  psVar7 = psStack_118c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1258 = PTR___stack_chk_guard_006aabf0;
  puStack_11e4 = (undefined *)piStack_1218;
  puStack_11ec = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAStack_11e0 = pAStack_125c;
  pAStack_11cc = unaff_s6;
  ppuStack_11c8 = unaff_s7;
  pAVar2 = (ASN1_STRING *)i2d_ASN1_SET(psVar7,(uchar **)0x0,(undefined1 *)ppuStack_1254,0x10,0,0);
  if (pAVar2 == (ASN1_STRING *)0x0) {
    ppiVar13 = (int **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    piVar17 = (int *)0x0;
  }
  else {
    piStack_1218 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAVar2,"asn_pack.c",0x5f);
    pAStack_125c = pAVar2;
    if (piStack_1218 == (int *)0x0) {
      ppiVar13 = (int **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      piVar17 = (int *)0x0;
    }
    else {
      ppiVar13 = &piStack_11f0;
      piStack_11f0 = piStack_1218;
      i2d_ASN1_SET(psVar7,(uchar **)ppiVar13,(undefined1 *)ppuStack_1254,0x10,0,0);
      if ((ASN1_STRING *)d2i != (ASN1_STRING *)0x0) {
        *(int *)d2i = (int)pAVar2;
      }
      piVar17 = piStack_1218;
      if (pAStack_1250 != (ASN1_STRING *)0x0) {
        pAStack_1250->length = (int)piStack_1218;
      }
    }
  }
  if (puStack_11ec == *(undefined4 **)puStack_1258) {
    return (int)piVar17;
  }
  pcStack_1214 = ASN1_unpack_string;
  puVar6 = puStack_11ec;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1260 = PTR___stack_chk_guard_006aabf0;
  uStack_1220 = puVar6[2];
  ppiVar12 = (int **)*puVar6;
  puVar6 = &uStack_1220;
  puStack_1230 = &_gp;
  iStack_121c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)ppiVar13)(0);
  if (iVar3 == 0) {
    ppiVar12 = (int **)&DAT_0000006e;
    uStack_1238 = 0x74;
    puVar6 = (undefined4 *)&DAT_00000088;
    iStack_1224 = iVar3;
    (**(code **)(puStack_1230 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    iVar3 = iStack_1224;
  }
  if (iStack_121c == *(int *)puStack_1260) {
    return iVar3;
  }
  pcStack_124c = ASN1_pack_string;
  iVar3 = iStack_121c;
  (**(code **)(puStack_1230 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_1264 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppiVar12 == (int **)0x0) {
    piVar17 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar17 != (int *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppiVar13 = (int **)&DAT_00000041;
    uVar9 = 0x81;
LAB_006108f8:
    piVar10 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppiVar13,"asn_pack.c",uVar9);
    piVar17 = (int *)0x0;
  }
  else {
    piVar17 = *ppiVar12;
    if (piVar17 == (int *)0x0) {
      piVar17 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar17 == (int *)0x0) goto LAB_00610928;
      *ppiVar12 = piVar17;
    }
LAB_0061083c:
    iVar8 = (*(code *)puVar6)(iVar3,0);
    *piVar17 = iVar8;
    if (iVar8 == 0) {
      ppiVar13 = (int **)&DAT_00000070;
      uVar9 = 0x88;
      goto LAB_006108f8;
    }
    ppiVar13 = (int **)&DAT_0000008b;
    iStack_1268 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8,"asn_pack.c");
    if (iStack_1268 == 0) {
      ppiVar13 = (int **)&DAT_00000041;
      piVar10 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      piVar17 = (int *)0x0;
    }
    else {
      piVar10 = &iStack_1268;
      piVar17[2] = iStack_1268;
      (*(code *)puVar6)(iVar3,piVar10);
    }
  }
  if (iStack_1264 == *(int *)puVar1) {
    return (int)piVar17;
  }
  iVar3 = iStack_1264;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppiVar13 == (int **)0x0) {
    piVar17 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar17 == (int *)0x0) {
LAB_00610a48:
      uVar14 = 0x41;
      uVar9 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    piVar17 = *ppiVar13;
    if (piVar17 == (int *)0x0) {
      piVar17 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar17 == (int *)0x0) goto LAB_00610a48;
      *ppiVar13 = piVar17;
    }
  }
  if (piVar17[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    piVar17[2] = 0;
  }
  iVar3 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar3,piVar17 + 2,piVar10);
  *piVar17 = iVar3;
  if (iVar3 == 0) {
    uVar14 = 0x70;
    uVar9 = 0xaa;
  }
  else {
    if (piVar17[2] != 0) {
      return (int)piVar17;
    }
    uVar14 = 0x41;
    uVar9 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar14,"asn_pack.c",uVar9);
  return 0;
}

