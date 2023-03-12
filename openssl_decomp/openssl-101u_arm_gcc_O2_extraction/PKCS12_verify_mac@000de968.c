
int PKCS12_verify_mac(PKCS12 *p12,char *pass,int passlen)

{
  int iVar1;
  uint uVar2;
  size_t len;
  ASN1_OCTET_STRING *pAVar3;
  PKCS12_MAC_DATA *pPVar4;
  size_t local_60;
  undefined auStack_5c [64];
  int local_1c;
  
  pPVar4 = p12->mac;
  local_1c = __stack_chk_guard;
  if (pPVar4 == (PKCS12_MAC_DATA *)0x0) {
    ERR_put_error(0x23,0x7e,0x6c,"p12_mutl.c",0x77);
  }
  else {
    iVar1 = OBJ_obj2nid(p12->authsafes->type);
    if (iVar1 == 0x15) {
      iVar1 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_5c,&local_60);
      if (iVar1 != 0) {
        pAVar3 = p12->mac->dinfo->digest;
        len = pAVar3->length;
        if (len == local_60) {
          iVar1 = CRYPTO_memcmp(auStack_5c,pAVar3->data,len);
          uVar2 = count_leading_zeroes(iVar1);
          pPVar4 = (PKCS12_MAC_DATA *)(uVar2 >> 5);
        }
        else {
          pPVar4 = (PKCS12_MAC_DATA *)0x0;
        }
        goto LAB_000de9b6;
      }
    }
    else {
      ERR_put_error(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
    }
    ERR_put_error(0x23,0x7e,0x6d,"p12_mutl.c",0x7b);
    pPVar4 = (PKCS12_MAC_DATA *)0x0;
  }
LAB_000de9b6:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pPVar4;
}

