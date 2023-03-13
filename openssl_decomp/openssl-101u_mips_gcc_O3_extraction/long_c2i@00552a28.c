
int long_c2i(uint *param_1,byte *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            char *param_6)

{
  ushort uVar1;
  uint3 uVar2;
  uint *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  ASN1_VALUE ****ppppAVar7;
  undefined4 *puVar8;
  ASN1_VALUE *****pppppAVar9;
  byte *pbVar10;
  ASN1_VALUE *****pppppAVar11;
  int iVar12;
  undefined1 *puVar13;
  ASN1_VALUE ****ppppAVar14;
  byte *unaff_s1;
  ASN1_VALUE ****ppppAVar15;
  ASN1_VALUE *****pppppAStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  undefined *puStack_90;
  byte *pbStack_8c;
  undefined *puStack_88;
  undefined *puStack_84;
  uint local_10;
  
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  if (param_3 < 5) {
    if (param_3 == 0) {
LAB_00552ba4:
      local_10 = 0;
    }
    else if ((char)*param_2 < '\0') {
      if (param_3 < 1) {
        local_10 = 0xffffffff;
      }
      else {
        local_10 = ~(uint)*param_2 & 0xff;
        if (((param_3 != 1) && (local_10 = ~(uint)param_2[1] & 0xff | local_10 << 8, param_3 != 2))
           && (local_10 = ~(uint)param_2[2] & 0xff | local_10 << 8, param_3 == 4)) {
          local_10 = ~(uint)param_2[3] & 0xff | local_10 << 8;
        }
        local_10 = ~local_10;
      }
    }
    else {
      if (param_3 < 1) goto LAB_00552ba4;
      local_10 = (uint)*param_2;
      if (param_3 != 1) {
        uVar1 = CONCAT11(*param_2,param_2[1]);
        local_10 = (uint)uVar1;
        if (param_3 != 2) {
          uVar2 = CONCAT21(uVar1,param_2[2]);
          local_10 = (uint)uVar2;
          if (param_3 == 4) {
            local_10 = CONCAT31(uVar2,param_2[3]);
          }
        }
      }
    }
    if (local_10 == *(uint *)(param_6 + 0x14)) goto LAB_00552afc;
    iVar5 = 1;
    *param_1 = local_10;
  }
  else {
LAB_00552afc:
    param_6 = "x_long.c";
    param_2 = (byte *)0xa6;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa6,0x80);
    iVar5 = 0;
  }
  if (puVar8 == *(undefined4 **)puStack_90) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  puStack_88 = (undefined *)*puVar8;
  pppppAVar9 = *(ASN1_VALUE ******)PTR___stack_chk_guard_006a9ae8;
  if (*(undefined **)(param_6 + 0x14) == puStack_88) {
    iVar5 = -1;
    param_2 = unaff_s1;
  }
  else {
    puStack_90 = puStack_88;
    if ((int)puStack_88 < 0) {
      puStack_90 = (undefined *)~(uint)puStack_88;
    }
    uVar6 = (*(code *)PTR_BN_num_bits_word_006a859c)(puStack_90);
    puVar4 = puStack_90;
    if ((uVar6 & 7) == 0) {
      iVar5 = (int)(uVar6 + 7) >> 3;
      if (param_2 == (byte *)0x0) {
        iVar12 = 1;
      }
      else {
        iVar12 = 1;
        *param_2 = (byte)((int)puStack_88 >> 0x1f);
        param_2 = param_2 + 1;
LAB_00552c40:
        if (0 < iVar5) {
          pbVar10 = param_2 + iVar5;
          if ((int)puStack_88 < 0) {
            do {
              pbVar10[-1] = ~(byte)puStack_90;
              puVar4 = (undefined *)((uint)puStack_90 >> 8);
              if (param_2 == pbVar10 + -1) goto LAB_00552c60;
              uVar6 = (uint)puStack_90 >> 8;
              pbVar10 = pbVar10 + -2;
              puStack_90 = (undefined *)((uint)puStack_90 >> 0x10);
              *pbVar10 = ~(byte)uVar6;
            } while (param_2 != pbVar10);
            iVar5 = iVar5 + iVar12;
            goto LAB_00552c64;
          }
          do {
            pbVar10[-1] = (byte)puStack_90;
            pbVar10 = pbVar10 + -1;
            puStack_90 = (undefined *)((uint)puStack_90 >> 8);
            puVar4 = puStack_90;
          } while (param_2 != pbVar10);
        }
      }
LAB_00552c60:
      puStack_90 = puVar4;
      iVar5 = iVar5 + iVar12;
    }
    else {
      iVar12 = 0;
      iVar5 = (int)(uVar6 + 7) >> 3;
      if (param_2 != (byte *)0x0) goto LAB_00552c40;
    }
  }
