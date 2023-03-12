
int CMS_RecipientInfo_kekri_id_cmp(CMS_RecipientInfo *ri,uchar *id,size_t idlen)

{
  int iVar1;
  ASN1_STRING local_18;
  
  if (*(int *)ri == 2) {
    local_18.type = 4;
    local_18.flags = 0;
    local_18.length = idlen;
    local_18.data = id;
    iVar1 = ASN1_OCTET_STRING_cmp(&local_18,**(ASN1_STRING ***)(*(int *)(ri + 4) + 4));
  }
  else {
    ERR_put_error(0x2e,0x8a,0x7b,"cms_env.c",0x1a5);
    iVar1 = -2;
  }
  return iVar1;
}

