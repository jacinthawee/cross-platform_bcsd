
int * cms_Receipt_verify(CMS_ContentInfo *param_1,CMS_ContentInfo *param_2)

{
  undefined *puVar1;
  stack_st_CMS_SignerInfo *psVar2;
  stack_st_CMS_SignerInfo *psVar3;
  int iVar4;
  undefined4 uVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_OCTET_STRING **ppAVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int unaff_s4;
  undefined4 *local_6c;
  int local_68;
  undefined auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_6c = (undefined4 *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar2 = CMS_get0_SignerInfos(param_2);
  psVar3 = CMS_get0_SignerInfos(param_1);
  if ((psVar2 == (stack_st_CMS_SignerInfo *)0x0) || (psVar3 == (stack_st_CMS_SignerInfo *)0x0))
  goto LAB_005bddd8;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar3);
  if (iVar4 == 1) {
    pAVar6 = CMS_get0_eContentType(param_1);
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar6);
    if (iVar4 == 0xcc) {
      ppAVar7 = CMS_get0_content(param_1);
      if (ppAVar7 != (ASN1_OCTET_STRING **)0x0) {
        if (*ppAVar7 != (ASN1_OCTET_STRING *)0x0) {
          unaff_s4 = (*(code *)PTR_ASN1_item_unpack_006a91d8)(*ppAVar7,PTR_CMS_Receipt_it_006a93f0);
          if (unaff_s4 != 0) {
            iVar4 = 0;
            iVar11 = 0;
            while( true ) {
              iVar8 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
              if (iVar8 <= iVar11) break;
              iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar2,iVar11);
              iVar8 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                                (*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(unaff_s4 + 0xc));
              if (iVar8 == 0) break;
              iVar11 = iVar11 + 1;
            }
            iVar8 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
            if (iVar11 == iVar8) {
              uVar9 = 0xa6;
              uVar5 = 0x112;
              goto LAB_005bdfe0;
            }
            uVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar3,0);
            uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xd8);
            piVar10 = (int *)(*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)
                                       (uVar5,uVar9,0xfffffffd,4);
            if (piVar10 == (int *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,0xa7,s_cms_ess_c_006721bc,0x120);
              goto LAB_005bdff8;
            }
            uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar4 + 8));
            uVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar5);
            iVar11 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar5);
            if (iVar11 != 0) {
              iVar11 = (*(code *)PTR_ASN1_item_digest_006a8fc0)
                                 (PTR_CMS_Attributes_Verify_it_006a9398,iVar11,
                                  *(undefined4 *)(iVar4 + 0xc),auStack_64,&local_68);
              if (iVar11 != 0) {
                if (*piVar10 != local_68) {
                  uVar9 = 0xa3;
                  uVar5 = 0x12a;
                  goto LAB_005bdfe0;
                }
                iVar11 = (*(code *)PTR_memcmp_006a9ad0)(auStack_64,piVar10[2]);
                if (iVar11 != 0) {
                  uVar9 = 0xa2;
                  uVar5 = 0x130;
                  goto LAB_005bdfe0;
                }
                uVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x32);
                iVar11 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)
                                   (iVar4,uVar5,0xfffffffd,6);
                if (iVar11 == 0) {
                  uVar9 = 0xad;
                  uVar5 = 0x13a;
                  goto LAB_005bdfe0;
                }
                iVar11 = (*(code *)PTR_OBJ_cmp_006a8cc4)(iVar11,*(undefined4 *)(unaff_s4 + 4));
                if (iVar11 != 0) {
                  uVar9 = 0xab;
                  uVar5 = 0x141;
                  goto LAB_005bdfe0;
                }
                iVar4 = CMS_get1_ReceiptRequest(iVar4,&local_6c);
                if (0 < iVar4) {
                  iVar4 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                                    (*local_6c,*(undefined4 *)(unaff_s4 + 8));
                  if (iVar4 != 0) goto LAB_005be194;
                  piVar10 = (int *)0x1;
                  goto LAB_005bdff8;
                }
                uVar9 = 0xa8;
                uVar5 = 0x148;
                goto LAB_005bdfe0;
              }
            }
            uVar9 = 0xac;
            uVar5 = 0x125;
            goto LAB_005bdfe0;
          }
          uVar9 = 0xa9;
          uVar5 = 0x105;
          goto LAB_005bddc4;
        }
      }
      uVar9 = 0x7f;
      uVar5 = 0xfe;
    }
    else {
      uVar9 = 0xa5;
      uVar5 = 0xf7;
    }
  }
  else {
    uVar9 = 0xa4;
    uVar5 = 0xf1;
  }
LAB_005bddc4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,uVar9,s_cms_ess_c_006721bc,uVar5);
LAB_005bddd8:
  if (local_6c != (undefined4 *)0x0) {
    (*(code *)PTR_ASN1_item_free_006a8658)(local_6c,PTR_CMS_ReceiptRequest_it_006a93ec);
  }
  piVar10 = (int *)0x0;
  while( true ) {
    if (local_24 == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005be194:
    uVar9 = 0xaa;
    uVar5 = 0x14e;
LAB_005bdfe0:
    piVar10 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa0,uVar9,s_cms_ess_c_006721bc,uVar5);
LAB_005bdff8:
    if (local_6c != (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a8658)(local_6c,PTR_CMS_ReceiptRequest_it_006a93ec);
    }
    (*(code *)PTR_ASN1_item_free_006a8658)(unaff_s4,PTR_CMS_Receipt_it_006a93f0);
  }
  return piVar10;
}

