
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find_str(ENGINE **pe,char *str,int len)

{
  char *__s;
  EVP_PKEY_ASN1_METHOD *e;
  int iVar1;
  size_t sVar2;
  int iVar3;
  int in_GS_OFFSET;
  ENGINE *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (len == -1) {
    len = strlen(str);
  }
  if (pe != (ENGINE **)0x0) {
    e = ENGINE_pkey_asn1_find_str(&local_24,str,len);
    if (e != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar1 = ENGINE_init((ENGINE *)e);
      if (iVar1 == 0) {
        e = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      ENGINE_free(local_24);
      *pe = local_24;
      goto LAB_0814c60c;
    }
    *pe = (ENGINE *)0x0;
  }
  iVar1 = 0;
  while( true ) {
    iVar3 = 0xb;
    if (app_methods != (_STACK *)0x0) {
      iVar3 = sk_num(app_methods);
      iVar3 = iVar3 + 0xb;
    }
    if (iVar3 <= iVar1) break;
    if (iVar1 < 0xb) {
      e = *(EVP_PKEY_ASN1_METHOD **)(standard_methods + iVar1 * 4);
    }
    else {
      e = (EVP_PKEY_ASN1_METHOD *)sk_value(app_methods,iVar1 + -0xb);
    }
    if (((byte)e[8] & 1) == 0) {
      __s = *(char **)(e + 0xc);
      sVar2 = strlen(__s);
      if ((len == sVar2) && (iVar3 = strncasecmp(__s,str,len), iVar3 == 0)) goto LAB_0814c60c;
    }
    iVar1 = iVar1 + 1;
  }
  e = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_0814c60c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return e;
}

