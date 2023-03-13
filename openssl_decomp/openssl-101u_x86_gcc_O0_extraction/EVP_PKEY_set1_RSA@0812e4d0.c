
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey,rsa_st *key)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_GS_OFFSET;
  ENGINE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pkey != (EVP_PKEY *)0x0) {
    local_14 = (ENGINE *)0x0;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 6) goto LAB_0812e546;
LAB_0812e5b6:
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
LAB_0812e5cf:
      piVar3 = (int *)EVP_PKEY_asn1_find(&local_14,6);
      if (piVar3 == (int *)0x0) {
        ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
        goto LAB_0812e598;
      }
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
      iVar2 = *piVar3;
      pkey->save_type = 6;
      pkey->engine = local_14;
      pkey->type = iVar2;
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
      if (pkey->save_type != 6) goto LAB_0812e5cf;
LAB_0812e546:
      if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0812e5b6;
    }
    (pkey->pkey).rsa = key;
    if (key != (rsa_st *)0x0) {
      RSA_up_ref(key);
      iVar2 = 1;
      goto LAB_0812e59a;
    }
  }
LAB_0812e598:
  iVar2 = 0;
LAB_0812e59a:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

