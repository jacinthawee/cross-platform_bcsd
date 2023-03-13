
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_GS_OFFSET;
  ENGINE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = 0;
  if (pkey == (EVP_PKEY *)0x0) goto LAB_0812e41f;
  local_14 = (ENGINE *)0x0;
  if ((pkey->pkey).ptr == (char *)0x0) {
    if (type == pkey->save_type) goto LAB_0812e40e;
LAB_0812e445:
    if (pkey->engine != (ENGINE *)0x0) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
    }
LAB_0812e45e:
    piVar4 = (int *)EVP_PKEY_asn1_find(&local_14,type);
    if (piVar4 == (int *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      uVar3 = 0;
      goto LAB_0812e41f;
    }
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar4;
    iVar2 = *piVar4;
    pkey->save_type = type;
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
    if (type != pkey->save_type) goto LAB_0812e45e;
LAB_0812e40e:
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0812e445;
  }
  (pkey->pkey).ptr = (char *)key;
  uVar3 = (uint)(key != (void *)0x0);
LAB_0812e41f:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

