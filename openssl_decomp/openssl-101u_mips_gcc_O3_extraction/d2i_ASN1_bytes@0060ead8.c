
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  uint uVar4;
  int iVar5;
  ASN1_STRING *pAVar6;
  int iVar7;
  undefined4 uVar8;
  stack_st_OPENSSL_BLOCK *a_00;
  undefined4 *puVar9;
  uchar **ppuVar10;
  ASN1_STRING **ppAVar11;
  ASN1_STRING **ppAVar12;
  undefined4 uVar13;
  char *free_func;
  uchar *unaff_s4;
  ASN1_STRING *unaff_s5;
  ASN1_STRING *unaff_s6;
  ASN1_STRING *unaff_s7;
  code *pcVar14;
  uchar *puStack_1f8;
  int iStack_1f4;
  undefined *puStack_1ec;
  ASN1_STRING *pAStack_1e8;
  undefined *puStack_1e4;
  uchar **ppuStack_1e0;
  char *pcStack_1dc;
  char *pcStack_1d8;
  code *pcStack_1d4;
  undefined4 uStack_1c0;
  undefined *puStack_1b8;
  ASN1_STRING *pAStack_1ac;
  undefined4 uStack_1a8;
  int iStack_1a4;
  ASN1_STRING *pAStack_1a0;
  code *pcStack_19c;
  ASN1_STRING *pAStack_178;
  undefined4 *puStack_174;
  undefined *puStack_16c;
  ASN1_STRING *pAStack_168;
  ASN1_STRING **ppAStack_164;
  ASN1_STRING *pAStack_160;
  uchar *puStack_15c;
  ASN1_STRING *pAStack_158;
  ASN1_STRING *pAStack_154;
  ASN1_STRING *pAStack_150;
  code *pcStack_14c;
  uchar *puStack_118;
  stack_st_OPENSSL_BLOCK *psStack_114;
  ASN1_STRING *pAStack_110;
  undefined4 uStack_10c;
  ASN1_STRING *local_f8;
  undefined4 local_f4;
  uchar **local_f0;
  undefined *local_e8;
  ASN1_STRING *local_dc;
  ASN1_STRING **local_d8;
  ASN1_STRING **local_d4;
  uchar **local_d0;
  ASN1_STRING *local_cc;
  uchar **local_c8;
  char *local_c4;
  ASN1_STRING *local_c0;
  undefined local_bc [8];
  undefined auStack_b4 [4];
  ASN1_STRING *local_b0;
  undefined local_ac [8];
  undefined auStack_a4 [8];
  uchar *local_9c;
  uchar *local_98;
  undefined4 local_94;
  undefined4 local_90;
  ASN1_STRING *local_8c;
  undefined4 local_88;
  ASN1_STRING local_84;
  ASN1_STRING *local_74;
  ASN1_STRING *local_70;
  ASN1_STRING *local_6c;
  uchar *local_68;
  ASN1_STRING *local_64;
  ASN1_STRING **local_60;
  ASN1_STRING local_58;
  ASN1_STRING *local_48;
  ASN1_STRING *local_44;
  ASN1_STRING *local_40;
  uchar *local_3c;
  ASN1_STRING *local_38;
  ASN1_STRING *local_34;
  uchar *local_2c;
  
  local_d0 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  local_e8 = &_gp;
  local_2c = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  free_func = (char *)Ptag;
  pAStack_160 = (ASN1_STRING *)Ptag;
  local_d4 = (ASN1_STRING **)pp;
  if (a == (ASN1_STRING **)0x0) {
LAB_0060ebd4:
    pcStack_1d8 = (char *)length;
    pAStack_110 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_1dc = (char *)pp;
    if (pAStack_110 != (ASN1_STRING *)0x0) {
      free_func = auStack_b4;
      pcStack_1d8 = local_bc + 4;
      pcStack_1dc = local_bc;
      local_c0 = *local_d4;
      local_f8 = (ASN1_STRING *)length;
      uVar2 = (**(code **)(local_e8 + -0x6e30))(&local_c0);
      pAVar3 = pAStack_110;
      if ((uVar2 & 0x80) == 0) goto LAB_0060ec1c;
      length = (long)(ASN1_STRING *)0x66;
      goto LAB_0060ec2c;
    }
    goto LAB_0060eb90;
  }
  pAStack_110 = *a;
  free_func = auStack_b4;
  if (pAStack_110 == (ASN1_STRING *)0x0) goto LAB_0060ebd4;
  local_c0 = (ASN1_STRING *)*pp;
  pcStack_1d8 = local_bc + 4;
  pcStack_1dc = local_bc;
  local_f8 = (ASN1_STRING *)length;
  uVar2 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&local_c0);
  pAVar3 = pAStack_110;
  if ((uVar2 & 0x80) != 0) {
    length = 0x66;
    if (pAStack_110 != *a) {
      pcVar14 = *(code **)(local_e8 + -0x6644);
      goto LAB_0060eb80;
    }
    goto LAB_0060ec50;
  }
