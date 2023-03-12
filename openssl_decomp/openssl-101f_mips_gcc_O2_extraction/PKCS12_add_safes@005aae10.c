
PKCS12 * PKCS12_add_safes(stack_st_PKCS7 *safes,int p7_nid)

{
  PKCS12 *p12;
  int iVar1;
  
  iVar1 = 0x15;
  if (0 < p7_nid) {
    iVar1 = p7_nid;
  }
  p12 = PKCS12_init(iVar1);
  if (p12 == (PKCS12 *)0x0) {
    p12 = (PKCS12 *)0x0;
  }
  else {
    iVar1 = PKCS12_pack_authsafes(p12,safes);
    if (iVar1 == 0) {
      PKCS12_free(p12);
      p12 = (PKCS12 *)0x0;
    }
  }
  return p12;
}

