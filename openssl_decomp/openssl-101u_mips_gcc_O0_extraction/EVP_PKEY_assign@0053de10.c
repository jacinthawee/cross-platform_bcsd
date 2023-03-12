
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  ENGINE *local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pkey == (EVP_PKEY *)0x0) {
    uVar3 = 0;
    goto LAB_0053dec0;
  }
  local_20 = (ENGINE *)0x0;
  if ((pkey->pkey).ptr == (char *)0x0) {
    if (type == pkey->save_type) goto LAB_0053deac;
LAB_0053def4:
    if (pkey->engine == (ENGINE *)0x0) {
LAB_0053df54:
      piVar4 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_20,type);
    }
    else {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar1 = PTR_EVP_PKEY_asn1_find_006a6fd4;
      pkey->engine = (ENGINE *)0x0;
      piVar4 = (int *)(*(code *)puVar1)(&local_20,type);
    }
    if (piVar4 == (int *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      uVar3 = 0;
      goto LAB_0053dec0;
    }
    iVar5 = *piVar4;
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar4;
    pkey->save_type = type;
    pkey->type = iVar5;
    pkey->engine = local_20;
  }
  else {
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar6 = *(code **)(pkey->ameth + 0x54), pcVar6 != (code *)0x0)) {
      (*pcVar6)();
      (pkey->pkey).ptr = (char *)0x0;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      pkey->engine = (ENGINE *)0x0;
    }
    if (type != pkey->save_type) goto LAB_0053df54;
LAB_0053deac:
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0053def4;
  }
  (pkey->pkey).ptr = (char *)key;
  uVar3 = (uint)(key != (void *)0x0);
LAB_0053dec0:
  if (local_1c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(local_1c + 0x14);
  }
  return uVar3;
}