LAB_0060ec1c:
  pAStack_110 = pAVar3;
  if (Ptag != local_bc._4_4_) {
    length = (long)&DAT_000000a8;
    goto LAB_0060ec2c;
  }
  if ((uVar2 & 0x20) != 0) {
    local_84.data = (uchar *)0x0;
    local_60 = local_d4;
    local_84.length = (int)local_c0;
    local_6c = local_bc._0_4_;
    local_70 = (ASN1_STRING *)Pclass;
    if (length == 0) {
      local_68 = (uchar *)0x0;
    }
    else {
      local_68 = (uchar *)((int)&local_c0->length + length);
    }
    unaff_s4 = (uchar *)0x0;
    local_d8 = (ASN1_STRING **)0x0;
    local_9c = (uchar *)0x0;
    unaff_s7 = &local_84;
    local_94 = 0;
    unaff_s6 = (ASN1_STRING *)auStack_a4;
    local_98 = (uchar *)0x0;
    pAStack_160 = (ASN1_STRING *)(local_ac + 4);
    local_c4 = "a_bytes.c";
    uVar4 = uVar2 & 1;
    local_84.flags = uVar2;
    local_74 = (ASN1_STRING *)Ptag;
    do {
      if (uVar4 == 0) {
        if (0 < (int)local_6c) goto LAB_0060ed04;
LAB_0060eea4:
        length = (long)&local_84;
        iVar7 = (**(code **)(local_e8 + -0x69e4))(length);
        if (iVar7 != 0) {
          pAVar3->length = (int)unaff_s4;
          if (pAVar3->data != (uchar *)0x0) {
            (**(code **)(local_e8 + -0x7f58))();
          }
          pAVar3->data = local_98;
          pAVar6 = (ASN1_STRING *)local_84.length;
          if (local_d8 != (ASN1_STRING **)0x0) {
            (**(code **)(local_e8 + -0x6644))(local_d8);
            pAVar6 = (ASN1_STRING *)local_84.length;
          }
          goto LAB_0060ee40;
        }
LAB_0060ed80:
        if (local_d8 != (ASN1_STRING **)0x0) goto LAB_0060ed88;
        goto LAB_0060ed9c;
      }
      pcStack_1dc = (char *)(local_68 + -local_84.length);
      local_84.type = (**(code **)(local_e8 + -0x69e0))(unaff_s7);
      if (local_84.type != 0) goto LAB_0060eea4;
LAB_0060ed04:
      pAVar6 = local_74;
      local_dc = local_70;
      local_64 = (ASN1_STRING *)local_84.length;
      unaff_s5 = (ASN1_STRING *)(local_68 + -local_84.length);
      ppAVar12 = local_d8;
      if ((local_d8 == (ASN1_STRING **)0x0) &&
         (ppAVar12 = (ASN1_STRING **)(**(code **)(local_e8 + -0x6650))(),
         ppAVar12 == (ASN1_STRING **)0x0)) goto LAB_0060ed9c;
      pcStack_1dc = auStack_b4 + 8;
      local_b0 = (ASN1_STRING *)local_84.length;
      pcStack_1d8 = (char *)pAStack_160;
      free_func = (char *)unaff_s6;
      local_f8 = unaff_s5;
      uVar2 = (**(code **)(local_e8 + -0x6e30))(auStack_b4 + 4);
      if ((uVar2 & 0x80) != 0) {
        local_84.data = (uchar *)0x66;
LAB_0060ed64:
        if (ppAVar12 != local_d8) {
          (**(code **)(local_e8 + -0x6644))(ppAVar12);
        }
        goto LAB_0060ed80;
      }
      if (pAVar6 != local_ac._4_4_) {
        local_84.data = &DAT_000000a8;
        goto LAB_0060ed64;
      }
      if ((uVar2 & 0x20) == 0) {
        if (local_ac._0_4_ == (ASN1_STRING *)0x0) {
          if (ppAVar12[2] == (ASN1_STRING *)0x0) {
            unaff_s5 = (ASN1_STRING *)0x0;
            local_84.length = (int)local_b0;
          }
          else {
            unaff_s5 = (ASN1_STRING *)0x0;
            (**(code **)(local_e8 + -0x7f58))();
            local_84.length = (int)local_b0;
          }
        }
        else {
          if (((int)*ppAVar12 < (int)local_ac._0_4_) ||
             (unaff_s5 = ppAVar12[2], unaff_s5 == (ASN1_STRING *)0x0)) {
            pcStack_1d8 = &DAT_000000e9;
            pcStack_1dc = local_c4;
            unaff_s5 = (ASN1_STRING *)
                       (**(code **)(local_e8 + -0x7dd8))
                                 ((uchar *)((int)&(local_ac._0_4_)->length + 1));
            if (unaff_s5 == (ASN1_STRING *)0x0) {
              local_84.data = &DAT_00000041;
              goto LAB_0060ed64;
            }
            if (ppAVar12[2] != (ASN1_STRING *)0x0) {
              (**(code **)(local_e8 + -0x7f58))();
            }
          }
          pcStack_1d8 = (char *)local_ac._0_4_;
          (**(code **)(local_e8 + -0x52f4))(unaff_s5,local_b0);
          *(uchar *)((int)&(local_ac._0_4_)->length + (int)&unaff_s5->length) = '\0';
          local_84.length = (int)((int)&(local_ac._0_4_)->length + (int)&local_b0->length);
        }
        *ppAVar12 = local_ac._0_4_;
        ppAVar12[2] = unaff_s5;
        ppAVar12[1] = pAVar6;
        pAVar6 = local_ac._0_4_;
      }
      else {
        local_58.data = (uchar *)0x0;
        local_58.length = (int)local_b0;
        local_40 = local_ac._0_4_;
        local_48 = pAVar6;
        local_44 = local_dc;
        if (unaff_s5 == (ASN1_STRING *)0x0) {
          local_3c = (uchar *)0x0;
        }
        else {
          local_3c = (uchar *)((int)&unaff_s5->length + (int)&local_b0->length);
        }
        local_cc = &local_58;
        local_dc = (ASN1_STRING *)0x0;
        auStack_a4._4_4_ = (ASN1_STRING **)0x0;
        unaff_s5 = (ASN1_STRING *)(auStack_a4 + 4);
        local_c8 = &local_58.data;
        local_90 = 0;
        local_88 = 0;
        local_8c = (ASN1_STRING *)0x0;
        pcStack_1dc = (char *)local_ac._0_4_;
        local_58.flags = uVar2;
        local_34 = unaff_s7;
        if ((uVar2 & 1) != 0) goto LAB_0060f054;
        while (pcVar14 = *(code **)(local_e8 + -0x69e4), 0 < (int)local_40) {
          while( true ) {
            local_f0 = local_c8;
            local_f8 = local_44;
            pcStack_1d8 = (char *)(local_3c + -local_58.length);
            local_38 = (ASN1_STRING *)local_58.length;
            local_f4 = 2;
            pcStack_1dc = (char *)local_cc;
            free_func = (char *)local_48;
            iVar7 = int_d2i_ASN1_bytes(unaff_s5);
            if (iVar7 == 0) goto LAB_0060f1ac;
            pcStack_1dc = (char *)((int)&(*auStack_a4._4_4_)->length + (int)&local_dc->length);
            iVar7 = (**(code **)(local_e8 + -0x72a0))(&local_90);
            if (iVar7 == 0) {
              local_58.data = &DAT_00000007;
              goto LAB_0060f1ac;
            }
            pcStack_1d8 = (char *)*auStack_a4._4_4_;
            pcStack_1dc = (char *)auStack_a4._4_4_[2];
            (**(code **)(local_e8 + -0x52f4))
                      ((uchar *)((int)&local_dc->length + (int)&local_8c->length));
            if ((local_58.flags & 1U) == 0) {
              pcStack_1dc = (char *)(local_58.length - (int)local_38);
              local_40 = (ASN1_STRING *)((int)local_40 - (int)pcStack_1dc);
            }
            local_dc = (ASN1_STRING *)((int)&(*auStack_a4._4_4_)->length + (int)&local_dc->length);
            if ((local_58.flags & 1U) == 0) break;
LAB_0060f054:
            pcStack_1dc = (char *)(local_3c + -local_58.length);
            local_58.type = (**(code **)(local_e8 + -0x69e0))(local_cc);
            if (local_58.type != 0) {
              pcVar14 = *(code **)(local_e8 + -0x69e4);
              goto LAB_0060f07c;
            }
          }
        }
LAB_0060f07c:
        iVar7 = (*pcVar14)(local_cc);
        if (iVar7 == 0) {
LAB_0060f1ac:
          if (auStack_a4._4_4_ != (ASN1_STRING **)0x0) {
            (**(code **)(local_e8 + -0x6644))();
          }
          if (local_8c != (ASN1_STRING *)0x0) {
            (**(code **)(local_e8 + -0x7f58))();
          }
          local_84.data = local_58.data;
          goto LAB_0060ed64;
        }
        *ppAVar12 = local_dc;
        if (ppAVar12[2] != (ASN1_STRING *)0x0) {
          (**(code **)(local_e8 + -0x7f58))();
        }
        ppAVar12[2] = local_8c;
        if (auStack_a4._4_4_ != (ASN1_STRING **)0x0) {
          (**(code **)(local_e8 + -0x6644))();
        }
        local_84.length = local_58.length;
        pAVar6 = *ppAVar12;
      }
      pcStack_1dc = (char *)((int)&pAVar6->length + (int)unaff_s4);
      iVar7 = (**(code **)(local_e8 + -0x72a0))(&local_9c);
      if (iVar7 == 0) goto LAB_0060f214;
      pcStack_1d8 = (char *)*ppAVar12;
      pcStack_1dc = (char *)ppAVar12[2];
      (**(code **)(local_e8 + -0x52f4))(local_98 + (int)unaff_s4);
      uVar4 = local_84.flags & 1;
      if (uVar4 == 0) {
        pcStack_1dc = (char *)(local_84.length - (int)local_64);
        local_6c = (ASN1_STRING *)((int)local_6c - (int)pcStack_1dc);
      }
      unaff_s4 = (uchar *)((int)&(*ppAVar12)->length + (int)unaff_s4);
      local_d8 = ppAVar12;
    } while( true );
  }
  if (local_bc._0_4_ == (ASN1_STRING *)0x0) {
    if (pAVar3->data == (uchar *)0x0) {
      length = 0;
      pAVar6 = local_c0;
    }
    else {
      length = 0;
      (**(code **)(local_e8 + -0x7f58))();
      pAVar6 = local_c0;
    }
  }
  else {
    if (pAVar3->length < (int)local_bc._0_4_) {
      pcVar14 = *(code **)(local_e8 + -0x7dd8);
LAB_0060f228:
      pcStack_1d8 = &DAT_000000e9;
      pcStack_1dc = "a_bytes.c";
      length = (*pcVar14)((uchar *)((int)&(local_bc._0_4_)->length + 1));
      if ((ASN1_STRING *)length == (ASN1_STRING *)0x0) {
        length = (long)&DAT_00000041;
        goto LAB_0060ec2c;
      }
      if (pAVar3->data != (uchar *)0x0) {
        (**(code **)(local_e8 + -0x7f58))();
      }
    }
    else {
      length = (long)pAVar3->data;
      pcVar14 = *(code **)(local_e8 + -0x7dd8);
      if ((ASN1_STRING *)length == (ASN1_STRING *)0x0) goto LAB_0060f228;
    }
    pcStack_1dc = (char *)local_c0;
    pcStack_1d8 = (char *)local_bc._0_4_;
    (**(code **)(local_e8 + -0x52f4))(length);
    *(uchar *)((int)&(local_bc._0_4_)->length + (int)(int *)length) = '\0';
    pAVar6 = (ASN1_STRING *)((int)&(local_bc._0_4_)->length + (int)&local_c0->length);
  }
  pAVar3->length = (int)local_bc._0_4_;
  pAVar3->data = (uchar *)length;
  pAVar3->type = Ptag;
