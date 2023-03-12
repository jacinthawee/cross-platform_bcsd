
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int in_a2;
  int unaff_s1;
  code *pcVar10;
  int iStack_98;
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
  
  puStack_44 = PTR___stack_chk_guard_006aabf0;
  local_18 = (ENGINE *)0x0;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  if (pkey == (EVP_PKEY *)0x0) {
    pkey = (EVP_PKEY *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_18);
    puVar8 = (undefined4 *)type;
    if (local_18 != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
      puVar8 = (undefined4 *)type;
    }
    if (pkey == (EVP_PKEY *)0x0) goto LAB_00540e4c;
LAB_00540d8c:
    iVar2 = 1;
  }
  else {
    puVar8 = (undefined4 *)type;
    unaff_s1 = type;
    if ((pkey->pkey).ptr == (char *)0x0) {
      if (type == pkey->save_type) goto LAB_00540d80;
LAB_00540da0:
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
    }
    else {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar10 = *(code **)(pkey->ameth + 0x54), pcVar10 != (code *)0x0)) {
        (*pcVar10)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pkey->engine = (ENGINE *)0x0;
      }
      if (type == pkey->save_type) {
LAB_00540d80:
        if (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_00540d8c;
        goto LAB_00540da0;
      }
    }
    puVar8 = (undefined4 *)type;
    piVar3 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_18);
    if (piVar3 == (int *)0x0) {
LAB_00540e4c:
      in_a2 = 0x9c;
      puVar8 = (undefined4 *)&DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      iVar2 = 0;
    }
    else {
      iVar4 = *piVar3;
      iVar2 = 1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar3;
      pkey->save_type = type;
      pkey->type = iVar4;
      pkey->engine = local_18;
    }
  }
  if (local_14 == *(undefined4 **)puStack_44) {
    return iVar2;
  }
  puStack_8c = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_84 = PTR___stack_chk_guard_006aabf0;
  iStack_58 = 0;
  puStack_54 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar2 = in_a2;
  pEStack_4c = pkey;
  iStack_48 = unaff_s1;
  if (puStack_8c == (undefined4 *)0x0) {
LAB_00540f68:
    if (puVar8 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
      puStack_88 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&iStack_58);
    }
    else {
      iVar2 = in_a2;
      puStack_88 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&iStack_58);
      puVar9 = puVar8;
    }
    if (puStack_8c == (undefined4 *)0x0) {
      if (iStack_58 != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      if (puStack_88 == (undefined4 *)0x0) goto LAB_00540ffc;
      goto LAB_00540f38;
    }
    if (puStack_88 == (undefined4 *)0x0) {
LAB_00540ffc:
      iVar2 = 0x9c;
      puVar9 = (undefined4 *)&DAT_0000009e;
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      iVar4 = 0;
    }
    else {
      uVar7 = *puStack_88;
      iVar4 = 1;
      puStack_8c[3] = puStack_88;
      puStack_8c[1] = 0;
      *puStack_8c = uVar7;
      puStack_8c[4] = iStack_58;
    }
  }
  else {
    puVar9 = puVar8;
    if (puStack_8c[5] == 0) {
      if (puStack_8c[1] == 0) goto LAB_00540f2c;
LAB_00540f4c:
      if (puStack_8c[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        puStack_8c[4] = 0;
      }
      goto LAB_00540f68;
    }
    if ((puStack_8c[3] != 0) && (pcVar10 = *(code **)(puStack_8c[3] + 0x54), pcVar10 != (code *)0x0)
       ) {
      (*pcVar10)();
      puStack_8c[5] = 0;
    }
    if (puStack_8c[4] != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
      puStack_8c[4] = 0;
    }
    if (puStack_8c[1] != 0) goto LAB_00540f68;
LAB_00540f2c:
    puStack_88 = puVar8;
    if (puStack_8c[3] == 0) goto LAB_00540f4c;
LAB_00540f38:
    iVar4 = 1;
  }
  if (puStack_54 == *(undefined4 **)puStack_84) {
    return iVar4;
  }
  pcStack_7c = EVP_PKEY_assign;
  puVar8 = puStack_54;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_98 = 0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_80 = in_a2;
  if (puVar8 == (undefined4 *)0x0) {
    iVar4 = (*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&iStack_98);
    if (iStack_98 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    if (iVar4 == 0) goto LAB_005411b8;
  }
  else {
    if (puVar8[5] == 0) {
      if (puVar9 == (undefined4 *)puVar8[1]) goto LAB_005410f0;
LAB_00541138:
      if (puVar8[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        puVar8[4] = 0;
      }
    }
    else {
      if ((puVar8[3] != 0) && (pcVar10 = *(code **)(puVar8[3] + 0x54), pcVar10 != (code *)0x0)) {
        (*pcVar10)();
        puVar8[5] = 0;
      }
      if (puVar8[4] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        puVar8[4] = 0;
      }
      if (puVar9 == (undefined4 *)puVar8[1]) {
LAB_005410f0:
        if (puVar8[3] != 0) goto LAB_005410fc;
        goto LAB_00541138;
      }
    }
    puVar6 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&iStack_98,puVar9);
    if (puVar6 == (undefined4 *)0x0) {
LAB_005411b8:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      uVar5 = 0;
      goto LAB_00541104;
    }
    uVar7 = *puVar6;
    puVar8[3] = puVar6;
    puVar8[1] = puVar9;
    *puVar8 = uVar7;
    puVar8[4] = iStack_98;
  }
LAB_005410fc:
  puVar8[5] = iVar2;
  uVar5 = (uint)(iVar2 != 0);
LAB_00541104:
  if (iStack_94 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(int *)(iStack_94 + 0x14);
  }
  return uVar5;
}

