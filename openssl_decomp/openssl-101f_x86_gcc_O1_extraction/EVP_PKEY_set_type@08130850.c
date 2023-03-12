
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  int in_GS_OFFSET;
  ENGINE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    pEVar4 = EVP_PKEY_asn1_find(&local_14,type);
    if (local_14 != (ENGINE *)0x0) {
      ENGINE_finish(local_14);
    }
    if (pEVar4 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0813095b;
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (type == pkey->save_type) goto LAB_081308c1;
LAB_081308c8:
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar1 = *(code **)(pkey->ameth + 0x54), pcVar1 != (code *)0x0)) {
        (*pcVar1)(pkey);
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      if (type == pkey->save_type) {
LAB_081308c1:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_08130908;
        goto LAB_081308c8;
      }
    }
    piVar2 = (int *)EVP_PKEY_asn1_find(&local_14,type);
    if (piVar2 == (int *)0x0) {
LAB_0813095b:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      iVar3 = 0;
      goto LAB_0813090d;
    }
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar2;
    iVar3 = *piVar2;
    pkey->save_type = type;
    pkey->engine = local_14;
    pkey->type = iVar3;
  }
LAB_08130908:
  iVar3 = 1;
LAB_0813090d:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