LAB_0060ee40:
  if (a != (ASN1_STRING **)0x0) {
    *a = pAVar3;
  }
  *local_d4 = pAVar6;
  goto LAB_0060eb94;
LAB_0060f214:
  local_84.data = &DAT_00000007;
  local_d8 = ppAVar12;
LAB_0060ed88:
  (**(code **)(local_e8 + -0x6644))(local_d8);
LAB_0060ed9c:
  length = (long)local_84.data;
  if (local_98 != (uchar *)0x0) {
    (**(code **)(local_e8 + -0x7f58))();
    length = (long)local_84.data;
  }
LAB_0060ec2c:
  pcVar14 = *(code **)(local_e8 + -0x6644);
  if ((a == (ASN1_STRING **)0x0) || (*a != pAStack_110)) {
LAB_0060eb80:
    (*pcVar14)(pAStack_110);
    if ((ASN1_STRING *)length != (ASN1_STRING *)0x0) {
LAB_0060ec50:
      pcVar14 = *(code **)(local_e8 + -0x6eac);
      goto LAB_0060ec58;
    }
  }
  else if ((ASN1_STRING *)length != (ASN1_STRING *)0x0) {
    pcVar14 = *(code **)(local_e8 + -0x6eac);
LAB_0060ec58:
    pcStack_1dc = (char *)0x8f;
    free_func = "a_bytes.c";
    local_f8 = (ASN1_STRING *)0xaf;
    pcStack_1d8 = (char *)length;
    (*pcVar14)(0xd);
    pAVar3 = (ASN1_STRING *)0x0;
    goto LAB_0060eb94;
  }
