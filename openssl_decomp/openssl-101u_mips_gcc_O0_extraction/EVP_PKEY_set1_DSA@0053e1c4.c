
int EVP_PKEY_set1_DSA(EVP_PKEY *pkey,dsa_st *key)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  ENGINE *local_18;
  int *local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pkey != (EVP_PKEY *)0x0) {
    local_18 = (ENGINE *)0x0;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0x74) goto LAB_0053e25c;
LAB_0053e2e4:
      if (pkey->engine == (ENGINE *)0x0) {
LAB_0053e340:
        piVar4 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18,0x74);
      }
      else {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        puVar1 = PTR_EVP_PKEY_asn1_find_006a6fd4;
        pkey->engine = (ENGINE *)0x0;
        piVar4 = (int *)(*(code *)puVar1)(&local_18,0x74);
      }
      if (piVar4 == (int *)0x0) {
        ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
        goto LAB_0053e2ac;
      }
      iVar3 = *piVar4;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar4;
      pkey->save_type = 0x74;
      pkey->type = iVar3;
      pkey->engine = local_18;
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar5 = *(code **)(pkey->ameth + 0x54), pcVar5 != (code *)0x0)) {
        (*pcVar5)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pkey->engine = (ENGINE *)0x0;
      }
      if (pkey->save_type != 0x74) goto LAB_0053e340;
LAB_0053e25c:
      if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0053e2e4;
    }
    (pkey->pkey).dsa = key;
    if (key != (dsa_st *)0x0) {
      (*(code *)PTR_DSA_up_ref_006a8adc)(key);
      iVar3 = 1;
      goto LAB_0053e2b0;
    }
  }
LAB_0053e2ac:
  iVar3 = 0;
LAB_0053e2b0:
  if (local_14 == *(int **)puVar2) {
    return iVar3;
  }
  piVar4 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*piVar4 != 0x74) {
    ERR_put_error(6,0x78,0x81,"p_lib.c",299);
    return 0;
  }
  (*(code *)PTR_DSA_up_ref_006a8adc)(piVar4[5]);
  return piVar4[5];
}

