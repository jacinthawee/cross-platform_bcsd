
void cms_Receipt_verify(CMS_ContentInfo *param_1,CMS_ContentInfo *param_2)

{
  _STACK *p_Var1;
  _STACK *p_Var2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_OCTET_STRING **ppAVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_OBJECT *pAVar7;
  CMS_SignerInfo *si;
  ASN1_OBJECT *pAVar8;
  char *name;
  EVP_MD *type;
  ASN1_STRING **local_6c;
  char *local_68;
  uchar auStack_64 [64];
  int local_24;
  
  local_6c = (ASN1_STRING **)0x0;
  local_24 = __stack_chk_guard;
  p_Var1 = (_STACK *)CMS_get0_SignerInfos(param_2);
  p_Var2 = (_STACK *)CMS_get0_SignerInfos(param_1);
  pAVar8 = (ASN1_OBJECT *)(uint)(p_Var1 == (_STACK *)0x0 || p_Var2 == (_STACK *)0x0);
  if (p_Var1 == (_STACK *)0x0 || p_Var2 == (_STACK *)0x0) {
    pAVar6 = (ASN1_OBJECT *)0x0;
    pAVar8 = (ASN1_OBJECT *)0x0;
  }
  else {
    iVar3 = sk_num(p_Var2);
    pAVar6 = pAVar8;
    if (iVar3 == 1) {
      pAVar4 = CMS_get0_eContentType(param_1);
      iVar3 = OBJ_obj2nid(pAVar4);
      if (iVar3 == 0xcc) {
        ppAVar5 = CMS_get0_content(param_1);
        if ((ppAVar5 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar5 == (ASN1_STRING *)0x0)) {
          pAVar6 = (ASN1_OBJECT *)0x0;
          ERR_put_error(0x2e,0xa0,0x7f,"cms_ess.c",0xfe);
          pAVar8 = (ASN1_OBJECT *)0x0;
        }
        else {
          pAVar6 = (ASN1_OBJECT *)ASN1_item_unpack(*ppAVar5,(ASN1_ITEM *)&CMS_Receipt_it);
          pAVar4 = pAVar8;
          if (pAVar6 == (ASN1_OBJECT *)0x0) {
            ERR_put_error(0x2e,0xa0,0xa9,"cms_ess.c",0x105);
            pAVar8 = pAVar6;
          }
          else {
            for (; iVar3 = sk_num(p_Var1), (int)pAVar8 < iVar3;
                pAVar8 = (ASN1_OBJECT *)((int)&pAVar8->sn + 1)) {
              pAVar4 = (ASN1_OBJECT *)sk_value(p_Var1,(int)pAVar8);
              iVar3 = ASN1_STRING_cmp((ASN1_STRING *)pAVar4->flags,(ASN1_STRING *)pAVar6->length);
              if (iVar3 == 0) break;
            }
            pAVar7 = (ASN1_OBJECT *)sk_num(p_Var1);
            if (pAVar8 == pAVar7) {
              ERR_put_error(0x2e,0xa0,0xa6,"cms_ess.c",0x112);
              pAVar8 = (ASN1_OBJECT *)0x0;
            }
            else {
              si = (CMS_SignerInfo *)sk_value(p_Var2,0);
              pAVar8 = OBJ_nid2obj(0xd8);
              pAVar8 = (ASN1_OBJECT *)CMS_signed_get0_data_by_OBJ(si,pAVar8,-3,4);
              if (pAVar8 == (ASN1_OBJECT *)0x0) {
                ERR_put_error(0x2e,0xa0,0xa7,"cms_ess.c",0x120);
              }
              else {
                iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)pAVar4->nid);
                name = OBJ_nid2sn(iVar3);
                type = EVP_get_digestbyname(name);
                if ((type == (EVP_MD *)0x0) ||
                   (iVar3 = ASN1_item_digest((ASN1_ITEM *)CMS_Attributes_Verify_it,type,
                                             (void *)pAVar4->length,auStack_64,(uint *)&local_68),
                   iVar3 == 0)) {
                  ERR_put_error(0x2e,0xa0,0xac,"cms_ess.c",0x125);
                  pAVar8 = (ASN1_OBJECT *)0x0;
                }
                else if (pAVar8->sn == local_68) {
                  pAVar7 = (ASN1_OBJECT *)memcmp(auStack_64,(void *)pAVar8->nid,(size_t)pAVar8->sn);
                  if (pAVar7 == (ASN1_OBJECT *)0x0) {
                    pAVar8 = OBJ_nid2obj(0x32);
                    pAVar8 = (ASN1_OBJECT *)
                             CMS_signed_get0_data_by_OBJ((CMS_SignerInfo *)pAVar4,pAVar8,-3,6);
                    if (pAVar8 == (ASN1_OBJECT *)0x0) {
                      ERR_put_error(0x2e,0xa0,0xad,"cms_ess.c",0x13a);
                    }
                    else {
                      pAVar8 = (ASN1_OBJECT *)OBJ_cmp(pAVar8,(ASN1_OBJECT *)pAVar6->ln);
                      if (pAVar8 == (ASN1_OBJECT *)0x0) {
                        iVar3 = CMS_get1_ReceiptRequest(pAVar4,&local_6c);
                        if (iVar3 < 1) {
                          ERR_put_error(0x2e,0xa0,0xa8,"cms_ess.c",0x148);
                        }
                        else {
                          iVar3 = ASN1_STRING_cmp(*local_6c,(ASN1_STRING *)pAVar6->nid);
                          if (iVar3 == 0) {
                            pAVar8 = (ASN1_OBJECT *)0x1;
                          }
                          else {
                            ERR_put_error(0x2e,0xa0,0xaa,"cms_ess.c",0x14e);
                            pAVar8 = (ASN1_OBJECT *)0x0;
                          }
                        }
                      }
                      else {
                        ERR_put_error(0x2e,0xa0,0xab,"cms_ess.c",0x141);
                        pAVar8 = pAVar7;
                      }
                    }
                  }
                  else {
                    ERR_put_error(0x2e,0xa0,0xa2,"cms_ess.c",0x130);
                    pAVar8 = (ASN1_OBJECT *)0x0;
                  }
                }
                else {
                  ERR_put_error(0x2e,0xa0,0xa3,"cms_ess.c",0x12a);
                  pAVar8 = (ASN1_OBJECT *)0x0;
                }
              }
            }
          }
        }
      }
      else {
        ERR_put_error(0x2e,0xa0,0xa5,"cms_ess.c",0xf7);
      }
    }
    else {
      ERR_put_error(0x2e,0xa0,0xa4,"cms_ess.c",0xf1);
    }
  }
  if (local_6c != (ASN1_STRING **)0x0) {
    ASN1_item_free((ASN1_VALUE *)local_6c,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  }
  if (pAVar6 != (ASN1_OBJECT *)0x0) {
    ASN1_item_free((ASN1_VALUE *)pAVar6,(ASN1_ITEM *)&CMS_Receipt_it);
  }
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pAVar8);
}

