
int CMS_decrypt_set1_key(CMS_ContentInfo *cms,uchar *key,size_t keylen,uchar *id,size_t idlen)

{
  _STACK *p_Var1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  
  iVar4 = 0;
  p_Var1 = (_STACK *)CMS_get0_RecipientInfos(cms);
  if (id == (uchar *)0x0) {
    for (; iVar2 = sk_num(p_Var1), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      if (iVar2 == 2) {
        CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
        iVar2 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
        if (0 < iVar2) {
          return 1;
        }
        ERR_clear_error();
      }
    }
  }
  else {
    for (; iVar2 = sk_num(p_Var1), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      if ((iVar2 == 2) && (iVar2 = CMS_RecipientInfo_kekri_id_cmp(pCVar3,id,idlen), iVar2 == 0)) {
        CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
        iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
        if (0 < iVar4) {
          return 1;
        }
        ERR_put_error(0x2e,0x71,0x70,"cms_smime.c",0x28a);
        return 0;
      }
    }
  }
  ERR_put_error(0x2e,0x71,0x84,"cms_smime.c",0x291);
  return 0;
}

