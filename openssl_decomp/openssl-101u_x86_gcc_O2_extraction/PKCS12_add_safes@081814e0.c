
PKCS12 * PKCS12_add_safes(stack_st_PKCS7 *safes,int p7_nid)

{
  PKCS12 *p12;
  int iVar1;
  PKCS12 *pPVar2;
  
  if (p7_nid < 1) {
    p7_nid = 0x15;
  }
  p12 = PKCS12_init(p7_nid);
  if (p12 == (PKCS12 *)0x0) {
    pPVar2 = (PKCS12 *)0x0;
  }
  else {
    iVar1 = PKCS12_pack_authsafes(p12,safes);
    pPVar2 = p12;
    if (iVar1 == 0) {
      pPVar2 = (PKCS12 *)0x0;
      PKCS12_free(p12);
    }
  }
  return pPVar2;
}

