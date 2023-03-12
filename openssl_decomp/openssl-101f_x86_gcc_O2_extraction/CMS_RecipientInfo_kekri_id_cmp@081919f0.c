
int CMS_RecipientInfo_kekri_id_cmp(CMS_RecipientInfo *ri,uchar *id,size_t idlen)

{
  int iVar1;
  int in_GS_OFFSET;
  ASN1_STRING local_20;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)ri == 2) {
    local_20.data = id;
    local_20.type = 4;
    local_20.flags = 0;
    local_20.length = idlen;
    iVar1 = ASN1_OCTET_STRING_cmp(&local_20,**(ASN1_STRING ***)(*(int *)(ri + 4) + 4));
  }
  else {
    ERR_put_error(0x2e,0x8a,0x7b,"cms_env.c",0x1c0);
    iVar1 = -2;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

