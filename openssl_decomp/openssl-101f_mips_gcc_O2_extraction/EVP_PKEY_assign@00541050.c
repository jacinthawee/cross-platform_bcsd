
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  ENGINE *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_20 = (ENGINE *)0x0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pkey == (EVP_PKEY *)0x0) {
    iVar4 = (*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_20);
    if (local_20 != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    if (iVar4 == 0) goto LAB_005411b8;
  }
  else {
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (type == pkey->save_type) goto LAB_005410f0;
LAB_00541138:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar5 = *(code **)(pkey->ameth + 0x54), pcVar5 != (code *)0x0)) {
        (*pcVar5)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
      if (type == pkey->save_type) {
LAB_005410f0:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_005410fc;
        goto LAB_00541138;
      }
    }
    piVar3 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_20,type);
    if (piVar3 == (int *)0x0) {
LAB_005411b8:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      uVar2 = 0;
      goto LAB_00541104;
    }
    iVar4 = *piVar3;
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
    pkey->save_type = type;
    pkey->type = iVar4;
    pkey->engine = local_20;
  }
LAB_005410fc:
  (pkey->pkey).ptr = (char *)key;
  uVar2 = (uint)(key != (void *)0x0);
LAB_00541104:
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(int *)(local_1c + 0x14);
  }
  return uVar2;
}

