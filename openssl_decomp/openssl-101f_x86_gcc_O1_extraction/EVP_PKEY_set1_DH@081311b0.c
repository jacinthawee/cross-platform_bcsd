
int EVP_PKEY_set1_DH(EVP_PKEY *pkey,dh_st *key)

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
    pEVar4 = EVP_PKEY_asn1_find(&local_14,0x1c);
    if (local_14 != (ENGINE *)0x0) {
      ENGINE_finish(local_14);
    }
    if (pEVar4 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_081312ec;
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0x1c) goto LAB_08131223;
LAB_0813122a:
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
      if (pkey->save_type == 0x1c) {
LAB_08131223:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_08131273;
        goto LAB_0813122a;
      }
    }
    piVar3 = (int *)EVP_PKEY_asn1_find(&local_14,0x1c);
    if (piVar3 == (int *)0x0) {
LAB_081312ec:
      uVar5 = 0;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      goto LAB_0813128b;
    }
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
    iVar2 = *piVar3;
    pkey->save_type = 0x1c;
    pkey->engine = local_14;
    pkey->type = iVar2;
  }
LAB_08131273:
  (pkey->pkey).dh = key;
  uVar5 = (uint)(key != (dh_st *)0x0);
  if (key != (dh_st *)0x0) {
    DH_up_ref(key);
  }
LAB_0813128b:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}