LAB_00552c64:
  if (pppppAVar9 == *(ASN1_VALUE ******)puStack_84) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = X509_NAME_ENTRY_it._8_4_;
  puVar13 = X509_NAME_ENTRY_it;
  uVar6 = (uint)X509_NAME_ENTRY_it[0];
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppppAVar11 = pppppAVar9;
  pppppAStack_9c = pppppAVar9;
  pbStack_8c = param_2;
  if (uVar6 == 0) {
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      pppppAVar11 = (ASN1_VALUE *****)&pppppAStack_9c;
      if (X509_NAME_ENTRY_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pppppAVar11,(ASN1_ITEM *)X509_NAME_ENTRY_it);
      }
      else {
        iVar5 = 0;
        if ((*X509_NAME_ENTRY_it._8_4_ & 6) == 0) {
          puVar13 = (undefined1 *)X509_NAME_ENTRY_it._8_4_[4];
          pppppAVar11 = (ASN1_VALUE *****)&pppppAStack_9c;
          asn1_item_combine_free(pppppAVar11,puVar13,*X509_NAME_ENTRY_it._8_4_ & 0x400);
        }
        else {
          puVar13 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
          for (; iVar12 = (*(code *)PTR_sk_num_006a6e2c)(pppppAVar9), iVar5 < iVar12;
              iVar5 = iVar5 + 1) {
            uStack_98 = (*(code *)PTR_sk_value_006a6e24)(pppppAVar9,iVar5);
            puVar13 = (undefined1 *)puVar3[4];
            asn1_item_combine_free(&uStack_98,puVar13,0);
          }
          (*(code *)PTR_sk_free_006a6e80)();
          pppppAVar11 = pppppAVar9;
        }
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  else {
    puVar13 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if (pppppAVar9 == (ASN1_VALUE *****)0x0) goto switchD_0055c4c0_caseD_0;
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar6 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar5 = (*(code *)(&switchD_0055c4c0::switchdataD_00669fb0)[uVar6 & 0xff])();
        return iVar5;
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  if (X509_NAME_ENTRY_it._16_4_[4] == 0) {
    puVar13 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar6 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar5 = (*(code *)(&switchD_0055c6fc::switchdataD_00669fcc)[uVar6 & 0xff])();
      return iVar5;
    }
  }
  else {
    puVar13 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar6 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar5 = (*(code *)(&switchD_0055c3bc::switchdataD_00669f94)[uVar6 & 0xff])();
      return iVar5;
    }
  }
switchD_0055c4c0_caseD_0:
  if (iStack_94 != *(int *)puVar4) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppppAVar15 = pppppAVar11[1];
    ppppAVar14 = *(ASN1_VALUE *****)((int)puVar13 + 4);
    ppppAVar7 = ppppAVar15;
    if ((int)ppppAVar14 <= (int)ppppAVar15) {
      ppppAVar7 = ppppAVar14;
    }
    iVar5 = (*(code *)PTR_memcmp_006a9ad0)(*pppppAVar11,*(undefined4 *)puVar13,ppppAVar7);
    if (iVar5 == 0) {
      iVar5 = (int)ppppAVar15 - (int)ppppAVar14;
    }
    return iVar5;
  }
  return *(int *)puVar4;
}

