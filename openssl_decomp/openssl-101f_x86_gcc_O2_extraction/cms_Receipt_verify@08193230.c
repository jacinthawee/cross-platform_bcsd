
size_t * cms_Receipt_verify(CMS_ContentInfo *param_1,CMS_ContentInfo *param_2)

{
  _STACK *p_Var1;
  _STACK *p_Var2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_OCTET_STRING **ppAVar5;
  ASN1_VALUE *val;
  int iVar6;
  CMS_SignerInfo *si;
  char *name;
  EVP_MD *type;
  size_t *psVar7;
  int in_GS_OFFSET;
  CMS_SignerInfo *local_70;
  ASN1_STRING **local_68;
  size_t local_64;
  uchar local_60 [64];
  int local_20;
  
  local_68 = (ASN1_STRING **)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p_Var1 = (_STACK *)CMS_get0_SignerInfos(param_2);
  p_Var2 = (_STACK *)CMS_get0_SignerInfos(param_1);
  if ((p_Var1 != (_STACK *)0x0) && (p_Var2 != (_STACK *)0x0)) {
    iVar3 = sk_num(p_Var2);
    if (iVar3 == 1) {
      pAVar4 = CMS_get0_eContentType(param_1);
      iVar3 = OBJ_obj2nid(pAVar4);
      if (iVar3 == 0xcc) {
        ppAVar5 = CMS_get0_content(param_1);
        if ((ppAVar5 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar5 == (ASN1_STRING *)0x0)) {
          ERR_put_error(0x2e,0xa0,0x7f,"cms_ess.c",0x108);
        }
        else {
          val = (ASN1_VALUE *)ASN1_item_unpack(*ppAVar5,(ASN1_ITEM *)CMS_Receipt_it);
          if (val != (ASN1_VALUE *)0x0) {
            local_70 = (CMS_SignerInfo *)0x0;
            iVar3 = 0;
            while( true ) {
              iVar6 = sk_num(p_Var1);
              if (iVar6 <= iVar3) break;
              local_70 = (CMS_SignerInfo *)sk_value(p_Var1,iVar3);
              iVar6 = ASN1_STRING_cmp(*(ASN1_STRING **)(local_70 + 0x14),
                                      *(ASN1_STRING **)(val + 0xc));
              if (iVar6 == 0) break;
              iVar3 = iVar3 + 1;
            }
            iVar6 = sk_num(p_Var1);
            if (iVar3 == iVar6) {
              iVar6 = 0x120;
              iVar3 = 0xa6;
LAB_0819345e:
              psVar7 = (size_t *)0x0;
              ERR_put_error(0x2e,0xa0,iVar3,"cms_ess.c",iVar6);
            }
            else {
              si = (CMS_SignerInfo *)sk_value(p_Var2,0);
              pAVar4 = OBJ_nid2obj(0xd8);
              psVar7 = (size_t *)CMS_signed_get0_data_by_OBJ(si,pAVar4,-3,4);
              if (psVar7 != (size_t *)0x0) {
                iVar3 = OBJ_obj2nid(**(ASN1_OBJECT ***)(local_70 + 8));
                name = OBJ_nid2sn(iVar3);
                type = EVP_get_digestbyname(name);
                if (type != (EVP_MD *)0x0) {
                  iVar3 = ASN1_item_digest((ASN1_ITEM *)CMS_Attributes_Verify_it,type,
                                           *(void **)(local_70 + 0xc),local_60,&local_64);
                  if (iVar3 != 0) {
                    if (*psVar7 == local_64) {
                      iVar3 = memcmp(local_60,(void *)psVar7[2],*psVar7);
                      if (iVar3 == 0) {
                        pAVar4 = OBJ_nid2obj(0x32);
                        pAVar4 = (ASN1_OBJECT *)CMS_signed_get0_data_by_OBJ(local_70,pAVar4,-3,6);
                        if (pAVar4 == (ASN1_OBJECT *)0x0) {
                          iVar6 = 0x14d;
                          iVar3 = 0xad;
                        }
                        else {
                          iVar3 = OBJ_cmp(pAVar4,*(ASN1_OBJECT **)(val + 4));
                          if (iVar3 == 0) {
                            iVar3 = CMS_get1_ReceiptRequest(local_70,&local_68,psVar7,psVar7);
                            if (iVar3 < 1) {
                              iVar6 = 0x15d;
                              iVar3 = 0xa8;
                            }
                            else {
                              psVar7 = (size_t *)0x1;
                              iVar3 = ASN1_STRING_cmp(*local_68,*(ASN1_STRING **)(val + 8));
                              if (iVar3 == 0) goto LAB_0819346f;
                              iVar6 = 0x165;
                              iVar3 = 0xaa;
                            }
                          }
                          else {
                            iVar6 = 0x155;
                            iVar3 = 0xab;
                          }
                        }
                      }
                      else {
                        iVar6 = 0x142;
                        iVar3 = 0xa2;
                      }
                    }
                    else {
                      iVar6 = 0x13b;
                      iVar3 = 0xa3;
                    }
                    goto LAB_0819345e;
                  }
                }
                iVar6 = 0x134;
                iVar3 = 0xac;
                goto LAB_0819345e;
              }
              ERR_put_error(0x2e,0xa0,0xa7,"cms_ess.c",0x12e);
            }
LAB_0819346f:
            if (local_68 != (ASN1_STRING **)0x0) {
              ASN1_item_free((ASN1_VALUE *)local_68,(ASN1_ITEM *)CMS_ReceiptRequest_it);
            }
            ASN1_item_free(val,(ASN1_ITEM *)CMS_Receipt_it);
            goto LAB_08193290;
          }
          ERR_put_error(0x2e,0xa0,0xa9,"cms_ess.c",0x110);
        }
      }
      else {
        ERR_put_error(0x2e,0xa0,0xa5,"cms_ess.c",0x100);
      }
    }
    else {
      ERR_put_error(0x2e,0xa0,0xa4,"cms_ess.c",0xf9);
    }
  }
  psVar7 = (size_t *)0x0;
  if (local_68 != (ASN1_STRING **)0x0) {
    ASN1_item_free((ASN1_VALUE *)local_68,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  }
LAB_08193290:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

