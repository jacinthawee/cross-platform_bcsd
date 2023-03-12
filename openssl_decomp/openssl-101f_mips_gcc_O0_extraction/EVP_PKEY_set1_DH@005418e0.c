
int EVP_PKEY_set1_DH(EVP_PKEY *pkey,dh_st *key)

{
  undefined *puVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  ENGINE *local_20;
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_20 = (ENGINE *)0x0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pkey == (EVP_PKEY *)0x0) {
    iVar4 = (*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_20,0x1c);
    if (local_20 != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    if (iVar4 == 0) goto LAB_00541a70;
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0x1c) {
        pEVar2 = pkey->ameth;
        goto LAB_00541988;
      }
LAB_00541990:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar6 = *(code **)(pkey->ameth + 0x54), pcVar6 != (code *)0x0)) {
        (*pcVar6)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
      if (pkey->save_type == 0x1c) {
        pEVar2 = pkey->ameth;
LAB_00541988:
        if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_005419e0;
        goto LAB_00541990;
      }
    }
    piVar3 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_20,0x1c);
    if (piVar3 == (int *)0x0) {
LAB_00541a70:
      uVar5 = 0;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      goto LAB_005419fc;
    }
    iVar4 = *piVar3;
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
    pkey->save_type = 0x1c;
    pkey->type = iVar4;
    pkey->engine = local_20;
  }
LAB_005419e0:
  (pkey->pkey).dh = key;
  uVar5 = (uint)(key != (dh_st *)0x0);
  if (key != (dh_st *)0x0) {
    (*(code *)PTR_DH_up_ref_006a9bfc)(key);
  }
LAB_005419fc:
  if (local_1c == *(int **)puVar1) {
    return uVar5;
  }
  piVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*piVar3 != 0x1c) {
    ERR_put_error(6,0x77,0x80,"p_lib.c",0x160);
    return 0;
  }
  (*(code *)PTR_DH_up_ref_006a9bfc)(piVar3[5]);
  return piVar3[5];
}

