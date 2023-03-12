
PKCS12 * PKCS12_add_safes(stack_st_PKCS7 *safes,int p7_nid)

{
  PKCS12 *p12;
  int iVar1;
  
  if (p7_nid < 1) {
    p7_nid = 0x15;
  }
  p12 = PKCS12_init(p7_nid);
  if (p12 != (PKCS12 *)0x0) {
    iVar1 = PKCS12_pack_authsafes(p12,safes);
    if (iVar1 != 0) {
      return p12;
    }
    PKCS12_free(p12);
    return (PKCS12 *)0x0;
  }
  return (PKCS12 *)0x0;
}