LAB_0060eb90:
  pAVar3 = (ASN1_STRING *)0x0;
LAB_0060eb94:
  if (local_2c == *local_d0) {
    return pAVar3;
  }
  uStack_10c = 0x60f2d8;
  puStack_118 = local_2c;
  (**(code **)(local_e8 + -0x5330))();
  pAStack_1a0 = (ASN1_STRING *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_1e0 = &puStack_118;
  psStack_114 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  pAVar3 = (ASN1_STRING *)
           d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_1e0,(long)pcStack_1dc,pcStack_1d8,
                        (free_func *)free_func,0x10,0);
  if (pAVar3 == (ASN1_STRING *)0x0) {
    pcStack_1dc = &DAT_0000006e;
    pcStack_1d8 = "asn_pack.c";
    ppuStack_1e0 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_114 == *(stack_st_OPENSSL_BLOCK **)pAStack_1a0) {
    return pAVar3;
  }
  pcStack_14c = ASN1_seq_pack;
  a_00 = psStack_114;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1e4 = PTR___stack_chk_guard_006a9ae8;
  puStack_16c = (undefined *)pAStack_1a0;
  puStack_174 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pAStack_168 = (ASN1_STRING *)length;
  ppAStack_164 = a;
  puStack_15c = unaff_s4;
  pAStack_158 = unaff_s5;
  pAStack_154 = unaff_s6;
  pAStack_150 = unaff_s7;
  pAVar3 = (ASN1_STRING *)i2d_ASN1_SET(a_00,(uchar **)0x0,(undefined1 *)ppuStack_1e0,0x10,0,0);
  if (pAVar3 == (ASN1_STRING *)0x0) {
    ppAVar12 = (ASN1_STRING **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAStack_1a0 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAVar3,"asn_pack.c",0x62);
    length = (long)pAVar3;
    if (pAStack_1a0 == (ASN1_STRING *)0x0) {
      ppAVar12 = (ASN1_STRING **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      pAVar3 = (ASN1_STRING *)0x0;
    }
    else {
      ppAVar12 = &pAStack_178;
      pAStack_178 = pAStack_1a0;
      i2d_ASN1_SET(a_00,(uchar **)ppAVar12,(undefined1 *)ppuStack_1e0,0x10,0,0);
      if ((ASN1_STRING *)pcStack_1d8 != (ASN1_STRING *)0x0) {
        *(int *)pcStack_1d8 = (int)pAVar3;
      }
      pAVar3 = pAStack_1a0;
      if ((ASN1_STRING *)pcStack_1dc != (ASN1_STRING *)0x0) {
        *(int *)pcStack_1dc = (int)pAStack_1a0;
      }
    }
  }
  if (puStack_174 == *(undefined4 **)puStack_1e4) {
    return pAVar3;
  }
  pcStack_19c = ASN1_unpack_string;
  puVar9 = puStack_174;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1ec = PTR___stack_chk_guard_006a9ae8;
  uStack_1a8 = puVar9[2];
  ppAVar11 = (ASN1_STRING **)*puVar9;
  puVar9 = &uStack_1a8;
  puStack_1b8 = &_gp;
  iStack_1a4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar3 = (ASN1_STRING *)(*(code *)ppAVar12)(0);
  if (pAVar3 == (ASN1_STRING *)0x0) {
    ppAVar11 = (ASN1_STRING **)&DAT_0000006e;
    uStack_1c0 = 0x79;
    puVar9 = (undefined4 *)&DAT_00000088;
    pAStack_1ac = pAVar3;
    (**(code **)(puStack_1b8 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    pAVar3 = pAStack_1ac;
  }
  if (iStack_1a4 == *(int *)puStack_1ec) {
    return pAVar3;
  }
  pcStack_1d4 = ASN1_pack_string;
  iVar7 = iStack_1a4;
  (**(code **)(puStack_1b8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_1f4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_1e8 = (ASN1_STRING *)length;
  if (ppAVar11 == (ASN1_STRING **)0x0) {
    pAVar3 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar3 != (ASN1_STRING *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppAVar12 = (ASN1_STRING **)&DAT_00000041;
    ppuVar10 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    pAVar6 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar3 = *ppAVar11;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      pAVar3 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_0060f754;
      *ppAVar11 = pAVar3;
    }
LAB_0060f614:
    iVar5 = (*(code *)puVar9)(iVar7,0);
    pAVar3->length = iVar5;
    if (iVar5 == 0) {
      ppAVar12 = (ASN1_STRING **)&DAT_00000070;
      ppuVar10 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppAVar12 = (ASN1_STRING **)&DAT_00000092;
      puStack_1f8 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"asn_pack.c");
      if (puStack_1f8 != (uchar *)0x0) {
        ppuVar10 = &puStack_1f8;
        pAVar3->data = puStack_1f8;
        (*(code *)puVar9)(iVar7,ppuVar10);
        pAVar6 = pAVar3;
        goto LAB_0060f670;
      }
      ppAVar12 = (ASN1_STRING **)&DAT_00000041;
      ppuVar10 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppAVar11 == (ASN1_STRING **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar3);
      pAVar6 = (ASN1_STRING *)0x0;
    }
    else {
      pAVar6 = *ppAVar11;
      if (pAVar6 == (ASN1_STRING *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar3);
        *ppAVar11 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar6 = (ASN1_STRING *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_1f4 == *(int *)puVar1) {
    return pAVar6;
  }
  iVar7 = iStack_1f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppAVar12 == (ASN1_STRING **)0x0) {
    pAVar3 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar3 == (ASN1_STRING *)0x0) {
LAB_0060f874:
      uVar13 = 0x41;
      uVar8 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    pAVar3 = *ppAVar12;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      pAVar3 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_0060f874;
      *ppAVar12 = pAVar3;
    }
  }
  if (pAVar3->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    pAVar3->data = (uchar *)0x0;
  }
  iVar7 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar7,&pAVar3->data,ppuVar10);
  pAVar3->length = iVar7;
  if (iVar7 == 0) {
    uVar13 = 0x70;
    uVar8 = 0xba;
  }
  else {
    if (pAVar3->data != (uchar *)0x0) {
      return pAVar3;
    }
    uVar13 = 0x41;
    uVar8 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar13,"asn_pack.c",uVar8);
  return (ASN1_STRING *)0x0;
}

