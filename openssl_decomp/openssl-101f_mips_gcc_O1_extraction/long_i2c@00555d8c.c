
int long_i2c(uint *param_1,byte *param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ASN1_VALUE ****ppppAVar6;
  ASN1_VALUE *****pppppAVar7;
  byte *pbVar8;
  ASN1_VALUE *****pppppAVar9;
  int iVar10;
  undefined1 *puVar11;
  uint unaff_s0;
  ASN1_VALUE ****ppppAVar12;
  byte *unaff_s1;
  ASN1_VALUE ****ppppAVar13;
  ASN1_VALUE *****pppppAStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  uint uStack_60;
  byte *pbStack_5c;
  uint uStack_58;
  undefined *puStack_54;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  uStack_58 = *param_1;
  pppppAVar7 = *(ASN1_VALUE ******)PTR___stack_chk_guard_006aabf0;
  if (*(uint *)(param_4 + 0x14) == uStack_58) {
    iVar4 = -1;
    param_2 = unaff_s1;
  }
  else {
    unaff_s0 = uStack_58;
    if ((int)uStack_58 < 0) {
      unaff_s0 = ~uStack_58;
    }
    uVar3 = (*(code *)PTR_BN_num_bits_word_006a96c0)(unaff_s0);
    uVar5 = unaff_s0;
    if ((uVar3 & 7) == 0) {
      iVar4 = (int)(uVar3 + 7) >> 3;
      if (param_2 == (byte *)0x0) {
        iVar10 = 1;
      }
      else {
        iVar10 = 1;
        *param_2 = (byte)((int)uStack_58 >> 0x1f);
        param_2 = param_2 + 1;
LAB_00555e10:
        if (0 < iVar4) {
          pbVar8 = param_2 + iVar4;
          if ((int)uStack_58 < 0) {
            do {
              pbVar8[-1] = ~(byte)unaff_s0;
              uVar5 = unaff_s0 >> 8;
              if (param_2 == pbVar8 + -1) goto LAB_00555e30;
              uVar5 = unaff_s0 >> 8;
              pbVar8 = pbVar8 + -2;
              unaff_s0 = unaff_s0 >> 0x10;
              *pbVar8 = ~(byte)uVar5;
            } while (param_2 != pbVar8);
            iVar4 = iVar4 + iVar10;
            goto LAB_00555e34;
          }
          do {
            pbVar8[-1] = (byte)unaff_s0;
            pbVar8 = pbVar8 + -1;
            unaff_s0 = unaff_s0 >> 8;
            uVar5 = unaff_s0;
          } while (param_2 != pbVar8);
        }
      }
LAB_00555e30:
      unaff_s0 = uVar5;
      iVar4 = iVar4 + iVar10;
    }
    else {
      iVar10 = 0;
      iVar4 = (int)(uVar3 + 7) >> 3;
      if (param_2 != (byte *)0x0) goto LAB_00555e10;
    }
  }
LAB_00555e34:
  if (pppppAVar7 == *(ASN1_VALUE ******)puStack_54) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = X509_NAME_ENTRY_it._8_4_;
  puVar11 = X509_NAME_ENTRY_it;
  uVar5 = (uint)X509_NAME_ENTRY_it[0];
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  pppppAVar9 = pppppAVar7;
  pppppAStack_6c = pppppAVar7;
  uStack_60 = unaff_s0;
  pbStack_5c = param_2;
  if (uVar5 == 0) {
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      pppppAVar9 = (ASN1_VALUE *****)&pppppAStack_6c;
      if (X509_NAME_ENTRY_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pppppAVar9,(ASN1_ITEM *)X509_NAME_ENTRY_it);
      }
      else {
        iVar4 = 0;
        if ((*X509_NAME_ENTRY_it._8_4_ & 6) == 0) {
          puVar11 = (undefined1 *)X509_NAME_ENTRY_it._8_4_[4];
          pppppAVar9 = (ASN1_VALUE *****)&pppppAStack_6c;
          asn1_item_combine_free(pppppAVar9,puVar11,*X509_NAME_ENTRY_it._8_4_ & 0x400);
        }
        else {
          puVar11 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
          for (; iVar10 = (*(code *)PTR_sk_num_006a7f2c)(pppppAVar7), iVar4 < iVar10;
              iVar4 = iVar4 + 1) {
            uStack_68 = (*(code *)PTR_sk_value_006a7f24)(pppppAVar7,iVar4);
            puVar11 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&uStack_68,puVar11,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pppppAVar9 = pppppAVar7;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar11 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if (pppppAVar7 == (ASN1_VALUE *****)0x0) goto switchD_0055fb90_caseD_0;
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar5 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar4 = (*(code *)(&switchD_0055fb90::switchdataD_0066aa70)[uVar5 & 0xff])();
        return iVar4;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (X509_NAME_ENTRY_it._16_4_[4] == 0) {
    puVar11 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar5 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*(code *)(&switchD_0055fdcc::switchdataD_0066aa8c)[uVar5 & 0xff])();
      return iVar4;
    }
  }
  else {
    puVar11 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar5 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fa8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*(code *)(&switchD_0055fa8c::switchdataD_0066aa54)[uVar5 & 0xff])();
      return iVar4;
    }
  }
switchD_0055fb90_caseD_0:
  if (iStack_64 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    ppppAVar13 = pppppAVar9[1];
    ppppAVar12 = *(ASN1_VALUE *****)((int)puVar11 + 4);
    ppppAVar6 = ppppAVar13;
    if ((int)ppppAVar12 <= (int)ppppAVar13) {
      ppppAVar6 = ppppAVar12;
    }
    iVar4 = (*(code *)PTR_memcmp_006aabd8)(*pppppAVar9,*(undefined4 *)puVar11,ppppAVar6);
    if (iVar4 == 0) {
      iVar4 = (int)ppppAVar13 - (int)ppppAVar12;
    }
    return iVar4;
  }
  return *(int *)puVar2;
}

