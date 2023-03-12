
int EVP_PKEY_set_type_str(EVP_PKEY *pkey,char *str,int len)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iVar10;
  code *pcVar11;
  undefined4 uStack_60;
  int iStack_5c;
  EVP_PKEY *pEStack_54;
  int *piStack_50;
  undefined *puStack_4c;
  int iStack_48;
  code *pcStack_44;
  ENGINE *local_20;
  undefined4 *local_1c;
  
  puStack_4c = PTR___stack_chk_guard_006a9ae8;
  local_20 = (ENGINE *)0x0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar10 = len;
  if (pkey == (EVP_PKEY *)0x0) {
LAB_0053dd28:
    if (str == (char *)0x0) {
      pcVar9 = (char *)0x0;
      piStack_50 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_20);
    }
    else {
      iVar10 = len;
      piStack_50 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&local_20);
      pcVar9 = str;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      if (local_20 != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
      }
      if (piStack_50 == (int *)0x0) goto LAB_0053ddbc;
      goto LAB_0053dcf8;
    }
    if (piStack_50 == (int *)0x0) {
LAB_0053ddbc:
      iVar10 = 0x9c;
      pcVar9 = &DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      iVar3 = 0;
    }
    else {
      iVar6 = *piStack_50;
      iVar3 = 1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piStack_50;
      pkey->save_type = 0;
      pkey->type = iVar6;
      pkey->engine = local_20;
    }
  }
  else {
    pcVar9 = str;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (pkey->save_type == 0) goto LAB_0053dcec;
LAB_0053dd0c:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pkey->engine = (ENGINE *)0x0;
      }
      goto LAB_0053dd28;
    }
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar11 = *(code **)(pkey->ameth + 0x54), pcVar11 != (code *)0x0)) {
      (*pcVar11)();
      (pkey->pkey).ptr = (char *)0x0;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      pkey->engine = (ENGINE *)0x0;
    }
    if (pkey->save_type != 0) goto LAB_0053dd28;
LAB_0053dcec:
    piStack_50 = (int *)str;
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0053dd0c;
LAB_0053dcf8:
    iVar3 = 1;
  }
  if (local_1c == *(undefined4 **)puStack_4c) {
    return iVar3;
  }
  pcStack_44 = EVP_PKEY_assign;
  puVar8 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEStack_54 = pkey;
  iStack_48 = len;
  if (puVar8 == (undefined4 *)0x0) {
    uVar4 = 0;
    goto LAB_0053dec0;
  }
  uStack_60 = 0;
  if (puVar8[5] == 0) {
    if (pcVar9 == (char *)puVar8[1]) goto LAB_0053deac;
LAB_0053def4:
    if (puVar8[4] == 0) {
LAB_0053df54:
      puVar5 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&uStack_60,pcVar9);
    }
    else {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar1 = PTR_EVP_PKEY_asn1_find_006a6fd4;
      puVar8[4] = 0;
      puVar5 = (undefined4 *)(*(code *)puVar1)(&uStack_60,pcVar9);
    }
    if (puVar5 == (undefined4 *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      uVar4 = 0;
      goto LAB_0053dec0;
    }
    uVar7 = *puVar5;
    puVar8[3] = puVar5;
    puVar8[1] = pcVar9;
    *puVar8 = uVar7;
    puVar8[4] = uStack_60;
  }
  else {
    if ((puVar8[3] != 0) && (pcVar11 = *(code **)(puVar8[3] + 0x54), pcVar11 != (code *)0x0)) {
      (*pcVar11)();
      puVar8[5] = 0;
    }
    if (puVar8[4] != 0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar8[4] = 0;
    }
    if (pcVar9 != (char *)puVar8[1]) goto LAB_0053df54;
LAB_0053deac:
    if (puVar8[3] == 0) goto LAB_0053def4;
  }
  puVar8[5] = iVar10;
  uVar4 = (uint)(iVar10 != 0);
LAB_0053dec0:
  if (iStack_5c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(iStack_5c + 0x14);
  }
  return uVar4;
}

