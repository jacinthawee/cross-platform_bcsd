
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_6c = (undefined4 *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  psVar2 = CMS_get0_SignerInfos(param_2);
  psVar3 = CMS_get0_SignerInfos(param_1);
  if ((psVar2 == (stack_st_CMS_SignerInfo *)0x0) || (psVar3 == (stack_st_CMS_SignerInfo *)0x0))
  goto LAB_005c0668;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar3);
  if (iVar4 == 1) {
    pAVar6 = CMS_get0_eContentType(param_1);
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pAVar6);
    if (iVar4 == 0xcc) {
      ppAVar7 = CMS_get0_content(param_1);
      if (ppAVar7 != (ASN1_OCTET_STRING **)0x0) {
        if (*ppAVar7 != (ASN1_OCTET_STRING *)0x0) {
          unaff_s4 = (*(code *)PTR_ASN1_item_unpack_006aa2f0)(*ppAVar7,PTR_CMS_Receipt_it_006aa4fc);
          if (unaff_s4 != 0) {
            iVar4 = 0;
            iVar11 = 0;
            while( true ) {
              iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
              if (iVar8 <= iVar11) break;
              iVar4 = (*(code *)PTR_sk_value_006a7f24)(psVar2,iVar11);
              iVar8 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                (*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(unaff_s4 + 0xc));
              if (iVar8 == 0) break;
              iVar11 = iVar11 + 1;
            }
            iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
            if (iVar11 == iVar8) {
              uVar9 = 0xa6;
              uVar5 = 0x120;
              goto LAB_005c0870;
            }
            uVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar3,0);
            uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xd8);
            piVar10 = (int *)(*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)
                                       (uVar5,uVar9,0xfffffffd,4);
            if (piVar10 == (int *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,0xa7,s_cms_ess_c_00672aac,0x12e);
              goto LAB_005c0888;
            }
            uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(**(undefined4 **)(iVar4 + 8));
            uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar5);
            iVar11 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
            if (iVar11 != 0) {
              iVar11 = (*(code *)PTR_ASN1_item_digest_006aa0d8)
                                 (PTR_CMS_Attributes_Verify_it_006aa4a4,iVar11,
                                  *(undefined4 *)(iVar4 + 0xc),auStack_64,&local_68);
              if (iVar11 != 0) {
                if (*piVar10 != local_68) {
                  uVar9 = 0xa3;
                  uVar5 = 0x13b;
                  goto LAB_005c0870;
                }
                iVar11 = (*(code *)PTR_memcmp_006aabd8)(auStack_64,piVar10[2]);
                if (iVar11 != 0) {
                  uVar9 = 0xa2;
                  uVar5 = 0x142;
                  goto LAB_005c0870;
                }
                uVar5 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x32);
                iVar11 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)
                                   (iVar4,uVar5,0xfffffffd,6);
                if (iVar11 == 0) {
                  uVar9 = 0xad;
                  uVar5 = 0x14d;
                  goto LAB_005c0870;
                }
                iVar11 = (*(code *)PTR_OBJ_cmp_006a9de4)(iVar11,*(undefined4 *)(unaff_s4 + 4));
                if (iVar11 != 0) {
                  uVar9 = 0xab;
                  uVar5 = 0x155;
                  goto LAB_005c0870;
                }
                iVar4 = CMS_get1_ReceiptRequest(iVar4,&local_6c);
                if (0 < iVar4) {
                  iVar4 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                    (*local_6c,*(undefined4 *)(unaff_s4 + 8));
                  if (iVar4 != 0) goto LAB_005c0a24;
                  piVar10 = (int *)0x1;
                  goto LAB_005c0888;
                }
                uVar9 = 0xa8;
                uVar5 = 0x15d;
                goto LAB_005c0870;
              }
            }
            uVar9 = 0xac;
            uVar5 = 0x134;
            goto LAB_005c0870;
          }
          uVar9 = 0xa9;
          uVar5 = 0x110;
          goto LAB_005c0654;
        }
      }
      uVar9 = 0x7f;
      uVar5 = 0x108;
    }
    else {
      uVar9 = 0xa5;
      uVar5 = 0x100;
    }
  }
  else {
    uVar9 = 0xa4;
    uVar5 = 0xf9;
  }
LAB_005c0654:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,uVar9,s_cms_ess_c_00672aac,uVar5);
LAB_005c0668:
  if (local_6c != (undefined4 *)0x0) {
    (*(code *)PTR_ASN1_item_free_006a977c)(local_6c,PTR_CMS_ReceiptRequest_it_006aa4f8);
  }
  piVar10 = (int *)0x0;
  while( true ) {
    if (local_24 == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c0a24:
    uVar9 = 0xaa;
    uVar5 = 0x165;
LAB_005c0870:
    piVar10 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa0,uVar9,s_cms_ess_c_00672aac,uVar5);
LAB_005c0888:
    if (local_6c != (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a977c)(local_6c,PTR_CMS_ReceiptRequest_it_006aa4f8);
    }
    (*(code *)PTR_ASN1_item_free_006a977c)(unaff_s4,PTR_CMS_Receipt_it_006aa4fc);
  }
  return piVar10;
}

