
int X509_supported_extension(X509_EXTENSION *ex)

{
  undefined *puVar1;
  ASN1_OBJECT *pAVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar2 = X509_EXTENSION_get_object(ex);
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pAVar2);
  local_10 = uVar3;
  if (uVar3 != 0) {
    iVar4 = (*(code *)PTR_OBJ_bsearch__006a9488)
                      (&local_10,supported_nids_13629,0xb,4,nid_cmp_BSEARCH_CMP_FN);
    uVar3 = (uint)(iVar4 != 0);
  }
  if (local_c == *(int *)puVar1) {
    return uVar3;
  }
  iVar4 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar3 = *(uint *)(iVar4 + 0x28);
  if ((uVar3 & 0x100) == 0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,3,"v3_purp.c",0x214);
    if ((*(uint *)(iVar4 + 0x28) & 0x100) == 0) {
      x509v3_cache_extensions_part_6(iVar4);
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,3,"v3_purp.c",0x216);
    uVar3 = *(uint *)(iVar4 + 0x28);
  }
  if (((uVar3 & 2) != 0) && ((*(uint *)(iVar4 + 0x2c) & 4) == 0)) {
    return 0;
  }
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 0x60) == 0x60) {
      return 3;
    }
    if ((uVar3 & 2) != 0) {
      return 4;
    }
    uVar5 = 5;
    if ((uVar3 & 8) == 0) {
      return 0;
    }
    if ((*(uint *)(iVar4 + 0x34) & 7) == 0) {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = (uVar3 << 0x1b) >> 0x1f;
  }
  return uVar5;
}

