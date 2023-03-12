
int CMS_decrypt_set1_key(CMS_ContentInfo *cms,uchar *key,size_t keylen,uchar *id,size_t idlen)

{
  _STACK *p_Var1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  int iVar5;
  
  p_Var1 = (_STACK *)CMS_get0_RecipientInfos(cms);
  if (id == (uchar *)0x0) {
    for (; iVar4 = sk_num(p_Var1), (int)id < iVar4; id = id + 1) {
      pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,(int)id);
      iVar4 = CMS_RecipientInfo_type(pCVar3);
      if (iVar4 == 2) {
        CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
        iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
        if (0 < iVar4) goto LAB_000e6b2c;
        ERR_clear_error();
      }
    }
LAB_000e6b08:
    iVar4 = 0;
    ERR_put_error(0x2e,0x71,0x84,"cms_smime.c",0x2bf);
  }
  else {
    iVar4 = 0;
    do {
      iVar2 = sk_num(p_Var1);
      iVar5 = iVar4 + 1;
      if (iVar2 <= iVar4) goto LAB_000e6b08;
      pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      iVar4 = iVar5;
    } while ((iVar2 != 2) || (iVar2 = CMS_RecipientInfo_kekri_id_cmp(pCVar3,id,idlen), iVar2 != 0));
    CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
    iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
    CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
    if (iVar4 < 1) {
      ERR_put_error(0x2e,0x71,0x70,"cms_smime.c",0x2b8);
      return 0;
    }
LAB_000e6b2c:
    iVar4 = 1;
  }
  return iVar4;
}

