
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int in_a2;
  int unaff_s1;
  code *pcVar11;
  undefined4 uStack_98;
  int iStack_94;
  undefined4 *puStack_8c;
  undefined4 *puStack_88;
  undefined *puStack_84;
  int iStack_80;
  code *pcStack_7c;
  int iStack_58;
  undefined4 *puStack_54;
  EVP_PKEY *pEStack_4c;
  int iStack_48;
  undefined *puStack_44;
  ENGINE *local_18;
  undefined4 *local_14;
  
  puStack_44 = PTR___stack_chk_guard_006a9ae8;
  local_18 = (ENGINE *)0x0;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  if (pkey == (EVP_PKEY *)0x0) {
    pkey = (EVP_PKEY *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18);
    puVar9 = (undefined4 *)type;
    if (local_18 != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar9 = (undefined4 *)type;
    }
    if (pkey == (EVP_PKEY *)0x0) goto LAB_0053dc0c;
LAB_0053db4c:
    iVar3 = 1;
  }
  else {
    puVar9 = (undefined4 *)type;
    unaff_s1 = type;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (type == pkey->save_type) goto LAB_0053db40;
LAB_0053db60:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pkey->engine = (ENGINE *)0x0;
      }
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar11 = *(code **)(pkey->ameth + 0x54), pcVar11 != (code *)0x0)) {
        (*pcVar11)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pkey->engine = (ENGINE *)0x0;
      }
      if (type == pkey->save_type) {
LAB_0053db40:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0053db4c;
        goto LAB_0053db60;
      }
    }
    puVar9 = (undefined4 *)type;
    piVar4 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18);
    if (piVar4 == (int *)0x0) {
LAB_0053dc0c:
      in_a2 = 0x9c;
      puVar9 = (undefined4 *)&DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      iVar3 = 0;
    }
    else {
      iVar5 = *piVar4;
      iVar3 = 1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar4;
      pkey->save_type = type;
      pkey->type = iVar5;
      pkey->engine = local_18;
    }
  }
  if (local_14 == *(undefined4 **)puStack_44) {
    return iVar3;
  }
  puStack_8c = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  iStack_58 = 0;
  puStack_54 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar3 = in_a2;
  pEStack_4c = pkey;
  iStack_48 = unaff_s1;
  if (puStack_8c == (undefined4 *)0x0) {
LAB_0053dd28:
    if (puVar9 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)0x0;
      puStack_88 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&iStack_58);
    }
    else {
      iVar3 = in_a2;
      puStack_88 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&iStack_58);
      puVar10 = puVar9;
    }
    if (puStack_8c == (undefined4 *)0x0) {
      if (iStack_58 != 0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
      }
      if (puStack_88 == (undefined4 *)0x0) goto LAB_0053ddbc;
      goto LAB_0053dcf8;
    }
    if (puStack_88 == (undefined4 *)0x0) {
LAB_0053ddbc:
      iVar3 = 0x9c;
      puVar10 = (undefined4 *)&DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      iVar5 = 0;
    }
    else {
      uVar8 = *puStack_88;
      iVar5 = 1;
      puStack_8c[3] = puStack_88;
      puStack_8c[1] = 0;
      *puStack_8c = uVar8;
      puStack_8c[4] = iStack_58;
    }
  }
  else {
    puVar10 = puVar9;
    if (puStack_8c[5] == 0) {
      if (puStack_8c[1] == 0) goto LAB_0053dcec;
LAB_0053dd0c:
      if (puStack_8c[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        puStack_8c[4] = 0;
      }
      goto LAB_0053dd28;
    }
    if ((puStack_8c[3] != 0) && (pcVar11 = *(code **)(puStack_8c[3] + 0x54), pcVar11 != (code *)0x0)
       ) {
      (*pcVar11)();
      puStack_8c[5] = 0;
    }
    if (puStack_8c[4] != 0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puStack_8c[4] = 0;
    }
    if (puStack_8c[1] != 0) goto LAB_0053dd28;
LAB_0053dcec:
    puStack_88 = puVar9;
    if (puStack_8c[3] == 0) goto LAB_0053dd0c;
LAB_0053dcf8:
    iVar5 = 1;
  }
  if (puStack_54 == *(undefined4 **)puStack_84) {
    return iVar5;
  }
  pcStack_7c = EVP_PKEY_assign;
  puVar9 = puStack_54;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_80 = in_a2;
  if (puVar9 == (undefined4 *)0x0) {
    uVar6 = 0;
    goto LAB_0053dec0;
  }
  uStack_98 = 0;
  if (puVar9[5] == 0) {
    if (puVar10 == (undefined4 *)puVar9[1]) goto LAB_0053deac;
LAB_0053def4:
    if (puVar9[4] == 0) {
LAB_0053df54:
      puVar7 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&uStack_98,puVar10);
    }
    else {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar1 = PTR_EVP_PKEY_asn1_find_006a6fd4;
      puVar9[4] = 0;
      puVar7 = (undefined4 *)(*(code *)puVar1)(&uStack_98,puVar10);
    }
    if (puVar7 == (undefined4 *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      uVar6 = 0;
      goto LAB_0053dec0;
    }
    uVar8 = *puVar7;
    puVar9[3] = puVar7;
    puVar9[1] = puVar10;
    *puVar9 = uVar8;
    puVar9[4] = uStack_98;
  }
  else {
    if ((puVar9[3] != 0) && (pcVar11 = *(code **)(puVar9[3] + 0x54), pcVar11 != (code *)0x0)) {
      (*pcVar11)();
      puVar9[5] = 0;
    }
    if (puVar9[4] != 0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      puVar9[4] = 0;
    }
    if (puVar10 != (undefined4 *)puVar9[1]) goto LAB_0053df54;
LAB_0053deac:
    if (puVar9[3] == 0) goto LAB_0053def4;
  }
  puVar9[5] = iVar3;
  uVar6 = (uint)(iVar3 != 0);
LAB_0053dec0:
  if (iStack_94 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(iStack_94 + 0x14);
  }
  return uVar6;
}

