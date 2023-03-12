
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth_str(ENGINE *e,char *str,int len)

{
  code *pcVar1;
  char *__s;
  int iVar2;
  size_t sVar3;
  int iVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  int iVar6;
  int in_GS_OFFSET;
  int local_28;
  EVP_PKEY_ASN1_METHOD *local_24;
  int local_20;
  
  pcVar1 = *(code **)(e + 0x30);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pcVar1 != (code *)0x0) {
    if (len == -1) {
      len = strlen(str);
    }
    iVar2 = (*pcVar1)(e,0,&local_28,0);
    if (0 < iVar2) {
      iVar6 = 0;
      do {
        (**(code **)(e + 0x30))(e,&local_24,0,*(undefined4 *)(local_28 + iVar6 * 4));
        pEVar5 = local_24;
        __s = *(char **)(local_24 + 0xc);
        sVar3 = strlen(__s);
        if ((len == sVar3) && (iVar4 = strncasecmp(__s,str,len), iVar4 == 0)) goto LAB_081160b2;
        iVar6 = iVar6 + 1;
      } while (iVar2 != iVar6);
    }
  }
  pEVar5 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_081160b2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pEVar5;
}

