
int CMS_decrypt_set1_password(CMS_ContentInfo *cms,uchar *pass,ssize_t passlen)

{
  _STACK *p_Var1;
  int iVar2;
  CMS_RecipientInfo *ri;
  int iVar3;
  
  iVar3 = 0;
  p_Var1 = (_STACK *)CMS_get0_RecipientInfos(cms);
  do {
    iVar2 = sk_num(p_Var1);
    if (iVar2 <= iVar3) {
      ERR_put_error(0x2e,0xa6,0x84,"cms_smime.c",0x2d7);
      return 0;
    }
    ri = (CMS_RecipientInfo *)sk_value(p_Var1,iVar3);
    iVar2 = CMS_RecipientInfo_type(ri);
    if (iVar2 == 3) {
      CMS_RecipientInfo_set0_password(ri,pass,passlen);
      iVar2 = CMS_RecipientInfo_decrypt(cms,ri);
      CMS_RecipientInfo_set0_password(ri,(uchar *)0x0,0);
      if (0 < iVar2) {
        return 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

