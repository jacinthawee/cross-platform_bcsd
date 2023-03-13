
int CMS_RecipientInfo_set0_password(CMS_RecipientInfo *ri,uchar *pass,ssize_t passlen)

{
  int iVar1;
  
  if (*(int *)ri == 3) {
    iVar1 = *(int *)(ri + 4);
    *(uchar **)(iVar1 + 0x10) = pass;
    if ((pass != (uchar *)0x0) && (passlen < 0)) {
      passlen = strlen((char *)pass);
    }
    *(ssize_t *)(iVar1 + 0x14) = passlen;
    return 1;
  }
  ERR_put_error(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
  return 0;
}

