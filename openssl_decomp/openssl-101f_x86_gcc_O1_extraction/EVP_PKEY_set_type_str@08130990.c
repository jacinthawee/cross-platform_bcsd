
int EVP_PKEY_set_type_str(EVP_PKEY *pkey,char *str,int len)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_GS_OFFSET;
  ENGINE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
LAB_08130a20:
    if (str == (char *)0x0) {
      piVar2 = (int *)EVP_PKEY_asn1_find(&local_14,0);
    }
    else {
      piVar2 = (int *)EVP_PKEY_asn1_find_str(&local_14,str,len);
    }
    if (pkey == (EVP_PKEY *)0x0) {
      if (local_14 != (ENGINE *)0x0) {
        ENGINE_finish(local_14);
      }
      if (piVar2 == (int *)0x0) goto LAB_08130aa0;
    }
    else {
      if (piVar2 == (int *)0x0) {
LAB_08130aa0:
        ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
        iVar3 = 0;
        goto LAB_08130a61;
      }
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar2;
      pkey->engine = local_14;
      iVar3 = *piVar2;
      pkey->save_type = 0;
      pkey->type = iVar3;
    }
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0) goto LAB_081309ff;
LAB_08130a06:
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      goto LAB_08130a20;
    }
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar1 = *(code **)(pkey->ameth + 0x54), pcVar1 != (code *)0x0)) {
      (*pcVar1)(pkey);
      (pkey->pkey).ptr = (char *)0x0;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
    }
    if (pkey->save_type != 0) goto LAB_08130a20;
LAB_081309ff:
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_08130a06;
  }
  iVar3 = 1;
LAB_08130a61:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

