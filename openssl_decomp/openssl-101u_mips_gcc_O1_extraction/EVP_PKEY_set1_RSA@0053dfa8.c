
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey,rsa_st *key)

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
      if (pkey->save_type == 6) goto LAB_0053e040;
LAB_0053e0c8:
      if (pkey->engine == (ENGINE *)0x0) {
LAB_0053e124:
        piVar4 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18,6);
      }
      else {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        puVar1 = PTR_EVP_PKEY_asn1_find_006a6fd4;
        pkey->engine = (ENGINE *)0x0;
        piVar4 = (int *)(*(code *)puVar1)(&local_18,6);
      }
      if (piVar4 == (int *)0x0) {
        ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
        goto LAB_0053e090;
      }
      iVar3 = *piVar4;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar4;
      pkey->save_type = 6;
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
      if (pkey->save_type != 6) goto LAB_0053e124;
LAB_0053e040:
      if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0053e0c8;
    }
    (pkey->pkey).rsa = key;
    if (key != (rsa_st *)0x0) {
      (*(code *)PTR_RSA_up_ref_006a7f98)(key);
      iVar3 = 1;
      goto LAB_0053e094;
    }
  }
LAB_0053e090:
  iVar3 = 0;
LAB_0053e094:
  if (local_14 == *(int **)puVar2) {
    return iVar3;
  }
  piVar4 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*piVar4 != 6) {
    ERR_put_error(6,0x79,0x7f,"p_lib.c",0x117);
    return 0;
  }
  (*(code *)PTR_RSA_up_ref_006a7f98)(piVar4[5]);
  return piVar4[5];
}

