
int EVP_PKEY_set_type_str(EVP_PKEY *pkey,char *str,int len)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int iVar9;
  code *pcVar10;
  int iStack_60;
  int iStack_5c;
  EVP_PKEY *pEStack_54;
  int *piStack_50;
  undefined *puStack_4c;
  int iStack_48;
  code *pcStack_44;
  ENGINE *local_20;
  undefined4 *local_1c;
  
  puStack_4c = PTR___stack_chk_guard_006aabf0;
  local_20 = (ENGINE *)0x0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar9 = len;
  if (pkey == (EVP_PKEY *)0x0) {
LAB_00540f68:
    if (str == (char *)0x0) {
      pcVar8 = (char *)0x0;
      piStack_50 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_20);
    }
    else {
      iVar9 = len;
      piStack_50 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_20);
      pcVar8 = str;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      if (local_20 != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      if (piStack_50 == (int *)0x0) goto LAB_00540ffc;
      goto LAB_00540f38;
    }
    if (piStack_50 == (int *)0x0) {
LAB_00540ffc:
      iVar9 = 0x9c;
      pcVar8 = &DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      iVar2 = 0;
    }
    else {
      iVar5 = *piStack_50;
      iVar2 = 1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piStack_50;
      pkey->save_type = 0;
      pkey->type = iVar5;
      pkey->engine = local_20;
    }
  }
  else {
    pcVar8 = str;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0) goto LAB_00540f2c;
LAB_00540f4c:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
      goto LAB_00540f68;
    }
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar10 = *(code **)(pkey->ameth + 0x54), pcVar10 != (code *)0x0)) {
      (*pcVar10)();
      (pkey->pkey).ptr = (char *)0x0;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
      pkey->engine = (ENGINE *)0x0;
    }
    if (pkey->save_type != 0) goto LAB_00540f68;
LAB_00540f2c:
    piStack_50 = (int *)str;
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_00540f4c;
LAB_00540f38:
    iVar2 = 1;
  }
  if (local_1c == *(undefined4 **)puStack_4c) {
    return iVar2;
  }
  pcStack_44 = EVP_PKEY_assign;
  puVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_60 = 0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_54 = pkey;
  iStack_48 = len;
  if (puVar7 == (undefined4 *)0x0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&iStack_60);
    if (iStack_60 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    if (iVar2 == 0) goto LAB_005411b8;
  }
  else {
    if (puVar7[5] == 0) {
      if (pcVar8 == (char *)puVar7[1]) goto LAB_005410f0;
LAB_00541138:
      if (puVar7[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        puVar7[4] = 0;
      }
    }
    else {
      if ((puVar7[3] != 0) && (pcVar10 = *(code **)(puVar7[3] + 0x54), pcVar10 != (code *)0x0)) {
        (*pcVar10)();
        puVar7[5] = 0;
      }
      if (puVar7[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        puVar7[4] = 0;
      }
      if (pcVar8 == (char *)puVar7[1]) {
LAB_005410f0:
        if (puVar7[3] != 0) goto LAB_005410fc;
        goto LAB_00541138;
      }
    }
    puVar4 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&iStack_60,pcVar8);
    if (puVar4 == (undefined4 *)0x0) {
LAB_005411b8:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      uVar3 = 0;
      goto LAB_00541104;
    }
    uVar6 = *puVar4;
    puVar7[3] = puVar4;
    puVar7[1] = pcVar8;
    *puVar7 = uVar6;
    puVar7[4] = iStack_60;
  }
LAB_005410fc:
  puVar7[5] = iVar9;
  uVar3 = (uint)(iVar9 != 0);
LAB_00541104:
  if (iStack_5c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(int *)(iStack_5c + 0x14);
  }
  return uVar3;
}

