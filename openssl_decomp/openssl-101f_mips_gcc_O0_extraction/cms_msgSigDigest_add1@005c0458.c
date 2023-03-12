
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
  
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  local_14 = *(CMS_ContentInfo **)PTR___stack_chk_guard_006aabf0;
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(**(undefined4 **)(param_2 + 8));
  uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
  iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
  if (iVar4 == 0) {
LAB_005c0524:
    cms_00 = (CMS_ContentInfo *)&DAT_000000a2;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa2,0xac,s_cms_ess_c_00672aac);
    piVar5 = (int *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(param_2 + 0xc);
    param_2 = auStack_54;
    iVar4 = (*(code *)PTR_ASN1_item_digest_006aa0d8)
                      (PTR_CMS_Attributes_Verify_it_006aa4a4,iVar4,*puVar1,param_2);
    if (iVar4 == 0) goto LAB_005c0524;
    cms_00 = (CMS_ContentInfo *)&DAT_000000d8;
    piVar5 = (int *)(*(code *)PTR_CMS_signed_add1_attr_by_NID_006aa49c)(param_1,0xd8,4,param_2);
    if (piVar5 == (int *)0x0) {
      cms_00 = (CMS_ContentInfo *)&DAT_000000a2;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa2,0x41,s_cms_ess_c_00672aac);
    }
    else {
      piVar5 = (int *)0x1;
    }
  }
  if (local_14 == *(CMS_ContentInfo **)puStack_9c) {
    return piVar5;
  }
  cms = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_ec = (undefined4 *)0x0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_98 = param_2;
  uStack_94 = param_1;
  psVar6 = CMS_get0_SignerInfos(cms_00);
  psVar7 = CMS_get0_SignerInfos(cms);
  if ((psVar6 == (stack_st_CMS_SignerInfo *)0x0) || (psVar7 == (stack_st_CMS_SignerInfo *)0x0))
  goto LAB_005c0668;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar7);
  if (iVar4 == 1) {
    pAVar8 = CMS_get0_eContentType(cms);
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pAVar8);
    if (iVar4 == 0xcc) {
      ppAVar9 = CMS_get0_content(cms);
      if (ppAVar9 != (ASN1_OCTET_STRING **)0x0) {
        if (*ppAVar9 != (ASN1_OCTET_STRING *)0x0) {
          unaff_s4 = (*(code *)PTR_ASN1_item_unpack_006aa2f0)(*ppAVar9,PTR_CMS_Receipt_it_006aa4fc);
          if (unaff_s4 != 0) {
            iVar4 = 0;
            iVar12 = 0;
            while( true ) {
              iVar10 = (*(code *)PTR_sk_num_006a7f2c)(psVar6);
              if (iVar10 <= iVar12) break;
              iVar4 = (*(code *)PTR_sk_value_006a7f24)(psVar6,iVar12);
              iVar10 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                 (*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(unaff_s4 + 0xc));
              if (iVar10 == 0) break;
              iVar12 = iVar12 + 1;
            }
            iVar10 = (*(code *)PTR_sk_num_006a7f2c)(psVar6);
            if (iVar12 == iVar10) {
              uVar11 = 0xa6;
              uVar3 = 0x120;
              goto LAB_005c0870;
            }
            uVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar7,0);
            uVar11 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xd8);
            piVar5 = (int *)(*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)
                                      (uVar3,uVar11,0xfffffffd,4);
            if (piVar5 == (int *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,0xa7,s_cms_ess_c_00672aac,0x12e);
              goto LAB_005c0888;
            }
            uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(**(undefined4 **)(iVar4 + 8));
            uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
            iVar12 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
            if (iVar12 != 0) {
              iVar12 = (*(code *)PTR_ASN1_item_digest_006aa0d8)
                                 (PTR_CMS_Attributes_Verify_it_006aa4a4,iVar12,
                                  *(undefined4 *)(iVar4 + 0xc),auStack_e4,&iStack_e8);
              if (iVar12 != 0) {
                if (*piVar5 != iStack_e8) {
                  uVar11 = 0xa3;
                  uVar3 = 0x13b;
                  goto LAB_005c0870;
                }
                iVar12 = (*(code *)PTR_memcmp_006aabd8)(auStack_e4,piVar5[2]);
                if (iVar12 != 0) {
                  uVar11 = 0xa2;
                  uVar3 = 0x142;
                  goto LAB_005c0870;
                }
                uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x32);
                iVar12 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)
                                   (iVar4,uVar3,0xfffffffd,6);
                if (iVar12 == 0) {
                  uVar11 = 0xad;
                  uVar3 = 0x14d;
                  goto LAB_005c0870;
                }
                iVar12 = (*(code *)PTR_OBJ_cmp_006a9de4)(iVar12,*(undefined4 *)(unaff_s4 + 4));
                if (iVar12 != 0) {
                  uVar11 = 0xab;
                  uVar3 = 0x155;
                  goto LAB_005c0870;
                }
                iVar4 = CMS_get1_ReceiptRequest(iVar4,&puStack_ec);
                if (0 < iVar4) {
                  iVar4 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                    (*puStack_ec,*(undefined4 *)(unaff_s4 + 8));
                  if (iVar4 != 0) goto LAB_005c0a24;
                  piVar5 = (int *)0x1;
                  goto LAB_005c0888;
                }
                uVar11 = 0xa8;
                uVar3 = 0x15d;
                goto LAB_005c0870;
              }
            }
            uVar11 = 0xac;
            uVar3 = 0x134;
            goto LAB_005c0870;
          }
          uVar11 = 0xa9;
          uVar3 = 0x110;
          goto LAB_005c0654;
        }
      }
      uVar11 = 0x7f;
      uVar3 = 0x108;
    }
    else {
      uVar11 = 0xa5;
      uVar3 = 0x100;
    }
  }
  else {
    uVar11 = 0xa4;
    uVar3 = 0xf9;
  }
LAB_005c0654:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,uVar11,s_cms_ess_c_00672aac,uVar3);
LAB_005c0668:
  if (puStack_ec != (undefined4 *)0x0) {
    (*(code *)PTR_ASN1_item_free_006a977c)(puStack_ec,PTR_CMS_ReceiptRequest_it_006aa4f8);
  }
  piVar5 = (int *)0x0;
  while( true ) {
    if (iStack_a4 == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c0a24:
    uVar11 = 0xaa;
    uVar3 = 0x165;
LAB_005c0870:
    piVar5 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,uVar11,s_cms_ess_c_00672aac,uVar3);
LAB_005c0888:
    if (puStack_ec != (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a977c)(puStack_ec,PTR_CMS_ReceiptRequest_it_006aa4f8);
    }
    (*(code *)PTR_ASN1_item_free_006a977c)(unaff_s4,PTR_CMS_Receipt_it_006aa4fc);
  }
  return piVar5;
}

