
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  uint uVar5;
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
    if (pEVar4 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_08130c0b;
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (type == pkey->save_type) goto LAB_08130b66;
LAB_08130b6d:
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
LAB_08130b66:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_08130bad;
        goto LAB_08130b6d;
      }
    }
    piVar3 = (int *)EVP_PKEY_asn1_find(&local_14,type);
    if (piVar3 == (int *)0x0) {
LAB_08130c0b:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      uVar5 = 0;
      goto LAB_08130bb7;
    }
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
    iVar2 = *piVar3;
    pkey->save_type = type;
    pkey->engine = local_14;
    pkey->type = iVar2;
  }
LAB_08130bad:
  (pkey->pkey).ptr = (char *)key;
  uVar5 = (uint)(key != (void *)0x0);
LAB_08130bb7:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

