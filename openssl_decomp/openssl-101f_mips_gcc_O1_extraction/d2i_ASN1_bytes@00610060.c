
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  int iVar6;
  undefined4 uVar7;
  stack_st_OPENSSL_BLOCK *a_00;
  undefined4 *puVar8;
  uchar **ppuVar9;
  char *d2i;
  ASN1_STRING **ppAVar10;
  ASN1_STRING **ppAVar11;
  undefined4 uVar12;
  uchar *puVar13;
  char *free_func;
  ASN1_STRING *pp_00;
  ASN1_STRING *unaff_s6;
  int *unaff_s7;
  uchar *puStack_180;
  int iStack_17c;
  undefined *puStack_178;
  ASN1_STRING *pAStack_174;
  undefined *puStack_170;
  uchar **ppuStack_16c;
  ASN1_STRING *pAStack_168;
  code *pcStack_164;
  undefined4 uStack_150;
  undefined *puStack_148;
  ASN1_STRING *pAStack_13c;
  undefined4 uStack_138;
  int iStack_134;
  ASN1_STRING *pAStack_130;
  code *pcStack_12c;
  ASN1_STRING *pAStack_108;
  undefined4 *puStack_104;
  undefined *puStack_fc;
  ASN1_STRING *pAStack_f8;
  ASN1_STRING *pAStack_f4;
  ASN1_STRING **ppAStack_f0;
  uchar **ppuStack_ec;
  undefined *puStack_e8;
  ASN1_STRING *pAStack_e4;
  int *piStack_e0;
  code *pcStack_dc;
  uchar *puStack_a8;
  stack_st_OPENSSL_BLOCK *psStack_a4;
  char *pcStack_a0;
  undefined4 uStack_9c;
  ASN1_STRING *local_78;
  undefined local_74 [8];
  undefined auStack_6c [4];
  ASN1_STRING local_68;
  ASN1_STRING local_58;
  free_func *local_48;
  int local_44;
  ASN1_STRING *local_40;
  undefined *local_3c;
  ASN1_STRING *local_38;
  uchar **local_34;
  uchar *local_2c;
  
  puStack_e8 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(uchar **)PTR___stack_chk_guard_006aabf0;
  free_func = (char *)Ptag;
  if (a == (ASN1_STRING **)0x0) {
LAB_0061032c:
    pAStack_168 = (ASN1_STRING *)pp;
    d2i = (char *)length;
    pAStack_174 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAStack_174 != (ASN1_STRING *)0x0) {
      local_78 = (ASN1_STRING *)*pp;
      free_func = auStack_6c;
      d2i = local_74 + 4;
      pAStack_168 = (ASN1_STRING *)local_74;
      uVar2 = (*(code *)PTR_ASN1_get_object_006a9514)(&local_78);
      pAVar5 = pAStack_174;
      if ((uVar2 & 0x80) == 0) goto LAB_006100f0;
      Ptag = 0x66;
      local_74._4_4_ = unaff_s6;
      goto LAB_00610378;
    }
    pAVar5 = (ASN1_STRING *)0x0;
    local_74._4_4_ = unaff_s6;
  }
  else {
    pAStack_174 = *a;
    free_func = auStack_6c;
    if (pAStack_174 == (ASN1_STRING *)0x0) goto LAB_0061032c;
    local_78 = (ASN1_STRING *)*pp;
    d2i = local_74 + 4;
    pAStack_168 = (ASN1_STRING *)local_74;
    uVar2 = (*(code *)PTR_ASN1_get_object_006a9514)(&local_78);
    pAVar5 = pAStack_174;
    if ((uVar2 & 0x80) == 0) {
LAB_006100f0:
      pAStack_174 = pAVar5;
      if (local_74._4_4_ == (ASN1_STRING *)Ptag) {
        if ((uVar2 & 0x20) == 0) {
          if (local_74._0_4_ == (ASN1_STRING *)0x0) {
            if (pAVar5->data == (uchar *)0x0) {
              free_func = (char *)0x0;
              pAVar3 = local_78;
            }
            else {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              free_func = (char *)0x0;
              pAVar3 = local_78;
            }
          }
          else {
            if (pAVar5->length < (int)local_74._0_4_) {
              if (pAVar5->data != (uchar *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
LAB_00610428:
              length = 0x680000;
              puVar13 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                           ((char *)((int)&(local_74._0_4_)->length + 1),"a_bytes.c"
                                            ,0xd5);
              if (puVar13 == (uchar *)0x0) {
                Ptag = (int)&DAT_00000041;
                goto LAB_00610378;
              }
            }
            else {
              puVar13 = pAVar5->data;
              if (puVar13 == (uchar *)0x0) goto LAB_00610428;
            }
            pAStack_168 = local_78;
            d2i = (char *)local_74._0_4_;
            free_func = (char *)(*(code *)PTR_memcpy_006aabf4)(puVar13);
            ((free_func *)free_func)[(int)local_74._0_4_] = (free_func)0x0;
            pAVar3 = (ASN1_STRING *)((int)&(local_74._0_4_)->length + (int)&local_78->length);
          }
          pAVar5->length = (int)local_74._0_4_;
          pAVar5->data = (uchar *)free_func;
          pAVar5->type = (int)local_74._4_4_;
          pp_00 = (ASN1_STRING *)Ptag;
        }
        else {
          local_40 = local_74._0_4_;
          local_58.length = (int)local_78;
          local_44 = Pclass;
          if (length == 0) {
            local_3c = (undefined *)0x0;
          }
          else {
            local_3c = (undefined *)((int)&local_78->length + length);
          }
          length = 0;
          local_68.length = 0;
          pp_00 = &local_58;
          local_68.type = 0;
          local_74._4_4_ = &local_68;
          local_68.flags = 0;
          unaff_s7 = &local_68.type;
          local_68.data = (uchar *)0x0;
          local_58.flags = uVar2;
          local_48 = (free_func *)Ptag;
          local_34 = pp;
          if ((uVar2 & 1) != 0) goto LAB_00610208;
          while (0 < (int)local_40) {
            while( true ) {
              local_38 = (ASN1_STRING *)local_58.length;
              free_func = (char *)local_48;
              pAVar3 = d2i_ASN1_bytes((ASN1_STRING **)local_74._4_4_,(uchar **)pp_00,
                                      (int)local_3c - local_58.length,(int)local_48,local_44);
              if (pAVar3 == (ASN1_STRING *)0x0) {
                local_58.data = &DAT_0000000d;
                goto LAB_00610460;
              }
              iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                (unaff_s7,(char *)((int)&(*(ASN1_STRING **)local_68.length)->length
                                                  + length));
              if (iVar4 == 0) {
                local_58.data = &DAT_00000007;
                goto LAB_00610460;
              }
              d2i = *(char **)local_68.length;
              pAStack_168 = *(ASN1_STRING **)(local_68.length + 8);
              (*(code *)PTR_memcpy_006aabf4)(local_68.data + length);
              if ((local_58.flags & 1U) == 0) {
                local_40 = (ASN1_STRING *)((int)local_40 - (local_58.length - (int)local_38));
              }
              length = (int)&(*(ASN1_STRING **)local_68.length)->length + length;
              if ((local_58.flags & 1U) == 0) break;
LAB_00610208:
              pAStack_168 = (ASN1_STRING *)(local_3c + -local_58.length);
              local_58.type = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(pp_00);
              if (local_58.type != 0) goto LAB_00610230;
            }
          }
LAB_00610230:
          iVar4 = (*(code *)PTR_asn1_const_Finish_006a9518)(pp_00);
          if (iVar4 == 0) {
LAB_00610460:
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x69,local_58.data,"a_bytes.c");
            if ((ASN1_STRING **)local_68.length != (ASN1_STRING **)0x0) {
              (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            }
            if (local_68.data != (uchar *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
            }
            Ptag = 0;
            goto LAB_00610378;
          }
          pAVar5->length = length;
          if (pAVar5->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pAVar5->data = local_68.data;
          pAVar3 = (ASN1_STRING *)local_58.length;
          if ((ASN1_STRING **)local_68.length != (ASN1_STRING **)0x0) {
            (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            pAVar3 = (ASN1_STRING *)local_58.length;
          }
        }
        if (a != (ASN1_STRING **)0x0) {
          *a = pAVar5;
        }
        *pp = (uchar *)pAVar3;
        Ptag = (int)pp_00;
        goto LAB_00610294;
      }
      Ptag = (int)&DAT_000000a8;
LAB_00610378:
      if (a != (ASN1_STRING **)0x0) goto LAB_00610380;
LAB_0061038c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_174);
    }
    else {
      Ptag = 0x66;
      local_74._4_4_ = unaff_s6;
LAB_00610380:
      if (pAStack_174 != *a) goto LAB_0061038c;
    }
    length = 0x680000;
    free_func = "a_bytes.c";
    pAStack_168 = (ASN1_STRING *)0x8f;
    d2i = (char *)Ptag;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pAVar5 = (ASN1_STRING *)0x0;
  }
LAB_00610294:
  if (local_2c == *(uchar **)puStack_e8) {
    return pAVar5;
  }
  uStack_9c = 0x610508;
  puStack_a8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAStack_130 = (ASN1_STRING *)PTR___stack_chk_guard_006aabf0;
  ppuStack_16c = &puStack_a8;
  psStack_a4 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  pcStack_a0 = (char *)length;
  pAVar5 = (ASN1_STRING *)
           d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_16c,(long)pAStack_168,d2i,
                        (free_func *)free_func,0x10,0);
  if (pAVar5 == (ASN1_STRING *)0x0) {
    pAStack_168 = (ASN1_STRING *)&DAT_0000006e;
    d2i = "asn_pack.c";
    ppuStack_16c = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
  }
  if (psStack_a4 == *(stack_st_OPENSSL_BLOCK **)pAStack_130) {
    return pAVar5;
  }
  pcStack_dc = ASN1_seq_pack;
  a_00 = psStack_a4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_170 = PTR___stack_chk_guard_006aabf0;
  puStack_fc = (undefined *)pAStack_130;
  puStack_104 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAStack_f8 = pAStack_174;
  pAStack_f4 = (ASN1_STRING *)Ptag;
  ppAStack_f0 = a;
  ppuStack_ec = pp;
  pAStack_e4 = local_74._4_4_;
  piStack_e0 = unaff_s7;
  pAVar5 = (ASN1_STRING *)i2d_ASN1_SET(a_00,(uchar **)0x0,(undefined1 *)ppuStack_16c,0x10,0,0);
  if (pAVar5 == (ASN1_STRING *)0x0) {
    ppAVar11 = (ASN1_STRING **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    pAVar5 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_130 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAVar5,"asn_pack.c",0x5f);
    pAStack_174 = pAVar5;
    if (pAStack_130 == (ASN1_STRING *)0x0) {
      ppAVar11 = (ASN1_STRING **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      pAVar5 = (ASN1_STRING *)0x0;
    }
    else {
      ppAVar11 = &pAStack_108;
      pAStack_108 = pAStack_130;
      i2d_ASN1_SET(a_00,(uchar **)ppAVar11,(undefined1 *)ppuStack_16c,0x10,0,0);
      if ((ASN1_STRING *)d2i != (ASN1_STRING *)0x0) {
        *(int *)d2i = (int)pAVar5;
      }
      pAVar5 = pAStack_130;
      if (pAStack_168 != (ASN1_STRING *)0x0) {
        pAStack_168->length = (int)pAStack_130;
      }
    }
  }
  if (puStack_104 == *(undefined4 **)puStack_170) {
    return pAVar5;
  }
  pcStack_12c = ASN1_unpack_string;
  puVar8 = puStack_104;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_178 = PTR___stack_chk_guard_006aabf0;
  uStack_138 = puVar8[2];
  ppAVar10 = (ASN1_STRING **)*puVar8;
  puVar8 = &uStack_138;
  puStack_148 = &_gp;
  iStack_134 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar5 = (ASN1_STRING *)(*(code *)ppAVar11)(0);
  if (pAVar5 == (ASN1_STRING *)0x0) {
    ppAVar10 = (ASN1_STRING **)&DAT_0000006e;
    uStack_150 = 0x74;
    puVar8 = (undefined4 *)&DAT_00000088;
    pAStack_13c = pAVar5;
    (**(code **)(puStack_148 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    pAVar5 = pAStack_13c;
  }
  if (iStack_134 == *(int *)puStack_178) {
    return pAVar5;
  }
  pcStack_164 = ASN1_pack_string;
  iVar4 = iStack_134;
  (**(code **)(puStack_148 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_17c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppAVar10 == (ASN1_STRING **)0x0) {
    pAVar5 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar5 != (ASN1_STRING *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppAVar11 = (ASN1_STRING **)&DAT_00000041;
    uVar7 = 0x81;
LAB_006108f8:
    ppuVar9 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppAVar11,"asn_pack.c",uVar7);
    pAVar5 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar5 = *ppAVar10;
    if (pAVar5 == (ASN1_STRING *)0x0) {
      pAVar5 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00610928;
      *ppAVar10 = pAVar5;
    }
LAB_0061083c:
    iVar6 = (*(code *)puVar8)(iVar4,0);
    pAVar5->length = iVar6;
    if (iVar6 == 0) {
      ppAVar11 = (ASN1_STRING **)&DAT_00000070;
      uVar7 = 0x88;
      goto LAB_006108f8;
    }
    ppAVar11 = (ASN1_STRING **)&DAT_0000008b;
    puStack_180 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar6,"asn_pack.c");
    if (puStack_180 == (uchar *)0x0) {
      ppAVar11 = (ASN1_STRING **)&DAT_00000041;
      ppuVar9 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      pAVar5 = (ASN1_STRING *)0x0;
    }
    else {
      ppuVar9 = &puStack_180;
      pAVar5->data = puStack_180;
      (*(code *)puVar8)(iVar4,ppuVar9);
    }
  }
  if (iStack_17c == *(int *)puVar1) {
    return pAVar5;
  }
  iVar4 = iStack_17c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppAVar11 == (ASN1_STRING **)0x0) {
    pAVar5 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar5 == (ASN1_STRING *)0x0) {
LAB_00610a48:
      uVar12 = 0x41;
      uVar7 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    pAVar5 = *ppAVar11;
    if (pAVar5 == (ASN1_STRING *)0x0) {
      pAVar5 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00610a48;
      *ppAVar11 = pAVar5;
    }
  }
  if (pAVar5->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar5->data = (uchar *)0x0;
  }
  iVar4 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar4,&pAVar5->data,ppuVar9);
  pAVar5->length = iVar4;
  if (iVar4 == 0) {
    uVar12 = 0x70;
    uVar7 = 0xaa;
  }
  else {
    if (pAVar5->data != (uchar *)0x0) {
      return pAVar5;
    }
    uVar12 = 0x41;
    uVar7 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar12,"asn_pack.c",uVar7);
  return (ASN1_STRING *)0x0;
}

