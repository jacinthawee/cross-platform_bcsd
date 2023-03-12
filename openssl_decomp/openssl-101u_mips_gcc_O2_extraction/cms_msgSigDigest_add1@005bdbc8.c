
int * cms_msgSigDigest_add1(undefined4 param_1,undefined *param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  stack_st_CMS_SignerInfo *psVar6;
  stack_st_CMS_SignerInfo *psVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_OCTET_STRING **ppAVar9;
  int iVar10;
  CMS_ContentInfo *cms;
  CMS_ContentInfo *cms_00;
  undefined4 uVar11;
  int iVar12;
  int unaff_s4;
  undefined4 *puStack_ec;
  int iStack_e8;
  undefined auStack_e4 [64];
  int iStack_a4;
  undefined *puStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined auStack_54 [64];
  CMS_ContentInfo *local_14;
  
  puStack_9c = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(CMS_ContentInfo **)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(param_2 + 8));
  uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
  iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
  if (iVar4 == 0) {
LAB_005bdc94:
    cms_00 = (CMS_ContentInfo *)&DAT_000000a2;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa2,0xac,s_cms_ess_c_006721bc);
    piVar5 = (int *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(param_2 + 0xc);
    param_2 = auStack_54;
    iVar4 = (*(code *)PTR_ASN1_item_digest_006a8fc0)
                      (PTR_CMS_Attributes_Verify_it_006a9398,iVar4,*puVar1,param_2);
    if (iVar4 == 0) goto LAB_005bdc94;
    cms_00 = (CMS_ContentInfo *)&DAT_000000d8;
    piVar5 = (int *)(*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)(param_1,0xd8,4,param_2);
    if (piVar5 == (int *)0x0) {
      cms_00 = (CMS_ContentInfo *)&DAT_000000a2;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa2,0x41,s_cms_ess_c_006721bc);
    }
    else {
      piVar5 = (int *)0x1;
    }
  }
  if (local_14 == *(CMS_ContentInfo **)puStack_9c) {
    return piVar5;
  }
  cms = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_ec = (undefined4 *)0x0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_98 = param_2;
  uStack_94 = param_1;
  psVar6 = CMS_get0_SignerInfos(cms_00);
  psVar7 = CMS_get0_SignerInfos(cms);
  if ((psVar6 == (stack_st_CMS_SignerInfo *)0x0) || (psVar7 == (stack_st_CMS_SignerInfo *)0x0))
  goto LAB_005bddd8;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar7);
  if (iVar4 == 1) {
    pAVar8 = CMS_get0_eContentType(cms);
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar8);
    if (iVar4 == 0xcc) {
      ppAVar9 = CMS_get0_content(cms);
      if (ppAVar9 != (ASN1_OCTET_STRING **)0x0) {
        if (*ppAVar9 != (ASN1_OCTET_STRING *)0x0) {
          unaff_s4 = (*(code *)PTR_ASN1_item_unpack_006a91d8)(*ppAVar9,PTR_CMS_Receipt_it_006a93f0);
          if (unaff_s4 != 0) {
            iVar4 = 0;
            iVar12 = 0;
            while( true ) {
              iVar10 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
              if (iVar10 <= iVar12) break;
              iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar6,iVar12);
              iVar10 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                                 (*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(unaff_s4 + 0xc));
              if (iVar10 == 0) break;
              iVar12 = iVar12 + 1;
            }
            iVar10 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
            if (iVar12 == iVar10) {
              uVar11 = 0xa6;
              uVar3 = 0x112;
              goto LAB_005bdfe0;
            }
            uVar3 = (*(code *)PTR_sk_value_006a6e24)(psVar7,0);
            uVar11 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xd8);
            piVar5 = (int *)(*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)
                                      (uVar3,uVar11,0xfffffffd,4);
            if (piVar5 == (int *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,0xa7,s_cms_ess_c_006721bc,0x120);
              goto LAB_005bdff8;
            }
            uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar4 + 8));
            uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
            iVar12 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
            if (iVar12 != 0) {
              iVar12 = (*(code *)PTR_ASN1_item_digest_006a8fc0)
                                 (PTR_CMS_Attributes_Verify_it_006a9398,iVar12,
                                  *(undefined4 *)(iVar4 + 0xc),auStack_e4,&iStack_e8);
              if (iVar12 != 0) {
                if (*piVar5 != iStack_e8) {
                  uVar11 = 0xa3;
                  uVar3 = 0x12a;
                  goto LAB_005bdfe0;
                }
                iVar12 = (*(code *)PTR_memcmp_006a9ad0)(auStack_e4,piVar5[2]);
                if (iVar12 != 0) {
                  uVar11 = 0xa2;
                  uVar3 = 0x130;
                  goto LAB_005bdfe0;
                }
                uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x32);
                iVar12 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)
                                   (iVar4,uVar3,0xfffffffd,6);
                if (iVar12 == 0) {
                  uVar11 = 0xad;
                  uVar3 = 0x13a;
                  goto LAB_005bdfe0;
                }
                iVar12 = (*(code *)PTR_OBJ_cmp_006a8cc4)(iVar12,*(undefined4 *)(unaff_s4 + 4));
                if (iVar12 != 0) {
                  uVar11 = 0xab;
                  uVar3 = 0x141;
                  goto LAB_005bdfe0;
                }
                iVar4 = CMS_get1_ReceiptRequest(iVar4,&puStack_ec);
                if (0 < iVar4) {
                  iVar4 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                                    (*puStack_ec,*(undefined4 *)(unaff_s4 + 8));
                  if (iVar4 != 0) goto LAB_005be194;
                  piVar5 = (int *)0x1;
                  goto LAB_005bdff8;
                }
                uVar11 = 0xa8;
                uVar3 = 0x148;
                goto LAB_005bdfe0;
              }
            }
            uVar11 = 0xac;
            uVar3 = 0x125;
            goto LAB_005bdfe0;
          }
          uVar11 = 0xa9;
          uVar3 = 0x105;
          goto LAB_005bddc4;
        }
      }
      uVar11 = 0x7f;
      uVar3 = 0xfe;
    }
    else {
      uVar11 = 0xa5;
      uVar3 = 0xf7;
    }
  }
  else {
    uVar11 = 0xa4;
    uVar3 = 0xf1;
  }
LAB_005bddc4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,uVar11,s_cms_ess_c_006721bc,uVar3);
LAB_005bddd8:
  if (puStack_ec != (undefined4 *)0x0) {
    (*(code *)PTR_ASN1_item_free_006a8658)(puStack_ec,PTR_CMS_ReceiptRequest_it_006a93ec);
  }
  piVar5 = (int *)0x0;
  while( true ) {
    if (iStack_a4 == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005be194:
    uVar11 = 0xaa;
    uVar3 = 0x14e;
LAB_005bdfe0:
    piVar5 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,uVar11,s_cms_ess_c_006721bc,uVar3);
LAB_005bdff8:
    if (puStack_ec != (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a8658)(puStack_ec,PTR_CMS_ReceiptRequest_it_006a93ec);
    }
    (*(code *)PTR_ASN1_item_free_006a8658)(unaff_s4,PTR_CMS_Receipt_it_006a93f0);
  }
  return piVar5;
}

